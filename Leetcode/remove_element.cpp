/*

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

 

示例 1:

给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。
 

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class remove_element
{
private:
    /* data */
public:
    remove_element(/* args */);
    ~remove_element();
    int removeElement(vector<int> &nums, int val)
    {
        auto bg = nums.begin();
        auto ed = nums.end();
        while (bg != ed)
        {
            *bg = (*bg == val) ? *(--ed) : *(++bg);
        }
        return static_cast<int>(ed - nums.begin());
    }
};

remove_element::remove_element(/* args */)
{
}

remove_element::~remove_element()
{
}

int main()
{
    vector<int> ivec = {0,1,2,2,3,0,4,2};
    const int num = 2;
    remove_element rel;
    cout << rel.removeElement(ivec, num) << endl;
    for (auto i : ivec)
    {
        cout << i << " ";
    }
    return 0;
}

//Wed,Jan27,2021

/*

==42==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000038 at pc 0x00000034e635 bp 0x7ffd993ee130 sp 0x7ffd993ee128
READ of size 4 at 0x602000000038 thread T0
    #2 0x7ffb6ce2c0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x602000000038 is located 0 bytes to the right of 8-byte region [0x602000000030,0x602000000038)
allocated by thread T0 here:
    #5 0x7ffb6ce2c0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
Shadow bytes around the buggy address:
  0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c047fff8000: fa fa fd fa fa fa 00[fa]fa fa fa fa fa fa fa fa
  0x0c047fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==42==ABORTING

*/

//origin code is tested correctly in local environment but failure in online.the code below is the final passed code after modify.

/*

int removeElement(vector<int> &nums, int val)
    {
        if(nums.size()==0)
        {
            return 0;
        }
        auto bg = nums.begin();
        auto ed = nums.end();
        while (bg != ed-1)
        {
            *bg = (*bg == val) ? *(--ed) : *(++bg);
        }
        *bg=(*bg==val)?(*--ed):*(++bg);
        return static_cast<int>(ed - nums.begin());
    }

*/