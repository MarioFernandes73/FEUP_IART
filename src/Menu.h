/*
 * Menu.h
 *
 *  Created on: 21 Feb 2017
 *
 */

#ifndef MENU_H_
#define MENU_H_

#include "University.h"

void initialOptions(University & university);
short int initialMenu();

void studentsOptions(University & universtiy);
short int studentsMenu();

void examsOptions(University & universtiy);
short int examsMenu();


#endif /* MENU_H_ */
