//////////////////////////////////////////////////////////////////////////////
//
//  File Name: ethernetswitch.cpp
//
//  Description
//
//  Program is complete with three other source files (pswitch_main.cpp,
//  ethernetswitch.hpp, and packetswitch.hpp). This module of the program
//  contains all function definitions for the ethernetSwitch class which is
//  inherited from the packetSwitch class.
//
//////////////////////////////////////////////////////////////////////////////


#include "wirelessrouter.hpp"

int WirelessRouter::numAlive=0;


//////////////////////////////////////////
//      Constructors and Destructor     //
//////////////////////////////////////////

// Default Constructor
WirelessRouter::WirelessRouter()
{
	ieeeStd		= "";
	maxClients	= 0;
	maxBandwidth	= 0;

	numAlive++;
}

// Overloaded Constructor
WirelessRouter::WirelessRouter(std::string new_ieeeStd, int new_maxClients, int new_maxBandwidth)
{
	ieeeStd		= new_ieeeStd;
	maxClients	= new_maxClients;
	maxBandwidth	= new_maxBandwidth;

	numAlive++;
}

// Default Destructor
WirelessRouter::~WirelessRouter()
{
	numAlive--;
}


//////////////////////////////////////////
//          Predicate Functions         //
//////////////////////////////////////////


bool WirelessRouter::isempty()
{
	if( ieeeStd == "" && maxClients == 0 && maxBandwidth == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}


//////////////////////////////////////////
//          Mutator Functions           //
//////////////////////////////////////////


int WirelessRouter::set_ieeeStd(std::string new_ieeeStd)	// IEEE 802.11 Standard
{
	ieeeStd = new_ieeeStd;
	return 0;
}

int WirelessRouter::set_maxClients(int new_maxClients)		// Maximum Clients supported at one time
{
	maxClients = new_maxClients;
	return 0;
}

int WirelessRouter::set_maxBandwidth(int new_maxBandwidth)	// Maximum total bandwidth of the WAP
{
	maxBandwidth = new_maxBandwidth;
	return 0;
}

int WirelessRouter::resetObject()				// Reset/Clear Object values
{
	ieeeStd	= "";
	maxClients	= 0;
	maxBandwidth	= 0;

	PacketSwitch::resetObject();				// Reset/Clear PacketSwitch values too

	return 0;
}


//////////////////////////////////////////
//          Accessor Functions          //
//////////////////////////////////////////


int WirelessRouter::get_numAlive()		// Number Alive
{
	return numAlive;
}

int WirelessRouter::display_memUsage()		// Memory Usage by Ethernet Switch Objects
{
  std::cout << "Memory Usage (Ethernet Switch): " << get_numAlive()* sizeof(WirelessRouter) << std::endl;
  return 0;
}

int WirelessRouter::printDetails() const	// Display all data contained in the object
{
	PacketSwitch::printDetails();

	std::cout << "Wireless Router IEEE Standard        : " << get_ieeeStd() << std::endl;
	std::cout << "Wireless Router Maximum Clients      : " << get_maxClients() << std::endl;
	std::cout << "Wireless Router Maximum Bandwidth    : " << get_maxBandwidth() << std::endl << std::endl;
	return 0;
}
