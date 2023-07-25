CPPFLAGS=-std=c++17 -Wall -Wextra
main: main.cpp loc.cpp map.cpp save.cpp colors.hpp loc_data.hpp stat.hpp names.cpp door.cpp

# Compiler flags \
CPPFLAGS = -std=gnu++17 -Wall -Wextra /usr/lib/libintl.dll.a -liconv

# List of source files \
SOURCES = main.cpp loc.cpp map.cpp save.cpp names.cpp door.cpp

# Generate object file names from source files (replace .cpp with .o) \
OBJECTS = $(SOURCES:.cpp=.o)

# Target to build the executable 'main' \
main: $(OBJECTS) \
	gcc $(CPPFLAGS) $(OBJECTS) -o main

# Rule to compile each source file to its object file \
%.o: %.cpp \
	gcc $(CPPFLAGS) -o $@

# Clean up object files and executable \
clean: \
	rm -f $(OBJECTS) main
