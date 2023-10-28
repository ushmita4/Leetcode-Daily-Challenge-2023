class Solution {
public:
    int countVowelPermutation(int n) {
        long long prevA = 1, prevE = 1, prevI = 1, prevO = 1, prevU = 1;
        int mod = 1e9 + 7; 

        for (int length = 2; length <= n; length++) {
           
            long long nextA = (prevE + prevU + prevI) % mod; 
            long long nextE = (prevA + prevI) % mod;
            long long nextI = (prevE + prevO) % mod; 
            long long nextO = prevI; 
            long long nextU = (prevO + prevI) % mod; 
            prevA = nextA;
            prevE = nextE;
            prevI = nextI;
            prevO = nextO;
            prevU = nextU;
        }

        // Return the sum of all vowel counts modulo the defined value
        return (prevA + prevE + prevI + prevO + prevU) % mod;
    }
};
