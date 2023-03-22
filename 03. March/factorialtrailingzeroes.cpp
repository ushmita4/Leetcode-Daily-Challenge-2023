#define ll long long int
class Solution {
public:
    int trailingZeroes(int n) {
        ll c=5,ans=0;
        while(c<=n){
            ans+=n/c;
            c*=5;
        }
        return ans;
    }
};
