///////////////////////////////
// CS225 Spring 2016 //////////
// Cristian Garcia ////////////
///////////////////////////////

// Include Derectives /////////
#include "component.hpp"
#include <iostream>
#include <string>

// Implementation Section: ///////////////////////////////////////////////////////////
int Component::num_alive=0;

// Default Create and Keep Track Number of Componentss ///////////////////////////
Component::Component()
{
   name = "";
   power_rating = 0.0;
   price = 0.0;
   num_alive++;
}

// Default Set Array of Network Objects ////////////////////////////////////////
Component::Component(std::string new_name, double new_power_rating, double new_price)
{
   name = new_name;
   power_rating = new_power_rating;
   price = new_price;
   num_alive++;
} 

// Destroy and Delete Track of Number of Packet Switches /////////////////////////////
Component::~Component()
{
   num_alive--;
} 

// Check if Network is Empty or Defined as Default ////////////////////////////
int Component::isempty()const
{
  if(name == "" && power_rating == 0.0 && price == 0.0)
   return 1;
  else
   return 0;
}

// Receive Information from Main and Set Network Object Label /////////////////
int Component::set_name(std::string new_name)
{
   name = new_name;
   return 0;
}


// Receive Information from Main and Set Packet Switch Object Per Port Speed /////////
double Component::set_power_rating(double new_power_rating)
{
power_rating = new_power_rating;
return 0;
}

// Receive Information from Main and Set Packet Switch Object Power //////////////////
double Component::set_price(double new_price)
{
price = new_price;
return 0;
}

// Set All Network Object Data to Blank or Default /////////////////////////////
int Component::set_blank()
{
   name = "";
   power_rating = 0.0;
   price = 0.0;
   return 0;
}

// Retrive Number of Alive Network Objects /////////////////////////////////////
int Component::get_num_alive()
{
   return num_alive;
}

// Retrieve Network Object Information /////////////////////////////////////
int Component::toCout()
{
   std::cout << "Component Details" << std::endl;
   std::cout << "Component #" << "\t" << "Name" << "\t\t" << "Power(watts)" << "\t\t" <<  "Price($)" << std::endl;
   std::cout << "Number" << "\t\t" << get_name() << "\t\t" << get_power_rating() << "\t\t\t"  << get_price() << std::endl;
   return 0;
}

ostream &operator<<( ostream &output, const Component &Cp)
{
   //if(Cp.get_name() == "" && Cp.get_power_rating() == 0.0 && Cp.get_price() == 0.0);
     //output <<"No Components Defined" << std::endl;
   //else
   //{  
   output    << "Component Details" << std::endl
             << "Component #" << "\t" << "Name" << "\t\t" << "Power(watts)" << "\t\t" <<  "Price($)" << std::endl
             << "Number" << "\t\t" << Cp.get_name() << "\t\t" << Cp.get_power_rating() << "\t\t\t"  << Cp.get_price() << std::endl;
   //}
   return output;
   
};