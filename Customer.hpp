//  Created by Adham Ali on 19/03/2023.

#ifndef Customer_hpp
#define Customer_hpp
#include "Person.hpp"


class Customer : public Person {
private:
  string mechanicID;
  Appointment appointment;

public:
  Customer();

  string getMechanicID();
  Appointment getAppointment();

  void setMechanicID(string n);
  void setAppointment(Appointment app);

 
  bool operator==(Customer &c);
  bool operator>(Customer &c);
  bool operator<(Customer &c);

 
  void printInfo();
};


#endif 
