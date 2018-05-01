//////////////////////////////////////////////////////////////////////////////
//
//  File Name: wirelessrouter.hpp
//
//  Description
//
//  Program is complete with three other source files (pswitch_main.cpp,
//  wirelessrouter.cpp, and packetswitch.hpp). This module of the program
//  contains the class declarations for the WirelessRouter class which is
//  inherited from the packetSwitch class.
//
//////////////////////////////////////////////////////////////////////////////


// Pre-Processor Directives

#include "packetswitch.hpp"

#ifndef WIRELESSROUTER_HPP_
#define WIRELESSROUTER_HPP_


// Decleration of the WirelessRouter Class

class WirelessRouter:public PacketSwitch
{
	private:

		static int numAlive;
		std::string ieeeStd;		// IEEE 802.11 Standard (e.g. a/b/g/n/ac)
		int maxClients;			// Total Number of Clients the WAP can support at one time
		int maxBandwidth;		// Maximum bandwidth the WAP can support (in Mbps)

	public:

		WirelessRouter();				// Default Constructor
		WirelessRouter(std::string, int, int);		// Overloaded Constructor

		~WirelessRouter();				// Default Destructor


		// Mutator Methods
		int set_ieeeStd(std::string);
		int set_maxClients(int);
		int set_maxBandwidth(int);


		// Accessor Methods
		static int get_numAlive();
		std::string get_ieeeStd()const{return ieeeStd;}
		int get_maxClients()const{return maxClients;}
		int get_maxBandwidth()const{return maxBandwidth;}

		// Helpers
		bool isempty();
		int resetObject();
		int display_memUsage();
		int printDetails() const;
};
#endif
