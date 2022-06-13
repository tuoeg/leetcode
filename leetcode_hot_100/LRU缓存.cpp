
#include <map>
using namespace std;

//本人思想，使用hashmap进行存储，可以在O(n)时间复杂度下访问key
//使用pair存储key以及一个访问计数
//该方法无法保证每次O(n)的底层调用
// class LRUCache
// {
//     map<int, pair<int, int>> member;
//     int capacity;
//     int count = 0; //判断存储容量
// public:
//     LRUCache(int capacity)
//     {
//         this->capacity = capacity;
//     }

//     int get(int key)
//     {
//         //判断存在
//         if (member.count(key))
//         {
//             // cout<<" "<<key;
//             upgrade_access_count(key);
//             member[key].second = 0;
//             return member[key].first;
//         }
//         return -1;
//     }

//     void put(int key, int value)
//     {
//         if (member.count(key) == 0)
//         {
//             this->count++;
//             upgrade_access_count(key);
//         }
//         //判断存储容量
//         if (this->count > this->capacity && member.count(key) == 0)
//         {
//             // cout<<key;
//             //删除一个数
//             delete_value();
//             this->count--;
//         }
//         //更新访问计数
//         //更新
//         member[key] = {value, 0};
//         // cout<<member[1].second;
//     }
//     void upgrade_access_count(int key)
//     {
//         //遍历map
//         for (auto &i : member)
//         {
//             if (i.first == key)
//                 continue;
//             i.second.second++;
//             // cout<<i.first;//<<i.second.second<<endl;
//         }
//         // cout<<endl;
//         // cout<<member[1].second;
//     }
//     void delete_value()
//     {
//         //找出最久未访问的值
//         int max_access = 0;
//         int index_key = 0;
//         for (auto &i : member)
//         {
//             // cout<<i.first<<i.second.second;
//             if (i.second.second > max_access)
//             {
//                 max_access = i.second.second;
//                 index_key = i.first;
//             }
//         }
//         //删除
//         member.erase(index_key);
//     }
// };

// hashmap存储双向链表的值
struct List_Node
{
    int key;
    int value;
    List_Node *pre;
    List_Node *next;
    List_Node(int key, int value) : key(key), value(value), pre(nullptr), next(nullptr) {}
    List_Node() : key(0), value(0), pre(nullptr), next(nullptr) {}
};
class LRUCache
{
private:
    map<int, List_Node *> member;
    List_Node *head; //类中只写生命定义，不要写赋值
    List_Node *tail;
    //初始化头尾结点连接
    int capacity;
    int count = 0;

public:
    LRUCache(int capacity)
    {
        head = new List_Node();
        tail = new List_Node();
        this->capacity = capacity;
        head->next = this->tail;
        tail->pre = this->head;
    }

    int get(int key)
    {
        if (member.count(key))
        {
            move_node(member[key]);
            return member[key]->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (member.count(key) == 0)
            count++;
        if (count > this->capacity)
        {
            // cout<<key;
            delete_node();
            count--;
        }
        //判断是否存在于map中
        if (member.count(key) == 0)
        {
            //新建结点
            List_Node *node = new List_Node(key, value);
            member[key] = node;
            //插入结点
            insert_node(node);
        }
        else
        {
            member[key]->value = value;
            move_node(member[key]);
        }
    }
    void insert_node(List_Node *node)
    {
        // cout<<head->next->key;
        node->next = this->head->next;
        node->pre = head;
        this->head->next = node;
        node->next->pre = node;
        // cout<<tail->pre->key;
    }
    void delete_node()
    {
        // cout<<tail->pre->key;
        if (tail->pre != head)
        {
            cout << this->tail->pre->key;
            member.erase(tail->pre->key);
            this->tail->pre->pre->next = this->tail;
            this->tail->pre = this->tail->pre->pre;
        }
    }
    void move_node(List_Node *node)
    {
        //移除中间node结点
        node->pre->next = node->next;
        node->next->pre = node->pre;
        //添加结点到头部
        insert_node(node);
    }
};
