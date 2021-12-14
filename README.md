
# PL Interpeter

## Project Description
The main goal of this project is to write an implmentation for the extended PL language. The program would be able to read and execute a program described in an input file and would print the final state of all variables involved in the computation.

## Research/Design
Below is the overall structure of the program:

1. Parse command-line flags
2. Allocate variable and label scope. **avl_alloc_tree**
3. Add each variable declared in the command-line flags into variable scope (**avl_insert**)
4. Open and Parse Input File, yielding a statement graph.
5. **statement =** start
6. **while statement != NULL**:
  1. Execute statement, yielding the next statement to execute.
  2. **statement =** next statement
7. Print all variables in scope
8. Free statement graph
9. Free scopes
10. Free command-line flags

## Implementation/Tools Used
 - Use Bison and Flex for generating the parser.
 - Use GMP for integer computation.
 - Use Reference Counting for determining when to call **free** on **malloc**-ed memory.
 - Use Make and GCC for building and compiling the program. Make is also used for building GMP if not already installed in the system.
 - **mpz_add**, **mpz_sub**, **mpz_mul**, and **mpz_fdiv_q** are the functions in the GMP library for doing additiona, subtraction, multiplication and division respectively.
 - **libavl** can be used to create a binary tree to map variable names to values. (**avl_alloc_tree** \& **avl_search**).

## Testing/Samples
		$ ./gen/pl -d `x = 3' -d `y = 5' ./examples/addition.txt
		x = 3, y = 5, z = 8
		$ ./gen/pl -d `x = 9' -d `y = 3' ./examples/multiplication.txt
		x = 9, y = 3, z = 27
		$ ./gen/pl -d `b = 3' -d `e = 5' ./examples/exponential.txt
		b = 3, e = 5, z = 243
		$ ./gen/pl -d `x = 3' -d `y = 5' ./examples/arithmetic.txt
		a = 8, b = 0, c = 15, d = 0, e = 0, f = 1, g = 0, h = 0, i = 1, j = 1, k = 1, l = 1, m = 0, x = 3, y = 5
		$ ./gen/pl -d `x = 3'./examples/fibonacci.txt
		a = 2, b = 3, c = 3, x = 0
		$ ./gen/pl -d `a = 3' -d `b = 5' -d `c = 2' ./examples/sort-3.txt
		a = 3, b = 5, c = 2, switch = 1, x = 2, y = 3, z = 5

## Goals Reached

 - Rearrange grammar such that **bison** & **flex** can generate a parser without errors. (done)

 - Use the reduction rules in generated parser to generate expression trees and statement graphs. (done)

 - Implement main computation loop and expression evaluation code using GMP for integer computation. (done)

 - Ensure that at the execution of the program there are no memory leaks and that there are no valgrind errors. (done)

 - Ensure that any input file that follows the above grammar could be executed by the program. This goal was not met for two reasons:
   - Programs with unreachable statements would result in an error. This is due to the fact that as the parses reads the input file, statement structs are allocated with references to the statements that would be transitioned to. For instance, an **if** statement has a reference to the first statement of the true case, as well as a reference to the first statement of the false case. These are the two paths forward in execution. Currently, the program throws an error if it cannot connect the whole program together in one long chain of references because as of right now, the program uses the chain of references to free the allocated statements at the end of execution and by allowing for multiple disconnected chains we would no longer be able to (conveniently) ensure no memory leaks.
   - GOTOs can only go upwards in the file. This is due to the fact that according to the language specifcation, labels can be reassigned, and that a GOTO should transition to the statement most recently assigned to the given label at the time of parsing the GOTO. This behaviour does function but made it difficult to also implement the ability for GOTOs to refer to labels yet-to-be-declared.

## References
 -  https://gmplib.org/
 -  https://www.gnu.org/software/make/manual/html\_node/Automatic-Variables.html
 -  Theory of Computation by Walter S. Brainerd, page 38.






















