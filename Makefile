compile-command = g++ ./src/$@.cpp -c -o ./src/$@.o

build:
	echo $(BASEDEPS)

prepare:
	cp include/* tests
	cp include/* src

compile:
	cd src && g++ *.cpp -c

%.cpp:
	g++ src/$@ -c -o src/$*.o

%.test: %.cpp
	g++ tests/$@.cpp src/*.o -o tests/$@
	./tests/$@

utils:
	$(compile-command)

clean:
	rm src/*.h || true
	rm tests/*.h || true
	rm *.o */*.o || true