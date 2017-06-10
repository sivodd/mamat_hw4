
#ifndef HW4_EE_COURSE_H
#define HW4_EE_COURSE_H
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Course.h"

class EE_Course : public Course {
protected:
	int Factor;

public:
    //constractor
    EE_Course(int CourseNumber, char* CourseName, int NumOfHW, float HwWeight);
    //destructor
    ~EE_Course();

    //operations
    int getFactor() const;
    bool setFactor(int factor);
	int getCourseGrade() const;
};

#endif //HW4_EE_COURSE_H
