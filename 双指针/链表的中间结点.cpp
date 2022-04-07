#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    List() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    //设计双指针，指针一次走两步，一个指针一次走一步
    ListNode *fast = head;
    ListNode *slow = head;
    //当fast指针到了末尾，跳出循环
    while (fast->next != nullptr)
    {
        //cout<<1;
        if (fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //当末尾只剩下一个结点时，fast指针和slow指针均走一步
        if (fast->next && !fast->next->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

//简化版本
ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next) //只要保证fast结点后面还有一个结点，那么就能够访问到下一个NULL结点
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}