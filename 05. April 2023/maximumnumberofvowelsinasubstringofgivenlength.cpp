class Solution {
public:
    int maxVowels(string s, int k) {
      unordered_set<char> vowels={'a','e','i','o','u'};
      int mc=0,c=0;
      for(int i=0;i<s.length();i++){
          if(i>=k && vowels.count(s[i-k]))
          c--;
          if(vowels.count(s[i]))
          c++;
          mc=max(mc,c);
      } 
      return mc; 
    }
};
