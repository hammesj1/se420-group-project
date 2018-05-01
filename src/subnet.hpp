///////////////////////////////
// SQA Project 2018 ///////////
// Cristian Garcia ////////////
// Josh Hammes ////////////////
///////////////////////////////

///////////////////////////////
#ifndef NETWORK_HPP_
#define NETWORK_HPP_

// Include Directives
#include <iostream>
#include <string>
using std::ostream;

// Decleration Section:
class Network
{
   private:
     // Data Hiding
     static int num_alive;
     std::string label;
     std::string ip_address;
     int num_nodes;

   public:
     // Constructor
     Network();
     Network(std::string, std::string, int);

     // Destructor
     ~Network();

     // Mutators
     int set_label(std::string);
     int set_ip_address(std::string);
     int set_num_nodes(int);
     int set_blank();

     // Accessors
     static int get_num_alive();
     std::string get_label()const{return label;}
     std::string get_ip_address()const{return ip_address;}
     int get_num_nodes()const{return num_nodes;}

     // Helpers
     int isempty();
     int toCout();
     friend ostream& operator<< (ostream &output, const Network& Nt);
};
#endif
