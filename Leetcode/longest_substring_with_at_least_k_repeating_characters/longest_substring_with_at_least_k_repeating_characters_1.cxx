/* 

找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。

示例 1:

输入:
s = "aaabb", k = 3

输出:
3

最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2:

输入:
s = "ababbc", k = 2

输出:
5

最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
通过次数20,114提交次数43,187

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <string>
#include <iostream>
#include <vector>
using std::cout;
using std::string;
using std::vector;
class longest_substring_with_at_least_k_repeating_characters
{

public:
    int longestSubstring(string s, int k)
    {
        if (k <= 1)
        {
            return s.size();
        }
        if (s.empty() || s.size() < k)
        {
            return 0;
        }
        vector<int> dic(26, 0);
        for (auto c : s)
        {
            ++dic[c - 97];
        }

        auto split = [=](string s) -> int {
            for (int i = 0; i < s.size(); ++i)
            {
                if (dic[s[i] - 97] < k)
                {
                    return i;
                }
            }
            return s.size();
        };

        int pos = split(s);
        if (pos == s.size())
        {
            return s.size();
        }
        int ll = longestSubstring(s.substr(0, pos), k);
        while (pos < s.size() && dic[s[pos] - 97] < k)
        {
            ++pos;
        }
        int lr = longestSubstring(s.substr(pos), k);

        return ll > lr ? ll : lr;
    }
};

int main()
{
    string s = "ababbc";
    longest_substring_with_at_least_k_repeating_characters lswalkrc;

    cout << lswalkrc.longestSubstring(s, 2) << "\n";
}

// 拙劣的模仿.
// Sat,Feb27,2021
// 13:16:30:511:637500285905119963