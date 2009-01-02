############################################################################
#   PROJECT: Classroom Raytracer
#   FILE:    Makefile
#   CONTENT: Make script
#
#   AUTHOR:  Bert Freudenberg (bf)
#   ADDRESS: University of Magdeburg, Germany
#   EMAIL:   bert@isg.cs.uni-magdeburg.de
#   RCSID:   $Id: Makefile,v 1.8 2001/11/01 16:47:46 bert Exp bert $
#
#############################################################################

### MACROS

# GNU (everywhere)
CPP = g++ -g -Wall

# GNU (faster)
#CPP = g++ -O5 -Wall -fomit-frame-pointer -ffast-math 

# SGI CC (SGI only, faster)
#CPP = CC -Ofast=$(HOSTARCH) -fullwarn
# -woff 1174,3180

# Solaris CC (Sun)
#CPP = CC -fast -libmil

LIBS = -lm

OBJS = main.o raytracer.o sphere.o light.o material.o \
	image.o triple.o lodepng.o scene.o

YAMLOBJS = yaml/content.o yaml/exp.o yaml/iterator.o yaml/map.o \
	yaml/node.o yaml/parser.o yaml/parserstate.o yaml/regex.o \
	yaml/scalar.o yaml/scanner.o yaml/scanscalar.o yaml/scantoken.o \
	yaml/sequence.o yaml/simplekey.o yaml/stream.o

### TARGETS

ray: $(OBJS) $(YAMLOBJS)
	$(CPP) $(OBJS) $(YAMLOBJS) $(LIBS) -o $@

run: ray rt1.in
	./ray rt1.in rt1.ppm

view: rt1.ppm
	$(VIEW) rt1.ppm &

depend: make.dep

clean:
	- /bin/rm -f  *.bak *~ $(OBJS) $(YAMLOBJS) ray rt1.ppm

make.dep:
	gcc -MM $(OBJS:.o=.cpp) > make.dep

### RULES

.SUFFIXES: .cpp .o .in .ppm .png .jpg .gif

.cpp.o:
	$(CPP) -c -o $@ $<

.in.ppm:
	./ray $*.in $*.ppm 

.ppm.png:
	pnmscale -width 64 $*.ppm | pnmtopng > $*.small.png
	pnmtopng $*.ppm > $*.png

.ppm.jpg:
	pnmscale -width 64 $*.ppm | cjpeg -quality 80 > $*.small.jpg
	cjpeg -quality 80 $*.ppm > $*.jpg 

.ppm.gif:
	pnmscale -width 64 $*.ppm | ppmquant -fs 256 | ppmtogif > $*.small.gif
	ppmquant -fs 256 $*.ppm | ppmtogif > $*.gif

### DEPENDENCIES

include make.dep

rt1.ppm: ray rt1.in
