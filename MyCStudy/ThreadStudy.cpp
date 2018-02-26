#include "ThreadStudy.h"
#include <mutex>
#include <fstream>
#include <deque>
#include <condition_variable>
#include <future>

ThreadStudy::ThreadStudy()
{
}


ThreadStudy::~ThreadStudy()
{
}
std::mutex mu;
std::condition_variable cond;

void function1(){
	for (size_t i = 0; i < 100; i++)
	{
		cout << i << endl;
	}
	cout << "这是线程。。。。" << endl;
}




class Fctor{

public:
	void operator()(std::string &msg){
		cout << "from t2 : " << msg.c_str() << endl;
		msg = "i love c";
	}
};

void share_printf(string msg, int id){
	std::lock_guard<std::mutex> guard(mu);//当guard析构的时候  不管有没有没有异常发生 mu对象将会自动的解锁

	//mu.lock(); 
	cout << msg.c_str() << id << endl;
	//mu.unlock();

	/*
	使用lock 和unlock的时候   如果在中途发生异常  代码很可能不能执行到unlock这里来 那么mu互斥对象会一直被锁住 最好使用lock_guard
	*/
}

void function2(){
	for (size_t i = 0; i < 50; i++)
	{
		share_printf("这是t4线程。。。。", i);
	}
}
class Lofile{//在这个对象中  f就在m_mutex互斥对象的保护之下  他是安全的 可以多线程并发使用的
public:
	Lofile(){
		f.open("log.txt");
	}
	void share_printf1(string msg, int id){
		std::lock_guard<std::mutex> guard(m_mutex);
		f<<msg.c_str() << id << std::endl;
	}
	//在share_printf2和share_printf3中 如果主线程和次线程分别调用容易引起死锁   可以使用std::lock进行解决  或者按照顺序构建互斥对象
	void share_printf2(string msg, int id){
		std::lock(m_mutex, m_mutex1);		//解决死锁问题
		std::lock_guard<std::mutex> guard(m_mutex,std::adopt_lock);
		std::lock_guard<std::mutex> guard1(m_mutex1, std::adopt_lock);
		f << msg.c_str() << id << std::endl;
	}
	void share_printf3(string msg, int id){
		std::lock(m_mutex, m_mutex1);		//解决死锁问题
		std::lock_guard<std::mutex> guard(m_mutex1, std::adopt_lock);
		std::lock_guard<std::mutex> guard1(m_mutex, std::adopt_lock);
		f << msg.c_str() << id << std::endl;
	}
	//unique_lock
	void share_printf4(string msg, int id){
		std::unique_lock<std::mutex> lock(m_mutex, std::defer_lock);//defer_lock  表示没有被加锁
		/*
		unique_lock和lock_guard比起来 unique_lock可以给部分代码枷锁  也可以移动    但是比起lock_guard  unique_lock需要更多的性能开销
		*/

		f << msg.c_str() << id << std::endl;
	}
	//Lazy Initialization
	void share_printf5(string msg, int id){
			//{
			//	std::unique_lock<std::mutex> lock(m_mutex, std::defer_lock);
			//	if (!f.is_open()){
			//		f.open("log.txt");
			//	}
			//}
		std::call_once(m_flag, [&](){f.open("log.txt"); });//call_once能确保一个线程只调用一次函数

		f << msg.c_str() << id << std::endl;
	}
private:
	std::mutex m_mutex;
	std::mutex m_mutex1;
	std::once_flag m_flag;
	std::ofstream f;
};
void function3(Lofile &log){
	for (size_t i = 0; i < 50; i++)
	{
		log.share_printf1("这是t4线程。。。。", i);
	}
}

std::deque<int> q;

void function4(){
	int count = 10;
	while (count > 0){
		std::unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one();//他会激活一个等待这条语句的线程
		//cond.notify_all();//将会激活所有的线程
		std::this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
}

void function5(){
	int data = 0;
	while (data != 1)
	{
		std::unique_lock<mutex> locker(mu);

		//必须要传入unique_lock初始化  lock_guard不能重复的激活
		cond.wait(locker, [&](){return !q.empty(); });//他会将线本线程休眠直到线程6调用cond.notify_one();
		data = q.back();
		q.pop_back();
		locker.unlock();
		cout << "这是线程7的值" << data << endl;

	}
}

int factorial(int N){
	int res = 1;
	for (size_t i = N; i < 1; i++)
	{
		res *= i;
	}
	cout << "res=====" << res << endl;
	return res;
}
int factorial1(std::future<int> &f){
	int res = 1;
	int N = f.get();
	for (size_t i = N; i < 1; i++)
	{
		res *= i;
	}
	cout << "res=====" << res << endl;
	return res;
}
void ThreadStudy::run(){
	/*
		线程对象只能被移动 不能被赋值  比如说 std::thread t2=t1;(错误)    std::thread t2=std::move(t1);(正确)  这个时候t1就为NULL了
	*/

	std::thread t1(function1);
	if (t1.joinable()){//线程是否能够join
		t1.join();//主线程会等待t1线程结束在运行
	}
	//t1.detach();//主线程不会等待t1线程  t1线程会和主线程一起执行（注意：如果一个线程被detach了，就不能join了）

	//------------------线程的管理------------------------

	string s("i love c++");
	std::thread t2((Fctor()),std::ref(s));//s为引用传递

	std::thread t3 = std::move(t2);//线程对象只能被移动 不能被赋值  这个时候t2就为null

	t3.join();
	
	cout << "最多可以使用多少个 线程" << std::thread::hardware_concurrency() << endl;

	//------------------数据的竞争与互斥对象-----------------------

	std::thread t4(function2);

	for (size_t i = 0; i < 50; i++)
	{
		share_printf("这是主线程。。。。", i);
	}
	t4.join();
		//---------------另外一种更加安全的做法------------
	cout << "----------------------------------------------------" << endl;
	Lofile log;
	std::thread t5(function3,std::ref(log));
	
	for (size_t i = 0; i < 50; i++)
	{
		log.share_printf1("这是主线程。。。。", i);
	}
	t5.join();

	//------------------死锁-----------------------
	/*
		多个线程 多个互斥对象引起  在新建互斥对象的时候一定要按照顺序

		避免死锁：评估一下程序是否需要两个以上的mutext
	*/

	//------------------Unique Lock和Lazy Initialization-----------------------

	//------------------条件变量-----------------------
	
	cout << "-----------------------条件变量-----------------------------" << endl;
	std::thread t6(function4);
	std::thread t7(function5);
	t6.join();
	t7.join();

	//------------------Future, Promise和async()-----------线程之间的值传递------------
	
	cout << "从次线程传递数据到主线程"<< endl;
	int x;
	std::future<int> fu = std::async(std::launch::async,factorial,4);
	x = fu.get();

	cout << "x========" << x << endl;

	cout << "从主线程传递数据到次线程" << endl;
	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::future<int> fu1 = std::async(std::launch::async, factorial1, std::ref(f));
	p.set_value(4);

	x = fu1.get();
	cout << "x========" << x << endl;

	//------------------packaged_task-----------------------
	

	cout << "这是主线程。。。。" << s.c_str()<<endl;
}
