#ifndef PACKAGENAME_TEMPLATE_H
#define PACKAGENAME_TEMPLATE_H

/**
 * @brief Add two integers
 *
 * @param pA First integer
 * @param pB Second integer
 * @return int Sum of the two integers
 */
int add(int pA, int pB);

/**
 * @brief Subtract two integers
 *
 * @param pA First integer
 * @param pB Second integer
 * @return int Difference of the two integers
 */
int subtract(int pA, int pB);

int multiply(int pA, int pB)
{
    int result = 0;
    int run = 0;
    for (int i = 0; i < pB; i++) { result = add(result, pA); }
    return result;
}

#endif// PACKAGENAME_TEMPLATE_H
