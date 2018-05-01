//////////////////////////////////////////////////////////////////////////////
//
//  File Name: subnet.cpp
//
//  Description
//
//  Program is complete with two other source files (pswitch_main.cpp and
//  subnet.hpp). This module of the program contains all function
//  definitions for the packetSwitch class.
//
//////////////////////////////////////////////////////////////////////////////


#include "subnet.hpp"

int Subnet::numAlive = 0;   // tracks Subnet objects in memory


//////////////////////////////////////////
//      Constructors and Destructor     //
//////////////////////////////////////////

// Default Constructor
Subnet::Subnet()
{
	ipAddress	= "";
	CIDR		= "";
	netMask		= "";
	defaultGate	= "";
	liveClients	= 0;

	numAlive++;
}

// Overloaded Constructor
Subnet::Subnet(std::string new_ipAddress, std::string new_CIDR, std::string new_netMask, 
		std::string new_defaultGate, int new_liveClients)
{
	ipAddress	= new_ipAddress;
	CIDR		= new_CIDR;
	netMask		= new_netMask;
	defaultGate	= new_defaultGate;
	liveClients	= new_liveClients;

	numAlive++;
}

// Default Destructor
Subnet::~Subnet()
{
   numAlive--;
}


//////////////////////////////////////////
//          Predicate Functions         //
//////////////////////////////////////////


bool Subnet::isempty()
{
	if(ipAddress == "" && CIDR == "" && netMask == "" && defaultGate == "" && liveClients == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//////////////////////////////////////////
//          Mutator Functions           //
//////////////////////////////////////////


int Subnet::set_ipAddress(std::string new_ipAddress)		// Root Node IP Address
{
	ipAddress = new_ipAddress;
	return 0;
}

int Subnet::set_CIDR(std::string new_CIDR)			// CIDR Identifier
{
	CIDR = new_CIDR;
	return 0;
}

int Subnet::set_netMask(std::string new_netMask)		// Subnet Mask
{
	netMask = new_netMask;
	return 0;
}

int Subnet::set_defaultGate(std::string new_defaultGate)	// Default Gateway
{
	defaultGate = new_defaultGate;
	return 0;
}

int Subnet::set_liveClients(int new_liveClients)		// Clients Live on the Subnet
{
	liveClients = new_liveClients;
	return 0;
}

int Subnet::resetObject()	// Reset/Clear Object values
{
	ipAddress	= "";
	CIDR		= "";
	netMask		= "";
	defaultGate	= "";
	liveClients	= 0;

	return 0;
}


//////////////////////////////////////////
//          Accessor Functions          //
//////////////////////////////////////////


int Subnet::get_numAlive()		// Number Alive
{
	return numAlive;
}

int Subnet::printDetails() const	// Display all data contained in the object
{
	std::cout << " Hardware Subnet Details " << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "Subnet Root Node IP Address          : " << get_ipAddress() << std::endl;
	std::cout << "Subnet CIDR Identifier               : " << get_CIDR() << std::endl;
	std::cout << "Subnet Mask                          : " << get_netMask() << std::endl;
	std::cout << "Subnet Default Gateway               : " << get_defaultGate() << std::endl;
	std::cout << "Subnet Live Clients                  : " << get_liveClients() << " clients"  << std::endl << std::endl;

   return 0;
}
