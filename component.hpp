///////////////////////////////
// CS225 Spring 2016 //////////
// Cristian Garcia ////////////
///////////////////////////////

///////////////////////////////
#ifndef PA3COMPONENT_HPP_
#define PA3COMPONENT_HPP_
// Include Directives /////////
#include <iostream>
#include <string>
using std::ostream;

// Decleration Section: //////////////////////////////////////////////////////////////
class Component
{
   private:
     // Data Hiding //////////////////////////////////////////////////////////////////
     static int num_alive;
     std::string name;
     /////std::string ip_address;
     /////int num_nodes;
     double power_rating;
     double price;
     //struct SizeInInches
     //{
     //   float height;
     //   float width;
     //   float depth;
     //} dimensions;

   public:
     // Constructor //////////////////////////////////////////////////////////////////
     Component();

     /////////////////////////////////////////////////////////////////////////////////
     Component(std::string, double, double);

     // Destructor ///////////////////////////////////////////////////////////////////
     ~Component();

     // Mutators ////////////////////////////////////////////
     int set_name(std::string);
     double set_power_rating(double);
     double set_price(double);
     int set_blank();
     
     // Accessors ///////////////////////////////////////////
     static int get_num_alive();
     std::string get_name()const{return name;}
     double get_power_rating()const{return power_rating;}
     double get_price()const{return price;}

     // Helpers //////////////////////////////////////////////////////////////////////
     int isempty()const;
     //int display_mem_usage();
     int toCout();
     
     friend ostream& operator<< (ostream &output, const Component& Cp);
};
#endif