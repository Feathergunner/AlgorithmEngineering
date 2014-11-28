CXX = g++
CXXFLAGS = -std=c++0x -Wall -O -c
INCLUDES = -Iinclude
CXXFLAGS_GTEST = -I/usr/local/include
LDFLAGS = /usr/lib/libgtest.a -pthread

OBJDIR = objects/

## IntMatrix
$(OBJDIR)IntMatrix.o: src/IntMatrix.cpp include/IntMatrix.h
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXFLAGS_GTEST) src/IntMatrix.cpp -o $@

$(OBJDIR)IntMatrix_test.o: src/test/IntMatrix_test.cpp
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXFLAGS_GTEST) src/test/IntMatrix_test.cpp -o $@

test_IntMatrix: $(OBJDIR)IntMatrix.o $(OBJDIR)IntMatrix_test.o
	$(CXX) -o Test_IntMatrix $^ $(LDFLAGS)
	./Test_IntMatrix

## Fibonacci
$(OBJDIR)Fibonacci.o: src/Fibonacci.cpp include/Fibonacci.h
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/Fibonacci.cpp -o $@
	
$(OBJDIR)main_fib.o: Fibonacci_main.cpp
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) Fibonacci_main.cpp -o $@
	
main_fib: $(OBJDIR)main_fib.o $(OBJDIR)IntMatrix.o $(OBJDIR)Fibonacci.o
	$(CXX) -o FibMain $^ $(LDFLAGS)
	
$(OBJDIR)test_Fibonacci.o: src/test/Fibonacci_test.cpp
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXFLAGS_GTEST) src/test/Fibonacci_test.cpp -o $@

test_Fibonacci: $(OBJDIR)IntMatrix.o $(OBJDIR)Fibonacci.o $(OBJDIR)test_Fibonacci.o 
	$(CXX) -o Test_Fibonacci $^ $(LDFLAGS)
	./Test_Fibonacci
	
$(OBJDIR)test_fail_Fibonacci.o: src/test/Fibonacci_failedTests.cpp
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXFLAGS_GTEST) src/test/Fibonacci_failedTests.cpp -o $@

test_fail_Fibonacci: $(OBJDIR)IntMatrix.o $(OBJDIR)Fibonacci.o $(OBJDIR)test_fail_Fibonacci.o
	$(CXX) -o Test_fail_Fibonacci $^ $(LDFLAGS)
	./Test_fail_Fibonacci

## StopWatch and Meter
$(OBJDIR)StopWatch.o: src/measure/StopWatch.cpp include/measure/StopWatch.h
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/measure/StopWatch.cpp -o $@

$(OBJDIR)Meter.o: $(OBJDIR) src/measure/Meter.cpp include/measure/Meter.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/measure/Meter.cpp -o $@

## Measure Fib:
$(OBJDIR)Measure_fib.o: src/measure/Measure_Fib.cpp
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/measure/Measure_Fib.cpp -o $@

Measure_Fib: $(OBJDIR)IntMatrix.o $(OBJDIR)Fibonacci.o $(OBJDIR)StopWatch.o $(OBJDIR)Meter.o $(OBJDIR)Measure_fib.o
	mkdir measurements -p
	$(CXX) -o Measure_Fib $^ $(LDFLAGS)

## Sort
$(OBJDIR)Sort.o: src/Sort.cpp include/Sort.h
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/Sort.cpp -o $@
	
$(OBJDIR)main_sort.o: Sort_main.cpp
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) Sort_main.cpp -o $@
	
main_sort: $(OBJDIR)Sort.o $(OBJDIR)main_sort.o
	$(CXX) -o SortMain $^ $(LDFLAGS)
	
$(OBJDIR)test_Sort.o: src/test/Sort_test.cpp include/Sort_test.h
	mkdir $(OBJDIR) -p
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXFLAGS_GTEST) src/test/Sort_test.cpp -o $@
	
test_Sort: $(OBJDIR)test_Sort.o $(OBJDIR)Sort.o
	$(CXX) -o Test_Sort $^ $(LDFLAGS)
	./Test_Sort

## all tests:
tests: test_IntMatrix test_Fibonacci test_fail_Fibonacci test_Sort

## build everything:
all: main_fib main_sort tests

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -r objects/*

