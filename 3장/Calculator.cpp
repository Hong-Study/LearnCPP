#include<iostream>
#include"Calculator.h"
#include"Adder.h"

void Calculator::run(){
    std::cout<<"두개의 수를 입력하세요 >> ";
    int a,b;
    std::cin >>a >> b;

    Adder adder(a,b);
    std::cout << adder.process() << std::endl;
}