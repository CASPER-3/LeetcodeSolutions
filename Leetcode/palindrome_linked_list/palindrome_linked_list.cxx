/* 

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
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

class palindrome_linked_list
{
private:
    /* data */
public:
    palindrome_linked_list(/* args */);
    ~palindrome_linked_list();
    bool isPalindrome(ListNode *head)
    {
        [[not_correct]] if (!head->next)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast->next)
        {
            if (slow->val == fast->val)
            {
                goto ed;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return false;

    ed:
        ListNode *st = head;
        int sum = 0;
        while (fast->next)
        {
            sum += fast->val;
            sum -= st->val;
        }

        return !sum;
    }
};

palindrome_linked_list::palindrome_linked_list(/* args */)
{
}

palindrome_linked_list::~palindrome_linked_list()
{
}

int main()
{
}
