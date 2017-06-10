
#include "Person.h"
#include <string.h>

//constructor
Person::Person(char *personName, int personID) :
	PersonID(personID), PersonName(personName)
{
	PersonName = new char[strlen(personName) + 1];
	strcpy(PersonName, personName);
}

//destructor
Person ::~Person(){
    delete[] PersonName;
}

//operations
int Person::getID()const{
    return PersonID;
}

char* Person::getName()const{ 
    char *name = new char[strlen(PersonName)+1];
    strcpy(name, PersonName);
    return name;
}
