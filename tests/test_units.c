#include "./unity/unity.h"
#include "../src/units.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/* ---- feet_to_meters ---- */

void test_feet_to_meters_zero(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 0.0, feet_to_meters(0.0));
}

/* 1 ft = 0.3048 m */
void test_feet_to_meters_exact_definition_one_foot(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 0.3048, feet_to_meters(1.0));
}

/* 500 ft is the TAWS height callout */
void test_feet_to_meters_callout_height_500ft(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 152.4, feet_to_meters(500.0));
}

/* altitude differences can be negative */
void test_feet_to_meters_negative_delta(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, -30.48, feet_to_meters(-100.0));
}

/* ---- meters_to_feet ---- */

void test_meters_to_feet_zero(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 0.0, meters_to_feet(0.0));
}

/* 1 / 0.3048 */
void test_meters_to_feet_one_meter(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 3.280839895013123, meters_to_feet(1.0));
}

void test_meters_to_feet_large_value(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 1640.4199475065617, meters_to_feet(500.0));
}

void test_meters_to_feet_negative_delta(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, -328.0839895013123, meters_to_feet(-100.0));
}

/* ---- meters_per_second_to_knots ---- */

void test_mps_to_knots_zero(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 0.0, meters_per_second_to_knots(0.0));
}

/* 3600 s/h divided by 1852 m/NM */
void test_mps_to_knots_one_mps(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 1.9438444924406047, meters_per_second_to_knots(1.0));
}

void test_mps_to_knots_large_value(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 971.9222462203023, meters_per_second_to_knots(500.0));
}

void test_mps_to_knots_negative_delta(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, -194.38444924406047, meters_per_second_to_knots(-100.0));
}

/* ---- round trip ---- */

void test_feet_meters_round_trip(void)
{
    TEST_ASSERT_DOUBLE_WITHIN(1e-9, 1234.5, meters_to_feet(feet_to_meters(1234.5)));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_feet_to_meters_zero);
    RUN_TEST(test_feet_to_meters_exact_definition_one_foot);
    RUN_TEST(test_feet_to_meters_callout_height_500ft);
    RUN_TEST(test_feet_to_meters_negative_delta);

    RUN_TEST(test_meters_to_feet_zero);
    RUN_TEST(test_meters_to_feet_one_meter);
    RUN_TEST(test_meters_to_feet_large_value);
    RUN_TEST(test_meters_to_feet_negative_delta);

    RUN_TEST(test_mps_to_knots_zero);
    RUN_TEST(test_mps_to_knots_one_mps);
    RUN_TEST(test_mps_to_knots_large_value);
    RUN_TEST(test_mps_to_knots_negative_delta);

    RUN_TEST(test_feet_meters_round_trip);

    return UNITY_END();
}