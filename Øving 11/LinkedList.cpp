#include <string>
#include <ostream>

#include "LinkedList.h"

using namespace std;

/**	Part 7 **/

/**	Constructor for the list node
	Sets the next pointer to NULL
	and value to the given argument **/
ListNode::ListNode(const string &value){
	next = NULL;
	this->value = value;
}

string ListNode::getValue() const{
	return value;
}

ListNode *ListNode::getNext() const{
	return next;
}

/**	Constructor for the Linked List
	sets the head and last pointers to NULL **/
LinkedList::LinkedList(){
	head = NULL;
	last = NULL;
}

/**	The destructor
	simply calls removeFromFront() as long as the list is not empty**/
LinkedList::~LinkedList(){
	string dummy;		//String used as argument for removeFromFront()
	while(!isEmpty()) {
		removeFromFront(dummy);
	}
}

/**	If the list is empty, head will be NULL**/
bool LinkedList::isEmpty() const{
	return head == NULL;
}

/**	Insert at front **/
void LinkedList::insertAtFront(const string &value){
	ListNode *node = new ListNode(value);	//Create a new list node with the given value
	if(isEmpty()) {				//If the list is empty,
		last = node;			//the last pointer is set to point to the new node
	}
	node->next = head;			//The next pointer of the new node is set to point to the first node of the list (or NULL if the list is empty)
	head = node;				//and then head is set to point to the new node, making it the first node in the list
}

/**	Insert at back **/
void LinkedList::insertAtBack(const string &value){
	ListNode *node = new ListNode(value);	//Create a new list node with the given value
	if(isEmpty()) {				//If the list is empty,
		head = node;			//the head pointer is set to point to the new node
	} else {					//if not
		last->next = node;		//the last node is set to point to the new node
	}
	last = node;				//The last pointer is set to point to the new node, making it the last node in the list
}

/**	Remove from front **/
bool LinkedList::removeFromFront(string &value){
	if(!isEmpty()){				//If the list is not empty, we remove a node, if not we simply return false
		ListNode *node = head;		//We make a new pointer to the first node in the list
		head = head->next;		//and make head point to the second node in the list
		value = node->getValue();	//we get the value of the first node and store it in the string reference given as argument
		delete node;			//and delete the node
		if(head == NULL){		//If head is NULL, the list is now empty,
			last = NULL;		//last is set to NULL as well
		}
		return true;			//Finally return true, indication a successfull remove
	}
	return false;
}

/**	Remove from front 
	Removing from back is a bit more complicated
	we here need to find the second last node, which means iterating through the list**/
bool LinkedList::removeFromBack(string &value){
	ListNode *current = head;		//Make two new pointers, one pointing to the first node
	ListNode *prev = NULL;			//and the other just pointing to NULL
	while(current != last){			//While the current pointer is not pointing to the last node
		prev = current;			//the prev pointer is set equal to the current pointer
		current = current->next;	//and the current pointer is set to point to the next node in the list
	}
	
	//After the loop is done, current points to the last node and prev points to the second last
	//If the list is empty, both points to NULL
	//If the list holds only one node, current points to this node and prev points to NULL
	
	if(current == NULL)		//The list is empty, false is returned
		return false;
		
	last = prev;			//The last pointer is set to point to the second last node (or NULL if the list holds only one node)
	value = current->getValue();	//the value of the node we wish to delete is stored in the argument
	delete current;			//and the node is deleted
	
	if(last == NULL){		//If the list now is empty (last/prev is NULL)
		head = NULL;		//head is set to NULL as well
	} else {				//if there is still nodes in the list
		last->next = NULL;	//the next pointer of the last node is set to NULL
	}
	return true;			//Finally return true, indication a successfull remove 
}

/**	Overload the << operator
	Iterates through all the nodes in the list, extracting the values**/
ostream &operator <<(ostream &str, const LinkedList &l){
	ListNode *current = l.head;
	str << "The list contains:";
	while(current != NULL){
		str << " " << current->getValue();
		current = current->getNext();
	}
	return str;
}

/**	Part 8
	Search the list **/
ListNode *LinkedList::search(const string &value){
	ListNode *node = head;			//Creates a pointer to the first node
	while(node != NULL){			//loops as long as this pointer is not NULL (as long as we have not reached the end of the list
		if(node->getValue() == value) {	//If the node the pointer points to holds the value we search for
			return node;		//the pointer is returned
		} else {				//if not
			node = node->next;	//the pointer is set to point to the next node in the list
		}
	}
	return node;				//If the loops finish, node is NULL and this is returned to indicate there was no match in the list
}


/**	Part 9
	Removing nodes from within the list
	This can be solved by several methods **/
void LinkedList::remove(const string &value){
	string dummy;				//string for use with the removeFromBack() and removeFromFront()
	while(head != NULL && head->getValue() == value) {	//as long as the first node match the given string
		removeFromFront(dummy);				//we remove it with removeFromFront
	}
	while(last != NULL && last->getValue() == value) {	//and as lint as the last node match the given string
		removeFromBack(dummy);				//we remove it with removeFromBack
	}	
	//The list now only contains the nodes we want to remove within it (not as the first or last node)
	
	ListNode *current = head;		//Creates pointers to the first node and to NULL
	ListNode *prev = NULL;
	while(current != NULL){				//While the current pointer is not NULL...
		if(current->getValue() == value){	//If the node pointed to by current match the given value
			prev->next = current->next;	//The next pointer of the node before the node to be removed is set to point to the node after
			delete current;			//The node is deleted
			current = prev->next;		//The current pointer is set to point to the node after the one removed
		} else{					//If the node do not match, the current and prev pointers are set to point to the next node
			prev = current;
			current = current->next;
		}
	}
}