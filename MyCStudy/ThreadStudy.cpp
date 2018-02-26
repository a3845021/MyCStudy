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
	cout << "�����̡߳�������" << endl;
}




class Fctor{

public:
	void operator()(std::string &msg){
		cout << "from t2 : " << msg.c_str() << endl;
		msg = "i love c";
	}
};

void share_printf(string msg, int id){
	std::lock_guard<std::mutex> guard(mu);//��guard������ʱ��  ������û��û���쳣���� mu���󽫻��Զ��Ľ���

	//mu.lock(); 
	cout << msg.c_str() << id << endl;
	//mu.unlock();

	/*
	ʹ��lock ��unlock��ʱ��   �������;�����쳣  ����ܿ��ܲ���ִ�е�unlock������ ��ômu��������һֱ����ס ���ʹ��lock_guard
	*/
}

void function2(){
	for (size_t i = 0; i < 50; i++)
	{
		share_printf("����t4�̡߳�������", i);
	}
}
class Lofile{//�����������  f����m_mutex�������ı���֮��  ���ǰ�ȫ�� ���Զ��̲߳���ʹ�õ�
public:
	Lofile(){
		f.open("log.txt");
	}
	void share_printf1(string msg, int id){
		std::lock_guard<std::mutex> guard(m_mutex);
		f<<msg.c_str() << id << std::endl;
	}
	//��share_printf2��share_printf3�� ������̺߳ʹ��̷ֱ߳����������������   ����ʹ��std::lock���н��  ���߰���˳�򹹽��������
	void share_printf2(string msg, int id){
		std::lock(m_mutex, m_mutex1);		//�����������
		std::lock_guard<std::mutex> guard(m_mutex,std::adopt_lock);
		std::lock_guard<std::mutex> guard1(m_mutex1, std::adopt_lock);
		f << msg.c_str() << id << std::endl;
	}
	void share_printf3(string msg, int id){
		std::lock(m_mutex, m_mutex1);		//�����������
		std::lock_guard<std::mutex> guard(m_mutex1, std::adopt_lock);
		std::lock_guard<std::mutex> guard1(m_mutex, std::adopt_lock);
		f << msg.c_str() << id << std::endl;
	}
	//unique_lock
	void share_printf4(string msg, int id){
		std::unique_lock<std::mutex> lock(m_mutex, std::defer_lock);//defer_lock  ��ʾû�б�����
		/*
		unique_lock��lock_guard������ unique_lock���Ը����ִ������  Ҳ�����ƶ�    ���Ǳ���lock_guard  unique_lock��Ҫ��������ܿ���
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
		std::call_once(m_flag, [&](){f.open("log.txt"); });//call_once��ȷ��һ���߳�ֻ����һ�κ���

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
		log.share_printf1("����t4�̡߳�������", i);
	}
}

std::deque<int> q;

void function4(){
	int count = 10;
	while (count > 0){
		std::unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one();//���ἤ��һ���ȴ����������߳�
		//cond.notify_all();//���ἤ�����е��߳�
		std::this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
}

void function5(){
	int data = 0;
	while (data != 1)
	{
		std::unique_lock<mutex> locker(mu);

		//����Ҫ����unique_lock��ʼ��  lock_guard�����ظ��ļ���
		cond.wait(locker, [&](){return !q.empty(); });//���Ὣ�߱��߳�����ֱ���߳�6����cond.notify_one();
		data = q.back();
		q.pop_back();
		locker.unlock();
		cout << "�����߳�7��ֵ" << data << endl;

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
		�̶߳���ֻ�ܱ��ƶ� ���ܱ���ֵ  ����˵ std::thread t2=t1;(����)    std::thread t2=std::move(t1);(��ȷ)  ���ʱ��t1��ΪNULL��
	*/

	std::thread t1(function1);
	if (t1.joinable()){//�߳��Ƿ��ܹ�join
		t1.join();//���̻߳�ȴ�t1�߳̽���������
	}
	//t1.detach();//���̲߳���ȴ�t1�߳�  t1�̻߳�����߳�һ��ִ�У�ע�⣺���һ���̱߳�detach�ˣ��Ͳ���join�ˣ�

	//------------------�̵߳Ĺ���------------------------

	string s("i love c++");
	std::thread t2((Fctor()),std::ref(s));//sΪ���ô���

	std::thread t3 = std::move(t2);//�̶߳���ֻ�ܱ��ƶ� ���ܱ���ֵ  ���ʱ��t2��Ϊnull

	t3.join();
	
	cout << "������ʹ�ö��ٸ� �߳�" << std::thread::hardware_concurrency() << endl;

	//------------------���ݵľ����뻥�����-----------------------

	std::thread t4(function2);

	for (size_t i = 0; i < 50; i++)
	{
		share_printf("�������̡߳�������", i);
	}
	t4.join();
		//---------------����һ�ָ��Ӱ�ȫ������------------
	cout << "----------------------------------------------------" << endl;
	Lofile log;
	std::thread t5(function3,std::ref(log));
	
	for (size_t i = 0; i < 50; i++)
	{
		log.share_printf1("�������̡߳�������", i);
	}
	t5.join();

	//------------------����-----------------------
	/*
		����߳� ��������������  ���½���������ʱ��һ��Ҫ����˳��

		��������������һ�³����Ƿ���Ҫ�������ϵ�mutext
	*/

	//------------------Unique Lock��Lazy Initialization-----------------------

	//------------------��������-----------------------
	
	cout << "-----------------------��������-----------------------------" << endl;
	std::thread t6(function4);
	std::thread t7(function5);
	t6.join();
	t7.join();

	//------------------Future, Promise��async()-----------�߳�֮���ֵ����------------
	
	cout << "�Ӵ��̴߳������ݵ����߳�"<< endl;
	int x;
	std::future<int> fu = std::async(std::launch::async,factorial,4);
	x = fu.get();

	cout << "x========" << x << endl;

	cout << "�����̴߳������ݵ����߳�" << endl;
	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::future<int> fu1 = std::async(std::launch::async, factorial1, std::ref(f));
	p.set_value(4);

	x = fu1.get();
	cout << "x========" << x << endl;

	//------------------packaged_task-----------------------
	

	cout << "�������̡߳�������" << s.c_str()<<endl;
}
