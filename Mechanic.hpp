//  Created by Ahmed Tarek.

#ifndef Mechanic_hpp
#define Mechanic_hpp
#include "Person.hpp"



class Mechanic : public Person {
private:
  int counter;
  Appointment *apps;

public:
  Mechanic();

  void setCounter(int c);
  void setApps(Appointment *a);

  int getCounter();
  Appointment *getApps();

  bool isAvailable(Appointment ap);
  void addApp(int h, int m);

  void printInfo();
};


#endif 
