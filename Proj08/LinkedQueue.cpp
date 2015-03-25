/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Hezkiel A. Nanda
 * Date: 11/12/13
 */

#include "LinkedQueue.h"


LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirst = myLast = NULL;
	} else {
		myFirst = new Node(original.getFirst(), NULL);
		Node * temp0 = original.myFirst->myNext;
		Node * temp1 = myFirst;
		while (temp0 != NULL) {
			temp1->myNext = new Node(temp0->myItem, NULL);
			temp1 = temp1->myNext;
			temp0 = temp0->myNext;
		}
		myLast = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirst;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}

LinkedQueue::LinkedQueue(){
	mySize = 0;
	myFirst = myLast = NULL;
}

Item LinkedQueue::getFirst() const{
	if(isEmpty()){
		throw EmptyQueueException("getFirst()");
	}
	return myFirst->myItem;
}

Item LinkedQueue::getLast() const{
	if(isEmpty()){
		throw EmptyQueueException("getLast()");
	}
	return myLast->myItem;
}

void LinkedQueue::append (const Item& it){
	Node * temp = new Node(it,NULL);
	if (isEmpty()){
		myFirst = temp;
	} else {
		myLast->myNext = temp;
	}
	myLast = temp;
	mySize ++;
}

Item LinkedQueue::remove(){
	if(isEmpty()){
		throw EmptyQueueException("remove()");
	} else{
		mySize --;
		Item result = myFirst->myItem;
		Node * nPtr = myFirst;
		myFirst = myFirst->myNext;
		nPtr->myNext = NULL;
		delete nPtr;
		if (mySize == 0){
			myLast = NULL;
		}
		return result;
	}
}
