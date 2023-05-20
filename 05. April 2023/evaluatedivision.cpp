class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &e, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, int> have;
        for (auto i : e)
            have[i[0] + "/" + i[1]] = 1;

        int temp = e.size();
        while (temp--)
        {
            vector<vector<string>> added;
            vector<double> vals;

            for (int i = 0; i < e.size(); i++)
            {
                for (int j = 0; j < e.size(); j++)
                {
                    if (i != j)
                    {
                        if (e[i][1] == e[j][0] and e[i][0] != e[j][1])
                        {
                            added.push_back({e[i][0], e[j][1]});
                            vals.push_back(values[i] * values[j]);
                        }
                        else if (e[i][1] == e[j][1] and e[i][0] != e[j][0])
                        {
                            added.push_back({e[i][0], e[j][0]});
                            vals.push_back(values[i] / values[j]);
                        }
                        else if (e[i][0] == e[j][0] and e[i][1] != e[j][1])
                        {
                            added.push_back({e[i][1], e[j][1]});
                            vals.push_back(values[j] / values[i]);
                        }
                        else if (e[i][0] == e[j][1] and e[i][1] != e[j][0])
                        {
                            added.push_back({e[i][1], e[j][0]});
                            vals.push_back(1.0 / (values[i] * values[j]));
                        }
                    }
                }
            }

            for (int j = 0; j < added.size(); j++)
            {
                if (have.find(added[j][0] + "/" + added[j][1]) == have.end())
                {
                    have[added[j][0] + "/" + added[j][1]] = 1;
                    e.push_back(added[j]);
                    values.push_back(vals[j]);
                }
            }
        }

        unordered_map<string, int> mp;
        unordered_map<string, double> val;

        for (int i = 0; i < e.size(); i++)
        {
            mp[e[i][0]] = 1, mp[e[i][1]] = 1;
            val[e[i][0] + "/" + e[i][1]] = values[i];
        }

        vector<double> ans;
        for (auto i : queries)
        {
            if (mp.find(i[0]) == mp.end() or mp.find(i[1]) == mp.end())
                ans.push_back(-1.000000);
            else
            {
                if (i[0] == i[1])
                    ans.push_back(1.000000);
                else
                {
                    string t = i[0] + "/" + i[1];
                    string tReverse = i[1] + "/" + i[0];
                    if (val.find(t) != val.end())
                        ans.push_back(val[t]);
                    else if (val.find(tReverse) != val.end())
                        ans.push_back(1.0 / val[tReverse]);
                    else
                        ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};
