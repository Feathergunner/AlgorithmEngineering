CXX = g++
CXXFLAGS = -Wall -O
LDFLAGS = -I/usr/local/include /usr/lib/libgtest.a -pthread
SOURCES = Ex02-Fibonacci.cpp
MAINSOURCES = Ex02-Fibonacci_main.cpp
TESTSOURCES = Ex02-Fibonacci_test.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TESTOBJECTS = $(TESTSOURCES:.cpp=.o)
MAINOBJECTS = $(MAINSOURCES:.cpp=.o)
EXECUTABLE = Ex02-Fibonacci
EXECUTABLE_TEST = Ex02-Fibonacci_test

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

