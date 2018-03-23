///////////////////////////////
// CS225 Spring 2016 //////////
// Cristian Garcia ////////////
///////////////////////////////

// Include Derectives /////////
#include "wirelessrouter.hpp"
#include <iostream>
#include <string>

// Implementation Section: ///////////////////////////////////////////////////////////
int WirelessRouter::num_alive=0;

// Default Create and Keep Track Number of Packet Switches ///////////////////////////
WirelessRouter::WirelessRouter()
{
   packet_size = 0;
   ieee_std = "";
   data_rate = 0.0;
   num_alive++;
   //net_ptr=NULL;
}

// Default Set Array of Packet Switch Objects ////////////////////////////////////////
WirelessRouter::WirelessRouter(int new_packet_size, std::string new_ieee_std, double new_data_rate)
{
   packet_size = new_packet_size;
   ieee_std = new_ieee_std;
   data_rate = new_data_rate;
   num_alive++;
} 

// Destroy and Delete Track of Number of Packet Switches /////////////////////////////
WirelessRouter::~WirelessRouter()
{
   num_alive--;
} 

// Check if Packet Sewitch is Empty or Defined as Default ////////////////////////////
int WirelessRouter::isempty()
{
  if(packet_size == 0 && ieee_std == "" && data_rate == 0.0)
   return 1;
  else
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Number of Ports ////////
int WirelessRouter::set_packet_size(int new_packet_size)
{
   packet_size = new_packet_size;
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Vendor /////////////////
int WirelessRouter::set_ieee_std(std::string new_ieee_std)
{
   ieee_std = new_ieee_std;
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Per Port Speed /////////
double WirelessRouter::set_data_rate(double new_data_rate)
{
   data_rate = new_data_rate;
   return 0;
}

double WirelessRouter::compute_packetspersec()///double pps, int num_ports, int packet_size) //////////////////     look!!!!!
{
   packets_per_sec = (data_rate / (8 * packet_size));
   return 0;
}

////int PacketSwitch::set_network_ptr(Network* new_net_ptr)
////{
////   net_ptr = new_net_ptr;
////   return 0;
////}


// Set All Packet Switch Object Data to Blank or Default /////////////////////////////
int WirelessRouter::set_blank()
{
   packet_size = 0;
   ieee_std = "";
   data_rate = 0.0;
   return 0;
}

// Retrive Number of Alive Packet Switch Objects /////////////////////////////////////
int WirelessRouter::get_num_alive()
{
   return num_alive;
}

// Determine and Display Packet Switch Array Memory Usage ////////////////////////////
int WirelessRouter::display_mem_usage()
{
  std::cout << "Program Memory Usage: " << get_num_alive()* sizeof(WirelessRouter) << std::endl;
  return 0;
}

//Retrieve All Packet Switch Object Information /////////////////////////////////////
int WirelessRouter::toCout()
{
   std::cout << "Wireless Router Packet Size          : " << get_packet_size() << std::endl;
   std::cout << "Wireless Router IEEE                 : " << get_ieee_std() << std::endl;
   std::cout << "Wireless Router Data Rate            : " << get_data_rate() << std::endl;
   return 0;
}

////Component* PacketSwitch::get_component(int index){return &loc_component_array[index];}

ostream &operator<<( ostream &output, const WirelessRouter &Wr)
{
   Wr.PacketSwitch::toCout();
   output << "Wireless Router Packet Size          : " << Wr.get_packet_size() << std::endl
          << "Wireless Router IEEE                 : " << Wr.get_ieee_std() << std::endl
          << "Wireless Router Data Rate            : " << Wr.get_data_rate() << std::endl;

          ////if(Ps.net_ptr != NULL)
          ////{ 
          ////  output << *(Ps.net_ptr);
          ////}
          ////else 
          ////{
          ////  output<<"Is not Network"<< std::endl;
          ////}
          ////for(int i = 0; i < 20 ; i++)
          ////{
          ////  if(Ps.loc_component_array[i].isempty()){}
          ////  else
          ////  output << Ps.loc_component_array[i] << std::endl;
          ////}

   return output;
};