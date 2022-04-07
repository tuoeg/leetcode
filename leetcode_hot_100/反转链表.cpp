#include <iostream>

using namespace std;

//回溯法，原地反转，head将是指向链表第一元素的指针，将能够直接访问第一个值
ListNode *reverseList(ListNode *head)
{
    //判断head的下一位为nullptr则结束
    ListNode *right = nullptr; //存储右边的链表
    ListNode *left = nullptr;  //存储左边的链表
    while (head != nullptr)
    {
        right = head->next;
        head->next = left;
        left = head;
        head = right;
    }
    return head;
}

//递归实现链表反转    这种写法将造成边界条件需要另外处理
ListNode *ret = nullptr;
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    reverse(head)->next = nullptr;
    return ret;
}
ListNode *reverse(ListNode *head)
{
    if (head->next == nullptr)
    {
        ret = head;
        return head;
    }
    reverse(head->next)->next = head;
    return head;
}

//递归不用考虑null边界处理

ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;
    ListNode *newList = reverseList(head->next); //这个newList其实一直没动，一直指向的最后结点
    head->next->next = head;
    head->next = nullptr; //当前结点置空，可以致使头结点为空
    return newList;
}