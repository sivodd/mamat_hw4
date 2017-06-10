#ifndef COURSE_H
#define COURSE_H
#include <stdio.h>
#include <stdlib.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class Course {
protected:
	int CourseNumber;
	char* CourseName;
	int NumOfHW;
	float HwWeight;
	int ExamGrade;
	int* Hwgardes;
public:
	//constractor
	Course(int courseNumber, char* courseName, int numOfHW, float hwWeight);
	Course(); 
	//destructor
	~Course();

	//operations
	int getNum() const;
	char* getName() const;
	int getExamGrade() const;
	int gethwGrade(int HwNum) const;
	int getHwNum() const;
	float getHwWeight() const;
	float getHwAvarge() const;
	int getCourseGrade() const;
	bool setExamGrade(int Examgrade);
	bool setHwGrade(int HwNum, int HwGrade);

};

#endif // !COURSE_H

