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
