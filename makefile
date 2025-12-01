compile: main.cpp
	g++ main.cpp -o testQ

run: testQ
	./testQ 1 2 3 2 x 3 2 x

clean:
	rm testQ