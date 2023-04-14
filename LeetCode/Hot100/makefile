CXX = g++
CXXFLAGS = -Wall -Werrors -g

SRCS = $(wildcard ./*.cpp)

OBJS = $(patsubst ./%.cpp, ./%.o, $(SRCS))

$(SRCS): $(OBJS)
	$(CXX) -o $(CXXFLAGS) $(SRCS) $(OBJS)

./%.o: ./%.cpp
	$(CXX) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf $(OBJS) *.cpp
