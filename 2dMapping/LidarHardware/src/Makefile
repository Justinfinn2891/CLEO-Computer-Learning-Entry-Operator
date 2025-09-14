CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -pthread \
           -I../rplidar_sdk-master/sdk/include \
           -I../rplidar_sdk-master/sdk/src \
           -I../include

LDFLAGS = -L../rplidar_sdk-master/output/Linux/Release -lsl_lidar_sdk

SRC = lidar.cpp ../lib/coordinates.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = lidar

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
