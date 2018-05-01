//////////////////////////////////////////////////////////////////////////////
//
//  File Name: ethernetswitch.hpp
//
//  Description
//
//  Program is complete with three other source files (pswitch_main.cpp,
//  ethernetswitch.cpp, and packetswitch.hpp). This module of the program
//  contains the class declarations for the ethernetSwitch class which is
//  inherited from the packetSwitch class.
//
//////////////////////////////////////////////////////////////////////////////


// Pre-Processor Directives

#include "packetswitch.hpp"

#ifndef ETHERNETSWITCH_HPP_
#define ETHERNETSWITCH_HPP_


// Decleration of the ethernetSwitch Class

class EthernetSwitch:public PacketSwitch
{
	private:

		static int numAlive;
		int numPorts;			// Number of physical ports on the switch
		int perPortSpeed;		// Max Bandwith supported for each port (Mbps)

	public:

		EthernetSwitch();		// Default Construtor
		EthernetSwitch(int, int);	// Overloaded Constructor

		~EthernetSwitch();		// Default Destructor


		// Mutator Methods
		int set_numPorts(int);
		int set_perPortSpeed(int);


		// Accessor Methods
		static int get_numAlive();
		int get_numPorts()const{return numPorts;}
		int get_perPortSpeed()const{return perPortSpeed;}


		// Additional Methods (Helper Functions)
		bool isempty();
		int resetObject();
		int display_memUsage();
		int printDetails() const;
};
#endif
