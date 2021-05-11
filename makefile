CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
CPPFLAGS = -MMD

bin/main: obj/src/libgeometry/main.o obj/src/libgeometry/libgeometry.a
	$(CC) $(CFLAGS) -o $@ $^
obj/src/libgeometry/main.o: src/geometry/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< -Isrc/libgeometry

obj/src/libgeometry/libgeometry.a: obj/src/geometry/geometry.o
	ar rcs $@ $^
obj/src/geometry/geometry.o: src/libgeometry/geometry.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

-include main.d geometry.d

.PHONY: clean
 	clean:
		rm bin/*
		rm obj/src/geometry/*.o
		rm obj/src/geometry/*.d
		rm obj/src/libgeometry/*.o
		rm obj/src/libgeometry/*.d
		rm obj/src/libgeometry/*.a
