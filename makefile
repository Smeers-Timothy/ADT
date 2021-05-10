## Variables ##

# Tools & Flags #
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes -Wswitch-default -Wswitch-enum -Wfloat-equal -Wredundant-decls -Winit-self -Wnull-dereference -Wextra -lm
LD=gcc
LDFLAGS=
DOXYGEN_CONFIG=TAD.doxyfile

# Files #
EXEC=escale.o course_liste.o course_tableau.o
TESTS=course_tableau_test test_list
TESTS_E=course_tableau_test test_list
MODULES=escale.c course_liste.c
OBJECTS=escale.o course_liste.o

## Rules ##

all: $(EXEC)

escale.o: src/escale.c
	$(CC) -c src/escale.c -o escale.o $(CFLAGS)

course_liste.o: src/course_liste.c
	$(CC) -c src/course_liste.c -o course_liste.o $(CFLAGS)

course_tableau.o: src/course_tableau.c
	$(CC) -c src/course_tableau.c -o course_tableau.o $(CFLAGS)

test_array: src/course_tableau_test.c
	$(CC) -g -o course_tableau_test src/escale.c src/course_tableau.c src/seatest.c src/course_tableau_test.c $(CFLAGS)

test_list: src/course_liste_test.c
	$(CC) -g -o course_liste_test src/escale.c src/course_liste.c src/seatest.c src/course_liste_test.c $(CFLAGS)

#documentation
doc:
	doxygen $(DOXYGEN_CONFIG)

.PHONY: doc

rapport:
		pdflatex rapport/tad-groupe34.tex

clean:
	rm -f *.o $(TESTS_E) *~
	rm -f course_tableau_test
	rm -f course_liste_test
	clear

archive:
	tar -zcvf tad-groupe34.tar.gz *.h *.c  makefile Images #Doxyfile
