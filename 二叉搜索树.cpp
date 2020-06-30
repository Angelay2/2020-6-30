#include <iostream>
#include <string>
using namespace std;

//template <class T>
//struct Node
//{
//	T _val;
//	Node* _left;
//	Node* _right;
//
//	Node(const T& val = T())
//		:_val(val)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//
//template <class T>
//class BST
//{
//public:
//	typedef Node<T> Node;
//
//	Node* find(const T& val)
//	{
//		//�Ӹ��ڵ㿪ʼ����
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_val == val)
//				return cur;
//			else if (cur->_val < val)
//				cur = cur->_right;
//			else
//				cur = cur->_left;
//		}
//		return nullptr;
//	}
//
//	BST()
//		:_root(nullptr)
//	{}
//
//	Node* copy(Node* root)
//	{
//		if (root == nullptr)
//			return nullptr;
//		Node* cur = new Node(root->_val);
//		cur->_left = copy(root->_left);
//		cur->_right = copy(root->_right);
//		return cur;
//	}
//
//	BST(const BST<T>& bst)
//	{
//		_root = copy(bst._root);
//	}
//
//	void destory(Node* root)
//	{
//		if (root)
//		{
//			destory(root->_left);
//			destory(root->_right);
//			delete root;
//			root = nullptr;
//		}
//	}
//
//	~BST()
//	{
//		if (_root)
//			destory(_root);
//	}
//
//	bool insert(const T& val)
//	{
//		//�ж��Ƿ�Ϊ����
//		if (_root == nullptr)
//		{
//			_root = new Node(val);
//			return true;
//		}
//
//		//���������λ��
//		Node* cur = _root;
//		Node* parent = nullptr;
//		while (cur)
//		{
//			parent = cur;
//			if (cur->_val == val)
//				return false;
//			else if (cur->_val < val)
//				cur = cur->_right;
//			else
//				cur = cur->_left;
//		}
//
//		cur = new Node(val);
//		//ȷ���²������ݵ�����λ��
//		if (parent->_val < val)
//			parent->_right = cur;
//		else
//			parent->_left = cur;
//		return true;
//	}
//
//	bool erase(const T& val)
//	{
//		if (_root == nullptr)
//			return false;
//		Node* cur = _root;
//		Node* parent = nullptr;
//		while (cur)
//		{
//			if (cur->_val == val)
//				break;
//			else if (cur->_val < val)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//		}
//		if (cur == nullptr)
//			return false;
//		//ɾ������
//		// 1. Ҷ�ӽڵ�
//		if (cur->_left == nullptr && cur->_right == nullptr)
//		{
//			//�ж�ɾ�����Ƿ�Ϊ���ڵ�
//			if (cur == _root)
//			{
//				_root = nullptr;
//			}
//			else
//			{
//				if (parent->_left == cur)
//					parent->_left = nullptr;
//				else
//					parent->_right = nullptr;
//			}
//
//			delete cur;
//		}
//		else if (cur->_left == nullptr)
//		{
//			if (cur == _root)
//			{
//				_root = cur->_right;
//			}
//			else
//			{
//				if (parent->_left == cur)
//					parent->_left = cur->_right;
//				else
//					parent->_right = cur->_right;
//			}
//			delete cur;
//		}
//		else if (cur->_right == nullptr)
//		{
//			if (cur == _root)
//			{
//				_root = cur->_left;
//			}
//			else
//			{
//				if (parent->_left == cur)
//					parent->_left = cur->_left;
//				else
//					parent->_right = cur->_left;
//			}
//			delete cur;
//		}
//		else
//		{
//			//���Һ��Ӷ�����
//
//			//1. �������������ҽڵ�
//			Node* child = cur->_left;
//			parent = cur;
//			while (child->_right)
//			{
//				parent = child;
//				child = child->_right;
//			}
//
//			//2. �����ҽڵ��ֵ���ǵ�ǰcurλ�õ�ֵ
//			cur->_val = child->_val;
//
//			//3. ��������
//			if (parent->_left == child)
//				parent->_left = child->_left;
//			else
//				parent->_right = child->_left;
//			//4. ɾ�����ҽڵ�
//			delete child;
//		}
//
//		return true;
//	}
//
//	void inorder()
//	{
//		_inorder(_root);
//		cout << endl;
//	}
//	//�����������������������
//	void _inorder(Node* root)
//	{
//		if (root)
//		{
//			_inorder(root->_left);
//			cout << root->_val << " ";
//			_inorder(root->_right);
//		}
//	}
//
//
//private:
//	Node* _root;
//};

//void test()
//{
//	BST<int> bst;
//	bst.insert(5);
//	bst.insert(3);
//	bst.insert(7);
//	bst.insert(2);
//	bst.insert(1);
//	bst.insert(0);
//	bst.insert(8);
//	bst.insert(6);
//	bst.insert(9);
//
//	bst.erase(0);  //Ҷ��
//	bst.erase(2);  //������������
//	bst.erase(8);  //������������
//	bst.erase(5);  //��������������
//}

//void test2()
//{
//	BST<int> bst;
//	bst.insert(5);
//	bst.insert(3);
//	bst.insert(7);
//	bst.insert(2);
//	bst.insert(1);
//	bst.insert(0);
//	bst.insert(8);
//	bst.insert(6);
//	bst.insert(9);
//
//	bst.inorder();
//
//	BST<int> copy(bst);
//	copy.insert(100);
//	copy.erase(5);
//	copy.inorder();
//
//
//}

template <class K, class V>
struct Node
{
	K _key;
	V _val;
	Node* _left;
	Node* _right;

	Node(const K& key = K(), const V& val = V())
		: _key(key)
		, _val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template <class K, class V>
class BST
{
public:
	typedef Node<K, V> Node;

	Node* find(const K& key)
	{
		//�Ӹ��ڵ㿪ʼ����
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)
				return cur;
			else if (cur->_key < key)
				cur = cur->_right;
			else
				cur = cur->_left;
		}
		return nullptr;
	}

	BST()
		:_root(nullptr)
	{}

	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* cur = new Node(root->_key, root->_val);
		cur->_left = copy(root->_left);
		cur->_right = copy(root->_right);
		return cur;
	}

	BST(const BST<K, V>& bst)
	{
		_root = copy(bst._root);
	}

	void destory(Node* root)
	{
		if (root)
		{
			destory(root->_left);
			destory(root->_right);
			delete root;
			root = nullptr;
		}
	}

	~BST()
	{
		if (_root)
			destory(_root);
	}

	bool insert(const K& key, const V& val)
	{
		//�ж��Ƿ�Ϊ����
		if (_root == nullptr)
		{
			_root = new Node(key, val);
			return true;
		}

		//���������λ��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_key == key)
				return false;
			else if (cur->_key < key)
				cur = cur->_right;
			else
				cur = cur->_left;
		}

		cur = new Node(key, val);
		//ȷ���²������ݵ�����λ��
		if (parent->_key < key)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}

	bool erase(const K& key)
	{
		if (_root == nullptr)
			return false;
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key == key)
				break;
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				parent = cur;
				cur = cur->_left;
			}
		}
		if (cur == nullptr)
			return false;
		//ɾ������
		// 1. Ҷ�ӽڵ�
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			//�ж�ɾ�����Ƿ�Ϊ���ڵ�
			if (cur == _root)
			{
				_root = nullptr;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = nullptr;
				else
					parent->_right = nullptr;
			}

			delete cur;
		}
		else if (cur->_left == nullptr)
		{
			if (cur == _root)
			{
				_root = cur->_right;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			delete cur;
		}
		else if (cur->_right == nullptr)
		{
			if (cur == _root)
			{
				_root = cur->_left;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			delete cur;
		}
		else
		{
			//���Һ��Ӷ�����

			//1. �������������ҽڵ�
			Node* child = cur->_left;
			parent = cur;
			while (child->_right)
			{
				parent = child;
				child = child->_right;
			}

			//2. �����ҽڵ��ֵ���ǵ�ǰcurλ�õ�ֵ
			cur->_key = child->_key;
			cur->_val = child->_val;

			//3. ��������
			if (parent->_left == child)
				parent->_left = child->_left;
			else
				parent->_right = child->_left;
			//4. ɾ�����ҽڵ�
			delete child;
		}

		return true;
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}
	//�����������������������
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_key << "-->" << root->_val << "  ";
			_inorder(root->_right);
		}
	}


private:
	Node* _root;
};

void test()
{
	/*BST<int, int> bst;
	bst.insert(5, 10);
	bst.insert(1, 100);
	bst.insert(0, 3);
	bst.insert(15, 10);
	bst.insert(20, 10);
	bst.insert(7, 17);
	bst.insert(100, 100);
	bst.insert(35, 90);

	bst.inorder();*/
	BST<string, string> bst;
	bst.insert("bite", "����");
	bst.insert("68 class", "68 ��");
	bst.insert("xian", "����");
	bst.insert("china", "�й�");

	bst.inorder();
}

void test2()
{
	BST<int, int> bst;
	bst.insert(1, 1);
	bst.insert(2, 2);
	bst.insert(3, 3);
	bst.insert(4, 4);
	bst.insert(5, 5);
	bst.insert(6, 6);
	bst.insert(7, 7);
	bst.insert(8, 8);

	bst.inorder();
}

int main()
{
	//test();
	test2();
	return 0;
}