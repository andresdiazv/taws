#include "units.h"

#define METERS_PER_FOOT 0.3048
#define FEET_PER_METERS 1.0 / 0.3048

#define METERS_PER_NAUTICAL_MILE 1852.0
#define SECONDS_PER_HOUR 3600.0
#define METERS_PER_SECOND_PER_KNOTS METERS_PER_NAUTICAL_MILE / SECONDS_PER_HOUR
#define KNOTS_PER_METERS_PER_SECOND SECONDS_PER_HOUR / METERS_PER_NAUTICAL_MILE

double feet_to_meters(double feet)
{
    return feet * METERS_PER_FOOT;
}

double meters_to_feet(double meters)
{
    return meters * FEET_PER_METERS;
}

double meters_per_second_to_knots(double meters_per_second)
{
    return meters_per_second * KNOTS_PER_METERS_PER_SECOND;
}

double knots_to_meters_per_second(double knots)
{
    return knots * METERS_PER_SECOND_PER_KNOTS;
}