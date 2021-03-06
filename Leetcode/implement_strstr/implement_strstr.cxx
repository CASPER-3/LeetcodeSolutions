/* 

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <string>
using std::cout;
using std::string;
class implement_strstr
{
private:
    /* data */
public:
    implement_strstr(/* args */);
    ~implement_strstr();
    int strStr(string haystack, string needle)
    {
        if (!needle.size())
        {
            return 0;
        }
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        if (haystack.size() == needle.size())
        {
            int strLen = haystack.size();
            for (int i = 0; i < strLen; ++i)
            {
                if (haystack[i] != needle[i])
                {
                    return -1;
                }
            }
            return 0;
        }

        int location = -1;
        int strLength = needle.size();

        auto bg = haystack.begin();
        auto ed = haystack.end();

        while (bg != ed)
        {
            if (*bg == needle[0] && (ed - bg) >= strLength)
            {
                bool flag = true;
                for (int i = 0; i < strLength; ++i)
                {
                    if (*(bg + i) != needle[i])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    return static_cast<int>(bg - haystack.begin());
                }
            }
            ++bg;
        }
        return location;
    }
};

implement_strstr::implement_strstr(/* args */)
{
}

implement_strstr::~implement_strstr()
{
}

int main()
{
    string haystack = "hello";
    string needle = "ll";
    implement_strstr is;
    cout << is.strStr(haystack, needle) << std::endl;
}
// Fri,Jan29,2021
