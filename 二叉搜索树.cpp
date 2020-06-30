
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
		//从根节点开始查找
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
		//判断是否为空树
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		//搜索插入的位置
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
		//确定新插入数据的左右位置
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
		//删除操作
		// 1. 叶子节点
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			//判断删除的是否为根节点
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
			//左右孩子都存在

			//1. 找左子树的最右节点
			Node* child = cur->_left;
			parent = cur;
			while (child->_right)
			{
				parent = child;
				child = child->_right;
			}

			//2. 用最右节点的值覆盖当前cur位置的值
			cur->_val = child->_val;

			//3. 重新链接
			if (parent->_left == child)
				parent->_left = child->_left;
			else
				parent->_right = child->_left;
			//4. 删除最右节点
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

	bst.erase(0);  //叶子
	bst.erase(2);  //不存在右子树
	bst.erase(8);  //不存在左子树
	bst.erase(5);  //左右子树都存在
}

int main()
{
	test();
	return 0;
}