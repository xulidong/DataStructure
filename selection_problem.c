/*
 * 来源：《数据结构与算法分析》引论
 * 题目：选择性问题，从N个数中找出第k大者
 * 
 * */
#include <stdio.h>
#include <stdlib.h>

/*
* 输出数组
* */
void printfArray(int arr[], int n) {
	int i = 0;
	for (i = 0; i < n; ++i ) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/*
 * 冒泡排序
 * */
void bubble_sort(int arr[], int n) {
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; ++i) {
		for (j = 0; j < n - 1 - i; ++j) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

/*
 * 对数组进行排序，返回第k-1位置上的元素即为第k大者
 * */
int getMaxK1(int arr[], int n, int k) {
	// 拷贝数组，不要改变出入参数的值
	int i = 0;
	int* tmp = malloc(sizeof(int) * 10); 
	for (i = 0; i < n; ++i) { 
		tmp[i] = arr[i];	
	}
	
	bubble_sort(tmp, n);
	int ret = tmp[k - 1];
	free(tmp);
	tmp = NULL;

	return ret;	
}

/*
 * 1 读入数组前k个元素并排序
 * 2 将余下的元素依次与第k-1个元素对比，小则忽略
 * 3 大则插入数组的合适位置，同时挤出最后一个元素
 * 4 然会第k-1位置上的元素, 排序
 * */
int getMaxK2(int arr[], int n, int k) {
	int i = 0;
	int* tmp = malloc(sizeof(int) * k);
	for (i = 0; i < k; ++i) {
		tmp[i] = arr[i];
	}
	bubble_sort(tmp, k);
	
	int j = 0;
	for (j = i; j < n; ++j) {
		if (arr[j] > tmp[k - 1]) {
			tmp[k - 1] = arr[j];
			bubble_sort(tmp, k);
		}	
	}

	printfArray(tmp, k);
	int ret = tmp[k - 1];
	free(tmp);
	tmp = NULL;

	return ret;
}

int main() {
	int arr[] = {9, 7, 0, 6, 1, 2, 4, 3, 5, 8};// 10个数：0-9
	int k = 3;// 找第3大者
	printf("%d\n", getMaxK1(arr, 10, k)); // 输出7
	printf("%d\n", getMaxK2(arr, 10, k)); // 输出7

	return 0;
}
