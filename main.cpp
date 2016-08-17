#include <cstdlib>

/* 
// test for array
#include "Array.h"

int mainFor()
{
	Array arr1(2);
	arr1.printArray();
	arr1.InsertAt(1, 1);
	arr1.printArray();

	arr1.DeleteAt(1);
	Array arr2(arr1);
	arr2.printArray();

	arr1.SetAt(1, 1);
	Array arr3 = arr1;
	arr3.printArray();

	arr3.PushBack(2);
	cout << "size:" << arr3.GetSize()<< endl;
	cout << "GetAt(2):" << arr3.GetAt(2) << endl;
	cout << "[2]:" << arr3[2] << endl;

	system("pause");

	return 0;
}
*/

/* 
// test for String.h
#include "String.h"
#include <cstdlib>

int main()
{
	String s;
	cin >> s;
	cout << s << ":" << s.size() << endl;

	char a[] = "Hello", b[] = "World";
	String s1(a), s2(b);
	cout << s1 << " + " << s2 << " = " << s1 + s2 << endl;

	String s3 = s1 + s2;
	if (s1 == s3){
		cout << "first: s1 == s3" << endl;
	}

	s1 += s2;
	if (s1 == s3){
		cout << "Second: s1 == s3" << endl;
	}

	system("pause");

	return 0;
}
*/

// test for list
//#include "List.h"
//#include <cstdlib>
//#include <iostream>
//#include <list>
//
//using namespace std;
//
//int main()
//{
//	List list;
//	for (int i = 1; i < 5; ++i){
//		list.PushFront(i);
//	}
//	list.printList();
//
//	list.PushBack(0);
//	list.printList();
//
//	List listCopy(list);
//	listCopy.printList();
//
//	List listAssig;
//	listAssig = list;
//	listAssig.printList();
//
//	int popfront = list.PopFront();
//	cout << "popfront:" << popfront << endl;
//	list.printList();
//
//	int popback = list.PopBack();
//	cout << "popback:" << popback << endl;
//	list.printList();
//
//
//	list.reverse();
//	cout << "do reverse..." << endl;
//	list.printList();
//
//	system("pause");
//
//	return 0;
//}

// test for Stack
//#include "Stack.h"
//#include <cstdlib>
//#include <iostream>
//#include <list>
//
//using namespace std;
//
//int main()
//{
//	Stack stack;
//	for (int i = 1; i < 5; ++i){
//		stack.Push(i);
//	}
//	stack.PrintStack();
//
//	Stack stackCopy(stack);
//	stackCopy.PrintStack();
//
//	Stack stackAssig;
//	stackAssig = stack;
//	stackAssig.PrintStack();
//
//	int pop = stack.Pop();
//	cout << "pop:" << pop << endl;
//	stack.PrintStack();
//
//	system("pause");
//
//	return 0;
//}

// test for Queue
//#include "Queue.h"
//#include <cstdlib>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	Queue queue;
//	for (int i = 1; i < 5; ++i){
//		queue.Push(i);
//	}
//	queue.PrintQueue();
//
//	Queue queueCopy(queue);
//	queueCopy.PrintQueue();
//
//	Queue queueAssig;
//	queueAssig = queue;
//	queueAssig.PrintQueue();
//
//	int pop = queue.Pop();
//	cout << "pop:" << pop << endl;
//	queue.PrintQueue();
//
//	system("pause");
//
//	return 0;
//}

// test for double list
//#include "DList.h"
//#include <cstdlib>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	DList list;
//	for (int i = 1; i < 5; ++i){
//		list.PushFront(i);
//	}
//	list.printList();
//
//	list.PushBack(0);
//	list.printList();
//
//	DList listCopy(list);
//	listCopy.printList();
//
//	DList listAssig;
//	listAssig = list;
//	listAssig.printList();
//
//	int popfront = list.PopFront();
//	cout << "popfront:" << popfront << endl;
//	list.printList();
//
//	int popback = list.PopBack();
//	cout << "popback:" << popback << endl;
//	list.printList();
//
//
//	list.reverse();
//	cout << "do reverse..." << endl;
//	list.printList();
//
//	system("pause");
//
//	return 0;
//}


// test for BSTree
//#include "BSTree.h"
//#include <cstdlib>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	BSTree tree;
//	int arr[6] = {5, 4, 8, 1, 7, 10};
//	for (int i = 0; i < 6; ++i){
//		tree.Insert(arr[i]);
//	}
//	
//	tree.PreorderTraversal();
//	tree.InorderTraversal();
//	tree.PostorderTraversal();
//	tree.DepthFirstSearch();
//	tree.BreadthFirstSearch();
//
//	tree.Remove(4);
//	tree.PreorderTraversal();
//
//	tree.Remove(1);
//	tree.PreorderTraversal();
//
//	tree.Remove(10);
//	tree.PreorderTraversal();
//
//	cout << "size:" << tree.Size() << endl;
//	cout << "deep:" << tree.Deep() << endl;
//	cout << "leaf:" << tree.Leaf() << endl;
//
//	system("pause");
//	return 0;
//}

// test for GraphList
//#include "GraphList.h"
//#include <cstdlib>
//
//int main()
//{
//	GraphList graph;
//	graph.createGraph();
//	graph.printGraph();
//	graph.topsort();
//
//	system("pause");
//
//	return 0;
//}

// test for GraphMartrix
//#include "GraphMatrix.h"
//#include <cstdlib>
//
//	int main()
//{
//	GraphMatrix graph;
//	graph.createGraph();
//	graph.printGraph();
//
//	system("pause");
//
//	return 0;
//}


// test for InsertionSort.h
//#include <iostream>
//#include <cstdlib>
//#include "Sort.h"
//using namespace std;
//
//int main()
//{
//	int array[] = {1,4, 10, 12, 2, 5,7, 10};
//	int length = (sizeof(array) / sizeof(array[0]));
//	printArray(array, length);
//	MergeSort(array, length);
//	printArray(array, length);
//
//	system("pause");
//
//	return 0;
//}

// test for binary search
//#include <iostream>
//#include <cstdlib>
//#include "Search.h"
//
//using namespace std;
//
//int main()
//{
//	int array[] = {1,4, 10, 12, 2, 5,7, 10};
//	int length = (sizeof(array) / sizeof(array[0]));
//
//	int index = binarySearch(array, 12, length);
//	printSearchResult(index);
//
//	index = recursiveBinarySearch(array, 5, 0, (length-1));
//	printSearchResult(index);
//
//	system("pause");
//
//	return 0;
//}


 //test for binary search
#include "YangHuiSanJiao.h"

int main()
{
	printSJ();
	system("pause");
	return 0;
}