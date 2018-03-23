////////////..///////////...////
// CS225 Spring 2016 //////////
// Cristian Garcia ////////////
///////////////////////////////

// Include Derectives /////////
#include "network.hpp"
#include <iostream>
#include <string>

// Implementation Section: ///////////////////////////////////////////////////////////
int Network::num_alive=0;

// Default Create and Keep Track Number of Packet Switches ///////////////////////////
Network::Network()
{
   label = "";
   ip_address = "";
   num_nodes = 0;
   num_alive++;
}

// Default Set Array of Network Objects ////////////////////////////////////////
/////Network::Network(std::string new_label, std::string new_ip_address, int new_num_nodes)
/////{
/////   label = new_label;
/////   ip_address = new_ip_address;
/////   num_nodes = new_num_nodes;
   /////pps = new_pps;
   /////power = new_power;
/////   num_alive++;
/////} 

// Destroy and Delete Track of Number of Packet Switches /////////////////////////////
Network::~Network()
{
   num_alive--;
} 

// Check if Network is Empty or Defined as Default ////////////////////////////
int Network::isempty()
{
  if(label == "" && ip_address == "" && num_nodes == 0)
   return 1;
  else
   return 0;
}

// Receive Information from Main and Set Network Object Label /////////////////
int Network::set_label(std::string new_label)
{
   label = new_label;
   return 0;
}

// Receive Information from Main and Network Object IP Address //////////////////
int Network::set_ip_address(std::string new_ip_address)
{
   ip_address = new_ip_address;
   return 0;
}

// Receive Information from Main and Set Network Object Number of Nodes ////////
int Network::set_num_nodes(int new_num_nodes)
{
   num_nodes = new_num_nodes;
   return 0;
}

// Set All Network Object Data to Blank or Default /////////////////////////////
int Network::set_blank()
{
   label = "";
   ip_address = "";
   num_nodes = 0;
   return 0;
}

// Retrive Number of Alive Network Objects /////////////////////////////////////
int Network::get_num_alive()
{
   return num_alive;
}

// Determine and Display Packet Switch Array Memory Usage ////////////////////////////
/////int PacketSwitch::display_mem_usage()
/////{
/////  std::cout << "Program Memory Usage: " << get_num_alive()* sizeof(PacketSwitch) << std::endl;
/////  return 0;
/////}


// Retrieve Network Object Information /////////////////////////////////////
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