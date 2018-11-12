#include <iostream>

#include <string>
#include <fstream>

using namespace std;

// Example of removing duplicates in a linked-list (as seen in class).
// This code is not ideal, it is for illustration purposes.
// You are strongly recommended to create Classes when you write your own programs.

struct EmailType {
	int id;
	string too;
	EmailType * link;
};

void print(EmailType * list) {
	EmailType * current = list;
	while(current) {
		cout << "ID: " << current->id << "\t" << current->too << endl;
		current = current->link;
	}
}

// we saw this in class
void deleteNodesById(int id, EmailType * list) {
	EmailType * lastVisited = list;
	while(lastVisited) {
		if(lastVisited->link) {
			if( id == lastVisited->link->id ) {
				// found a duplicate, update the links, delete it
				EmailType * temp = lastVisited->link;
				lastVisited->link = lastVisited->link->link;
				delete temp;
			}
			else {
				lastVisited = lastVisited->link;
			}
		}
		else {
			lastVisited = NULL;
		}
	}
}

// we saw this in class
void deleteDuplicates(EmailType * list) {
	EmailType * current = list;
	while(current) {
		deleteNodesById(current->id, current);
		current = current->link;
	}
}

int main()
{
	// initialize a list, we want 'head' to always point to the first element of the list
	EmailType * head = 0;

	// Step 1. add a new element (directly) to the list
	head = new EmailType;
	head->id = 1;
	head->too = string("one");
	head->link = NULL;
	// print the list 
	cout << endl << "List at step 1" << endl;
	print(head);

	// Step 2. add another element to the list (manually to the end of the list)
	head->link = new EmailType;
	head->link->id = 2;
	head->link->too = string("two");
	head->link->link = 0; // zero here is equivalent to NULL
	cout << endl << "List at step 2" << endl;
	print(head);

	// Step 3. add yet another element to the list (manually at the begining of the list)
	EmailType * node = new EmailType;
	node->id = 3;
	node->too = string("three");
	node->link = head;  // connect the node to the list
	head = node;  // the head of the list now points to the (newly created) node
	cout << endl << "List at step 3" << endl;
	print(head);

	// Step 4: similar to previous step, but add a few duplicates (at begining of the list)
	// The variable 'node' is just re-used
	for( int i = 0; i < 3; i++ ) {
		node = new EmailType;
		node->id = 2;
		node->too = string("twos");
		node->link = head;  // connect the node to the list
		head = node;  // the head of the list now points to the (newly created) node
	}
	cout << endl << "List at step 4" << endl;
	print(head);

	// Step 5. add another '3' element to the list to make things interesting (manually at the begining of the list)
	node = new EmailType;
	node->id = 3;
	node->too = string("three");
	node->link = head;  // connect the node to the list
	head = node;  // the head of the list now points to the (newly created) node
	cout << endl << "List at step 5" << endl;
	print(head);

	// delete duplicates
	deleteDuplicates(head);
	cout << endl << "List after delete duplicates" << endl;
	print(head);

	// clean up memory from last node to firs (because I'm not writing a method to do it via a while loop)
	// and I know for sure that there are only three nodes at this point in the list.
	delete head->link->link;
	delete head->link;
	delete head;
}
