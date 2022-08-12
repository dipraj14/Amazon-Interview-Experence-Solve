// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string lcs(int m, int n, string s1, string s2) {


        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        int ans = 0, index = 0;
        string result;
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }
        for (int j = 0; j <= m; j++) {
            dp[j][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (ans < dp[i][j]) {
                        string temp = s1.substr(i - dp[i][j], dp[i][j]);
                        string temp2 = temp;
                        reverse(temp2.begin(), temp2.end());
                        if (temp == temp2) {
                            ans = dp[i][j];
                            result = temp;
                        }
                    }
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return result;

    }
    string longestPalindrome(string s) {
        string ans;
        string org = s;

        reverse(s.begin(), s.end());

        int m = org.length();
        int n = m;

        ans = lcs(m, n, org, s);

        return ans;
    }
};