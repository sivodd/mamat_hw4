//
// Created by sivan on 07/06/2017.
//

#ifndef HW4_CS_COURSE_H
#define HW4_CS_COURSE_H

#include "Course.h"

class CS_Course : public Course {
protected:
    int Factor=0;

public:
    //constractor
    CS_Course();
    //destructor
    ~CS_Course();

    //operations
    int getFactor()const;
    bool setFactor(int Factor);

};

#endif //HW4_CS_COURSE_H
