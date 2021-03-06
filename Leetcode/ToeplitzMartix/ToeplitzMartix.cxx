/* 

给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。

如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。

 

示例 1：

1   2   3   4
5   1   2   3
9   5   1   2


输入：matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
输出：true
解释：
在上述矩阵中, 其对角线为: 
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。 
各条对角线上的所有元素均相同, 因此答案是 True 。
示例 2：


输入：matrix = [[1,2],[2,2]]
输出：false
解释：
对角线 "[1, 2]" 上的元素不同。
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99
 

进阶：

如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？
如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/toeplitz-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class ToeplitzMartix
{
private:
    /* data */
public:
    ToeplitzMartix(/* args */);
    ~ToeplitzMartix();
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix[matrix.size() - 1].size(); ++i)
        {
            int tempval = matrix[matrix.size() - 1][i];
            int posx = i - 1;
            int posy = (matrix.size() - 2);
            while (posx >= 0 && posy >= 0)
            {
                if (matrix[posy][posx] != tempval)
                {
                    return false;
                }
                --posx;
                --posy;
            }
        }

        for (int i = matrix.size() - 1; i >= 0; --i)
        {
            int tempval = matrix[i][matrix[0].size() - 1];
            int posx = matrix[0].size() - 2;
            int posy = i - 1;
            while (posx >= 0 && posy >= 0)
            {
                if (matrix[posy][posx] != tempval)
                {
                    return false;
                }
                --posx;
                --posy;
            }
        }
        return true;
    }
};

ToeplitzMartix::ToeplitzMartix(/* args */)
{
}

ToeplitzMartix::~ToeplitzMartix()
{
}

int main()
{
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
    ToeplitzMartix tom;
    cout << tom.isToeplitzMatrix(matrix) << "\n";
}

/* 

[[44,35,39],[15,44,35],[17,15,44],[80,17,15],[43,80,0],[77,43,80]]
44  35  39
15  44  35
17  15  44
80  17  15
43  80  0
77  43  80

 */

// Mon,Feb22,2021
// 09:16:19:323:637495821793234549