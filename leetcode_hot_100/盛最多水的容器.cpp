#include <vector>
using namespace std;

//考虑到存在两个变量，使用O(n*n)遍历,该方法还是超时了
int maxArea(vector<int> &height)
{
    int max_area = 0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int area = (j - i) * (min(height[i], height[j]));
            max_area = max_area > area ? max_area : area;
        }
    }
    return max_area;
}

//使用双指针
//左右指针比较大小，较小的指针需要进行移动(左指针向左移动，右指针向右移动)，需要补齐短板
//该算法正确性验证，面积中的底部长度在刚开始时是最长的，指针移动之后，底部长度一定是单调递减的
//当左指针高度低于右指针高度时，左指针将被抛弃(如果左指针存在到下一个最优位置)，因为左指针不抛弃的话，右指针向
//左移动，面积将永远小于该状态，至于会不会有一个右指针向右移动能找到一个最优的面积，可以证明不会有，右侧位置因为小于左侧的位置
//而被淘汰，左指针不动，而右指针向右走面积一定比之前更小
int maxArea(vector<int> &height)
{
    int max_area;
    int left = 0;
    int right = height.size() - 1;
    while (left < nums.size())
    {
        int area = min(height[left], height[right]) * (right - left + 1);
        max_area = max_area > area ? max_area : area;
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_area;
}