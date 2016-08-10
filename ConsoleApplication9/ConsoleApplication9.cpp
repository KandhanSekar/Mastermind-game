// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
void displayans();
int noofrounds;										//no of rounds plaed(NOt used so far)
int dispar[] = { 0,0,0,0 };
int crt[] = { 0, 1, 2, 3 };
vector<int>mag1;

int imp[] = { 0,0,0,0 };
void getinput()
{
	for (int i = 0; i < 4; i++)
	{
		//int j;
		cin >> imp[i];
		//imp[i] = j;
	}
}

void displayinp()
{
	cout << "\n THE GUESS IS \n";
	for (int i = 0; i < 4; i++)
	{
		cout << imp[i] << "\n";
	}
}



bool search(int b)
{
	vector<int>::iterator a = mag1.begin();
	
		while (a != mag1.end())
		{
			if ((*a) == b)
			{
				//cout << "it is found\n";
				//cout << b;
				return true;
				//break;
			}
			else
			{
				++a;

			}
		}
		return false;
}

void nextcon()
{
	//cout << "\n CHECKING NEXT CON\n";
	for (int i = 0; i < 4; i++)
	{
		//cout << "enter loop 1\n";
		if (dispar[i] != 1)
		{
			if (search(imp[i]) == true)
			{
				//cout << "condi is tru\n"<<imp[i];
				//cout << "aiiiiiii "<< i;
				dispar[i] = 2;
				//cout << "THISSSS";
				//displayans();
				//cout << "THISSS";
			}
			else
			{
				dispar[i] == 3;
			}
		}
	}
}
void check()
{
	//cout << "\nENTERED CHECK FN\n";
	for (int i = 0; i < 4; i++)
	{
		if (imp[i] == crt[i])
		{
			dispar[i] = 1;
			
		}
		else
		{
			mag1.push_back(crt[i]);
		}
		
	}
	nextcon();
	
}

void displayans()
{
	cout << "\n" << "DISPLAYING ANSWERS\n";
	for (int i = 0; i < 4; i++)
	{
		cout << dispar[i] << "\n";
	}
}
void refresh()
{
	for (int i = 0; i < 4; i++)
	{
		dispar[i] = 0;
	}
	cout << "\n you have " << noofrounds<<" Guessed left\n";

}

void winner()
{
	if (dispar[0] == 1 && dispar[1] == 1 && dispar[2] == 1 && dispar[3] == 1)
	{
		cout << "\n CORRECT GUESS \n CONGRATS YOU WON with " << noofrounds << " guesses left \n";
		exit(0);
	}
	
}
int main()
{
	cout<<"MASTERIND GAME\n";//rules
	cout << "\n Here are the rules of the Game !!";
	cout << "Choose your option\n 1. Pre defined sequence \n 2. Random sequence \n 3. 2 player\n";
	int p;
	cin >> p;
	switch (p)
	{
	case 1:
	{//
		break;
	}
	case 2:
	{
		for (int i = 0; i < 4; i++)
		{
			int v2;
			v2 = rand() % 5 + 1;
			//cout << v2;
			crt[i] = v2;
		}
		break;
	}
	case 3:
	{
		cout << "\n Enter the  play sequence";
		for (int i = 0; i < 4; i++)
		{
			cin >> crt[i];
		}
		for (int i = 0; i < 99; i++)
		{
			cout << "\n";
		}

		break;
	}
	}
	
	
	cout << "enter the number of rounds";
	cin >> noofrounds;
	
	while (noofrounds != 0)
	{
		cout << "\n Enter your guess";
		getinput();											// get the input four number guesses
		
		//displayinp();		////								// display what we have got
		
		check();											// checking condns
		displayans();										// display feedback thing
		noofrounds--;
		winner();
		refresh();
	}
    return 0;
}
