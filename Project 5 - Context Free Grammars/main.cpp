/*
Taylor Morlan
COMP 53
Project 5 - Context - Free Grammars
Bowring
*/
#include <iostream>
#include <string>
#include <sstream>//to manipulate strings
#include <fstream>//to read from file
#include <ctime>//random number generation
#include "hashtable.h"
using namespace std;

void generateSentence(Hashtable& h);//function to randomly generate a sentence

int main()
{
	srand((unsigned)time(0));//see for random number generation
	string fName;//string for user input of file name to open.
	Hashtable h;
	bool running=true;
	while(running)//while the user hasn't chosen to exit the program
	{
		cout << "1.)Enter a file name to load into the hashtable." <<endl<<"2.)Empty the current hashtable."<<endl<<"3.)Print the current hashtable."<<endl<<"4.)Generate a sentence."<<endl<<"5.)Exit"<<endl<<"Select an option: ";
		int input;
		cin >> input;
		switch(input)//switch for user choice
		{
		case 1:
			{
				h.~Hashtable();//calls the destructor, to clear the hashtable if it isn't empty
				system("cls");
				cout << "Enter the file name(example.g): ";
				cin >> fName;
				ifstream f(fName);
				string line;

				while(getline(f,line))//reads in each line of the file
				{
					string key, data;
					stringstream ss;
					ss << line;
					getline(ss,key, ':');//splits up the key and the data
					int length=key.length();
					for (int i=0; i<length; i++)
						if (key[i]==' ')//removes spaces
							key=key.substr(0,i);
					getline(ss,data);
					h.insert(key, data);//inserts the data into the hashtable
				}
				system("cls");
				cout << "Loaded "<<fName<<"..."<<endl;
			}
			break;
		case 2:
			system("cls");
			h.~Hashtable();//runs the destructor to empty the hashtable
			cout << "Hashtable emptied." <<endl;
			system ("pause");
			break;
		case 3:
			h.print();//prints the hashtable
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			generateSentence(h);//generates a random sentence
			system("pause");
			system("cls");
			break;
		case 5:
			running=false;
			break;
		default:
			cout << "Invalid Input."<<endl;
			system("pause");
			system("cls");
		
	}
	}
	system("pause");
}

void generateSentence(Hashtable& h)
{
	//checks to see if the table is empty
	bool empty=true;
	hnode *cur;
	for (int i=0; i<97; i++)
	{
		cur=h.getArr()[i];
		if (cur!=NULL)
		{
			empty=false;
			break;
		}
	}
	if (empty==false)
	{
		stack <string> s;
		stack <string> tempStack;//two stacks to make sure sentences are in order
		stringstream ss;
		s.push("<Start>");
		while (s.empty()==false)
		{
			string temp = s.top();
			s.pop();
			if (temp.length()==0)//continues if there is a trailing space
				continue;
			if (temp[0]!='<')//cout if there is data
				cout << temp << " ";
			else//loads the grammar into a stack
			{
				string replacement=h.search(temp);
				ss << replacement;
				string temper;
				while (getline(ss,temper, ' '))
				{
					tempStack.push(temper);
				}
				while(tempStack.empty()==false)
				{
					s.push(tempStack.top());
					tempStack.pop();
				}
				ss.clear();
			}

		}
	}
	else
		cout << "Hashtable is empty!" <<endl;
}