/*
 * Interaction.h
 *
 *  Created on: 21 Feb 2017
 *      Author: Mário
 */

#ifndef INTERACTION_H_
#define INTERACTION_H_

#include <vector>

#include "University.h"

Student * createStudent();

void editStudent(Student * student);

bool confirmDeleteStudent(Student * student);

void printStudents(std::vector<Student *> students);


#endif /* INTERACTION_H_ */
