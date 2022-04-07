#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 给你一个下标从 0 开始的整数数组 nums ，如果满足下述条件，则认为数组 nums 是一个 美丽数组 ：

// nums.length 为偶数
// 对所有满足 i % 2 == 0 的下标 i ，nums[i] != nums[i + 1] 均成立
// 注意，空数组同样认为是美丽数组。

// 你可以从 nums 中删除任意数量的元素。当你删除一个元素时，被删除元素右侧的所有元素将会向左移动一个单位以填补空缺，而左侧的元素将会保持 不变 。

int minDeletion(vector<int> &nums)
{
    stack<int> st;
    st.push(nums[0]);
    int index = 0;
    int delete_num = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        // index是实时变化的
        if (index % 2 == 0 && nums[i] == st.top())
        {
            delete_num++;
            continue;
        }
        st.push(nums[i]);
        index = st.size() - 1;
    }
    //最后的奇偶
    if (st.size() % 2 != 0)
        delete_num++;
    return delete_num;
}