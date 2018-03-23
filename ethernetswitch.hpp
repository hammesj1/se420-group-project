///////////////////////////////
// CS225 Spring 2016 //////////
// Cristian Garcia ////////////
///////////////////////////////

///////////////////////////////
#ifndef ETHERNETSWITCH_HPP_
#define ETHERNETSWITCH_HPP_
// Include Directives /////////
#include <iostream>
#include <string>
#include "packetswitch.hpp"
using std::ostream;

// Decleration Section: //////////////////////////////////////////////////////////////
class EthernetSwitch:public PacketSwitch
{
   private:
     // Data Hiding //////////////////////////////////////////////////////////////////
     static int num_alive;
     int packet_size;
     int rating;

   public:
     
     // Constructor //////////////////////////////////////////////////////////////////
     EthernetSwitch();

     /////////////////////////////////////////////////////////////////////////////////
     EthernetSwitch(int, int);

     // Destructor ///////////////////////////////////////////////////////////////////
     ~EthernetSwitch();

     // Mutators ////////////////////////////////////////////
     int set_packet_size(int);
     int set_rating(int);
     double compute_packetspersec();
     int set_blank();
     
     // Accessors ///////////////////////////////////////////
     static int get_num_alive();
     int get_packet_size()const{return packet_size;}//;
     int get_rating()const{return rating;}//;

     // Helpers //////////////////////////////////////////////////////////////////////
     int isempty();
     int display_mem_usage();
     int toCout() const;
     friend ostream& operator<< (ostream &output, const EthernetSwitch& Es);

};
#endif