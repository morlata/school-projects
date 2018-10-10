/*
Taylor Morlan
Project 4 - Hangman Game
Comp 51
*/

#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;
void gameDisplay(int userMistake, char gallows[][9]);
string pickCity();
void charArrayBlank(char capitalArray[40], char capitalArray2[40], char capitalArray3[40], int stringSize);
int playGame(char capitalArray[40], char capitalArray2[40], char capitalArray3[40], int userMistake, int stringSize, string& guessed);
void test_playGame();
void test_gameDisplay(char gallows[][9]);

int main()//Main function, calls to other function to run the program.
{	
	string capital;
	char gallows[7][9];
	char capitalArray[40], capitalArray2[40], capitalArray3[40];
	int userMistake=0;
	char userChoice, userChoice2;
	bool playingGame=true, playingGame2=false, sameArray=false, inputFail=false;
	int stringSize;



	cout << "Welcome to Hangman, the country capitals edition!"<<endl;
	do{
		sameArray=false;
		userMistake=0;
		string guessed="";
		capital=pickCity();
		strcpy(capitalArray,capital.c_str());
		strcpy(capitalArray2,capital.c_str());
		strcpy(capitalArray3,capital.c_str());
		stringSize=capital.size();
		charArrayBlank(capitalArray, capitalArray2, capitalArray3, stringSize);
		for (int i=0;i<7;i++)
		{
			for (int j=0;j<9;j++)
			{
				gallows[i][j]='\0';
			}
		}
		cout << "1.) Play game" <<endl<< "2.) Test Functions" <<endl<< "3.) Quit"<<endl;
		cout << "Please select an option from the list: ";
		cin >> userChoice;
		system("cls");
		switch (userChoice)
		{
		case '1'://Starts the game.
			do{
				gameDisplay(userMistake, gallows);
				userMistake=playGame(capitalArray, capitalArray2, capitalArray3, userMistake, stringSize, guessed);
				system("cls");
				sameArray=true;
				for (int i=0; i<stringSize; i++)
				{
					if (capitalArray[i]!=capitalArray2[i])
						sameArray=false;
				}
				if (sameArray==true)
					break;
			}while(userMistake<6);
			playingGame=false;
			break;
		case '2'://Test function.
			cout << "1.) Test gameDisplay Function"<<endl<< "2.)Quit"<<endl;
			do{
			cout << "Please select an option from the list: ";
			cin >> userChoice2;
			switch (userChoice2)
			{
			case '1':
				test_gameDisplay(gallows);
				break;
			case '2':
				system("cls");
				break;
			default:
				cout << "You didn't enter one of the options."<<endl;
				inputFail=true;
			break;
			}
			}while (inputFail==true);
				break;
		case '3'://Quit.
			userMistake=0;
			playingGame=false;
			break;
		default://User input error.
			sameArray=false;
			cout << "That is not an option, please try again..."<<endl;
		}
		if (sameArray)
		{
			cout << "You correctly guessed the capital "<<capital<<"."<<endl;
			cout << "You Win!!!"<<endl;
			playingGame=true;
			system("pause");
			system("cls");
		}

		if(userMistake==6)
		{
			playingGame=true;
			gameDisplay(userMistake, gallows);
			cout << "You have been hanged!"<<endl;
			cout << "The capital you were trying to guess was " <<capital<<"."<<endl;
			system("pause");
			system("cls");
			userMistake=0;
		}

	}while(playingGame);
	cout << "Goodbye."<<endl;

	system("pause");

}

void gameDisplay(int userMistake, char gallows[][9])//Sets up the display for the game. Calls # of user mistakes and previous array values.----------------------------------------------------------------------------------------------------------------
{
	if (userMistake==0)
	{
		for (int i=0; i<9; i++)
		{
			gallows[6][i]='_';
		}
		for (int i=1; i<7; i++)
		{
			gallows[i][4]='|';
		}
		gallows[0][3]='_';
		gallows[1][2]='|';
	}
	if (userMistake==1)
		gallows[2][2]='*';
	if (userMistake==2)
		gallows[3][2]='|';
	if (userMistake==3)
		gallows[3][1]='-';
	if (userMistake==4)
		gallows[3][3]='-';
	if (userMistake==5)
		gallows[4][1]='/';
	if (userMistake==6)
		gallows[4][3]='\\';

	for (int i=0;i<7;i++)
	{
		cout << endl;
		for (int j=0;j<9;j++)
		{
			cout << gallows[i][j];
		}
	}
	cout << endl;
}

string pickCity()//Pulls all the data from the text file, and puts it into an array. Then randomly selects a capital from the array. No user input, but there is input from the file.------------------
{
	srand ((unsigned)time(0));
	int totalLines=0;
	string capital;
	string line;
	string locations[180];
	ifstream inStream;
	inStream.open("capitals.txt");
	if (inStream.fail())
	{
		cout << "The file capitals.txt does not exist!"<<endl;
		return(0);
	}
	while (getline(inStream, line))
	{
		locations[totalLines]=line;
		totalLines++;
	}

	int randomLine=rand()%totalLines+1;
	capital = locations[randomLine];
	inStream.close();
	return(capital);
}

void charArrayBlank(char capitalArray[40], char capitalArray2[40], char capitalArray3[40], int stringSize)//Sets up the display for what part of the capital the user has guessed/still needs to guess. The other array is for checking values. No user input. Calls 3 arrays and the lenth of a string.
{	
	for (int i=0; i<stringSize; i++)
	{
		if (capitalArray2[i]!=',' && capitalArray2[i]!=' ')
			capitalArray2[i]='_';
		if (capitalArray3[i]!=',' && capitalArray3[i]!=' ')
			capitalArray3[i]='_';
	}	
}

int playGame(char capitalArray[40], char capitalArray2[40], char capitalArray3[40], int userMistake, int stringSize, string& guessed)//Main function of the program. Lets you play the game. User is only asked to input characters to guess what the capital is. Calls 3 arrays, # of mistakes, length of string, and string containing characters already guessed by user.
{
	
	cout << capitalArray2 << endl;
	int stringSize2=guessed.length();
	char userInput;
	bool previousEntry;
	do{
		previousEntry=false;
		cout << "Please make a guess: ";
		cin >> userInput;
		for (int i=0; i<stringSize2; i++)
		{
			if (userInput==guessed[i])
			{
				previousEntry=true;
				cout << "You already guessed that letter!"<<endl;
				break;
			}
		}
	}while (previousEntry==true);
	guessed+=userInput;
	bool sameArray=true;
	for (int i=0; i<stringSize; i++)
	{
		if (userInput==capitalArray[i] || tolower(userInput)==capitalArray[i] || toupper(userInput)==capitalArray[i])
			capitalArray2[i]=capitalArray[i];
	}
	for (int i=0; i<stringSize; i++)
	{
		if (capitalArray2[i]!=capitalArray3[i])
			sameArray=false;
	}
	if (sameArray==true)
	{
		userMistake++;
	}
	else
	{
		for (int i=0; i<stringSize; i++)
		{
			capitalArray3[i]=capitalArray2[i];
		}
	}
	return(userMistake);
}



//Test Function------------------------------------------------------------------------------------------Test Function--------------------------------------------------------------------


void test_gameDisplay(char gallows[][9])//This is the only function that I could write a testcase function for. Calls array for display.
{
	for (int i=0;i<7;i++)
		{
			for (int j=0;j<9;j++)
			{
				gallows[i][j]='\0';
			}
		}
	cout << "Testing gameDisplay."<<endl;
	cout << "Common Case: userMistake=4"<<endl;
	gameDisplay(4, gallows);
	system("pause");
	for (int i=0;i<7;i++)
		{
			for (int j=0;j<9;j++)
			{
				gallows[i][j]='\0';
			}
		}
	cout << "Common Case: userMistake=5"<<endl;
	gameDisplay(5, gallows);
	system("pause");
	for (int i=0;i<7;i++)
		{
			for (int j=0;j<9;j++)
			{
				gallows[i][j]='\0';
			}
		}
	cout << "Boundary Case: userMistake=0"<<endl;
	gameDisplay(0, gallows);
	system("pause");
	for (int i=0;i<7;i++)
		{
			for (int j=0;j<9;j++)
			{
				gallows[i][j]='\0';
			}
		}
	cout << "Boundary Case: userMistake=6"<<endl;
	gameDisplay(6, gallows);
	system("pause");
	for (int i=0;i<7;i++)
		{
			for (int j=0;j<9;j++)
			{
				gallows[i][j]='\0';
			}
		}
	cout << "Error Case: userMistake=-3"<<endl;
	gameDisplay(-3, gallows);
	system("pause");
	for (int i=0;i<7;i++)
		{
			for (int j=0;j<9;j++)
			{
				gallows[i][j]='\0';
			}
		}
	cout << "Error Case: userMistake=8"<<endl;
	gameDisplay(8, gallows);
	system("pause");
	system("cls");


}



