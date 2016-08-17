#include <iostream>
#include <cstdio>
#include <iomanip>      // std::setw

#define  NO_EDGE (-1)

using namespace std;

// 有向图
class GraphMatrix
{
public:
	~GraphMatrix();

	void createGraph();
	void printGraph();

private:
	// 1. 输入定点数
	void inputVertexCount();
	// 2. 生成定点数组
	void makeVertexArray();
	// 3. 输入边数
	void inputEdgeCount();
	// 4. 输入边的起始点
	void inputEdgeInfo();
	// 5. 添加边节点至对应的链表中
	void addEdgeToList(int vFrom, int weight, int vTo);
private:
	int m_vCount;
	int m_eCount;
	int** m_vVertex;
};

GraphMatrix::~GraphMatrix(){
	for (int i = 0; i < m_vCount; ++i){
		delete m_vVertex[i];
	}
	delete[] m_vVertex;
}

void GraphMatrix::inputVertexCount()
{
	cout << "please input count of vertex:";
	cin >> m_vCount;
}

void GraphMatrix::makeVertexArray()
{
	m_vVertex = new int*[m_vCount];
	for (int i = 0; i < m_vCount; ++i){
		m_vVertex[i] = new int[m_vCount];
	}
	for (int i = 0; i < m_vCount; ++i){
		for (int j = 0; j < m_vCount; ++j){
			m_vVertex[i][j] = NO_EDGE;
		}
	}
}

void GraphMatrix::inputEdgeCount()
{
	cout << "please input count of edge:";
	cin >> m_eCount;
}

void GraphMatrix::inputEdgeInfo()
{
	cout << "please input edge information:" << endl;
	for (int i = 0; i < m_eCount; ++i){
		cout << "the edge " << i << ":" << endl;

		// 起点
		int from = 0;
		cout << "From: ";
		cin >> from;

		// 权值
		int weight = 0;
		cout << "Weight:";
		cin >> weight;

		// 终点
		int to = 0;
		cout << "To: ";
		cin >> to;
		cout << endl;

		addEdgeToList(from, weight, to);
	}
}

void GraphMatrix::addEdgeToList(int vFrom, int weight, int vTo)
{
	m_vVertex[vFrom][vTo] = weight;
}

void GraphMatrix::printGraph()
{
	for (int i = 0; i < m_vCount; ++i){
		for (int j = 0; j < m_vCount; ++j){
			cout << setw(3) << m_vVertex[i][j] << " ";
		}
		cout << endl;
	}
}

void GraphMatrix::toGraphList()
{

}

// **************************************************************************
// 流程控制
// **************************************************************************
void GraphMatrix::createGraph()
{
	inputVertexCount();
	makeVertexArray();
	inputEdgeCount();
	inputEdgeInfo();
}