#include <iostream>
#include "slinkedlist.h"
#include <cassert>

using namespace std;

template<typename T>
void Print(T& elem)
{
	cout << elem << endl;
}

template<typename T>
void PrintList(SLinkedList<T> list)
{
	for(int i = 0; i < list.size(); ++i)
	{
		Print(*(list.front()));
		list.pop_front();
	}
}

int main()
{
	SLinkedList<int> int_list;
	
	int_list.push_front(10);
	int_list.push_front(20);
	int_list.push_front(30);
	int_list.push_front(40);
	int_list.push_front(50);
	int_list.push_front(60);
	
	PrintList(int_list);


	return 0;
}