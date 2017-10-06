//
//  main.cpp
//  Base_Conversion
//  进制转换
//  1.题目描述：对一个unsigned long的整数，将其转换为对应的16进制数
//  2.方法：
//      （1）使用数组存储数据
//      （2）使用栈存储数据
//      （3）使用字符串常量高效转换
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <stack>
#include <iostream>

using namespace std;

//使用数组存储数据
char* Convert1_16(unsigned long value){
    char * Buffer;
    Buffer = new char[sizeof(unsigned long) * 2 + 1];
    Buffer[8] = '\0';
    int mod;
    for (int i = sizeof(unsigned long)*2-1; i >= 0; i--) {
        mod = value % 16;
        if (mod < 10) {
            Buffer[i] = mod + '0';
        } else {
            Buffer[i] = (mod - 10) + 'A';
        }
        value = value / 16;
    }
    return Buffer;
}

//使用栈存储数据
void Convert2_16(unsigned long value){
    stack<char> st;
    int mod;
    while (value != 0) {
        mod = value % 16;
        if (mod < 10) {
            st.push(mod + '0');
        } else {
            st.push(mod-10 + 'A');
        }
        value = value / 16;
    }
    cout << "2.value = " << value << " = " << "0x";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}


//使用字符串常量高效转换
char* Convert3_16(unsigned long value){
    char * Buffer;
    Buffer = new char[sizeof(unsigned long) * 2 + 1];
    Buffer[8] = '\0';
    for (int i = sizeof(unsigned long)*2-1; i >= 0; i--) {
        Buffer[i] = "0123456789ABCDEF"[value % 16];
        value /= 16;
    }
    return Buffer;
}


int main(int argc, const char * argv[]) {
    
    unsigned long value = 4791;
    char* result;
    
    result = Convert1_16(value);
    cout << "1.value = 0x" << result << endl;   //0x12B7
    
    Convert2_16(value);

    result = Convert3_16(value);
    cout << "3.value = 0x" << result << endl;
    
    return 0;
}
