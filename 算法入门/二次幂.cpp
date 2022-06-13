#include <iostream>

using namespace std;

// idea：使用左移运算符进行操作，并且判断相等
//官方解法，可以使用二进制运算
// n&(n-1)的结果为0(如果n为2的x次幂运算)
// n&(-n)=n  计算机中负数的表示是反码的补码

bool isPowerOfTwo(int n)
{
    // int temp = 1;
    // while (temp < n)
    // {
    //     temp = temp << 1;
    //     if (n == temp)
    //         return true;
    // }
    // return false;
    return n > 0 && n & (n - 1) == 0;
}