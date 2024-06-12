#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <math.h>
#include "text.h"
#include "config.h"
#include "lib.h"

typedef struct DoubleTypedTestResult {
    double result;
    double expected;
} DoubleTypedTestResult;

typedef struct Test {
    DoubleTypedTestResult(*function)(void);
    char* name;
} Test;

DoubleTypedTestResult test_root_1(void) {
    double x = root(lin, zero, one, zero, -1, 1, ROOT_EPS);
    DoubleTypedTestResult result = {x, 0};
    return result;
}

DoubleTypedTestResult test_root_2(void) {
    double x = root(lin_plus2, zero, one, zero, -1, 1, ROOT_EPS);
    DoubleTypedTestResult result = {x, -2};
    return result;
}

DoubleTypedTestResult test_root_3(void) {
    double x = root(lin_plus2, lin_2x, one, two, 0, 10, ROOT_EPS);
    DoubleTypedTestResult result = {x, 2};
    return result;
}

DoubleTypedTestResult test_integral_1(void) {
    double area = integral(lin, zero, 0, 4, ROOT_EPS);
    DoubleTypedTestResult result = {area, 8};
    return result;
}

DoubleTypedTestResult test_integral_2(void) {
    double area = integral(quad, quad_neg, -2, 2, ROOT_EPS);
    DoubleTypedTestResult result = {area, 2.666626};
    return result;
}

DoubleTypedTestResult test_integral_3(void) {
    double area = integral(lin_plus2, zero, -2, 0, ROOT_EPS) + integral(lin_plus2_neg, zero, 0, 2, ROOT_EPS);
    DoubleTypedTestResult result = {area, 4};
    return result;
}

int main(void) {
    size_t tests_amount = 6;
    Test tests[] = {
        { test_root_1, "ROOT TEST ONE" },
        { test_root_2, "ROOT TEST TWO" },
        { test_root_3, "ROOT TEST THREE" },
        { test_integral_1, "INTEGRAL TEST ONE" },
        { test_integral_2, "INTEGRAL TEST TWO" },
        { test_integral_3, "INTEGRAL TEST THREE" },
    };

    int overall_result = 0;
    int overall_time = 0;

    printf("%s\n", gen_separator(50, '>'));
    printf("[%s] %s (%s %d)\n", 
        MSG_TEST_DEFAULT_PREFIX, 
        MSG_TEST_INTRO_HEADER, 
        MSG_TEST_INTRO_HEADER_AMOUNT, 
        tests_amount);

    for (int i = 0; i < tests_amount; ++i) {
        char* test_name = tests[i].name;
        printf("[%s]  %s: \"%s\"...\n", MSG_TEST_DEFAULT_PREFIX, MSG_TEST_HEADER, test_name);
        clock_t start = clock();
        DoubleTypedTestResult current_result = tests[i].function();
        clock_t end = clock();
        int exec_time = end - start;
        int is_success = compare_doubles(current_result.result, current_result.expected);
        char* current_prefix = is_success ? MSG_TEST_SUCCESS_PREFIX : MSG_TEST_FAIL_PREFIX;
        char* current_message_header = is_success ? MSG_TEST_SUCCESS : MSG_TEST_FAIL;
        char* current_color = is_success ? C_GREEN : C_RED;
        overall_result += is_success;
        // NOT ACTUAL MILLISECONDS! Refactor later.
        printf("%s", current_color);
        printf("[%s]  %s %s (%dms)\n", current_prefix, test_name, current_message_header, exec_time / 10);
        printf("[%s]  %s: %lf\n", current_prefix, MSG_TEST_EXPECTED, current_result.expected);
        printf("[%s]  %s: %lf\n\n", current_prefix, MSG_TEST_RESULT, current_result.result);
        printf("%s", C_WHITE);
    }

    printf("[%s]  %s\n", MSG_TEST_DEFAULT_PREFIX, MSG_TEST_OVERRAL_HEADER);
    printf("[%s]  %s %d/%d\n", MSG_TEST_DEFAULT_PREFIX, MSG_TEST_OVERALL_SUCCESS, overall_result, tests_amount);
    printf("[%s]  %s %d/%d\n", MSG_TEST_DEFAULT_PREFIX, MSG_TEST_OVERALL_FAILED, tests_amount - overall_result, tests_amount);
    printf("%s\n", gen_separator(50, '>'));

    return !(overall_result == tests_amount);
}
