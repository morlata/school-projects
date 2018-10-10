//Project One Source

#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;
//This program was written by Taylor Morlan. Also, I wrote most of this before you taught us how to make loops, so, there is a lot of copied and pasted code. 
//These are variables used in the program.
int sum;//This is the sum of the two numbers for the game.
int userNumber;//This is the number that the user chooses in the game.
int main()
{
	srand ((unsigned)time(0));//This is for random number generation.
	int compNum;//This is the variable the program will use for the randomly generated number.
	char userChoice;//This is the character for the user's response to the first question.
	cout << "Welcome to Odd or Even!" << endl;
	cout << "Would you like to be (O)dd or (E)ven?" << endl;//This is just asking the user to pick a side.
	cin >> userChoice;
	//These are variables to keep track of the number of round wins the computer and user have individually.
	int userWins=0;
	int computerWins=0;
	switch (userChoice)// I used a switch to differentiate between the possible user input options, o for odd, e for even, and any other inputs default the user to odd.
	{

		case 'O':
		case 'o':
			cout << "Please enter a number in the range [1,5]." <<endl;
			cin >> userNumber;
				if (userNumber<1 || userNumber>5){//I used this if statement to default the user to to 3, if they enter a number outside of the range [1,5].
					cout << "Error: That number is not in the range [0,5]. Let's say that you picked 3."<<endl;
					userNumber=3;}
			cout << "I will select a number in the range [1,5] then add the two numbers." <<endl;
			compNum = rand()%5 + 1;//This randomly generates a number from 1 to 5.
			cout << "I chose " <<compNum<< ".";
			(sum = userNumber + compNum);
				if (sum%2==0){//This checks whether or not the sum is even.
					cout << "The sum is " << sum << " which is even." << endl << "I'm sorry but I have won this round." <<endl;
					(computerWins++);//This adds a win to the computer.
	}
				else
	{
					cout << "Congratulations! The sum is " << sum << " which is odd." <<endl<< "You have won this round." <<endl;
					(userWins++);
	}
	//Just redoing the same process for the second round.
			cout << "Please enter a number in the range [1,5]." <<endl;
			cin >> userNumber;
				if (userNumber<1 || userNumber>5){
					cout << "Error: That number is not in the range [0,5]. Let's say that you picked 3."<<endl;
					userNumber=3;}
			cout << "I will randomly select a number in the range [1,5]." <<endl;
			compNum = rand()%5+1;
			cout << "I chose " <<compNum<< ".";
			(sum = userNumber + compNum);
				if (sum%2==0){
					cout << "The sum is " << sum << " which is even." <<endl << "I'm sorry but I have won this round." <<endl;
					(computerWins++);
	}
				else
	{
					cout << "Congratulations! The sum is " << sum << " which is odd!" <<endl<< "You have won this round." <<endl;
					(userWins++);
	}
				if (userWins == 2){
					cout << "Congratulations User! You have won the match!"<<endl;
					system ("pause");
	}
				else if (computerWins ==2){
					cout << "I'm sorry user. You have lost the match."<<endl;
					system ("pause");
	}
	//This is the optional and final round of the game.
				else{
					cout << "Please enter a number in the range [1,5]." <<endl;
					cin >> userNumber;
				if (userNumber<1 || userNumber>5){
					cout << "Error: That number is not in the range [0,5]. Let's say that you picked 3."<<endl;
					userNumber=3;}
			cout << "I will randomly select a number in the range [1,5]." <<endl;
			compNum = rand()%5+1;
			cout << "I chose " <<compNum<< ".";
			(sum = userNumber + compNum);
				if (sum%2==0){
					cout << "The sum is " << sum << " which is even." <<endl << "I'm sorry but I have won this round." <<endl;
					(computerWins++);
	}
				else
	{
					cout << "Congratulations! The sum is " << sum << " which is odd!" <<endl<< "You have won this round." <<endl;
					(userWins++);
	}
				if (userWins==2){
					cout << "Congratulations user! You have won the match!"<<endl;
					system ("pause");
	}
				else if (computerWins==2){
					cout << "I'm sorry user. You have lost the match."<<endl;
					system ("pause");
	}
	break;
	//This code is initiated if the user enters e for the first question.
		case 'e':
		case 'E':
			cout << "Please enter a number in the range [1,5]." <<endl;
			cin >> userNumber;
				if (userNumber<1 || userNumber>5){
					cout << "Error: That number is not in the range [0,5]. Let's say that you picked 3."<<endl;
					userNumber=3;}
			cout << "I will select a number in the range [1,5] then add the two numbers." <<endl;
			compNum = rand()%5 + 1;
			cout << "I chose " <<compNum<< ".";
			(sum = userNumber + compNum);
				if (sum%2==0){
					cout << "Congratulations! The sum is " << sum << " which is even." << endl << "You have won this round." <<endl;
					userWins++;
	}
				else
	{
					cout << "The sum is " << sum << " which is odd." <<endl<< "I'm sorry but I have won this round." <<endl;
					(computerWins++);
	}
	//Just redoing the same process.
			cout << "Please enter a number in the range [1,5]." <<endl;
			cin >> userNumber;
				if (userNumber<1 || userNumber>5){
					cout << "Error: That number is not in the range [0,5]. Let's say that you picked 3."<<endl;
					userNumber=3;}
			cout << "I will randomly select a number in the range [1,5]." <<endl;
			compNum = rand()%5+1;
			cout << "I chose " <<compNum<< ".";
			(sum = userNumber + compNum);
				if (sum%2==0){
				cout << "Congratulations! The sum is " << sum << " which is even." <<endl << "You have won this round." <<endl;
				(userWins++);
	}
				else
	{
					cout << "The sum is " << sum << " which is odd." <<endl<< "I'm sorry but I have won this round." <<endl;
					(computerWins++);
	}
				if (userWins == 2){
					cout << "Congratulations User! You have won the match!"<<endl;
					system ("pause");
	}
				else if (computerWins ==2){
					cout << "I'm sorry user. You have lost the match."<<endl;
					system ("pause");
	}
	//This is the optional and final round of the game.
				else{
					cout << "Please enter a number in the range [1,5]." <<endl;
					cin >> userNumber;
				if (userNumber<1 || userNumber>5){
					cout << "Error: That number is not in the range [0,5]. Let's say that you picked 3."<<endl;
					userNumber=3;}
			cout << "I will randomly select a number in the range [1,5]." <<endl;
			compNum = rand()%5+1;
			cout << "I chose " <<compNum<< ".";
			(sum = userNumber + compNum);
				if (sum%2==0){
					cout << "Congratulations! The sum is " << sum << " which is even." <<endl << "You have won this round." <<endl;
					(userWins++);
	}
				else
	{
					cout << "The sum is " << sum << " which is odd." <<endl<< "I'm sorry but I have won this round." <<endl;
					(computerWins++);
	}
				if (userWins==2){
					cout << "Congratulations user! You have won the match!"<<endl;
					system ("pause");
	}
				else if (computerWins==2){
					cout << "I'm sorry user. You have lost the match."<<endl;
					system ("pause");
	}

	



		break;
		//This code is initiated if the user enters something other than o and e.
		default:
			cout << "Error: that is not an option. User is defaulted to Odds." <<endl;//Telling the user that they are odds.
	//This is just a copy of the code I wrote for when the user chooses odd.
			cout << "Please enter a number in the range [1,5]." <<endl;
			cin >> userNumber;
				if (userNumber<1 || userNumber>5){
					cout << "Error: That number is not in the range [0,5]. Let's say that you picked 3."<<endl;
					userNumber=3;}
			cout << "I will select a number in the range [1,5] then add the two numbers." <<endl;
			compNum = rand()%5 + 1;
			cout << "I chose " <<compNum<< ".";
			(sum = userNumber + compNum);
				if (sum%2==0){
					cout << "The sum is " << sum << " which is even." << endl << "I'm sorry but I have won this round." <<endl;
					(computerWins++);
	}
				else
	{
					cout << "Congratulations! The sum is " << sum << " which is odd." <<endl<< "You have won this round." <<endl;
					(userWins++);
	}
	//Just redoing the same process.
			cout << "Please enter a number in the range [1,5]." <<endl;
			cin >> userNumber;
				if (userNumber<1 || userNumber>5){
					cout << "Error: That number is not in the range [0,5]. Let's say that you picked 3."<<endl;
					userNumber=3;}
			cout << "I will randomly select a number in the range [1,5]." <<endl;
			compNum = rand()%5+1;
			cout << "I chose " <<compNum<< ".";
			(sum = userNumber + compNum);
				if (sum%2==0){
					cout << "The sum is " << sum << " which is even." <<endl << "I'm sorry but I have won this round." <<endl;
					(computerWins++);
	}
				else
	{
					cout << "Congratulations! The sum is " << sum << " which is odd!" <<endl<< "You have won this round." <<endl;
					(userWins++);
	}
				if (userWins == 2){
					cout << "Congratulations User! You have won the match!"<<endl;
					system ("pause");
	}
				else if (computerWins ==2){
					cout << "I'm sorry user. You have lost the match."<<endl;
					system ("pause");
	}
	//This is the optional and final round of the game.
				else{
					cout << "Please enter a number in the range [1,5]." <<endl;
					cin >> userNumber;
				if (userNumber<1 || userNumber>5){
					cout << "Error: That number is not in the range [0,5]. Let's say that you picked 3."<<endl;
					userNumber=3;}
			cout << "I will randomly select a number in the range [1,5]." <<endl;
			compNum = rand()%5+1;
			cout << "I chose " <<compNum<< ".";
			(sum = userNumber + compNum);
				if (sum%2==0){
					cout << "The sum is " << sum << " which is even." <<endl << "I'm sorry but I have won this round." <<endl;
					(computerWins++);
	}
				else
	{
					cout << "Congratulations! The sum is " << sum << " which is odd!" <<endl<< "You have won this round." <<endl;
					(userWins++);
	}
				if (userWins==2){
					cout << "Congratulations user! You have won the match!" <<endl;
					system ("pause");
	}
				else if (computerWins==2){
					cout << "I'm sorry user. You have lost the match."<<endl;
					system ("pause");
	}
}
}
}
}
}