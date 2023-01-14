<h1 align="center">
	📖 PUSH_SWAP
</h1>

<p align="center">
	<b><i>Let's swap some push!</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/zstenger93/push_swap?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/zstenger93/push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/zstenger93/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/zstenger93/push_swap?color=green" />
</p>

> _FYI:_

	The algorythm is kinda crappy but good enough for now :]

---

> _My approach:_

	I'm not the the best with algorythms so maybe this repo won't be your best choice, but
	I've tried to keep it simple and as clean as possible

	My solution was quicksort but with sort of random pivot number picking.
	I take the length of the list and divide it by 2 around 100 and by 5 at 500 numbers.
	Depending on that my pivot number will be at 1/2 or 1/5 from the start of the list.

	It's random, but I've found it effective.
	I've been testing for a while t get the best option and this is the best I could get so far.

	With `small lists` it is the usual as for most approach, with  2 number just `swap`,
	then `sort_3` with the 5 possible variations and then `sort_5` with pushing the smallest
	numbers to stack B until 3 left in A, then `sort_3` and move back the 2 smallest to the top.
	To be honest it's not really the most effective because I'm moving numbers around even when
	a simple `RRA` would be enough, but still complies with the requirements very well.

	`Sorting bigger` lists is where the algorythm kicks in.
	So first I have a while loop with the `length` of the list.
	until it's bigger than five I get my `MID` which will be the pivot number so not exactly mid.
	when the element of the list is equal of the `length / 2` or `length / 5` depending on the
	length of the list.
	After I've found the pivot number, I take it in a while statement, until `pivot && length > 5`
	I sort the list to stack `B`. if it's smaller than the pivot `PB` else `RA`/
	When we are out of smaller numbers than pivot && there are more than 5 element left on the list,
	we get another pivot and repeat until only 5 number remains.

	When it's finished, the remaining 5 number on stack `A` is being sorted which are the 5 biggest number.
	Afterwards we start pushing back from `B` to `A` with `sort_to_a` with the following steps.

	For this I have a struct to save space and it's easier anyway.
	Calculate the smallest number on the list.
	Calculate the biggest number on the list.
	Calculate the next biggest number on the list.
	`RB` to get the `current max` to the top of the list.
	Then I have an if statement where I go if the current element of the list is equal to
	`min`, `max` or `next max` then I use `PA`.
	Here I have 2 abomination in my code, the first is the next step.
	If the element of the list equals `next max` and `IS` is set to 0 then now
	`IS = 1` then with the next statement do the actual `SA` and if
	it's equal to `min` count up with `j` and do `RA` to put it on the bottom of the list.
	Then `i++` and `--length` and repeat.
	When everything is moved back to a then `j--` and `RRA` to move the smallest numbers from the
	bottom to the top, `free` the stacks and we are done.

---

## 💡 About the project

> _This project is about writing a program with a sorting algorythm._

	This project will make you sort data on a stack, with a limited set of instructions, using
    the lowest possible number of actions. To succeed you’ll have to manipulate various
    types of algorithms and choose the most appropriate solution (out of many) for an
    optimized data sorting

For more 42 projects [**visit my repository**](https://github.com/zstenger93).

---

## 🛠️ Instructions

### Allowed operations:
> <i>The following commands are available at your hand:
> - `sa` (swap a): Swap the first 2 elements at the top of stack a.
> - `sb` (swap b): Swap the first 2 elements at the top of stack b.
> - `ss` : sa and sb at the same time.
> - `pa` (push a): Take the first element at the top of b and put it at the top of a.
> - `pb` (push b): Take the first element at the top of a and put it at the top of b.
> - `ra` (rotate a): Shift up all elements of stack a by 1.
> - `rb` (rotate b): Shift up all elements of stack b by 1.
> - `rr` : ra and rb at the same time.
> - `rra` (reverse rotate a): Shift down all elements of stack a by 1.
> - `rrb` (reverse rotate b): Shift down all elements of stack b by 1.
> - `rrr` : rra and rrb at the same time.</i>

### Mandatory:
> - <i>You have 2 stacks named a and b.
> - The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
> - You have to write a program named push_swap that takes as an argument the stack
a formatted as a list of integers. The first argument should be at the top of the
stack (be careful about the order).

> - The program must display the smallest list of instructions possible to sort the stack
a, the smallest number being at the top.
> - Instructions must be separated by a ’\n’ and nothing else.
> - The goal is to sort the stack with the lowest possible number of operations. During
the evaluation process, the number of instructions found by your program will be
compared against a limit: the maximum number of operations tolerated. If your
program either displays a longer list or if the numbers aren’t sorted properly, your
grade will be 0.
> - If no parameters are specified, the program must not display anything and give the
prompt back.
> - In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.</i>

### Bonus:
> - <i>Create a checker program for push_swap
> - Add some sprite animation.
> - Display the movement count directly on screen instead of writing it in the shell.
> - Write a program named checker that takes as an argument the stack a formatted
as a list of integers. The first argument should be at the top of the stack (be careful
about the order). If no argument is given, it stops and displays nothing.
> -  It will then wait and read instructions on the standard input, each instruction will
be followed by ’\n’. Once all the instructions have been read, the program has to
execute them on the stack received as an argument.
> -  If after executing those instructions, the stack a is actually sorted and the stack b
is empty, then the program must display "OK" followed by a ’\n’ on the standard
output.
> - In every other case, it must display "KO" followed by a ’\n’ on the standard output.
> - In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments
are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or
is incorrectly formatted.</i>

---

## Usage

> - `Makefile` is configured for both `Mac` and `Linux` use.

### Simply compile with make for mandatory and make bonus for the checker
> - after that you can run with `./push_swap` + `ARGS` or
> - `./push_swap` + `ARGS` + `| wc -l` to get the count of operations or
> - `./push_swap` + `ARGS` + `| wc -l` + `./checker` + `ARGS` or
> - `checker_Mac` / `checker_Linux` from the project page
> - If it's good it will displays OK or KO if not.

---

### 📋 Testing

> - You can just run `make rt` to run a random test:
```shell
$ make rt
```
> - It generates random numbers each time for the arguments:
