/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Compiled using g++ and cl
 * To run, redirect input file in command prompt.
 * When compiling with cl, had to use /EHsc to resolve the exception handler warning.
 * Also, cl complained about cstdlib when trying to compile outside of developer command prompt.
 */

#include "coaster.h"

int main(void)
{
	int c, n, p, rideCapacity, runs;

	while (cin >> c >> n >> p)
	{
		if(c == 0 && c == n && n == p)
			break;

		rideCapacity = calcRideCapacity(c, n);
		runs = calcRuns(p, rideCapacity);

		cout << runs << endl;
	}


	return EXIT_SUCCESS;
}// End main