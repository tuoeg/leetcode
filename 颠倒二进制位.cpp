#include <iostream>
#include <math>
using namespace std;

// idea对n的每一位进行遍历，同时统计倒转总和
uint32_t reverseBits(uint32_t n)
{
    int count = 0;
    uint32_t sum = 0;
    while (n)
    {
        if (n & 1)
            sum = sum + pow(2, 31 - count);
        n = n >> 1;
        count++;
    }
    return sum;
}

//官方思路
// 有另外一种不使用循环的做法，类似于归并排序。
// 其思想是分而治之，把数字分为两半，然后交换这两半的顺序；
// 然后把前后两个半段都再分成两半，交换内部顺序……直至最后交换顺序的时候，交换的数字只有 1 位