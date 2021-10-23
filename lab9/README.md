# Lab 9: gdb and assembly - Zhuocaili

* Who did you work with?
I worked with TA, going along with Tiffany's instructions.

* How long did this take you?
About 2 hours.

* What external resources did you use (if any)?
- https://sourceware.org/gdb/onlinedocs/gdb/TUI-Commands.html#TUI-Commands

* [Optional] What did you like about this lab?
GDB may be a good tool for us to debug our program.

* [Optional] How could this lab be improved?

## Part 1: Assembler

1. Swap Response/Observations
subq    $16, %rsp changes to subq    $32, %rsp
movl    $1, -4(%rbp) changes to movq    $1, -8(%rbp)
movl    $2, -8(%rbp) changes to movq    $2, -16(%rbp)
movl    -4(%rbp), %eax changes to movq    -8(%rbp), %rax
movl    %eax, -4(%rbp) changes to movq    %rax, -8(%rbp)
movl    -8(%rbp), %eax changes to movq    -16(%rbp), %rax

2. Functions Response/Observations
- Q1:
	movl	-20(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -20(%rbp)

- Q2: 
they are not directlu have changes in bytes, but instead, they are changed by reassiging values between each other

- Q3:
different from the swap_int.s, there is a popq now in the swap function

3. Static Array Response/Observations
addq	$280, %rax;
addq	$288, %rax;

4. For loops Response/Observations
	cmpl	$4, -4(%rbp)
	jle	.L3

   jle means it will jump if less than, then it will go to L3 and go on the loop.

## Part 2: gdb

1. ```prog1```
   * What was the bug?
   When the value of i keeps increasing, if it reaches 10, it would be out of the boundary of integers, then the program with crash.

   * What line did the bug occur?
   It happens in line 11: for(i =0 ; i < 11; i++)

   * What is the fix for the bug?
   Change 11 to 10.

2. ```prog2```
   * What was the bug
   The problem is that the program didn't give the value after creating the integers to myIntegers, making myIntegers keeps NULL
   * What line did the bug occur?
   line31: int* myIntegers;createIntegersList(10);
   * What is the fix for the bug?
   Should change it to:
   int* myIntegers; 
   myIntegers = createIntegersList(10);


## Outstanding Questions

Do you have any outstanding questions you'd like addressed?
The assembler is quite hard to read and understand without cheatsheet.