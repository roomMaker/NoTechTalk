#include "Set_JH.h"
#include <queue>
Set::Node::Node(int data, Node* parent, Node* left, Node* right)
	:Data(data), Parent(parent), Left(left), Right(right)
{

}

Set::Node::~Node()
{
	Parent = nullptr;
	Left = nullptr;
	Right = nullptr;
}

bool Set::Node::IsLeaf() const
{
	if (Left == nullptr && Right == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Set::empty() const
{
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

size_t Set::size() const
{
	return _size;
}

bool Set::insert(int value)
{
	// 0. 새 노드 생성
	Node* newNode = new Node(value);

	// 1. 루트 노드일 경우 루트 노드 생성
	if (_head->Parent == nullptr)
	{
		_head->Parent = newNode;
		newNode->Parent = _head;

		++_size;

		return true;
	}
	
	// 2. 삽입될 위치의 부모 노드 찾음
	Node* parent = nullptr;
	Node* p = _head->Parent;

	while (p)
	{
		parent = p;

		if (p->Data == value)
		{
			return false;
		}
		else if (value < p->Data)
		{
			p = p->Left;
		}
		else
		{
			p = p->Right;
		}
	}

	// 3. 새로운 노드 삽입
	if (value < parent->Data)
	{
		parent->Left = newNode;
	}
	else
	{
		parent->Right = newNode;
	}

	newNode->Parent = parent;

	++_size;

	return false;
}

Set::Node* Set::find(int value) const
{
	Node* result = _head->Parent;

	while (result)
	{
		if (result->Data == value)
		{
			break;
		}
		else if (value > result->Data)
		{
			result = result->Right;
		}
		else
		{
			result = result->Left;
		}
	}
	return result;
}

void Set::traverseByPreorder() const
{
	traverseByPreorderHelper(_head->Parent);
}

void Set::traverseByInorder() const
{
	traverseByInorderHelper(_head->Parent);
}

void Set::traverseByPostorder() const
{
	traverseByPostorderHelper(_head->Parent);
}

void Set::traverseByLevelorder() const
{
	std::queue<Node*> que;
	if (_head->Parent)
	{
		que.push(_head->Parent);
	}
	
	while (!que.empty())
	{
		Node* node = que.front();
		que.pop();
		std::cout << node->Data << "->";

		if (node->Left != nullptr)
		{
			que.push(node->Left);
		}
		if (node->Right != nullptr)
		{
			que.push(node->Right);
		}
	}
}

void Set::traverseByPreorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	std::cout << node->Data << "->";
	traverseByPreorderHelper(node->Left);
	traverseByPreorderHelper(node->Right);
}

void Set::traverseByInorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	traverseByInorderHelper(node->Left);
	std::cout << node->Data << "->";
	traverseByInorderHelper(node->Right);
}

void Set::traverseByPostorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	traverseByPostorderHelper(node->Left);
	traverseByPostorderHelper(node->Right);
	std::cout << node->Data << "->";
}

//std::pair<Set::Node*, bool> Set::insert(int value)
//{
//	if (empty())
//	{
//		_root = new Node(value);
//		++_size;
//
//		return std::make_pair(_root, true);
//	}
//
//	// 이진 검색 트리 : 왼쪽 서브 트리는 자기보다 작은 값, 오른쪽 서브트리는 자기보다 큰 값.
//	Node* currentNode = _root;
//	Node* prevNode = nullptr;
//
//	while (currentNode)
//	{
//		prevNode = currentNode;
//
//		// 이진 검색 수행
//		if (currentNode->Data == value)
//		{
//			return std::make_pair(currentNode, false);
//		}
//		else if (currentNode->Data < value)
//		{
//			currentNode = currentNode->Right;
//		}
//		else
//		{
//			currentNode = currentNode->Left;
//		}
//
//	}
//
//	currentNode = new Node(value, prevNode);
//
//	// currentNode를 prevNode에 왼쪽 자식으로 삽입할 건지 오른쪽 자식으로 삽입할 건지?
//	if (prevNode->Data < value)
//	{
//		prevNode->Right = currentNode;
//	}
//	else
//	{
//		prevNode->Left = currentNode;
//	}
//
//	++_size;
//
//	return std::make_pair(currentNode, true);
//}
//
//void Set::erase(Node* pos)
//{
//	if (pos->Parent == nullptr)
//	{
//		if (pos->IsLeaf())
//		{
//			_root = nullptr;
//
//			delete pos;
//			pos = nullptr;
//
//			--_size;
//
//			return;
//		}
//	}
//}