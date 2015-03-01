//Chris Geraldpaulraj
//Card Game in c++

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stack>
#include <sstream>
#include <ctime>

using namespace std;

string translater(float cardnumber) //takes in card number and returns the name of card
{

	if (cardnumber > 52)
	{
		return " a penalty card";
	}

	int num = ceil(cardnumber / 4);
	string number;

	switch (num)
	{
	case 11:
		number = "Jack";
		break;
	case 12:
		number = "Queen";
		break;
	case 13:
		number = "King";
		break;
	case 1:
		number = "Ace";
		break;
	default:
		ostringstream stri;
		stri << num;
		number = stri.str();

	}

	int numbers = cardnumber;
	int suitnumber = numbers % 4;
	string suit;
	if (suitnumber == 1)
		suit = "Clubs";
	else if (suitnumber == 2)
		suit = "Diamonds";
	else if (suitnumber == 3)
		suit = "Hearts";
	else if (suitnumber == 0)
		suit = "Spades";


	ostringstream oss;
	oss << " " << number << " of " << suit << " ";
	return oss.str();

}


int main()
{
	float players; //number of players
	cout << "Welcome to the Job Card Game!" << endl;
	cout << "---------------------------------------\n";
	cout << "Rules: The game allows up to 4 players. 56 cards in a deck with 4 penalty cards\n" << endl;
	cout << "The deck is shuffled every round and each card is ranked based on face value and secondly their suit. Penalty cards are not ranked\n" << endl;
	cout << "At the end of each round the player with the highest rank card is the winner and their score is increased by 2. Players with penalty cards have their scores decreased by 2.\n" << endl;
	//The 2nd to 10th cards are the number cards, the next 3 are king queen and jack. The first card is the ace. These are the cards per suite in a unshuffled deck. The 53-56 cards are penalty cards.
	//Card number one would be ace of clubs. number 14 is ace of diamonds. Number 27 is ace of hearts. Number 40 is ace of diamonds.  In this implementation, ace is lowest rank.
	float array_cards[56]; //Array has deck of cards.
	float temp_deck[56];
	int j;
	for (j = 0; j < 56; j++)
	{
		temp_deck[j] = -1;
	}
	for (int i = 0; i < 56; i++)  //this loop places the cards into the main array or deck
	{
		array_cards[i] = i + 1;
	}

	cout << "Please enter the number of players for this game: \n";
	cin >> players;
	while (players < 2 || players > 4)
	{
		cout << "You need more than 1 player to play the game\n";
		cout << "pick more than 1 person but less than 5 people.\n";
		cout << "Please enter the number of players for this game: \n";
		cin >> players;
		if (players >= 2 && players <= 4)
			break;
	}
	srand(time(NULL));
	for (int i = 0; i < 56; i++)   //shuffle deck
	{
		while (-1)
		{
			j = rand() % 56;
			if (temp_deck[j] == -1)
			{
				temp_deck[j] = array_cards[i];
				break;
			}
		}
	}

	stack <float> main_deck;            //Using a stack so we can push our array of cards into the stack
	for (int i = 0; i < 56; i++)
	{
		main_deck.push(temp_deck[i]);
	}


	//Deck is shuffled
	int scores[4];
	int pickedcards[4];
	while (-1)  //infinite while loop
	{

		cout << endl;
		for (int i = 0; i < players; i++)
		{

			//round 1 starts and first person picks card
			cout << "Player" << i + 1 << "'s card is " << translater(main_deck.top()) << endl;
			pickedcards[i] = main_deck.top();
			if (pickedcards[i] > 52)
			{
				scores[i] = scores[i] - 1;
				pickedcards[i] = 0;
			}
			if (scores[i] < 0)
			{
				scores[i] = 0;
			}
			main_deck.pop();  //each card is seen and then popped/discarded.

		}
		float max = 0;
		for (int i = 0; i < players; i++)
		{
			if (pickedcards[i] > max)
				max = pickedcards[i];
		}
		if (max == 0)
		{
			cout << "No winners this round :(" << endl;
		}
		else if (max == pickedcards[0])
		{
			cout << "Round winner is" << " Player " << 1 << endl;
			scores[0] = scores[0] + 2;
			cout << "score table: " << endl;
			cout << " p1   p2   p3   p4" << endl;
			cout << "----|----|----|----" << endl;
			for (int i = 0; i < players; i++)
			{
				cout << " " << scores[i] << "   ";
			}
			cout << endl;
			if (scores[0] >= 21)
			{
				cout << endl;
				cout << "Winner is player 1!" << endl;
				break;
			}
		}
		else if (max == pickedcards[1])
		{
			cout << "Round winner is" << " Player " << 2 << endl;
			scores[1] = scores[1] + 2;
			cout << "score table: " << endl;
			cout << " p1   p2   p3   p4" << endl;
			cout << "----|----|----|----" << endl;
			for (int i = 0; i < players; i++)
			{
				cout << " " << scores[i] << "   ";
			}
			cout << endl;
			if (scores[1] >= 21)
			{
				cout << endl;
				cout << "Winner is player 2!" << endl;
				break;
			}
		}
		else if (max == pickedcards[2])
		{
			cout << "Round winner is" << " Player " << 3 << endl;
			scores[2] = scores[2] + 2;
			cout << "score table: " << endl;
			cout << " p1   p2   p3   p4" << endl;
			cout << "----|----|----|---" << endl;
			for (int i = 0; i < players; i++)
			{
				cout << " " << scores[i] << "   ";
			}
			cout << endl;
			if (scores[2] >= 21)
			{
				cout << endl;
				cout << "Winner is player 3!" << endl;
				break;
			}
		}
		else if (max == pickedcards[3])
		{
			cout << "Round winner is" << " Player " << 4 << endl;
			scores[3] = scores[3] + 2;
			cout << "score table: " << endl;
			cout << " p1   p2   p3   p4" << endl;
			cout << "----|----|----|---" << endl;
			for (int i = 0; i < players; i++)
			{
				cout << " " << scores[i] << "   ";
			}
			cout << endl;
			if ((scores[3] >= 21))
			{
				cout << endl;
				cout << "Winner is player 4!" << endl;
				break;
			}
		}

	}
	int x;
	cin >> x;
}
