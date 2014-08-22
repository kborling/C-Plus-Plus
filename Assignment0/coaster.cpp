#include "coaster.h"

/*
 * Multiplies the # of cars by the car capacity
 * to determine overall ride capacity.
 */
int calcRideCapacity(int cars, int capacity)
{
	int rideCapacity = cars * capacity;
	return rideCapacity;
}// End calcRideCapacity

/*
 * Divides the number of people by the ride capacity
 * and takes the ceiling of that result to determine # of runs.
 * Returns 1 if the # of people are <= ride capacity.
 */
int calcRuns(int people, int rideCapacity)
{
	double runs = 0.0;
	
	if(people > rideCapacity)
	{
		runs = ceil((double)people / rideCapacity);
		return (int)runs;
	}
	else
		return 1;
}// End calcRuns