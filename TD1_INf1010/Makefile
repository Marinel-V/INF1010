# Makefile for compiling and running the hospital management system
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Executable name
EXEC = main_program

# Source files
SRCS = Main.cpp \
       Specialite.cpp \
       Medecin.cpp \
       Infirmier.cpp \
       HopitalPoly.cpp \
       TestSuite.cpp

# Header files
HEADERS = Const.h \
          Specialite.h \
          Medecin.h \
          Infirmier.h \
          HopitalPoly.h \
          TestSuite.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the executable
all: $(EXEC)

# Rule to link object files and create the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Rule to compile .cpp files to .o object files
# Each .o file depends on its .cpp file and corresponding .h file
Main.o: Main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

# Clean up generated object and executable files
clean:
	rm -f $(OBJS) $(EXEC)

# Rule to run the program after building
run: $(EXEC)
	./$(EXEC)

# Declare phony targets
.PHONY: all clean run