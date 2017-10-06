//
//  main.cpp
//  Lowest_Common_Multiple
//  最小公倍数
//  1.题目描述：求解两个整数（不能是负数）的最小公倍数
//  2.方法：
//      （1）穷举法
//      （2）公式： lcm = a * b / gcd(a,b)
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//
//穷举法
unsigned long LCM1(unsigned long a, unsigned long b){
    if (a * b == 0) {
        return 0;
    }
    
    unsigned long lcm = a > b ? a : b;
    while (1) {
        if ((lcm%a == 0) && (lcm%b == 0)) {
            break;
        }
        lcm++;
    }
    return lcm;
}

unsigned long GCD(unsigned long a, unsigned long b){
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}
//公式法
unsigned long LCM2(unsigned long a, unsigned long b){
    if (a * b == 0) {
        return 0;
    }
    
    unsigned long lcm = a * b / GCD(a, b);
    
    return lcm;
}

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    unsigned long a, b;
    
    cout << "Please input a and b: " << endl;
    cin >> a >> b;
    
    unsigned long lcm;
    
    lcm = LCM1(a, b);
    cout << "1.lcm = " << lcm << endl;
    
    lcm = LCM2(a, b);
    cout << "2.lcm = " << lcm << endl;
    
    return 0;
}
