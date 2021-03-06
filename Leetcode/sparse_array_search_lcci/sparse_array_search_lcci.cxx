/* 

稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。

示例1:

 输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
 输出：-1
 说明: 不存在返回-1。
示例2:

 输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
 输出：4
提示:

words的长度在[1, 1000000]之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sparse-array-search-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class sparse_array_search_lcci
{
private:
    /* data */
public:
    sparse_array_search_lcci(/* args */);
    ~sparse_array_search_lcci();
    int findString(vector<string> &words, string s)
    {
        int left = 0;
        int right = words.size() - 1;
        return find(words, left, right, s);
    }
    int find(vector<string> &words, int left, int right, string s)
    {

        while ((words[left] == "" || words[right] == "") && left < right)
        {
            left = words[left] == "" ? left + 1 : left;
            right = words[right] == "" ? right - 1 : right;
        }

        if (words[left] > s || words[right] < s)
        {
            return -1;
        }

        int mid = (left + right) >> 1;

        while (mid > left && words[mid] == "")
        {
            --mid;
        }

        if (words[mid] == s)
        {
            return mid;
        }

        if (words[mid] < s)
        {
            return find(words, mid + 1, right, s);
        }
        else
        {
            return find(words, left, mid - 1, s);
        }
    }
};

sparse_array_search_lcci::sparse_array_search_lcci(/* args */)
{
}

sparse_array_search_lcci::~sparse_array_search_lcci()
{
}

int main()
{
    sparse_array_search_lcci sasl;
    vector<string> svec{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    cout << sasl.findString(svec, "ball") << endl;
}

// Thu,Feb18,2021

/* 
Today is the 49th day of 2021

2021 has passed 13.2949296042618%

Fuck Life.
 */
