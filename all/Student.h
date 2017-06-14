
#ifndef HW4_STUDENT_H
#define HW4_STUDENT_H


#include "Person.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

// student is a sub class of person
class Student : public Person {

protected:
//	holds an array of pointers to all students courses- cs and ee apart.
	CS_Course* CS_Courses[MAX_COURSE_NUM];
	EE_Course* EE_Courses[MAX_COURSE_NUM];
//	counters that track how many courses a student is taking
	int NumOfEE_Courses;
	int NumOfCS_Courses;

public:
// *************************************************************************************
//* Function name : Student
//* Description   : constructor for Student class
//* Parameters    : personName - a string of a persons name
//                  personID - a num representing the persons ID
//* Return value  : None.
//*************************************************************************************
    Student(char *PersonName, int personID);

// *************************************************************************************
//* Function name : ~Student
//* Description   : destructor for student class, frees all dynamic memory for person.
//* Parameters    : None.
//* Return value  : None.
//*************************************************************************************
    ~Student();

    //operations
// *************************************************************************************
//* Function name : getCourseCnt
//* Description   : Returns the sum of cs and ee courses a student is taking.
//* Parameters    : None.
//* Return value  : Number of all courses in both faculties.
//*************************************************************************************
    int getCourseCnt()const;

// *************************************************************************************
//* Function name : addEE_Course
//* Description   : Given a pointer to a course adds it to the student.
//* Parameters    : ee_course - a pointer to a EE course.
//* Return value  : true / false.
//*************************************************************************************
    bool addEE_Course(EE_Course* ee_course);

// *************************************************************************************
//* Function name : addCS_Course
//* Description   : Given a pointer to a course adds it to the student.
//* Parameters    : cs_course- a pointer to a CS course.
//* Return value  : true / false.
//*************************************************************************************
    bool addCS_Course(CS_Course* cs_course);

// *************************************************************************************
//* Function name : remCourse
//* Description   : Given a course number removes the course, frees it's memory.
//* Parameters    : CourseNum - a number to a course.
//* Return value  : true / false.
//*************************************************************************************
    bool remCourse(int CourseNum);

// *************************************************************************************
//* Function name : getEE_Course
//* Description   : Returns a pointer to a course given it's number.
//* Parameters    : ee_courseNum - a number of an EE course.
//* Return value  : EE_Course* - a pointer to a EE course if found.
//*************************************************************************************
    EE_Course* getEE_Course(int ee_courseNum)const;

// *************************************************************************************
//* Function name : getCS_Course
//* Description   : Returns a pointer to a course given it's number.
//* Parameters    : ee_courseNum - a number of a CS course.
//* Return value  : CS_Course* - a pointer to a CS course if found.
//*************************************************************************************
    CS_Course* getCS_Course(int cs_courseNum)const;

// *************************************************************************************
//* Function name : getAvg
//* Description   : Returns the average of a student.
//* Parameters    : None.
//* Return value  : A Rounded average of the student
//*************************************************************************************
    int getAvg()const;

// *************************************************************************************
//* Function name : print
//* Description   : Prints out the students details and all his courses details.
//* Parameters    : None.
//* Return value  : None.
//*************************************************************************************
    void print()const;

};

#endif //HW4_STUDENT_H
