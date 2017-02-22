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
#include "MyExceptions.h"
#include "Interaction.h"

using namespace std;

short int initialMenu()
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
		if(option <0)
			cout << "Error, please choose your option: ";
		else
			break;
	}



	return option;
}

void initialOptions(University & university)
{
	unsigned short int option;

	while((option=initialMenu()))
	switch (option)
	{
	case 1:studentsOptions(university);
	break;
	}
}



short int studentsMenu()
{
	short int option=-1;
	cout << TAB_BIG << "Initial Menu";
	cout << endl << endl;
	cout << TAB << "Choose your option";
	cout << endl << endl;
	cout << TAB << "1 - Create new student" << endl;
	cout << TAB << "2 - Edit existing student" << endl;
	cout << TAB << "3 - Delete student" << endl;
	cout << TAB << "4 - View students" << endl;
	cout << TAB << "0 - Return to initial menu" << endl;
	cout << endl;
	cout << "Please write your option here: ";

	while(true)
	{
		option = readUnsignedShortInt(0,4);
		if(option < 0)
			cout << "Error, please choose your option: ";
		else
			break;
	}


	return option;
}

void studentsOptions(University & university)
{
	unsigned short int option;

	while((option=studentsMenu()))
		try{
	switch (option)
	{
	case 1:
		university.addStudent(createStudent());
		break;
	case 2:
		editStudent(university.findStudent(createStudent()));
		break;
	case 3:
		university.removeStudent(createStudent());
		break;
	case 4:
		printStudents(university.getStudents());
		break;
	}
		}
	catch(elementNotInVectorException<Student *> &e)
	{
		cout << "Error! " << e.getElement()->getName() << " not found!" << endl;
	}
}

