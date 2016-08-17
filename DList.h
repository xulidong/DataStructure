#include <cstdio>
#include <cassert>
#include <iostream>

using namespace std;

class DList
{
public:
	// **************************************************************************
	// 类的四大函数：构造函数、拷贝构造函数、重载赋值运算符、析构函数
	// **************************************************************************
	DList();
	DList(const DList &list);
	DList& operator=(const DList &list);
	~DList();

	// **************************************************************************
	// 增删改查
	// **************************************************************************
	void PushFront(const int& data);
	int PopFront();
	void PushBack(const int& data);
	int PopBack();

	void reverse();

	unsigned short size();
	bool isEmpty();
	void printList();

private:
	void Free();

private:
	typedef struct Node{
		Node(int d):data(d),next(NULL),prev(NULL){}
		int data;
		struct Node* next;
		struct Node* prev;
	}Node;

	Node* m_head;
	Node* m_tail;/* 这个变量加得有点鸡肋，最初是想用来操作链表尾，发现只有插入的时候能用，删除的时候用不了，因为没有前指针 */
	unsigned short m_size;
};

// **************************************************************************
// 私有方法
// **************************************************************************
void DList::Free()
{
	if(m_head){
		Node* tmp = NULL;
		while(m_head){
			tmp = m_head;
			m_head = m_head->next;
			delete tmp;
		}
	}
	m_head = NULL;
	m_tail = NULL;
	m_size = 0;
}

// **************************************************************************
// 类的四大函数：构造函数、拷贝构造函数、重载赋值运算符、析构函数
// **************************************************************************
DList::DList()
{
	m_head = NULL;
	m_tail = NULL;
	m_size = 0;
}

DList::DList(const DList &list)
{
	m_head = NULL;
	m_tail = NULL;

	m_size = list.m_size;

	if(list.m_head){
		Node* tmp = list.m_head;
		Node* q = NULL;
		while(tmp){
			Node* node = new Node(tmp->data);
			if(!m_head){
				m_head = node;
				q = m_head;
			}
			else{
				node->prev = q;
				q->next = node;
				q = node;
			}
			tmp = tmp->next;
		}
		m_tail = q; 
	}
	else{
		m_head = NULL;
		m_tail = NULL;
	}
}

DList& DList::operator=(const DList &list)
{
	Free();

	m_size = list.m_size;

	if(list.m_head){
		Node* tmp = list.m_head;
		Node* q = NULL;
		while(tmp){
			Node* node = new Node(tmp->data);
			if(!m_head){
				m_head = node;
				q = m_head;
			}
			else{
				node->prev = q;
				q->next = node;
				q = node;
			}

			tmp = tmp->next;
		}
		m_tail = q; 
	}
	else{
		m_head = NULL;
		m_tail = NULL;
	}

	return *this;
}

DList::~DList()
{
	if (m_head){
		Node* tmp = m_head;
		while (tmp){
			m_head = m_head->next;
			delete tmp;
			tmp = m_head;
		}
	}
	m_head = NULL;
	m_tail = NULL;
}

// **************************************************************************
// 增删改查
// **************************************************************************
void DList::PushFront(const int& data)
{
	Node* tmp = new Node(data);
	if (!m_head) {
		m_head = tmp;
		m_tail = tmp;
	}
	else{
		tmp->next = m_head;
		m_head->prev = tmp;
		m_head = tmp;
	}
	++m_size;
}

int DList::PopFront()
{
	assert(m_size > 0);

	Node* tmp = m_head;
	m_head = m_head->next;
	m_head->prev = NULL;

	int val = tmp->data;
	delete tmp;
	--m_size;

	return val;
}

void DList::PushBack(const int& data)
{
	Node* tmp = new Node(data);
	tmp->prev = m_tail;
	m_head ? (m_tail->next = tmp) : (m_head = tmp);
	m_tail = tmp;
	++m_size;
}

int DList::PopBack()
{
	assert(m_size > 0);

	int val = 0;
	Node *pre = m_tail->prev;
	if (!pre){
		val = m_tail->data;
		delete m_tail;
		m_head = NULL;
		m_tail = NULL;
		m_size = 0;
	}
	else{
		delete m_tail;
		m_tail = pre;
		m_tail->next = NULL;
		--m_size;
	}

	return val;
}

void DList::reverse()
{
	// 链表为空或只有一个元素，直接返回
	if (!m_head || !m_head->next){
		return;
	}

	Node* pre = m_head;  
	Node* cur = m_head->next; 
	Node* next = NULL;
	while (cur)  {  
		next = cur->next;  
		cur->next = pre;
		pre->prev = cur;
		pre = cur;
		cur = next;
	}  
	pre->prev = NULL;
	m_head->next = NULL;
	m_tail = m_head;
	m_head = pre;

}

unsigned short DList::size()
{
	return m_size;
}

bool DList::isEmpty()
{
	return (m_size == 0);
}

void DList::printList()
{
	cout << "size : " << m_size << " , content : " << endl;
	cout << "From Head:";
	if (m_head){
		Node* tmp = m_head;
		while (tmp){
			cout << tmp->data << " -> ";
			tmp = tmp->next;
		}
	}
	cout << "NULL" << endl;

	cout << "From Tail:";
	if (m_tail){
		Node* tmp = m_tail;
		while (tmp){
			cout << tmp->data << " -> ";
			tmp = tmp->prev;
		}
	}
	cout << "NULL" << endl;

}