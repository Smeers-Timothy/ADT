/**
 * @file stopover.h
 * @brief Ce fichier contient les prototypes des fonction du type abstrait "stopover"
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

#ifndef STOPOVER_H_
#define STOPOVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

typedef struct Escale_t Escale;

Escale* create_stopover(float p_latitude, float p_longitude, char *p_name);

float get_x(Escale *p_stopover);

float get_y(Escale *p_stopover);

char* get_name(Escale *p_stopover);

float get_time(Escale *p_stopover);

float calculate_range(Escale *p_stopover, Escale *p_secondStopover);

Escale* log_time(Escale *p_stopover, float p_time);

void free_stopover(Escale *p_stopover);

#endif /* STOPOVER_H_ */
