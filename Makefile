CXXFLAGS+=-std=c++0x -I. -g -DDEBUG -pipe

# I want 4.6!! range-based for ftw
CXX=/usr/lib/gcc-snapshot/bin/g++

all:
	if [ ${TERM} ]; then clear; fi
	$(CXX) $(CXXFLAGS) -o clobvm main.cpp Instruction.cpp ClobFile.cpp DataTypes/*.cpp
	$(CXX) $(CXXFLAGS) -o testcomp.bin testcomp.cpp Instruction.cpp ClobFile.cpp DataTypes/*.cpp

cgi32:
	clear
	$(CXX) $(CXXFLAGS) -g0 -m32 -o clobvm main.cpp Instruction.cpp ClobFile.cpp  DataTypes/*.cpp
	$(CXX) $(CXXFLAGS) -g0 -m32 -o testcomp.bin testcomp.cpp Instruction.cpp ClobFile.cpp DataTypes/*.cpp
	
clean:
	-rm main.bin

install:
	-cp -v clobvm /usr/local/bin/
	./testcomp.bin
	-cp -v test.clobcc /var/www/