# Programming Contests Library by Filip Hlasek

The goal of this project is to provide basic algorithms and data structures which are often useful when solving problems in a short term [programming competitions](https://en.wikipedia.org/wiki/Competitive_programming). During these competitions it is very important to be able to implement and debug your solution as quickly as possible. On the other hand, small optimizations and running time tweaks usually do not make a big difference. This library is supposed to accompany the programming language standard library and simplify implementation of common patterns which might be difficult to debug during the live contest.

**Goals**

* Provide a reasonably general implementation of well-known algorithms and data structures.
* Ensure correctness and stability by testing.
* Make it clear what the time complexity and memory complexity is.
* Write easy to understand and well documented code which is easily adjustable for a specific problem.

**Non-goals**

* Optimize the implementation for the cost of clarity.
* Re-implement standard library algorithms and data structures.
* Have the best known algorithm for the specific problem (sometimes easier and more clear algorithm might be more useful).
* Provide the most general version of the algorithm or data structure.

# Content

Currently, you can find two useful things here:

* [algorithms](./algorithms) - the implementation of the algorithms in C++ programming language.
* [environment](./environment) - the configuration of tools which which make it easier to participate in programming contests.

# Usage

During a programming competition copy the corresponding function from the library directly to the source code of the solution and call it in your code. Alternatively, you can use it as a header-only library, but usually it is not permitted to submit more than one source file as a solution.

# Testing

All of the provided algorithms were used in a programming competition several times. There should always be a reference solution using the particular implementation and a link to an online judge which can evaluate the validity of the solution. Alternatively, there might also be an input file with the corresponding correct output.
