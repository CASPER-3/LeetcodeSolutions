/* 

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

 

示例 1：


输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]
 

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
通过次数324,175提交次数790,195

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class remove_nth_node_from_end_of_list
{
private:
    /* data */
public:
    remove_nth_node_from_end_of_list(/* args */);
    ~remove_nth_node_from_end_of_list();
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next)
        {
            return nullptr;
        }
        ListNode prehead(0, head);
        ListNode *front = head;
        ListNode *back = head;
        ListNode *preback = &prehead;
        for (int i = 0; i < n - 1; ++i)
        {
            front = front->next;
            
        }
        while (front->next)
        {
            front = front->next;
            preback = preback->next;
            back = back->next;
        }

        preback->next = back->next;
        back = nullptr;

        return (&prehead)->next;
    }
};

remove_nth_node_from_end_of_list::remove_nth_node_from_end_of_list(/* args */)
{
}

remove_nth_node_from_end_of_list::~remove_nth_node_from_end_of_list()
{
}

/**
 * 快慢指针.思路类似于 @file kth_node_from_end_of_list_lcci.cxx
 * 加入了哑节点(Dummy node),避免了对头节点特殊情况的处理.
 */
// Mon,Feb22,2021
// 14:07:49:810:637495996698109759
