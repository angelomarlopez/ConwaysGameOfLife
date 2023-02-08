CXX = g++
LIB_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

INCLUDE = include/
SRC = src/

FILE_OBJS = Cell.o Tab.o World.o Window.o

output: Main.o $(FILE_OBJS)
	$(CXX) Main.o $(FILE_OBJS) -o output $(LIB_FLAGS)

Main.o: Main.cpp
	$(CXX) -c Main.cpp

Window.o: $(SRC)Window.cpp $(INCLUDE)Window.hpp
	$(CXX) -c $(SRC)Window.cpp

World.o: $(SRC)World.cpp $(INCLUDE)World.hpp
	$(CXX) -c $(SRC)World.cpp

Tab.o: $(SRC)Tabs/Tab.cpp $(INCLUDE)Tabs/Tab.hpp
	$(CXX) -c $(SRC)Tabs/Tab.cpp

Cell.o: $(SRC)Cell.cpp $(INCLUDE)Cell.hpp
	$(CXX) -c $(SRC)Cell.cpp

clean:
	rm *.o output