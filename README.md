Pacman Path Calculator (Dynamic Programming)
This repository contains a C implementation of a grid-based pathfinding problem.
The program calculates the total number of unique paths a character can take to move from the top-left corner (0, 0) to the bottom-right corner (n-1, m-1) of a grid, moving only down or right.

Logic and Implementation
The solution utilizes Dynamic Programming to efficiently count paths.
Since the number of possible paths increases exponentially with grid size, the result is calculated modulo 16561 to prevent integer overflow and meet specific problem constraints.

Algorithm
The number of ways to reach any specific cell (i, j) is the sum of the paths leading to its neighbors from which a move is possible (the cell directly above and the cell directly to the left): dp[i][j] = (dp[i-1][j] + dp[i][j-1]) mod 16561.
Cells in the first row and first column are initialized to 1.
