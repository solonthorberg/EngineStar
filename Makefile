CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Iincl
TARGET   = engine_star

SRCS = $(wildcard src/*.cpp)

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
