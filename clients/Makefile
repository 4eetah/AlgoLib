CXXFLAGS=-I../ -std=c++11

SRCS=$(shell find -name "*cpp" -exec basename '{}' \;)
OBJS=$(SRCS:%.cpp=%.o)
TARGETS=$(SRCS:%.cpp=%)

all: $(TARGETS)

DepthFirstPaths_cli: DepthFirstPaths_cli.o
	$(CXX) -o $@ $(CXXFLAGS) $<

DirectedEdge_cli: DirectedEdge_cli.o
	$(CXX) -o $@ $(CXXFLAGS) $<

Digraph_cli: Digraph_cli.o
	$(CXX) -o $@ $(CXXFLAGS) $<

Graph_cli: Graph_cli.o
	$(CXX) -o $@ $(CXXFLAGS) $<

Edge_cli: Edge_cli.o
	$(CXX) -o $@ $(CXXFLAGS) $<

clean:
	rm $(OBJS) $(TARGETS)
