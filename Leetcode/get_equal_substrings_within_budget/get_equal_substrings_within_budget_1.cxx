/* 

给你两个长度相同的字符串，s 和 t。

将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。

用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。

如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。

如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。

 

示例 1：

输入：s = "abcd", t = "bcdf", cost = 3
输出：3
解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。
示例 2：

输入：s = "abcd", t = "cdef", cost = 3
输出：1
解释：s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为 1。
示例 3：

输入：s = "abcd", t = "acde", cost = 0
输出：1
解释：你无法作出任何改动，所以最大长度为 1。
 

提示：

1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s 和 t 都只含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/get-equal-substrings-within-budget
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::sort;
using std::string;
using std::vector;
class get_equal_substrings_within_budget
{
private:
    /* data */
public:
    get_equal_substrings_within_budget(/* args */);
    ~get_equal_substrings_within_budget();
    int equalSubstring(string s, string t, int maxCost)
    {
        vector<int> diff;
        for (int i = 0; i < s.size(); ++i)
        {
            diff.push_back(t[i] - s[i] > 0 ? t[i] - s[i] : s[i] - t[i]);
        }
        int sliding_window_size = 1;
        while (sliding_window_size <= s.size())
        {
            auto front = diff.begin();
            auto back = diff.begin() + sliding_window_size - 1;
            int temp_cost = 0;
            for (auto it = front; it <= back; ++it)
            {
                temp_cost += *it;
            }
            if (temp_cost <= maxCost)
            {
                ++sliding_window_size;
                continue;
            }
            else
            {
                while (back != diff.end() - 1)
                {
                    temp_cost -= *front;
                    ++front;
                    ++back;
                    temp_cost += *back;
                    if (temp_cost <= maxCost)
                    {
                        goto ed;
                    }
                }
                return sliding_window_size - 1;
            }
        ed:
            ++sliding_window_size;
        }

        return sliding_window_size;
    }
};

get_equal_substrings_within_budget::get_equal_substrings_within_budget(/* args */)
{
}

get_equal_substrings_within_budget::~get_equal_substrings_within_budget()
{
}

int main()
{
    get_equal_substrings_within_budget geswb;
    string s1 = "krrgw";
    string s2 = "zjxss";
    std::cout << geswb.equalSubstring(s1, s2, 19) << std::endl;
}

// 去补丁版本，只是性能很差，勉强通过，改变的地方其实只是原版本是滑动窗口大小逐渐递减，这个版本是滑动窗口大小逐渐递增.
// Fri,Feb5,2021
