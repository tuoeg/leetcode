class Solution
{
public:
    int findClosest(vector<string> &words, string word1, string word2)
    {
        int len = 0;
        int temp = 0;
        bool flag = true;
        for (int i = 0; i < words.length(); i++)
        {
            if ((words[i] == word1 || words[i] == word2) && flag)
            {
                flag = false;
                temp = i;
                break;
            }
            if (words[i] == word1 || words[i] == word2)
            {
                if (words[i] != words[temp])
                    len = len < (i - temp) ? len : (i - temp);
                else
                    temp = i;
            }
        }
        return len;
    }
};