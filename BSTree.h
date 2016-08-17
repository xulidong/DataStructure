#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// binary search tree�����ķ���Ϊ������������������������߶��������������ΪBST
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
	// ����Ĵ��������캯�����������캯�������ظ�ֵ���������������
	// **************************************************************************
	BSTree();
	~BSTree();

	// **************************************************************************
	// ��ɾ�Ĳ�
	// **************************************************************************
	void Insert(int x);
	void Remove(int x);

	// ���ض������ĸ���
	unsigned short Size();
	unsigned short Deep();
	unsigned short Leaf();

	bool IsEmpty();

	// ����
	void PreorderTraversal();	// �������
	void InorderTraversal();	// �������
	void PostorderTraversal();	// �������
	void DepthFirstSearch();	// ������ȱ���
	void BreadthFirstSearch();	// ������ȱ���

private:
	void Remove(int x, Node** pNode);

	// �ݹ�������������
	unsigned short CountSize(Node* n);
	unsigned short CountDeep(Node* n);
	unsigned short CountLeaf(Node* n);

	// �ݹ����
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
// ˽�з���
// **************************************************************************
/* 
//1 ����������ݴ�����ʲô���⣿
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
node��һ���ֲ���������node�Ĳ�����delete֮�ⶼ������Ч

// 2 ���ʣ�����Ĵ�����ʲô���⣿
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
ͬ�������⣬��Ȼ���ﴫ�ݵĲ�����ָ�룬����Node* node = *pNode;�����˿�����

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
// ����Ĵ��������캯�����������캯�������ظ�ֵ���������������
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
// ��ɾ�Ĳ�
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