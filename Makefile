compile-command = g++ ./src/$@.cpp -c -o ./src/$@.o
CXXFLAGS = -std=c++17

build:
	echo $(BASEDEPS)

prepare:
	cp include/* tests
	cp include/* src

compile:
	cd src && g++ $(CXXFLAGS) *.cpp -c

%.cpp:
	g++ $(CXXFLAGS) src/$@ -c -o src/$*.o

%.test: %.cpp
	g++ tests/$@.cpp src/*.o -o tests/$@
	./tests/$@

clean:
	rm src/*.h || true
	rm tests/*.h || true
	rm *.o */*.o || true