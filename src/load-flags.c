#include <stdlib.h>
#include <argp.h>
#include <math.h>
#include "lib.h"
#include "config.h"
#include "text.h"

static struct argp_option options[] = {
    {"help", 'h', 0, 0, MSG_ARGS_HELP, 0},
    {"funcs-list", 'l', 0, 0, MSG_ARGS_LIST, 0},
    {"root", 'r', 0, 0, MSG_ARGS_ROOT, 0},
    {"iterations", 'i', 0, 0, MSG_ARGS_ITERATIONS, 0},
    {"test-root", 'R', "F1:F2:A:B:E:R", 0, MSG_ARGS_TEST_ROOT, 0},
    {"test-integral", 'I', "F1:F2:A:B:E:R", 0, MSG_ARGS_TEST_INTEGRAL, 0},
    {0}
};

MathArguments parse_math_arguments(char* arg) {
    MathArguments result = {0, 0, 0, 0, 0, 0};
    int current_arg = 0;
    int index = 0;
    char buffer[20];
    int buf_size = 0;
    while (1) {
        if (arg[index] == '\0') break;
        if (arg[index] == ':') {
            buffer[buf_size] = '\0';
            switch (current_arg) {
                case 0:
                    result.f = func_by_number(atoi(buffer));
                    result.f_deriv = func_deriv_by_number(atoi(buffer));
                    break;
                case 1:
                    result.g = func_by_number(atoi(buffer));
                    result.g_deriv = func_deriv_by_number(atoi(buffer));
                    break;
                case 2:
                    result.a = atof(buffer);
                    break;
                case 3:
                    result.b = atof(buffer);
                    break;
                case 4:
                    result.eps =atof(buffer);
                    break;
            }
            buf_size = 0;
            index++;
            current_arg++;
            continue;
        }
        buffer[buf_size] = arg[index];
        buf_size++;
        index++;
    }
    if (current_arg != 5) {
        perror("Error");
        exit(1);
    }
    buffer[buf_size] = '\0';
    result.result = atof(buffer);
    return result;
}

static error_t parse_opt (int key, char* arg, struct argp_state* state) {
    Arguments *arguments = (Arguments*)(state->input);

    switch (key) {
        case 'i':
            arguments->iterations = 1;
            break;
        case 'r':
            arguments->root = 1;
            break;
        case 'R':
            arguments->math_args = parse_math_arguments(arg);
            arguments->test_root = 1;
            break;
        case 'I':
            arguments->math_args = parse_math_arguments(arg);
            arguments->test_integral = 1;
            break;
        case 'h':
            arguments->help = 1;
            break;
        case 'l':
            arguments->list = 1;
            break;
        default:
            break;
  }
  return 0;
}

static struct argp argp_parser = {
   .options = options,
   .parser = parse_opt,
   .args_doc = "",
   .doc = APP_NAME,
   .children = NULL,
   .help_filter = NULL,
   .argp_domain = NULL
};

void print_assertion_resilt(double expect, double result, double eps) {
        printf("[%s]  %s...\n", MSG_TEST_DEFAULT_PREFIX, MSG_TEST_HEADER);
        int is_success = fabs(expect - result) < eps;
        char* current_prefix = is_success ? MSG_TEST_SUCCESS_PREFIX : MSG_TEST_FAIL_PREFIX;
        char* current_message_header = is_success ? MSG_TEST_SUCCESS : MSG_TEST_FAIL;
        char* current_color = is_success ? C_GREEN : C_RED;
        printf("%s", current_color);
        printf("[%s]  %s\n", current_prefix, current_message_header);
        printf("[%s]  %s: %lf\n", current_prefix, MSG_TEST_EXPECTED, expect);
        printf("[%s]  %s: %lf\n\n", current_prefix, MSG_TEST_RESULT, result);
        printf("%s", C_WHITE);
}

Arguments load_flags(int flags_amount, char* flags[]) {
    Arguments arguments;

    arguments.iterations = 0;
    arguments.root = 0;
    arguments.test_integral = 0;
    arguments.test_root = 0;
    arguments.help = 0;
    arguments.list = 0;
    argp_parse(&argp_parser, flags_amount, flags, 0, 0, &arguments);

    if (arguments.help) {
        argp_help(&argp_parser, stdout, ARGP_HELP_LONG, NULL);
        exit(0);
    }
    if (arguments.list) {
        printf("%s\n", MSG_FUNCTION_LIST);
        exit(0);
    }

    if (arguments.test_integral) {
        double x = integral(
            arguments.math_args.f, 
            arguments.math_args.g, 
            arguments.math_args.a,
            arguments.math_args.b,
            arguments.math_args.eps);
        print_assertion_resilt(x, arguments.math_args.result, arguments.math_args.eps);
        exit(0);
    }

    if (arguments.test_root) {
        double x = root(
            arguments.math_args.f, 
            arguments.math_args.g, 
            arguments.math_args.f_deriv,
            arguments.math_args.g_deriv,
            arguments.math_args.a,
            arguments.math_args.b,
            arguments.math_args.eps);
        print_assertion_resilt(x, arguments.math_args.result, arguments.math_args.eps);
        exit(0);
    } 

    return arguments;
}
