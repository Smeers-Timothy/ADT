## Variables ##

# Tools & Flags #
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes -Wswitch-default -Wswitch-enum -Wfloat-equal -Wredundant-decls -Winit-self -Wnull-dereference -Wextra -lm
LD=gcc
LDFLAGS=
DOXYGEN=DOXYGEN

# Files #
EXEC=stopover.o list_race.o table_race.o
TESTS=test_table test_list
TESTS_E=test_table test_list
MODULES=stopover.c list_race.c
OBJECTS=stopover.o list_race.o

## Rules ##

all: $(EXEC)

stopover.o: stopover.c
	$(CC) -c stopover.c -o stopover.o $(CFLAGS)

list_race.o: list_race.c
	$(CC) -c list_race.c -o list_race.o $(CFLAGS)

table_race.o: table_race.c
	$(CC) -c table_race.c -o table_race.o $(CFLAGS)

test_table: test_table.c
	$(CC) -g -o test_table stopover.c table_race.c seatest.c test_table.c $(CFLAGS)

test_list: test_list.c
	$(CC) -g -o test_list stopover.c list_race.c seatest.c test_list.c $(CFLAGS)

clean:
	rm -f *.o $(TESTS_E) *~
	clear
