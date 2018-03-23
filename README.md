# SE420 Group Project - Group 3

Contained in this repository is the source code of the final project in SE420 - Software Quality Assurance (Spring 2018).
The purpose of using GitHub is to gain experience with a CMVC system by tracking changes, issues, etc. as work is done to
improve the original code.

The source code uses the C++ Language and is compiled with the C++11 standard.

## About The Program

The project is meant to build on already existing code from previous coursework done in CS225 (C++). This code was written
to store details about packet switching hardware used in networks. The details are entered by a user via a command line
interface (CLI).

The scope of this project focuses on adding features to simulate packet switching networks using stored hardware components.
The project also includes the addition of simulated packet data. However, at this time, implementing the transmission/transfer
of the packet data from one packet switch object to another is outside the scope of the project, but features may be added
as time allows.

## Usage

Use `make` to build the code. A makefile is included in this repository which is used to compile the code.

Use `./PSP.exe` to run the program once it has been built/compiled. When the program starts, a menu is displayed allowing the
user to choose from various options. The menu is as follows:

```
   Packet Switch Selection Menu:
   0 - 19: Ethernet Switches
   20 - 39: Wireless Routers
   40 - 60: Packet Switches
   * - Display Data for All Active Packet Switches
   B - Display Program Memory Usage
   +/- Succeeding / Preceding Packet Switch Object Within Array
   # - Set the Selected Packet Switch
   0 - Clear Selected Packet Switch Data
   > - Create a New Network
   I - Set the Network Index for Packet Sitch
   D - Display Packet Switch Data
   V - Set Packet Switch Vendor
   M - Set Packet Switch Model
   N - Set the Number of Ports in the Packet Switch
   T - Set Per Port Speed of the Packet Switch
   E - Set Power Consumption of the Packet Switch
   S - Set Dimensions of the Packet Switch
   C - Add Packet Swithc Component
   R - Set the Rating of the Ethernet Switch
   W - Set the IEEE standart of the Wireless Router
   X - Set the Data Rate of the Wireless Routher
   F - Set Packet Size fo the Ethernet Switch or Wireless Router
   A - Display Ehternet Switches Sorted by their Rating
   P - Print this Menu
   Q - Quit this Program
```

Use `./PSP.exe < test#.in` to run the program with a test script.
