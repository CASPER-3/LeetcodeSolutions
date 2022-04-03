/* 

6. Z 字形变换
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 

示例 1：

输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
示例 3：

输入：s = "A", numRows = 1
输出："A"
 

提示：

1 <= s.length <= 1000
s 由英文字母（小写和大写）、',' 和 '.' 组成
1 <= numRows <= 1000

 */

#include <string>
#include <vector>
using std::vector;
using std::string;
#include <iostream>
using std::cout;
using std::endl;

/* class Solution {
public:
    string convert(string s, int numRows) {

        vector<string> martix(numRows,"");
        //martix.reserve(numRows);
        int line = 1;
        int pos = 0;
        while(pos < s.size())
        {
            int i = 0;
            if(line % (numRows-1) == 1)
            {
                while(i < numRows)
                {
                    martix[i++].push_back(s[pos++]);
                }
            }
            else
            {   i = numRows - 2;
                if(i!=0 || i!=numRows-1)
                {
                    martix[i--].push_back(s[pos++]);
                }
            }
            ++line;
        
        }
        
        string res="";
        for(auto &str : martix)
        {
            res+=str;
        }
        return res;
        
    }
}; */

class Solution {
public:
    string convert(string s, int numRows) {

        if(s.size() == 1 || numRows == 1 ||(s.size()==numRows))
            return s;
        if(numRows == 2)
        {
            int i = 0;
            string res{""};
            while(i < s.size())
            {
                res.push_back(s[i]);
                i +=2;
            }
            i = 1;
            while(i < s.size())
            {
                res.push_back(s[i]);
                i +=2;
            }
            return res;
        }

        vector<string> martix(numRows,"");
        //martix.reserve(numRows);
        int line = 1;
        int pos = 0;
        int diff = 0;
        while(pos < s.size())
        {
            int i = 0;
            if(line % (numRows-1) == 1)
            {
                while(i < numRows && pos < s.size())
                {
                    martix[i++].push_back(s[pos++]);
                }
                diff = 0;
            }
            else
            {   
                i = numRows - 2 - diff;
                if(i > 0 && pos < s.size())
                {
                    martix[i].push_back(s[pos++]);
                    ++diff;
                }          
            }
            ++line;
        
        }
        
        string res="";
        for(auto &str : martix)
        {
            cout<<str<<endl;
            res+=str;
        }
        return res;
        
    }
};

int main()
{
    Solution sl;
    string str {"PAYPALISHIRING"};
    sl.convert(str,4);
}

//Tue,Mar1,2022
//勉强通过了,但是是很糟糕的写法.