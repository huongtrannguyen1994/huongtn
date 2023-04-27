class Solution {
public:
   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> v(image.size(), vector<bool>(image[0].size(), false));
        vector<vector<int>> q;

        int firstColor = image[sr][sc];
        image[sr][sc] = color;

        int mX[] = {1, -1, 0, 0};
        int mY[] = {0, 0, -1, 1};

        q.push({sr, sc});
        v[sr][sc] = true;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int xl = x + mX[i];
                int yl = y + mY[i];

                if(xl < 0 || xl >= image.size() || yl < 0 || yl >= image[0].size()) continue;
                if(!v[xl][yl] && image[xl][yl] == firstColor) {
                    v[xl][yl] = true;
                    image[xl][yl] = color;
                    p.push({xl, yl});
                }
            }
        }
        return image;
    }
};