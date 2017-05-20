CC = g++
CFLAGS = `sdl2-config --cflags --libs` -lSDL2_image
OUTPUT = test

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

$(OUTPUT): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(OUTPUT)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm *.o $(OUTPUT)
