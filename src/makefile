## Variables ##

# Tools & Flags #
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes -Wswitch-default -Wswitch-enum -Wfloat-equal -Wredundant-decls -Winit-self -Wnull-dereference -Wextra -lm
LD=gcc
LDFLAGS=
DOXYGEN=DOXYGEN

# Files #
EXEC=escale.o course_liste.o course_tableau.o
TESTS=test_tableau test_liste
TESTS_E=course_tableau_test course_liste_test
MODULES=escale.c course_liste.c
OBJECTS=escale.o course_liste.o

## Rules ## 

all: $(EXEC)

escale.o: escale.c
	$(CC) -c escale.c -o escale.o $(CFLAGS)

course_liste.o: course_liste.c
	$(CC) -c course_liste.c -o course_liste.o $(CFLAGS)

course_tableau.o: course_tableau.c
	$(CC) -c course_tableau.c -o course_tableau.o $(CFLAGS)

test_tableau: course_tableau_test.c
	$(CC) -g -o course_tableau_test escale.c course_tableau.c seatest.c course_tableau_test.c $(CFLAGS)

test_liste: course_liste_test.c
	$(CC) -g -o course_liste_test escale.c course_liste.c seatest.c course_liste_test.c $(CFLAGS)

clean:
	rm -f *.o $(TESTS_E) *~
	clear
