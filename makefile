linkTarget = 	rtx_app

LIBS = 		-lSDL2

CFLAGS = 	-std=c++17 -Ofast

objects = 	main.o \
		CApp.o \
		$(patsubst %.cpp,%.o,$(wildcard ./source/*.cpp))

rebuildables = 	$(objects) $(linkTarget)

$(linkTarget): $(objects)
	g++ -g -o $(linkTarget) $(objects) $(LIBS) $(CFLAGS)

%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)

.PHONEY:
clean:
	rm $(rebuildables)
