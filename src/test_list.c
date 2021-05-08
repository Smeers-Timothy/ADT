#include "race.h"
#include "seatest.h"
#include "stopover.h"

static void test_add_stopover() {

	Escale *l_firstStopover;
	Escale *l_secondStopover;
	Escale *l_thirdStopover;
	Escale *l_stopover;
	Course *l_race;


	l_firstStopover = create_stopover(10, 10, "Liege");
	l_secondStopover = create_stopover(55555.55, 4444, "Bruxelles");
	l_thirdStopover = create_stopover(25, 25, "Namur");
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

	l_firstStopover = create_stopover(10, 10, "Liege");
	l_secondStopover = create_stopover(55555.55, 4444, "Bruxelles");
	l_thirdStopover = create_stopover(25, 25, "Namur");
	l_race = create_list_race(l_firstStopover, l_secondStopover);

	add_end(&l_race, l_thirdStopover);
	assert_int_equal(0, is_list_circuit(l_race));

	add_end(&l_race, l_firstStopover);
	assert_int_equal(1, is_list_circuit(l_race));
	assert_int_equal(3, get_list_stopover(l_race));

	remove_list_stopover(&l_race, l_firstStopover);
	assert_int_equal(2, get_list_stopover(l_race));

	free_list_race(l_race);

}

static void test_race_time() {

	Escale *l_firstStopover;
	Escale *l_secondStopover;
	Escale *l_thirdStopover;
	Course *l_race;

	l_firstStopover = create_stopover(10, 10, "Liege");
	l_secondStopover = create_stopover(55555.55, 4444, "Bruxelles");
	l_thirdStopover = create_stopover(25, 25, "Namur");
	l_race = create_list_race(l_firstStopover, l_secondStopover);

	log_time(l_secondStopover, 10);
	log_time(l_thirdStopover, 17);
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
