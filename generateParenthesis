class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generateParenthesisCore(n, n, "", ret);
        return ret;
    }
    void generateParenthesisCore(int left, int right, string str, vector<string> &vec)
    {
        if(left == 0 && right == 0) {
            vec.push_back(str);
            return;
        }
        if(left > 0) {
            generateParenthesisCore(left-1, right, str+'(', vec);
        }
        if(right>0 && left< right) {
            generateParenthesisCore(left, right-1, str+')', vec);
        }
    }
};
