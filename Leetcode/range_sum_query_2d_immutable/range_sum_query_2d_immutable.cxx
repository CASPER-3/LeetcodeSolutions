/* 

304. 二维区域和检索 - 矩阵不可变

difficulty: medium

给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。

Range Sum Query 2D
上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。

示例:

给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
说明:

你可以假设矩阵不可变。
会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。
通过次数18,200提交次数37,409

会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。
通过次数18,200提交次数37,409

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <utility>
using std::move;
using std::vector;

class NumMatrix
{

  vector<vector<int>> imatrix;

public:
  NumMatrix(vector<vector<int>> &matrix)
  {
    imatrix = move(matrix);
    for (auto &vec : imatrix)
    {
      for (int i = 1; i < vec.size(); ++i)
      {
        vec[i] += vec[i - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    int sum = 0;
    for (int i = row1; i <= row2; ++i)
    {
      sum += col1 ? imatrix[i][col2] - imatrix[i][col1 - 1] : imatrix[i][col2];
    }
    return sum;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */



// 大概是最朴素的解法?一维前缀和.时间百分之5,空间百分之100,笑了.
// Tue,March2,2021
// 09:42:32:622:637502749526220292


/* 

Today is the 61th day of 2021

2021 has passed 16.5492389649924%

Fuck Life.

 */