// You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
// Input
// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
// Output
// Print one integer: the number of rooms.
// Constraints

// 1 \le n,m \le 1000

// Example
// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Output:
// 3
#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,vector<vector<int>> &vis,vector<string> &grid){
    vis[row][col]=1;
    int n=vis.size();
    int m=vis[0].size();
    vector<int> dirr{1,0,-1,0};
    vector<int> dirc{0,1,0,-1};
    for(int i=0;i<4;i++){
        int nr=row+dirr[i];
        int nc=col+dirc[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='.' && !vis[nr][nc]){
            dfs(nr,nc,vis,grid);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> grid(n,"");
    for(auto &i:grid) cin>>i;
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && !vis[i][j]){
            cnt++;
            dfs(i,j,vis,grid);
            }
        }
    }
    cout<<cnt<<endl;
}