/**
 * @file stopover.c
 * @brief Ce fichier contient les fonction du type abstrait "stopover"
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


#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "stopover.h"

/* STRUCT */

struct Escale_t {
	float s_latitude;
	float s_longitude;
	float s_bestTime;
	char *s_name;
};

/* DYNAMIC FUNCTION */

Escale* create_stopover(float p_latitude, float p_longitude, char *p_name) {
	assert(p_name != NULL);
	assert(p_latitude <= 90 && p_latitude >= -90);
	assert(p_longitude <= 180 && p_longitude >= -180);

	Escale *l_stopover = malloc(sizeof(Escale));

	if (l_stopover == NULL)
		return (NULL);

	l_stopover->s_name = malloc(sizeof(char) * sizeof(p_name));

	if (l_stopover->s_name == NULL)
		return (NULL);

	l_stopover->s_latitude = p_latitude;
	l_stopover->s_longitude = p_longitude;

	strcpy(l_stopover->s_name, p_name);

	return (l_stopover);
}

Escale* log_time(Escale *p_stopover, float p_time) {
	assert(p_stopover != NULL);
	assert(p_time >= 0);

	p_stopover->s_bestTime = p_time;

	return (p_stopover);
}

void free_stopover(Escale *p_stopover) {
	assert(p_stopover != NULL);

	free(p_stopover->s_name);
	free(p_stopover);
}

float calculate_range(Escale *p_stopover, Escale *p_secondStopover) {
	assert(p_stopover != NULL);
	assert(p_secondStopover != NULL);

	float l_range = acos(
			sin(p_stopover->s_latitude) * sin(p_secondStopover->s_latitude)
					+ cos(p_stopover->s_longitude)
							* cos(p_secondStopover->s_longitude) * 1000);

	return (l_range);
}

/* GETTERS & SETTERS */

char* get_name(Escale *p_stopover) {
	assert(p_stopover != NULL);

	return (p_stopover->s_name);
}

float get_latitude(Escale *p_stopover) {
	assert(p_stopover != NULL);

	return (p_stopover->s_latitude);
}
float get_longitude(Escale *p_stopover) {
	assert(p_stopover != NULL);

	return (p_stopover->s_longitude);
}

float get_best_time(Escale *p_stopover) {
	assert(p_stopover != NULL);

	return (p_stopover->s_bestTime);
}
