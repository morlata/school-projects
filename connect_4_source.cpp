/*****************************************************************************
*  Filename: Project5.cpp
*  Author: Taylor Morlan
*  Description: This program allows two computer players to play Connect 4
*               against each other.  There are two class: Board and Player
****************************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

/*****************************************************************************
*  Board Class Declaration
****************************************************************************/
class Board
{
private:
	char board [6][7];
public:
	Board();
	void getArray(char theArray[][7]);
	void printBoard();
	bool checkMove(int col);
	void makeMove(char player, int col);
	void undoMove(int col);
	bool isFull();
	void reset();
	bool hasWon(char player);             
	void hostTournament();
};

/*****************************************************************************
*  Player Class Declaration and Definitions
****************************************************************************/

// PLEASE PUT YOUR PLAYER CLASS CODE HERE.
// (This code should implement a COMPUTER player for connect-4)

class Player
{
public://functions are explained at their actual locations.
	Player();
	Player(char letter);
	int bestMove(int scores[]);
	int evalMove(int col, Board B, int s[][7]);
	int evalAllMoves(Board B);
	void winLoseCheck(int scores[], Board B);
	void hrz2Check(int scores[], Board B);
private:
	char team,oppTeam;//team is the char for the team of the class instance, oppTeam is the opposing team.
};

Player::Player()//default constructor assigns the team to be O and the opposing team is X.
{
	team='O';
	oppTeam='X';
}

Player::Player(char letter)//contructor with char input. Assigns the input character as team, and the makes oppTeam the other possible char.
{
	team=letter;
	if (team=='X')
		oppTeam='O';
	if (team=='O')
		oppTeam='X';
}

int Player::bestMove(int scores[])//Selects the highest scoring move and returns it. Parameter is the array for storing scores of the columns.
{
	int best=-1;
	for (int i=0; i<7; i++)
	{
		if (scores[i]>scores[best])
			best=i;
	}
	return best;
}

int Player::evalMove(int col, Board B, int s[][7])//This function determines which row of each column is where the next move will be made. Parameters are the column of the move, the array with predesignated scores for each space, and the board class.
{
	int rowOfMove; 
	char theArray[6][7];
	B.getArray(theArray);
	if (theArray[0][col]!='e')
		return (-999);//if the column is full it makes it an impossible move.
	for (int j=5; j>-1; j--)
	{
		if (theArray[j][col]=='e')
		{
			rowOfMove=j;
			break;
		}
	}

	return s[rowOfMove][col];

}

void Player::winLoseCheck(int scores[], Board B)//This function checks if moves will win the game, block the opponent from winning, or set up the opponent for a 1 move win on the next move. Parameters are the score array and the board class.
{
	for (int i=0; i<7; i++)//winning move check
	{
		if (B.checkMove(i))
		{
			B.makeMove(team,i);
			if (B.hasWon(team))
			{
				scores[i]+=100;
			}
			B.undoMove(i);
		}
	}
	for (int i=0; i<7; i++)//opponent winning move block.
	{
		if (B.checkMove(i))
		{
			B.makeMove(oppTeam,i);
			if (B.hasWon(oppTeam))
			{
				scores[i]+=75;
			}
			B.undoMove(i);
		}
	}

	for (int i=0; i<7; i++)//Opponent win setup avoidance.
		if (B.checkMove(i))
		{
			B.makeMove('Y', i);
			if (B.checkMove(i))
			{
				B.makeMove(oppTeam,i);
				if (B.hasWon(oppTeam))
				{
					scores[i]+= -50;
				}
				B.undoMove(oppTeam);
			}
			B.undoMove(i);
		}
}

void Player::hrz2Check(int scores[], Board B)//This function checks for horizontal 2 in a row with emty space on either side, in order to block the opponent from a certain win, or to build onto. I think this was one of the options for extra credit.
{
	char theArray[6][7];
	B.getArray(theArray);

	for (int i=1; i<6; i++)//Blocking 2 hrz.
	{
		if (theArray[5][i-1]=='e' && theArray[5][i]==oppTeam && theArray[5][i+1]==oppTeam && theArray[5][i+2]=='e')
		{
			scores[i-1]+=50;
			scores[i+2]+=50;
		}
	}
	for (int i=1; i<6; i++)
	{
		if (theArray[4][i-1]=='e' && theArray[4][i]==oppTeam && theArray[4][i+1]==oppTeam && theArray[4][i+2]=='e' && theArray[5][i-1]!='e' && theArray[5][i+1]!='e')
		{
			scores[i-1]+=50;
			scores[i+2]+=50;
		}
	}
	for (int i=1; i<6; i++)
	{
		if (theArray[3][i-1]=='e' && theArray[3][i]==oppTeam && theArray[3][i+1]==oppTeam && theArray[3][i+2]=='e' && theArray[4][i-1]!='e' && theArray[4][i+1]!='e' && theArray[5][i-1]!='e' && theArray[5][i+1]!='e')
		{
			scores[i-1]+=50;
			scores[i+2]+=50;
		}
	}
	for (int i=1; i<6; i++)
	{
		if (theArray[2][i-1]=='e' && theArray[2][i]==oppTeam && theArray[2][i+1]==oppTeam && theArray[2][i+2]=='e' && theArray[3][i-1]!='e' && theArray[3][i+1]!='e' && theArray[4][i-1]!='e' && theArray[4][i+1]!='e' && theArray[5][i-1]!='e' && theArray[5][i+1]!='e')
		{
			scores[i-1]+=50;
			scores[i+2]+=50;
		}
	}
	for (int i=1; i<6; i++)
	{
		if (theArray[1][i-1]=='e' && theArray[1][i]==oppTeam && theArray[1][i+1]==oppTeam && theArray[1][i+2]=='e' && theArray[2][i-1]!='e' && theArray[2][i+1]!='e' && theArray[3][i-1]!='e' && theArray[3][i+1]!='e' && theArray[4][i-1]!='e' && theArray[4][i+1]!='e' && theArray[5][i-1]!='e' && theArray[5][i+1]!='e')
		{
			scores[i-1]+=50;
			scores[i+2]+=50;
		}
	}
	for (int i=1; i<6; i++)
	{
		if (theArray[0][i-1]=='e' && theArray[0][i]==oppTeam && theArray[0][i+1]==oppTeam && theArray[0][i+2]=='e' && theArray[1][i-1]!='e' && theArray[1][i+1]!='e' && theArray[2][i-1]!='e' && theArray[2][i+1]!='e' && theArray[3][i-1]!='e' && theArray[3][i+1]!='e' && theArray[4][i-1]!='e' && theArray[4][i+1]!='e' && theArray[5][i-1]!='e' && theArray[5][i+1]!='e')
		{
			scores[i-1]+=50;
			scores[i+2]+=50;
		}
	}



	for (int i=1; i<6; i++)//Building on 2 hrz.
	{
		if (theArray[5][i-1]=='e' && theArray[5][i]==team && theArray[5][i+1]==team && theArray[5][i+2]=='e')
		{
			scores[i-1]+=25;
			scores[i+2]+=25;
		}
	}
	for (int i=1; i<6; i++)
	{
		if (theArray[4][i-1]=='e' && theArray[4][i]==team && theArray[4][i+1]==team && theArray[4][i+2]=='e' && theArray[5][i-1]!='e' && theArray[5][i+1]!='e')
		{
			scores[i-1]+=25;
			scores[i+2]+=25;
		}
	}
	for (int i=1; i<6; i++)
	{
		if (theArray[3][i-1]=='e' && theArray[3][i]==team && theArray[3][i+1]==team && theArray[3][i+2]=='e' && theArray[4][i-1]!='e' && theArray[4][i+1]!='e' && theArray[5][i-1]!='e' && theArray[5][i+1]!='e')
		{
			scores[i-1]+=25;
			scores[i+2]+=25;
		}
	}
	for (int i=1; i<6; i++)
	{
		if (theArray[2][i-1]=='e' && theArray[2][i]==team && theArray[2][i+1]==team && theArray[2][i+2]=='e' && theArray[3][i-1]!='e' && theArray[3][i+1]!='e' && theArray[4][i-1]!='e' && theArray[4][i+1]!='e' && theArray[5][i-1]!='e' && theArray[5][i+1]!='e')
		{
			scores[i-1]+=25;
			scores[i+2]+=25;
		}
	}
	for (int i=1; i<6; i++)
	{
		if (theArray[1][i-1]=='e' && theArray[1][i]==team && theArray[1][i+1]==team && theArray[1][i+2]=='e' && theArray[2][i-1]!='e' && theArray[2][i+1]!='e' && theArray[3][i-1]!='e' && theArray[3][i+1]!='e' && theArray[4][i-1]!='e' && theArray[4][i+1]!='e' && theArray[5][i-1]!='e' && theArray[5][i+1]!='e')
		{
			scores[i-1]+=25;
			scores[i+2]+=25;
		}
	}
	for (int i=1; i<6; i++)
	{
		if (theArray[0][i-1]=='e' && theArray[0][i]==team && theArray[0][i+1]==team && theArray[0][i+2]=='e' && theArray[1][i-1]!='e' && theArray[1][i+1]!='e' && theArray[2][i-1]!='e' && theArray[2][i+1]!='e' && theArray[3][i-1]!='e' && theArray[3][i+1]!='e' && theArray[4][i-1]!='e' && theArray[4][i+1]!='e' && theArray[5][i-1]!='e' && theArray[5][i+1]!='e')
		{
			scores[i-1]+=25;
			scores[i+2]+=25;
		}
	}
	
}

int Player::evalAllMoves(Board B)//Evaluation function that calls my other functions. Parameter is Board B.
{
	int scores[7], bestCol=0, s[6][7];//Array for storing the scores of each move, int for the best move, array for storing the score of each space;
	s[0][0]=1, s[0][1]=2, s[0][2]=3, s[0][3]=4, s[0][4]=3, s[0][5]=2, s[0][6]=1;//These integer assignments rank each space on the board for the ai. The more centralized the point is, the higher the value it is assigned. This was another extra credit option.
	s[1][0]=2, s[1][1]=3, s[1][2]=4, s[1][3]=5, s[1][4]=4, s[1][5]=3, s[1][6]=2;
	s[2][0]=3, s[2][1]=4, s[2][2]=5, s[2][3]=6, s[2][4]=5, s[2][5]=4, s[2][6]=3;
	s[3][0]=3, s[3][1]=4, s[3][2]=5, s[3][3]=6, s[3][4]=5, s[3][5]=4, s[3][6]=3;
	s[4][0]=2, s[4][1]=3, s[4][2]=4, s[4][3]=5, s[4][4]=4, s[4][5]=3, s[4][6]=2;
	s[5][0]=1, s[5][1]=2, s[5][2]=3, s[5][3]=4, s[5][4]=3, s[5][5]=2, s[5][6]=1;

	for (int col=0;col<7;col++)//Gets the score for each column.
		scores[col]=evalMove(col,B,s);
	winLoseCheck(scores,B);//Alters the scores depending on logic within this function.
	hrz2Check(scores, B);//Also alters the scores depending on logic.
	bestCol=bestMove(scores);//Selects the highest scoring column.
	return bestCol;
}



/*****************************************************************************
*  Human Player Class Declaration and Definitions
****************************************************************************/

class HumanPlayer
{
private:
	char player;  // 'X' or 'O'

public:
	HumanPlayer(char p);
	HumanPlayer();
	int evalAllMoves(Board b);
};

/*****************************************************************************
*  HumanPlayer Function Definitions
****************************************************************************/

/* HumanPlayer()
* Description: Initializes the human player to be 'X' by default
*/
HumanPlayer::HumanPlayer()
{
	player = 'X'; // default player
}


/* HumanPlayer(char player)
* Description: Initializes the human player to user-specified value
*/
HumanPlayer::HumanPlayer(char p)
{
	player = p;
}

/* evalAllMoves()
* Description: Prompt the human player for a move and validate it
* Arguments: The current Board class
*/
int HumanPlayer::evalAllMoves(Board b)
{
	bool validMove = false;
	int move;

	cout << "Human player " 
		<< player
		<< ": What column to play next? [0-6]: ";
	cin >> move;
	validMove = b.checkMove(move);

	while(!validMove)
	{
		cout << "Sorry, " << move 
			<< " is not a valid move for the current board." << endl;
		cout << "Please enter a valid column to play nextj [0-6]: ";
		cin >> move;
		validMove = b.checkMove(move);
	}

	return move;
}

/*****************************************************************************
*  Board Function Definitions
****************************************************************************/

/* Board()
* Description: Initializes the connect 4 board to be empty (as denoted by 'e')
*/
Board::Board()
{
	// for every row and column pair fill in an 'e'
	for (int row = 0; row < 6; row++)
		for (int col = 0; col < 7; col++)
			board[row][col] = 'e';
}
/* getArray
* Description: Fill the parameter theArray with the values currently stored in the
*              game board.  Must be 6 rows by 7 cols.
*/
void Board::getArray(char theArray[][7])
{
	for (int row = 0; row < 6; row++)
		for (int col = 0; col < 7; col++)
			theArray[row][col] = board[row][col];
}
/* printBoard()
* Description: Prints the board to the screen in a readable format
*/
void Board::printBoard()
{
	system("CLS");
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			// for each cell, print a blank space if it's empty or the player who
			// occupies that cell
			if (board[row][col] == 'e')
				cout << "|   ";
			else
				cout << "| " << board[row][col] << " ";
		}
		// break line at end of each row
		cout << "|\n";
	}
	// print column numbers at bottom
	cout << "-----------------------------\n  0   1   2   3   4   5   6\n\n";
}
/* checkMove()
* Description: Tests to see if the proposed move is legal
*/
bool Board::checkMove(int col)
{
	// if outside of legal column values, return false
	if (col < 0 || col > 6)
		return false;
	// if column is full, return false
	if (board[0][col] != 'e')
		return false;
	// otherwise, it's ok
	return true;
}
/* makeMove()
* Description: If the move is legal, updates the game board to reflect the
*              move the player is making.
*/
void Board::makeMove(char player, int col)
{
	// Test for legality
	if (checkMove(col))
	{
		// Find lowest empty row in specified column
		for (int i = 5; i >= 0; i--)
			if (board[i][col] == 'e')
			{
				// Fill in player's move
				board[i][col] = player;
				return;
			}
	}
}
/* undoMove
* Description: Removes the last token placed in the specified column
*/
void Board::undoMove(int col)
{
	for (int row = 0; row < 6; row++)
	{
		if (board[row][col] != 'e')
		{
			board[row][col] = 'e';
			return;
		}
	}
}
/* isFull()
* Description: Tests to see if board is completely full by checking top of each column
*/
bool Board::isFull()
{
	bool full = true;
	// since fill from bottom (row 5), just test row 0 for each column
	for (int col = 0; col < 7; col++)
		if (board[0][col] == 'e')
			full = false;
	return full;
}
/* reset()
* Description: Resets the board to be full of e's
*/
void Board::reset()
{
	// for every row and column pair fill in an 'e'
	for (int row = 0; row < 6; row++)
		for (int col = 0; col < 7; col++)
			board[row][col] = 'e';
}
/* hasWon
* Description: Tests to see if the specified player has won the game by checking all
*              4-in-a-row, 4-in-a-column and 4-on-a-diagonal possibilities.
*/
bool Board::hasWon(char player)
{
	// test for 4 in a row
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (board[row][col] == player &&
				board[row][col+1] == player &&
				board[row][col+2] == player &&
				board[row][col+3] == player)
				return true;
		}
	}
	// test for 4 in a column
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			if (board[row][col] == player &&
				board[row+1][col] == player &&
				board[row+2][col] == player &&
				board[row+3][col] == player)
				return true;
		}
	}
	// test for up-right diagonals
	for (int row = 5; row > 2; row--)
	{
		for (int col = 0; col < 4; col++)
		{
			if (board[row][col] == player &&
				board[row-1][col+1] == player &&
				board[row-2][col+2] == player &&
				board[row-3][col+3] == player)
				return true;
		}
	}
	// test for down-right diagonals
	for (int row = 5; row > 2; row--)
	{
		for (int col = 6; col > 2; col--)
		{
			if (board[row][col] == player &&
				board[row-1][col-1] == player &&
				board[row-2][col-2] == player &&
				board[row-3][col-3] == player)
				return true;
		}
	}

	// else, hasn't won
	return false;
}
/* hostTournament
* Description: hosts a games between two computer Player objects: pX and pO.
*              pX moves first and pO moves second.
*/
void Board::hostTournament()
{
	// Decide on type of game being played
	int mode; // 1=human, 2=computer
	do {
		cout << "Welcome to Connect-4" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Please select the desired game mode [1 or 2]:" << endl;
		cout << " (1) Human (X) versus Computer (O)" << endl;
		cout << " (2) Computer (X) versus Computer (O)" << endl;
		cin >> mode;
	} while (mode < 1 || mode > 2);

	// Create a human and two computer player objects
	// (note - not all objects will be used depending on game mode)
	HumanPlayer hpX('X');
	Player pX('X');
	Player pO('O');

	// initialize game board
	bool gameOver = false;
	int move = -1;
	// start the game: pauses added so user can watch game unfold
	printBoard();
	Sleep(500); // pause for 500 milliseconds (0.5 seconds)
	do
	{
		// Player X makes a move.
		do
		{
			if(mode==1)
				move = hpX.evalAllMoves(*this); // human player
			else
				move = pX.evalAllMoves(*this); // computer player
		} while(!checkMove(move));
		makeMove('X',move);
		printBoard();
		Sleep(500);
		// check to see if it was a winning move
		if (hasWon('X'))
		{
			cout << "Congratulations Player X, you have won!!\n\n";
			gameOver = true;
		}
		// check to see if move resulted in a stalemate
		else if (isFull())
		{
			cout << "A Stalemate, too bad!\n\n";
			gameOver = true;
		}
		else
		{
			// Player O makes a move
			do
			{
				move = pO.evalAllMoves(*this);
			}while(!checkMove(move));
			makeMove('O',move);
			printBoard();
			Sleep(500);
			// check to see if it was the winning move
			if (hasWon('O'))
			{
				cout << "Congratulations Player O, you have won!!\n\n";
				gameOver = true;
			}
			// check to see if move resulted in a statemate
			else if (isFull())
			{
				cout << "A Stalemate, too bad!\n\n";
				gameOver = true;
			}
		}		
		// continue until either one player wins or the board fills up
	}while (!gameOver);
}

/*****************************************************************************
*  main 
****************************************************************************/

int main ()
{
	// in case anyone's using random numbers
	srand((unsigned)time(0));
	// create game board
	Board b;
	// start tournament
	b.hostTournament();
	system("PAUSE");
}