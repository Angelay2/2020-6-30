
template <class T>
struct Node
{
	T _val;
	Node* _left;
	Node* _right;

	Node(const T& val = T())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template <class T>
class BST
{
public:
	typedef Node<T> Node;

	Node* find(const T& val)
	{
		//�Ӹ��ڵ㿪ʼ����
		Node* cur = _root;
		while (cur)
		{
			if (cur->_val == val)
				return cur;
			else if (cur->_val < val)
				cur = cur->_right;
			else
				cur = cur->_left;
		}
		return nullptr;
	}

	BST()
		:_root(nullptr)
	{}

	bool insert(const T& val)
	{
		//�ж��Ƿ�Ϊ����
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		//���������λ��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_val == val)
				return false;
			else if (cur->_val < val)
				cur = cur->_right;
			else
				cur = cur->_left;
		}

		cur = new Node(val);
		//ȷ���²������ݵ�����λ��
		if (parent->_val < val)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}

	bool erase(const T& val)
	{
		if (_root == nullptr)
			return false;
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_val == val)
				break;
			else if (cur->_val < val)
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

private:
	Node* _root;
};

void test()
{
	BST<int> bst;
	bst.insert(5);
	bst.insert(3);
	bst.insert(7);
	bst.insert(2);
	bst.insert(1);
	bst.insert(0);
	bst.insert(8);
	bst.insert(6);
	bst.insert(9);

	bst.erase(0);  //Ҷ��
	bst.erase(2);  //������������
	bst.erase(8);  //������������
	bst.erase(5);  //��������������
}

int main()
{
	test();
	return 0;
}