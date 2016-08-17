#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

// 边
struct Edge{
	int vName;
	int weight;// 权值
	struct Edge* next;
};

// 顶点(链表头)
struct Vertex{
	int vName;	
	int in;// 入度
	int out; // 初度
	struct Edge* next;
};

// 有向图
class GraphList
{
public:
	~GraphList();

	void createGraph();
	void printGraph();
	bool topsortInDegree();
	bool topsortOutDegree();

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
	Vertex* m_vVertex;
};

GraphList::~GraphList(){
	for (int i = 0; i < m_vCount; ++i){
		Edge* tmp = m_vVertex[i].next;
		Edge* edge = NULL;
		while(tmp){
			edge = tmp;
			tmp = tmp->next;
			delete edge;
			edge = NULL;
		}
	}
	delete[] m_vVertex;
}

void GraphList::inputVertexCount()
{
	cout << "please input count of vertex:";
	cin >> m_vCount;
}

void GraphList::makeVertexArray()
{
	m_vVertex = new Vertex[m_vCount];
	// 初始化
	for (int i = 0; i < m_vCount; ++i){
		m_vVertex[i].vName = i;
		m_vVertex[i].next = NULL;
		m_vVertex[i].in = 0;
		m_vVertex[i].out = 0;
	}
}

void GraphList::inputEdgeCount()
{
	cout << "please input count of edge:";
	cin >> m_eCount;
}

void GraphList::inputEdgeInfo()
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

void GraphList::addEdgeToList(int vFrom, int weight, int vTo)
{
	Edge* edge = new Edge();
	edge->vName = vTo;
	edge->weight = weight;
	edge->next = NULL;
	Edge* tmp = m_vVertex[vFrom].next;
	if (tmp){
		while(tmp->next){
			tmp = tmp->next;
		}
		tmp->next = edge;
	}else{
		m_vVertex[vFrom].next = edge;
	}
	++m_vVertex[vTo].in;	// 终点入度加1
	++m_vVertex[vFrom].out;	// 起点初度加1
}

void GraphList::printGraph()
{
	for (int i = 0; i < m_vCount; ++i){
		Edge* tmp = m_vVertex[i].next;
		cout << "list:" << m_vVertex[i].vName << "(in:" << m_vVertex[i].in << ")"<< "->";
		while(tmp){
			cout << "(weight:" << tmp->weight << ")";
			cout << tmp->vName << "->";
			tmp = tmp->next;
		}
		cout << "NULL" << endl;
	}
}

bool GraphList::topsortInDegree()
{
	stack<Vertex*> vertexStack;
	queue<Vertex*> vertexQueue;
	int* degree = new int[m_vCount];// 声明一个临时变量，保存入度值，作操作，避免影响原始节点中的数据
	
	// 1 统计入度为0的点
	for(int i = 0; i < m_vCount; ++i){
		degree[i] = m_vVertex[i].in;
		if(!degree[i]){
			vertexStack.push(&m_vVertex[i]);
		}
	}

	int count = 0;
	while(!vertexStack.empty()){
		// 保存入度为0的点
		Vertex* tmp = vertexStack.top();
		vertexStack.pop();
		vertexQueue.push(tmp);
		++count;

		// 2 从图中删除该结点以及它的所有出边（即与之相邻点入度减1）
		Edge* edge = tmp->next;
		while(edge){
			Vertex* vertex = &m_vVertex[edge->vName];
			--degree[edge->vName];
			if (!degree[edge->vName]){
				vertexStack.push(vertex);
			}
			edge = edge->next;
		}
	}
	
	// 判断是否有环
	if (count < m_vCount) {
		return false;
	}

	// 输出排序结果
	while(!vertexQueue.empty()){
		Vertex* tmp = vertexQueue.front();
		vertexQueue.pop();
		cout << tmp->vName << " ";
	}
	cout << endl;

	delete[] degree;

	return true;
}

// **************************************************************************
// 流程控制
// **************************************************************************
void GraphList::createGraph()
{
	inputVertexCount();
	makeVertexArray();
	inputEdgeCount();
	inputEdgeInfo();
}
