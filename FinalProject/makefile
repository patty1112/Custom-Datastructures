TARGET = FP
SRC_FILES = main.cpp Dice.cpp Field.cpp fileFunctions.cpp Game.cpp hitOutcomes.cpp pitcherOutcomes.cpp Player.cpp Team.cpp baseStatus.cpp

CXX = g++
CFLAGS = -Wall -g -std=c++11

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
main.o: main.cpp
Dice.o: Dice.h
Field.o: Field.h
fileFunctions.o: fileFunctions.h
Game.o: Game.h
hitOutcomes.o: hitOutcomes.h
pitcherOutcomes.o: pitcherOutcomes.h
Player.o: Player.h
Team.o: Team.h
baseStatus.o: baseStatus.h
