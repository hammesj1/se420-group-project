//////////////////////////////////////////////////////////////////////////////
//
//  File Name: packetswitch.hpp
//
//  Description
//
//  Program is complete with two other source files (pswitch_main.cpp and
//  packetswitch.cpp). This module of the program contains the class
//  declarations for the packetSwitch class.
//
//////////////////////////////////////////////////////////////////////////////


// Pre-processor Directives

#include <iostream>
#include <string>

#include "subnet.hpp"

#ifndef PACKETSWITCH_HPP_
#define PACKETSWITCH_HPP_


// Declaration of the Packet Switch Class
class PacketSwitch
{
	private:

		static int numAlive;	// Object Counter

		std::string vendor;
		std::string model;
		std::string location;	// Physical location of the hardware (e.g. B72-129)
		double	power;		// Power consumtion (in Watts)
		int	mtu;		// Max Packet Size before fragmenting (Maximum Transmission Unit)

		struct sizeInInches	// Physical size of the hardware (in Inches)
		{
			float height;
			float width;
			float depth;
		} dimensions;

		Subnet* netPtr = NULL;

	public:

		PacketSwitch();								// Default Constructor
		PacketSwitch(std::string, std::string, std::string, double, int,	// Overloaded Constructor
				 float, float, float, Subnet*);

		virtual ~PacketSwitch();						// Destructor


		// Mutator Methods
		int set_vendor(std::string);
		int set_model(std::string);
		int set_location(std::string);
		int set_power(double);
		int set_mtu(int);
		int set_dimensions(float, float, float);
		int set_subnet(Subnet*);


		// Accessor Methods
		static int get_numAlive();
		std::string get_vendor()const{return vendor;}
		std::string get_model()const{return model;}
		std::string get_location()const{return location;}
		double	get_power()const{return power;}
		int	get_mtu()const{return mtu;}
		float	get_height()const{return dimensions.height;}
		float	get_width()const{return dimensions.width;}
		float	get_depth()const{return dimensions.depth;}

		Subnet* get_netPtr()const{return netPtr;}
		std::string get_subnet_ipAddress()const{return netPtr->get_ipAddress();}
		std::string get_subnet_CIDR()const{return netPtr->get_CIDR();}
		std::string get_subnet_netMask()const{return netPtr->get_netMask();}
		std::string get_subnet_defaultGate()const{return netPtr->get_defaultGate();}
		int get_subnet_liveClients()const{return netPtr->get_liveClients();}


		// Additional Methods (Helper Functions)
		bool isempty();
		int resetObject();
		int display_memUsage();
		int printDetails() const;
};
#endif
