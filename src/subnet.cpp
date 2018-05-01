///////////////////////////////
// SQA Project 2018 ///////////
// Cristian Garcia ////////////
// Josh Hammes ////////////////
///////////////////////////////

// Include Derectives
#include "network.hpp"
#include <iostream>
#include <string>
// Implementation Section

// Default Create and Keep Track Number of Networks
int Network::num_alive=0;
Network::Network()
{
   label = "";
   ip_address = "";
   num_nodes = 0;
   num_alive++;
}

// Destroy and Delete Track of Number of Networks
Network::~Network()
{
   num_alive--;
}

// Check if Network is Empty or Defined as Default
int Network::isempty()
{
  if(label == "" && ip_address == "" && num_nodes == 0)
   return 1;
  else
   return 0;
}

// Receive Information from Main App and Set Network Object Label
int Network::set_label(std::string new_label)
{
   label = new_label;
   return 0;
}

// Receive Information from Main App and Set Network Object IP Address
int Network::set_ip_address(std::string new_ip_address)
{
   ip_address = new_ip_address;
   return 0;
}

// Receive Information from Main App and Set Network Object Number of Nodes
int Network::set_num_nodes(int new_num_nodes)
{
   num_nodes = new_num_nodes;
   return 0;
}

// Set All Network Object Data to Blank or Default
int Network::set_blank()
{
   label = "";
   ip_address = "";
   num_nodes = 0;
   return 0;
}

// Retrive Number of Alive Network Objects
int Network::get_num_alive()
{
   return num_alive;
}

// Retrieve Network Object or Ojects Information
int Network::toCout()
{
   std::cout << "Connected Network Details" << std::endl;
   std::cout << "-------------------------" << std::endl;
   std::cout << "Network Label                        : " << get_label() << std::endl;
   std::cout << "Network IP Address                   : " << get_ip_address() << std::endl;
   std::cout << "Number of Network Nodes              : " << get_num_nodes() << " nodes"  << std::endl;
   return 0;
}

ostream &operator<<( ostream &output, const Network &Nt)
{
   output << "Connected Network Details" << std::endl
          << "-------------------------" << std::endl
          << "Network Label                        : " << Nt.get_label() << std::endl
          << "Network IP Address                   : " << Nt.get_ip_address() << std::endl
          << "Number of Network Nodes              : " << Nt.get_num_nodes() << " nodes"  << std::endl;
   return output;
};
