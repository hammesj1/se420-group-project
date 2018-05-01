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


#include "ethernetswitch.hpp"

int EthernetSwitch::numAlive = 0;


//////////////////////////////////////////
//      Constructors and Destructor     //
//////////////////////////////////////////

// Default Constructor
EthernetSwitch::EthernetSwitch()
{
	numPorts	= 0;
	perPortSpeed	= 0;

	numAlive++;
}

// Overloaded Constructor
EthernetSwitch::EthernetSwitch(int new_numPorts, int new_perPortSpeed)
{
	numPorts = new_numPorts;
	perPortSpeed = new_perPortSpeed;

	numAlive++;
} 

// Default Destructor
EthernetSwitch::~EthernetSwitch()
{
	numAlive--;
}


//////////////////////////////////////////
//          Predicate Functions         //
//////////////////////////////////////////


bool EthernetSwitch::isempty()
{
	if(numPorts == 0 && perPortSpeed == 0 && PacketSwitch::isempty() == 1)
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


int EthernetSwitch::set_numPorts(int new_numPorts)		// Number of Physical Ports
{
	numPorts = new_numPorts;
	return 0;
}

int EthernetSwitch::set_perPortSpeed(int new_perPortSpeed)	// Bandwidth per Physical Port (Mbps)
{
	perPortSpeed = new_perPortSpeed;
	return 0;
}

int EthernetSwitch::resetObject()				// Reset/Clear Object values
{
	numPorts	= 0;
	perPortSpeed	= 0;

	PacketSwitch::resetObject();				// Reset/Clear PacketSwitch values too

	return 0;
}


//////////////////////////////////////////
//          Accessor Functions          //
//////////////////////////////////////////


int EthernetSwitch::get_numAlive()		// Number Alive
{
	return numAlive;
}

int EthernetSwitch::display_memUsage()		// Memory Usage by Ethernet Switch Objects
{
	std::cout << "Memory Usage (Ethernet Switch): " << get_numAlive()* sizeof(EthernetSwitch) << std::endl;
	return 0;
}

int EthernetSwitch::printDetails() const	// Display all data contained in the object
{
	PacketSwitch::printDetails();

	std::cout << "Ethernet Switch Number of Ports      : " << get_numPorts() << std::endl;
	std::cout << "Ethernet Switch Per Port Speed       : " << get_perPortSpeed() << std::endl << std::endl;
	return 0;
}








