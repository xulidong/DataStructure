#include<iostream>
#include <cstring>
using namespace std;

// ****************************************************************************************************
// ��ӡ����
// ****************************************************************************************************
void printArray(int array[], int length)
{
	for(int i = 0; i < length; ++i){
		cout << array[i] << " ";
	}
	cout << endl;
}

// ****************************************************************************************************
// ð������(����)
// �ȶ�����
// ƽ��ʱ�临�Ӷȣ�O(n^2)
// ˼·������ѡȡһ�����������ڵıȽϣ����ѡȡ��������ͽ���λ��
// ****************************************************************************************************
void BubbleSort(int array[], int length)
{
	for(int i = 0; i < length - 1; ++i){
		for(int j = 0; j < length - i - 1; ++j){
			if (array[j] > array[j + 1]) {
				// ������������ֵ(���Բο��ҵ���һƪ���֣�http://blog.csdn.net/xufeng0991/article/details/40648961)
				array[j+1] ^= array[j] ^= array[j+1] ^= array[j];
			}
		}
	}
}

// ****************************************************************************************************
// ֱ�Ӳ�������(����)
// �ȶ�����
// ƽ��ʱ�临�Ӷȣ�O(n^2)
// ˼·����δ����Ĳ���������ѡȡһ�������������򲿷��в���
// (������������һ������ʼ��������ƶ�������ģ��õ�������뵽���������ĵĺ���λ�ã�ʹ����Ȼ����)
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
// �鲢(����)
// �ȶ�����
// ƽ��ʱ�临�Ӷȣ�O(nlogn)
// ˼·���鲢���������������
// ****************************************************************************************************
// �ϲ�������������array[begin...mid]��array[mid+1...end]�ϲ�
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
		// �ѳ���Ϊn���������зֳ���������Ϊn/2��������, ���й鲢
		int mid = (begin + end)/2;
		MergePass(array, begin, mid, tmp);
		MergePass(array, mid + 1, end, tmp);
		// ����������õ������кϲ���һ�����յ���������
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