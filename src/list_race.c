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

#include "race.h"

/* STRUCT */

typedef Course Cell;

struct Course_t {
	Escale *s_stopover;
	Cell *s_next_stopover;
	unsigned int s_nbrStopover;
};

/* DYNAMIC FUNCTION */

Cell* create_cell(Escale *p_data) {
	assert(p_data != NULL);

	Cell *l_cell;

	l_cell = malloc(sizeof(Cell));

	if (l_cell == NULL)
		return (NULL);

	l_cell->s_data = p_data;
	l_cell->s_next = NULL;

	return (l_cell);
}

static Course* add_start(Course *p_header, Escale *p_stopover) {
	assert(p_header != NULL);
	assert(p_stopover != NULL);

	Cell *l_cell;

	l_cell = create_cell(p_stopover);

	if (l_cell == NULL)
		return (NULL);

	l_cell->s_next = p_header->s_start;

	if (p_header->s_end == p_header->s_start)
		p_header->s_end->s_next = l_cell;

	p_header->s_start = l_cell;
	p_header->s_nbrStopover += 1;

	return (p_header);
}

static Course* add_end(Course *p_header, Escale *p_stopover) {
	assert(p_header != NULL);
	assert(p_stopover != NULL);

	Cell *l_cell;

	l_cell = create_cell(p_stopover);

	if (l_cell == NULL)
		return (NULL);

	l_cell->s_next = p_header->s_end->s_next;
	p_header->s_end->s_next = l_cell;
	p_header->s_end = l_cell;
	p_header->s_nbrStopover += 1;

	return (p_header);
}

Course* create_race(Escale *p_stopover, Escale *p_secondStopover) {
	assert(p_stopover != NULL);
	assert(p_secondStopover != NULL);

	Cell *l_race;
	Course *l_header;

	l_race = create_cell(p_stopover);
	l_header = malloc(sizeof(Course));

	if (l_header == NULL)
		return (NULL);

	l_race->s_next = create_cell(p_secondStopover);
	l_race->s_next->s_next = NULL;

	l_header->s_start = l_race;
	l_header->s_end = l_race->s_next;
	l_header->s_nbrStopover = 2;

	return (l_header);
}

Course* add_stopover(Course *p_race, Escale *p_stopover, int p_position) {
	assert(p_race != NULL);
	assert(p_stopover != NULL);
	assert(p_position > 0);

	unsigned int l_number;
	Course l_start;
	Course l_end;
	Cell *l_current;
	Cell *l_previous;
	Cell *l_cell;

	l_number = get_stopover(p_race);
	l_start = add_start(p_race, p_stopover);
	l_end = add_end(p_race, p_stopover);

	if (p_position > l_number)
		return (NULL);

	if (p_position == 1)
		return (l_start);

	if (p_position == l_number)
		return (l_end);

	l_current = p_race->s_start;
	l_previous = NULL;

	for (unsigned int i = 1; i < p_position; i++) {
		l_previous = l_current;
		l_current = l_current->s_next;
	}

	l_cell = create_cell(p_stopover);

	if (l_cell == NULL)
		return (NULL);

	l_cell->s_next = l_current;
	l_previous->s_next = l_cell;
	p_race->s_nbrStopover += 1;

	return (p_race);
}

Course* remove_stopover(Course *p_race, int p_position) {
	assert(p_race != NULL);
	assert(p_position > 0);

	unsigned int l_number;
	Course *l_remove;

	l_number = get_stopover(p_race);

	if (p_position > l_number)
		return (NULL);

	p_race->s_count++;

	if (p_position == 1) {
		p_race->s_count = 0;
		p_race->s_pointer = p_race->s_start;
		p_race->s_start = p_race->s_pointer->s_next;
		p_race->s_end->s_next = p_race->s_pointer->s_next;
		free(p_race->s_pointer);
		p_race->s_nbrStopover -= 1;

		return (p_race);
	}

	if (p_race->s_count == 1)
		p_race->s_pointer = p_race->s_start;

	if (p_race->s_count > 1) {
		p_race->s_nullPointer = p_race->s_pointer;
		p_race->s_pointer = p_race->s_pointer->s_next;
	}

	if (p_race->s_count == p_position) {

		if (p_position == l_number) {
			p_race->s_end = p_race->s_nullPointer;
		}
		p_race->s_count = 0;
		p_race->s_nullPointer->s_next = p_race->s_pointer->s_next;

		free(p_race->s_pointer);
		p_race->s_nbrStopover -= 1;

		return (p_race);
	}

	l_remove = remove_stopover(p_race, p_position);

	return (l_remove);
}

Escale* obtain_stopover(Course *p_race, int p_position) {
	assert(p_race != NULL);

	unsigned int l_number;
	Cell *l_cell;

	l_number = get_stopover(p_race);
	l_cell = p_race->s_pointer;

	if (p_position > l_number)
		return (NULL);

	if (p_race->s_count == 0) {
		l_cell = p_race->s_start;

		for (unsigned int i = 1; i <= p_position; i++)
			l_cell = l_cell->s_next;

	} else {

		for (unsigned int i = p_race->s_count; i < p_position; i++)
			l_cell = l_cell->s_next;
	}

	l_number = get_stopover(p_race);

	if (p_race->s_count == l_number)
		p_race->s_count = 0;

	return (l_cell->s_data);
}

void free_race(Course *p_race) {
	assert(p_race != NULL);

	p_race->s_pointer = p_race->s_start;
	unsigned int l_number = get_stopover(p_race);

	if (p_race->s_pointer->s_next != NULL) {

		if (p_race->s_pointer->s_next != p_race->s_start) {

			for (unsigned int i = 1; i < l_number; i++) {
				free_stopover(p_race->s_pointer->s_data);
				free(p_race->s_pointer);
				p_race->s_pointer = p_race->s_pointer->s_next;
			}
		}
	} else {
		free_stopover(p_race->s_pointer->s_data);
		free(p_race->s_pointer);
		free(p_race);
	}

}

/* GETTERS & SETTERS */

unsigned int get_stopover(Course *p_race) {
	assert(p_race != NULL);

	unsigned int l_number = p_race->s_nbrStopover;

	return (l_number);
}

unsigned int get_step(Course *p_race) {
	assert(p_race != NULL);

	unsigned int l_step = p_race->s_nbrStopover;

	if (l_step > 0)
		l_step -= 1;

	return (l_step);
}

