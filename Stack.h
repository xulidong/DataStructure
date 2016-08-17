#include <cstdio>
#include <cassert>
#include <iostream>

using namespace std;

class Stack
{
public:
	// **************************************************************************
	// 类的四大函数：构造函数、拷贝构造函数、重载赋值运算符、析构函数
	// **************************************************************************
	Stack();
	Stack(const Stack &Stack);
	Stack& operator=(const Stack &Stack);
	~Stack();

	// **************************************************************************
	// 增删改查
	// **************************************************************************
	void Push(const int& data);
	int Pop();

	unsigned short Size();
	bool IsEmpty();
	void PrintStack();

private:
	void Free();

private:
	typedef struct Node{
		Node(int d):data(d),next(NULL){}
		int data;
		struct Node* next;
	}Node;

	Node* m_head;
	Node* m_tail;
	unsigned short m_size;
};

// **************************************************************************
// 私有方法
// **************************************************************************
void Stack::Free()
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
Stack::Stack()
{
	m_head = NULL;
	m_tail = NULL;
	m_size = 0;
}

Stack::Stack(const Stack &Stack)
{
	m_head = NULL;
	m_tail = NULL;

	m_size = Stack.m_size;

	if(Stack.m_head){
		Node* tmp = Stack.m_head;
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

Stack& Stack::operator=(const Stack &Stack)
{
	Free();

	m_size = Stack.m_size;

	if(Stack.m_head){
		Node* tmp = Stack.m_head;
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

Stack::~Stack()
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
void Stack::Push(const int& data)
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

int Stack::Pop()
{
	assert(m_size > 0);

	Node* tmp = m_head;
	m_head = m_head->next;

	int val = tmp->data;
	delete tmp;
	--m_size;

	return val;
}

unsigned short Stack::Size()
{
	return m_size;
}

bool Stack::IsEmpty()
{
	return (m_size == 0);
}

void Stack::PrintStack()
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