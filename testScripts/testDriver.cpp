//////////////////////////////////////////////////////////
//
//	Test Driver
//
//////////////////////////////////////////////////////////


#include "packetswitch.hpp"
#include "ethernetswitch.hpp"
#include "wirelessrouter.hpp"
#include "subnet.hpp"


int testPositive_packetSwitch();
//int testNegative_packetSwitch();

int testPositive_ethernetSwitch();
//int testNegative_ethernetSwitch();

int testPositive_wirelessRouter();
//int testNegative_wirelessRouter();

//int testPositive_subnet();
//int testNegative_subnet();

int main()
{
	int return_psPos = 0, return_esPos = 0, return_wrPos = 0, return_subPos = 0;
	int return_psNeg = 0, return_esNeg = 0, return_wrNeg = 0, return_subNeg = 0;

	return_psPos = testPositive_packetSwitch();
	//return_psNeg = testNegative_packetSwitch();

	return_esPos = testPositive_ethernetSwitch();
	//return_esNeg = testNegative_ethernetSwitch();

	return_wrPos = testPositive_wirelessRouter();
	//return_wrNeg = testNegative_wirelessRouter();

	//return_subPos = testPositive_subnet();
	//return_subNeg = testNegative_subnet();

	if( return_psPos == 1 )
		std::cout << "Packet Switch failed one or more of its positive tests!" << std::endl;
	if( return_psNeg == 1 )
		std::cout << "Packet Switch failed one or more of its negative tests!" << std::endl;
	if( return_esPos == 1 )
		std::cout << "Ethernet Switch failed one or more of its positive tests!" << std::endl;
	if( return_esNeg == 1 )
		std::cout << "Ethernet Switch failed one or more of its negative tests!" << std::endl;
	if( return_wrPos == 1 )
		std::cout << "Wireless Router failed one or more of its positive tests!" << std::endl;
	if( return_wrNeg == 1 )
		std::cout << "Wireless Router failed one or more of its negative tests!" << std::endl;
	if( return_subPos == 1 )
		std::cout << "Subnet failed one or more of its positive tests!" << std::endl;
	if( return_subNeg == 1 )
		std::cout << "Subnet failed one or more of its negative tests!" << std::endl;
}

//////////////////////////////////
//				//
//	Packet Switch		//
//				//
//////////////////////////////////
//
// Positive Test
//
int testPositive_packetSwitch()
{
	int returnInt = 0;

	try
	{
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		PacketSwitch ps;									// Test Default Constructor

		if( ps.get_vendor() == "" && ps.get_model() == "" && ps.get_location() == "" && 
			ps.get_power() == 0 && ps.get_mtu() == 0 && ps.get_height() == 0.0 && 
			ps.get_width() == 0.0 && ps.get_depth() == 0.0 && ps.get_netPtr() == NULL )
		{
			std::cout << "Packet Switch\tDefault Constructor PASSED" << std::endl;
		}
		else
		{
			std::cout << "Packet Switch\tDefault Constructor\tFAILED" << std::endl;
			returnInt = 1;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		ps.set_vendor("Cisco");									// Test Mutator Functions
		ps.set_model("Switch-tastic switcher");
		ps.set_location("B72-129");
		ps.set_power(2500);
		ps.set_mtu(1500);
		ps.set_dimensions(15.9, 28.5, 5.3);

		if( ps.get_vendor() == "Cisco" && ps.get_model() == "Switch-tastic switcher" &&
			ps.get_location() == "B72-129" && ps.get_power() == 2500 && ps.get_mtu() == 1500 &&
			ps.get_height() == 15.9 && ps.get_width() == 28.5 && ps.get_depth() == 5.3 )
		{
			std::cout << "Packet Switch\tMutator Functions PASSED" << std::endl;
		}
		else
		{
			std::cout << "Packet Switch\tMutator Functions\tFAILED" << std::endl;
			returnInt = 1;
		}		

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if( !( ps.isempty() ) )									// Test isempty()
		{
			std::cout << "Packet Switch\tisempty() PASSED" << std::endl;
		}
		else
		{
			std::cout << "Packet Switch\tisempty()\tFAILED" << std::endl;
			returnInt = 1;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if( ps.get_numAlive() == 1 )								// Test get_numAlive()
		{
			std::cout << "Packet Switch\tget_numAlive() PASSED" << std::endl;
		}
		else
		{
			std::cout << "Packet Switch\tget_numAlive()\tFAILED" << std::endl;
			returnInt = 1;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		ps.resetObject();									// Test resetObject()

		if( ps.get_vendor() == "" && ps.get_model() == "" && ps.get_location() == "" && 
			ps.get_power() == 0 && ps.get_mtu() == 0 && ps.get_height() == 0.0 && 
			ps.get_width() == 0.0 && ps.get_depth() == 0.0 && ps.get_netPtr() == NULL )
		{
			std::cout << "Packet Switch\tresetObject() PASSED" << std::endl;
		}
		else
		{
			std::cout << "Packet Switch\tresetObject()\tFAILED" << std::endl;
			returnInt = 1;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if( ps.display_memUsage() == 136 )							// Test display_memUsage()
		{
			std::cout << "Packet Switch\tdisplay_memUsage() PASSED" << std::endl;
		}
		else
		{
			std::cout << "Packet Switch\tdisplay_memUsage()\tFAILED" << std::endl;
			returnInt = 1;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		PacketSwitch ps2( "Linksys", "I'm a router, yo!", "B70A-103", 				// Test Overloaded Construtor
					50, 1028, 10.2, 18.4, 2.15, NULL );

		if( ps.get_vendor() == "Linksys" && ps.get_model() == "I'm a router, yo!" && 
			ps.get_location() == "B70A-103" && ps.get_power() == 50 && 
			ps.get_mtu() == 1028 && ps.get_height() == 10.2 && ps.get_width() == 18.4 && 
			ps.get_depth() == 2.15 && ps.get_netPtr() == NULL )
		{
			std::cout << "Packet Switch\tOverloaded Constructor PASSED" << std::endl;
		}
		else
		{
			std::cout << "Packet Switch\tOverloaded Constructor\tFAILED" << std::endl;
			returnInt = 1;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if( ps.display_memUsage() == 272 )							// Test display_memUsage(), again
		{
			std::cout << "Packet Switch\tdisplay_memUsage() PASSED" << std::endl;
		}
		else
		{
			std::cout << "Packet Switch\tdisplay_memUsage()\tFAILED" << std::endl;
			returnInt = 1;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		ps.~PacketSwitch();									// Test default destructor

		if( ps.get_numAlive() == 1 )
		{
			std::cout << "Packet Switch\tDefault Constructor PASSED" << std::endl;
		}
		else
		{
			std::cout << "Packet Switch\tDefault Constructor\tFAILED" << std::endl;
			returnInt = 1;
		}
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while testing the methods of the Packet Switch Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}

	return returnInt;
}

//////////////////////////////////
//
// Negative Test
//
int testNegative_packetSwitch()
{
	try
	{
		
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while running negative tests on the Packet Switch Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}

	return 0;
}



//////////////////////////////////
//				//
//	Ethernet Switch		//
//				//
//////////////////////////////////
//
// Positive Test
//
int testPositive_ethernetSwitch()
{
	try
	{
		EthernetSwitch es;									// Test Constructor
		es.printDetails();


		es.set_numPorts(25);									// Test Mutator Functions
		es.set_perPortSpeed(100);
		es.printDetails();

		std::cout << "Object Empty? " << es.isempty() << std::endl << std::endl;		// Test isempty()
		std::cout << "Total Alive: " << es.get_numAlive() << std::endl << std::endl;		// Test get_numAlive()
		es.resetObject();									// Test resetObject()
		es.printDetails();

		std::cout << "Object Empty? " << es.isempty() << std::endl << std::endl;		// Test isempty(), again
		es.display_memUsage();									// Test display_memUsage()

		EthernetSwitch es2( 50, 1000 );								// Test Overloaded Construtor

		std::cout << "Number of Ports : " << es2.get_numPorts() << std::endl <<			// Test Accessor Functions
			     "Per Port Speed  : " << es2.get_perPortSpeed()  << std::endl << std::endl;

		es2.display_memUsage();									// Test display_memUsage(), again

		std::cout << "Total Alive: " << es.get_numAlive() << std::endl << std::endl;		// Test get_numAlive(), again

		es.~EthernetSwitch();									// Test default destructor

		std::cout << "Total Alive: " << es2.get_numAlive() << std::endl << std::endl;
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while testing the methods of the Ethernet Switch Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}

	return 0;
}

//////////////////////////////////
//
// Negative Test
//
int testNegative_ethernetSwitch()
{
	try
	{
		
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while running negative tests on the Ethernet Switch Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}

	return 0;
}



//////////////////////////////////
//				//
//	Wireless Router		//
//				//
//////////////////////////////////
//
// Positive Test
//
int testPositive_wirelessRouter()
{
	try
	{
		WirelessRouter wr;									// Test Constructor
		wr.printDetails();


		wr.set_ieeeStd("a/b/g/n");								// Test Mutator Functions
		wr.set_maxClients(200);
		wr.set_maxBandwidth(100);
		wr.printDetails();

		std::cout << "Object Empty? " << wr.isempty() << std::endl << std::endl;		// Test isempty()
		std::cout << "Total Alive: " << wr.get_numAlive() << std::endl << std::endl;		// Test get_numAlive()
		wr.resetObject();									// Test resetObject()
		wr.printDetails();

		std::cout << "Object Empty? " << wr.isempty() << std::endl << std::endl;		// Test isempty(), again
		wr.display_memUsage();									// Test display_memUsage()

		WirelessRouter wr2( "ac", 25, 200 );							// Test Overloaded Construtor

		std::cout << "IEEE Standard : " << wr2.get_ieeeStd() << std::endl <<			// Test Accessor Functions
			     "Max Clients   : " << wr2.get_maxClients()  << std::endl <<
			     "Max Bandwidth : " << wr2.get_maxBandwidth()  << std::endl << std::endl;

		wr2.display_memUsage();									// Test display_memUsage(), again

		std::cout << "Total Alive: " << wr.get_numAlive() << std::endl << std::endl;		// Test get_numAlive(), again

		wr.~WirelessRouter();									// Test default destructor

		std::cout << "Total Alive: " << wr2.get_numAlive() << std::endl << std::endl;
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while testing the methods of the Wireless Router Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}

	return 0;
}

//////////////////////////////////
//
// Negative Test
//
int testNegative_wirelessRouter()
{
	try
	{
		
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while running negative tests on the Wireless Router Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}

	return 0;
}



//////////////////////////////////
//				//
//	      Subnet		//
//				//
//////////////////////////////////
//
// Positive Test
//
int testPositive_subnet()
{
	try
	{
		
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while testing the methods of the Subnet Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}

	return 0;
}

//////////////////////////////////
//
// Negative Test
//
int testNegative_subnet()
{
	try
	{
		
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while running negative tests on the Subnet Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}

	return 0;
}	
