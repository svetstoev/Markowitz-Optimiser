# Portfolio-Optimiser
Solving the Markowitz model for a range of target returns

**1. Initial requirements**

In order to make use of the project, the user should have the C++ 14 package installed on their PC, so that they can compile and run the codes included in the current repository.

**2. Main Components and Getting Started**

- `csv.h` and `csv.cpp` – used to store all the operations needed for the work with csv files.
- `Matrix.h` and `Matrix.cpp` which defines two new types – `Vector` and `Matrix` as well as the mathematical operations that can be used with them.
- `returnData.h` and `returnData.cpp` – as the name implies, those were used in order to read and return the data from the csv file provided. The class is deliberately not linked with any other classes and placed into a separate header file so that it can be easily accessed on its own and used for reading other files as well (by just changing the name of the file).
- `porfolioSolver.h` and `poertfolioSolver.cpp` – those are the most important files in the project since they contain all the functions needed to create the Markowitz portfolio, as well as to execute the back-testing after that. 
- `class inSample` and `class outOfSample` – those two classes inherit from `class Portfolio`. They have a very simple but a crucial role. They both include the virtual function `NPeriods()` which means that whenever we create an object from one of those classes, it will have access to all the public members/ functions of `class Portfolio`, but will execute them with a window size (number of periods) which applies only to the corresponding ‘child’ class. This aspect of the code is crucial for creating the back-testing algorithm.
- The `backTester.h` and `backTester.cpp` consist of the actual back-testing algorithm which makes references to the classes already created. There was not really a need to place it in a separate header file, however, it is done again in order to create a neater and more user-friendly experience. 
- Finally, the only thing that we need to do in `Main.cpp` is to create the return Matrix using the `returnMatrix.h` library and call the `backTesting` function which takes as arguments the newly created return matrix, the target return of our choice, as well as the sizes of the in-sample and out-of-sample windows (in case we want to play with them and change their values from the ones originally stipulated). 
- Please notice that the initializing values for lambda, miu as well as the initial portfolio weights needed to set off the algorithm have been manually hard-coded (lambda=1,miu=1,equal weights assumed, i.e. 1/NAssets). However, the code could be easily modified in order to take them as inputs from a public member function defined in `class Portfolio`.

**3. License**

The files included in this repository are covered under the MIT license.

**4. Author**

Svetlozar Stoev
