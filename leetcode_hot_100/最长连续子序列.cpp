#include <iostream>

using namespace std;

//设计查询，可以使用hashmap进行存储，本地数值存进map之后，遍历也是有序的
int longestConsecutive(vector<int> &nums)
{
    std::unordered_set<int> num_set;
    for (auto num : nums)
    {
        num_set.insert(num);
    }
    int longest_length = 0;
    //此时的num_set是无序的，查询num的前一位数值，可以判断num还需要不要重新判断
    for (auto num : num_set)
    {
        if (!num_set.count(num - 1))
        {
            int length = 1;
            while (num_set.count(num + 1))
            {
                length++;
                num++;
            }
            longest_length = length > longest_length ? length : longest_length;
        }
    }
    return longest_length;
}