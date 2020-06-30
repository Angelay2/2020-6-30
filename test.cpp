#include <iostream>
#include <string>

/*
二叉搜索树:
根结点大于左边的所有子树, 小于右边的所有子树, 根结点是中间节点(不是绝对位置的中间). 
在二叉搜素树搜索一个数, 就不需要遍历了, 类似二分法

插入时 要么靠近叶子结点 要么是缺失的叶子结点
空树: 直接插入
非空树: 搜索+插入
	1. 如果插入已经存在的值, 则插入结束,不能插入
	2. 比val小  往左走,
	3. 比val大, 往右走
	4. 找到确定位置后, 再将其与parent结点比较是小插入左边, 大放在右节点
删除:
	删除后保证结构依旧为二叉搜索树
子树中的最右结点: 大于子树中的其他所有结点
子树中的最左结点: 小于子树中的其他所有结点

如果删除的是叶子 只需要把这个删掉，
一个子树存在 另一个子树不存在， 则要把这个子树再链接 


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
//	D *p = new D("class A", "class B", "class C", "class D");// 最后打印ABCD, 如果不是虚拟继承, A会被执行多次, 打印ABACD
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
	string _name; // 姓名
};
class Student : public Person
{
public:
	int _stuNum; // 学号
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
	p->test();  // 输出B->1
	return 0; 
}