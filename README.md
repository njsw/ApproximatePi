# ApproximatePi
Visualization of Monte Carlo approximation of Pi utilizing SDL2. Code was written quickly with the point being to quickly visualize the approximation algorithm (viewer discretion is advised).

ApproximatePi executable is available (this is a unix executable). Any OS not compatible will have to build the src files manually and link SDL2.

# Approximation Algorithm
The approximation algorithm is based on Monte Carlo, which randomly selects a point inside a square bounded by (-1,1), (1,1), (-1,-1), and (1,-1). This square is special because it can have a unit circle perfectly inscribed within it's boundaries. The unit circle has an area equal to pi, since its radius is a single unit.

The algorithm proceeds to draw a random point and plot it within the square. The standard distance formula is employed to determine whether the selected point is within the unit circle. After sufficiently large sampling the value of pi can be approximated to reasonable precision using the following formula:

<img src="/media/Equation.gif" />

where 4 is the sampling area, c_in is the number of points that fall inside the unit circle, and c_out is the number of points that fall outside the unit circle.
