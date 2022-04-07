#include <iostream>
#include <vector>
using namespace std;

// idea采用回溯模板，每一个插入到temp数组中，将判断是否在temp中存在该数据，存在便不再处理
//但是该方法浪费空间，经历很多重复遍历

//官方办法，将nums数组分成两边，一边是已经排列过得数组，一边是待排数组，每次将待排数与已排数进行置换，便不用再判断visit
// void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
//     // 所有数都填完了
//     if (first == len) {
//         res.emplace_back(output);
//         return;
//     }
//     for (int i = first; i < len; ++i) {
//         // 动态维护数组
//         swap(output[i], output[first]);
//         // 继续递归填下一个数
//         backtrack(res, output, first + 1, len);
//         // 撤销操作
//         swap(output[i], output[first]);
//     }
// }
// vector<vector<int>> permute(vector<int>& nums) {
//     vector<vector<int> > res;
//     backtrack(res, nums, 0, (int)nums.size());
//     return res;
// }

bool isContain(vector<int> &temp, int num);
void backtrack(vector<int> &nums, vector<int> &temp, vector<vector<int>> &result);
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> temp;
    backtrack(nums, temp, result);
    return result;
}
void backtrack(vector<int> &nums, vector<int> &temp, vector<vector<int>> &result)
{
    if (temp.size() == nums.size())
    {
        result.push_back(temp);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        //处理当前结点，判断该结点是否在temp数组中
        if (!isContain(temp, nums[i]))
        {
            temp.push_back(nums[i]);
            backtrack(nums, temp, result);
            temp.pop_back();
        }
    }
}
bool isContain(vector<int> &temp, int num)
{
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == num)
            return true;
    }
    return false;
}

int main()
{
    vector<int> test = {1, 2};
    auto s = permute(test);
    printf("%d", s.size());
}