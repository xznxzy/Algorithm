//
//  main.cpp
//  Factorial_of_N
//  1.题目描述：输入n值，求解n的阶乘
//  2.方法：
//      （1）累乘法
//      （2）递归法
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>
#define UL unsigned long
using namespace std;

//累乘法
UL Factorial1(UL n){
    UL result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

//递归法:要注意别超过了系统的上线，超过了栈的上线就会失败
//递归使用条件：1.能把原问题分解为较小规模的问题  2.有结束条件
UL Factorial2(UL n){
    if (n == 0) {
        return 1;
    } else {
        return Factorial2(n - 1) * n;
    }
}

int main(int argc, const char * argv[]) {
    UL n;
    cout << "Please input n: ";
    cin >> n;
    
    cout << "1.The factorial of N is " << Factorial1(n) << endl;
    cout << "2.The factorial of N is " << Factorial2(n) << endl;
    
    return 0;
}
