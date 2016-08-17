#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

// ��
struct Edge{
	int vName;
	int weight;// Ȩֵ
	struct Edge* next;
};

// ����(����ͷ)
struct Vertex{
	int vName;	
	int in;// ���
	int out; // ����
	struct Edge* next;
};

// ����ͼ
class GraphList
{
public:
	~GraphList();

	void createGraph();
	void printGraph();
	bool topsortInDegree();
	bool topsortOutDegree();

private:
	// 1. ���붨����
	void inputVertexCount();
	// 2. ���ɶ�������
	void makeVertexArray();
	// 3. �������
	void inputEdgeCount();
	// 4. ����ߵ���ʼ��
	void inputEdgeInfo();
	// 5. ��ӱ߽ڵ�����Ӧ��������
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
	// ��ʼ��
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

		// ���
		int from = 0;
		cout << "From: ";
		cin >> from;
		
		// Ȩֵ
		int weight = 0;
		cout << "Weight:";
		cin >> weight;

		// �յ�
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
	++m_vVertex[vTo].in;	// �յ���ȼ�1
	++m_vVertex[vFrom].out;	// �����ȼ�1
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
	int* degree = new int[m_vCount];// ����һ����ʱ�������������ֵ��������������Ӱ��ԭʼ�ڵ��е�����
	
	// 1 ͳ�����Ϊ0�ĵ�
	for(int i = 0; i < m_vCount; ++i){
		degree[i] = m_vVertex[i].in;
		if(!degree[i]){
			vertexStack.push(&m_vVertex[i]);
		}
	}

	int count = 0;
	while(!vertexStack.empty()){
		// �������Ϊ0�ĵ�
		Vertex* tmp = vertexStack.top();
		vertexStack.pop();
		vertexQueue.push(tmp);
		++count;

		// 2 ��ͼ��ɾ���ý���Լ��������г��ߣ�����֮���ڵ���ȼ�1��
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
	
	// �ж��Ƿ��л�
	if (count < m_vCount) {
		return false;
	}

	// ���������
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
// ���̿���
// **************************************************************************
void GraphList::createGraph()
{
	inputVertexCount();
	makeVertexArray();
	inputEdgeCount();
	inputEdgeInfo();
}
