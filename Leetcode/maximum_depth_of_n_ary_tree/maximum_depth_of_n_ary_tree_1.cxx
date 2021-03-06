/* 

给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。

 

示例 1：



输入：root = [1,null,3,2,4,null,5,6]
输出：3
示例 2：



输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：5
 

提示：

树的深度不会超过 1000 。
树的节点数目位于 [0, 104] 之间。
通过次数43,451提交次数60,857

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <algorithm>
using std::max;
using std::vector;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class maximum_depth_of_n_ary_tree
{
public:
    int maxDepth(Node *root)
    {
        auto maxchild = [=]() -> int { int dep=0;for(auto tr:root->children){dep=max(dep,maxDepth(tr));}return dep; };
        return root ? maxchild() + 1 : 0;
    }
};

// 更简洁的写法.
// Tue,March2,2021
// 08:55:38:962:637502721389626823