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

#ifndef COURSE_H_
#define COURSE_H_

#include "../code/escale.h"

/**
 * @struct typedef struct Course_t Course
 * @brief Structure de donnée contenant les information nécessaire à une course
 */
typedef struct Course_t Course;

/**
 * @fn Course create_list_race*(Escale*, Escale*)
 * @brief Allows you to initialize the race structure
 *
 * @pre p_stopover != NULL && p_secondStopover != NULL
 * @post a race was create with connection cell
 * @param p_stopover the first stopover
 * @param p_secondStopover the second stopover
 * @return Course * a memory allowed pointer to the header of the course structure
 * 			NULL on error
 */
Course* create_list_race(Escale *p_stopover, Escale *p_secondStopover);

/**
 * @fn Course create_table_race*(Escale*, Escale*)
 * @brief Allows you to initialize the race structure
 *
 * @pre p_stopover != NULL && p_secondStopover != NULL
 * @post a race was create with connection cell
 * @param p_stopover the first stopover
 * @param p_secondStopover the second stopover
 * @return Course * a memory allowed pointer to the header of the course structure
 * 			NULL on error
 */
Course* create_table_race(Escale *p_stopover, Escale *p_secondStopover);

/**
 * @fn Course remove_table_stopover*(Course*, int)
 * @brief Allows you to remove a stopover to the structure
 *
 * @pre p_race != NULL && p_position > 0
 * @post a stopover has been removed
 * @param p_race a pointer to the Course structure
 * @param p_position the position in the list
 * @return Course * a pointer to the header of the course structure
 * 			NULL on error
 */
Course* remove_table_stopover(Course *p_race, int p_position);

/**
 * @fn Course add_table_stopover*(Course*, Escale*, int)
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
Course* add_table_stopover(Course *p_race, Escale *p_stopover, int p_position);

/**
 * @fn Escale obtain_list_stopover*(Course*, Escale*)
 * @brief getter of the data of a cell
 *
 * @pre p_race != NULL && p_stopover != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @param p_stopover a pointer to the Escale structure
 * @return Escale *a pointer to the data Escale structure
 * 			NULL on error
 */
Escale* obtain_list_stopover(Course *p_race, Escale *p_stopover);

/**
 * @fn Escale obtain_table_stopover*(Course*, int)
 * @brief getter of the data of a cell
 *
 * @pre p_race != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @param p_position the position in the list
 * @return Escale *a pointer to the data Escale structure
 * 			NULL on error
 */
Escale* obtain_table_stopover(Course *p_race, int p_position);

/**
 * @fn void add_start*(Course**, Escale*)
 * @brief Allows you to add a stopover at the start
 *
 * @pre p_race != NULL && p_stopover != NULL
 * @post p_stopover0 < p_stopover
 * @param p_race a pointer to the Course structure
 * @param p_stopover a pointer to the Escale structure
 */
void* add_start(Course **p_race, Escale *p_stopover);

/**
 * @fn void add_end*(Course**, Escale*)
 * @brief Allows you to add a stopover at the end
 *
 * @pre p_race != NULL && p_stopover != NULL
 * @post p_stopover0 < p_stopover
 * @param p_race a pointer to the Course structure
 * @param p_stopover a pointer to the Escale structure
 */
void* add_end(Course **p_race, Escale *p_stopover);

/**
 * @fn void add_list_stopover*(Course**, Escale*, int)
 * @brief Allows you to add a stopover to the structure
 *
 * @pre p_race != NULL && p_stopover != NULL
 * @post a stopover has been added
 * @param p_race a pointer to the Course structure
 * @param p_stopover a pointer to the Escale structure
 * @param p_position the position in the list
 */
void *add_list_stopover(Course **p_race, Escale *p_stopover, int p_position);

/**
 * @fn void print_race(Course*)
 * @brief Allows you to display the race in the console
 *
 * @pre p_race != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 */
void print_race(Course *p_race);

/**
 * @fn void remove_list_stopover(Course**, Escale*)
 * @brief Allows you to remove a stopover to the structure
 *
 * @pre p_race != NULL && p_stopover != NULL
 * @post a stopover has been removed
 * @param p_race a pointer to the Course structure
 * @param p_stopover a pointer to the Escale structure
 */
void remove_list_stopover(Course **p_race, Escale *p_stopover);

/**
 * @fn void free_table_race(Course*)
 * @brief Used to free the memory of the Course structure
 *
 * @pre p_race != NULL
 * @post Course *p_race is released
 * @param p_race a pointer to the Course structure
 */
void free_table_race(Course *p_race);

/**
 * @fn void free_list_race(Course*)
 * @brief Used to free the memory of the Course structure
 *
 * @pre p_race != NULL
 * @post Course *p_race is released
 * @param p_race a pointer to the Course structure
 */
void free_list_race(Course *p_race);

/**
 * @fn unsigned int is_table_circuit(Course*)
 * @brief Used to determine if the race is a circuit
 *
 * @pre p_race != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @return 0 if the race is not a circuit
 * 			1 else
 */
unsigned int is_table_circuit(Course *p_race);

/**
 * @fn unsigned int is_list_circuit(Course*)
 * @brief Used to determine if the race is a circuit
 *
 * @pre p_race != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @return 0 if the race is not a circuit
 * 			1 else
 */
unsigned int is_list_circuit(Course *p_race);

/**
 * @fn unsigned int get_table_stopover(Course*)
 * @brief getter of the number of stopover
 *
 * @pre p_race != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @return unsigned int p_race->s_nbrStopover
 */
unsigned int get_table_stopover(Course *p_race);

/**
 * @fn unsigned int get_list_stopover(Course*)
 * @brief getter of the number of stopover
 *
 * @pre p_race != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @return unsigned int p_race->s_nbrStopover
 */
unsigned int get_list_stopover(Course *p_race);

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
 * @fn float stopover_race_time(Course*, Escale*)
 * @brief allows you to find the best time of the stage
 *
 * @pre p_race != NULL && p_stopover != NULL
 * @post /
 * @param p_race a pointer to the Course structure
 * @param p_stopover  pointer to the Escale structure
 * @return float l_time
 * 			NULL on error
 */
float stopover_race_time(Course *p_race, Escale *p_stopover);

/**
 * @fn float race_table_time(Course*)
 * @brief get time to race
 *
 * @pre p_race != NULL
 * @post p_race->s_bestTime0 != p_race->s_bestTime
 * @param p_race a pointer to the Course structure
 * @return float p_race->s_bestTime
 */
float race_table_time(Course *p_race);

/**
 * @fn float race_table_time(Course*)
 * @brief get time to race
 *
 * @pre p_race != NULL
 * @post p_race->s_bestTime0 != p_race->s_bestTime
 * @param p_race a pointer to the Course structure
 * @return float p_race->s_bestTime
 */
float race_list_time(Course *p_race);

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

#endif /* COURSE_H_ */
