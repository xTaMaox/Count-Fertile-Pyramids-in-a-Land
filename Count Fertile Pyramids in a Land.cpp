class Solution {
public:
    #define ll long long
    ll dp1[1001][1001],dp2[1001][1001];

    bool issafe(ll x,ll y,ll n,ll m,vector<vector<int>>&grid){
        return x<0 || y<0 || x>=n || y>=m || grid[x][y]==0;
    }

    ll solve1(vector<vector<int>>&grid,ll i,ll j,ll n,ll m){
        if(issafe(i,j,n,m,grid)){
            return 0;
        }
        if(dp1[i][j]!=-1){
            return dp1[i][j];
        }
        ll answer,temp1,temp2,temp3;
        temp1=solve1(grid,i+1,j-1,n,m),temp2=solve1(grid,i+1,j,n,m),temp3=solve1(grid,i+1,j+1,n,m);
        answer=1+min({temp1,temp2,temp3});
        return dp1[i][j]=answer;
    }

    ll solve2(vector<vector<int>>&grid,ll i,ll j,ll n,ll m){
        if(issafe(i,j,n,m,grid)){
            return 0;
        }
        if(dp2[i][j]!=-1){
            return dp2[i][j];
        }
        ll answer,temp1,temp2,temp3;
        temp1=solve2(grid,i-1,j-1,n,m),temp2=solve2(grid,i-1,j,n,m),temp3=solve2(grid,i-1,j+1,n,m);
        answer=1+min({temp1,temp2,temp3});
        return dp2[i][j]=answer;
    }

    int countPyramids(vector<vector<int>>& grid) {
        ll n=grid.size(),m=grid[0].size(),answer=0;
        memset(dp1,-1,sizeof(dp1));memset(dp2,-1,sizeof(dp2));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(grid[i][j]==1){
                    answer+=solve1(grid,i,j,n,m)-1;
                }
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(grid[i][j]==1){
                    answer+=solve2(grid,i,j,n,m)-1;
                }
            }
        }
        return answer;
    }
};