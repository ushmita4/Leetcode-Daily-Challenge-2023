class Solution {
public:
vector<vector<int>> edges;
vector<bool> visit;
long long ans=0;
int count(int dest,int k){
     int c=1;
     visit[dest]=true;
     for(auto it:edges[dest]){
         if(visit[it]==false)
         c+=count(it,k);
     }
     if(dest!=0)
     ans+=((c+k-1)/k);

     return c;
}

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
       edges.resize(n+1);
       visit.resize(n+1);
        for(auto it:roads){
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }
         count(0,seats);
         return ans;
    }
};
