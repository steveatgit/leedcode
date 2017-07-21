Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle.back();
        for(int i=triangle.size()-2; i>=0; i--) {
            for(int j=0; j<=i; j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

// http://www.cnblogs.com/grandyang/p/4286274.html
//这个题目限制了空间复杂度o(n)
// 是动态规划问题，状态转移矩阵为dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + p(i,j)
// 复制最后一行作为dp数组，这样是从下往上一层层扫描，其实原理也是上面的状态转移矩阵
// dp:  [4, 1, 8, 3]
//      [7, 1, 8, 3]
/*      [7, 6, 8, 3]
        [7, 6, 10, 3]
        [9, 6, 10, 3]
        [9, 10, 10, 3]
        [11, 10, 10, 3]
*/
