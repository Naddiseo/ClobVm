CXXFLAGS+=-std=c++0x -I. -g

# I want 4.6!! range-based for ftw
CXX=/usr/lib/gcc-snapshot/bin/g++

all:
	$(CXX) $(CXXFLAGS) -o main.bin *.cpp DataTypes/*.cpp