//////////////////////////////////////////////////////////
//
//	Test Driver
//
//////////////////////////////////////////////////////////

int testPositive_packetSwitch();
//int testNegative_packetSwitch();

int testPositive_ethernetSwitch();
//int testNegative_ethernetSwitch();

//int testPositive_wirelessRouter();
//int testNegative_wirelessRouter();

int main()
{
	testPositive_packetSwitch();
	//testNegative_packetSwitch();

	testPositive_ethernetSwitch();
	//testNegative_ethernetSwitch();

	//testPositive_wirelessRouter();
	//testNegative_wirelessRouter();
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
	try
	{
		PacketSwitch ps;									// Test Constructor
		ps.printDetails();


		ps.set_vendor("Cisco");									// Test Mutator Functions
		ps.set_model("Switch-tastic switcher");
		ps.set_power(2500);
		ps.set_mtu(1500);
		ps.set_dimensions(15.9, 28.5, 5.3);
		ps.printDetails();

		std::cout << "Object Empty? " << ps.isempty() << std::endl << std::endl;		// Test isempty()
		std::cout << "Total Alive: " << ps.get_numAlive() << std::endl << std::endl;		// Test get_numAlive()
		ps.resetObject();									// Test resetObject()
		ps.printDetails();

		std::cout << "Object Empty? " << ps.isempty() << std::endl << std::endl;		// Test isempty(), again
		ps.display_memUsage();									// Test display_memUsage()

		PacketSwitch ps2( "Linksys", "I'm a router, yo!", 50, 65535, 10.2, 18.4, 2.15 );	// Test Overloaded Construtor

		std::cout << "Vendor : " << ps2.get_vendor() << std::endl <<				// Test Accessor Functions
			     "Model  : " << ps2.get_model()  << std::endl <<
			     "Power  : " << ps2.get_power()  << std::endl <<
			     "MTU    : " << ps2.get_mtu()    << std::endl <<
			     "Height : " << ps2.get_height() << std::endl <<
			     "Width  : " << ps2.get_width()  << std::endl <<
			     "Depth  : " << ps2.get_depth()  << std::endl << std::endl;

		ps2.display_memUsage();									// Test display_memUsage(), again

		std::cout << "Total Alive: " << ps.get_numAlive() << std::endl << std::endl;		// Test get_numAlive(), again
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while testing the methods of the Packet Switch Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}
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
		std::cout << "An error occurred while testing the methods of the Packet Switch Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}
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


		es.set_vendor("Cisco");									// Test Mutator Functions
		es.set_model("Switch-tastic switcher");
		es.set_power(2500);
		es.set_mtu(1500);
		es.set_dimensions(15.9, 28.5, 5.3);

		es.set_numPorts(25);
		es.set_perPortSpeed(100);
		es.printDetails();
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while testing the methods of the Packet Switch Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}
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
		std::cout << "An error occurred while testing the methods of the Packet Switch Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}
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
		
	}

	// In the event of a run-time error
	catch(const std::exception& errMsg)
	{
		std::cout << "An error occurred while testing the methods of the Packet Switch Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}
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
		std::cout << "An error occurred while testing the methods of the Packet Switch Class." << std::endl;
		std::cout << "Error Message: " << errMsg.what() << std::endl;
		std::exit(0);
	}
}
	
