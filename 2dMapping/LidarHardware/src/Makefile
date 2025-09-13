# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -pthread

# Paths
INCLUDES = -I../rplidar_sdk-master/sdk/include \
           -I../rplidar_sdk-master/sdk/src

LIBS = -L../rplidar_sdk-master/output/Linux/Release \
       -lsl_lidar_sdk

# Targets
TARGET = lidar
SRC = lidar.cpp
OBJ = $(SRC:.cpp=.o)

# Build rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(CXXFLAGS) $(INCLUDES) $(LIBS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

clean:
	rm -f $(OBJ) $(TARGET)
