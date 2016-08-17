#include<iostream>
#include <cstring>
using namespace std;

// ****************************************************************************************************
// 打印数组
// ****************************************************************************************************
void printArray(int array[], int length)
{
	for(int i = 0; i < length; ++i){
		cout << array[i] << " ";
	}
	cout << endl;
}

// ****************************************************************************************************
// 冒泡排序(升序)
// 稳定排序
// 平均时间复杂度：O(n^2)
// 思路：依次选取一个数与其相邻的比较，如果选取的数更大就交换位置
// ****************************************************************************************************
void BubbleSort(int array[], int length)
{
	for(int i = 0; i < length - 1; ++i){
		for(int j = 0; j < length - i - 1; ++j){
			if (array[j] > array[j + 1]) {
				// 交换两个数的值(可以参考我的另一篇文字：http://blog.csdn.net/xufeng0991/article/details/40648961)
				array[j+1] ^= array[j] ^= array[j+1] ^= array[j];
			}
		}
	}
}

// ****************************************************************************************************
// 直接插入排序(升序)
// 稳定排序
// 平均时间复杂度：O(n^2)
// 思路：从未排序的部分数组中选取一个数，往已排序部分中插入
// (类似我们摸牌一样，开始在下面的牌都是无序的，拿到手里插入到手中有序拍的合适位置，使其仍然有序)
// ****************************************************************************************************
void InsertionSort(int array[], int length)
{
	for(int i = 1; i < length; ++i){
		int tmp = array[i];
		int j = i;
		for(; j > 0 && tmp < array[j-1]; --j){
			array[j] = array[j-1];
		}
		array[j] = tmp;
	}
}

// ****************************************************************************************************
// 归并(升序)
// 稳定排序
// 平均时间复杂度：O(nlogn)
// 思路：归并两个已有序的数组
// ****************************************************************************************************
// 合并二个有序数列array[begin...mid]和array[mid+1...end]合并
void Merge(int array[], int begin, int mid, int end, int temp[])
{
	int left = begin, right = mid + 1;  
	int k = 0;  

	while (left <= mid && right <= end) {  
		if (array[left] < array[right]) {
			temp[k++] = array[left++];
		}
		else {  
			temp[k++] = array[right++];  
		}
	}  

	while (left <= mid) {
		temp[k++] = array[left++];  
	}

	while (right <= end)  {
		temp[k++] = array[right++];  
	}

	for (int i = 0; i < k; ++i) {
		array[begin + i] = temp[i]; 
	}
} 

void MergePass(int array[], int begin, int end, int* tmp)
{
	if (begin < end) {
		// 把长度为n的输入序列分成两个长度为n/2的子序列, 进行归并
		int mid = (begin + end)/2;
		MergePass(array, begin, mid, tmp);
		MergePass(array, mid + 1, end, tmp);
		// 将两个排序好的子序列合并成一个最终的排序序列
		Merge(array, begin, mid, end, tmp);
	}
	printArray(array, end + 1);
}

void MergeSort(int array[], int length)
{
	int* tmp = new int[length];
	MergePass(array, 0, length - 1, tmp);
	delete[] tmp;
}