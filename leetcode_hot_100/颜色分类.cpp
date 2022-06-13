#include <vector>
using namespace std;

//该题想使用双指针进行处理，以为使用双指针应该对时间复杂度产生影响
//但是实际上时间复杂度只是O(n)
void sortColors(vector<int> &nums)
{
    int begin = 0;
    int end = nums.size() - 1;
    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] == 0)
        {
            swap(nums[begin], nums[i]);
            begin++;
        }
        if (nums[i] == 2)
        {
            if (i < end)
            {
                cout << nums[i];
                swap(nums[i], nums[end]);
                end--;
                i--;
            }
            else
                break;
        }
        i++;
    }
}