class Solution {
public:
    void dfs(int node, vector<int> g[], vector<int>& vis, int&c) {
        c++;
        vis[node] = 1;
        for(auto & x: g[node]){
            if(!vis[x]) dfs(x,g,vis,c);
        }
        return;
    } 
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for(auto & x:edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<int> arr;
        
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++ ){
            if(!vis[i]){
            int c = 0;
                dfs(i,g,vis,c);
                arr.push_back(c);
                
            }
        }
        sort(arr.rbegin(),arr.rend());
        
       long long sum = 0;
        long long f_ans = 0;
        for (int i = 0 ; i < arr.size() ; i++){
         
            sum += arr[i];
            f_ans +=  arr[i] * (n-sum);
            
        }
        return f_ans;
        
    }
};
