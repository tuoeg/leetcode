#include <iostream>
using namespace std;

// idea：使用数组承接所有的值，并从头到尾进行比较
//使用栈进行抵消还是不能达到目的，因为两两相等的数值可以直接抵消

// O(n)时间复杂度  O(n)空间复杂度使用递归遍历，递归时指针会到达链表的
//最后，可以让另一个指针从头结点开始遍历,该方法直接遍历了两次链表
ListNode *begin = nullptr;

bool recursion(ListNode *head)
{
    if (!head)
    {
        return true;
    }
    else
    {
        if (!recursion(head->next))
            return false;
        if (begin->val != head->val)
            return false;
        begin = begin->next;
    }
    return true;
}

bool isPalindrome(ListNode *head)
{
    ListNode *begin = head;
    return recursion(head);
}

//避免使用 O(n)O(n) 额外空间的方法就是改变输入
//官方的O(n)时间复杂度，O(1)空间复杂度
//使用快慢指针，快指针走两步，慢指针走一步，先找出中间点，然后对后半段进行原地反转
//最后反转链表
bool isPalindrome(ListNode *head)
{
    ListNode *middle_node = get_middle_node(head);
    //对后半段进行反转
    ListNode *ret = reverse_list(middle_node->next);
    while (head)
}

//使用常规反转，递归反转肯定会造成存储超标
ListNode *reverse_list(ListNode *head)
{
    ListNode *left = nullptr;
    ListNode *right = nullptr;
    while (head != nullptr)
    {
        right = head->next;
        head->next = left;
        left = head;
        head = right;
    }
    return head;
}

ListNode *get_middle_node(ListNode *head)
{
    ListNode *fast;
    ListNode *slow;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow = next;
    }
    return fast;
}