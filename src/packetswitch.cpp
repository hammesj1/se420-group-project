//////////////////////////////////////////////////////////////////////////////
//
//  File Name: packetswitch.cpp
//
//  Description
//
//  Program is complete with two other source files (pswitch_main.cpp and
//  packetswitch.hpp). This module of the program contains all function
//  definitions for the packetSwitch class.
//
//////////////////////////////////////////////////////////////////////////////


#include "packetswitch.hpp"

int PacketSwitch::numAlive=0;   // tracks packetSwitch objects in memory


//////////////////////////////////////////
//      Constructors and Destructor     //
//////////////////////////////////////////

// Default Contructor
PacketSwitch::PacketSwitch()
{
        vendor          = "";
        model           = "";
	location	= "";
        power           = 0;
        mtu             = 0;
        dimensions      = {0.0, 0.0, 0.0};

        numAlive++;

        // net_ptr=NULL;        // Probably remove this
}

// Overloaded Constructor
PacketSwitch::PacketSwitch(std::string new_vendor, std::string new_model, std::string new_location,
				double new_power, int new_mtu, float height, float width, float depth)
{
        vendor          = new_vendor;
        model           = new_model;
	location	= new_location;
        power           = new_power;
        mtu             = new_mtu;
        dimensions      = {height, width, depth};

        numAlive++;
}

// Destructor
PacketSwitch::~PacketSwitch()
{
        numAlive--;
}


//////////////////////////////////////////
//          Predicate Functions         //
//////////////////////////////////////////


bool PacketSwitch::isempty()
{
        if(vendor == "" && model == "" && location == "" && power == 0 && mtu == 0 &&
                dimensions.height == 0.0 && dimensions.width == 0.0 && dimensions.depth == 0.0)
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



int PacketSwitch::set_vendor(std::string new_vendor)		// Vendor
{
        vendor = new_vendor;
        return 0;
}

int PacketSwitch::set_model(std::string new_model)		// Model
{
        model = new_model;
        return 0;
}

int PacketSwitch::set_location(std::string new_location)	// Physical Location
{
        location = new_location;
        return 0;
}

double PacketSwitch::set_power(double new_power)		// Power
{
        power = new_power;
        return 0;
}

int PacketSwitch::set_mtu(int new_mtu)				// Maximum Transmission Unit
{
        mtu = new_mtu;
        return 0;
}

int PacketSwitch::set_dimensions(float new_height, float new_width, float new_depth)    // Dimensions
{
        dimensions.height = new_height;
        dimensions.width = new_width;
        dimensions.depth = new_depth;
        return 0;
}

int PacketSwitch::resetObject()         // Reset/Clear Object values
{
        vendor          = "";
        model           = "";
	location	= "";
        power           = 0;
        mtu             = 0;
        dimensions      = {0.0, 0.0, 0.0};

        return 0;
}


//////////////////////////////////////////
//          Accessor Functions          //
//////////////////////////////////////////


int PacketSwitch::get_numAlive()		// Number Alive
{
        return numAlive;
}

int PacketSwitch::display_memUsage()		// Memory Usage by Packet Switch Objects
{
        std::cout << "Memory Usage (Packet Switch): " << get_numAlive()* sizeof(PacketSwitch) << std::endl << std::endl;
        return 0;
}

int PacketSwitch::printDetails() const		// Display all data contained in the object
{
        std::cout << "Packet Switch Vendor                 : " << get_vendor() << std::endl;
        std::cout << "Packet Switch Model                  : " << get_model() << std::endl;
        std::cout << "Packet Switch Location               : " << get_location() << std::endl;
	std::cout << "Packet Switch Power Comsumption      : " << get_power() << " W" << std::endl;
	std::cout << "Packet Switch MTU                    : " << get_mtu() << " Bytes" << std::endl;
	std::cout << "Packet Switch Dimensions (H x W x D) : " << get_height() << " x " << get_width() << " x " << get_depth() << std::endl << std::endl;
	return 0;
}
