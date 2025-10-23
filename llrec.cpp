#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {

	//head recursion (do work on the way back after the recursive call)

	//base case - if head is empty
	if (head == nullptr) {
		smaller = nullptr;
		larger = nullptr;
	}
	
	Node* temp = head;

	llpivot(head->next, smaller, larger, pivot);

	//work on the way back
	if (temp->val <= pivot) {
		temp->next = smaller;
		smaller = temp;
	}
	else {
		temp->next = larger;
		larger = temp;
	}

	head = nullptr;
	
}