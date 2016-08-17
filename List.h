#include <cstdio>
#include <cassert>
#include <iostream>

using namespace std;

class List
{
public:
	// **************************************************************************
	// 类的四大函数：构造函数、拷贝构造函数、重载赋值运算符、析构函数
	// **************************************************************************
	List();
	List(const List &list);
	List& operator=(const List &list);
	~List();

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
		Node(int d):data(d),next(NULL){}
		int data;
		struct Node* next;
	}Node;

	Node* m_head;
	Node* m_tail;/* 这个变量加得有点鸡肋，最初是想用来操作链表尾，发现只有插入的时候能用，删除的时候用不了，因为没有前指针 */
	unsigned short m_size;
};

// **************************************************************************
// 私有方法
// **************************************************************************
void List::Free()
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
List::List()
{
	m_head = NULL;
	m_tail = NULL;
	m_size = 0;
}

List::List(const List &list)
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

List& List::operator=(const List &list)
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

List::~List()
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
void List::PushFront(const int& data)
{
	Node* tmp = new Node(data);
	if (!m_head) {
		m_head = tmp;
		m_tail = tmp;
	}
	else{
		tmp->next = m_head;
		m_head = tmp;
	}
	++m_size;
}

int List::PopFront()
{
	assert(m_size > 0);

	Node* tmp = m_head;
	m_head = m_head->next;

	int val = tmp->data;
	delete tmp;
	--m_size;

	return val;
}

void List::PushBack(const int& data)
{
	Node* tmp = new Node(data);
	m_head ? (m_tail->next = tmp) : (m_head = tmp);
	m_tail = tmp;
	++m_size;
}

int List::PopBack()
{
	assert(m_size > 0);

	int val = 0;
	Node *cur, *pri;
	if (!m_head->next){
		val = m_head->data;
		delete m_head;
		m_head = NULL;
		m_tail = NULL;
		m_size = 0;
	}
	else{
		cur = m_head;
		while (cur->next->next){
			cur = cur->next;
		}
		pri = cur;
		m_tail = cur;
		cur = cur->next;
		pri->next = NULL;
		val = cur->data;
		delete cur;
		cur = NULL;

		--m_size;
	}

	return val;
}

void List::reverse()
{
	// 链表为空或只有一个元素，直接返回
	if (!m_head || !m_head->next){
		return;
	}
	
	Node *pri, *cur, *tmp;
	pri = m_head;
	cur = m_head->next;
	m_head->next = NULL;
	while (cur){
		tmp = cur->next;
		cur->next = pri;
		pri = cur;
		cur = tmp;
	}
	m_head = pri;
}

unsigned short List::size()
{
	return m_size;
}

bool List::isEmpty()
{
	return (m_size == 0);
}

void List::printList()
{
	cout << "size : " << m_size << " , content : ";
	if (m_head){
		Node* tmp = m_head;
		while (tmp){
			cout << tmp->data << " -> ";
			tmp = tmp->next;
		}
	}

	cout << "NULL" << endl;
}