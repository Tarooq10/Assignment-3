//  Created by Ahmed Tarek


#include "Customer.hpp"
#include "Mechanic.hpp"
#include "Queue.hpp"
#include <fstream>

int main() {
  
  ifstream in("/Users/maha/Downloads/AUC_CS2_Ass3/mechanics.txt");
    
   
  if (in.fail())
  {
    cout << "fail to open this file" << endl;
    return 0;
  }
 
  int n;
  in >> n;
  
  Mechanic *mechanics = new Mechanic[n];
  string name, id;
  int age;
  int l, hr, min;
  
  for (int i = 0; i < n; i++) {
    
    in >> name;
    mechanics[i].setName(name);
   
    in >> age;
    mechanics[i].setAge(age);
   
    in >> id;
    mechanics[i].setID(id);
   
    in >> l;
  
    for (int j = 0; j < l; j++) {
      in >> hr;
      in >> min;
      mechanics[i].addApp(hr, min);
    }
  }
 
  in.close();
  
  cout << "Available Mechanic List : " << endl;
  for (int i = 0; i < n; i++) {
    mechanics[i].printInfo();
  }
  cout << "////////////////////////" << endl;
  
  in.open("/Users/maha/Desktop/Fundamentals of Computing II/assignment3/assignment3/customers.txt");
  if (in.fail()) {
    cout << "fail to open this file" << endl;
    return 0;
  }
 
  int NC;
  in >> NC;
  
  Customer *customers = new Customer[NC];
  for (int i = 0; i < NC; i++)
  {
    in >> name;
    customers[i].setName(name);
    in >> age;
    customers[i].setAge(age);
    in >> id;
    customers[i].setID(id);
    
    in >> hr;
    in >> min;
  
    Appointment app1;
    app1.hour = hr;
    app1.min = min;
    customers[i].setAppointment(app1);
  }
  in.close();

  
  for (int i = 0; i < NC - 1; i++)
  {
    for (int j = 0; j < NC - 1; j++)
    {
      if (customers[j] > customers[j + 1])
      {
        swap(customers[j], customers[j + 1]);
      }
    }
  }

  
  Queue<Customer> qC;
  for (int i = 0; i < NC; i++)
  {
    qC.push(customers[i]);
  }

  
  Queue<Mechanic> qM;
  for (int i = 0; i < n; i++) {
    qM.push(mechanics[i]);
  }

  
  cout << "Customers After Adding Appointment : " << endl;
  while (!qC.isEmpty())
  {
  
    Customer t = qC.pop();
    
    for (int i = 0; i < qM.length(); i++) {
      Mechanic c = qM.pop();

      if (c.isAvailable(t.getAppointment())) {
        t.setMechanicID(c.getID());
        t.printInfo();
        qM.push(c);
        break;
      }

      qM.push(c);
    }
  }
    return 0;
}
