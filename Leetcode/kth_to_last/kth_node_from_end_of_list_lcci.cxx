/* 

实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。

通过次数46,058提交次数59,094

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <cstdlib>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class kth_node_from_end_of_list_lcci
{
private:
    /* data */
public:
    kth_node_from_end_of_list_lcci(/* args */);
    ~kth_node_from_end_of_list_lcci();
    int kthToLast(ListNode *head, int k)
    {
        ListNode *back=head;
        ListNode *front=head;
        for(int i=0;i<k-1;++i)
        {
            front=front->next;
        }
        while(front->next)
        {
            front=front->next;
            back=back->next;
        }
        return back->val;
    }
};

kth_node_from_end_of_list_lcci::kth_node_from_end_of_list_lcci(/* args */)
{
}

kth_node_from_end_of_list_lcci::~kth_node_from_end_of_list_lcci()
{
}

// 很简单的快慢指针问题.
// Mon,Feb22,2021
// 09:31:41:822:637495831018221572
