/* 

给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。

矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。



 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]
示例 2：

输入：matrix = [[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-109 <= matrix[i][j] <= 109
通过次数45,790提交次数68,031

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/transpose-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
using std::cout;
using std::vector;
class transpose_matrix
{
private:
    /* data */
public:
    transpose_matrix(/* args */);
    ~transpose_matrix();
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        // vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size()));
        vector<vector<int>> ans(matrix[0].size(), vector<int>(matrix.size()));

        for (int i = 0; i < ans.size(); ++i)
        {
            for (int j = 0; j < ans[0].size(); ++j)
            {
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};

transpose_matrix::transpose_matrix(/* args */)
{
}

transpose_matrix::~transpose_matrix()
{
}

int main()
{
    // 1    2   3
    // 4    5   6

    /* 
    
            1   2   3           1   4
            4   5   6           2   5       
                                3   6
     */
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}};
    transpose_matrix tm;
    for (auto &vec : tm.transpose(matrix))
    {
        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

// Thu,Feb25,2021
// 08:51:18:558:637498398785585553
