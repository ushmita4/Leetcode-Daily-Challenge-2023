class Solution {
public:
 void backtracking(int index,string s1,string digits,map<char,string>& mp,vector<string>& ans,int n){
  if(index==n){
      ans.push_back(s1);
      return;
  }
  string s2=mp[digits[index]];
  for(int i=0;i<s2.length();i++){
      s1+=s2[i];
      backtracking(index+1,s1,digits,mp,ans,n);
      s1.pop_back();
  }
 }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string> ans;
        if(digits.size()==0)
        return ans;
        map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        string s1="";
        
        backtracking(0,s1,digits,mp,ans,n);

        return ans;
    }
};
