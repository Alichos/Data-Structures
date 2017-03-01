#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int value;
	Node* next;

	Node(int element): 
		value(element), next(NULL) {}
};

struct LinkedList{ 
	int size_of;
	Node* first, *last;
	LinkedList(): 
		first(NULL), last(NULL), size_of(0) {}

	void pushElement(int element){
		Node * new_node = new Node(element);
		if(first == NULL){
			first = new_node;
		} else {
			last->next = new_node;
		} last = new_node;
		size_of++;
	}

	Node* find(int element){
		Node* actual_node = first;
		while(actual_node != NULL){
			if(actual_node->value == element){
				return actual_node;
			} actual_node = actual_node->next;
		} return NULL;
	}

	void deleteElement(int element){
		Node* deleted_element = find(element);

		if(deleted_element == NULL) return;

		Node* to_delete = deleted_element->next;

		deleted_element->value = deleted_element->next->value;
		deleted_element->next = deleted_element->next->next;

		delete to_delete;
	}

	int size(){
		return size_of;
	}
};

int main(){
	return 0;
}
