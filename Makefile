CC=clang++
CFLAGS=-g
OUT=out

build:
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) SmartPointers.cpp -o $(OUT)/SmartPointers
	$(CC) $(CFLAGS) VirtualFunction.cpp -o $(OUT)/VirtualFunction
	$(CC) $(CFLAGS) VirtualDestructor.cpp -o $(OUT)/VirtualDestructor
	$(CC) $(CFLAGS) Tree.cpp -o $(OUT)/Tree
	$(CC) $(CFLAGS) WeakPointer.cpp -o $(OUT)/WeakPointer

clean:
	rm -r $(OUT)
