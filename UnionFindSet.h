/* ���鼯 */

#ifndef UNION_FIND_SET_H
#define UNION_FIND_SET_H

class UnionFindSet {
public:
	UnionFindSet(unsigned int capacity);
	~UnionFindSet();


	// ����v�������ϵĸ����
	int find(int v);
	
	// �ϲ�v1��v2�����ļ���
	void merge(int v1, int v2);

	// ���v1��v2�Ƿ�����ͬһ������
	bool isSame(int v1, int v2);
private:
	int* m_parents; // ��¼���ڵ���±�
	int* m_depth; // ��¼ÿ�����ڵ�����
};

#endif