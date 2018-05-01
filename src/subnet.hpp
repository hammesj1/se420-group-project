//////////////////////////////////////////////////////////////////////////////
//
//  File Name: subnet.hpp
//
//  Description
//
//  Program is complete with two other source files (pswitch_main.cpp and
//  subnet.cpp). This module of the program contains the class
//  declarations for the packetSwitch class.
//
//////////////////////////////////////////////////////////////////////////////


// Pre-processor Directives

#include <iostream>
#include <string>

#ifndef SUBNET_HPP_
#define SUBNET_HPP_


// Declaration of the Subnet Class
class Subnet
{
	private:

		static int numAlive;

		std::string ipAddress;		// IP Address of the Subnet's root node
		std::string CIDR;		// CIDR Identifier of the Subnet (e.g. 192.168.1/24)
		std::string netMask;		// Subnet Mask (e.g. 255.255.255.0)
		std::string defaultGate;	// Default Gateway in and out of the Subnet

		int liveClients;		// Total number of clients that are live on the Subnet

	public:

		Subnet();								// Default Construtor
		Subnet(std::string, std::string, std::string, std::string, int);	// Overloaded Constructor

		~Subnet();								// Default Destructor


		// Mutator Methods
		int set_ipAddress(std::string);
		int set_CIDR(std::string);
		int set_netMask(std::string);
		int set_defaultGate(std::string);
		int set_liveClients(int);


		// Accessor Methods
		static int get_numAlive();
		std::string get_ipAddress()const{return ipAddress;}
		std::string get_CIDR()const{return CIDR;}
		std::string get_netMask()const{return netMask;}
		std::string get_defaultGate()const{return defaultGate;}
		int get_liveClients()const{return liveClients;}


		// Helper Methods
		bool isempty();
		int resetObject();
		int printDetails() const;
};
#endif
