/* 

编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：



在节点 c1 开始相交。

 

示例 1：

        4 ---> 1 ---> 8 ---> 4 ---> 5
                  /
5 ---> 0 ---> 1 -/

a + x = 5
b + x = 6
b - a = 1

输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

示例 2：



输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

示例 3：



输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
 

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cstdlib>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class intersection_of_two_linked_lists
{
private:
    /* data */
public:
    intersection_of_two_linked_lists(/* args */);
    ~intersection_of_two_linked_lists();
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *it1 = headA;
        ListNode *it2 = headB;
        if (!it1 || !it2)
        {
            return NULL;
        }
        int count1 = 0;
        int count2 = 0;
        int diff = 0;
        while (it1->next)
        {
            it1 = it1->next;
            ++count1;
        }
        while (it2->next)
        {
            it2 = it2->next;
            ++count2;
        }

        if (it1 != it2)
        {
            return NULL;
        }
        else
        {
            diff = count1 > count2 ? count1 - count2 : -(count1 - count2);
        }
        ListNode *lt1 = headA;
        ListNode *lt2 = headB;
        if (count1 > count2)
        {
            for (int i = 0; i < diff; ++i)
            {
                lt1 = lt1->next;
            }
        }
        else
        {
            for (int i = 0; i < diff; ++i)
            {
                lt2 = lt2->next;
            }
        }

        while (lt1 != lt2)
        {
            lt1 = lt1->next;
            lt2 = lt2->next;
        }
        return lt1;
    }
};

intersection_of_two_linked_lists::intersection_of_two_linked_lists(/* args */)
{
}

intersection_of_two_linked_lists::~intersection_of_two_linked_lists()
{
}

// Tue,Feb2,2021
