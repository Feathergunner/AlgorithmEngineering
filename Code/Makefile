CXX = g++
CXXFLAGS = -std=c++0x -Wall -O -c
CXXFLAGS_GTEST = -I/usr/local/include
LDFLAGS = /usr/lib/libgtest.a -pthread

OBJDIR = objects/

$(OBJDIR)IntMatrix.o: src/IntMatrix.cpp include/IntMatrix.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) src/IntMatrix.cpp -o $@

$(OBJDIR)IntMatrix_test.o: src/test/IntMatrix_test.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) src/test/IntMatrix_test.cpp -o $@

test_IntMatrix: $(OBJDIR)IntMatrix.o $(OBJDIR)IntMatrix_test.o
	$(CXX) -o Test_IntMatrix $^ $(LDFLAGS)
	./Test_IntMatrix
	
$(OBJDIR)Fibonacci.o: src/Fibonacci.cpp include/Fibonacci.h
	$(CXX) $(CXXFLAGS) src/Fibonacci.cpp -o $@
	
$(OBJDIR)test_Fibonacci.o: src/test/Fibonacci_test.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) src/test/Fibonacci_test.cpp -o $@

test_Fibonacci: $(OBJDIR)IntMatrix.o $(OBJDIR)Fibonacci.o $(OBJDIR)test_Fibonacci.o 
	$(CXX) -o Test_Fibonacci $^ $(LDFLAGS)
	./Test_Fibonacci
	
$(OBJDIR)test_fail_Fibonacci.o: src/test/Fibonacci_failedTests.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_GTEST) src/test/Fibonacci_failedTests.cpp -o $@

test_fail_Fibonacci: $(OBJDIR)IntMatrix.o $(OBJDIR)Fibonacci.o $(OBJDIR)test_fail_Fibonacci.o
	$(CXX) -o Test_fail_Fibonacci $^ $(LDFLAGS)
	./Test_fail_Fibonacci
	
tests: test_IntMatrix test_Fibonacci test_fail_Fibonacci
	
$(OBJDIR)main_fib.o: Fibonacci_main.cpp
	$(CXX) $(CXXFLAGS) Fibonacci_main.cpp -o $@
	
main_fib: $(OBJDIR)main_fib.o $(OBJDIR)IntMatrix.o $(OBJDIR)Fibonacci.o
	$(CXX) -o FibMain $^ $(LDFLAGS)
	
$(OBJDIR)StopWatch.o: src/measure/StopWatch.cpp include/measure/StopWatch.h
	$(CXX) $(CXXFLAGS) src/measure/StopWatch.cpp -o $@

$(OBJDIR)Meter.o: src/measure/Meter.cpp include/measure/Meter.h
	$(CXX) $(CXXFLAGS) src/measure/Meter.cpp -o $@

$(OBJDIR)Measure_fib.o: src/measure/Measure_Fib.cpp
	$(CXX) $(CXXFLAGS) src/measure/Measure_Fib.cpp -o $@

Measure_Fib: $(OBJDIR)IntMatrix.o $(OBJDIR)Fibonacci.o $(OBJDIR)StopWatch.o $(OBJDIR)Meter.o $(OBJDIR)Measure_fib.o
	$(CXX) -o Measure_Fib $^ $(LDFLAGS)

# Removes all objects and executables:
.PHONY: clean
clean:
	rm -r objects/*

