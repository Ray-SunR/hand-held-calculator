#Hand-held Digital Calculator
Contributor: Renchen Sun
##Compilation
The program can be compiled by using the following command
make

An executable called "calculator" will be produced. 

Techniques Applied: Objected-Oriented Programming Skills, C++

#Instruction

The calculator has a limited amount of memory which can store and process a number which is between -2,147,483,648 to 2,147,483,647. The calculator can hold:
	1. The current contents of display
	2. The current computed result (with which the displayed value will eventually be combined)
	3. The contents of memory (same as pressing MC/MR/M+)
	4. The most recent pressed operation key (+, -, *, /)
	5. Whether the current computation has an error

**Note: This calculator cannot operate decimal numbers.**

##Commands:

* num1 + num2
  Add up two numbers, num1& numb2

* num1 * num2
  Multiply two numbers together

* num1 - num2
  Subtract num2 from num1

* num1 / num2
  num1 divided by num2

* MR
  Read the number from the memory

* M+
  Add the displayed number to the memory

* MC
  Clear the number in the memory

* =
  Display the calculated value

* AC
  Clear memory, restart.

##Output format:
If the content in the memory is 0, then display:
**Value-of-display**
If the content in the memory is not 0, then display:
**Value-of-display M: Value-of-memory**
If the content in the memory has an error, then display:
**0 M:Value-of-memory E**

##Example: (Itatics denote input)

*456-123+456=*
  789
*1+1=*
  7892
  *AC*
  *1+1=*
  2
  *M+*
  *=*
  2 M: 2
  */0*
  *=*
  0 M: 2 E
  *AC*
  *=*
  0
