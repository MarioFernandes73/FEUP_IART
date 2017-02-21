/*
 * Menu.cpp
 *
 *  Created on: 21 Feb 2017
 *      Author: Mário
 */

#define TAB		"	"
#define TAB_BIG	"		"

#include <iostream>

#include "Menu.h"
#include "Auxiliary.h"

using namespace std;

unsigned short int initialMenu()
{
	short int option=-1;
	cout << TAB_BIG << "Initial Menu";
	cout << endl << endl;
	cout << TAB << "Choose your option";
	cout << endl << endl;
	cout << TAB << "1 - Menu of Students" << endl;
	cout << TAB << "0 - Save & Exit" << endl;
	cout << endl;
	cout << "Please write your option here: ";

	while(true)
	{
		option = readUnsignedShortInt(0,1);
		if(option == 0)
			break;
		else if(option > 0)
			return option;
		else
			cout << "Error, please choose your option: " << endl;
	}
	return 0;
}

void initialOptions(University & university)
{
	unsigned short int option;

	while((option=initialMenu()))
	switch (option)
	{
	case 1:cout << "lol" << endl;
	break;
	}
}
