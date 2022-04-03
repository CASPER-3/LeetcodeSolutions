#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {

        queue<int> que;

        int res = 0;
        int sz = ops.size();
        for(int i = 0;i < sz;++i)
        {
            if(isalpha(ops[i][0]))
            {
                if(ops[i][0]=='C')
                 {
                     res-=que.back();
                     que.pop();
                 }
                else if(ops[i][0]=='D')
                {
                    res+=que.back()*2;
                    que.push(que.back()*2);
                }
                    
            }
            else if(isdigit(ops[i][0]))
            {
                res+=ops[i][0]-'0';
                que.push(ops[i][0]-'0');

            }
            else
            {
                int temp = que.back();
                que.pop();
                int sum = temp + que.back();
                que.push(temp);
                que.push(sum);
                res+=sum;
            }
        }
        return res;

    }
};

int main()
{
    vector<string> source {"5","2","C","D","+"};
    Solution sl;
    sl.calPoints(source);
}

