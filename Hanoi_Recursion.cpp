//
//  main.cpp
//  Hanoi_Recursion
//  1.题目描述：输入n值，实现n个盘子的汉诺塔移动
//  2.方法：
//      递归法
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>

using namespace std;

void Hanoi(int n, char A, char B, char C){
    if (n == 1) {
        cout << A << "-->" << C << endl;
    } else {
        Hanoi(n-1, A, C, B);
        cout << A << "-->" << C << endl;
        Hanoi(n-1, B, A, C);
    }
}

int main(int argc, const char * argv[]) {
    
    int n;
    
    cout << "Please input the number n: ";
    cin >> n;
    
    Hanoi(n, 'A', 'B', 'C');
    
    return 0;
}
