/* 

给你一个由一些多米诺骨牌组成的列表 dominoes。

如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。

形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。

在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。

 

示例：

输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
输出：1
 

提示：

1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9
通过次数34,503提交次数63,321

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class number_of_equivalent_domino_pairs
{
private:
    /* data */
public:
    number_of_equivalent_domino_pairs(/* args */);
    ~number_of_equivalent_domino_pairs();
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        [[un_finished]]
        vector<int> pos;
        vector<int> neg;
        vector<int> bk1(19);
        vector<int> bk2(17);

        
        for (auto &vec : dominoes)
        {
            pos.push_back(vec[0] + vec[1]);
            neg.push_back(vec[0] - vec[1] > 0 ? vec[0] - vec[1] : vec[1] - vec[0]);
            ++bk1[vec[0] + vec[1]];
            ++bk2[vec[0] - vec[1] > 0 ? vec[0] - vec[1] : vec[1] - vec[0]];
        }

        int cnt1 = 0;
        for (int i = 0; i < bk1.size(); ++i)
        {
            cnt1 += bk1[i] >> 1;
        }
        int cnt2 = 0;
        for (int i = 0; i < bk2.size(); ++i)
        {
            cnt2 += bk2[i] >> 1;
        }
        return cnt1 > cnt2 ? cnt2 : cnt1;
    }
};

number_of_equivalent_domino_pairs::number_of_equivalent_domino_pairs(/* args */)
{
}

number_of_equivalent_domino_pairs::~number_of_equivalent_domino_pairs()
{
}

int main()
{
    // [[1,2],[1,2],[1,1],[1,2],[2,2]]
    vector<vector<int>> dominoes{{1, 2}, {2, 1}, {1, 1}, {1, 2},{2,2}};
    number_of_equivalent_domino_pairs noedp;
    cout << noedp.numEquivDominoPairs(dominoes) << "\n";
}

/* 

    a + b = s1      c + d = s1
    a - b = s2      c - d = s2

    a + b = c + d
    a - b = c - d
       2a = 2c
        a = c

 */
