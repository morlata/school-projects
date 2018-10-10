/*
Taylor Morlan
COMP 53
*/
#include<iostream>
#include<string>
#include<ctime>
#include<Windows.h>
using namespace std;

class Cell
{
private:
	bool isMine, covered, flagged;//boolean for if the cell is a mine, covered, and flagged.
	int mines;//number of mines adjacent to the cell.
public:
	//accessors/mutators
	bool getFlagged ()
	{
		return flagged;
	}
	void setFlagged (bool flag)
	{
		flagged=flag;
	}
	int getMines()
	{
		return mines;
	}
	void setMines(int m)
	{
		mines=m;
	}
	bool getIsMine()
	{
		return isMine;
	}
	bool getCovered()
	{
		return covered;
	}
	void setCovered(bool cover)
	{
		covered=cover;
	}
	//constructor
	Cell()
	{
		int random=rand()%9+1;//10% chance to be a mine
		if (random==2)
			isMine=true;
		else
			isMine=false;
		mines=0;
		covered=true;//cells start covered, and unflagged
		flagged=false;
	}
};

class Grid
{
private:
	Cell arr[10][10];
public:
	//accessors and mutators that link to Cell class accessors and mutators
	bool getArrFlagged(int row, int col)
	{
		return arr[row][col].getFlagged();
	}
	void setArrFlagged (bool flag, int row, int col)
	{
		arr[row][col].setFlagged(flag);
	}
	void setArrCovered (bool cover, int row, int col)
	{
		arr[row][col].setCovered(cover);
	}
	bool getArrCovered (int row, int col)
	{
		return arr[row][col].getCovered();
	}
	bool getArrIsMine(int row, int col)
	{
		return arr[row][col].getIsMine();
	}
	int getArrMines (int row, int col)
	{
		return arr[row][col].getMines();
	}
	//Function to display the grid to the user, takes into account which cells are covered, flagged, etc..
	void displayGrid()
	{
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "  0 1 2 3 4 5 6 7 8 9"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int i=0; i<10; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << i;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout <<'|';
			for (int j=0; j<10; j++)
			{
				if (arr[i][j].getCovered()==true && arr[i][j].getFlagged()==false)
					cout << ' ' <<"|";
				if (arr[i][j].getCovered()==true && arr[i][j].getFlagged()==true)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << '>';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << '|';
				}
				if (arr[i][j].getCovered()==false)
				{
					if (arr[i][j].getIsMine()==false)
						cout << arr[i][j].getMines() << "|";
					if (arr[i][j].getIsMine()==true)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						cout << '*';
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cout << '|';
					}
				}
			}
			cout << endl;
		}
	}
	//consructor
	Grid()
	{//Checking mines for inner 9x9 grid.
		for (int i=1; i<9;i++)
		{
			for (int j=1; j<9; j++)
			{
				if (arr[i-1][j-1].getIsMine()==true)
						arr[i][j].setMines(arr[i][j].getMines()+1);
				if (arr[i-1][j].getIsMine()==true)
						arr[i][j].setMines(arr[i][j].getMines()+1);
				if (arr[i-1][j+1].getIsMine()==true)
						arr[i][j].setMines(arr[i][j].getMines()+1);
				if (arr[i][j-1].getIsMine()==true)
						arr[i][j].setMines(arr[i][j].getMines()+1);
				if (arr[i][j+1].getIsMine()==true)					
						arr[i][j].setMines(arr[i][j].getMines()+1);
				if (arr[i+1][j-1].getIsMine()==true)
						arr[i][j].setMines(arr[i][j].getMines()+1);
				if (arr[i+1][j].getIsMine()==true)
						arr[i][j].setMines(arr[i][j].getMines()+1);
				if (arr[i+1][j+1].getIsMine()==true)
						arr[i][j].setMines(arr[i][j].getMines()+1);		
			}
		}
		//Checking for mines for left-most column excluding end points.
		for(int i=1; i<9; i++)
		{
				if (arr[i-1][0].getIsMine()==true)
					arr[i][0].setMines(arr[i][0].getMines()+1);
				if (arr[i-1][1].getIsMine()==true)
					arr[i][0].setMines(arr[i][0].getMines()+1);
				if (arr[i][1].getIsMine()==true)
					arr[i][0].setMines(arr[i][0].getMines()+1);
				if (arr[i+1][0].getIsMine()==true)
					arr[i][0].setMines(arr[i][0].getMines()+1);
				if (arr[i+1][1].getIsMine()==true)
					arr[i][0].setMines(arr[i][0].getMines()+1);
			
		}
		//same as above but for the furthest right column.
		for (int i=1; i<9; i++)
		{
				if (arr[i-1][9].getIsMine()==true)
					arr[i][9].setMines(arr[i][9].getMines()+1);
				if (arr[i-1][8].getIsMine()==true)
					arr[i][9].setMines(arr[i][9].getMines()+1);
				if (arr[i][8].getIsMine()==true)
					arr[i][9].setMines(arr[i][9].getMines()+1);
				if (arr[i+1][9].getIsMine()==true)
					arr[i][9].setMines(arr[i][9].getMines()+1);
				if (arr[i+1][8].getIsMine()==true)
					arr[i][9].setMines(arr[i][9].getMines()+1);
			
		}
		//same but for first row
		for (int i=1; i<9; i++)
		{
				if (arr[0][i-1].getIsMine()==true)
					arr[0][i].setMines(arr[0][i].getMines()+1);
				if (arr[0][i+1].getIsMine()==true)
					arr[0][i].setMines(arr[0][i].getMines()+1);
				if (arr[1][i-1].getIsMine()==true)
					arr[0][i].setMines(arr[0][i].getMines()+1);
				if (arr[1][i].getIsMine()==true)
					arr[0][i].setMines(arr[0][i].getMines()+1);
				if (arr[1][i+1].getIsMine()==true)
					arr[0][i].setMines(arr[0][i].getMines()+1);
			
		}
		//last row
		for (int i=1; i<9; i++)
		{
				if (arr[9][i-1].getIsMine()==true)
					arr[9][i].setMines(arr[9][i].getMines()+1);
				if (arr[9][i+1].getIsMine()==true)
					arr[9][i].setMines(arr[9][i].getMines()+1);
				if (arr[8][i].getIsMine()==true)
					arr[9][i].setMines(arr[9][i].getMines()+1);
				if (arr[8][i-1].getIsMine()==true)
					arr[9][i].setMines(arr[9][i].getMines()+1);
				if (arr[8][i+1].getIsMine()==true)
					arr[9][i].setMines(arr[9][i].getMines()+1);
			
		}
		//Upper left corner
		
			if (arr[0][1].getIsMine()==true)
				arr[0][0].setMines(arr[0][0].getMines()+1);
			if (arr[1][1].getIsMine()==true)
				arr[0][0].setMines(arr[0][0].getMines()+1);
			if (arr[1][0].getIsMine()==true)
				arr[0][0].setMines(arr[0][0].getMines()+1);	
		
		//Lower left corner	
		
			if (arr[9][1].getIsMine()==true)
				arr[9][0].setMines(arr[9][0].getMines()+1);
			if (arr[8][1].getIsMine()==true)
				arr[9][0].setMines(arr[9][0].getMines()+1);
			if (arr[8][0].getIsMine()==true)
				arr[9][0].setMines(arr[9][0].getMines()+1);
		
		//upper right corner
		
			if (arr[0][8].getIsMine()==true)
				arr[0][9].setMines(arr[0][9].getMines()+1);
			if (arr[1][8].getIsMine()==true)
				arr[0][9].setMines(arr[0][9].getMines()+1);
			if (arr[1][9].getIsMine()==true)
				arr[0][9].setMines(arr[0][9].getMines()+1);
		
		//lower right corner
		
			if (arr[8][9].getIsMine()==true)
				arr[9][9].setMines(arr[9][9].getMines()+1);
			if (arr[8][8].getIsMine()==true)
				arr[9][9].setMines(arr[9][9].getMines()+1);
			if (arr[9][8].getIsMine()==true)
				arr[9][9].setMines(arr[9][9].getMines()+1);
		
	}
};
//recursive function to reveal cells around cells that have no adjacent mines
void recurseCheck (int row, int col, Grid &theGrid)
{
	//somewhat redundant failsafe so no cells that are outside the grid, are uncovered, are mines, or are flagged are able to run in the function
if (row>9 || row<0 || col>9 || col<0 || theGrid.getArrIsMine(row,col)==true || theGrid.getArrCovered(row,col)==false || theGrid.getArrFlagged(row,col)==true)
	return;
theGrid.setArrCovered(false,row,col);//uncovers cell
if (theGrid.getArrMines(row, col)==0)
{//Each if statement also checks the same stuff as above
	if (theGrid.getArrIsMine(row-1,col-1)==false && theGrid.getArrFlagged(row-1,col-1)==false && theGrid.getArrCovered(row-1,col-1)==true && col>0 && row>0)
		recurseCheck(row-1,col-1,theGrid);
	if (theGrid.getArrIsMine(row-1,col)==false && theGrid.getArrFlagged(row-1,col)==false && theGrid.getArrCovered(row-1,col)==true && row>0)
		recurseCheck(row-1,col,theGrid);
	if (theGrid.getArrIsMine(row-1,col+1)==false && theGrid.getArrFlagged(row-1,col+1)==false && theGrid.getArrCovered(row-1,col+1)==true && row>0 && col<9)
		recurseCheck(row-1,col+1,theGrid);
	if (theGrid.getArrIsMine(row,col-1)==false && theGrid.getArrFlagged(row,col-1)==false && theGrid.getArrCovered(row,col-1)==true && col>0)
		recurseCheck(row,col-1,theGrid);
	if (theGrid.getArrIsMine(row,col+1)==false && theGrid.getArrFlagged(row,col+1)==false && theGrid.getArrCovered(row,col+1)==true && col<9)
		recurseCheck(row,col+1,theGrid);
	if (theGrid.getArrIsMine(row+1,col-1)==false && theGrid.getArrFlagged(row+1,col-1)==false && theGrid.getArrCovered(row+1,col-1)==true && row<9 && col>0)
		recurseCheck(row+1,col-1,theGrid);
	if (theGrid.getArrIsMine(row+1,col)==false && theGrid.getArrFlagged(row+1,col)==false && theGrid.getArrCovered(row+1,col)==true && row<9)
		recurseCheck(row+1,col,theGrid);
	if (theGrid.getArrIsMine(row+1,col+1)==false && theGrid.getArrFlagged(row+1,col+1)==false && theGrid.getArrCovered(row+1,col+1)==true && row<9 && col<9)
		recurseCheck(row+1,col+1,theGrid);	
}
}

//function to check if the user has won
bool winCheck (Grid theGrid)
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			if (theGrid.getArrIsMine(i,j)==false && theGrid.getArrCovered(i,j)==true)
				return false;
		}
	}
	return true;
}
//function to facilitate the user choice of uncovering a cell.
bool makeMove (int row, int col, Grid &theGrid)
{//if the user uncovers a mine, they lose
	if (theGrid.getArrIsMine(row, col)==true)
	{
		theGrid.setArrCovered(false,row, col);
		theGrid.displayGrid();
		cout << "You lose!"<<endl;
		return false;
	}
	//if it gets this far, the recursive checking function is called.
	recurseCheck(row,col,theGrid);
	//checking for the win after the move is made.
	theGrid.displayGrid();
	if (winCheck(theGrid)==true)
	{
		cout << "You win!"<<endl;
		return false;
	}
	return true;
}

//function to manage the game
void gameManage (Grid &theGrid)
{
	bool playingGame=true;
	int row, col;
	do{
		cout << "Would like to 1.)Uncover or 2.)Flag ?"<<endl;
		int userChoice;
		cin >> userChoice;
		switch(userChoice)
		{
		case 1://uncovering
			cout << "Enter row: ";
			cin >> row;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Error! Invalid Input!"<<endl;
					break;
			}
			cout << endl << "Enter column: ";
			cin >> col;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Error! Invalid Input!"<<endl;
					break;
			}
			if (theGrid.getArrFlagged(row, col)==true)//reprompts the user if the cell is flagged
			{
				cout << "You can't uncover a flagged cell!"<<endl;
				break;
			}
			if (theGrid.getArrCovered(row,col)==false)//reprompts if the cell is uncovered
			{
				cout << "That cell is already uncovered!"<<endl;
				break;
			}
			playingGame=makeMove(row, col, theGrid);
			break;
		case 2://flagging
			cout << "Enter row: ";
			cin >> row;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Error! Invalid Input!"<<endl;
					break;
			}
			cout << endl << "Enter column: ";
			cin >> col;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Error! Invalid Input!"<<endl;
					break;
			}
			if (theGrid.getArrFlagged(row, col)==true)//de-flags if the cell is flagged
			{
				theGrid.setArrFlagged(false, row, col);
				system("cls");
				theGrid.displayGrid();
				break;
			}
			if (theGrid.getArrCovered(row, col)==true)//flags if it isn't flagged
			{
				theGrid.setArrFlagged(true, row, col);
				system("cls");
				theGrid.displayGrid();
				break;
			}
			if (theGrid.getArrCovered(row,col)==false)//reprompts if the cell is uncovered
				cout << "You can't flag an uncovered space!"<<endl;
		default:
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Error! Invalid Input!"<<endl;
					break;
			}
		}
	}while(playingGame);
}

int main()
{
	srand((unsigned)time(0));
	Grid theGrid;
	theGrid.displayGrid();
	cout << "Welcome to Minesweeper!"<<endl;
	gameManage(theGrid);
	system("pause");
}