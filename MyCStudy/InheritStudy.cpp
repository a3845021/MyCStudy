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

//����һ���µ�ѧ���࣬����score����
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

//ͨ���̳д���һ���µ�ѧ����

class Student3 :public Student
{
public:
	Student3(int id, string name, int score)
		:Student(id,name)//���๹��
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

//�̳й���
/*
	����1��ֻҪ�����е�privat��Ա������ʲô�̳з�ʽ�����Ӷ����ʲ���
	����2������ǹ���(public)�̳У������еķ��ʿ���Ȩ�޲���
	����3������Ǳ�����protected���̳У������и����г���private��Ա�������ڶ����ж���protected
	����4�������˽�У�private���̳�,�����и����г���private��Ա�������ڶ����ж���private
*/

class  Parent
{
public:
	int pub;//������ڲ����ⲿ���ܷ���
protected:
	int pro;//������ڲ����Է��ʣ�������ⲿ�����Է���
private:
	int pri;//������ڲ����Է��ʣ�������ⲿ�����Է���
};

//���м̳�
class  Child:public Parent
{
public:
	Child(){
	
	}
	void func(){
		cout << pub << endl;//pub�����public��Ա��������public�̳У���ġ��ڲ� �ⲿ�����Է���
		
		cout << pro << endl;//pro�Ǹ����protected��Ա��������public�̳���ġ��ڲ������Է���
							//��ʱ��pro�������ܹ����ʣ�˵����ʱpro����private��Ա������protected��Ա
		
		//cout << pri << endl;//pri�Ǹ����private��Ա���� ��public�̳���ġ��ڲ� �ⲿ�������Է���
	}

private:
	int b;
};

//������
class SubChild :public Child
{
	void func2()
	{
		cout << pro << endl;
	}
};

// �����̳�
class  Child2:protected Parent
{
	void func2(){
		pub;//��ʱpubͨ��protected�̳У��ܹ�������ڲ�����
			//pub������ڲ����Է��ʣ�����ⲿ���ʲ��ˣ���Ķ��ӿ��Է���
			//pub ����protected��Ա
		pro;//pro��pub��һ�������ʣ�proҲ��protected��Ա
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

//˽�м̳�
class  Child3:private Parent 
{
	void func3(){
		pub;//pub ������ڲ����Է��ʣ��ڼ̳�����ڲ����Է��ʣ�����ⲿ���ܷ���
			//pub �ڶ����з��ʲ��ˣ�˵��pub��Child3����˽�г�Ա
		pro;//pro��pub��������һ����Ҳ��˽�г�Ա
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
//��̳�
/*
	���˵үү����һ���������ӻ�̳��������������������ӻᱻ��̳У���ôүү����������������ӿ�����ݣ���Ҫ�ڶ��Ӽ̳�үү��ʱ�򣬼���virtual�ؼ��֣���ֹ��ݿ���
*/

//�Ҿ���
class  Furniture
{
public:
	int m;//����
};

//��������̳�үү��ĳ���̳з�ֹ�����ڶ�̳��ҵ�ʱ�򣬳���үү���еı����´�����
class Bed:virtual public Furniture
{
public:
	void sleep(){
		cout << "�ڴ���˯��" << endl;
	}
};

//ɳ����
class sofa :virtual public Furniture
{
public:
	void sit(){
		cout << "��ɳ������Ϣ" << endl;
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
	1:���������Ե����������ʹ��
	2������������ֱ�Ӹ�ֵ���������
	3������������ֱ�ӳ�ʼ���������
	***4������ָ�����ֱ��ָ���������***
	5���������ÿ���ֱ�������������
	*/
	//--------------��ϰ--------------------
	//Parent p;
	//Child c = p; //p������䲻��c����ռ� ���겿�ֲ��ܳ�ʼ��  ����˵c�����е�b

	//Child c;
//	Parent p1 = c;//c���� ��ռ�õ��ڴ�ռ�>=p����ռ�ÿռ䣬�ܹ������p��������Ҫ�Ŀռ�

	//--------------��ϰ------------------
	Parent *pp = NULL;
	Child *cp = NULL;

	Parent p;//�������
	Child c;

	pp = &c;// c�ڴ沼���ܹ����㸸��ָ���ȫ��Ҫ�󣬿�����һ�����ӵĶ����ַ������ָ�븳ֵ

	myPrint(&p);//ʵ��Ӧ��
	myPrint(&c);

	//-------------��̳�--------------

	Bed b;
	b.sleep();

	sofa s;
	s.sit();
	cout << "---------------------" << endl;
	SofaBed sb;
	sb.SleepAndSit();

	sb.m;//��Ϊʹ������̳�  ��������ֻ��һ��m

	//sb.Bed::m;
	//sb.sofa::m;

}