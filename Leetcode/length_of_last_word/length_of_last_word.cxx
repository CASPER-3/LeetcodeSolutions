/* 

给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

 

示例:

输入: "Hello World"
输出: 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/length-of-last-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
class length_of_last_word
{
private:
    /* data */
public:
    length_of_last_word(/* args */);
    ~length_of_last_word();
    int lengthOfLastWord(string s)
    {
        if (s.size() == 0 || (s.size() == 1 && s == " "))
        {
            return 0;
        }
        if (s.size() == 1)
        {
            return 1;
        }
        auto bg = s.begin();
        auto ed = s.end() - 1;
        int count = 0;
        while (ed >= bg)
        {
            if ((*ed) == ' ' && count)
            {
                return count;
            }
            count = ((*ed) == ' ') ? count : count + 1;
            --ed;
        }
        return count;
    }
};

length_of_last_word::length_of_last_word(/* args */)
{
}

length_of_last_word::~length_of_last_word()
{
}

int main()
{
    length_of_last_word lolw;
    string s = "a ";
    cout << lolw.lengthOfLastWord(s) << endl;
}

// Fri,Jan29,2021
