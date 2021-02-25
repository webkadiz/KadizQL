compile-command = g++ ./src/$@.cpp -c -o ./src/$@.o
CXXFLAGS = -std=c++17 -Wall


prepare:
	cp include/* tests
	cp include/* src

compile:
	cd src && g++ $(CXXFLAGS) *.cpp -c

%.cpp:
	g++ $(CXXFLAGS) src/$@ -c -o src/$*.o

%.test: %.cpp
	g++ $(CXXFLAGS) tests/$@.cpp src/*.o -o tests/$@
	./tests/$@

clean:
	rm tests/*.test
	rm *.o */*.o || true