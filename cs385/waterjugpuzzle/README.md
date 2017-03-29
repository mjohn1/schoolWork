Michael A. John
Fall 2014
Water Jug Puzzle project

Given 6 numbers, where the first 3 are the capacity limits of three water jugs and the latter 3 numbers is the goal state of the system, find and display the steps taken to achieve the goal states of all three water jugs.

This project had a number of assumptions:
This was the hierarchy of pour structure, without it, choosing a starting water jug would result in oddities from solution to solution.
1) Pour from C to A
2) Pour from B to A
3) Pour from C to B
4) Pour from A to B
5) Pour from B to C
6) Pour from A to C

We also assumed that all the water started in the third jug, jug C. This helps understand why the assumptions above start with C to A.

This was a tough one.