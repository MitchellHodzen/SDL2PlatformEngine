CC = g++
CLIBS = `sdl2-config --cflags --libs` -lSDL2_image
OUTPUT = test
OBJDIR = bin
SRCDIR = .

SOURCES = $(wildcard *.cpp)
POBJECTS = $(SOURCES:.cpp=.o)
OBJECTS = $(addprefix $(OBJDIR)/, $(POBJECTS))

$(OUTPUT): $(OBJECTS)
	$(CC) $(OBJECTS) $(CLIBS) -o $(OUTPUT)

$(OBJDIR)/%.o: %.cpp
	$(CC) -c $< -o $@ $(CLIBS)

clean:
	rm $(OBJDIR)/*.o $(OUTPUT)
