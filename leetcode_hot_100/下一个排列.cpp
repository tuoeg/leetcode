

//巧妙思想
//下一个排列肯定得紧挨着上一个排列，从前往后有一段公共的部分
//从后往前，如果后面的数字大于前面的那个数，那么前面那个数到结尾的数
//构成的组合已经是最大的情况，可以将前面的那个数进行更换，并且对后面的数进行升序排列

void nextPermutation(vector<int> &nums)
{
    int left = 0, right = 0;
    //从后往前找到那个需要变更的位置
    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            left = i - 1;
            break;
        }
    }
    for (int i = nums.size() - 1; i > left; i--)
    {
        if (nums[i] > nums[left])
        {
            right = i;
            break;
        }
    }
    if (left == 0 & right == 0)
    {
        sort(nums.begin(), nums.end());
        return;
    }
    //交换
    swap(nums[left], nums[right]);
    //排序
    sort(nums.begin() + left + 1, nums.end());
}
}