/*
	Taylor Morlan
	COMP 53
	Project 5 - Context - Free Grammars
	Bowring
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#include "hnode.h"

class Hashtable
{
private:
	static const int SIZE=97;
	hnode *arr[SIZE];
public:
	Hashtable();//constructor
	~Hashtable();//destructor
	hnode** getArr();//returns the array of hnode*'s
	int hash(string key);//hash function
	void insert(string key, string data);//insert function
	void print();//print function
	int size(int location);//function the returns the length of a linked list in the hash table based on the location in the parameter
	string search(string h);//searchs for a key in the hashtable
};

#endif