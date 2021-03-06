/* 

给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：

输入: s1 = "abc", s2 = "bca"
输出: true 
示例 2：

输入: s1 = "abc", s2 = "bad"
输出: false
说明：

0 <= len(s1) <= 100
0 <= len(s2) <= 100
通过次数37,624提交次数57,489
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-permutation-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::unordered_map;
using std::vector;
class check_permutation_lcci
{

public:
    bool CheckPermutation(string s1, string s2)
    {
        int sz1 = s1.size();
        int sz2 = s2.size();
        if (sz1 != sz2)
        {
            return false;
        }
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for (int i = 0; i < s1.size(); ++i)
        {
            ++v1[s1[i]-97];
            ++v2[s2[i]-97];
        }

        return v1==v2;
    }
};