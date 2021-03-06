/* 

示例 1:

输入: 5
输出: 2
解释: 5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
示例 2:

输入: 1
输出: 0
解释: 1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。
 

注意:

给定的整数保证在 32 位带符号整数的范围内。
你可以假定二进制数不包含前导零位。
本题与 1009 https://leetcode-cn.com/problems/complement-of-base-10-integer/ 相同
通过次数30,466提交次数43,755

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-complement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */
#include <iostream>
#include <vector>
#include <bitset>
using std::cout;
using std::bitset;
using std::vector;
class number_complement
{
private:
    /* data */
public:
    number_complement(/* args */);
    ~number_complement();
    int findComplement(int num)
    {
        bitset<32> bs(num);
        size_t pos=0;
        while(bs._Find_first()!=32)
        {

        }
        return bs._Find_first();
    }
};

number_complement::number_complement(/* args */)
{
}

number_complement::~number_complement()
{
}

int main()
{
    
    int ia=0;
    number_complement nc;
    cout<<nc.findComplement(ia);
    
}

// Thu,Feb25,2021
