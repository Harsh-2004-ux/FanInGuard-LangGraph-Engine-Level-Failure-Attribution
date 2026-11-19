class Solution {
public:
    int dir1[4] = {-1, 0, 1, 0};
    int dir2[4] = {0, 1, 0, -1};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        // Add all treasure cells to the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // BFS
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int new_i = i + dir1[k];
                int new_j = j + dir2[k];

                if(new_i >= 0 && new_i < n &&
                   new_j >= 0 && new_j < m &&
                   grid[new_i][new_j] == INT_MAX) {

                    grid[new_i][new_j] = grid[i][j] + 1;
                    q.push({new_i, new_j});
                }
            }
        }
    }
};