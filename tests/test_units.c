#include "./unity/unity.h"
#include "../src/units.h"

void setUp(void)
{

}

void tearDown(void)
{

}

void test_0_feet(void)
{
    // <tolerance>, <expected>, <actual>
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 0, feet_to_meters(0));
}

void test_1_feet(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 0.3048, feet_to_meters(1));
}

void test_500_feet(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 152.4, feet_to_meters(500));
}

void test_negative_100_feet(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, -30.48, feet_to_meters(-100));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_0_feet);
    RUN_TEST(test_1_feet);
    RUN_TEST(test_500_feet);
    RUN_TEST(test_negative_100_feet);
    return UNITY_END();
}