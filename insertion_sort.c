#include <stdio.h>

void printArray(int arr[], int n) {
	int i = 0;
	for (i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/*
 * 将数字插入到已经有序的数组(数组中的第一个元素，认为是有序的)中，使数组任然有序，类似我们打扑克牌时摸牌的过程。
 * 过程：
 * 1 在有序的元素中"从前完后"找到插入的位置;
 * 2 保存要插入的元素(因为往后移的过程中会覆盖改元素)，将该位置之后的元素往后移(从后面开始移);
 * 3 插入该元素;
 * 4 重复1-3直到最后一个元素。
 * */
void insertionSort(int arr[], int n) {
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 1; i < n; ++i) {
		// 查找插入位置j
		for (j = 0; j < i ; ++j) {
			if (arr[i] < arr[j]) {
				break;
			}
		}
		if (j != i) {
			int tmp = arr[i];
			// 将插入位置之后的元素往后移
			for (k = i; k > j; --k) {
				arr[k] = arr[k - 1];
			}
			// 插入该元素
			arr[j] = tmp;
		}
	}
}

/*
 * 优化一，在查找插入位置的过程中移动元素。
 * */
void insertionSort1(int arr[], int n) {
	int i = 0;
	int j = 0;
	int k = 0;
	int tmp = 0;
	for (i = 1; i < n; ++i) {
		tmp = arr[i];
		// 查找插入位置，同时移动元素
		for (j = i; tmp < arr[j - 1] && j > 0 ; --j) {
			arr[j] = arr[j - 1];
		}
		// 简单的赋值，可不加此判断
		if (i != j) {
			// 插入该元素
			arr[j] = tmp;
		}
	}
}

int main() {
	int arr[10] = {0, 7, 2, 8, 1, 3, 4, 9, 5, 6};
	insertionSort1(arr, 10);
	printArray(arr, 10);// 输出:0, 1, 2, 3, 4, 5, 6, 7, 8, 9

	return 0;
};
