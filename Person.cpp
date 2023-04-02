//  Created by Ahmed Tarek.

#include "Person.hpp"


Person::Person()
{
  name = "";
  id = "";
  age = 0;
}
//setters
void Person::setName(string n)
{
    name = n;
    
}
void Person::setID(string s)
{
    id = s;
    
}
void Person::setAge(int a)
{
    age = a;
    
}

//getters
string Person::getName()
{
    return name;
    
}
string Person::getID()
{
    return id;
    
}
int Person::getAge()
{
    return age;
    
}

//print function
void Person::printInfo()
{
  cout << "Name : " << name << endl;
  cout << "ID   : " << id << endl;
  cout << "Age  : " << age << endl;
}
