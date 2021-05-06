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
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "race.h"
#include "stopover.h"

struct Course_t{
    Escale *s_stopover;
    float s_coordY;
    float s_bestTime;
    char *s_name;
};

Course *create_race(Escale *p_stopover, Escale *p_secondStopover){

    return ;
}
int is_circuit(Course *p_race){

    return;
}
int number_stopover(Course *p_race){

    return;
}
int number_steps(Course *p_race){

    return;
}
float best_time_race(Course *p_race){

    return;
}
float best_time_stopovers_race(Course *p_race, Escale *p_stopover){

    return;
}
Course *add_stopover(Course *p_race, Escale *p_stopover){

    return;
}
Course *remove_stopover(Course *p_race, Escale *p_stopover){

    return;
}
