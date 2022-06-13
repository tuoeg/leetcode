#include <iostream>
#include <queue>
using namespace std;

//广度优先遍历，需要记录每一层的节点的个数
Node *connect(Node *root)
{
    queue<Node> q;
    q.push(root);
    int num = 1;
    while (!q.empty())
    {
        for (int i = 0; i < num; i++)
        {
            Node singleNode = q.front();
            q.pop();
            if (i != num - 1)
            {
                singleNode->next = q.front();
            }
            else
            {
                singleNode->next = NULL;
            }
            q.push(singleNode->left);
            q.push(singleNode->right);
        }
        num = q.size();
    }
}

//第二种思路，可以充分利用next指针，当上层的next指针
//全部指向到位之后，下一层可以利用上一层的next指针跨空访问
//同一层的结点全部使用链表访问
//node.right.next = node.next.left