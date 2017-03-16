#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h> 
#include "queue.h"

#ifndef TRUE
#define TRUE !0
#endif

#ifndef FALSE
#define FALSE 0
#endif

/*
        +----+-------+------------------------
        | x  | ITEM1 | ITEM2 | ....
	    +----+-------+-------------------------
Index     0      1       2      index for reading 
STCKCOUTR 0      1       2      points to last Element
*/
// function appends @ the end of fifo 
// ... a new Item with data 'int dat' and empty id.
int FiFo::add(int dat) {
	Item *pNew;
	// leave 1.st element (index=0) free
	StackCounter++;
	pNew = new Item[StackCounter + 1];
	if (pNew == NULL) return FALSE;
	// copy old content to new list
	for (int i = 0; i < StackCounter; i++)
	{
		pNew[i] = pList[i];
	}
	delete pList;
	pList = pNew;
	pList[StackCounter].data = dat; // Copy dat to queue@[stackCounter]
	pList[StackCounter].id = StackCounter; // set id = Stackcounter
	return TRUE;
};

// function appends @ the end of fifo ... 
// ... a complete Item (data + id).
int FiFo::append(Item dat) {
	Item *pNew;
	// leave 1.st element (index=0) free
	StackCounter++;
	// new_array is +1 Element greater than old_array
	pNew = new Item[StackCounter + 1];
	if (pNew == NULL) return FALSE;
	// copy old content to new list
	for (int i = 0; i < StackCounter; i++)
	{
		pNew[i] = pList[i];
	}
	delete pList;
	pList = pNew;
	pList[StackCounter].data = dat.data;
	pList[StackCounter].id = StackCounter;
	return TRUE;
};

int FiFo::print(Item* pItem) {
	if (pItem != NULL) {
		printf("\ndata=%x id=%d", pItem->data, pItem->id);
		return TRUE;
	}
	return FALSE;
}

Item* FiFo::setAtIndex(int position){
if (StackCounter == 0) return NULL;
index = position;
return &pList[index];
};


// function is setting index to first element in Queue index=1 ...
// ... and returns this first Element
Item* FiFo::getFirst(void) {
if (StackCounter == 0) return NULL;
//pItem=&pList[1];
index = 1;
return &pList[1];
};

// This function do not delete any Element of the given Fifo.
// Adressing of current element is done by the variable index, 
// ... which runs thru Fifo boundaries.
// Function increments index every time, it is called 
//  ...  and is returning this Element.
// If fifo is completly read out, 
//  ... index is set outside fifo boundaries.
//  ...  and is returning NULL as Element.
Item* FiFo::getNext(void) {
	if (pList == NULL) return NULL;
	if (StackCounter != 0 && index < StackCounter) {
		index++;
		return &pList[index];
	}
//  index out of fifo-range
return NULL;
};


// function is (re)reading an element @ current index
// ... without deleting this element
Item* FiFo::getAtIndex(void) {
if (pList == NULL) return NULL;
if (StackCounter != 0 && index <= StackCounter) {
	return &pList[index];
	}
return NULL;
};

// read out last element of queue ?
// index == StackCounter  : return TRUE
// index != StackCounter : return FALSE
int FiFo::last(void) {
if (index == StackCounter) {
	return TRUE;
	}
else {
	return FALSE;
	}
}

int FiFo::setItem(Item data)
{
	return TRUE;
}

// Constructor of class
FiFo::FiFo(void) {
	StackCounter = 0;
	// create new List size=1
	pList = new Item[1];
	pList->data = 0xFFFF;  // initialize 1st Element of List
	pList->id = -1;        // 0th Element id=-1
};

// untested function : Delete old Queue und create a new one
int FiFo::reset(void) {
 if (pList != NULL) {
	 delete pList; // delete old Fifo
	 pList = NULL;
	 StackCounter = 0;
	 // create new List size=1
	 pList = new Item[1];
	 pList->data = 0xFFFF;  // initialize 1st Element of List
	 pList->id = -1;
	 return TRUE;
	}
return FALSE;
};

FiFo::~FiFo(void) {
	if (pList!=NULL) delete pList;
};
