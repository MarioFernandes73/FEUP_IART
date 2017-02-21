/*
 * Auxiliary.cpp
 *
 *  Created on: 21 Feb 2017
 *      Author: Mário
 */

#include <string>
#include <sstream>
#include <iostream>

#include "Auxiliary.h"

using namespace std;

short int readUnsignedShortInt(unsigned short int first, unsigned short int last)
{
	unsigned short int input;
	string temp;
	stringstream ss;

	getline(cin, temp);

	if(temp=="")
	{
		return 0;
	}

	for(unsigned int i=0; i<temp.size(); i++)
	{
		if(!isdigit(temp[i]))
		{
			return 0;
		}
	}

	ss << temp;
	ss >> input;

	return input;

}

