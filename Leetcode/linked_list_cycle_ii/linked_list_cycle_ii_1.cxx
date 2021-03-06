/* 

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：

你是否可以使用 O(1) 空间解决此题？
 

示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
 

提示：

链表中节点的数目范围在范围 [0, 104] 内
-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <cstdlib>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class linked_list_cycle_ii
{
private:
    /* data */
public:
    linked_list_cycle_ii(/* args */);
    ~linked_list_cycle_ii();
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return NULL;
        }
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while (fast->next && fast->next->next && fast != slow)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!fast->next || !fast->next->next)
        {
            return NULL;
        }
        ListNode *bg = head;

        while (bg != slow)
        {
            bg = bg->next;
            slow = slow->next;
        }
        return slow;
    }
};

linked_list_cycle_ii::linked_list_cycle_ii(/* args */)
{
}

linked_list_cycle_ii::~linked_list_cycle_ii()
{
}

int main()
{
    ListNode node0(3);
    ListNode node1(2);
    ListNode node2(0);
    ListNode node3(-4);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node1;
    auto head = &node0;
    linked_list_cycle_ii llcii;
    llcii.detectCycle(head);
}

// 快慢指针，环形链表的神.
// Sun,Feb7,2021
