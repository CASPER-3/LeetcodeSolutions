/* 

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列
通过次数476,196提交次数728,496

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
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

class merge_two_sorted_list
{
private:
    /* data */
public:
    merge_two_sorted_list(/* args */);
    ~merge_two_sorted_list();
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        [[__unfinished__]]
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        ListNode *st1 = l1;
        ListNode *st2 = l2;
        while(st2)
        {
            
        }

    }
};

merge_two_sorted_list::merge_two_sorted_list(/* args */)
{
}

merge_two_sorted_list::~merge_two_sorted_list()
{
}

// Wed,Feb24,2021