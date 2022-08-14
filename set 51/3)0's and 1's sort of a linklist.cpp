// https://www.geeksforgeeks.org/sort-a-linked-list-of-0s-and-1s/#:~:text=Traverse%20the%20given%20linked%20list,nodes%20with%20the%20value%201.


#include <bits/stdc++.h>
using namespace std;

// Link list node
class Node {
public:
	int data;
	Node* next;
};

// Function to print linked list
void printList(Node* node)
{
	// Iterate until node is NOT NULL
	while (node != NULL) {

		// Print the data
		cout << node->data << " ";
		node = node->next;
	}
}

// Function to sort the linked list
// consisting of 0s and 1s
void sortList(Node* head)
{
	// Base Case
	if ((head == NULL)
		|| (head->next == NULL)) {
		return;
	}

	// Store the count of 0s and 1s
	int count0 = 0, count1 = 0;

	// Stores the head node
	Node* temp = head;

	// Traverse the list Head
	while (temp != NULL) {

		// If node->data value is 0
		if (temp->data == 0) {

			// Increment count0 by 1
			count0++;
		}

		// Otherwise, increment the
		// count of 1s
		else {
			count1++;
		}

		// Update the temp node
		temp = temp->next;
	}

	// Update the temp to head
	temp = head;

	// Traverse the list and update
	// the first count0 nodes as 0
	while (count0--) {
		temp->data = 0;
		temp = temp->next;
	}

	// Now, update the value of the
	// remaining count1 nodes as 1
	while (count1--) {
		temp->data = 1;
		temp = temp->next;
	}

	// Print the Linked List
	printList(head);
}

// Function to push a node
void push(Node** head_ref, int new_data)
{
	// Allocate node
	Node* new_node = new Node();

	// Put in the data
	new_node->data = new_data;

	// Link the old list of the
	// new node
	new_node->next = (*head_ref);

	// Move the head to point to
	// the new node
	(*head_ref) = new_node;
}

// Driver Code
int main(void)
{
	Node* head = NULL;
	push(&head, 0);
	push(&head, 1);
	push(&head, 0);
	push(&head, 1);
	push(&head, 1);
	push(&head, 1);
	push(&head, 1);
	push(&head, 1);
	push(&head, 0);
	sortList(head);

	return 0;
}
