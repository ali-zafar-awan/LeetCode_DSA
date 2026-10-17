class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size(),c = grid[0].size(),l = 0,n = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    l++;

                    if (i + 1 < r && grid[i + 1][j] == 1) {
                        n++;
                    }
                    if (j + 1 < c && grid[i][j + 1] == 1) {
                        n++;
                    }
                }
            }
        }

        return 4 * l - 2 * n;
    }
};