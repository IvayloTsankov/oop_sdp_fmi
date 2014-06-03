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
void PrintList(const SLinkedList<T>& list)
{
    Node<int>* it = list.begin_iterator();
    while(it != NULL)
    {
        Print(it->data);
        it = it->next;
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

    SLinkedList<int> second_list = int_list;
    
    Print("SecondList: ");
    PrintList(second_list);

    int_list.clear();
    bool e = int_list.empty();
    Print("First list empty()?: ");
    Print(e);
    
    e = second_list.empty();
    Print("Second List empty()?: ");
    Print(e);

	Print("second list front(): ");
	Print(*(second_list.front()));

	Print("second list back(): ");
	Print(*(second_list.back()));

	Print("front after one pop_front(): ");
	second_list.pop_front();
	Print(*(second_list.front()));

	Print("back after one pop_back(): ");
	second_list.pop_back();
	Print(*(second_list.back()));

    Print("Before insert after: ");
	PrintList(second_list);

	Print("After insert 100 after 30");
	second_list.insert_after(30, 100);
	PrintList(second_list);

    Print("After erase 100: ");
    second_list.erase(100);
    PrintList(second_list);

    Print("after clear second_list: ");
    second_list.clear();
    e = second_list.empty();
    Print("second list is empty()?: ");
    Print(e);


	return 0;
}
