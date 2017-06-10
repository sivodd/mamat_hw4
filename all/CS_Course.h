//
// Created by sivan on 07/06/2017.
//

#ifndef HW4_CS_COURSE_H
#define HW4_CS_COURSE_H
#include <stdlib.h>
#include "Course.h"

class CS_Course : public Course {
protected:
	bool IsTakef;
	char* Book;
public:
    //constractor
    CS_Course(char* book,bool isTakef, int CourseNumber, char* CourseName, int NumOfHW, float HwWeight);
    //destructor
    ~CS_Course();

    //operations
	bool isTakef() const;
	char* getBook() const;
	bool setTakef(bool binary);
	void setBook(char* name);
	int getCourseGrade() const;
};

#endif //HW4_CS_COURSE_H
