#include <check.h>

extern TCase *test_case(void);

Suite *test_suite(void)
{
    Suite *s = suite_create("test_suite");
    suite_add_tcase(s, test_case());
    return s;
}

int main()
{
    SRunner *sr = srunner_create(test_suite());
    srunner_run_all(sr, CK_ENV);
    int numbeFailed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return numbeFailed;
}
