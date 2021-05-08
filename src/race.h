/**
 * @file race.h
 * @brief Ce fichier contient les prototype du type abstrait "race"
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

#ifndef RACE_H_
#define RACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stopover.h"

/**
 * @struct typedef struct Course_t Course
 * @brief Structure de donnée contenant les information nécessaire à une course
 */
typedef struct Course_t Course;

/**
 * @fn Course create_race*(Escale*, Escale*)
 * @brief Allows you to initialize the race structure
 *
 * @pre p_stopover != NULL && p_secondStopover != NULL
 * @post a race was create with connection cell
 * @param p_stopover the first stopover
 * @param p_secondStopover the second stopover
 * @return Course * a memory allowed pointer to the header of the course structure
 * 			NULL on error
 */
Course* create_race(Escale *p_stopover, Escale *p_secondStopover);

/**
 * @fn Course add_stopover*(Course*, Escale*, int)
 * @brief Allows you to add a stopover to the structure
 *
 * @pre p_race != NULL && p_stopover != NULL && p_position > 0
 * @post a stopover has been added
 * @param p_race a pointer to the Course structure
 * @param p_stopover a pointer to the Escale structure
 * @param p_position the position in the list
 * @return Course * a pointer to the header of the course structure
 * 			NULL on error
 */
Course* add_stopover(Course *p_race, Escale *p_stopover, int p_position);

/**
 * @fn Course remove_stopover*(Course*, int)
 * @brief Allows you to remove a stopover to the structure
 *
 * @pre p_race != NULL && p_position > 0
 * @post a stopover has been removed
 * @param p_race a pointer to the Course structure
 * @param p_position the position in the list
 * @return Course * a pointer to the header of the course structure
 * 			NULL on error
 */
Course* remove_stopover(Course *p_race, int p_position);

/**
 * @fn Escale obtain_stopover*(Course*, int)
 * @brief getter of the data of a cell
 *
 * @pre p_race != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @param p_position the position in the list
 * @return Escale *a pointer to the data Escale structure
 * 			NULL on error
 */
Escale* obtain_stopover(Course *p_race, int p_position);

/**
 * @fn void free_race(Course*)
 * @brief Used to free the memory of the Course structure
 *
 * @pre p_race != NULL
 * @post Course *p_race is released
 * @param p_race a pointer to the Course structure
 */
void free_race(Course *p_race);

/**
 * @fn unsigned int is_circuit(Course*)
 * @brief Used to determine if the race is a circuit
 *
 * @pre p_race != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @return 0 if the race is not a circuit
 * 			1 else
 */
unsigned int is_circuit(Course *p_race);

/**
 * @fn float race_time(Course*)
 * @brief get time to race
 *
 * @pre p_race != NULL
 * @post p_race->s_bestTime0 != p_race->s_bestTime
 * @param p_race a pointer to the Course structure
 * @return float p_race->s_bestTime
 */
float race_time(Course *p_race);

/**
 * @fn unsigned int get_stopover(Course*)
 * @brief getter of the number of stopover
 *
 * @pre p_race != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @return unsigned int p_race->s_nbrStopover
 */
unsigned int get_stopover(Course *p_race);

/**
 * @fn unsigned int get_step(Course*)
 * @brief getter of the number of step
 *
 * @pre p_race != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @return unsigned int p_race->s_nbrStopover -1
 */
unsigned int get_step(Course *p_race);

/**
 * @fn float get_time(Course*, int)
 * @brief
 *
 * @pre p_race != NULL && p_position < p_race->s_nbrStopover
 * @post /
 * @param p_race a pointer to the Course structure
 * @param p_position the position in the list
 * @return float l_time
 */
float get_time(Course *p_race, int p_position);

#endif /* RACE_H_ */
