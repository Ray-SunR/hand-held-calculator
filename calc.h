//
//  Header.h
//  A3Q1
//
//  Created by Sun Renchen on 2013-06-14.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef A3Q1_Header_h
#define A3Q1_Header_h
#include <iostream>
struct Calc {
    Calc();
    Calc(const Calc &other);
    
    bool error;
    int display;
    char oper;
    int result;
    int memory;
    
    void digit(int digit);
    void op(char oper);
    void equals();
    
    void memPlus();
    void memClear();
    void memRecall();
    
    bool isError() const;
    
    void allClear();
};

std::ostream &operator<<(std::ostream &out, const Calc &c);


#endif
