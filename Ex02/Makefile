CXX = g++
CXXFLAGS = -Wall -O -I/usr/local/include
LDFLAGS = /usr/lib/libgtest.a -pthread
SOURCES = src/Fibonacci.cpp
MAINSOURCES = src/Fibonacci_main.cpp
TESTSOURCES = src/Fibonacci_test.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TESTOBJECTS = $(TESTSOURCES:.cpp=.o)
MAINOBJECTS = $(MAINSOURCES:.cpp=.o)
EXECUTABLE = Fibonacci
EXECUTABLE_TEST = Fibonacci_test

.PHONY: all
all: build
	
# builds algorithms
.PHONY: build
build: $(MAINOBJECTS)
	$(CXX) $(MAINOBJECTS) $(CXXFLAGS) -o $(EXECUTABLE)

# builds and executes tests:
.PHONY: tests
tests: $(TESTOBJECTS)
	$(CXX) $(TESTOBJECTS) $(LDFLAGS) $(CXXFLAGS) -o $(EXECUTABLE_TEST)
	./$(EXECUTABLE_TEST)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TESTOBJECTS) $(MAINOBJECTS) $(EXECUTABLE) $(EXECUTABLE_TEST)

