#include "game.h"

//comments on the game class are in the header

bool Game::playGame(Player& p)
{
	bool playing=true;
	playing=arr[p.getRow()][p.getCol()]->runEvent(p);
	return playing;
}

Game::Game()
{
	rows=0;
	cols=0;
	arr=NULL;
	c=NULL;
}

void Game::getGrid()
{
	ifstream inStream;
	inStream.open("game.txt");
	if (!inStream)
		cout << "File couldn't be opened!"<<endl;
	inStream >> rows >> cols;
	arr = new Location **[rows];

	for (int i=0; i<rows; i++)
	{
		arr[i]=new Location *[cols];
		for (int j=0; j<cols; j++)
		{
			char temp;
			inStream >> temp;
			if (temp=='L')
				arr[i][j] = new Location;
			if (temp=='R')
				arr[i][j] = new Riddles;
			if (temp=='B')
				arr[i][j] = new Boss;
			if (temp=='E')
				arr[i][j] = new Enemy;
		}
	}
}

void Game::displayGrid(Player p)
{
	system("cls");
	p.display();
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			if (p.getRow()==i && p.getCol()==j)
				cout << "*";
			else
				arr[i][j]->printCell();
			cout << " ";
		}
		cout << endl;
	}

}

void Game::makeMove(Player &p)
{
	bool madeMove=false;
	do{
		cout << "Will you venture (N)orth, (S)outh, (E)ast, or (W)est?";
		char input;
		cin >> input;
		switch (input)
		{
		case 'n':
		case 'N':
			if (p.getRow()==0)
			{
				cout << "You can't travel North!"<<endl;
				system("pause");
				break;
			}
			p.setRow(p.getRow()-1);
			madeMove=true;
			break;
		case 's':
		case 'S':
			if (p.getRow()==rows-1)
			{
				cout << "You can't travel South!"<<endl;
				system("pause");
				break;
			}
			p.setRow(p.getRow()+1);
			madeMove=true;
			break;
		case 'e':
		case 'E':
			if (p.getCol()==cols-1)
			{
				cout << "You can't travel East!"<<endl;
				system("pause");
				break;
			}
			p.setCol(p.getCol()+1);
			madeMove=true;
			break;
		case 'W':
		case 'w':
			if (p.getCol()==0)
			{
				cout << "You can't travel West!"<<endl;
				system("pause");
				break;
			}
			p.setCol(p.getCol()-1);
			madeMove=true;
			break;
		default:
			cout << "Input error!";
			system("pause");
		}
	}while(madeMove=false);
}