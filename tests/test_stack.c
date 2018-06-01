//
// Created by cubazis on 24.05.18.
//
#include <check.h>
#include "stack.h"

#define TOL_STRICT 1e-9

START_TEST (test_pop)
    {
        push(5);
        push(3);
        push(1.1111);
        push(7);
        push(102);
        push(12456);
        push(0);
        ck_assert_double_eq_tol(pop(), 0, TOL_STRICT);
        ck_assert_double_eq_tol(pop(), 12456, TOL_STRICT);
        ck_assert_double_eq_tol(pop(), 102, TOL_STRICT);
        push(228);
        ck_assert_double_eq_tol(pop(), 228, TOL_STRICT);
        push(1337);
        push(228);
        ck_assert_double_eq_tol(pop(), 228, TOL_STRICT);
        ck_assert_double_eq_tol(pop(), 1337, TOL_STRICT);
        push(8943);
        push(1212);
        push(1212112);
        push(9997);
        ck_assert_double_eq_tol(pop(), 9997, TOL_STRICT);
        ck_assert_double_eq_tol(pop(), 1212112, TOL_STRICT);
        ck_assert_double_eq_tol(pop(), 1212, TOL_STRICT);
        ck_assert_double_eq_tol(pop(), 8943, TOL_STRICT);
        ck_assert_double_eq_tol(pop(), 7, TOL_STRICT);
        ck_assert_double_eq_tol(pop(), 1.1111, TOL_STRICT);
        ck_assert_double_eq_tol(pop(), 3, TOL_STRICT);
        ck_assert_double_eq_tol(pop(), 5, TOL_STRICT);
        ck_assert_double_eq(pop(), -INFINITY);
        ck_assert_double_eq_tol(pop(), -INFINITY, TOL_STRICT);

    }
END_TEST


START_TEST (test_peek)
    {
        //YOUR CODE HERE
    }
END_TEST

START_TEST (test_push)
    {
        //YOUR CODE HERE
    }
END_TEST

Suite *str_suite(void) {
    Suite *suite = suite_create("stack");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_push);
    tcase_add_test(tcase, test_pop);
    tcase_add_test(tcase, test_peek);
    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}