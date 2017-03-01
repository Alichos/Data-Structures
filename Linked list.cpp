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

	void PushElement(int element){
		Node* new_node = new Node(element);
		if(first == NULL){
			first = new_node;
		} else {
			last->next = new_node;
		} last = new_node;
		size_of++;
	}

	Node* Find(int element){
		Node* actual_node = first;
		while(actual_node != NULL){
			if(actual_node->value == element){
				return actual_node;
			} actual_node = actual_node->next;
		} return NULL;
	}

	//When the last element is deleted;
	void SpecialCase(){
		if(size_of == 1){
			first = last = NULL; return;
		}

		Node* actual_node = first;
		for(int i = 0; i < size_of - 2; i++){
			actual_node = actual_node->next;
		} delete actual_node->next; 
		actual_node->next = NULL; 
		last = actual_node;
	}

	void DeleteElement(int element){
		Node* deleted_element = Find(element);

		if(deleted_element == NULL) return;

		Node* to_delete = deleted_element->next;

		if(to_delete == NULL){
			SpecialCase();
			size_of--; return;
		}

		deleted_element->value = to_delete->value;
		deleted_element->next = to_delete->next;

		delete to_delete; size_of--;
	}

	int Size(){
		return size_of;
	}
};

int main(){
	return 0;
}
