class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        if(a.size()>b.size()){
            while(b.size()<a.size()){
                b+="0";
            }
        }
        else if(b.size()>a.size()){
            while(a.size()<b.size()){
                a+="0";
            }
        }
        string ans="";
        int c=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='1' and b[i]=='1' and c==0){
                ans+="0";
                c=1;
            }
            else if(a[i]=='1' and b[i]=='1' and c==1){
                ans+="1";
                c=1;
            }
            else if(((a[i]=='1' and b[i]=='0') or (a[i]=='0' and b[i]=='1')) and c==0){
                ans+="1";
                c=0;
            }
            else if(((a[i]=='1' and b[i]=='0') or (a[i]=='0' and b[i]=='1')) and c==1){
                ans+="0";
                c=1;
            }
            else if(a[i]=='0' and b[i]=='0' and c==0){
                ans+="0";
                c=0;
            }
            else if(a[i]=='0' and a[i]=='0' and c==1){
                ans+="1";
                c=0;
            }
        }
        if(c==1){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
