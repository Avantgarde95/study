CC=clang++

build:
	mkdir -p out
	$(CC) SmartPointers.cpp -o out/SmartPointers
	$(CC) VirtualFunction.cpp -o out/VirtualFunction
	$(CC) VirtualDestructor.cpp -o out/VirtualDestructor

clean:
	rm -r out

