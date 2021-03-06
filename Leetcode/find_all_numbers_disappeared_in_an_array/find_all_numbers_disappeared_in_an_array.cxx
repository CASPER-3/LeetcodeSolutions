/* 

给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <unordered_set>
using std::unordered_set;
using std::vector;

  /**
   *  @brief A class which find the disappeared numbers from the range 1 to n in an array.
   *
   *  @ingroup sequences
   *
   *  @tparam _Tp  Type of element.
   *  @tparam _Alloc  Allocator type, defaults to allocator<_Tp>.
   *
   *  Meets the requirements of a <a href="tables.html#65">container</a>, a
   *  <a href="tables.html#66">reversible container</a>, and a
   *  <a href="tables.html#67">sequence</a>, including the
   *  <a href="tables.html#68">optional sequence requirements</a> with the
   *  %exception of @c push_front and @c pop_front.
   *
   *  In some terminology a %vector can be described as a dynamic
   *  C-style array, it offers fast and efficient access to individual
   *  elements in any order and saves the user from worrying about
   *  memory and size allocation.  Subscripting ( @c [] ) access is
   *  also provided as with C-style arrays.
  */
class find_all_numbers_disappeared_in_an_array
{
private:
    /* data */
public:
    find_all_numbers_disappeared_in_an_array(/* args */);
    ~find_all_numbers_disappeared_in_an_array();
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {

        unordered_set<int> iuns(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=1;i<=nums.size();++i)
        {
            if(!iuns.count(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

find_all_numbers_disappeared_in_an_array::find_all_numbers_disappeared_in_an_array(/* args */)
{
}

find_all_numbers_disappeared_in_an_array::~find_all_numbers_disappeared_in_an_array()
{
}

// Wed,Feb17,2021
