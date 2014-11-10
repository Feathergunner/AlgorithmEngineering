CXX = g++
CXXFLAGS = -Wall -O -I/usr/local/include
LDFLAGS = /usr/lib/libgtest.a -pthread

SOURCE_MAIN = src/Fibonacci_main.cpp
SOURCE_TEST_MAT = tests/IntMatrix_test.cpp 
SOURCE_TEST_FIB = tests/Fibonacci_test.cpp
SOURCE_TEST_FAIL = tests/Fibonacci_failedTests.cpp

# is there a more practical way of defining all these OBJECTS_* -sets?
OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS_TEST_MAT = $(SOURCE_TEST_MAT:.cpp=.o)
OBJECTS_TEST_FIB = $(SOURCE_TEST_FIB:.cpp=.o)
OBJECTS_TEST_FAIL = $(SOURCE_TEST_FAIL:.cpp=.o)
ALLOBJECTS = $(OBJECTS) $(OBJECTS_TEST_MAT) $(OBJECTS_TEST_FIB) $(OBJECTS_TEST_FAIL)

EXECUTABLE = Fibonacci
EXECUTABLE_TEST_MAT = IntMatrix_test
EXECUTABLE_TEST_FIB = Fibonacci_test
EXECUTABLE_TEST_FAIL = Fibonacci_fail
ALLEXES = $(EXECUTABLE) $(EXECUTABLE_TEST_MAT) $(EXECUTABLE_TEST_FIB) $(EXECUTABLE_TEST_FAIL)

.PHONY: all
all: build
	
# builds algorithms
.PHONY: build
build: $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(CXXFLAGS) -o $(EXECUTABLE)

# builds and executes tests:
.PHONY: test_all
test_all: test_mat test_fib test_fail
	
.PHONY: test_mat
test_mat: $(OBJECTS_TEST_MAT)
	$(CXX) $(OBJECTS_TEST_MAT) $(LDFLAGS) $(CXXFLAGS) -o $(EXECUTABLE_TEST_MAT)
	./$(EXECUTABLE_TEST_MAT)

.PHONY: test_fib
test_fib: $(OBJECTS_TEST_FIB)
	$(CXX) $(OBJECTS_TEST_FIB) $(LDFLAGS) $(CXXFLAGS) -o $(EXECUTABLE_TEST_FIB)
	./$(EXECUTABLE_TEST_FIB)
	
.PHONY: test_fail
test_fail: $(OBJECTS_TEST_FAIL)
	$(CXX) $(OBJECTS_TEST_FAIL) $(LDFLAGS) $(CXXFLAGS) -o $(EXECUTABLE_TEST_FAIL)
	./$(EXECUTABLE_TEST_FAIL)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -f $(ALLOBJECTS) $(ALLEXES)

