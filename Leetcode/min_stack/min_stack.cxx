/* 

设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
 

示例:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 

提示：

pop、top 和 getMin 操作总是在 非空栈 上调用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */
#include <iostream>
#include <vector>
#include <unordered_set>
using std::cout;
using std::endl;
using std::unordered_multiset;
using std::vector;

class MinStack
{

private:
    vector<int> min_stack;
    int min_of_stack = INT32_MIN;
    // int pre_min_of_stack = INT32_MIN;
    vector<int> min_value;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        // pre_min_of_stack = min_of_stack;
        min_of_stack = (!min_stack.size() || x < min_of_stack) ? x : min_of_stack;
        min_value.push_back(min_of_stack);
        min_stack.push_back(x);
    }

    void pop()
    {
        min_stack.pop_back();
        min_value.pop_back();
        // min_of_stack = *--min_value.end();
        min_of_stack = min_value[min_value.size() - 1];
    }

    int top()
    {

        // return *--min_stack.end();
        return min_stack[min_stack.size() - 1];
    }

    int getMin()
    {
        return min_of_stack;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    /* 
    
    ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
    [[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]

    
    ["MinStack",           [[],
    "push",                [2147483646],
    "push",                [2147483646],
    "push",                [2147483647],
    "top",                 [],
    "pop",                 [],
    "getMin",              [],
    "pop",                 [],
    "getMin",              [],
    "pop",                 [],
    "push",                [2147483647],
    "top",                 [],
    "getMin",              [],
    "push",                [-2147483648],
    "top",                 [],
    "getMin",              [],
    "pop",                 [],
    "getMin"]              []]
    
     */
    MinStack *obj = new MinStack(); //0
    obj->push(2147483646);          //1
    obj->push(2147483646);          //2
    obj->push(2147483647);          //3
    int temp = obj->top();          //4
    obj->pop();                     //5
    int temp_1 = obj->getMin();     //6
    obj->pop();                     //7
    int temp_2 = obj->getMin();     //8
    obj->pop();                     //9
    obj->push(2147483647);          //10
    int temp_3 = obj->top();        //11
    int temp_4 = obj->getMin();     //12
    obj->push(-2147483648);         //13
    int temp_5 = obj->top();        //14
    int temp_6 = obj->getMin();     //15
    obj->pop();                     //16
    int temp_7 = obj->getMin();     //17

    cout << temp << endl;
    cout << temp_1 << endl;
    cout << temp_2 << endl;
    cout << temp_3 << endl;
    cout << temp_4 << endl;
    cout << temp_5 << endl;
    cout << temp_6 << endl;
    cout << temp_7 << endl;

    // int param_1 = obj->getMin();

    // obj->pop();
    // cout << obj->top() << endl;
    // cout << param_1 << endl;
}

/* 

=================================================================
==42==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000001328 at pc 0x000000350993 bp 0x7ffd2a34da20 sp 0x7ffd2a34da18
READ of size 8 at 0x603000001328 thread T0
    #4 0x7f912f7660b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x603000001328 is located 8 bytes to the left of 32-byte region [0x603000001330,0x603000001350)
allocated by thread T0 here:
    #6 0x7f912f7660b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
Shadow bytes around the buggy address:
  0x0c067fff8210: fa fa fd fd fd fd fa fa fd fd fd fd fa fa fd fd
  0x0c067fff8220: fd fa fa fa fd fd fd fd fa fa 00 00 00 00 fa fa
  0x0c067fff8230: fd fd fd fd fa fa 00 00 00 00 fa fa fd fd fd fd
  0x0c067fff8240: fa fa 00 00 00 00 fa fa fd fd fd fd fa fa 00 00
  0x0c067fff8250: 00 00 fa fa fd fd fd fd fa fa 00 00 00 00 fa fa
=>0x0c067fff8260: fd fd fd fd fa[fa]00 00 00 00 fa fa 00 00 00 00
  0x0c067fff8270: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8280: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8290: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff82a0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff82b0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
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

// Mon,Feb1,2021