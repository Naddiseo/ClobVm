CXXFLAGS+=-std=c++0x -I.
all:
	$(CXX) $(CXXFLAGS) -o main.bin *.cpp