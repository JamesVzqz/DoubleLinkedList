
// Choose which run to compile
#define RUN0
//RUN1 RUN2 RUN3


#ifdef RUN0 

#include"dllist.h"
#include<iostream>

void main() {
	
	DLList<int> * l = new DLList<int>;; //DLList of integers

	// prove push_front, push_at, push rear, pop_front, pop_rear, pop_at, pop_item and print

	l->push_rear(1);
	l->push_front(5);
	l->push_front(7);
	l->push_front(4);
	l->push_front(42);
	l->push_rear(11);
	l->push_at(3, 10);

	l->print();

	int index = 0;

	std::cout << "\n" << "Empty?: " << l->empty() << "\n";

	std::cout << "\n" << "Pop rear: " << l->pop_rear() << "\n";
	l->print();

	std::cout << "\n" << "Pop front: " << l->pop_front() << "\n";
	l->print();

	std::cout << "\n" << "Pop rear: " << l->pop_rear() << "\n";
	l->print();

	std::cout << "\n" << "Pop item at index " << index << ": " << l->pop_at(index) << "\n";
	l->print();
	
	std::cout << "\n" << "Pop item 4, index is: " << l->pop_item(4) << "\n";
	l->print();

	std::cout << "\n";

	std::cout << "\n" << "Front item: " << l->front() << "\n";

	std::cout << "\n" << "Rear item: " << l->rear() << "\n";

	std::cout << "\n" << "Count of items: " << l->count() << "\n";

	std::cout << "\n" << "Item at index " << index << ": " << l->at(index) << "\n";

	std::cout << "\n" << "Index of item 5: " << l->find(5) << "\n";


}

#elif defined RUN1

#include"dllist.h"
#include"studentinfo.h"
#include<iostream>
#include<string>

void main() {

	std::cout << StudentInfo::name() << std::endl;
	std::cout << StudentInfo::id() << std::endl;

	DLList<std::string> * l = new DLList<std::string>; //DLList of integers

	l->push_rear("Hello");
	l->push_front("World");
	l->push_front("Bob");
	l->push_front("2");

	l->print(); // 2 Bob World Hello

	l->pop_rear();  // Will trip assert if empty
	l->print(); // 2 Bob World 

	std::cout << l->front() << std::endl; // 2

}

#elif defined RUN2

#define MAKE_MEMBERS_PUBLIC
#include"dllist.h"
#include<assert.h>

//Unit test example for push_font on initially empty list

void main() {

	// Step 1: Initial state
	// Assume that constructor implemented properly
	// If you're not sure if the constructor is 
	// implemented properly, STOP, go back and make
	// sure. Luckily the default constructor is 
	// done for you.  But the point remains, never,
	// ever, use a function in a test that isn't itself
	// verified to function according to spec.
	DLList<int> * l = new DLList<int>;


	// Step 2: Execute the function to test
	l->push_front(99);

	// Step 3: Verify what you expect to observe.
	// You must know what is supposed to happen in
	// order to analyze for correctness. Generally, 
	// you must permute all possible combinations
	// of all member variables.
	assert(l->head != nullptr);
	assert(l->tail != nullptr);
	assert(l->size == 1);
	assert(l->head->prev == nullptr);
	assert(l->head->next == nullptr);
	assert(l->head->item == 99);

	std::cout << "All assertions were successfull!" << "\n";

}

#else

#define MAKE_MEMBERS_PUBLIC
#include"dllist.h"
#include<assert.h>
#include<string>

//Unit test example for push_font on initially non empty list

void main() {

	// Step 1: Initial state
	// Same as above, except we must first populate the dllist
	// However, since we are testing push_front, we cannot
	// use it to generate the initial state of our list
	// to test.  So we have to manually set the initial state
	// in this case we are creating a list with three nodes.
	DLList<std::string>::Node* first = new DLList<std::string>::Node;
	DLList<std::string>::Node* second = new DLList<std::string>::Node;
	DLList<std::string>::Node* third = new DLList<std::string>::Node;

	// We have to manually linked everything together:
	first->item = "first";
	first->prev = nullptr;
	first->next = second;

	second->item = "second";
	second->prev = first;
	second->next = third;

	third->item = "third";
	third->prev = second;
	third->next = nullptr;

	// Now we create  DLList object and inject the initial control state:
	DLList<std::string> * l = new DLList<std::string>;
	l->head = first;
	l->tail = third;
	l->size = 3;

	// Step 2: Now with the list given a complete and correct starting state
	// We can test various member functions for correctness.
	// For example we can use this as one test for push_front;
	l->push_front("Zero");

	// Step 3: Verify:  Technically, we should examine all 
	// member variables, and all nodes' item, next, prev pointers
	// to ensure that the push_front didn't mangle any of the
	// internal nodes.  But, this is mostly just to illustrate
	// how you might develop your own tests.  
	assert(l->size == 4);
	assert(l->head->prev == nullptr);
	assert(l->head == first->prev);
	assert(l->head->next == first);
	assert(l->head->item == "Zero");
	assert(l->tail == third);

	std::cout << "All assertions were successfull!" << "\n";

}



#endif