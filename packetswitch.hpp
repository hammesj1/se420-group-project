///////////////////////////////
// CS225 Spring 2016 //////////
// Cristian Garcia ////////////
///////////////////////////////

///////////////////////////////
#ifndef PACKETSWITCH_HPP_
#define PACKETSWITCH_HPP_
// Include Directives /////////
#include <iostream>
#include <string>
#include "network.hpp"
#include "component.hpp"
using std::ostream;
// Decleration Section: //////////////////////////////////////////////////////////////
class PacketSwitch
{
   private:
     // Data Hiding //////////////////////////////////////////////////////////////////
     static int num_alive;
     std::string vendor;
     std::string model;
     //int num_ports;
     //double pps;
     double power;
     struct SizeInInches
     {
        float height;
        float width;
        float depth;
     } dimensions;
     int net_tkr;
     Network *net_ptr;
     //double thermal_output;
     //double packet_per_sec;
  
   protected:
     int num_ports;
     double pps; 
     double packets_per_sec;
     //Component *ptr_component;

   public:
     Component loc_component_array[20];
     int cindex; //int cindex = 0;
     Component* get_component(int index);
     // Constructor //////////////////////////////////////////////////////////////////
     PacketSwitch();

     /////////////////////////////////////////////////////////////////////////////////
     PacketSwitch(std::string, std::string, int, double, double);

     // Destructor ///////////////////////////////////////////////////////////////////
     virtual ~PacketSwitch();

     // Mutators ////////////////////////////////////////////
     int set_vendor(std::string);
     int set_model(std::string);
     int set_num_ports(int);
     double set_pps(double);
     double set_power(double);
     int set_dimensions(float, float, float);
     int set_net_tkr(int);
     int set_blank();
     int set_network_ptr( Network* );
     virtual double compute_packetspersec();
     
     // Accessors ///////////////////////////////////////////
     static int get_num_alive();
     std::string get_vendor()const{return vendor;}
     std::string get_model()const{return model;}
     int get_num_ports()const{return num_ports;}
     double get_pps()const{return pps;}
     double get_power()const{return power;}
     float get_dimensions_height()const{return dimensions.height;}
     float get_dimensions_width()const{return dimensions.width;}
     float get_dimensions_depth()const{return dimensions.depth;}
     int get_net_tkr(){return net_tkr;}
     Network* get_network_ptr()const{return net_ptr;}
     double get_compute_packetspersec()const{return packets_per_sec;}

     // Helpers //////////////////////////////////////////////////////////////////////
     int isempty();
     int display_mem_usage();
     int toCout() const;
     friend ostream& operator<< (ostream &output, const PacketSwitch& Ps);
};
#endif