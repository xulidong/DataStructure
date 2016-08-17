#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// binary search tree，中文翻译为二叉搜索树、二叉查找树或者二叉排序树。简称为BST
class BSTree
{
	struct Node{
		Node(int x = 0):data(x), lchild(NULL), rchild(NULL){}
		struct Node* lchild;
		struct Node* rchild;
		int data;
	};

public:
	// **************************************************************************
	// 类的四大函数：构造函数、拷贝构造函数、重载赋值运算符、析构函数
	// **************************************************************************
	BSTree();
	~BSTree();

	// **************************************************************************
	// 增删改查
	// **************************************************************************
	void Insert(int x);
	void Remove(int x);

	// 返回二叉树的个数
	unsigned short Size();
	unsigned short Deep();
	unsigned short Leaf();

	bool IsEmpty();

	// 遍历
	void PreorderTraversal();	// 先序遍历
	void InorderTraversal();	// 中序遍历
	void PostorderTraversal();	// 后序遍历
	void DepthFirstSearch();	// 深度优先遍历
	void BreadthFirstSearch();	// 广度优先遍历

private:
	void Remove(int x, Node** pNode);

	// 递归计算二叉树个数
	unsigned short CountSize(Node* n);
	unsigned short CountDeep(Node* n);
	unsigned short CountLeaf(Node* n);

	// 递归遍历
	void PreorderTraversal(Node* n);
	void InorderTraversal(Node* n);
	void PostorderTraversal(Node* n);
	void DepthFirstSearch(Node* n);
	void BreadthFirstSearch(Node* n);

	void Free(Node* node);
private:
	Node* m_root;
};

// **************************************************************************
// 私有方法
// **************************************************************************
/* 
//1 请问下面这份代码有什么问题？
void BSTree::Remove(int x, Node* node)
{
	if (!node) {
		return;
	}
	if (x < node->data) {
		Remove(x, node->lchild);
	}
	else if (x > node->data){
		Remove(x, node->rchild);
	}
	else if (node->lchild && node->rchild) {
		Node* min = node->rchild;
		while(min->lchild){
			min = min->lchild;
		}
		node->data = min->data;
		Remove(node->data, node->rchild);
	}
	else{
		Node* tmp = node;
		if(node->lchild){
			node = node->lchild;
		}
		else if (node->rchild){
			node = node->rchild;
		}
		else{
			node = NULL;
		}
		delete tmp;
		tmp = NULL;
	}
}
node是一个局部变量，对node的操作除delete之外都不会生效

// 2 再问，下面的代码有什么问题？
void BSTree::Remove(int x, Node** pNode)
{
	if (!pNode || !(*pNode)) {
		return;
	}
	Node* node = *pNode;
	if (x < node->data) {
		Remove(x, node->lchild);
	}
	else if (x > node->data){
		Remove(x, node->rchild);
	}
	else if (node->lchild && node->rchild) {
		Node* min = node->rchild;
		while(min->lchild){
			min = min->lchild;
		}
		node->data = min->data;
		Remove(node->data, node->rchild);
	}
	else{
		Node* tmp = node;
		if(node->lchild){
			node = node->lchild;
		}
		else if (node->rchild){
			node = node->rchild;
		}
		else{
			node = NULL;
		}
		delete tmp;
		tmp = NULL;
	}
}
同样的问题，虽然这里传递的参数是指针，但是Node* node = *pNode;发生了拷贝。

*/
void BSTree::Remove(int x, Node** pNode)
{
	if (!pNode || !(*pNode)) {
		return;
	}
	
	if (x < (*pNode)->data) {
		Remove(x, &((*pNode)->lchild));
	}
	else if (x > (*pNode)->data){
		Remove(x, &((*pNode)->rchild));
	}
	else if ((*pNode)->lchild && (*pNode)->rchild) {
		Node* min = (*pNode)->rchild;
		while(min->lchild){
			min = min->lchild;
		}
		(*pNode)->data = min->data;
		Remove((*pNode)->data, &((*pNode)->rchild));
	}
	else{
		Node* tmp = *pNode;
		if((*pNode)->lchild){
			(*pNode) = (*pNode)->lchild;
		}
		else if ((*pNode)->rchild){
			*pNode = (*pNode)->rchild;
		}
		else{
			*pNode = NULL;
		}
		delete tmp;
		tmp = NULL;
	}
}

unsigned short BSTree::CountSize(Node* n)
{
	if(!n){
		return 0;
	}
	
	return CountSize(n->lchild) + CountSize(n->rchild) + 1;
}

unsigned short BSTree::CountDeep(Node* n)
{
	if (!n) {
		return 0;
	}
	int ldeep = CountDeep(n->lchild);
	int rdeep = CountDeep(n->rchild);
	return ( ldeep > rdeep ) ? (ldeep + 1) : (rdeep + 1);
}

unsigned short BSTree::CountLeaf(Node* n)
{
	if (!n){
		return 0;
	}
	if (!n->lchild&& !n->rchild){
		return 1;
	}
	return CountLeaf(n->lchild) + CountLeaf(n->rchild);
}

void  BSTree::PreorderTraversal(Node* n)
{
	if (n) {
		cout << n->data << ",";
		PreorderTraversal(n->lchild);
		PreorderTraversal(n->rchild);
	}
}

void  BSTree::InorderTraversal(Node* n)
{
	if (n) {
		InorderTraversal(n->lchild);
		cout << n->data << ",";
		InorderTraversal(n->rchild);
	}
}

void  BSTree::PostorderTraversal(Node* n)
{
	if (n) {
		PostorderTraversal(n->lchild);
		PostorderTraversal(n->rchild);
		cout << n->data << ",";
	}
}

void BSTree::DepthFirstSearch(Node* root)
{
	stack<Node *> nodeStack;
	nodeStack.push(root);
	Node* node = NULL;
	while(!nodeStack.empty()){
		node = nodeStack.top();
		cout << node->data << ",";
		nodeStack.pop();
		if (node->rchild) {
			nodeStack.push(node->rchild);
		}
		if (node->lchild) {
			nodeStack.push(node->lchild);
		}
	}
}

void BSTree::BreadthFirstSearch(Node* root)
{
	queue<Node *> nodeQueue;
	nodeQueue.push(root);
	Node* node = NULL;
	while(!nodeQueue.empty()){
		node = nodeQueue.front();
		nodeQueue.pop();
		cout << node->data << ",";
		if (node->lchild) {
			nodeQueue.push(node->lchild);
		}
		if (node->rchild) {
			nodeQueue.push(node->rchild);
		}
	}
}

void BSTree::Free(Node* n)
{
	if (n) {
		Free(n->lchild);
		Free(n->rchild);
		delete n;
		n = NULL;
	}
}

// **************************************************************************
// 类的四大函数：构造函数、拷贝构造函数、重载赋值运算符、析构函数
// **************************************************************************
BSTree::BSTree()
{
	m_root = NULL;
}

BSTree::~BSTree()
{
	Free(m_root);
}

// **************************************************************************
// 增删改查
// **************************************************************************
void BSTree::Insert(int x)
{
	Node* tmp = new Node(x);
	if (!m_root){
		m_root = tmp;
	}
	else{
		Node* pre = m_root;
		Node* cur = m_root;
		while (cur){
			pre = cur;
			cur = (x < cur->data) ? (cur->lchild) : (cur->rchild);
		}
		(x < pre->data) ? (pre->lchild = tmp) : (pre->rchild = tmp);
	}
}

void BSTree::Remove(int x)
{
	if (!m_root){
		return;
	}
	Remove(x, &m_root);
}

unsigned short BSTree::Size()
{
	return CountSize(m_root);
}

unsigned short BSTree::Deep()
{
	return CountDeep(m_root);
}

unsigned short BSTree::Leaf()
{
	return CountLeaf(m_root);
}

bool BSTree::IsEmpty()
{
	return m_root == NULL;
}

void BSTree::PreorderTraversal()
{
	PreorderTraversal(m_root);
	cout << endl;
}

void BSTree::InorderTraversal()
{
	InorderTraversal(m_root);
	cout << endl;
}

void BSTree::PostorderTraversal()
{
	PostorderTraversal(m_root);
	cout << endl;
}

void BSTree::DepthFirstSearch()
{
	DepthFirstSearch(m_root);
	cout << endl;
}

void BSTree::BreadthFirstSearch()
{
	BreadthFirstSearch(m_root);
	cout << endl;
}