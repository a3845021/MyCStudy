#include "InheritStudy.h"


InheritStudy::InheritStudy()
{
}


InheritStudy::~InheritStudy()
{
}

class Student{
public:
	Student(int id,string name){
		this->id = id;
		this->name = name;
	}
	void printS(){
		cout << "id=" << this->id << "name=" <<this->name.c_str()<<endl;
	}
private:
	int id;
	string  name;
};

//创建一个新的学生类，增加score功能
class Student2
{
public:
	Student2(int id, string name, int score){
		this->id = id;
		this->name = name;
		this->score = score;
	}
	~Student2(){
	}
private:
	int id;
	string name;
	int score;
};

//通过继承创建一个新的学生类

class Student3 :public Student
{
public:
	Student3(int id, string name, int score)
		:Student(id,name)//父类构造
	{
		this->score = score;
	}
	void printS(){
		Student::printS();
		cout << "score=" << this->score << endl;
	}
private:
	int score;
};

//继承规则
/*
	规则1：只要父类中的privat成员，不管什么继承方式，儿子都访问不了
	规则2：如果是公有(public)继承，儿子中的访问控制权限不变
	规则3：如果是保护（protected）继承，儿子中父亲中除了private成员，其余在儿子中都是protected
	规则4：如果是私有（private）继承,儿子中父亲中除了private成员，其余在儿子中都是private
*/

class  Parent
{
public:
	int pub;//在类的内部和外部都能访问
protected:
	int pro;//在类的内部可以访问，在类的外部不可以访问
private:
	int pri;//在类的内部可以访问，在类的外部不可以访问
};

//共有继承
class  Child:public Parent
{
public:
	Child(){
	
	}
	void func(){
		cout << pub << endl;//pub父类的public成员变量，在public继承，类的【内部 外部】可以访问
		
		cout << pro << endl;//pro是父类的protected成员变量，在public继承类的【内部】可以访问
							//此时的pro在孙子能够访问，说明此时pro不是private成员，而是protected成员
		
		//cout << pri << endl;//pri是父类的private成员变量 在public继承类的【内部 外部】不可以访问
	}

private:
	int b;
};

//孙子类
class SubChild :public Child
{
	void func2()
	{
		cout << pro << endl;
	}
};

// 保护继承
class  Child2:protected Parent
{
	void func2(){
		pub;//此时pub通过protected继承，能够在类的内部访问
			//pub在类的内部可以访问，类的外部访问不了，类的儿子可以访问
			//pub 就是protected成员
		pro;//pro根pub是一样的性质，pro也是protected成员
	}
};

class Sub_child2 :public Child2
{

public:
	void sub_fun2(){
		pub;
		pro;
	}
};

//私有继承
class  Child3:private Parent 
{
	void func3(){
		pub;//pub 在类的内部可以访问，在继承类的内部可以访问，类的外部不能访问
			//pub 在儿子中访问不了，说明pub在Child3中是私有成员
		pro;//pro跟pub的性质是一样，也是私有成员
	//	pri;
	}
};

class  Sub_child3:public Child3
{
public:
	void sub_fun3(){
		//pub;
		//pro;
	}
};

void myPrint(Parent *p){

}

//-------------------------------------
//多继承
/*
	如果说爷爷中有一个变量儿子会继承这个变量，但是如果儿子会被多继承，那么爷爷中这个变量会在孙子拷贝多份，需要在儿子继承爷爷的时候，加上virtual关键字，防止多份拷贝
*/

//家具类
class  Furniture
{
public:
	int m;//材质
};

//将父亲类继承爷爷类改成虚继承防止儿子在多继承我的时候，出现爷爷类中的变量会拷贝多份
class Bed:virtual public Furniture
{
public:
	void sleep(){
		cout << "在床上睡觉" << endl;
	}
};

//沙发类
class sofa :virtual public Furniture
{
public:
	void sit(){
		cout << "在沙发上休息" << endl;
	}

};

class  SofaBed:public Bed,public sofa
{
public:
	void SleepAndSit(){
		sleep();
		sit();
	}
};




void InheritStudy::run(){
	Student3 s3(1,"zhangsan",90);
	s3.printS();


	/*
	1:子类对象可以当作父类对象使用
	2：子类对象可以直接赋值给父类对象
	3：子类对象可以直接初始化父类对象
	***4：父类指针可以直接指向子类对象***
	5：父类引用可以直接引用子类对象
	*/
	//--------------练习--------------------
	//Parent p;
	//Child c = p; //p对象填充不满c对象空间 友谊部分不能初始化  比如说c对象中的b

	//Child c;
//	Parent p1 = c;//c对象 所占用的内存空间>=p对象占用空间，能够填充满p对象所需要的空间

	//--------------练习------------------
	Parent *pp = NULL;
	Child *cp = NULL;

	Parent p;//父类对象
	Child c;

	pp = &c;// c内存布局能够满足父类指针的全部要求，可以用一个儿子的对象地址给父类指针赋值

	myPrint(&p);//实际应用
	myPrint(&c);

	//-------------多继承--------------

	Bed b;
	b.sleep();

	sofa s;
	s.sit();
	cout << "---------------------" << endl;
	SofaBed sb;
	sb.SleepAndSit();

	sb.m;//因为使用了虚继承  所以这里只有一个m

	//sb.Bed::m;
	//sb.sofa::m;

}