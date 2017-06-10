
#ifndef HW4_PERSON_H
#define HW4_PERSON_H

#include "Proj.h"
#include "Course.h"
#include "CS_Course.h"
#include "EE_Course.h"

class Person {
protected:
    int PersonID;
    char* PersonName;

public:
    //constructor
    Person(char* personName, int personID);

    //destructor
    ~Person();

    //operations
    int getID()const;
    char* getName()const; //need to read more about the use of const.

};

#endif //HW4_PERSON_H
