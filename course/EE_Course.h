
#ifndef HW4_EE_COURSE_H
#define HW4_EE_COURSE_H

#include "Course.h"

class EE_Course : public Course {
protected:
    int Factor=0;

public:
    //constractor
    EE_Course();
    //destructor
    ~EE_Course();

    //operations
    int getFactor()const;
    bool setFactor(int Factor);

};

#endif //HW4_EE_COURSE_H
