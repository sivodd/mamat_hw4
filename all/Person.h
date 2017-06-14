
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
// *************************************************************************************
//* Function name : Person
//* Description   : constructor for person class
//* Parameters    : personName - a string of a persons name
//                  personID - a num representing the persons ID
//* Return value  : None.
//*************************************************************************************
    Person(char* personName, int personID);

// *************************************************************************************
//* Function name : ~Person
//* Description   : destructor for person class, frees all dynamic memory for person.
//* Parameters    : None.
//* Return value  : None.
//*************************************************************************************
    ~Person();

    //operations
//*************************************************************************************
//* Function name : getID
//* Description   : Fetches a persons ID for a user outside the class
//* Parameters    : None.
//* Return value  : ID number.
//*************************************************************************************
    int getID()const;

//*************************************************************************************
//* Function name : getName
//* Description   : Gets a persons name for a user outside the class
//* Parameters    : None.
//* Return value  : A persons name.
//*************************************************************************************
    char* getName()const;

};

#endif //HW4_PERSON_H
