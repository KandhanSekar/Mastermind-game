// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int crt[] = { 0, 1, 2, 3 };
vector<int>mag1;

int imp[3];
void getinput()
{
	for (int i = 0; i < 4; i++)
	{
		int j;
		cin >> j;
		imp[i] = j;
	}
}

void displayinp()
{
	for (int i = 0; i < 4; i++)
	{
		cout << imp[i] << "\n";
	}
}

int dispar[3];

bool search(int b)
{
	vector<int>::iterator a = mag1.begin();
	
		while (a != mag1.end())
		{
			if ((*a) == b)
			{
				cout << "it is found\n";
				cout << b;
				return true;
				break;
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
	for (int i = 0; i < 4; i++)
	{
		if (dispar[i] != 1)
		{
			if (search(imp[i]) == true)
			{
				dispar[i] == 2;
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
		nextcon();
	}
}

void displayans()
{
	for (int i = 0; i < 4; i++)
	{
		cout << dispar[i] << "\n";
	}
}
int main()
{
	cout<<"MASTERIND GAME";
	int noofrounds;
	cout << "enter the number of rounds";
	cin >> noofrounds;
	cout << "\n Enter your guess";
	getinput();
	displayinp();
	check();
	displayans();
    return 0;
}
