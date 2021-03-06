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
#include <unordered_set>
using std::cout;
using std::string;
using std::unordered_set;
using std::vector;

class number_of_valid_words_for_each_puzzle
{

public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        
        vector<int> ans;
        for (auto sp : puzzles)
        {
            unordered_set<char> ps(sp.begin(), sp.end());
            int count = 0;
            for (auto sw : words)
            {
                unordered_set<char> ws(sw.begin(), sw.end());
                if (!ws.count(sp[0]))
                {
                    continue;
                }
                else
                {
                    bool flag = true;
                    for (int i = 0; i < sw.size(); ++i)
                    {
                        if (!ps.count(sw[i]))
                        {
                            flag = false;
                            break;
                        }
                    }
                    count = flag ? count + 1 : count;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};



int main()
{
    
}


/* 

前言
我们首先需要理解清楚题目中的字谜规则：

对于单词 {word}word 以及谜面 {puzzle}puzzle，设 S_wS 
w
​	
  表示 {word}word 中出现的字母组成的「不重复」集合，S_pS 
p
​	
  表示 {puzzle}puzzle 中出现的字母组成的集合（由于题目中规定了 {puzzle}puzzle 中出现的字母是不重复的，因此这个集合本身也是「不重复」的）。

如果存在 S_pS 
p
​	
  的一个子集 S'_pS 
p
′
​	
 ，并且 S'_pS 
p
′
​	
  包含 {puzzle}puzzle 中的首字母，使得 S_w = S'_pS 
w
​	
 =S 
p
′
​	
 ，那么 {word}word 就是 {puzzle}puzzle 的谜底。

因此，我们可以设计出解决该字谜问题的一个算法流程：

首先我们计算出每一个 {word}word 对应的集合 S_wS 
w
​	
 ，存放在某一「数据结构」中，便于后续操作中的快速查找；

随后我们依次枚举每一个 {puzzle}puzzle，计算出其对应的集合 S_pS 
p
​	
 ，并枚举满足要求的子集 S'_pS 
p
′
​	
 。对于每一个 S'_pS 
p
′
​	
 ，我们在「数据结构」中查找其出现的次数，那么所有的 S'_pS 
p
′
​	
  出现次数之和就是 {puzzle}puzzle 对应的谜底个数。

存放 S_wS 
w
​	
  对应的「数据结构」可以有多种选择，本篇题解中会介绍较为常用的两种。

方法一：二进制状态压缩
思路与算法

由于题目中规定 {word}word 和 {puzzle}puzzle 均只包含小写字母，因此 S_wS 
w
​	
  和 S_pS 
p
​	
  的大小最多为 2626，我们可以考虑使用一个长度为 2626 的二进制数 b_wb 
w
​	
  或 b_pb 
p
​	
  来表示这一集合。

对于 b_wb 
w
​	
  从低到高的第 ii 个二进制位（ii 从 00 开始编号），如果 S_wS 
w
​	
  中包含第 ii 个小写字母，那么对应的二进制位为 11，否则为 00。

因此我们可以使用一个哈希映射来表示需要的「数据结构」：对于哈希映射中的每一个键值对，其中的键表示一个长度为 2626 的二进制数，值表示其出现的次数，即数组 {words}words 中多少个 {word}word 压缩成的二进制数等于键。构造哈希映射的过程也很简单：我们只需要遍历每一个 {word}word，并遍历 {word}word 中的每一个字母，将对应位置的二进制位标记为 11，这样就计算出了 {word}word 对应的二进制表示，将其在哈希映射中作为键对应的值增加 11 即可。

对于 {puzzle}puzzle 对应的 b_pb 
p
​	
 ，我们可以通过相同的方法求出，那么接下来就需要枚举 b_pb 
p
​	
  的子集 b'_pb 
p
′
​	
  了。枚举一个二进制数的子集也有多种方法，这里介绍常用的两种：

第一种：由于题目中规定 {puzzle}puzzle 的长度恰好为 77，因此我们可以枚举所有 66 位的二进制数（因为 {puzzle}puzzle 中的首字母必须要出现，因此最高位必须是 11，我们只需要枚举剩余的 66 位就行了）。对于每个枚举出的 66 位二进制数，我们遍历 {puzzle}puzzle 中除了首字母以外的其余 66 个字母，只有当二进制位为 11 时，我们才将 {puzzle}puzzle 中的字母在二进制表示中的二进制位标记位 11。这样我们就得到了每一个 b'_pb 
p
′
​	
  对应的二进制表示。

第二种：我们也可以使用通用的「枚举二进制子集」的方法，下面给出伪代码：


function get_subset(bitmask)
    subset = bitmask
    answer = [bitmask]
    while subset != 0
        subset = (subset - 1) & bitmask
        put subset into the answer list
    end while
    return answer
end function
其中 \texttt{bitmask}bitmask 表示一个二进制数，\texttt{subset}subset 会遍历所有 \texttt{bitmask}bitmask 的子集，并将所有的子集放入 \texttt{answer}answer 中。需要注意的是，\texttt{bitmask}bitmask 本身也是 \texttt{bitmask}bitmask 的一个子集，因此 \texttt{answer}answer 在初始时就包含 \texttt{bitmask}bitmask 本身。

与第一种方法类似，我们需要保证 {puzzle}puzzle 中的首字母必须要出现，因此在使用第二种方法枚举子集时，我们先将首字母对应的二进制位标记为 00，每枚举到一个子集，就将首字母对应的二进制位标记为 11，这样得到的子集都是满足要求的。

在得到了 b_pb 
p
​	
  的子集 b'_pb 
p
′
​	
  后，我们将 b'_pb 
p
′
​	
  在哈希映射中对应的值累计入答案，这样 b_pb 
p
​	
  的所有子集的累加和就是其作为谜面的谜底数量。

细节

在遍历 {word}word 时，如果 b_wb 
w
​	
  中包含的 11 的数量大于 77，那么它一定无法作为谜底，因此我们无需将其加入哈希映射中。

代码


class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> frequency;

        for (const string& word: words) {
            int mask = 0;
            for (char ch: word) {
                mask |= (1 << (ch - 'a'));
            }
            if (__builtin_popcount(mask) <= 7) {
                ++frequency[mask];
            }
        }

        vector<int> ans;
        for (const string& puzzle: puzzles) {
            int total = 0;

            // 枚举子集方法一
            // for (int choose = 0; choose < (1 << 6); ++choose) {
            //     int mask = 0;
            //     for (int i = 0; i < 6; ++i) {
            //         if (choose & (1 << i)) {
            //             mask |= (1 << (puzzle[i + 1] - 'a'));
            //         }
            //     }
            //     mask |= (1 << (puzzle[0] - 'a'));
            //     if (frequency.count(mask)) {
            //         total += frequency[mask];
            //     }
            // }

            // 枚举子集方法二
            int mask = 0;
            for (int i = 1; i < 7; ++i) {
                mask |= (1 << (puzzle[i] - 'a'));
            }
            int subset = mask;
            do {
                int s = subset | (1 << (puzzle[0] - 'a'));
                if (frequency.count(s)) {
                    total += frequency[s];
                }
                subset = (subset - 1) & mask;
            } while (subset != mask);
            
            ans.push_back(total);
        }
        return ans;
    }
};
复杂度分析

时间复杂度：O(m|w| + n2^{|p|})O(m∣w∣+n2 
∣p∣
 )，其中 mm 和 nn 分别是数组 {words}words 和 {puzzles}puzzles 的长度，|w|∣w∣ 是 {word}word 的最大长度 5050，|p|∣p∣ 是 {puzzle}puzzle 的最大长度 77。时间复杂度分为三部分：

计算所有 {word}word 对应的二进制表示的时间复杂度为 O(m|w|)O(m∣w∣)；

计算所有 {puzzle}puzzle 对应的二进制表示的时间复杂度为 O(n|p|)O(n∣p∣)；

枚举 {puzzle}puzzle 的子集的时间复杂度为 O(n2^{|p|-1})O(n2 
∣p∣−1
 )，这里为使用第二种方法的时间复杂度，如果使用第一种方法，那么时间复杂度略高，为 O(n(|p|-1)2^{|p|-1})O(n(∣p∣−1)2 
∣p∣−1
 )。

由于 |p|-1∣p∣−1 与 |p|∣p∣ 同阶，因此写成 O(|p|)O(∣p∣) 更加简洁。并且由于第三部分的时间复杂度在渐进意义下严格大于第二部分，因此总时间复杂度即为第一部分与第三部分之和 O(m|w| + n2^{|p|})O(m∣w∣+n2 
∣p∣
 )。

空间复杂度：O(m)O(m)，即为哈希映射需要使用的空间，其中最多只包含 mm 个键值对。

方法二：字典树
思路与算法

由于题目中规定 {word}word 和 {puzzle}puzzle 均只包含小写字母，我们也可以考虑使用字典树来表示需要的「数据结构」。由于方法一中已经详细介绍了每一步的做法，因此方法二中只介绍与方法一不同的地方。

对于每一个 {word}word 对应的集合 S_wS 
w
​	
 ，我们将 S_wS 
w
​	
  中的的字母按照字典序进行排序，组成一个字符串，加入字典树中。与方法一中的哈希映射类似，我们需要统计每个字符串在字典树中的出现次数。

对于每一个 {puzzle}puzzle 对应的集合 S_pS 
p
​	
 ，我们枚举 S_pS 
p
​	
  的子集，并将子集中的字母按照字典序进行排序，组成一个字符串，在字典树中查询得到其出现次数。需要注意的是，由于 S_pS 
p
​	
  只是一个普通的集合，而不是二进制表示，因此我们可以使用回溯的方法，在枚举子集的同时维护可以在字典树上进行查询的指针。详细的实现可以见下面的代码。

细节

在实际的实现中，我们无需显式地构造出加入字典树以及在字典树中查询需要的字符串，可以考虑使用一些等价的简单数据结构（例如列表）表示字符串。

代码

下面给出的 \texttt{C++}C++ 代码中并未析构字典树申请的堆空间。

C++JavaPython3GolangC

struct TrieNode {
    int frequency = 0;
    TrieNode* child[26];

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }
};

class Solution {
private:
    TrieNode* root;

public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        root = new TrieNode();

        auto add = [&](const string& word) {
            TrieNode* cur = root;
            for (char ch: word) {
                if (!cur->child[ch - 'a']) {
                    cur->child[ch - 'a'] = new TrieNode();
                }
                cur = cur->child[ch - 'a'];
            }
            ++cur->frequency;
        };

        // 在回溯的过程中枚举 puzzle 的所有子集并统计答案
        // find(puzzle, required, cur, pos) 表示 puzzle 的首字母为 required, 当前搜索到字典树上的 cur 节点，并且准备枚举 puzzle 的第 pos 个字母是否选择（放入子集中）
        // find 函数的返回值即为谜底的数量
        function<int(const string&, char, TrieNode*, int)> find = [&](const string& puzzle, char required, TrieNode* cur, int pos) {
            // 搜索到空节点，不合法，返回 0
            if (!cur) {
                return 0;
            }
            // 整个 puzzle 搜索完毕，返回谜底的数量
            if (pos == 7) {
                return cur->frequency;
            }
            
            // 选择第 pos 个字母
            int ret = find(puzzle, required, cur->child[puzzle[pos] - 'a'], pos + 1);

            // 当 puzzle[pos] 不为首字母时，可以不选择第 pos 个字母
            if (puzzle[pos] != required) {
                ret += find(puzzle, required, cur, pos + 1);
            }
            
            return ret;
        };
        
        for (string word: words) {
            // 将 word 中的字母按照字典序排序并去重
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
            // 加入字典树中
            add(word);
        }

        vector<int> ans;
        for (string puzzle: puzzles) {
            char required = puzzle[0];
            sort(puzzle.begin(), puzzle.end());
            ans.push_back(find(puzzle, required, root, 0));
        }
        return ans;
    }
};
复杂度分析

时间复杂度：O(m|w|\log|w| + n2^{|p|})O(m∣w∣log∣w∣+n2 
∣p∣
 )，其中 mm 和 nn 分别是数组 {words}words 和 {puzzles}puzzles 的长度，|w|∣w∣ 是 {word}word 的最大长度 5050，|p|∣p∣ 是 {puzzle}puzzle 的最大长度 77。时间复杂度分为四部分：

计算所有 {word}word 对应的集合，进行排序的时间复杂度为 O(m|w|\log|w|)O(m∣w∣log∣w∣)；

将第一部分加入字典树的时间复杂度为 O(m|w|)O(m∣w∣)；

计算所有 {puzzle}puzzle 对应的集合，进行排序的时间复杂度为 O(n|p|\log|p|)O(n∣p∣log∣p∣)；

枚举 {puzzle}puzzle 的子集并在字典树中查询子集的复杂度为 O(n2^{|p|-1})O(n2 
∣p∣−1
 )。

由于 |p|-1∣p∣−1 与 |p|∣p∣ 同阶，因此写成 O(|p|)O(∣p∣) 更加简洁。并且由于第一部分的时间复杂度在渐进意义下严格大于第二部分，第四部分的时间复杂度在渐进意义下严格大于第三部分，因此总时间复杂度即为第一部分与第四部分之和 O(m|w|\log|w| + n2^{|p|})O(m∣w∣log∣w∣+n2 
∣p∣
 )。

空间复杂度：O(m|w| + |p|)O(m∣w∣+∣p∣)。字典树需要使用的空间为 O(m|w|)O(m∣w∣)，将 {word}word 加入字典树时，需要用 O(|w|)O(∣w∣) 的空间存储 {word}word 按照字典序排序后的结果，其在渐进意义下严格小于 O(m|w|)O(m∣w∣) 可忽略。在使用回溯的方法在字典树中查询 {puzzle}puzzle 的子集时，需要使用 O(|p|)O(∣p∣) 的空间存储 {puzzle}puzzle 按照字典序排序后的结果，并且需要 O(|p|)O(∣p∣) 的栈空间，因此总空间复杂度为 O(m|w| + |p|)O(m∣w∣+∣p∣)。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/solution/cai-zi-mi-by-leetcode-solution-345u/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */