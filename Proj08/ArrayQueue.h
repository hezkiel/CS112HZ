/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name: Hezkiel A. Nanda
 * Date:11/12/13
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast-1] == getLast().
 * 
 *  (When I am not empty:
 *     myFirst is the index of my oldest value;
 *     myLast is the index of the spot where the next
 *       item to be appended will be placed.)      
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>
using namespace std;

template <class Item>
class ArrayQueue {
public:

	ArrayQueue(const ArrayQueue<Item>& original);
	virtual ~ArrayQueue();
	ArrayQueue<Item>& operator=(const ArrayQueue<Item>& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	void setCapacity(unsigned newCapacity);
	bool isEmpty() const;
	bool isFull() const;
	ArrayQueue (const int capacitySize);
	void append(const Item& it);
	Item getFirst() const;
	Item remove();
	Item getLast() const;

protected:
	virtual void makeCopyOf(const ArrayQueue<Item>& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirst;      // index of oldest item (if any)
	unsigned myLast;       // index of next available spot for append (if any)
	Item*    myArray;      // dynamic array of items

	friend class ArrayQueueTester;
};
template <class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}

template <class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirst = original.myFirst;
	myLast = original.myLast;
	myArray = new Item[myCapacity];
	memcpy(myArray, original.myArray, myCapacity * sizeof(Item));
}

template <class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete[] myArray;
	myArray = NULL;
	mySize = myFirst = myLast = 0;
}

template <class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete[] myArray;
		makeCopyOf(aQueue);
	}
	return *this;
}

template <class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

template <class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

template <class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

template <class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

template <class Item>
ArrayQueue<Item>::ArrayQueue(const int capacitySize) {
	if (capacitySize > 0) {
		myCapacity = capacitySize;
		mySize = 0;
		myFirst = myLast = 0;
		myArray = new Item[myCapacity];
	} else {
		throw QueueException("ArrayQueue(int)",
				"the capacity size must be bigger than zero!");
	}
}

template <class Item>
void ArrayQueue<Item>::append(const Item& it) {
	if (isFull()) {
		throw FullQueueException("append()");
	} else {
		myArray[myLast] = it;
		myLast = (myLast + 1) % myCapacity;
		mySize++;
	}
}

template <class Item>
Item ArrayQueue<Item>::getFirst() const{
	if (isEmpty()) {
		throw EmptyQueueException("getFirst()");
	} else {
		return myArray[myFirst];
	}
}

template <class Item>
Item ArrayQueue<Item>::getLast() const {
	if (isEmpty()) {
		throw EmptyQueueException("getLast()");
	} else {
		return myArray[(myLast - 1 + myCapacity) % myCapacity];
	}
}

template <class Item>
Item ArrayQueue<Item>::remove() {
	if(isEmpty()){
		throw EmptyQueueException("remove()");
	} else {
		Item result = myArray[myFirst];
		myFirst = (myFirst+1)%myCapacity;
		mySize --;
		return result;
	}
}

template <class Item>
void ArrayQueue<Item>::setCapacity(unsigned newCapacity){
	if(newCapacity == 0){
		throw QueueException ("setCapacity()","new capacity size must be positive!");
	} if(newCapacity < getSize()){
		throw QueueException ("setCapacity()", "new capacity must be bigger than the size!");
	} else{
		Item * newMyArray;
		newMyArray = new Item[newCapacity];
		for (unsigned i = myFirst; i < myLast; i++){
			newMyArray[i] = myArray[i];
		}
		delete [] myArray;
		this->myCapacity = newCapacity;
		this->myArray = newMyArray;
	}
}


#endif /*ARRAY_QUEUE_H_*/
