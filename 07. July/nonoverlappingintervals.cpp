class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
        return 0;
        sort(intervals.begin(),intervals.end());
        int c=0,end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                c++;
                if(intervals[i][1]<end)
                end=intervals[i][1];
            }
            else{
                end=intervals[i][1];
            }
        }
        return c;
    }
};
