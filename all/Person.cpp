
#include "Person.h"
#include <string.h>

// *************************************************************************************
//* Function name : Person
//* Description   : constructor for person class
//* Parameters    : personName - a string of a persons name
//                  personID - a num representing the persons ID
//* Return value  : None.
//*************************************************************************************
Person::Person(char *personName, int personID) :
	PersonID(personID), PersonName(personName)
{
    //  create a copy of a given name and a memory allocation
	PersonName = new char[strlen(personName) + 1];
	strcpy(PersonName, personName);
}

// *************************************************************************************
//* Function name : ~Person
//* Description   : destructor for person class, frees all dynamic memory for person.
//* Parameters    : None.
//* Return value  : None.
//*************************************************************************************
Person ::~Person(){
    delete[] PersonName;
}

//operations
//*************************************************************************************
//* Function name : getID
//* Description   : Fetches a persons ID for a user outside the class
//* Parameters    : None.
//* Return value  : ID number.
//*************************************************************************************
int Person::getID()const{
    return PersonID;
}

//*************************************************************************************
//* Function name : getName
//* Description   : Gets a persons name for a user outside the class
//* Parameters    : None.
//* Return value  : A persons name.
//*************************************************************************************
char* Person::getName()const{ 
    char *name = new char[strlen(PersonName)+1];
    strcpy(name, PersonName);
    return name;
}
