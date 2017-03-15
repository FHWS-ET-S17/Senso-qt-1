#pragma once


typedef	struct {
	int data;
	char id;
}Item;


class FiFo {
public:
	FiFo();
	~FiFo();
	int reset();
	int append(Item);
	int add(int);
	Item* setAtIndex(int);
	Item* getFirst(void);
	Item* getAtIndex(void);
	Item* getNext(void);
	int setItem(Item);
	int print(Item*);
	int last(void);

private:

	Item *pList;		// Zeiger auf Liste der Elemente aus Items
						//Item *pItem;		// Zeiger auf aktuell betrachtetes Element
	int	index;			// Index des momentan betrachteten Items
						//int sizeMax;		//  Größe des Stacks
	int StackCounter;	// StackCounter, zeigt auf das letzte eingehängte Element
						//Item Element;		// Puffer für den Inhalt des aktuell betrachteten  Elementes
};