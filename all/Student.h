
#ifndef HW4_STUDENT_H
#define HW4_STUDENT_H


#include "Person.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Student : public Person {

protected:
	CS_Course* CS_Courses[MAX_COURSE_NUM];
	EE_Course* EE_Courses[MAX_COURSE_NUM];
	int NumOfEE_Courses;
	int NumOfCS_Courses;

public:
    //constructor
    Student(char *PersonName, int personID);

    //destructor
    ~Student(); //there is a warning here i don't understand "destructor hides a non virtual function from class person"?

    //operations
    int getCourseCnt()const;
    bool addEE_Course(EE_Course* ee_course);
    bool addCS_Course(CS_Course* cs_course);
    bool remCourse(int CourseNum);
    EE_Course* getEE_Course(int ee_courseNum)const;
    CS_Course* getCS_Course(int cs_courseNum)const;
    int getAvg()const;
    void print()const;

};

#endif //HW4_STUDENT_H
