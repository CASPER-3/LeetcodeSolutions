#include <string>
#include <vector>
#include <algorithm>
using std::max;
using std::string;
using std::vector;

// Reference1.

int longestSubstring(string s, int k)
{
    if (k <= 1)
        return s.size();
    if (s.empty() || s.size() < k)
        return 0;

    vector<int> hash(128, 0);
    for (char c : s)
        ++hash[c];

    int i = 0;
    while (i < s.size() && hash[s[i]] >= k)
        ++i;
    if (i == s.size())
        return s.size();

    int l = longestSubstring(s.substr(0, i), k);
    while (i < s.size() && hash[s[i]] < k)
        ++i;
    int r = longestSubstring(s.substr(i), k);

    return max(l, r);
}



// Reference2.

int longestSubstring(string s, int k)
{
    int ret = 0;
    int n = s.length();
    for (int t = 1; t <= 26; t++)
    {
        int l = 0, r = 0;
        vector<int> cnt(26, 0);
        int tot = 0;
        int less = 0;
        while (r < n)
        {
            cnt[s[r] - 'a']++;
            if (cnt[s[r] - 'a'] == 1)
            {
                tot++;
                less++;
            }
            if (cnt[s[r] - 'a'] == k)
            {
                less--;
            }

            while (tot > t)
            {
                cnt[s[l] - 'a']--;
                if (cnt[s[l] - 'a'] == k - 1)
                {
                    less++;
                }
                if (cnt[s[l] - 'a'] == 0)
                {
                    tot--;
                    less--;
                }
                l++;
            }
            if (less == 0)
            {
                ret = max(ret, r - l + 1);
            }
            r++;
        }
    }
    return ret;
}

/* 

对于字符串 ss，如果存在某个字符 \textit{ch}ch，它的出现次数大于 00 且小于 kk，则任何包含 \textit{ch}ch 的子串都不可能满足要求。也就是说，我们将字符串按照 \textit{ch}ch 切分成若干段，则满足要求的最长子串一定出现在某个被切分的段内，而不能跨越一个或多个段。因此，可以考虑分治的方式求解本题。

C++JavaJavaScriptGolangC

class Solution {
public:
    int dfs(const string& s, int l, int r, int k) {
        vector<int> cnt(26, 0);
        for (int i = l; i <= r; i++) {
            cnt[s[i] - 'a']++;
        }

        char split = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = i + 'a';
                break;
            }
        }
        if (split == 0) {
            return r - l + 1;
        }

        int i = l;
        int ret = 0;
        while (i <= r) {
            while (i <= r && s[i] == split) {
                i++;
            }
            if (i > r) {
                break;
            }
            int start = i;
            while (i <= r && s[i] != split) {
                i++;
            }

            int length = dfs(s, start, i - 1, k);
            ret = max(ret, length);
        }
        return ret;
    }

    int longestSubstring(string s, int k) {
        int n = s.length();
        return dfs(s, 0, n - 1, k);
    }
};
复杂度分析

时间复杂度：O(N\cdot \Sigma)O(N⋅Σ)，其中 NN 为字符串的长度，\SigmaΣ 为字符集的大小，本题中等于 2626。由于每次递归调用都会完全去除某个字符，因此递归深度最多为 \SigmaΣ。

空间复杂度：O(\Sigma^2)O(Σ 
2
 )。递归的深度为 O(\Sigma)O(Σ)，每层递归需要开辟 O(\Sigma)O(Σ) 的额外空间。

方法二：滑动窗口
我们枚举最长子串中的字符种类数目，它最小为 11，最大为 \SigmaΣ（字符集的大小，本题中为 2626）。

对于给定的字符数量 tt，我们维护滑动窗口的左右边界 l,rl,r、滑动窗口内部每个字符出现的次数 \textit{cnt}cnt，以及滑动窗口内的字符种类数目 \textit{total}total。当 \textit{total} > ttotal>t 时，我们不断地右移左边界，并对应地更新 \textit{cnt}cnt 以及 \textit{total}total，直到 \textit{total} \le ttotal≤t 为止。这样，对于任何一个右边界 rr，我们都能找到最大的 l_{max}l 
max
​	
 ，使得 s[l_{max}...r]s[l 
max
​	
 ...r] 之间的字符种类数目不多于 tt。

对于任何一组 l_{max}, rl 
max
​	
 ,r 而言，如果 s[l_{max}...r]s[l 
max
​	
 ...r] 之间存在出现次数小于 kk 的字符，我们可以断定：对于任何 l' \in (l_{max}, r)l 
′
 ∈(l 
max
​	
 ,r) 而言，s[l'...r]s[l 
′
 ...r] 依然不可能是满足题意的子串，因为：

要么某个字符的出现次数降为 00，此时子串内虽然少了一个出现次数小于 kk 的字符，但字符的总数也不等于 cc 了；
要么某个字符的出现次数降为非 00 整数，此时子串内该字符的出现次数依然小于 kk。
根据上面的结论，我们发现：当限定字符种类为 kk 时，满足题意的最长子串，就一定出自某个 s[l_{max}...r]s[l 
max
​	
 ...r]。因此，在滑动窗口的维护过程中，就可以直接得到最长子串的大小。

此外还剩下一个细节：如何判断某个子串内的字符是否都出现了至少 kk 次？我们当然可以每次遍历 \textit{cnt}cnt 数组，但是这会带来 O(\Sigma)O(Σ) 的额外开销。

我们可以维护一个计数器 \textit{less}less，代表当前出现次数小于 kk （且不为 00）的字符的数量。每次移动滑动窗口的边界，只会让某个字符的出现次数加一或者减一。对于移动右边界的情况而言：

当某个字符的出现次数从 00 增加到 11 时，将 \textit{less}less 加一；

当某个字符的出现次数从 k-1k−1 增加到 kk 时，将 \textit{less}less 减一。

对于移动左边界的情形，讨论是类似的。

通过维护额外的计数器 \textit{less}less，我们无需遍历 \textit{cnt}cnt 数组，就能知道每个字符是否都出现了至少 kk 次。读者可以自行思考 k=1k=1 时的处理逻辑。

C++JavaJavaScriptGolangC

class Solution {
public:
    int longestSubstring(string s, int k) {
        int ret = 0;
        int n = s.length();
        for (int t = 1; t <= 26; t++) {
            int l = 0, r = 0;
            vector<int> cnt(26, 0);
            int tot = 0;
            int less = 0;
            while (r < n) {
                cnt[s[r] - 'a']++;
                if (cnt[s[r] - 'a'] == 1) {
                    tot++;
                    less++;
                }
                if (cnt[s[r] - 'a'] == k) {
                    less--;
                }

                while (tot > t) {
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l] - 'a'] == k - 1) {
                        less++;
                    }
                    if (cnt[s[l] - 'a'] == 0) {
                        tot--;
                        less--;
                    }
                    l++;
                }
                if (less == 0) {
                    ret = max(ret, r - l + 1);
                }
                r++;
            }
        }
        return ret;
    }
};
复杂度分析

时间复杂度：O(N \cdot \Sigma)O(N⋅Σ)，其中 NN 为字符串的长度，\SigmaΣ 为字符集的大小，本题中等于 2626。我们需要遍历所有可能的 tt，共 \SigmaΣ 种可能性；内层循环中滑动窗口的复杂度为 O(N)O(N)。

空间复杂度：O(\Sigma)O(Σ)。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/zhi-shao-you-kge-zhong-fu-zi-fu-de-zui-c-o6ww/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */