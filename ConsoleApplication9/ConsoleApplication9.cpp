// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
void displayans();
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
	cout << "\n CHECKING NEXT CON\n";
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
	cout << "\nENTERED CHECK FN\n";
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
}
int main()
{
	cout<<"MASTERIND GAME";
	//displayans();										//REMOVE
	int noofrounds;										//no of rounds plaed(NOt used so far)
	cout << "enter the number of rounds";
	cin >> noofrounds;
	//displayans();										//REMOVE
	cout << "\n Enter your guess";
	while (noofrounds != 0)
	{
		getinput();											// get the input four number guesses
		//displayans();										//REMOVE
		displayinp();										// display what we have got
		//displayans();										//REMOVE
		check();											// checking condns
		displayans();										// display feedback thing
		noofrounds--;
		refresh();
	}
    return 0;
}
