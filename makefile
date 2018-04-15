# CS225
# Packet Switch and Other Related Classes
# Here is a simple Make Macro.
LINK_TARGET = PSP.exe

# Here is a Make Macro that uses the backslash to extend to multiple lines.
OBJS =  \
	pswitch_main.o \
	packetswitch.o \
  network.o \
  ethernetswitch.o \
  wirelessrouter.o \

# Here is a Make Macro defined by two Macro Expansions.
# A Macro Expansion may be treated as a textual replacement of the Make Macro.
# Macro Expansions are introduced with $ and enclosed in (parentheses).
REBUILDABLES = $(OBJS) $(LINK_TARGET)

# The rule for "all" is used to incrementally build your system.
# It does this by expressing a dependency on the results of that system,
# which in turn have their own rules and dependencies.
all : $(LINK_TARGET)
	echo All done

# Here is a simple Rule (used for "cleaning" your build environment).
# It has a Target named "clean" (left of the colon ":" on the first line),
# no Dependencies (right of the colon),
# and two Commands (indented by tabs on the lines that follow).
# The space before the colon is not required but added here for clarity.
clean :
	rm -f $(REBUILDABLES)
	echo Clean done

# There are two standard Targets your Makefile should probably have:
# "all" and "clean", because they are often command-line Goals.
# Also, these are both typically Artificial Targets, because they don't typically
# correspond to real files named "all" or "clean".

# There is no required order to the list of rules as they appear in the Makefile.
# Make will build its own dependency tree and only execute each rule only once
# its dependencies' rules have been executed successfully.

# Here is a Rule that uses some built-in Make Macros in its command:
# $@ expands to the rule's target, in this case "test_me.exe".
# $^ expands to the rule's dependencies, in this case the three files
# main.o, test1.o, and  test2.o.
$(LINK_TARGET) : $(OBJS)
	g++ -g -Wall -o $@ $^

# Here is a Pattern Rule, often used for compile-line.
# It says how to create a file with a .o suffix, given a file with a .cpp suffix.
# The rule's command uses some built-in Make Macros:
# $@ for the pattern-matched target
# $< for the pattern-matched dependency
# -std=c++11 useful in cygwin
# -Wall good to display all warnings
%.o : %.cpp
	g++ -g -Wall -o $@ -c $< #-std=c++11

# These are Dependency Rules, which are rules without any command.
# Dependency Rules indicate that if any file to the right of the colon changes,
# the target to the left of the colon should be considered out-of-date.
# The commands for making an out-of-date target up-to-date may be found elsewhere
# (in this case, by the Pattern Rule above).
# Dependency Rules are often used to capture header file dependencies.
GP5_main.o : GP5devices.hpp GP5computer.hpp GP5printer.hpp GP5network.hpp
GP5devices.o : GP5devices.hpp GP5network.hpp
GP5computer.o : GP5computer.hpp GP5devices.hpp
GP5printer.o : GP5printer.hpp GP5devices.hpp
GP5network.o : GP5network.hpp

pswitch_main.o : packetswitch.hpp network.hpp ethernetswitch.hpp wirelessrouter.hpp
ethernetswitch.o : ethernetswitch.hpp
network.o : network.hpp
packetswitch.o : packetswitch.hpp
wirelessrouter.o : wirelessrouter.hpp
