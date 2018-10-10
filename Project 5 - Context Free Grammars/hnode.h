/*
	Taylor Morlan
	COMP 53
	Project 5 - Context - Free Grammars
	Bowring
*/
#ifndef HNODE_H
#define HNODE_H

#include <string>
using namespace std;

class hnode
{
private:
	string key, data;//strings for the key and data
	hnode *next;//pointer to the next node
public:
	hnode()//unnecessary constructor
	{
	}
	hnode(string ky, string dta, hnode *nxt)//contructor with parameters
	{
		key=ky;
		data=dta;
		next=nxt;
	}
	void setKey(string k)//setkey
	{
		key=k;
	}
	string getKey()//getkey
	{
		return key;
	}
	void setData(string d)//etc
	{
		data=d;
	}
	string getData()//etc
	{
		return data;
	}
	void setNext(hnode *n)//etc
	{
		next=n;
	}
	hnode* getNext()//etc
	{
		return next;
	}
};

#endif