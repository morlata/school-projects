/*
Taylor Morlan
COMP 53
Project 4 - 27 card trick
*/
#ifndef NODE_H
#define NODE_H

#include "card.h"

class Node//node class for the linked list
{
public:
	Node* next;//pointer to next item in list
	Card data;//data
	Node()//constructor
	{
		next=NULL;
	}
};

#endif