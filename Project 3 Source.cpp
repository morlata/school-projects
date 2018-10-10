/* Taylor Morlan
COMP 51
Project 3	*/

#include<iostream>
#include<ctime>
#include<math.h>
using namespace std;
double highLow(double money,double bet);//Function Declaration for High-Low.
double twentyOne(double money, double bet);//Function Declaration for 21.
double craps(double money, double bet);//Function declaration for Craps.
double slots(double money, double bet);//Function declaration for slots.
double betCheck(double money);//Function declaration for bet checker.
void test_highLow();//Test function declarations...
void test_twentyOne();
void test_craps();
void test_slots();
void test_betCheck();
int main()
{
	bool inCasino=true;//Boolean used to tell if the user is in the casino or not.
	bool testing=true;//Boolean used to tell if the user is still testing functions.
	double money, bet;//Money is the total amount of money that the user has. Bet is the bet.
	srand((unsigned)time(0));//Random number generation seed.
	money = rand()%100+1;//Randomly generate a number [1,100]
	money=money+100;//Add 100

	cout << "Welcome to the Casino!"<<endl;
	cout << "You have $" << money<<endl;
	do{//Do-While loop the loops the main menu until the user is out of money or quits.
		cout << "Please select an option from the following list:" <<endl<< "1.) Play High-Low" <<endl<< "2.) Play 21" <<endl<< "3.) Play Craps" <<endl<< "4.) Play the Slots" <<endl<< "5.) Test Functions"<<endl<< "6.) Leave Casino"<<endl;
		char userChoice;
		cin >> userChoice;
		switch (userChoice)//Switch for option selection.
		{
		case '1':
			cout << "Welcome to High-Low."<<endl;
			bet=betCheck(money);//Activates betCheck function, which gets a valid user bet.
			money += highLow(money, bet);//Plays the high-low function with the user total money and bet, then either subtracts the bet from the total or adds the winnings to the total.
			cout << "You now have $" <<money<<endl;
			if (money==0)//If the user has no money, they are booted from the casino.
			{
				inCasino=false;
				cout << "You are out of money!"<<endl;
			}
			break;
		case '2'://Same process as above, but for 21.
			cout << "Welcome to 21."<<endl;
			bet=betCheck(money);
			money+=twentyOne(money, bet);
			cout << "You now have $" <<money<<endl;
			if (money==0)
			{
				inCasino=false;
				cout << "You are out of money!"<<endl;
			}
			break;
		case '3'://Same process for craps.
			cout << "Welcome to Craps."<<endl;
			bet=betCheck(money);
			money+=craps(money, bet);
			cout << "You now have $" <<money<<endl;
			if (money==0)
			{
				inCasino=false;
				cout << "You are out of money!"<<endl;
			}
			break;
		case '4'://Same process for Slots.
			cout << "Welcome to the Slots."<<endl;
			bet=betCheck(money);
			money+=slots(money, bet);
			cout << "You now have $" <<money<<endl;
			if (money==0)
			{
				inCasino=false;
				cout << "You are out of money!"<<endl;
			}
			break;
		case '5'://Testing functions.
			do{
				cout << "Which function would you like to test?"<<endl<<"1.) Play High-Low" <<endl<< "2.) Play 21" <<endl<< "3.) Play Craps" <<endl<< "4.) Play the Slots" <<endl<< "5.) Bet Checker"<<endl<< "5.) Stop Test"<<endl;
				char testChoice;
				cin >> testChoice;
				switch (testChoice)//Switch to pick which function to test, or to stop testing.
				{
				case '1':
					test_highLow();//Activates the test function for high low.
					break;
				case '2':
					test_twentyOne();//Test function for 21.
					break;
				case '3':
					test_craps();//Test function for craps.
					break;
				case '4':
					test_slots();//Test function for slots.
					break;
				case '5':
					test_betCheck();//Test function for the bet function.
					break;
				case '6'://Option to stop testing.
					cout << "Returning to normal Casino operations."<<endl;
					testing=false;//Ends loop.
					break;
				default://If the user doesn't enter one of the options above.
					cout << "You didn't enter a valid option."<<endl;
				}
			}while(testing==true);
			break;
		case '6'://Option to leave the casino.
			inCasino=false;
			break;
		default://If the user doesn't enter one of the options.
			cout << "You did not select one of the options, please try again..."<<endl;
		}
	}while (inCasino==true);//do-while loop mentioned above.
	cout << "Goodbye."<<endl;
	system("pause");
}
//Functions

//Bet Function
double betCheck(double money)
{
	bool betValidation=false;//Bool used for loop that tests bet.
	double bet;
	do{
		cout << "How much would you like to bet?"<<endl;
		cin >> bet;//User enters a bet.
		if (bet<=money && bet>0)//If it's valid, the loop is terminated, and the bet is kept.
			betValidation=true;
		else //If it isnt' valid, it loops and reprompts the user until it is valid.
		{
			cout << "You didn't enter a valid amount to bet..."<<endl;
			cout << "You have $"<<money<<endl;
		}
	}while (betValidation==false);
	return(bet);//Returns a valid bet.
}

//High-Low Function-----------------------------------------------------------------------------------------------------------------------------------------------

double highLow(double money, double bet)
{
	if (bet<0 || bet>money)//The only reason this and the next 4 lines are here is to make the test_betCheck function have a purpose for project requirements.
	{
		cout << "Error! Invalid input!";
		return(0);//quits the function
	}
	int compNum = rand()%10+1;//Random number 1-10.
	cout << "The number is: " <<compNum<<endl;
	cout << "Will the next number be (H)igher or (L)ower?"<<endl;
	char userInput;
	bool gameRunning=true;//Bool to see if the game is still running.
	int newCompNum=rand()%10+1;//Random number 1-10.
	do{
		cin >> userInput;
		switch (userInput)//Switch for if the user thinks the next number will be higher or lower.
		{
		case 'h'://User picks higher.
		case 'H':
			if (newCompNum>compNum)//If new number is bigger, user wins.
			{
				cout << "The second number is "<<newCompNum<<" which is greater than "<<compNum<<". You win!"<<endl;
			}
			else if (newCompNum==compNum)//If it's the same, user loses.
			{
				cout << "The second number is "<<newCompNum<<" which is equal to "<<compNum<<". You lose."<<endl;
				bet=-bet;
			}
			else //If it's less, user loses.
			{
				cout << "The second number is "<<newCompNum<<" which is less than "<<compNum<<". You lose."<<endl;
				bet=-bet;
			}
			gameRunning=false;//Game over.
			break;

		case 'l'://User picks lower.
		case 'L':
			if (newCompNum<compNum){//If it's less, user wins.
				cout << "The second number is "<<newCompNum<<" which is less than "<<compNum<<". You win!"<<endl;
			}
			else if (newCompNum==compNum){//If it's equal, user loses.
				cout << "The second number is "<<newCompNum<<" which is equal to "<<compNum<<". You lose."<<endl;
				bet=-bet;
			}
			else {//If it's greater, user loses.
				cout << "The second number is "<<newCompNum<<" which is greater than "<<compNum<<". You lose."<<endl;
				bet=-bet;
			}
			gameRunning=false;//Game is over
			break;

		default://If the user doesn't enter a valid option.
			cout << "You did not enter a valid option, please try again..."<<endl;
		}
	}while (gameRunning==true);//Loops till the user picks a valid option and finishes the game.
	return(bet);//Returns the winnings, losses.
}

//21 Function----------------------------------------------------------------------------------------------------------------------

double twentyOne(double money, double bet)
{
	if (bet<0 || bet>money)//another section of code just to give the test_betCheck a purpose.
	{
		cout << "Error! Invalid input!";
		return(0);
	}
	int total;//User total of cards.
	int cardOne=rand()%13+1;//Random card 1-13
	int cardTwo=rand()%13+1;
	int additionalCard;
	if (cardOne>=11 && cardOne<=13)//Jacks through kings, this code is used to create more accurate odds.
		cardOne=10;
	if (cardTwo>=11 && cardTwo<=13)
		cardTwo=10;
	total=cardOne+cardTwo;//Adds cards.
	cout << "You first card is "<<cardOne<<" and your second card is "<<cardTwo<<"."<<endl<<"Your total is "<<total<<"."<<endl;
	char userChoice;
	bool userParticipating=true;//Bool to check if the user still wants to hit.
	do{
		cout << "Would you like to (H)it or (S)tay?"<<endl;
		cin >> userChoice;
		switch(userChoice)
		{
		case 'h'://User hits.
		case 'H':
			additionalCard=rand()%13+1;//Random generator for each additional card the user wants.
			if (additionalCard>=11 && additionalCard<=13)
				additionalCard=10;
			total=total+additionalCard;//Adds the card to the total.
			cout << "Your new total is "<<total<<"."<<endl;
			if (total==21)//Must stay.
			{
				cout<<"Your total is "<<total<<". You have to stay."<<endl;
				userParticipating=false;
				break;
			}
			if (total>21)//Bust.
			{
				cout<<"Your total is "<<total<<". You have busted and you lose."<<endl;
				userParticipating=false;
				break;
			}
			break;
		case 's'://User stays.
		case 'S':
			userParticipating=false;//User stops hitting.
			break;
		default:
			cout << "You didn't enter a valid option. Please try again..."<<endl;
		}

	}while(userParticipating==true);
	if (total>21)//bust
	{
		cout << "You busted, so you lose."<<endl;
		bet=-bet;
	}
	if (total<=21)//Fair game
	{
		int compNum=rand()%7+16;//Computer picks a number from 16-23
		cout << "My total is "<<compNum<<endl;
		if (compNum>21)//Computer busts
		{
			cout << "I busted, so you win!"<<endl;
			bet=2*bet;
		}
		else if (total>compNum)//Computer loses.
		{
			cout << "Your total is higher than mine, so you win!"<<endl;
			bet=2*bet;
		}
		else if (total==compNum)//Computer wins.
		{
			cout << "Our totals are the same, so I win."<<endl;
			bet=-bet;
		}
		else //Computer wins.
		{
			cout << "My total is higher than yours. You lose."<<endl;
			bet=-bet;
		}
	}
	return(bet);//Returns the winnings/losses.
}


//Craps Function----------------------------------------------------------------------------------------------------------------------------craps------------

double craps(double money, double bet)
{
	if (bet<0 || bet>money)//Same pointless code as before...
	{
		cout << "Error! Invalid input!";
		return(0);
	}
	bool userSelectionValidation=false;//bool for if the user picks a valid option.
	int dieSum, dieOne, dieTwo;//Integers for dice.
	do{
		cout << "Would you like to bet on (P)ass or (N)o Pass?"<<endl;
		char userInput;
		cin >> userInput;
		switch (userInput)//Switch for user choice of Pass or No pass.
		{
		case 'p'://Pass
		case 'P':
			userSelectionValidation=true;//Valid option.
			dieOne=rand()%6+1;//Random number for die.
			dieTwo=rand()%6+1;
			dieSum=dieOne+dieTwo;
			if (dieSum==2 || dieSum==3 || dieSum==12)//Craps. User loses.
			{
				cout << "The sum of the dice is "<<dieSum<<", which is Craps."<<endl;
				cout << "You lose."<<endl;
				bet=-bet;
				break;
			}
			else if (dieSum==7 || dieSum==11)//Natural, user wins.
			{
				cout << "The sum of the dice is "<<dieSum<<", which is a Natural."<<endl;
				cout << "You win!"<<endl;
				break;
			}
			else//Must reroll.
			{
				cout << "The sum of the dice is "<<dieSum<<" which is not an acceptable value. I will re-roll for"<<endl<<"you until the value is the same as the original value or 7."<<endl;
				int dieSumTwo;
				do{//Loops till the two die add up to the first number, or 7.
					cout << "Rolling..."<<endl;
					dieOne=rand()%6+1;
					dieTwo=rand()%6+1;
					dieSumTwo=dieOne+dieTwo;
					cout << dieSumTwo<<endl;
				}while(dieSumTwo!=dieSum && dieSumTwo!=7);
				if (dieSumTwo==7)//User loses.
				{
					cout << "The new sum of the dice is "<<dieSumTwo<<"."<<endl;
					cout << "You lose."<<endl;
					bet=-bet;//makes the bet a negative number, to subtract form total money.
					break;
				}
				if (dieSum==dieSumTwo)//Same number as before, user wins.
				{
					cout << "The new sum of the dice is "<<dieSumTwo<<", which is the same as the orginal sum."<<endl;
					cout << "You win!"<<endl;
					break;
				}
			}
		case 'n':
		case 'N'://No pass, same as pass, except the wins and losses are changed.
			userSelectionValidation=true;
			dieOne=rand()%6+1;
			dieTwo=rand()%6+1;
			dieSum=dieOne+dieTwo;
			if (dieSum==2 || dieSum==3 || dieSum==12)
			{
				cout << "The sum of the dice is "<<dieSum<<", which is Craps."<<endl;
				cout << "You Win!"<<endl;
				break;
			}
			else if (dieSum==7 || dieSum==11)
			{
				cout << "The sum of the dice is "<<dieSum<<", which is a Natural."<<endl;
				cout << "You lose."<<endl;
				bet=-bet;
				break;
			}
			else
			{
				cout << "The sum of the dice is "<<dieSum<<" which is not an acceptable value. I will re-roll for"<<endl<<"you until the value is the same as the original value or 7."<<endl;
				int dieSumTwo;
				do{
					cout << "Rolling..."<<endl;
					dieOne=rand()%6+1;
					dieTwo=rand()%6+1;
					dieSumTwo=dieOne+dieTwo;
					cout << dieSumTwo<<endl;
				}while(dieSumTwo!=dieSum && dieSumTwo!=7);
				if (dieSumTwo==7)
				{
					cout << "The new sum of the dice is "<<dieSumTwo<<"."<<endl;
					cout << "You win!"<<endl;
					break;
				}
				if (dieSum==dieSumTwo)
				{
					cout << "The new sum of the dice is "<<dieSumTwo<<", which is the same as the orginal sum."<<endl;
					cout << "You lose."<<endl;
					bet=-bet;
					break;
				}
			}
		default:
			cout << "You did not enter a valid selection."<<endl;
		}
	}while(userSelectionValidation==false);
	return(bet);//Returns the winnings/losses.
}

//Slots Function----------------------------------------------------------------------------------------------------------------------------------------------

double slots(double money, double bet)
{
	if (bet<0 || bet>money)//Same code...
	{
		cout << "Error! Invalid input!";
		return(0);
	}
	cout << "Spinning..."<<endl;

	int wheelOne=rand()%8+1;//random number 1-9
	int wheelTwo=rand()%8+1;
	int wheelThree=rand()%8+1;

	cout <<wheelOne<<" "<<wheelTwo<<" "<<wheelThree<<endl;

	if (wheelOne==wheelTwo && wheelOne==wheelThree)//If they are all the same, it's the jackpot.
	{
		cout << "All three wheels are the same! Congratulation, you hit the jackpot!"<<endl;
		bet=99*bet;
	}
	else if (wheelOne==wheelTwo || wheelOne==wheelThree || wheelTwo==wheelThree)//If two are the same, it's still a win.
	{
		cout << "Two of the three wheels are the same! You won!"<<endl;
		bet=10*bet;
	}
	else//None are the same, user loses bet.
	{
		cout << "None of the wheels are the same. You lose."<<endl;
		bet=-bet;
	}
	return(bet);//returns winnings/losses.
}

//Test Functions

//Test High-Low--------------------------------------------------------------------------------------------------------------------------------------------
void test_highLow()//Inputs values for money and bet to function highLow.

{
	double bet, money=100;//Sets money to 100, will not make test less accurate.
	cout << "For the purpose of this test I will assign the total user money to be $100."<<endl;
	cout << "Common user inputs:"<<endl;//common cases
	cout << "Bet=25"<<endl;
	bet=25;
	bet=highLow(money,25);
	cout << "You now have $"<<(money+bet)<<endl;
	cout << "Bet=47"<<endl;
	bet=47;
	bet=highLow(money,47);
	cout << "You now have $"<<(money+bet)<<endl;

	cout <<"Bet=69"<<endl;
	bet=69;
	bet=highLow(money,69);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Boundary Cases:"<<endl;//Boundary cases 1 or 100
	cout << "Bet=100"<<endl;
	bet=100;
	bet=highLow(money,100);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Bet=1"<<endl;
	bet=1;
	bet=highLow(money,1);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Error Cases:"<<endl;//invalid inputs, though it isn't possible with the betCheck function.
	cout << "Bet=-10"<<endl;
	bet=-10;
	bet=highLow(money,-10);

	cout <<endl<< "Bet=9999"<<endl;
	bet=9999;
	bet=highLow(money,9999);
	cout <<endl;
}


//Test 21-----------------------------------------------------------------------------------------------------------------------------------------------------

void test_twentyOne()//Almost the exact same code as above, but with different function calls.
{
	double bet, money=100;
	cout << "For the purpose of this test I will assign the total user money to be $100."<<endl;
	cout << "Common user inputs:"<<endl;
	cout << "Bet=25"<<endl;
	bet=25;
	bet=twentyOne(money,25);
	cout << "You now have $"<<(money+bet)<<endl;
	cout << "Bet=47"<<endl;
	bet=47;
	bet=twentyOne(money,47);
	cout << "You now have $"<<(money+bet)<<endl;

	cout <<"Bet=69"<<endl;
	bet=69;
	bet=twentyOne(money,69);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Boundary Cases:"<<endl;
	cout << "Bet=100"<<endl;
	bet=100;
	bet=twentyOne(money,100);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Bet=1"<<endl;
	bet=1;
	bet=twentyOne(money,1);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Error Cases:"<<endl;
	cout << "Bet=-10"<<endl;
	bet=-10;
	bet=twentyOne(money,-10);

	cout <<endl<< "Bet=9999"<<endl;
	bet=9999;
	bet=twentyOne(money,9999);
	cout<<endl;
}

//Test Craps-----------------------------------------------------------------------------------------------------------------------------------------------------

void test_craps()//Also same as above, but with different function calls.
{
	double bet, money=100;
	cout << "For the purpose of this test I will assign the total user money to be $100."<<endl;
	cout << "Common user inputs:"<<endl;
	cout << "Bet=25"<<endl;
	bet=25;
	bet=craps(money,25);
	cout << "You now have $"<<(money+bet)<<endl;
	cout << "Bet=47"<<endl;
	bet=47;
	bet=craps(money,47);
	cout << "You now have $"<<(money+bet)<<endl;

	cout <<"Bet=69"<<endl;
	bet=69;
	bet=craps(money,69);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Boundary Cases:"<<endl;
	cout << "Bet=100"<<endl;
	bet=100;
	bet=craps(money,100);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Bet=1"<<endl;
	bet=1;
	bet=craps(money,1);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Error Cases:"<<endl;
	cout << "Bet=-10"<<endl;
	bet=-10;
	bet=craps(money,-10);

	cout <<endl<< "Bet=9999"<<endl;
	bet=9999;
	bet=craps(money,9999);
	cout <<endl;
}

//Test Slots-----------------------------------------------------------------------------------------------------------------------------------------------------

void test_slots()//Same but with different function calls.
{
	double bet, money=100;
	cout << "For the purpose of this test I will assign the total user money to be $100."<<endl;
	cout << "Common user inputs:"<<endl;
	cout << "Bet=25"<<endl;
	bet=25;
	bet=slots(money,25);
	cout << "You now have $"<<(money+bet)<<endl;
	cout << "Bet=47"<<endl;
	bet=47;
	bet=slots(money,47);
	cout << "You now have $"<<(money+bet)<<endl;

	cout <<"Bet=69"<<endl;
	bet=69;
	bet=slots(money,69);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Boundary Cases:"<<endl;
	cout << "Bet=100"<<endl;
	bet=100;
	bet=slots(money,100);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Bet=1"<<endl;
	bet=1;
	bet=slots(money,1);
	cout << "You now have $"<<(money+bet)<<endl;

	cout << "Error Cases:"<<endl;
	cout << "Bet=-10"<<endl;
	bet=-10;
	bet=slots(money,-10);

	cout <<endl<< "Bet=9999"<<endl;
	bet=9999;
	bet=slots(money,9999);
	cout<<endl;
}

//Test for bet checker--------------------------------------------------------------------------------------------------------------------------------------------

void test_betCheck()//NEW CODE!
{
	double money, bet;
	cout << "Common Cases:"<<endl;
	cout << "Total Money=125.98"<<endl;
	money=125.98;//Sets money to 125.98.
	bet=betCheck(money);//User can only enter a number in the range [1,125.98]
	cout <<"$"<<bet<<" is a valid bet."<<endl;
	cout << "Total Money=178.50"<<endl;
	money=178.50;//Same as above but with another number.
	bet=betCheck(money);
	cout <<"$"<<bet<<" is a valid bet."<<endl;
	cout << "Boundary Cases:"<<endl;
	cout << "Total Money=$1"<<endl;//The boundary is actually smaller than this, but Prof. Canniff said this was ok.
	money=1;
	bet=betCheck(money);
	cout <<"$"<<bet<<" is a valid bet."<<endl;
	cout << "There are no error cases for this function, since the input value of this function is randomly generated by the computer, then put through a process where the value will always be valid."<<endl;
}