//
//  main.cpp
//  Bit_Set
//  位设置
//  1.题目描述：对一个unsigned char 8 bit数据的指定位 置0或置1 操作，并保持其它位不变
//    函数原型： void bit_set(unsigned char * p_data, unsigned char position, bool flag);
//    参数说明： p_data是指定的原始数据，position是指定位（取值范围1~8），flag表示是置0还是置1操作
//  2.方法：
//      （1）分支设置法
//      （2）位操作设置法
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>
using namespace std;

//分支设置法
void bit_set1(unsigned char * p_data, unsigned char position, bool flag){
    if (flag) {
        switch (position) {
            case 1:
                *p_data |= 0x01;
                break;
            case 2:
                *p_data |= 0x02;
                break;
            case 3:
                *p_data |= 0x04;
                break;
            case 4:
                *p_data |= 0x08;
                break;
            case 5:
                *p_data |= 0x10;
                break;
            case 6:
                *p_data |= 0x20;
                break;
            case 7:
                *p_data |= 0x40;
                break;
            case 8:
                *p_data |= 0x80;
                break;
            default:
                break;
        }
    } else {
        switch (position) {
            case 1:
                *p_data &= ~0x01;
                break;
            case 2:
                *p_data &= ~0x02;
                break;
            case 3:
                *p_data &= ~0x04;
                break;
            case 4:
                *p_data &= ~0x08;
                break;
            case 5:
                *p_data &= ~0x10;
                break;
            case 6:
                *p_data &= ~0x20;
                break;
            case 7:
                *p_data &= ~0x40;
                break;
            case 8:
                *p_data &= ~0x80;
                break;
            default:
                break;
        }
    }
}

//位操作设置法
void bit_set2(unsigned char * p_data, unsigned char position, bool flag){
    if (flag) {
        *p_data |= (0x1 << (position-1));
    } else {
        *p_data &= ~(0x1 << (position-1));
    }
}

int main(int argc, const char * argv[]) {
    
    unsigned char data = 100; //0~255之间
    bool flag = false;
    unsigned char position = 3;
    
    bit_set1(&data, position, flag);
    cout << "1.data = " << (int)data << endl;
    
    data = 100;
    bit_set2(&data, position, flag);
    cout << "2.data = " << (int)data << endl;
    
    return 0;
}
