class Solution {
public:
    void dfs(vector <int> &edges, vector <bool> &vis, vector <int> &path, int ind, int cost)
    {
        if(ind == -1 || vis[ind]) return ;
        vis[ind] = 1;
        path[ind] = cost;
        dfs(edges, vis, path, edges[ind], cost+1);
        return ;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector <int> path1(edges.size(), INT_MAX), path2(edges.size(), INT_MAX);
        vector <bool> vis(edges.size(), 0);
        dfs(edges, vis, path1, node1, 0);
        fill(vis.begin(), vis.end(), 0);
        dfs(edges, vis, path2, node2, 0);
        int ans = -1;
        int cost = INT_MAX;
        for(int i = 0; i < edges.size(); i++)
        {
            if(cost > max(path1[i], path2[i]))
            {
                cost = max(path1[i], path2[i]);
                ans = i;
            }
        }
        return ans;
    }
};
