#include <iostream>
using namespace std;

//初试idea 可以使用步长不一样的双指针 步长为1和步长为2；
//此处会出现一种面试题，步长为3能行得通吗，当环形结点数为2的时候，可能就会出现指针永远不会相遇的情况
bool hasCycle(ListNode *head)
{
    if (head == nullptr)
        return false;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr)
    {
        //不用对慢指针的next进行判空，因为只需要处理快指针就行
        if (fast->next == nullptr || fast->next->next == nullptr)
            return false;
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return true;
}