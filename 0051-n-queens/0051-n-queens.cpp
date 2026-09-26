class Solution {
public:
    bool isValid(vector<string>& b, int n, int r, int c){
        for(int i = 0; i < n; i++){
            if(b[i][c]=='Q' && i!=r) return false;
        }
        for(int i = 0; i < n; i++){
            if(b[r][i]=='Q' && i!=c) return false;
        }
        for(int i = r-1, j = c-1; i>=0 && j>=0; i--, j--){
            if(b[i][j]=='Q') return false;
        }
        for(int i = r+1, j = c+1; i<n && j<n; i++, j++){
            if(b[i][j]=='Q') return false;
        }
        for(int i = r+1, j = c-1; i<n && j>=0; i++, j--){
            if(b[i][j]=='Q') return false;
        }
        for(int i = r-1, j = c+1; i>=0 && j<n; i--, j++){
            if(b[i][j]=='Q') return false;
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