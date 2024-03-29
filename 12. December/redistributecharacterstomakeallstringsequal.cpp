class Solution {
public:
    bool makeEqual(vector<string>& words) {
       vector<int> counts(26,0);
       for(string word:words){
       for(char c:word){
         counts[c-'a']++;
       }
       }
       int n=words.size();
       for(int i:counts){
           if(i%n!=0)
           return false;
       }
       return true;
    }
};
