#include "../src/Day10/Day10Part1.h"
#include "../unity/src/unity.h"

/* *********************** THIS FILE IS USED FOR THE UNIT TEST *********************** */
/*In this file I test my code for calculating the sum of signal strenghts*/

void setUp(void)
{

}

void tearDown(void)
{

}

/*Here I test that my function for calculating the sum of signal strenghts actually gives the corrent answer*/
void test_CalculateSignalStrength(void)
{
    /*The actual register values, X, are*/
    int cycle1[221] = {0};
    cycle1[20] = 21;
    cycle1[60] = 21;
    cycle1[100] = 21;
    cycle1[140] = 17;
    cycle1[180] = 21;
    cycle1[220] = 21;

    TEST_ASSERT_EQUAL_INT(14560, calculate_signal_strenghts(cycle1));
}

/*Here I test that my function can handles zeros correctly*/
void test_CalculateSignalStrengthWithZeros(void)
{
    /*Now the register values are zeros*/
    int cycle2[221] = {0};

    TEST_ASSERT_EQUAL_INT(0, calculate_signal_strenghts(cycle2));
}

/*Run the tests*/
/*Both tests should pass*/
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_CalculateSignalStrength);
    RUN_TEST(test_CalculateSignalStrengthWithZeros);
    return UNITY_END();
}