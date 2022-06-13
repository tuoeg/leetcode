class Solution
{
public:
    //直接使用暴力法
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        for (int i = 0; i < temperatures.size(); i++)
        {
            int num = 0;
            for (int j = i; j < temperatures.size(); j++)
            {
                if (temperatures[j] > temperatures[i])
                    num = j - i;
            }
            temperatures[i] = num;
        }
        return temperatures;
    }
};