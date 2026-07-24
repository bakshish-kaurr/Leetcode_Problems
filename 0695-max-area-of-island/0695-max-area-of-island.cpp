class Solution {
public:
    int ans = 0;

    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};

    void dfs(vector<vector<bool>>& vis, int m, int n,
             vector<vector<int>>& grid, int r, int c, int& a) {

        vis[r][c] = true;
        a++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 &&
                nr < m && nc < n &&
                grid[nr][nc] == 1 &&
                !vis[nr][nc]) {

                dfs(vis, m, n, grid, nr, nc, a);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int a = 0;
                    dfs(vis, m, n, grid, i, j, a);
                    ans = max(ans, a);
                }
            }
        }

        return ans;
    }
};