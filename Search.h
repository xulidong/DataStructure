#include <iostream>
using namespace std;

void printSearchResult(int index)
{
	if (index != -1){
		cout << "found " << index << endl;
	}
	else{
		cout << "not found" << endl;
	}
}

// ****************************************************************************************************
// ���ַ�����
// ƽ��ʱ�临�Ӷȣ�O(logn)
// ˼·���۰����
// ****************************************************************************************************
// �ݹ�
int recursiveBinarySearch( int *array, int key, int low, int high)
{
	if(low > high){
		return -1;
	}
	
	int mid = (low + high) / 2;
	if (key == array[mid]) {
		return mid;
	}
	else if (key < array[mid]) {
		return recursiveBinarySearch(array, key, low,mid -1);
	}
	else {
		return recursiveBinarySearch(array, key, mid + 1, high);
	}
}

//�ǵݹ�
int binarySearch(int *a, int key, int length)
{
	int left = 0;
	int right = length - 1;
	int mid = ( left + right ) / 2;

	while( left < right && a[mid] != key ) {
		if( key > a[mid]){
			left = mid + 1;
		}
		else if( key < a[mid]){
			right = mid - 1;
		}
		mid = ( left + right ) / 2;
	}

	if (key == a[mid]) {
		return mid;
	}

	return -1;
}