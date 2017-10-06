//
//  main.cpp
//  Fibonacci
//  1.题目描述：输入n值，求解第n项的斐波那契数列值
//  2.方法：
//      （1）概念法
//      （2）递归法
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>

using namespace std;

unsigned int Fibonacci1(unsigned int n){
    unsigned int fib1 = 1;
    unsigned int fib2 = 1;
    unsigned fib = 1;
    for (int i = 3; i <= n; i++) {
        fib = fib1+ fib2;
        fib1 = fib2;
        fib2 = fib;
    }
    return fib;
}

unsigned int Fibonacci2(unsigned int n){
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return Fibonacci2(n-1) + Fibonacci2(n-2);
    }
}

int main(int argc, const char * argv[]) {
    
    unsigned int n;
    
    cout << "Please input n: ";
    cin >> n;
    
    cout << "1.The N of Fibonacci is " << Fibonacci1(n) << endl;
    cout << "2.The N of Fibonacci is " << Fibonacci2(n) << endl;

    return 0;
}
