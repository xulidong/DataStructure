#include "UnionFindSet.h"


UnionFindSet::UnionFindSet(unsigned int capacity) {
	m_parents = new int[capacity];
	m_depth = new int[capacity];
	for (auto i = 0; i < capacity; ++i) {
		*(m_parents + i) = i;
		*(m_depth + i) = 1;
	}
}
UnionFindSet::~UnionFindSet() {
	delete m_parents;
}

int UnionFindSet::find(int v) {
	if ((*(m_parents + v) == v)) {
		return v;
	} else {
		// return find(*(m_parents + v));

		// 路径压缩
		*(m_parents + v) = find(*(m_parents + v));
		return *(m_parents + v);
	}
	
}

void UnionFindSet::merge(int v1, int v2) {
	// 把v1的父节点改成v2的父节点
	// *(m_parents + find(v1)) = find(v2);

	// 按秩合并

	// 先找到两个根节点
	int x = find(*(m_parents + v1));
	int y = find(*(m_parents + v2));

	// 简单的树往复杂的树上合并
	if (*(m_depth + x) < *(m_depth + y)) {
		*(m_parents + x) = y;
	} else {
		*(m_parents + y) = x;
	}

	if (*(m_depth + x) == *(m_depth + y) && x != y) {
		// 如果深度相同且根节点不同，则新的根节点的深度+1
		*(m_depth + y) += 1;
	}
}

bool UnionFindSet::isSame(int v1, int v2) {
	return find(v1) == find(v2);
}
