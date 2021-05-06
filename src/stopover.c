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

#include "stopover.h"

struct Escale_t {
	float s_coordX;
	float s_coordY;
	float s_bestTime;
	char *s_name;
};

Escale* create_stopover(float p_x, float p_y, char *p_name) {
	assert(p_name != NULL);

	Escale *l_stopover = malloc(sizeof(Escale));

	if (l_stopover == NULL)
		return (NULL);

	l_stopover->s_name = malloc(sizeof(char) * sizeof(p_name));

	if(l_stopover->s_name == NULL)
		return (NULL);

	l_stopover->s_coordX = p_x;
	l_stopover->s_coordY = p_y;

	strcpy(l_stopover->s_name, p_name);

	return (l_stopover);
}

float get_x(Escale *p_stopover) {
	assert(p_stopover != NULL);

	return (p_stopover->s_coordX);
}
float get_y(Escale *p_stopover) {
	assert(p_stopover != NULL);

	return (p_stopover->s_coordY);
}
char* get_name(Escale *p_stopover) {
	assert(p_stopover != NULL);

	return (p_stopover->s_name);
}

float get_time(Escale *p_stopover) {
	assert(p_stopover != NULL);

	return (p_stopover->s_bestTime);
}

float calculate_range(Escale *p_stopover, Escale *p_secondStopover) {
	assert(p_stopover != NULL);
	assert(p_secondStopover != NULL);

	float l_range = acos(
			sin(p_stopover->s_coordX)
			* sin(p_secondStopover->s_coordX)
			+ cos(p_stopover->s_coordY)
			* cos(p_secondStopover->s_coordY));

	return (l_range);
}
Escale* log_time(Escale *p_stopover, float p_time) {
	assert(p_stopover != NULL);
	assert(p_time >= 0);

	p_stopover->s_bestTime = p_time;

	return (p_stopover);
}

void free_stopover(Escale *p_stopover) {
	assert(p_stopover != NULL)
	free(p_stopover->s_name);
	free(p_stopover);
}

