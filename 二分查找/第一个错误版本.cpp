#include<iostream>



using namespace std;
//这种写法想的太复杂了，包括while的跳出条件以及其中的判断第一个错误版本
int firstBadVersion(int n)
{
    int begin=0;
    int end=n;
    int middle;
    while(begin<=end&&begin>=0&&end<=n)
    {
        middle=(end+begin)/2;
        if(!isBadVersion(middle))
        {
            begin=middle+1;
        }
        if(isBadVersion(middle))
        {
            end=middle-1;
        }
        if(isBadVersion(middle)&&middle-1>=1&&!isBadVersion(middle-1))
        {
            return middle;
        }
    }
    return -1;
}





// 简化版本，优化while跳出条件
// 此处需要注意的是begin和end的赋值条件，在判断到middle是坏版本时需要将middle赋值给end,否则将begin赋值成middle+1
int firstBadVersion(int n)
{
    int begin=1;
    int end=n;
    int middle;
    while(begin>=end)
    {
        middle=begin+(end-begin)/2;
        if(isBadVersion(middle))
        {
            end=middle;
        }
        else
        {
            begin=middle+1;
        }
    }
    return middle;
}