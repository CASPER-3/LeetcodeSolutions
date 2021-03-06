/* 

203. 移除链表元素

difficulty: easy
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
通过次数135,727提交次数288,068

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-linked-list-elements
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

class remove_linked_list_element
{

public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if(!head)
        {
            return head;
        }
        if(!head->next)
        {
            return head->val==val?nullptr:head;
        }
        auto slow=head;
        auto fast=head->next;
        if(head->val)
        {
            return fast;
        }
        if(fast->val==val)
        {
            head->next=nullptr;
            return head;
        }
        while(fast->next)
        {
          
            if(fast->val==val)
            {
                slow->next=fast->next;
            }


        }

    }
};