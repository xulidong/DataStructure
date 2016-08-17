#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Array
{
public:
	// **************************************************************************
	// 类的四大函数：构造函数、拷贝构造函数、重载赋值运算符、析构函数
	// **************************************************************************
	// 默认构造函数
	Array(int size, int val = 0);
	// 拷贝构造函数
	Array(const Array &array);
	// 重载赋值运算符
	Array& operator= (const Array &array);
	// 析构函数
	~Array();

	// **************************************************************************
	// 重载
	// **************************************************************************
	int operator[](int index) const;

	// **************************************************************************
	// 增删改查
	// **************************************************************************
	void InsertAt(int index, int val);
	void PushBack(int val);
	void DeleteAt(int index);
	void SetAt(int index, int val);
	int GetAt(int index);

	void SetSize(int size);
	int GetSize();

	void printArray();

private:
	// 初始化
	void Init();
	// 释放动态内存
	void Free();
	// 判断下表是否合法
	bool isValidIndex(int index);
	// 扩展内存空间
	void getMoreMememory();

private:
	int *m_array;
	int m_size;
	int m_max;
};


// **************************************************************************
// 私有方法
// **************************************************************************
void Array::Init()
{
	m_size = 0;
	m_max = 1;
	m_array = new int[m_max];
}

void Array::Free()
{
	delete[] m_array;
}

bool Array::isValidIndex(int index)
{
	if (index >= 0 && index < m_size){
		return true;
	} 

	return false;
}

void Array::getMoreMememory()
{
	m_max *= 2;
	int* tmp = new int[m_max];
	memcpy(tmp, m_array, m_size * sizeof(int));
	delete[] m_array;
	m_array = tmp;
}

// **************************************************************************
// 类的四大函数：构造函数、拷贝构造函数、重载赋值运算符、析构函数
// **************************************************************************
Array::Array(int size, int val)
{
	if (size > 0){
		m_size = size;
		m_max = size;
		m_array = new int[m_max];
		for(int i=0; i < m_size; ++i){
			m_array[i] = val;
		}
	}
	else if (size == 0){
		Init();
	}
	else{
		cout << "Invalid size:"<< size << endl;
		exit(0);
	}
}

Array::Array(const Array& array)
{
	m_size = array.m_size;
	m_max = array.m_max;
	m_array = new int[array.m_max];
	memcpy(m_array, array.m_array, array.m_max * sizeof(int));
}

Array& Array::operator=(const Array& array)
{
	if (this != &array){
		m_size = array.m_size;
		m_max = array.m_size;
		Free();
		m_array = new int[array.m_max];
		memcpy(m_array, array.m_array, array.m_max * sizeof(int));
	}

	return *this;
}

Array::~Array()
{
	Free();
}

// **************************************************************************
// 重载
// **************************************************************************
int Array::operator[](int index) const
{
	// 此函数常函数，不能调用isValidIndex
	if ( index >= 0 && index < m_size ){
		return m_array[index];
	}else{
		cout << "Invalid index:" << index << endl;	
		exit(0);
	}
}

// **************************************************************************
// 增删改查
// **************************************************************************
void Array::InsertAt(int index, int val)
{
	if ( !isValidIndex(index) ){
		cout << "invalid index:" << index << endl;
		exit(0);
	}

	if (m_size >= m_max){
		getMoreMememory();
	}

	for(int i = index; i < m_size; ++i){
		m_array[i + i] = m_array[i];
	}
	m_array[index] = val;
	++m_size;
}

void Array::PushBack(int val)
{
	if (m_size >= m_max){
		getMoreMememory();
	}

	m_array[m_size] = val;
	++m_size;
}

void Array::DeleteAt(int index)
{
	if ( !isValidIndex(index) ){
		cout << "invalid index:" << index << endl;
		exit(0);
	}

	for (int i = index; i < m_size; ++i){
		m_array[i] = m_array[i+1];
		m_array[m_size-1] = 0;
		--m_size;
	}
}

void Array::SetAt(int index, int val)
{
	if ( !isValidIndex(index) ){
		cout << "invalid index:" << index << endl;
		exit(0);
	}
	m_array[index] = val;
}

int Array::GetAt(int index)
{
	if ( !isValidIndex(index) ){
		cout << "invalid index:" << index << endl;
		exit(0);
	}
	return m_array[index];
}

void Array::SetSize(int size)
{
	if (size < m_size){
		for(int i = size; i < m_size; ++i){
			m_array[i] = 0;
		}
	}
	else if (size >= m_size){
		if (size > m_max) {
			m_max = size;
			int* tmp = new int[m_max];
			memcpy(tmp, m_array, m_size*sizeof(int));
			m_array = tmp;
		}
		for(int i = m_size; i < size; ++i){
			m_array[i] = 0;
		}
	}
	m_size = size;
}

int Array::GetSize()
{
	return m_size;
}

void Array::printArray()
{
	if(m_size == 0) 
	{ 
		cout << "this array is empty." << endl; 
		exit(0); 
	} 
	else
	{ 
		for(int i=0; i<m_size; ++i) 
			cout << "[" << i << "]" << m_array[i] << endl; 
	}
	cout << endl;
}