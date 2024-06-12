#ifndef TEXT_INCLUDED
#define TEXT_INCLUDED

// ERRROR MESSAGES
#define MSG_ERR_ROOT_NOTFOUND "Error: root not found. Please, check the search interval validity."
#define MSG_ERR_INTEGRAL_NOTFOUND "Error: integral result is invalid or infinite."

// RESULT MESSAGES
#define MSG_RESULT_INTEGRAL "Area between three given functions is"
#define MSG_RESULT_ITERATIONS "Iterations counted during root computation"
#define MSG_RESULT_ROOTS "Anchor points to integral calculation aka roots (least to most) are:"

// TEST MESSAGES
#define MSG_TEST_DEFAULT_PREFIX "TEST"
#define MSG_TEST_SUCCESS_PREFIX "DONE"
#define MSG_TEST_FAIL_PREFIX "FAIL"
#define MSG_TEST_INTRO_HEADER "app testing."
#define MSG_TEST_INTRO_HEADER_AMOUNT "tests amount:"
#define MSG_TEST_HEADER "Running test"
#define MSG_TEST_SUCCESS "test is successful!"
#define MSG_TEST_FAIL "test is failed!"
#define MSG_TEST_RESULT "Test result"
#define MSG_TEST_EXPECTED "Was expected"
#define MSG_TEST_OVERRAL_HEADER "All tests finished. "
#define MSG_TEST_OVERALL_SUCCESS "Successful tests:"
#define MSG_TEST_OVERALL_FAILED "Failed tests:"
#define C_GREEN "\x1B[32m"
#define C_RED "\x1B[31m"
#define C_WHITE "\x1B[37m"

// ARGS DESCRIPTIONS
#define MSG_ARGS_HELP "Output help message."
#define MSG_ARGS_ROOT "Count intersection points of three given functions."
#define MSG_ARGS_LIST "Functions numbers."
#define MSG_ARGS_ITERATIONS "Count root finding cycle iterations."
#define MSG_ARGS_TEST_INTEGRAL "Manually call integral function: of functions F1 and F2 on interval A and B with epsilon value E, assert with R value."
#define MSG_ARGS_TEST_ROOT "Manually call root function: of functions F1 and F2 on interval A and B with epsilon value E, assert with R value."

// FUNCTION CODES
#define MSG_FUNCTION_LIST "1  - f(x) = ln(a)\n2  - f(x) = -2x + 14\n3  - f(x) = 1/(2-x) + 6\n4  - f(x) = x\n5  - f(x) = x + 2\n6  - f(x) = -x + 2\n7  - f(x) = -x\n8  - f(x) = 0\n9  - f(x) = 1\n10 - f(x) = 2\n11 - f(x) = 2x\n12 - f(x) = x^2\n13 - f(x) = -x^2 + 2"

#endif
