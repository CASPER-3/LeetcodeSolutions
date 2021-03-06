/* 

实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。

 

示例：

输入：单向链表a->b->c->d->e->f中的节点c
结果：不返回任何数据，但该链表变为a->b->d->e->f
通过次数49,513提交次数58,029

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-middle-node-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <cstdlib>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class delete_middle_node_lcci
{
private:
    /* data */
public:
    delete_middle_node_lcci(/* args */);
    ~delete_middle_node_lcci();
    void deleteNode(ListNode *node)
    {
        ListNode *it=node;
        while (it->next->next)
        {
            it->val=it->next->val;
            it=it->next;
        }
        it->val=it->next->val;
        it->next=nullptr;
    }
};

delete_middle_node_lcci::delete_middle_node_lcci(/* args */)
{
}

delete_middle_node_lcci::~delete_middle_node_lcci()
{
}

// Wed,Feb24,2021
// 10:14:25:391:637497584653913157