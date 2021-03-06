/* 

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1：


输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1]
 

提示：

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
 

进阶：你能在不修改链表节点值的情况下解决这个问题吗?（也就是说，仅修改节点本身。）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

/* 
 Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class swap_nodes_in_pairs
{
private:
    /* data */
public:
    swap_nodes_in_pairs(/* args */);
    ~swap_nodes_in_pairs();
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        auto front = head->next;
        auto back = head;
        auto temp = front->next;
        front->next = back;
        back->next = temp;
        head = front;
        while (temp && temp->next)
        {
            front = temp->next;
            back = temp;
            temp = front->next;
            front->next = back;
            back->next = temp;
        }
        return head;
    }
};

swap_nodes_in_pairs::swap_nodes_in_pairs(/* args */)
{
}

swap_nodes_in_pairs::~swap_nodes_in_pairs()
{
}

/* 
         b f t
        [1,2,3,4]

 */

//
