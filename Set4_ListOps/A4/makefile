TARGET = A4
SRC_FILES = main.cpp Face.cpp Vertex.cpp vector_functions.cpp

CXX = g++
CFLAGS = -Wall -g

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

#DEPENDENCIES
main.o: main.cpp vector_functions.cpp
Face.o: Face.h
vector_functions.o: vector_functions.h
Vertex.o: Vertex.h