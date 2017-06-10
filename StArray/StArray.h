#ifndef STARRAY_H
#define STARRAY_H
#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Student.h"
#include  "Proj.h"

class StArray {
protected:
	Student* students [MAX_STUDENT_NUM];// = { NULL };
	int NumOfStudents;
public:
	//constractor
	StArray();
	//destructor
	~StArray();
	
	//operations
	bool addStudent(int student_id, char* student_name);
	bool addEE_Course(int student_id, int course_num, char* course_name, int NumOfHw, float hwWeight);
	bool addCS_Course(int student_id, int course_num, char* course_name, int NumOfHw, float hwWeight,bool takef ,char* book);
	bool setHwGrade(int student_id, int course_num, int Hw_num, int hw_grade);
	bool setExamGrade(int student_id, int course_num, int examGrade);
	bool setFactor(int course_num, int Factor);
	bool printStudent(int student_id);
	void printAll();
	void resetStArray();
};

#endif // !STARRAY_H

