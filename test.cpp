#include <iostream>
#include <string>

/*
����������:
����������ߵ���������, С���ұߵ���������, ��������м�ڵ�(���Ǿ���λ�õ��м�). 
�ڶ�������������һ����, �Ͳ���Ҫ������, ���ƶ��ַ�

����ʱ Ҫô����Ҷ�ӽ�� Ҫô��ȱʧ��Ҷ�ӽ��
����: ֱ�Ӳ���
�ǿ���: ����+����
	1. ��������Ѿ����ڵ�ֵ, ��������,���ܲ���
	2. ��valС  ������,
	3. ��val��, ������
	4. �ҵ�ȷ��λ�ú�, �ٽ�����parent���Ƚ���С�������, ������ҽڵ�
ɾ��:
	ɾ����֤�ṹ����Ϊ����������
�����е����ҽ��: ���������е��������н��
�����е�������: С�������е��������н��

���ɾ������Ҷ�� ֻ��Ҫ�����ɾ����
һ���������� ��һ�����������ڣ� ��Ҫ��������������� 


*/

using namespace std;
//class A{
//public:
//	A(char *s) { cout << s << endl; }
//	~A(){}
//};
//class B :virtual public A {
//public:
//	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//class C :virtual public A {
//public:
//	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//class D :public B, public C {
//public:
//	D(char *s1, char *s2, char *s3, char *s4) :B(s1, s2), C(s1, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//
//int main() {
//	D *p = new D("class A", "class B", "class C", "class D");// ����ӡABCD, �����������̳�, A�ᱻִ�ж��, ��ӡABACD
//	delete p;
//	system("pause");
//	return 0;
//}

//class A {
//public:
//	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
//	virtual void test(){ func(); }
//};
//class B : public A {
//public:
//	void func(int val = 0){ std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	B*p = new B;
//	p->test();
//	system("pause");
//	return 0;
//}

class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // ����
};
class Student : public Person
{
public:
	int _stuNum; // ѧ��
};
void Display(const Person& p, const Student& s) {
	cout << p._name << endl;
	cout << s._stuNum << endl;
}
int main()
{
	Person p;
	Student s;
	Display(p, s);

	system("pause");
	return 0;
}


class A
{
public:
	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
	virtual void test(){ this->func(); }
};
class B : public A
{
public:
	void func(int val = 0){ std::cout << "B->" << val << std::endl; } 
};
int main(int argc, char* argv[])
{
	B*p = new B;
	p->test();  // ���B->1
	return 0; 
}