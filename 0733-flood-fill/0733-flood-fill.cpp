
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color){
            return image;
        }
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int r, int c, int old, int color) {
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size()){
            return;
        }
        if (image[r][c] != old){
            return;
        }
        image[r][c] = color;

        dfs(image, r + 1, c, old, color);
        dfs(image, r - 1, c, old, color);
        dfs(image, r, c + 1, old, color);
        dfs(image, r, c - 1, old, color);
    }
};
