#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// idea 常规遍历解法
ListNode *mergeTwoList(ListNode *list1, ListNode *list2)
{
    ListNode *ret = new ListNode();
    ListNode *temp = ret;
    //有串提前结束遍历便退出循环
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if (list1 == nullptr)
        temp->next = list2;
    if (list1 != nullptr)
        temp->next = list1;
    return ret->next;
}

//使用递归解法,直接先到末尾进行处理
ListNode *mergeTwoList(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;
    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoList(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoList(list1, list2->next);
        return list2;
    }
}