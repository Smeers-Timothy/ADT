/**
 * @file list_race.c
 * @brief Ce fichier contient le type abstrait "race"
 *
 * @author Smeers Timothy S200930
 * @version 0.1
 * @date 01/05/2021
 *
 * Critère de style :
 * s_	Les variable globale à plusieurs fichiers
 * p_	Les paramètre de fonctions
 * l_	Les variables globale à une seule fonction
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "race.h"
#include "stopover.h"

/* STRUCT */

typedef Course Cell;

struct Course_t {
	Escale *s_stopover;
	Cell *s_next_stopover;
	unsigned int s_nbrStopover;
};

/* DYNAMIC FUNCTION */

Course* create_list_race(Escale *p_stopover, Escale *p_secondStopover) {
	assert(p_stopover != NULL);
	assert(p_secondStopover != NULL);

	Course *l_race;

	l_race = NULL;

	add_end(&l_race, p_stopover);
	add_end(&l_race, p_secondStopover);

	return (l_race);
}

Escale* obtain_list_stopover(Course *p_race, Escale *p_stopover) { /* @suppress("No return") */
	assert(p_race != NULL);
	assert(p_stopover != NULL);

	Cell *l_cell;

	l_cell = p_race;

	while (l_cell != NULL) {

		if (l_cell->s_stopover == p_stopover)
			return (l_cell->s_stopover);

		l_cell = l_cell->s_next_stopover;
	}
}

void* add_start(Course **p_race, Escale *p_stopover) { /* @suppress("No return") */
	assert(p_race != NULL);
	assert(p_stopover != NULL);

	Cell *l_cell;

	l_cell = malloc(sizeof(Cell));

	if (l_cell == NULL)
		return (NULL);

	l_cell->s_stopover = p_stopover;
	l_cell->s_next_stopover = *p_race;

	*p_race = l_cell;
}

void* add_end(Course **p_race, Escale *p_stopover) { /* @suppress("No return") */
	assert(p_race != NULL);
	assert(p_stopover != NULL);

	Cell *l_cell;
	Cell *l_lastCell;

	l_lastCell = *p_race;
	l_cell = malloc(sizeof(Cell));

	if (l_cell == NULL)
		return (NULL);

	l_cell->s_stopover = p_stopover;
	l_cell->s_next_stopover = NULL;

	if (*p_race == NULL) {
		*p_race = l_cell;
		l_cell->s_nbrStopover = 1;

	} else {

		while (l_lastCell->s_next_stopover != NULL)
			l_lastCell = l_lastCell->s_next_stopover;

		l_lastCell->s_next_stopover = l_cell;
	}
}

void remove_list_stopover(Course **p_race, Escale *p_stopover) {
	assert(p_race != NULL);
	assert(p_stopover != NULL);

	Cell *l_cell;
	Cell *l_current;

	if ((*p_race)->s_stopover == p_stopover) {
		l_cell = *p_race;
		(*p_race) = (*p_race)->s_next_stopover;
		free(l_cell);

	} else {
		l_current = *p_race;

		while (l_current->s_next_stopover != NULL) {

			if (l_current->s_next_stopover->s_stopover == p_stopover) {
				l_cell = l_current->s_next_stopover;
				l_current->s_next_stopover =
						l_current->s_next_stopover->s_next_stopover;
				free(l_cell);
				break;

			} else {
				l_current = l_current->s_next_stopover;
			}
		}
	}
}

void print_race(Course *p_race) {
	assert(p_race != NULL);

	char *l_name;
	Cell *l_cell;

	l_name = get_name(p_race->s_stopover);
	l_cell = p_race;

	while (l_cell != NULL) {
		printf("\n %s", l_name);
		l_cell = l_cell->s_next_stopover;
	}
}

void free_list_race(Course *p_race) {
	assert(p_race != NULL);

	Cell *l_cell;

	while (p_race != NULL) {
		l_cell = p_race;
		p_race = p_race->s_next_stopover;
		free(l_cell);
	}
}

float stopover_race_time(Course *p_race, Escale *p_stopover) { /* @suppress("No return") */
	assert(p_race != NULL);
	assert(p_stopover != NULL);

	float l_time;
	Cell *l_cell;

	l_cell = p_race;

	while (l_cell != NULL) {

		l_time = get_best_time(l_cell->s_stopover);

		if (l_cell->s_stopover == p_stopover)
			return (l_time);

		l_cell = l_cell->s_next_stopover;
	}
}

float race_list_time(Course *p_race) {
	assert(p_race != NULL);

	Cell *l_cell;
	unsigned int l_time;

	l_cell = p_race->s_next_stopover;
	l_time = 0;

	while (l_cell != NULL) {
		l_time += get_best_time(l_cell->s_stopover);
		l_cell = l_cell->s_next_stopover;
	}
	return (l_time);
}

unsigned int is_list_circuit(Course *p_race) {
	assert(p_race != NULL);

	Escale *l_start;
	Escale *l_end;
	Cell *l_cell;

	l_start = p_race->s_stopover;
	l_cell = p_race;

	while (l_cell->s_next_stopover != NULL)
		l_cell = l_cell->s_next_stopover;

	l_end = l_cell->s_stopover;

	if (l_start != l_end)
		return (0);

	return (1);

}

/* GETTERS & SETTERS */

unsigned int get_list_stopover(Course *p_race) {
	assert(p_race != NULL);

	unsigned int l_number;
	Cell *l_cell;

	l_cell = p_race->s_next_stopover;
	l_number = 0;

	while (l_cell != NULL) {
		l_cell = l_cell->s_next_stopover;
		l_number++;
	}
	return (l_number);
}
