///////////////////////////////
//
// CS225 SPRING 2016
// CRISTIAN GARCIA
//
///////////////////////////////

// Include Directives
#include<iostream>
#include<string>
#include<sstream>
#include<unistd.h>

// Project Classess
#include "packetswitch.hpp"
#include "ethernetswitch.hpp"
#include "wirelessrouter.hpp"

//
using namespace std;

// Global Variables
const int ARR_MAX = 60;
const int PER_GROUP = 20;
const int max_pswitch = 60;
const int max_network = 60;

// = {new EthernetSwitch, new WirelessRouter, new PacketSwitch};
PacketSwitch *mixed_array[ARR_MAX];

// Boolean Logic
bool interactive = true;
bool done = false;

// Pointers
PacketSwitch **pswitch_array;///top
Network *network_array;
PacketSwitch **cur_pswitch;
Network *cur_network;

// Function Prototypes
int print_menu();
int process_menu_in(string);
int init_mixed_array();

// Start of Main Function
int main()
{
   string input_line;

   // Create Array of Packet Switch Objects
   init_mixed_array();
   // Create Array of Network Objects
   Network loc_network_array[max_network];

   // Point to Packet Swtich Array
   pswitch_array = mixed_array;
   // Point to Network Array
   network_array = loc_network_array;

   // Point to First Object in Packet Switch Array
   cur_pswitch = mixed_array;
   // Point to First Object in Network Array
   cur_network = loc_network_array;

   // Determine Input Stream as Interactive Or Test File
   interactive = isatty(STDIN_FILENO);

   // Interactive
   if (interactive) print_menu();

   // Execute Packet Switch Program Until Quit Is Selected
   while (!done)
   {
	  // Identify Current Packetswitch Being Worked On
      cout << endl << "Menu for object [" << (cur_pswitch - pswitch_array) << "] : ";
	  // Get Input Stream
      getline(cin, input_line);
	  // Process Input Line
      process_menu_in(input_line);
   }

   // Quit Was Selected Terminate Packet Switch Program
   cout << "You have selected to quit.\n\n"
           "Packet Switch Program Terminated - Goodbye!\n" << endl;
   return 0;
}

//
int init_mixed_array()
{
   for (int i = 0; i < ARR_MAX; i++)
     {
       int type = (i / (PER_GROUP));
       switch (type)
       {
          case 0:
              mixed_array[i] = new EthernetSwitch();
              break;
          case 1:
              mixed_array[i] = new WirelessRouter();
              break;
          case 2:
              mixed_array[i] = new PacketSwitch();
              break;
          default:
              std::cout << "ERROR : In array please initialize!" << std::endl;
              return -1;
       }
     }
   return 0;
}

// Display Packet Switch Menu
int print_menu()
{
   cout << "/*************************************************************/\n"
           "/*************************** MENU ****************************/\n"
           "/*************************************************************/\n"
           "/*                                                           */\n"
           "/*              0 - 19: Ethernet Switch Objects              */\n"
           "/*             20 - 39: Wireless Router Objects              */\n"
           "/*             40 - 59: Packet Switch Objects                */\n"
           "/*    --------------------------------------------------     */\n"
           "/*     *  : Display Data For All Objects                     */\n"
		   "/*     !  : Display Available Networks                       */\n"
           "/*     B  : Display Program Memory Usage                     */\n"
           "/*     +/-: Succeeding / Preceding Object                    */\n"
           "/*     #  : Set The Selected Object                          */\n"
           "/*     0  : Clear The Selected Object's Data                 */\n"
           "/*     >  : Create A New Network                             */\n"
           "/*     I  : Set The Network Index For The Current Obect      */\n"
           "/*     D  : Display The Selected Object's Data               */\n"
           "/*     V  : Set Packet Switch Vendor                         */\n"
           "/*     M  : Set Packet Switch Model                          */\n"
           "/*     N  : Set Packet Switch Number of Ports                */\n"
           "/*     T  : Set Packet Switch Per Port Speed                 */\n"
           "/*     E  : Set Packet Switch Power Consumption              */\n"
           "/*     S  : Set Packet Switch Dimensions [H W D]             */\n"
           "/*     R  : Set The Rating Of The Ethernet Switch            */\n"
           "/*     W  : Set The IEEE Standard Of The Wireless Router     */\n"
           "/*     X  : Set The Data Rate Of The Wireless Router         */\n"
           "/*     F  : Set Packet Size For Ethernet Or Wireless         */\n"
           "/*     A  : Display Ethernet Switches Sorted By Rating       */\n"
           "/*     P  : Print This Menu                                  */\n"
           "/*     Q  : Quit This Program                                */\n"
           "/*                                                           */\n"
           "/*************************************************************/\n";
   return 0;
}

// Execute Packet Switch Menu Process
int process_menu_in(string menu_line)
{
   // Determine Interactive Process or Test File Process
   char menuchar;
   istringstream in_string(menu_line);
   in_string >> menuchar;
   istream *in_stream;

   // Execute Interactive Stream Process, Else Execute Test File Stream Process
   if (interactive)
     in_stream = &cin;
   else
     in_stream = &in_string;

   // Execute Switch Process
   switch(toupper(menuchar))
   {
      // Display All Modified Objects
      case '*':
      {
        cout << "\n\n=== Packet Switches ===\n";
        for(int z = 0; z < ARR_MAX; z++)
        {
          if( z >= 0 && z <= 19 && static_cast<EthernetSwitch*>(pswitch_array[z])->isempty() == 0)
          {
            cout << "EtherenetSwitch Print[" << z << "]" <<endl;
            cout << *(static_cast<EthernetSwitch*>(pswitch_array[z]));
          }

          else if( z >= 20 && z <= 39 && static_cast<WirelessRouter*>(pswitch_array[z])->isempty() == 0)
          {
            cout << "WirelessRouter Print[" << z << "]" <<endl;
            cout << *(static_cast<WirelessRouter*>(pswitch_array[z]));
          }

          else if( z >= 40 && z <= 59 && (pswitch_array[z])->isempty() == 0)
          {
            cout << "Packeswitch print[" << z << "]" <<endl;
            cout << *(static_cast<PacketSwitch*>(pswitch_array[z]));
          }
        }
      }
      break;

	  // Display Available Networks or Advice There is None.
	  case '!':
      {
        cout << "\n\n=== Available Networks ===\n";
		int net_empty = 0;
        for(int z = 0; z < max_network; z++)
        {
          if(z >= 0 && z <= 59 && (&network_array[z])->isempty() == 0)
          {
            cout << "\nNetwork Index Number [" << z << "]" <<endl;
            cout << network_array[z];
			net_empty = 1;
          }

		  else if(net_empty == 0 && z == 59)
		  {
			cout << "\nNo Newtworks Defined\n\nPlease Create a New Network" <<endl;
		  }
        }
      }
      break;

      // Display Program Memory Usage
      case 'B':
	    //packetswitch.cpp
        (*cur_pswitch)->display_mem_usage();
      break;

      // Select Succeeding Obect
	  // ***BUG*** able to exit scope of available memory space.
      case '+':
      {
       int i = 0;
       i++;
       cur_pswitch = &cur_pswitch[i];
       cout << "Index set to " << (cur_pswitch - pswitch_array) << endl;
      }
      break;

      // Select Preceding Obect
	  // ***BUG*** able to exit scope of available memory space.
      case '-':
      {
       int i = 0;
       i--;
       cur_pswitch = &cur_pswitch[i];
       cout << "Index set to " << (cur_pswitch - pswitch_array) << endl;
      }
      break;

      // Create Network Set Label, IP Address, and Size
	  // ***BUG*** network label gets cut off on first space
      case '>':
      {
        string new_label, new_ip_address;
        int new_num_nodes;
        cout << "Enter Network Information\n";
        cout << "\nEnter Network Label: ";
        (*in_stream) >> new_label;
        cur_network->set_label(new_label);
        cout << "\nEnter Network IP Address: ";
        (*in_stream) >> new_ip_address;
        cur_network->set_ip_address(new_ip_address);
        cout << "\nEnter Network Number Nodes: ";
        (*in_stream) >> new_num_nodes;
        if(interactive)cin.get();
        cur_network->set_num_nodes(new_num_nodes);
        cur_network++;
      }
        break;

      // Set network to current object
	  // ***ADD*** a display for user to use with available networks.
      case 'I':
      {
       int i;
       cout << "Select Network Index: ";
       (*in_stream) >> i;
       if(interactive)cin.get();
	   (*cur_pswitch)->set_network_ptr(&network_array[i]);
       cout << "Network Index for Current Packet Switch To:" << (cur_network - network_array) << endl;
	   cin.get();
      }
      break;

      // Select Packet Switch Number
      case '#':
      {
       int i = 0;
       cout << "Select a Packet Swith number: ";
       (*in_stream) >> i;
       if(interactive)cin.get();
       cur_pswitch = (pswitch_array +i);
       cout << "Index set to " << (cur_pswitch - pswitch_array) << endl;
      }
      break;

      //Set Packet Switch Data to Blank
      case '0':
        (*cur_pswitch)->set_blank();
      break;

      // Display Current Packet Switch Data
      case 'D':
      {
        int i;
        i = cur_pswitch - mixed_array;
        cout << "Packet Switch [" << i << "]" << endl;
        if(i >= 0 && i <= 19)
        {
          cout << *(static_cast<EthernetSwitch*>(*cur_pswitch));
        }
        else if(i >= 20 && i <= 40)
        {
          cout << *(static_cast<WirelessRouter*>(*cur_pswitch));
        }
        else if(i >= 40 && i <= 60)
        {
          cout << *(*cur_pswitch);
        }
      }
        break;

      // Set Packet Switch Vendor
      case 'V':
      {
        string new_vendor;
        cout << "Enter Switch Vendor: ";
        (*in_stream) >> new_vendor;
        if(interactive)cin.get();
        (*cur_pswitch)->set_vendor(new_vendor);
      }
        break;

      // Set Packet Switch Model
      case 'M':
      {
        string new_model;
        cout << "Enter Switch Model: ";
        (*in_stream) >> new_model;
		if(interactive)cin.get();
        (*cur_pswitch)->set_model(new_model);
      }
        break;

      // Set Packet Switch Number of Ports
      case 'N':
      {
        int new_num_ports;
        cout << "Enter Number of Ports in the Switch: ";
        (*in_stream) >> new_num_ports;
        if(interactive)cin.get();
        (*cur_pswitch)->set_num_ports(new_num_ports);
      }
        break;

      // Set Packet Switch Per Port Speed
      case 'T':
      {
        double new_pps;
        cout << "Enter Per Port Speed in the Switch: ";
        (*in_stream) >> new_pps;
        if(interactive)cin.get();
        (*cur_pswitch)->set_pps(new_pps);
      }
        break;

      // Set Packet Switch Power Cosumption
      case 'E':
      {
        double new_power;
        cout << "Enter Power Consumption of the Switch: ";
        (*in_stream) >> new_power;
        if(interactive)cin.get();
        (*cur_pswitch)->set_power(new_power);
      }
        break;

      // Set Packet Switch Dimensions
      case 'S':
      {
        float new_height, new_width, new_depth;
        cout << "Enter Dimensions:";
        (*in_stream) >> new_height;
        (*in_stream) >> new_width;
        (*in_stream) >> new_depth;
        if(interactive)cin.get();
        (*cur_pswitch)->set_dimensions(new_height, new_width, new_depth);
      }
        break;

      //Set Rating
      case 'R':
      {
        int new_rating;
        cout << "Enter Rating of Ethernet Switch: ";
        (*in_stream) >> new_rating;
        if(interactive)cin.get();
        (*(static_cast<EthernetSwitch*>(*cur_pswitch))).set_rating(new_rating);
      }
        break;

	  //Set IEEE Satadard
      case 'W':
      {
        string new_ieee_std;
        cout << "Enter IEEE Standard of the Wireless Router: ";
        (*in_stream) >> new_ieee_std;
        if(interactive)cin.get();
        (*(static_cast<WirelessRouter*>(*cur_pswitch))).set_ieee_std(new_ieee_std);
      }
        break;

      // Set Data Rate
      case 'X':
      {
        double new_data_rate;
        cout << "Enter Data Rate of the Wireless Router: ";
        (*in_stream) >> new_data_rate;
        if(interactive)cin.get();
        (*(static_cast<WirelessRouter*>(*cur_pswitch))).set_data_rate(new_data_rate);
      }
        break;

      // Set Packet Size
      case 'F':
      {
        int index = cur_pswitch - pswitch_array;
        int new_packet_size;
        cout << "Enter Packet Size for Ethernet Switch or Wireless Router: ";
        (*in_stream) >> new_packet_size;
        if(interactive)cin.get();
        if(index >= 0 && index <= 19)
        {
          static_cast<EthernetSwitch*>(*cur_pswitch)->set_packet_size(new_packet_size);
        }
        else if(index >= 20 && index <= 39)
        {
          static_cast<WirelessRouter*>(*cur_pswitch)->set_packet_size(new_packet_size);
        }
      }
        break;

      // Ethernet Switches by Order
      case 'A':
      {
        cout << "\n\n=== Ethernet Switches in Order ===\n";
        int rc;
        int ec;
        for(rc = 0; rc <= 10; rc++)
        {
          for(ec = 0; ec < 20; ec++)
          {
            if(static_cast<EthernetSwitch*>(pswitch_array[ec])->get_rating() == rc && static_cast<EthernetSwitch*>(pswitch_array[ec])->isempty() == 0)
            {
              cout << *(static_cast<EthernetSwitch*>(pswitch_array[ec])) << endl;
            }
          }
        }
      }
      break;

      // Display Packet Switch Menu
      case 'P':
        print_menu();
        break;

      // Terminate Packet Switch Program
      case 'Q':
        done = true;
        break;
   }
  return 0;
}

// End of Main Function
