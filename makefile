OBJS = main.o game.o player.o enemy.o wall.o
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

game: $(OBJS)
	$(CXX) $(CXXFLAGS) -o game $(OBJS) $(LDLIBS)

$(OBJS): game.h

$(OBJS): player.h

$(OBJS): enemy.h

$(OBJS): wall.h


clean:
	$(RM) game $(OBJS)
