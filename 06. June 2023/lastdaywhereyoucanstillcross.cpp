class Solution {
public:
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,-1,0,1};
    bool solve(int n,int m,vector<vector<int>>&c,int k){
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<k;i++)vis[c[i][0]-1][c[i][1]-1]=1; 
        for(int j=0;j<m;j++){
            if(vis[0][j]==0){
                vis[0][j]=1;
                q.push({0,j}); 
            }
        }
       
        while(!q.empty()){
            int l=q.size();
            while(l--){
                auto [i,j]=q.front();
                q.pop();
                if(i==n-1)return true; 
                for(int p=0;p<4;p++){
                    int x=i+dx[p];
                    int y=j+dy[p];
                    if(x>=0 && y>=0 && x<n && y<m && !vis[x][y]){
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
        }
        return false;
    }
    int latestDayToCross(int n, int m, vector<vector<int>>&c) {
        int l=0,r=c.size(),ans=0;
        // applying binary search to find the last possible day
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(n,m,c,mid)){
                ans=mid;
                l=mid+1; // continue checking for the maximum possible answer
            }
            else r=mid-1;
        }
        return ans;
    }
};
