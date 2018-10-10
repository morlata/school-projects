/*
Taylor Morlan
COMP 53
Project 5 - Context - Free Grammars
Bowring
*/
#include "hashtable.h"

Hashtable::Hashtable()
{
	for (int i=0;i<SIZE;i++)//makes all the pointers null
		arr[i] = NULL;
}

hnode** Hashtable::getArr()
{
	return arr;
}

int Hashtable::hash(string key)//hashfunction
{
	int sum = 0;
	for (int i=0; i<key.length(); i++)
	{
		sum += (int)key[i];
	}
	int h= sum%SIZE;//modulus method
	return h;
}

void Hashtable::insert(string key, string data)
{
	int index=hash(key);
	int q=0;
	while (arr[index]!=NULL && q!=SIZE)//linear probing
	{
		q++;
		if (index==SIZE)
		{
			index=0;
			q--;
		}
		else 
			index++;
	}

	stringstream ss;
	ss<<data;
	string node;
	while(getline(ss, node, '|'))//adds the data into the hashtable as separate nodes for each piece
	{
		int length=node.length();
		int i,j;
		for (i=0; i<length && node[i] == ' '; i++){}
		for (j=length-1; j>0 && node[j] == ' '; j--){}
		node=node.substr(i, j-i+1);
		arr[index]=new hnode(key, node, arr[index]);
	}
}

void Hashtable::print()
{
	hnode *cur;
	bool empty=true;
		for (int i=0; i<SIZE; i++)//prints the hashtable if it isn't empty
		{
			cur=arr[i];
			while (cur!=NULL)
			{
				empty=false;
				cout << cur->getData() << endl;
				cur=cur->getNext();
			}
		}
		if (empty==true)
			cout << "Hashtable is empty!"<<endl;
}

int Hashtable::size(int location)//returns the length of a linked list
{
	int size=0;
	hnode *cur=arr[location];
	while (cur!=NULL)
	{
		size++;
		cur=cur->getNext();
	}
	return size;
}

string Hashtable::search(string s)//searches for a key with linear probing.
{
	int position=hash(s);
	while(arr[position]->getKey()!=s)
	{
		if (position==SIZE)
			position=0;
		else
			position++;
	}
	int size= this->size(position);
	int random=rand()%size;

	hnode *current;

	current=arr[position];
	for (int i=0; i<random; i++)
	{
		current=current->getNext();
	}
	return current->getData();
}

Hashtable::~Hashtable()//destructor, deallocates all dynamically allocated variables.
{
	hnode *cur;
	for (int i=0; i<SIZE; i++)
	{
		cur=arr[i];
		while (cur!=NULL)
		{
			hnode *temp=cur;
			cur=temp->getNext();
			delete temp;
		}
		arr[i]=NULL;
	}
}

