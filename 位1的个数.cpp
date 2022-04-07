#include <iostream>

using namespace std;

// idea直接对输入的数值进行移位，并且统计移位的次数
int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        n & 1 == 1 ? count++ : count;
        n = n >> 1;
    }
    return count;
}

//官方解决方案,位运算，n&(n-1)每一次都能消除一个最低位的1

int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}