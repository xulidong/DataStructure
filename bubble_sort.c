#include <stdio.h>

/*
 * 打印数组
 * */
void printArray(int arr[], int n) {
    int i = 0;
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
 * 冒泡排序，过程：
 * 1 从第一个元素开始，依次与相邻的数比较，若前一个小，则交换位置；
 * 2 直至最后一个元素，结束后最后大元素就在最后的位置了。
 * 3 重复1，直至倒数第二个元素；
 * 4 重复1，直至倒数第三个元素；
 * 5 重复1，直到只剩下第一个元素。
 * */
void bubbleSort(int arr[], int n) {
    int i = 0;
    int j = 0;
    int tmp = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n - 1 - i; ++j) {
            if (arr[j] < arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

/*
 * 冒泡排序优化一
 * 设置一个标记来标志一趟比较是否发生交换
 * 如果没有发生交换，则数组已经有序
 * */
void bubbleSort1(int arr[], int n) {
    int i = 0;
    int j = 0;
    int tmp = 0;
    int flag = 0;
    for (i = 0; i < n; ++i) {
        flag = 0;
        for (j = 0; j < n - 1 - i; ++j) {
            if (arr[j] < arr[j + 1]) {
                flag = 1;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

/*
 * 冒泡排序优化二
 * 用一个变量记录下最后一个发生交换的位置，后面没有发生交换的已经有序
 * 所以可以用这个值来作为下一次比较结束的位置
 * */
void bubbleSort2(int arr[], int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp = 0;
    int flag = n;

    for (i = 0; i < flag; ++i) {
        k = flag;
        flag = 0;
        for (j = 0; j < k; ++j) {
            if (arr[j] < arr[j + 1]) {
                flag = j;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
int main() {
    int arr[] = {9, 5, 8, 4, 7, 3, 2, 0, 6, 1};
    printArray(arr, 10);
    bubbleSort2(arr, 10);
    printArray(arr, 10);

    return 0;
}
