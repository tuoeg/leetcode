#include <stack>

//考虑到最小值需要O(n)获取，可以同时维护一个最小栈，将数值栈对应的最小值吃存入栈中
//访问元素之前注意判空，push和pop都应该进行对min进行更新
class MinStack
{
public:
    stack<int> data1;     //存储数值
    stack<int> min_stack; //存储最小值
    int min;
    MinStack()
    {
    }

    void push(int val)
    {
        data1.push(val);
        if (min_stack.empty())
        {
            min_stack.push(val);
            min = val;
        }
        else
        {
            if (min > val)
            {
                min_stack.push(val);
                min = val; //需要更新min
            }
            else
            {
                min_stack.push(min);
            }
        }
    }

    void pop()
    {
        if (!data1.empty())
        {
            data1.pop();
            min_stack.pop();
        }
        if (!min_stack.empty())    //访问top前需要进行判空操作
            min = min_stack.top(); //在弹出元素之后需要对min进行更新
    }

    int top()
    {
        if (!data1.empty())
            return data1.top();
        return -1;
    }

    int getMin()
    {
        if (!min_stack.empty())
            return min_stack.top();
        return -1;
    }
};