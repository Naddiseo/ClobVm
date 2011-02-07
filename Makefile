CXXFLAGS+=-std=c++0x -I. -g -DDEBUG

# I want 4.6!! range-based for ftw
CXX=/usr/lib/gcc-snapshot/bin/g++

all:
	clear
	$(CXX) $(CXXFLAGS) -o main.bin *.cpp DataTypes/*.cpp

all32:
	clear
	$(CXX) $(CXXFLAGS) -m32 -o main.bin *.cpp DataTypes/*.cpp
	
clean:
	-rm main.bin