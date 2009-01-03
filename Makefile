############################################################################
# Makefile for the raytracer framwork created for the Computer Science 
# course "Introduction Computer Graphics" taught at the University of 
# Groningen by Tobias Isenberg.
############################################################################

### MACROS

# GNU (everywhere)
CPP = g++ -g -Wall

# GNU (faster)
#CPP = g++ -O5 -Wall -fomit-frame-pointer -ffast-math 

LIBS = -lm

EXECUTABLE = ray

OBJS = main.o raytracer.o sphere.o light.o material.o \
	image.o triple.o lodepng.o scene.o

YAMLOBJS = yaml/content.o yaml/exp.o yaml/iterator.o yaml/map.o \
	yaml/node.o yaml/parser.o yaml/parserstate.o yaml/regex.o \
	yaml/scalar.o yaml/scanner.o yaml/scanscalar.o yaml/scantoken.o \
	yaml/sequence.o yaml/simplekey.o yaml/stream.o


### TARGETS

$(EXECUTABLE): $(OBJS) $(YAMLOBJS)
	$(CPP) $(OBJS) $(YAMLOBJS) $(LIBS) -o $@

run: $(EXECUTABLE) scene01.yaml
	./$(EXECUTABLE) scene01.yaml scene01.png

depend: make.dep

clean:
	- /bin/rm -f  *.bak *~ $(OBJS) $(YAMLOBJS) $(EXECUTABLE)

make.dep:
	gcc -MM $(OBJS:.o=.cpp) > make.dep

### RULES

.SUFFIXES: .cpp .o .yaml .png

.cpp.o:
	$(CPP) -c -o $@ $<

### DEPENDENCIES

include make.dep
