/**
 * @file table_race.c
 * @brief Ce fichier contient les fonction du type abstrait "race" en tableau
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

#include <stdlib.h>
#include <assert.h>

#include "../code/course.h"
#include "../code/escale.h"

/* DEFINE */

#define REALLOC 2
#define SIZE 10

/* STRUCT */

struct Course_t {
	Escale **s_stopover;
	float s_bestTime;
	unsigned int s_sizeBoard;
	unsigned int s_nbrStopover;
};

/* STATIC FUNCTION */

static Course* memory_allocation(Course *p_race);

static Course* right_shift(Course *p_race, unsigned int p_start);

static Course* left_shift(Course *p_race, unsigned int p_start);

static Course* memory_allocation(Course *p_race) {
	assert(p_race != NULL);

	unsigned int l_newSize;

	p_race->s_sizeBoard *= REALLOC;
	l_newSize = p_race->s_sizeBoard * sizeof(Escale*);

	p_race->s_stopover = realloc(p_race->s_stopover, l_newSize);

	return (p_race);
}

static Course* right_shift(Course *p_race, unsigned int p_start) {
	assert(p_race != NULL);

	unsigned int l_step;

	if (p_race->s_sizeBoard < p_race->s_nbrStopover)
		p_race = memory_allocation(p_race);

	if (p_race->s_nbrStopover > 0)
		l_step = p_race->s_nbrStopover - 1;

	for (unsigned int i = l_step; i >= p_start; i--)
		p_race->s_stopover[i + 1] = p_race->s_stopover[i];

	return (p_race);
}

static Course* left_shift(Course *p_race, unsigned int p_start) {
	assert(p_race != NULL);

	unsigned int l_step;

	if (p_race->s_nbrStopover > 0)
		l_step = p_race->s_nbrStopover - 1;

	for (unsigned int i = p_start; i < l_step; i++)
		p_race->s_stopover[i] = p_race->s_stopover[i + 1];

	return (p_race);
}

/* DYNAMIC FUNCTION */

Course* create_table_race(Escale *p_stopover, Escale *p_secondStopover) {
	assert(p_stopover != NULL);
	assert(p_secondStopover != NULL);

	float l_firstLatitude;
	float l_firstLongitude;
	float l_secondLatitude;
	float l_secondLongitude;
	Course *l_race;

	l_firstLatitude = get_latitude(p_stopover);
	l_firstLongitude = get_longitude(p_stopover);
	l_secondLatitude = get_latitude(p_secondStopover);
	l_secondLongitude = get_longitude(p_secondStopover);

	if (l_firstLatitude < l_secondLatitude
			&& l_firstLongitude < l_secondLongitude
			&& l_firstLatitude > l_secondLatitude
			&& l_firstLongitude > l_secondLongitude)
		return (NULL);

	l_race = malloc(sizeof(Course));

	if (l_race == NULL)
		return (NULL);

	l_race->s_sizeBoard = SIZE;

	log_time(p_stopover, 0.0);

	l_race->s_nbrStopover = 2;

	l_race->s_stopover = malloc(sizeof(Escale*) * SIZE);

	if (l_race->s_stopover == NULL) {
		free(l_race);
		return (NULL);
	}

	l_race->s_bestTime = 0;
	l_race->s_stopover[0] = p_stopover;
	l_race->s_stopover[1] = p_secondStopover;

	return (l_race);
}

Course* add_table_stopover(Course *p_race, Escale *p_stopover, int p_position) {
	assert(p_race != NULL);
	assert(p_stopover != NULL);

	right_shift(p_race, p_position);

	p_race->s_stopover[p_position] = p_stopover;
	p_race->s_sizeBoard += 1;
	p_race->s_nbrStopover++;

	return (p_race);
}

Course* remove_table_stopover(Course *p_race, int p_position) {
	assert(p_race != NULL);

	int l_position;

	l_position = get_table_stopover(p_race);

	if (p_position > l_position)
		return (NULL);

	free_stopover(p_race->s_stopover[p_position]);
	left_shift(p_race, p_position);
	p_race->s_nbrStopover--;

	return (p_race);

}

Escale* obtain_table_stopover(Course *p_race, int p_position) {
	assert(p_race != NULL);

	Escale *l_header;

	l_header = p_race->s_stopover[p_position];

	return (l_header);
}

void free_table_race(Course *p_race) {
	assert(p_race != NULL);

	if (p_race->s_stopover != NULL)
		free(p_race->s_stopover);

	if (p_race != NULL)
		free(p_race);
}

unsigned int is_table_circuit(Course *p_race) {
	assert(p_race != NULL);

	unsigned int l_step;
	float l_firstLatitude;
	float l_firstLongitude;
	float l_secondLatitude;
	float l_secondLongitude;

	l_step = p_race->s_sizeBoard - 1;

	l_firstLatitude = get_latitude(p_race->s_stopover[0]);
	l_secondLatitude = get_latitude(p_race->s_stopover[l_step]);
	l_firstLongitude = get_longitude(p_race->s_stopover[0]);
	l_secondLongitude = get_longitude(p_race->s_stopover[l_step]);

	if (l_firstLatitude < l_secondLatitude && l_firstLatitude > l_secondLatitude
			&& l_firstLongitude < l_secondLongitude
			&& l_firstLongitude > l_secondLongitude)
		return (0);

	return (1);
}

float race_table_time(Course *p_race) {
	assert(p_race != NULL);

	p_race->s_bestTime = 0;

	for (unsigned int i = 0; i < p_race->s_nbrStopover; i++)
		p_race->s_bestTime += get_best_time(p_race->s_stopover[i]);

	return (p_race->s_bestTime);
}

/* GETTERS & SETTERS */

unsigned int get_table_stopover(Course *p_race) {
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

float get_time(Course *p_race, int p_position) {
	assert(p_race != NULL);
	assert(p_position < p_race->s_nbrStopover);

	float l_time;

	l_time = get_best_time(p_race->s_stopover[p_position]);

	return (l_time);
}
