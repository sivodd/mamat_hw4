
#include "Person.h"
#include <string.h>

//constructor
Person :: Person(char *PersonName, int PersonID) :
    PersonID(PersonID), PersonName(PersonName){}

//destructor
Person ::~Person(){
    delete[] PersonName; // maybe person name should be new like in workshop 9 p3
}

//operations
int Person::getID()const{
    return PersonID;
}

char* Person::getName()const{ //is this a const function?
//need to make sure that who ever calls this function will call delete.
    char *name = new char[strlen(PersonName)+1];
    strcpy(name, PersonName);
    return name;
}
