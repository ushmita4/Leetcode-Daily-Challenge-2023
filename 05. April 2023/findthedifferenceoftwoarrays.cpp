class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    set<int>s1, s2;
    for (auto x : nums1)
    {
      s1.insert(x);
    }
    for (auto x : nums2)
    {
      s2.insert(x);
    }
    vector<vector<int>>ans;
    set<int>v1, v2;
    for (auto x : nums1)
    {
      auto it1 = s2.find(x);
      if (it1 == s2.end())
      {
        v1.insert(x);
      }
    }
    for (auto x : nums2)
    {
      auto it1 = s1.find(x);
      if (it1 == s1.end())
      {
        v2.insert(x);
      }
    }
    vector<int>v11, v12;
    for (auto x : v1)
    {
      v11.push_back(x);
    }
    for (auto x : v2)
    {
      v12.push_back(x);
    }
    ans.push_back(v11);
    ans.push_back(v12);

    return ans;
  }
};
