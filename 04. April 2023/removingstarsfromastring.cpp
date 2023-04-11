class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        char ch,x;
        string result="";
        for(int i=0;i<s.size();i++){
            ch=s[i];
            if(ch=='*'){
                if(st.empty())
                    continue;
                else
                    st.pop();
            }
            else
                st.push(ch);
        }
        while(!st.empty())
        {
            x=st.top();
            st.pop();
            result+=x;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
