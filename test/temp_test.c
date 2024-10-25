#include "PackageName/template.h"
#include <stdio.h>
#include <assert.h>

#include <check.h>

// NOLINTBEGIN

START_TEST(test_add)
{
    ck_assert_int_eq(add(2, 3), 5);
    ck_assert_int_eq(add(-1, 1), 0);
    ck_assert_int_eq(add(0, 0), 0);
}
END_TEST

START_TEST(test_subtract)
{
    ck_assert_int_eq(subtract(5, 3), 2);
    ck_assert_int_eq(subtract(1, 1), 0);
    ck_assert_int_eq(subtract(0, 0), 0);
}
END_TEST

// NOLINTEND

TCase *test_case(void)
{
    TCase *tc = tcase_create("test_case");
    tcase_add_test(tc, test_add);
    tcase_add_test(tc, test_subtract);
    return tc;
}
