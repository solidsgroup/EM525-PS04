FEM Coding Assignment: LST, Q4, Q9 Shape Functions
==================================================

This assignment is similar to assignment 2: the objetive is to implement shape functions for 
linear strain triangle (LST), bilinear quadrilateral (Q4), and Larange quadrilateral (Q9) elements.

Initial setup
-------------

1. Check out the problem repository
    
         git clone https://github.com/solidsgroup/EM525-PS04.git
   
2. Change into the problem directory

         cd EM525-PS04
   
3. Use this command to install eigen (optional: you can skip this if you have eigen installed)

         make eigen

4. Now, compile the code

         make

5. Compile the code again (using `make`) and run with `./bin/main`.
   The output should indicate that the DiracTest, SumToUnityTest, and EtaDerivativeTest passes for
   CST (which you implemented before), and that it fails for LST, Q4, and Q9.

Implementation
--------------

You will find two TODOs in each of the following files:

- `src/Element/LST.H`
- `src/Element/Q4.H`
- `src/Element/Q9.H`

For each of these, you must compute the shape functions (eta) and their derivatives (deta), just as you 
did for the CST element.
Note that the shape functions are all given to you in the notes; you only need to implement them and
compute their derivatives.

Check result
------------

You will know that the implementation is successful if all of the tests pass. 
For your reference:

- The "Weak Dirac" test checks that each shape function returns 1 for its associated node and zero
  for all other nodes. The error message will tell you which shape function / node is problematic.

- The "SumToUnity" test checks that all the shape functions sum to one for points sampled randomly
  inside the element.

- The "EtaDerivative" checks the exact derivative (deta) against a numerically calculated derivative
  to ensure consistency.





