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
//#include "network.hpp"

#ifndef PACKETSWITCH_HPP_
#define PACKETSWITCH_HPP_


// Declaration of the Packet Switch Class
class PacketSwitch
{
	private:

		static int numAlive;	// Object Counter

		std::string vendor;
		std::string model;

		double	power;		// Power consumtion (in Watts)
		int	mtu;		// Max Packet Size before fragmenting (Maximum Transmission Unit)

		struct sizeInInches	// Physical size of the hardware (in Inches)
		{
			float height;
			float width;
			float depth;
		} dimensions;

	public:

		PacketSwitch();									// Default Constructor
		PacketSwitch(std::string, std::string, double, int, float, float, float);	// Overloaded Constructor

		virtual ~PacketSwitch();							// Destructor


		// Mutator Methods
		int	set_vendor(std::string);
		int	set_model(std::string);
		double	set_power(double);
		int	set_mtu(int);
		int	set_dimensions(float, float, float);


		// Accessor Methods
		static int get_numAlive();
		std::string get_vendor()const{return vendor;}
		std::string get_model()const{return model;}

		double	get_power()const{return power;}
		int	get_mtu()const{return mtu;}

		float	get_height()const{return dimensions.height;}
		float	get_width()const{return dimensions.width;}
		float	get_depth()const{return dimensions.depth;}


		// Additional Methods (Helper Functions)
		bool isempty();
		int resetObject();
		int display_memUsage();
		int printDetails() const;
};
#endif
