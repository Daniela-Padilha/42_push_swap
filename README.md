## About

Push Swap is a 42 school algorithm project aimed to better understand structures, algorithms and the concept of complexity, where we must sort a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.

## Build

Clone the repository:

```shell
git clone https://github.com/Daniela-Padilha/42_push_swap.git
```
Enter the cloned directory
```shell
cd 42_push_swap
```
Run `make` to compile the program without bonus:
```shell
make
```

## Usage examples

```shell
./push_swap 5 1 4763 -34
```
Or
```shell
./push_swap "5 1 4763 -34"
```
The program returns "Error" in case letters or duplicate numbers are provided.

If the arguments are valid, the program will output the list of operations performed to sort the list in the most efficient way.

## Push_Swap Rules and Grading

The program is only allowed two stacks to work with, stack a and stack b. The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated. The stack b is empty.

The possible operations are:

* ```sa``` (swap a): Swap the first 2 elements at the top of stack a.
                      Do nothing if there is only one or no elements.

* ```sb``` (swap b): Swap the first 2 elements at the top of stack b.
                    Do nothing if there is only one or no elements.

* ```ss```: ```sa``` and ```sb``` at the same time.

* ```pa``` (push a): Take the first element at the top of b and put it at the top of a.
                      Do nothing if b is empty.

* ```pb``` (push b): Take the first element at the top of a and put it at the top of b.
                      Do nothing if a is empty.

* ```ra``` (rotate a): Shift up all elements of stack a by 1.
                      The first element becomes the last one.

* ```rb``` (rotate b): Shift up all elements of stack b by 1.
                      The first element becomes the last one.

* ```rr```: ```ra``` and ```rb``` at the same time.

* ```rra``` (reverse rotate a): Shift down all elements of stack a by 1.
                                The last element becomes the first one.

* ```rrb``` (reverse rotate b): Shift down all elements of stack b by 1.
                                The last element becomes the first one.

* ```rrr``` : ```rra``` and ```rrb``` at the same time.

The grade depends on how efficient the sorting process is.
 
* Sorting 3 values: no more than 3 actions.
* Sorting 5 values: no more than 12 actions.
* Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 700 actions
  * 4 points for less than 900
  * 3 points for less than 1100
  * 2 points for less than 1300
  * 1 point for less than 1500
* Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 5500 actions
  * 4 points for less than 7000
  * 3 points for less than 8500
  * 2 points for less than 10000
  * 1 point for less than 11500

## Sources

[Video Tutorial](https://www.youtube.com/watch?v=wRvipSG4Mmk&t=1435s&ab_channel=Thuggonaut)

[The Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)


## The Norm

This project is written in accordance to the 42 School's ["The Norm"](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) (_Version 4_).
