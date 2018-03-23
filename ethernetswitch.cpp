///////////////////////////////
// CS225 Spring 2016 //////////
// Cristian Garcia ////////////
///////////////////////////////

// Include Derectives /////////
#include "ethernetswitch.hpp"
#include <iostream>
#include <string>

// Implementation Section: ///////////////////////////////////////////////////////////
int EthernetSwitch::num_alive=0;

// Default Create and Keep Track Number of Packet Switches ///////////////////////////
EthernetSwitch::EthernetSwitch()
{
   PacketSwitch();
   packet_size = 0;
   rating = 0;
   num_alive++;
}

// Default Set Array of Packet Switch Objects ////////////////////////////////////////
EthernetSwitch::EthernetSwitch(int new_packet_size, int new_rating)
{
   packet_size = new_packet_size;
   rating = new_rating;
   num_alive++;
} 

// Destroy and Delete Track of Number of Packet Switches /////////////////////////////
EthernetSwitch::~EthernetSwitch()
{
   num_alive--;
} 

// Check if Packet Sewitch is Empty or Defined as Default ////////////////////////////
int EthernetSwitch::isempty()
{
  if(packet_size == 0 && rating == 0)
   return 1;
  else
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Number of Ports ////////
int EthernetSwitch::set_packet_size(int new_packet_size)
{
   packet_size = new_packet_size;
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Number of Ports ////////
int EthernetSwitch::set_rating(int new_rating)
{
   rating = new_rating;
   return 0;
}

double EthernetSwitch::compute_packetspersec()///double pps, int num_ports, int packet_size) //////////////////     look!!!!!
{
   packets_per_sec = ((pps * num_ports) / (8 * packet_size));
   return 0;
}

// Set All Packet Switch Object Data to Blank or Default /////////////////////////////
int EthernetSwitch::set_blank()
{
   packet_size = 0;
   rating = 0;
   return 0;
}

// Retrive Number of Alive Packet Switch Objects /////////////////////////////////////
int EthernetSwitch::get_num_alive()
{
   return num_alive;
}

// Determine and Display Packet Switch Array Memory Usage ////////////////////////////
int EthernetSwitch::display_mem_usage()
{
  std::cout << "Program Memory Usage: " << get_num_alive()* sizeof(EthernetSwitch) << std::endl;
  return 0;
}

//Retrieve All Packet Switch Object Information /////////////////////////////////////
int EthernetSwitch::toCout() const
{
   std::cout << "Ethernet Switch Packet Size             : " << get_packet_size() << std::endl;
   std::cout << "Ethernet Switch Rating                  : " << get_rating() << std::endl;
   return 0;
}

///Component* PacketSwitch::get_component(int index){return &loc_component_array[index];}

ostream &operator<<( ostream &output, const EthernetSwitch &Es)
{
          Es.PacketSwitch::toCout();



   output << "Ethernet Switch Packet Size                : " << Es.get_packet_size() << std::endl
          << "Ethernet Switch Rating                     : " << Es.get_rating() << std::endl;
  
          ////if(Es.net_ptr != NULL)
          ////{ 
          ////  output << *(Es.net_ptr);
          ////}
          ////else 
          ////{
          ////  output<<"Is not Network"<< std::endl;
          ////}
          ////for(int i = 0; i < 20 ; i++)
          ////{
          ////  if(Es.loc_component_array[i].isempty()){}
          ////  else
          ////  output << Es.loc_component_array[i] << std::endl;
          ////}
          
   return output;
};