# Makefile
CXX = g++
CXXFLAGS = -std=c++17 -pthread
TARGET = app

all: $(TARGET)

$(TARGET): main.cpp 
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

clean:
	rm -f $(TARGET)