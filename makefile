## Variables ##

# Tools & Flags #
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes -Wswitch-default -Wswitch-enum -Wfloat-equal -Wredundant-decls -Winit-self -Wnull-dereference -Wextra -lm
LD=gcc
LDFLAGS=
DOXYGEN_CONFIG=TAD.doxyfile

# Files #
EXEC=code/escale.o code/course_liste.o code/course_tableau.o
TESTS=course_tableau_test test_list
TESTS_E=course_tableau_test test_list
MODULES=escale.c course_liste.c
OBJECTS=escale.o course_liste.o

## Rules ##

all: $(EXEC)

escale.o: code/escale.c
	$(CC) -c code/escale.c -o escale.o $(CFLAGS)

course_liste.o: code/course_liste.c
	$(CC) -c code/course_liste.c -o course_liste.o $(CFLAGS)

course_tableau.o: code/course_tableau.c
	$(CC) -c code/course_tableau.c -o course_tableau.o $(CFLAGS)

test_array: code/course_tableau_test.c
	$(CC) -c code/course_tableau.c -o code/course_tableau.o $(CFLAGS)
	ar rcs code/course_tableau_test.a code/course_tableau.o

test_list: code/course_liste_test.c
	$(CC) -c code/course_liste.c -o code/course_liste.o $(CFLAGS)
	ar rcs code/course_liste_test.a code/course_liste.o

#documentation
doc:
	doxygen $(DOXYGEN_CONFIG)

.PHONY: doc

rapport:
		pdflatex rapport/tad-groupe34.tex

clean:
	rm -f code/*.o $(TESTS_E) code/*~
	rm -f code/course_tableau_test.a
	rm -f code/course_liste_test.a
	clear
