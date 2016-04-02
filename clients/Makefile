CXXFLAGS=-I../ -std=c++11 -g

SRCS=$(shell find -name "*cpp" -exec basename '{}' \;)
TARGETS=$(SRCS:%.cpp=%)

all: $(TARGETS)

clean:
	rm $(TARGETS)
