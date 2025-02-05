# 🔢 ABOUT push_swap

In this project, I developed a sorting algorithm for a specific problem using two stacks. The goal of the project is to efficiently sort a stack of integers using a set of predefined operations.

#### 1º - Enter the project folder and run `make`
```bash
cd push_swap
make fclean && make
```
#### 2. Basic Tests
Verify if the program correctly sorts small sequences:
```bash
./push_swap 2 1 3
./push_swap 5 4 3 2 1
./push_swap 3 1 2 6 4
```
#### 3. Invalid Input Tests
Ensure that invalid inputs return Error:
```bash
./push_swap 2 2 3          # Duplicate numbers
./push_swap 2147483648 1 2 # Exceeds INT_MAX
./push_swap -2147483649 2 3 # Below INT_MIN
./push_swap a b c          # Invalid characters
./push_swap " "            # Empty input
```
#### 4. Already Sorted Sequences
Ensure that the program does not output unnecessary operations when the stack is already sorted:
```bash
./push_swap 1 2 3 4 5
./push_swap -10 -5 0 5 10
```
If no output is printed, the program correctly detects sorted sequences.

#### 5. Measuring the Number of Operations (Efficiency)
Run tests to measure the number of operations needed to sort different sequence sizes:
```bash
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | wc -l
ARG=$(seq 1 500 | shuf); ./push_swap $ARG | wc -l
ARG=$(seq 1 1000 | shuf); ./push_swap $ARG | wc -l
```
Expected results:
100 numbers → ≤ 900 operations
500 numbers → ≤ 5500 operations
1000 numbers → ≤ 11500 operations
If the number of operations is significantly higher, optimizations may be needed.

#### 6. Validate Sorting with checker
If you have a checker program, ensure that push_swap produces a valid sorting sequence:
> If you have problems running the `./checker`, use `chmod 777 ./checker` and try again.
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
To verify how the program handles extreme values, run:
```bash
./push_swap 9 0 -217 2147483647 -2147483648 | ./checker 9 0 -217 2147483647 -2147483648
```
#### 7. Memory Leak Detection (valgrind)
```bash
valgrind --leak-check=full ./push_swap 5 1 2 3 4
ARG=$(seq 1 100 | shuf); valgrind --leak-check=full ./push_swap $ARG
```
At the end of the report, it should display:
`All heap blocks were freed -- no leaks are possible`
If memory leaks are detected, review allocation (malloc) and deallocation (free) logic.

#### 8. Analyze the Sequence of Operations
Check if the push_swap algorithm generates an optimized sequence:
```bash
./push_swap 3 2 1 | cat -e
./push_swap 5 1 2 3 4 | cat -e
```
If unnecessary operations (e.g., ra followed by rra) appear, further optimizations may be required.

#### 9. Performance Testing
Test the program on large datasets to assess stability and efficiency:
```bash
ARG=$(seq 1 1000 | shuf); ./push_swap $ARG | wc -l
```
If the number of operations exceeds 11500, optimization is needed.

#### 10. Running the Push-Swap Tester
If using an automated tester, run:
```bash
cd Push-Swap-Tester
bash push_swap_test_linux.sh
```
If the tester cannot find push_swap
Copy the push_swap binary to the tester directory:
```bash
cp ../push_swap .
```

#### MAKEFILE RULES

`make` - Compile push_swap **mandatory** functions.

`make bonus` - Compile push_swap **bonus** functions.

`make all` - Compile **mandatory** + **bonus** functions.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.


## MANDATORY
#### RULES
> The program is only allowed to work with two stacks, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

Possible actions:
- [x] `pa` **(push A)**: Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
- [x] `pb` **(push B)**: Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
- [x] `sa` **(swap A)**: Swap the first 2 elements at the top of stack A. Do nothing if there are only one or no elements.
- [x] `sb` **(swap B)**: Swap the first 2 elements at the top of stack B. Do nothing if there are only one or no elements.
- [x] `ss`: `sa` and `sb` at the same time.
- [x] `ra` **(rotate A)**: Shift all elements of stack A up by 1. The first element becomes the last one.
- [x] `rb` **(rotate B)**: Shift all elements of stack B up by 1. The first element becomes the last one.
- [x] `rr` : `ra` and `rb` at the same time.
- [x] `rra` **(reverse rotate A)**: Shift all elements of stack A down by 1. The last element becomes the first one.
- [x] `rrb` **(reverse rotate B)**: Shift all elements of stack b down by 1. The last element becomes the first one.
- [x] `rrr` : `rra` and `rrb` at the same time.

#### GRADE
> The grade depends on how efficient the program's sorting process is.
 
- [x] Sorting **3 values**: no more than **3 actions**.
- [x] Sorting **5 values**: no more than **12 actions**.
- [x] Sorting **100 values**: **rating from 1 to 5 points** depending on the number of actions:

- [x] **5 points** for less than **700 actions**.
- [x] **4 points** for less than **900 actions**.
- [x] **3 points** for less than **1100 actions**.
- [x] **2 points** for less than **1300 actions**.
- [x] **1 point** for less than **1500 actions**.
- [x] Sorting **500 values**: **rating from 1 to 5 points** depending on the number of actions:

- [x] **5 points** for less than **5500 actions**.
- [x] **4 points** for less than **7000 actions**.
- [x] **3 points** for less than **8500 actions**.
- [x] **2 points** for less than **10000 actions**.
- [x] **1 point** for less than **11500 actions**.

> Note: Validating the project requires at least 80/100. I believe 3 points with 100 and 500 numbers would be 80/100.

#### ERROR MANAGEMENT
> The program should print `Error` + `\n` if the following tests are made:

- [x] Non-numeric parameters.
- [x] Duplicate numeric parameter.
- [x] Numeric parameter greater than INT_MAX.
- [x] Numeric parameter less than INT_MIN.

```bash
./push_swap 4 bb 2
./push_swap 4 4 5
./push_swap 4 2 2147483648
./push_swap 4 2 -2147483649
```

#### SORTED EXAMPLES
> Should not print anything if the following tests are made:

- [x] No parameter.
- [x] Single numeric argument.
- [x] The numbers are already sorted.

```bash
./push_swap
./push_swap 42
./push_swap 0 1 2 3
./push_swap 0 1 2 3 4 5 6 7 8 9
```