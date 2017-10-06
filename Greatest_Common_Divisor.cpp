//
//  main.cpp
//  Greatest_Common_Divisor
//	最大公约数
//	1.题目描述：求解两个整数（不能是负数）的最大公约数（要求两数不能同时为0）
//	2.方法：
//		（1）穷举法
//		（2）相减法
//		（3）欧几里得辗转相除法
//		（4）欧几里得辗转相除法：递归实现
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

//穷举法
unsigned long GCD1(unsigned long a, unsigned long b){
    if (a == 0) {
        return b;
    } else if(b == 0){
        return a;
    } else if(a == b){
        return a;
    }
    unsigned long gcd = a > b ? b : a;
    while (gcd > 1) {
        if ((a%gcd==0) && (b%gcd==0)) {
            return gcd;
        }
        gcd--;
    }
    return gcd;
}

//相减法
unsigned long GCD2(unsigned long a, unsigned long b){
    if (a == 0) {
        return b;
    } else if(b == 0){
        return a;
    } else if(a == b){
        return a;
    }
    
    unsigned long gcd = 0;
    
    while (a != b) {
        //用较大的一个减去较小的一个，直到两者相等，就得到了最大公约数
        gcd = a > b ? (a-=b) : (b-=a);
    }
    
    return gcd;
}

//欧几里得辗转相除法
unsigned long GCD3(unsigned long a, unsigned long b){
    if (a == 0) {
        return b;
    } else if(b == 0){
        return a;
    } else if(a == b){
        return a;
    }
    
    unsigned long mod = a % b;
    while (mod != 0) {
        a = b;
        b = mod;
        mod = a % b;
    }
    
    return b;
}

//欧几里得辗转相除法：递归实现
unsigned long GCD4(unsigned long a, unsigned long b){
    if (b == 0) {
        return a;
    } else {
        return GCD4(b, a % b);
    }
}


#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    unsigned long a, b;
    
    cout << "Please input a and b: ";
    cin >> a >> b;
    
    unsigned long gcd;
    
    gcd = GCD1(a, b);
    cout << "1.gcd = " << gcd << endl;

    gcd = GCD2(a, b);
    cout << "2.gcd = " << gcd << endl;

    gcd = GCD3(a, b);
    cout << "3.gcd = " << gcd << endl;

    gcd = GCD4(a, b);
    cout << "4.gcd = " << gcd << endl;
	
    return 0;
}
