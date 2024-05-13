// There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.
// Input
// The first input line has two integers n and m: the number of pupils and friendships. The pupils are numbered 1,2,\dots,n.
// Then, there are m lines describing the friendships. Each line has two integers a and b: pupils a and b are friends.
// Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.
// Output
// Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.
// If there are no solutions, print "IMPOSSIBLE".
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5 3
// 1 2
// 1 3
// 4 5

// Output:
// 1 2 2 1 2
//like graph coloring problem whenever it requires more than 2 teams print Impossible
#include<bits/stdc++.h>
using namespace std;
int possible=true;
void dfs(int node,vector<int> adj[],vector<int> &teams,int team){
    teams[node]=team;
    for(auto it:adj[node]){
        if(teams[it]==-1){  //if he is not on any team add on any team
        dfs(it,adj,teams,!team);
        }
        else if(teams[it]==team){  //if he is already in some team check if he is not on the same team as his friend
            possible=false;
            return;
        }
        
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> teams(n+1,-1); //there are  a total three states for each pupil =>-1->no,0->team1,1->team2
    for(int i=1;i<=n;i++){
        if(teams[i]==-1)
        dfs(i,adj,teams,0);
    }
    if(!possible) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=1;i<teams.size();i++){
        cout<<teams[i]+1<<" ";
    }
}