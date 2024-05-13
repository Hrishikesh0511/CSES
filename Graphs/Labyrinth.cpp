// You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
// Input
// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.
// Output
// First print "YES", if there is a path, and "NO" otherwise.
// If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.
// Constraints

// 1 \le n,m \le 1000

// Example
// Input:
// 5 8
// ########
// #.A#...#
// #.##.#B#
// #......#
// ########

// Output:
// YES
// 9
// LDDRRRRRU
// The approach fails for larger strings we need to copy everytime which takes O(n) time
// so Used a backtracking approach by storing the parents(co-ordinates) in another grid
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> dis;
pair<int, int> res = {-1, -1};
void bfs(int row, int col, vector<vector<int>> &vis, vector<string> &grid)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = vis.size();
    int m = vis[0].size();
    dis.resize(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<int> dirr{1, 0, -1, 0};
    vector<int> dirc{0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        vis[r][c] = 1;
        if (grid[r][c] == 'B')
        {
            cout << "YES" << endl;
            res = {r, c};
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dirr[i];
            int nc = c + dirc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && !vis[nr][nc])
            {
                if (dis[nr][nc].first == -1) // we will take only the first occurence because first one will only b the shortest path
                {
                    dis[nr][nc] = {r, c};
                    q.push({nr, nc});
                }
            }
        }
    }
    cout << "NO" << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n, "");
    for (auto &i : grid)
        cin >> i;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A' && !vis[i][j])
            {
                bfs(i, j, vis, grid);
            }
        }
    }
    int r = res.first;
    int c = res.second;
    if (r == -1 && c == -1)
        return 0;
    string s = "";
    while (grid[r][c] != 'A')
    {
        int nr, nc;
        nr = dis[r][c].first;
        nc = dis[r][c].second;
        if (nr > r)
            s.push_back('U');
        else if (nr < r)
            s.push_back('D');
        else if (nc > c)
            s.push_back('L');
        else
            s.push_back('R');
        r = nr, c = nc;
    }
    reverse(s.begin(), s.end());
    cout << s.size() << endl;
    cout << s << endl;
}