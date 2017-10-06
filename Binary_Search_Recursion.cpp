//
//  main.cpp
//  Binary_Search
//  时间复杂度为logn
//  1.题目描述：针对数据，进行二分查找，要求：查找的数据排列必须有序
//  2.方法：
//      （1）概念法
//      （2）递归法
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>

using namespace std;

int Binary_Search1(int arr[], int n, int key){
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key < arr[mid]) {
            high = mid - 1;
        } else if(key > arr[mid]){
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int Binary_Search2(int arr[], int low, int high, int key){
    if (low > high) {
        return -1;
    }
    
    int mid = (low + high) / 2;
    
    if (key == arr[mid]) {
        return mid;
    } else if(key > arr[mid]) {
        low = mid + 1;
        return Binary_Search2(arr, low, high, key);
    } else {
        high = mid - 1;
        return Binary_Search2(arr, low, high, key);
    }
}


int main(int argc, const char * argv[]) {
    
    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 100};
    int n = sizeof(arr) / sizeof(int);
    int key;
    
    cout << "Please input the number: ";
    cin >> key;
    
    int pos1 = Binary_Search1(arr, n, key);
    
    if (pos1 == -1) {
        cout << "No such number!" << endl;
    } else {
        cout << "1.pos: " << pos1 << endl;
    }
    
    int pos2 = Binary_Search2(arr, 0, n, key);
    
    if (pos2 == -1) {
        cout << "No such number!" << endl;
    } else {
        cout << "2.pos: " << pos2 << endl;
    }

    
    return 0;
}
