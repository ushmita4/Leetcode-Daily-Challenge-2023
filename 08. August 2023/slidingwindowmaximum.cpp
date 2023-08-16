class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
     
        vector<int>maxx;
        int n = nums.size();

        int i = 0 , j = 0;
        priority_queue<pair<int,int>>pq;
        vector<int>vis(n,0);

        while(j < n){
            pq.push({nums[j],j});

            if(j - i + 1 < k) j++;    
            else if(j - i + 1 == k){  
                maxx.push_back(pq.top().first);
                
              
                if(pq.top().first == nums[i] && pq.top().second == i) pq.pop();

               
                while(vis[pq.top().second]) pq.pop();
                
            
                vis[i] = 1;

                
                i++; j++;
            }
        }

   
        return maxx;
    }
}; 
