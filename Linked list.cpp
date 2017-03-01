#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct node{
	int value;
	node* next;

	node(int element): 
		value(element), next(NULL) {}
};

struct linkedList{ 
	int size_of;
	node* first, *last;
	linkedList(): 
		first(NULL), last(NULL), size_of(0) {}

	void pushElement(int element){
		node * new_node = new node(element);
		if(first == NULL){
			first = new_node;
		} else {
			last->next = new_node;
		} last = new_node;
		size_of++;
	}

	node* find(int element){
		node* actual_node = first;
		while(actual_node != NULL){
			if(actual_node->value == element){
				return actual_node;
			} actual_node = actual_node->next;
		} return NULL;
	}

	void deleteElement(int element){
		node* deleted_element = find(element);
		if(deleted_element == NULL) return;
		deleted_element->value = deleted_element->next->value;
		deleted_element->next = deleted_element->next->next;

		delete deleted_element->next;
	}

	int size(){
		return size_of;
	}
};

int main(){
	return 0;
}
