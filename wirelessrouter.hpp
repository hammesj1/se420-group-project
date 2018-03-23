///////////////////////////////
// CS225 Spring 2016 //////////
// Cristian Garcia ////////////
///////////////////////////////

///////////////////////////////
#ifndef WIRELESSROUTER_HPP_
#define WIRELESSROUTER_HPP_
// Include Directives /////////
#include <iostream>
#include <string>
#include "packetswitch.hpp"
using std::ostream;

// Decleration Section: //////////////////////////////////////////////////////////////
class WirelessRouter:public PacketSwitch
{
   private:
     // Data Hiding //////////////////////////////////////////////////////////////////
     static int num_alive;
     int packet_size;
     std::string ieee_std;
     double data_rate;

   public:
     // Constructor //////////////////////////////////////////////////////////////////
     WirelessRouter();

     /////////////////////////////////////////////////////////////////////////////////
     WirelessRouter(int, std::string, double);

     // Destructor ///////////////////////////////////////////////////////////////////
     ~WirelessRouter();

     // Mutators ////////////////////////////////////////////
     int set_packet_size(int);
     int set_ieee_std(std::string);
     double set_data_rate(double);
     double compute_packetspersec();
     int set_blank();
     
     // Accessors ///////////////////////////////////////////
     static int get_num_alive();
     int get_packet_size()const{return packet_size;}
     std::string get_ieee_std()const{return ieee_std;}
     double get_data_rate()const{return data_rate;}

     // Helpers //////////////////////////////////////////////////////////////////////
     int isempty();
     int display_mem_usage();
     int toCout();
     friend ostream& operator<< (ostream &output, const WirelessRouter& Wr);
};
#endif