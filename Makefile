CXX = g++

prog1 : main2.o matrix.o
	$(CXX) main2.o matrix.o -o prog1

main1.o: main2.cpp matrix.h
	$(CXX) -c main2.cpp

matrix.o: matrix.cpp matrix.h
	$(CXX) -c matrix.cpp

clean:
	rm *.o prog*
