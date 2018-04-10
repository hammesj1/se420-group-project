///////////////////////////////
// SQA Project 2018 ///////////
// Cristian Garcia ////////////
// Josh Hammes ////////////////
///////////////////////////////

// Include Derectives
#include "wirelessrouter.hpp"
#include <iostream>
#include <string>

// Implementation Section:
int WirelessRouter::num_alive=0;

// Default Create and Keep Track Number of Wireless Routers
WirelessRouter::WirelessRouter()
{
   packet_size = 0;
   ieee_std = "";
   data_rate = 0.0;
   num_alive++;
   //net_ptr=NULL;
}

// Default Set Array of Wireless Routers Objects
WirelessRouter::WirelessRouter(int new_packet_size, std::string new_ieee_std, double new_data_rate)
{
   packet_size = new_packet_size;
   ieee_std = new_ieee_std;
   data_rate = new_data_rate;
   num_alive++;
}

// Destroy and Delete Track of Number of Wireless Routers
WirelessRouter::~WirelessRouter()
{
   num_alive--;
}

// Check if Wireless Router is Empty or Defined as Default
int WirelessRouter::isempty()
{
  if(packet_size == 0 && ieee_std == "" && data_rate == 0.0)
   return 1;
  else
   return 0;
}

// Receive Information from Main and Set Wireless Router Object Number of Ports
int WirelessRouter::set_packet_size(int new_packet_size)
{
   packet_size = new_packet_size;
   return 0;
}

// Receive Information from Main and Set Wireless Router Object Vendor
int WirelessRouter::set_ieee_std(std::string new_ieee_std)
{
   ieee_std = new_ieee_std;
   return 0;
}

// Receive Information from Main and Set Wireless Router Object Per Port Speed
double WirelessRouter::set_data_rate(double new_data_rate)
{
   data_rate = new_data_rate;
   return 0;
}

// Compute Pacckets Per Second for Wireless Router
double WirelessRouter::compute_packetspersec()
{
   packets_per_sec = (data_rate / (8 * packet_size));
   return 0;
}

// Set All Wireless Router Object Data to Blank or Default
int WirelessRouter::set_blank()
{
   packet_size = 0;
   ieee_std = "";
   data_rate = 0.0;
   return 0;
}

// Retrive Number of Alive Wireless Router Objects
int WirelessRouter::get_num_alive()
{
   return num_alive;
}

// Determine and Display Wireless Router Array Memory Usage
int WirelessRouter::display_mem_usage()
{
  std::cout << "Program Memory Usage: " << get_num_alive()* sizeof(WirelessRouter) << std::endl;
  return 0;
}

//Retrieve All Wireless Router Object Information
int WirelessRouter::toCout()
{
   std::cout << "Wireless Router Packet Size          : " << get_packet_size() << std::endl;
   std::cout << "Wireless Router IEEE                 : " << get_ieee_std() << std::endl;
   std::cout << "Wireless Router Data Rate            : " << get_data_rate() << std::endl;
   return 0;
}

ostream &operator<<( ostream &output, const WirelessRouter &Wr)
{
   Wr.PacketSwitch::toCout();
   output << "Wireless Router Packet Size          : " << Wr.get_packet_size() << std::endl
          << "Wireless Router IEEE                 : " << Wr.get_ieee_std() << std::endl
          << "Wireless Router Data Rate            : " << Wr.get_data_rate() << std::endl;
   return output;
};
