/* 

给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

注意：请不要在超过该数组长度的位置写入元素。

要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

 

示例 1：

输入：[1,0,2,3,0,4,5,0]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
示例 2：

输入：[1,2,3]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,2,3]
 

提示：

1 <= arr.length <= 10000
0 <= arr[i] <= 9
通过次数15,740提交次数27,151

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/duplicate-zeros
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
using std::cout;
using std::vector;
class duplicate_zeros
{
private:
    /* data */
public:
    duplicate_zeros(/* args */);
    ~duplicate_zeros();
    void duplicateZeros(vector<int> &arr)
    {
        for(int i=0;i<arr.size();++i)
        {
            if(!arr[i])
            {
                int temp=0;
                for(int j=i+1;j<arr.size();++j)
                {
                    int ori=arr[j];
                    arr[j]=temp;
                    temp=ori;
                }
                ++i;
            }
        }
    }
};

duplicate_zeros::duplicate_zeros(/* args */)
{
}

duplicate_zeros::~duplicate_zeros()
{
}

int main()
{
    duplicate_zeros dz;
    vector<int> ivec{1, 0, 2, 3, 0, 4, 5, 0};
    dz.duplicateZeros(ivec);
    for (auto i : ivec)
    {
        cout << i << " ";
    }
}

// 性能太差.
// Wed,Feb24,2021
// 13:36:43:199:637497706031997470