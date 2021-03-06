/* 

外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。

字谜的迷面 puzzle 按字符串形式给出，如果一个单词 word 符合下面两个条件，那么它就可以算作谜底：

单词 word 中包含谜面 puzzle 的第一个字母。
单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
例如，如果字谜的谜面是 "abcdefg"，那么可以作为谜底的单词有 "faced", "cabbage", 和 "baggage"；而 "beefed"（不含字母 "a"）以及 "based"（其中的 "s" 没有出现在谜面中）。
返回一个答案数组 answer，数组中的每个元素 answer[i] 是在给出的单词列表 words 中可以作为字谜迷面 puzzles[i] 所对应的谜底的单词数目。

 

示例：

输入：
words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
输出：[1,1,3,2,4,0]
解释：
1 个单词可以作为 "aboveyz" 的谜底 : "aaaa" 
1 个单词可以作为 "abrodyz" 的谜底 : "aaaa"
3 个单词可以作为 "abslute" 的谜底 : "aaaa", "asas", "able"
2 个单词可以作为 "absoryz" 的谜底 : "aaaa", "asas"
4 个单词可以作为 "actresz" 的谜底 : "aaaa", "asas", "actt", "access"
没有单词可以作为 "gaswxyz" 的谜底，因为列表中的单词都不含字母 'g'。
 

提示：

1 <= words.length <= 10^5
4 <= words[i].length <= 50
1 <= puzzles.length <= 10^4
puzzles[i].length == 7
words[i][j], puzzles[i][j] 都是小写英文字母。
每个 puzzles[i] 所包含的字符都不重复。
通过次数2,792提交次数7,881

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <bitset>
using std::bitset;
using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

class number_of_valid_words_for_each_puzzle
{

public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        unordered_map<bitset<26>, int> dictionary;
        vector<int> ans;

        for (auto sw : words)
        {
            bitset<26> bs;
            for (auto c : sw)
            {
                bs.set(c - 97);
            }

            if(bs.count()>7)
            {
                continue;
            }

            if (dictionary.count(bs))
            {
                ++dictionary[bs];
            }
            else
            {
                dictionary[bs] = 1;
            }
        }

        for (auto sp : puzzles)
        {
            bitset<26> sc(0);
            sc.set(sp[0] - 97);
            int count = 0;
            for (int i = 0; i < 64; ++i)
            {
                bitset<6> temp(i);
                for (int j = 0; j < 6; ++j)
                {
                    if (temp[j])
                    {
                        sc.set(sp[j + 1] - 97);
                    }
                }
                count += dictionary[sc];
                sc.reset();
                sc.set(sp[0] - 97);
            }
            ans.push_back(count);
        }

        return ans;
    }
};

int main()
{

    // vector<string> words{"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    // vector<string> puzzles{"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
    vector<string> words{"apple", "pleas", "please"};
    vector<string> puzzles{"aelwxyz", "aelpxyz", "aelpsxy", "saelpxy", "xaelpsy"};
    number_of_valid_words_for_each_puzzle novwfep;

    for (auto i : novwfep.findNumOfValidWords(words, puzzles))
    {

        cout << i << " ";
    }
}


// 
// Fri,Feb26,2021
