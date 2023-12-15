class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> graph;
        for (int i = 0; i < paths.size(); i++) {
            graph.insert(paths[i][0]);
        }
        
        for (int i = 0; i < paths.size(); i++) {
            string candidate = paths[i][1];
            if (graph.find(candidate) == graph.end()) {
                return candidate;
            }
        }
        
        return "";
    }
};
