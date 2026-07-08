CXX = g++
CXXFLAGS = -std=c++11 -I/usr/local/include/hiredis
LDFLAGS = -lhiredis

TARGET = redis

all: $(TARGET)

$(TARGET): redis.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) redis.cpp $(LDFLAGS)

clean:
	rm -f $(TARGET)