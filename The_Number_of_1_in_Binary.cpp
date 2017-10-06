//
//  main.cpp
//  The_Number_of_1_in_Binary
//  二进制中1的个数
//  1.题目描述：对一个字节的无符号整形变量，求二进制中1的个数，要求执行效率尽可能高
//  2.方法：
//      （1）使用模方法
//      （2）使用位操作运算
//      （3）时间复杂度是与1的个数有关的算法
//      （4）分支法
//      （5）查表法
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>
using namespace std;

//使用模方法
int Count1(unsigned char ch){
    int count = 0;
    while (ch != 0) {
        if (ch % 2 == 1) {
            count++;
        }
        ch /= 2;
    }
    return count;
}

//使用位操作运算
int Count2(unsigned char ch){
    int count = 0;
    while (ch != 0) {
        count += ch & 0x01;
        ch = ch >> 1;
    }
    return count;
}

//时间复杂度是与1的个数有关的算法，用（数据本身）&（数据本身-1）
int Count3(unsigned char ch){
    int count = 0;
    while (ch != 0) {
        ch &= (ch-1);
        count++;
    }
    return count;
}

//分支法：因为只有1个字节，8个位，所以可以把所有情况都求出来，实际上并不可取
int Count4(unsigned char ch){
    int count = 0;
    switch (ch) {
        case 0x0:
            count = 0;
            break;
        case 0x1:
        case 0x2:
        case 0x4:
        case 0x8:
        case 0x10:
        case 0x20:
        case 0x40:
        case 0x80:
            count = 1;
            break;
        case 0x3:
        case 0x6:
        case 0xc:
        case 0x18:
        case 0x30:
        case 0x60:
        case 0xc0:
            count = 2;
            break;
        //还有其他的没补全
        default:
            break;
    }
    return count;
}

//查表法
int countTable[256] = {
    //将所有的情况罗列出来
    0, 1, 1, 2, 1, 2, 2, 3//256种情况都列举出来
};

int Count5(unsigned char ch){
    return countTable[ch];
}


int main(int argc, const char * argv[]) {
    
    unsigned char ch = 100;
    int count = 0;
    
    count = Count1(ch);
    cout << "1.count = " << count << endl;
    
    count = Count2(ch);
    cout << "2.count = " << count << endl;
    
    count = Count3(ch);
    cout << "3.count = " << count << endl;
    
    count = Count4(ch);
    cout << "4.count = " << count << endl;
    
    count = Count5(ch);
    cout << "5.count = " << count << endl;
    
    return 0;
}
