/*
 * University.cpp
 *
 *  Created on: 21 Feb 2017
 *      Author: M�rio
 */

#include "University.h"

#include <vector>
using namespace std;

vector<Student *> University::getStudents()
{
	return this->students;
}

