class Solution {
public:
    bool isValid(vector<string>& b, int n, int r, int c){
        for (int k = 0; k < n; k++) {
            if (b[k][c] == 'Q') return false;
            if (b[r][k] == 'Q') return false;

            if (k == 0) continue;

            int i1 = r - k, j1 = c - k;
            if (i1 >= 0 && j1 >= 0 && b[i1][j1] == 'Q') return false;

            int i2 = r + k, j2 = c + k;
            if (i2 < n && j2 < n && b[i2][j2] == 'Q') return false;

            int i3 = r + k, j3 = c - k;
            if (i3 < n && j3 >= 0 && b[i3][j3] == 'Q') return false;

            int i4 = r - k, j4 = c + k;
            if (i4 >= 0 && j4 < n && b[i4][j4] == 'Q') return false;
        }
        return true;
    }

    void N_Queens(vector<string>& b, vector<vector<string>>& ans, int n, int r=0){
        if(r==n){
            ans.push_back(b);
            return;
        }
        for(int i=0; i<n; i++){
            if(isValid(b,n,r,i)){
                b[r][i]='Q';
                N_Queens(b,ans,n,r+1);
                b[r][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> b(n, string(n, '.'));
        vector<vector<string>> ans;
        N_Queens(b, ans, n);
        return ans;
    }
};