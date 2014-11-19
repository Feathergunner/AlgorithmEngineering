CXX = g++
CXXFLAGS = -std=c++0x -Wall -O -c
CXXFLAGS_GTEST = -I/usr/local/include
LDFLAGS = /usr/lib/libgtest.a -pthread

IntMatrix.o: src/IntMatrix.cpp include/IntMatrix.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) src/IntMatrix.cpp

test_IntMatrix.o: src/test/IntMatrix_test.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) src/test/IntMatrix_test.cpp

test_IntMatrix: IntMatrix.o test_IntMatrix.o
	$(CXX) -o Test_IntMatrix IntMatrix.o IntMatrix_test.o $(LDFLAGS)
	./Test_IntMatrix
	
Fibonacci.o: src/Fibonacci.cpp include/Fibonacci.h
	$(CXX) $(CXXFLAGS) src/Fibonacci.cpp
	
test_Fibonacci.o: src/test/Fibonacci_test.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) src/test/Fibonacci_test.cpp

test_Fibonacci: IntMatrix.o Fibonacci.o test_Fibonacci.o 
	$(CXX) -o Test_Fibonacci IntMatrix.o Fibonacci.o Fibonacci_test.o $(LDFLAGS)
	./Test_Fibonacci
	
test_fail_Fibonacci.o: src/test/Fibonacci_failedTests.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) src/test/Fibonacci_failedTests.cpp

test_fail_Fibonacci: IntMatrix.o Fibonacci.o test_fail_Fibonacci.o
	$(CXX) -o Test_fail_Fibonacci IntMatrix.o Fibonacci.o Fibonacci_failedTests.o $(LDFLAGS)
	./Test_fail_Fibonacci
	
tests: test_IntMatrix test_Fibonacci test_fail_Fibonacci
	
main_fib.o: Fibonacci_main.cpp
	$(CXX) $(CXXFLAGS) Fibonacci_main.cpp
	
main_fib: main_fib.o IntMatrix.o Fibonacci.o
	$(CXX) -o FibMain Fibonacci_main.o IntMatrix.o Fibonacci.o $(LDFLAGS)
	
StopWatch.o: src/measure/StopWatch.cpp include/measure/StopWatch.h
	$(CXX) $(CXXFLAGS) src/measure/StopWatch.cpp

Meter.o: src/measure/Meter.cpp include/measure/Meter.h
	$(CXX) $(CXXFLAGS) src/measure/Meter.cpp

Measure_fib.o: src/measure/Measure_Fib.cpp
	$(CXX) $(CXXFLAGS) src/measure/Measure_Fib.cpp

Measure_Fib: IntMatrix.o Fibonacci.o StopWatch.o Meter.o Measure_fib.o
	$(CXX) -o Measure_Fib IntMatrix.o Fibonacci.o StopWatch.o Meter.o Measure_Fib.o $(LDFLAGS)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -f *.o

