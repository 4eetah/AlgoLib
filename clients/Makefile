CXXFLAGS=-I../ -std=c++11 -g

SRCS=$(shell find -name "*cpp" -exec basename '{}' \;)
OBJS=$(SRCS:%.cpp=%.o)
TARGETS=$(SRCS:%.cpp=%)

all: $(TARGETS)

CC_cli: CC_cli.o
	$(CXX) -o $@ $(CXXFLAGS) $<

DepthFirstPaths_cli: DepthFirstPaths_cli.o
	$(CXX) -o $@ $(CXXFLAGS) $<

DepthFirstDirectedPaths_cli: DepthFirstDirectedPaths_cli.o
	$(CXX) -o $@ $(CXXFLAGS) $<

BreadthFirstPaths_cli: BreadthFirstPaths_cli.o
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
