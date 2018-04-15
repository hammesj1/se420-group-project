///////////////////////////////
// CS225 Spring 2016 //////////
// Cristian Garcia ////////////
///////////////////////////////

// Include Derectives /////////
#include "packetswitch.hpp"
#include <iostream>
#include <string>

// Implementation Section: ///////////////////////////////////////////////////////////
int PacketSwitch::num_alive=0;

// Default Create and Keep Track Number of Packet Switches ///////////////////////////
PacketSwitch::PacketSwitch()
{
   vendor = "";
   model = "";
   num_ports = 0;
   pps = 0.0;
   power = 0.0;
   dimensions.height = 0.0;
   dimensions.width = 0.0;
   dimensions.depth = 0.0;
   num_alive++;
   net_ptr=NULL;
}

// Default Set Array of Packet Switch Objects ////////////////////////////////////////
PacketSwitch::PacketSwitch(std::string new_vendor, std::string new_model, int new_num_ports, double new_pps, double new_power)
{
   vendor = new_vendor;
   model = new_model;
   num_ports = new_num_ports;
   pps = new_pps;
   power = new_power;
   num_alive++;
}

// Destroy and Delete Track of Number of Packet Switches /////////////////////////////
PacketSwitch::~PacketSwitch()
{
   num_alive--;
}

// Check if Packet Sewitch is Empty or Defined as Default ////////////////////////////
int PacketSwitch::isempty()
{
  if(vendor == "" && model == "" && num_ports == 0 && pps == 0.0 && power == 0.0 && dimensions.height == 0.0 && dimensions.width == 0.0 && dimensions.depth == 0.0)
   return 1;
  else
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Vendor /////////////////
int PacketSwitch::set_vendor(std::string new_vendor)
{
   vendor = new_vendor;
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Model //////////////////
int PacketSwitch::set_model(std::string new_model)
{
   model = new_model;
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Number of Ports ////////
int PacketSwitch::set_num_ports(int new_num_ports)
{
   num_ports = new_num_ports;
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Per Port Speed /////////
double PacketSwitch::set_pps(double new_pps)
{
   pps = new_pps;
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Power //////////////////
double PacketSwitch::set_power(double new_power)
{
   power = new_power;
   return 0;
}

// Receive Information from Main and Set Packet Switch Object Dimensions /////////////
int PacketSwitch::set_dimensions(float new_height, float new_width, float new_depth)
{
   dimensions.height = new_height;
   dimensions.width = new_width;
   dimensions.depth = new_depth;
   return 0;
}

//int PacketSwitch::set_network_ptr(int new_net_tkr)
//{
 //  net_ptr = new_net_ptr;
//   return 0;
//}

int PacketSwitch::set_network_ptr(Network* new_net_ptr)
{
   net_ptr = new_net_ptr;
   return 0;
}


// Set All Packet Switch Object Data to Blank or Default /////////////////////////////
int PacketSwitch::set_blank()
{
   vendor = "";
   model = "";
   num_ports = 0;
   pps = 0.0;
   power = 0.0;
   dimensions.height = 0.0;
   dimensions.width = 0.0;
   dimensions.depth = 0.0;
   return 0;
}

// Retrive Number of Alive Packet Switch Objects /////////////////////////////////////
int PacketSwitch::get_num_alive()
{
   return num_alive;
}

// Determine and Display Packet Switch Array Memory Usage ////////////////////////////
int PacketSwitch::display_mem_usage()
{
  std::cout << "Program Memory Usage: " << get_num_alive()* sizeof(PacketSwitch) << std::endl;
  return 0;
}


double PacketSwitch::compute_packetspersec()    ///double pps, int num_ports, int packet_size)
{
   std::cout << "No Sufficient Data Avalible in the Object" << std::endl;
   return 0;
}

//Retrieve All Packet Switch Object Information /////////////////////////////////////
int PacketSwitch::toCout() const
{
   std::cout << "Packet Switch Vendor                 : " << get_vendor() << std::endl;
   std::cout << "Packet Switch Model                  : " << get_model() << std::endl;
   std::cout << "Packet Switch Number of Ports        : " << get_num_ports() << std::endl;
   std::cout << "Packet Switch Per Port Speed         : " << get_pps() << " Mbps" << std::endl;
   std::cout << "Packet Switch Power Comsumption      : " << get_power() << " W" << std::endl;
   std::cout << "Packet Switch Dimensions (H x W x D) : " << get_dimensions_height() << " x " << get_dimensions_width() << " x " << get_dimensions_depth() << " inches" << std::endl;

    if(net_ptr != NULL)
          {
            std::cout << *(net_ptr);
          }
          else
          {
            std::cout<<"Is not Network"<< std::endl;
          }
   return 0;
}

ostream &operator<<( ostream &output, const PacketSwitch &Ps)
{

   output << "Packet Switch Vendor                 : " << Ps.get_vendor() << std::endl
          << "Packet Switch Model                  : " << Ps.get_model() << std::endl
          << "Packet Switch Number of Ports        : " << Ps.get_num_ports() << std::endl
          << "Packet Switch Per Port Speed         : " << Ps.get_pps() << " Mbps" << std::endl
          << "Packet Switch Power Comsumption      : " << Ps.get_power() << " W" << std::endl
          << "Packet Switch Dimensions (H x W x D) : " << Ps.dimensions.height << " x " << Ps.dimensions.width << " x " << Ps.dimensions.depth <<std::endl;
          //if(Ps.get_network_ptr()->isempty() == 0)
          //if (Ps.get_vendor() == "" && Ps.get_model() == "" && Ps.get_num_ports() == 0 && Ps.get_pps() == 0.0 && Ps.get_power() == 0.0 &&
               //Ps.dimensions.height == 0.0 && Ps.dimensions.width == 0.0 && Ps.dimensions.depth == 0.0);

          if(Ps.net_ptr != NULL)
          {
            output << *(Ps.net_ptr);
          }
          else
          {
            output<<"Is not Network"<< std::endl;
          }
   return output;
};
