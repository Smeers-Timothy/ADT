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

#ifndef ESCALE_H_
#define ESCALE_H_

/**
 * @struct typedef struct Escale_t Escale
 * @brief Structure de donnée contenant les information nécessaire à une Escale
 */
typedef struct Escale_t Escale;

/**
 * @fn Escale create_stopover*(float, float, char*)
 * @brief Allows you to create a stopover
 *
 * @pre p_name != NULL && p_latitude <= 90 && p_latitude >= -90 && p_longitude <= 180 && p_longitude >= -180
 * @post Escale != NULL
 * @param p_latitude The latitude
 * @param p_longitude The longitude
 * @param p_name The name of the stopover
 * @return Escale *l_stopover a pointer to the Escale data structure
 * 			NULL on error
 */
Escale* create_stopover(float p_latitude, float p_longitude, char *p_name);

/**
 * @fn Escale log_time*(Escale*, float)
 * @brief Allows to set the time
 *
 * @pre p_stopover != NULL && p_time >= 0
 * @post p_stopover->s_bestTime0 != p_stopover->s_bestTime && p_stopover->s_bestTime != NULL
 * @param p_stopover A pointer to the Escale structure
 * @param p_time The best time
 * @return Escale* p_stopover A pointer to the Escale structure
 */
Escale* log_time(Escale *p_stopover, float p_time);

/**
 * @fn void free_stopover(Escale*)
 * @brief allows to free the memory allocated for the Escale structure
 *
 * @pre p_stopover != NULL
 * @post p_stopover is allowed
 * @param p_stopover A pointer to the Escale structure
 */
void free_stopover(Escale *p_stopover);

/**
 * @fn float calculate_range(Escale*, Escale*)
 * @brief allows you to calculate the distance between two stopovers
 *
 * @pre p_stopover != NULL && p_secondStopover != NULL
 * @post /
 * @param p_stopover A pointer to the Escale structure
 * @param p_secondStopover A pointer to the Escale structure
 * @return float l_range
 */
float calculate_range(Escale *p_stopover, Escale *p_secondStopover);

/**
 * @fn char get_name*(Escale*)
 * @brief getter for the name of the stopover
 *
 * @pre p_stopover != NULL
 * @post /
 * @param p_stopover A pointer to the Escale structure
 * @return p_stopover->s_name
 */
char* get_name(Escale *p_stopover);

/**
 * @fn float get_latitude(Escale*)
 * @brief getter for the latitude of the stopover
 *
 * @pre p_stopover != NULL
 * @post /
 * @param p_stopover A pointer to the Escale structure
 * @return p_stopover->s_latitude
 */
float get_latitude(Escale *p_stopover);

/**
 * @fn float get_longitude(Escale*)
 * @brief getter for the longitude of the stopover
 *
 * @pre p_stopover != NULL
 * @post /
 * @param p_stopover A pointer to the Escale structure
 * @return p_stopover->s_longitude
 */
float get_longitude(Escale *p_stopover);

/**
 * @fn float get_best_time(Escale*)
 * @brief getter for the best time of the stopover
 *
 * @pre p_stopover != NULL
 * @post /
 * @param p_stopover A pointer to the Escale structure
 * @return p_stopover->s_bestTime
 */
float get_best_time(Escale *p_stopover);

#endif /* ESCALE_H_ */
