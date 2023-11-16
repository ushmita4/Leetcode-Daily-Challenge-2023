class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
       set<int> s;
       for(string st : nums){
           s.insert(stoi(st, 0, 2));
           cout<<stoi(st, 0, 2)<<"\n";
       }
       for(int i=0;i<nums.size()+1;i++){
           if(s.find(i)==s.end()){
               string res=bitset<16>(i).to_string();
               return res.substr(16-nums.size());
           }
       }
       return "";
    }
};
