//  https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

class Solution
{
public:
    int minRight(int freq[])
    {
        int f = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
                return i;
        }
        return 26;
    }
    string robotWithString(string s)
    {
        int freq[26] = {};
        for (auto &a : s)
            freq[a - 'a']++;
        stack<char> st;
        string res;
        for (auto &a : s)
        {
            st.push(a);
            freq[a - 'a']--;
            while (!st.empty() && st.top() - 'a' <= minRight(freq))
            {
                res.push_back(st.top());
                st.pop();
            }
        }

        return res;
    }
};