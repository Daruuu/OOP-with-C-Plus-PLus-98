/*
 * Acutest - A unit testing facility for C.
 * Copyright (c) 2013-2022 Martin Mitas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 */

#ifndef ACUTEST_H
#define ACUTEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifndef TEST_NO_MAIN
static int acutest_run_(int argc, char** argv);
int main(int argc, char** argv) { return acutest_run_(argc, argv); }
#endif

#define TEST_LIST const struct acutest_test_ acutest_test_list_[]
#define TEST_CHECK(cond) acutest_check_((cond), #cond, __FILE__, __LINE__)
#define TEST_ASSERT(cond) do { if (!acutest_check_((cond), #cond, __FILE__, __LINE__)) return; } while(0)
#define TEST_CASE(name) { #name, name }

struct acutest_test_ {
    const char* name;
    void (*func)(void);
};

extern const struct acutest_test_ acutest_test_list_[];

static int acutest_test_count_ = 0;
static int acutest_test_failed_ = 0;
static int acutest_test_passed_ = 0;
static int acutest_current_test_failed_ = 0;
static const char* acutest_current_test_name_ = NULL;

static void acutest_print_verdict_(void) {
    printf("\nSummary: %d tests run, %d passed, %d failed.\n",
           acutest_test_count_, acutest_test_passed_, acutest_test_failed_);
}

static int acutest_check_(int cond, const char* cond_str, const char* file, int line) {
    if (!cond) {
        if (!acutest_current_test_failed_) {
            acutest_current_test_failed_ = 1;
            acutest_test_failed_++;
        }
        printf("  %s:%d: Check failed: %s\n", file, line, cond_str);
        return 0;
    }
    return 1;
}

static int acutest_run_(int argc, char** argv) {
    (void)argc; (void)argv;
    for (acutest_test_count_ = 0; acutest_test_list_[acutest_test_count_].name; acutest_test_count_++) {
        acutest_current_test_name_ = acutest_test_list_[acutest_test_count_].name;
        acutest_current_test_failed_ = 0;
        printf("Test %s... ", acutest_current_test_name_);
        acutest_test_list_[acutest_test_count_].func();
        if (!acutest_current_test_failed_) {
            acutest_test_passed_++;
            printf("OK\n");
        }
    }
    acutest_print_verdict_();
    return (acutest_test_failed_ > 0);
}

#endif /* ACUTEST_H */
