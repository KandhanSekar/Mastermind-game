// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
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
int main()
{
	cout<<"MASTERIND GAME";
	int noofrounds;
	cout << "enter the number of rounds";
	cin >> noofrounds;
	cout << "\n Enter your guess";
	getinput();
	displayinp();
    return 0;
}
