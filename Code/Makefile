CXX = g++
CXXFLAGS = -std=c++0x -Wall -O -I/usr/local/include
LDFLAGS = /usr/lib/libgtest.a -pthread

SOURCES = src/Fibonacci.cpp src/IntMatrix.cpp src/measure/StopWatch.cpp src/measure/Meter.cpp
SRC_MAIN = src/Fibonacci_main.cpp
SRC_TEST_FIB = src/test/Fibonacci_test.cpp
SRC_TEST_FIB_FAIL = src/test/Fibonacci_failedTests.cpp
SRC_TEST_INTMAT = src/test/IntMatrix_test.cpp
SRC_MEASURE_FIB = src/measure/Measure_Fib.cpp

OBJ_MAIN = $(SRC_MAIN:.cpp=.o)
OBJ_TEST_FIB = $(SRC_TEST_FIB:.cpp=.o)
OBJ_TEST_FIB_FAIL = $(SRC_TEST_FIB_FAIL:.cpp=.o)
OBJ_TEST_INTMAT = $(SRC_TEST_INTMAT:.cpp=.o)
OBJ_MEASURE_FIB = $(SRC_MEASURE_FIB:.cpp=.o)
OBJ_OTHER = $(SOURCES:.cpp=.o)
ALLOBJECTS = $(OBJ_OTHER) $(OBJ_MAIN) $(OBJ_TEST_FIB) $(OBJ_TEST_FIB_FAIL) $(OBJ_TEST_INTMAT) $(OBJ_MEASURE_FIB)

EXECUTABLE = Main
EXE_TEST_FIB = TestFib
EXE_TEST_FIB_FAIL = TestFibFail
EXE_TEST_INTMAT = TestIntMat
EXE_MEASURE_FIB = MeasureFib
ALLEXES = $(EXECUTEABLE) $(EXE_TEST_FIB) $(EXE_TEST_FIB_FAIL) $(EXE_TEST_INTMAT) $(EXE_MEASURE_FIB)

.PHONY: all
all: build
	
# builds algorithms
.PHONY: build
build: $(OBJ_MAIN) $(OBJ_OTHER)
	$(CXX) $(OBJ_MAIN) $(LDFLAGS) $(CXXFLAGS) -o $(EXECUTABLE)

# builds and executes tests:
.PHONY: test_all
test_all: test_mat test_fib test_fib_fail

# tests the IntMatrix
.PHONY: test_mat
test_mat: $(OBJ_TEST_INTMAT) $(OBJ_OTHER)
	$(CXX) $(OBJ_TEST_INTMAT) $(LDFLAGS) $(CXXFLAGS) -o $(EXE_TEST_INTMAT)
	./$(EXE_TEST_INTMAT)

# tests Fibonacci
.PHONY: test_fib
test_fib: $(OBJ_TEST_FIB) $(OBJ_OTHER)
	$(CXX) $(OBJ_TEST_FIB) $(LDFLAGS) $(CXXFLAGS) -o $(EXE_TEST_FIB)
	./$(EXE_TEST_FIB)

# failed tests for Fibonacci
.PHONY: test_fib_fail
test_fib_fail: $(OBJ_TEST_FIB_FAIL) $(OBJ_OTHER)
	$(CXX) $(OBJ_TEST_FIB_FAIL) $(LDFLAGS) $(CXXFLAGS) -o $(EXE_TEST_FIB_FAIL)
	./$(EXE_TEST_FIB_FAIL)

# builds and executes measurements:
# measures Fibonacci
.PHONY: measurefib
measure: $(OBJ_MEASURE_FIB) $(OBJ_OTHER)
	$(CXX) $(OBJ_MEASURE_FIB) $(LDFLAGS) $(CXXFLAGS) -o $(EXE_MEASURE_FIB)
	./$(EXE_MEASURE_FIB)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -f $(ALLOBJECTS) $(ALLEXES)

