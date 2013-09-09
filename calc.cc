//
//  calc.cc
//  CS246 A3Q1
//
//  Created by Sun Renchen on 2013-06-14.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//  This is the implementation of a simple simulated hand-held calculator.

// Sample output:
//A sample session follows:
/*
 A sample session follows:
 456-123+456=
 789
 1+1=
 7892
 AC
 1+1=
 2
 M+
 =
 2 M: 2
 /0
 =
 0 M: 2 E
 AC
 =
 0
*/

#include "calc.h"

//Constructor, used to set all fields to default.
Calc::Calc()
{
    allClear();
}

//Copy constructor
Calc::Calc(const Calc& other)
{
    error = other.error;
    display = other.display;
    oper = other.oper;
    result = other.result;
    memory = other.memory;
}

//adds digit (which must be between 0 and 9, inclusive) to the end of the display value.
void Calc::digit(int digit)
{
    if (error == true) //If the status is error, then do nothing.
        return;
    display = 10 * display + digit;
}

//sets the operator field. If the operator field previously contained an operator, it combines display and result with that operator, and stores the result. If not, display is copied to result. In either case, display is cleared (reset to 0).
void Calc::op(char opera)
{
    if (error == true)//If the status is error, then do nothing.
        return;
    if (oper != 'N') // 'N' stands for not set.
    {
        if (oper == '+')
            result = display + result;
        if (oper == '-')
            result = result - display;
        if (oper == '*')
            result = display * result;
        if (oper == '/') // Check special case when the operator is division.
        {
            if (display != 0) // if the division is not 0.
                result = result / display;
            else // if the division is 0
            {
                error = true; //set the error field to true, then reset all fields to default.
                oper = 'N';
                result = 0;
                return ;
            }
        }
        oper = opera;
    }
    else // If there was an operator entered before, then calculate the result based on the former operator, then assign new operator to the operator.
    {
        result = display;
        oper = opera;
    }
    display = 0;
}

void Calc::equals() // combines result and display using operator, and stores the result in result and display. Clears the operator field.
{
    if (oper == 'N' || error == true) // If the user entered nothing before, or the status is error, then do nothing.
        return;
    if (oper == '+')
        result = display + result;
    if (oper == '-')
        result = result - display;
    if (oper == '*')
        result = display * result;
    if (oper == '/') // Check special case when division by zero.
    {
        if (display == 0)
        {
            error = true;
            oper = 'N';
            result = 0;
            return ;
        }
        else
            result = result / display;
    }
    display = result;
    oper = 'N';
}

void Calc::memPlus() // adds the displayed value to the contents of memory, and stores the result in memory
{
    if (error == true)
        return;
    memory = display;
}

void Calc::memClear() // clears the contents of the memory (sets it to 0)
{
    if (error == true)
        return;
    memory = 0;
}

void Calc::memRecall() //copies the contents of memory to the display.
{
    if (error == true)
        return;
    display = memory;
}

bool Calc::isError() const // Return the status of the calculator.
{
    return error? true : false;
}

void Calc::allClear() //Reset all the fields to default.
{
    error = false;
    display = 0;
    oper = 'N';
    result = 0;
    memory = 0;
}

std::ostream& operator<<(std::ostream& out, const Calc& c) // Output the operator.
{
    out.flush();
    if (c.memory == 0 && c.isError())
        return out << c.display << " E";
    else if (c.memory == 0 && !c.isError())
        return out << c.display;
    else if (c.memory != 0 && c.isError())
        return out << c.display << " M: " << c.memory << " E";
    else
        return out << c.display << " M: " << c.memory;
}
