//
//  main.cpp
//  my_strlen
//  1.题目描述：实现求字符串长度的函数my_strlen
//  2.方法：
//      （1）直接法
//      （2）递归法：当不允许使用任何中间变量的时候用递归法
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>
#include <assert.h>

using namespace std;

size_t my_strlen1(const char * str){
    assert(str != NULL);
    size_t count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

size_t my_strlen2(const char * str){
    assert(str != NULL);
    size_t i = 0;
    for (i = 0; *str++ != '\0'; ++i);
    return i;
}

size_t my_strlen3(const char * str){
    assert(str != NULL);
    if (*str == '\0') {
        return 0;
    } else {
        return my_strlen3(str+1) + 1;
    }
}

int main(int argc, const char * argv[]) {
    
    const char *str = "hello";
    cout << "strlen(): " << strlen(str) << endl;
    
    cout << "1.my_strlen(): " << my_strlen1(str) << endl;
    cout << "2.my_strlen(): " << my_strlen2(str) << endl;
    cout << "3.my_strlen(): " << my_strlen3(str) << endl;
    
    return 0;
}
