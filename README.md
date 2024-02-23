FEM Coding Assignment: Quadrature Points and the Isoparametric Element Jacobian
===============================================================================

This assignment extends the Q4, Q9, CST, and LST elements that you implemented in PS03 to
include quadrature weights and points, as well as to add the calculation of the Jacobian.

Initial setup (same as before)
------------------------------

1. Check out the problem repository
    
         git clone https://github.com/solidsgroup/EM525-PS04.git
   
2. Change into the problem directory

         cd EM525-PS04
   
3. Use this command to install eigen (optional: you can skip this if you have eigen installed)

         make eigen

4. Now, compile the code

         make

   You should see a number of warnings indicating "no return statement".
   These should disappear once you have implemented the assignment.

Part 1: Adding quadrature points and weights
--------------------------------------------

You will find two TODOs in each of the following files:

- `src/Element/LST.H`
- `src/Element/CST.H`
- `src/Element/Q4.H`
- `src/Element/Q9.H`

To address the todo items:
1. For the `eta` and `deta` functions, simply copy/paste your implementations from PS03.
2. For the `getArea` function, you can simply return a value (like `return 1.0;` if the area of
   the template element is 1.0).
3. For `Qp`, add vectors corresponding to the quadrature points. (This should be a comma-separated list of
   `Eigen::Vector2d`s, like for `Y0`.
4. For `Qw`, add a comma-separated list of weights corresponding to the quadrature points.

Part 2: Implement the Jacobian matrix calculation
-------------------------------------------------

You will find a TODO in the following file:

- `src/Element/Element.H`

(Note that this is an **abstract parent element**, meaning that everything you imlement here is
automatically inherited by all of the other elements.)

Follow the instructions to implement the Jacobian matrix.


Check result
------------

You will find a TODO in the following file:

- `src/main.cpp`

Follow the instructions in this file to create a CST element with embedded coordinates
(recommended that you use the coordinates in the CST example in the notes.)
When you have completed the example, running `./bin/main` will run the tests, followed by
the output from your test.

Play around with the inputs `X0` to ensure that this implmentation makes sense.
Provide a brief discussion in your submission.





