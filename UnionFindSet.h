/* 并查集 */

#ifndef UNION_FIND_SET_H
#define UNION_FIND_SET_H

class UnionFindSet {
public:
	UnionFindSet(unsigned int capacity);
	~UnionFindSet();


	// 查找v所属集合的跟结点
	int find(int v);
	
	// 合并v1和v2所属的集合
	void merge(int v1, int v2);

	// 检测v1和v2是否属于同一个集合
	bool isSame(int v1, int v2);
private:
	int* m_parents; // 记录父节点的下标
	int* m_depth; // 记录每个父节点的深度
};

#endif