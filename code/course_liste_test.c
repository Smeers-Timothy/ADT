/**
 * @file test_list.c
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

#include "../code/course.h"
#include "../code/escale.h"
#include "../code/seatest.h"

static void test_add_stopover();
static void test_is_circuit();
static void test_race_time();
static void test_fixture();
static void all_tests();

static void test_add_stopover() {

	Escale *l_firstStopover;
	Escale *l_secondStopover;
	Escale *l_thirdStopover;
	Escale *l_stopover;
	Course *l_race;

	l_firstStopover = create_stopover(18, 32, "Comblain-la_Tour"); /* @suppress("Avoid magic numbers") */
	l_secondStopover = create_stopover(-90, 180, "Sart-Tilmant"); /* @suppress("Avoid magic numbers") */
	l_thirdStopover = create_stopover(-40, 25, "Eupen"); /* @suppress("Avoid magic numbers") */
	l_race = create_list_race(l_firstStopover, l_secondStopover);

	add_end(&l_race, l_thirdStopover);

	l_stopover = obtain_list_stopover(l_race, l_firstStopover);

	assert_float_equal(get_latitude(l_firstStopover),
			get_latitude(l_stopover), 0);

	assert_float_equal(get_longitude(l_firstStopover),
			get_longitude(l_stopover), 0);

	l_stopover = obtain_list_stopover(l_race, l_secondStopover);

	assert_float_equal(get_latitude(l_secondStopover),
			get_latitude(l_stopover), 0);

	assert_float_equal(get_longitude(l_secondStopover),
			get_longitude(l_stopover), 0);

	l_stopover = obtain_list_stopover(l_race, l_thirdStopover);

	assert_float_equal(get_latitude(l_thirdStopover),
			get_latitude(l_stopover), 0);

	assert_float_equal(get_longitude(l_thirdStopover),
			get_longitude(l_stopover), 0);

	free_list_race(l_race);
}

static void test_is_circuit() {

	Escale *l_firstStopover;
	Escale *l_secondStopover;
	Escale *l_thirdStopover;
	Course *l_race;

	l_firstStopover = create_stopover(18, 32, "Comblain-la_Tour"); /* @suppress("Avoid magic numbers") */
	l_secondStopover = create_stopover(-90, 180, "Sart-Tilmant"); /* @suppress("Avoid magic numbers") */
	l_thirdStopover = create_stopover(-40, 25, "Eupen"); /* @suppress("Avoid magic numbers") */
	l_race = create_list_race(l_firstStopover, l_secondStopover);

	add_end(&l_race, l_thirdStopover);
	assert_int_equal(0, is_list_circuit(l_race));

	add_end(&l_race, l_firstStopover);
	assert_int_equal(1, is_list_circuit(l_race));

	free_list_race(l_race);

}

static void test_race_time() {

	Escale *l_firstStopover;
	Escale *l_secondStopover;
	Escale *l_thirdStopover;
	Course *l_race;

	l_firstStopover = create_stopover(18, 32, "Comblain-la_Tour"); /* @suppress("Avoid magic numbers") */
	l_secondStopover = create_stopover(-90, 180, "Sart-Tilmant"); /* @suppress("Avoid magic numbers") */
	l_thirdStopover = create_stopover(-40, 25, "Eupen"); /* @suppress("Avoid magic numbers") */
	l_race = create_list_race(l_firstStopover, l_secondStopover);

	log_time(l_secondStopover, 10); /* @suppress("Avoid magic numbers") */
	log_time(l_thirdStopover, 17); /* @suppress("Avoid magic numbers") */
	add_end(&l_race, l_thirdStopover);

	assert_float_equal(10, stopover_race_time(l_race, l_secondStopover), 0);
	assert_float_equal(17, stopover_race_time(l_race, l_thirdStopover), 0);

	assert_float_equal(27, race_list_time(l_race), 0);

	add_end(&l_race, l_thirdStopover);

	assert_float_equal(44, race_list_time(l_race), 0);

	free_list_race(l_race);

}

static void test_fixture() {

	test_fixture_start();
	run_test(test_add_stopover);
	run_test(test_is_circuit);
	run_test(test_race_time);
	test_fixture_end();
}

static void all_tests() {

	test_fixture();
}

int main() {

	return (run_tests(all_tests));
}
