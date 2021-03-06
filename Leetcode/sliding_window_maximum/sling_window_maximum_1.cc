/* 

给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::find;
using std::sort;
using std::vector;

class sliding_window_maximum
{

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if(k<=1)
        {
            return nums;
        }
        auto front = nums.begin();
        auto back = nums.begin() + k - 1;
        vector<int> slidngWindow(front, back+1);
        vector<int> ans;
        sort(slidngWindow.begin(), slidngWindow.end());
        int max_in_sliding_window = *--slidngWindow.end();
        ans.push_back(max_in_sliding_window);
        while (back != nums.end() - 1)
        {
            slidngWindow.erase(find(slidngWindow.begin(), slidngWindow.end(), *front));
            ++front;
            ++back;
            if (*back >= *--slidngWindow.end())
            {
                slidngWindow.push_back(*back);
            }
            else
            {
                for (auto it = slidngWindow.begin(); it != slidngWindow.end(); ++it)
                {
                    if (*it > *back)
                    {
                        slidngWindow.insert(it, *back);
                        break;
                    }
                }
            }
            max_in_sliding_window = *--slidngWindow.end();
            ans.push_back(max_in_sliding_window);
        }
        return ans;
    }
};

int main()
{
    sliding_window_maximum swm;
    vector<int> nums{1,-1};
    auto ans = swm.maxSlidingWindow(nums,1);
    for (auto i : ans)
    {
        std::cout << i << " ";
    }
}

// Thu,Feb4,2021