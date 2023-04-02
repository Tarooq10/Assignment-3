//  Created by Ahmed Tarek.

#include "Customer.hpp"


Customer::Customer() : Person()
{
  mechanicID = "";
  appointment.hour = 0;
  appointment.min = 0;
}

//getters
string Customer::getMechanicID()
{
    return mechanicID;
    
}
Appointment Customer::getAppointment()
{
    return appointment;
    
}

//setters
void Customer::setMechanicID(string n)
{
    mechanicID = n;
    
}
void Customer::setAppointment(Appointment app)
{
    appointment = app;
    
}

//overloading operators
bool Customer::operator==(Customer &c)
{
  if (appointment.hour == c.appointment.hour &&
      appointment.min == c.appointment.min)
    return true;
  else
    return false;
}

bool Customer::operator>(Customer &c)
{
  if (appointment.hour > c.appointment.hour)
    return true;
  else if (appointment.hour < c.appointment.hour)
    return false;
  else {
    if (appointment.min > c.appointment.min)
      return true;
    else
      return false;
  }
}

bool Customer::operator<(Customer &c)
{
  if (appointment.hour < c.appointment.hour)
    return true;
  else if (appointment.hour > c.appointment.hour)
    return false;
  else {
    if (appointment.min < c.appointment.min)
      return true;
    else
      return false;
  }
}


void Customer::printInfo()
{
   
  Person::printInfo();

  cout << "Mechanic ID : " << mechanicID << " @ " << appointment.hour << ":" << appointment.min<<endl<<endl;
}
