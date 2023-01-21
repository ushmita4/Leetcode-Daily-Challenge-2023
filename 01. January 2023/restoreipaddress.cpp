class Solution {
public:
        vector<string> restoreIpAddresses(string s) {
        vector<string> addresses;
        string ip;
        
        findAll(s, 0, addresses, ip, 1);
        return addresses;
    }
    
    void findAll(string s, int start, vector<string>& addresses, string& ip, int dep){        
        if(dep==5){
            addresses.push_back(ip);
            return;
        }
        
        for(int i=start+1; i<=start+3; i++){
            
            if(s.length()-i > (4-dep)*3)
                continue;            
            
            string add = s.substr(start, i-start);
            if(!checkIsValid(add)){
                continue;
            }
            
            if(ip!="")
                add = "." + add;
            
            ip+=add;                
            findAll(s, i, addresses, ip, dep+1);
            ip = ip.substr(0, ip.length()-add.length());
        }
    }
    
    bool checkIsValid(string add){
        if(add.length()>1)
        if(add.at(0)=='0')
            return false;
        
        return atoi(add.c_str())<=255;
    }
};
