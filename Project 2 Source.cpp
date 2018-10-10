#include<iostream>
#include<math.h>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
/*  Taylor Morlan
Project 2 - Subtract a Square */
int main(){
	srand((unsigned)time(0));//Initializing random number generation.
	int heapOne;//Integer for number of marbles in the first heap.
	int heapTwo;//Integer for number of marbles in the second heap.
	int whoWon;//Integer to determine who won the game in the end.
	bool gameRunning=true;//Boolean expression used to see if the game is over or not.
	heapOne=rand()%100+1;
	heapTwo=rand()%100+1;
	cout << "Welcome to Subtract a Square!"<<endl;
	do{//This do-while loop encompasses the majority of the program, the program breaks from it once all of the marbles have been taken.
		cout << "Heap One: " << heapOne << " marbles" <<endl << "Heap Two: " << heapTwo << " marbles" <<endl;
		cout << "Please select a heap to take marbles from. Enter 1 for"<<endl<< "heap one or 2 for heap two."<<endl;
		int userSelection;//This integer is for the user's selection of which pile to draw from.
		cin >> userSelection;
		int marblesToSubtract;//This integer is for the number of marbles that will be subtracted by the user or computer.
		double d_sqrt;//This double and the integer below are used in a section of code that determines whether the user input and the computer random choice are perfect squares.
		int i_sqrt;
		int continueLoop=1;//This integer is used to check whether a loop should be continued.
		if (userSelection==1){//this statement is activated if the user chooses the first heap of marbles.
			if(heapOne>0){//This checks to see if the heap is empty, if it is, the else statement below prompts the user to select the other pile.
				do{
					cout << "How many marbles would you like to take from the heap?"<<endl;
					cin >> marblesToSubtract;//This is the user input for the number of marbles to subtract.
					d_sqrt = sqrt((double)marblesToSubtract);//this line and the one below it check to see if the input is a perfect square.
					i_sqrt = d_sqrt;
					if (marblesToSubtract>0 && marblesToSubtract<=heapOne && i_sqrt==d_sqrt){/*This if statement activates if the user input is greater than zero, less than or equal to the pile size, and a perfect square.*/
						continueLoop=0;//Defining this integer exits the loop.
						heapOne=heapOne-marblesToSubtract;
						cout << "Heap One: " << heapOne << " marbles" <<endl << "Heap Two: " << heapTwo << " marbles" <<endl;
					}
					else{
						cout << "You did not enter a valid number of marbles to take, please try again..."<<endl;
						system("pause");
					}
				}while(continueLoop==1);
				if (heapOne==0&&heapTwo==0){//This statement is used after each user or computer move to check to see if both piles are empty, if they are, it breaks from the loop and ends the game.
					whoWon=1;
					gameRunning=false;
					break;
				}
				int computerChoice;//This integer is for the computer's pile choice.
				computerChoice = rand()%2+1;//This randomizes the computer's pile choice.
				if (computerChoice==1){
					if (heapOne>0){//this makes sure the pile isn't empty.
						int squareRootOne=sqrt((double)heapOne);//The next 3 lines randomly select a perfect square that is not bigger than the pile.
						int compMarbles=rand()%squareRootOne+1;
						int compMarblesSquare=(compMarbles)*(compMarbles);
						heapOne=heapOne-compMarblesSquare;//The random square is subtracted.
						cout<<"I took " <<compMarblesSquare<< " from Heap 1."<<endl;
					}
					else if (heapOne==0){//If the pile is empty, the computer defaults to the other pile.
						int squareRootOne=sqrt((double)heapTwo);
						int compMarbles=rand()%squareRootOne+1;
						int compMarblesSquare=(compMarbles)*(compMarbles);
						heapTwo=heapTwo-compMarblesSquare;
						cout<<"I took " <<compMarblesSquare<< " from Heap 2."<<endl;
					}
				}
				else if (computerChoice==2){//This is the same as above, except the computer chose the second pile.
					if (heapTwo>0){
						int squareRootOne=sqrt((double)heapTwo);
						int compMarbles=rand()%squareRootOne+1;
						int compMarblesSquare=(compMarbles)*(compMarbles);
						heapTwo=heapTwo-compMarblesSquare;
						cout<<"I took " <<compMarblesSquare<< " from Heap 2."<<endl;
					}
					else if (heapTwo==0){
						int squareRootOne=sqrt((double)heapOne);
						int compMarbles=rand()%squareRootOne+1;
						int compMarblesSquare=(compMarbles)*(compMarbles);
						heapOne=heapOne-compMarblesSquare;
						cout<<"I took " <<compMarblesSquare<< " from Heap 1."<<endl;
					}
				}
				if (heapOne==0&&heapTwo==0){
					whoWon=0;
					gameRunning=false;
					break;
				}
			}else//This statement is used if heap one is empty.
				cout << "That heap has no marbles."<<endl;
		}
		else if (userSelection==2){//This goes through the same process as when then user selects 1, but it substitutes heap two where it said heap one, and vice versa.
			if (heapTwo>0){
				do{
					cout << "How many marbles would you like to take from the heap?"<<endl;
					cin >> marblesToSubtract;
					d_sqrt = sqrt((double)marblesToSubtract);
					i_sqrt = d_sqrt;
					if (marblesToSubtract>0 && marblesToSubtract<=heapTwo && i_sqrt==d_sqrt){
						continueLoop=0;
						heapTwo=heapTwo-marblesToSubtract;
						cout << "Heap One: " << heapOne << " marbles" <<endl << "Heap Two: " << heapTwo << " marbles" <<endl;
					}
					else{
						cout << "You did not enter a valid number of marbles to take, please try again..."<<endl;
						system("pause");
					}
				}while(continueLoop==1);

				if (heapOne==0&&heapTwo==0){
					whoWon=1;
					gameRunning=false;
					break;
				}

				int computerChoice;//The computer move is exactly the same as above.
				computerChoice = rand()%2+1;
				if (computerChoice==1){
					if (heapOne>0){
						int squareRootOne=sqrt((double)heapOne);
						int compMarbles=rand()%squareRootOne+1;
						int compMarblesSquare=(compMarbles)*(compMarbles);
						heapOne=heapOne-compMarblesSquare;
						cout<<"I took " <<compMarblesSquare<< " from Heap 1."<<endl;
					}
					else if(heapOne==0){
						int squareRootOne=sqrt((double)heapTwo);
						int compMarbles=rand()%squareRootOne+1;
						int compMarblesSquare=(compMarbles)*(compMarbles);
						heapTwo=heapTwo-compMarblesSquare;
						cout<<"I took " <<compMarblesSquare<< " from Heap 2."<<endl;
					}
				}
				else if (computerChoice==2){
					if (heapTwo>0){
						int squareRootOne=sqrt((double)heapTwo);
						int compMarbles=rand()%squareRootOne+1;
						int compMarblesSquare=(compMarbles)*(compMarbles);
						heapTwo=heapTwo-compMarblesSquare;
						cout<<"I took " <<compMarblesSquare<< " from Heap 2."<<endl;
					}else if (heapTwo==0){
						int squareRootOne=sqrt((double)heapOne);
						int compMarbles=rand()%squareRootOne+1;
						int compMarblesSquare=(compMarbles)*(compMarbles);
						heapOne=heapOne-compMarblesSquare;
						cout<<"I subtracted " <<compMarblesSquare<< " from Heap 1."<<endl;
					}
				}
				if (heapOne==0&&heapTwo==0){
					whoWon=0;
					gameRunning=false;
					break;
				}
			}else
				cout << "That heap has no marbles."<<endl;
		}
		else{//This is activated if the user does not pick a pile correctly.
			cout << "You did not enter 1 or 2, please try again..."<<endl;
			system("pause");
		}

	}while(gameRunning);
	if (whoWon==0)//This if statement or the else if below it output the winner of the game.
		cout << "Congratulations User! You have won the game!"<<endl;
	else if(whoWon==1)
		cout << "I have won the game."<<endl;
	system("pause");


}

