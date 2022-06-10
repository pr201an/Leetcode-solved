class Solution {
    bool checkequal(vector<int> s1freq, vector<int> s2freq){
        for(int i=0;i<26;i++){
            if(s1freq[i] != s2freq[i])
                return false;
        }
        return true;
    }
        
public:    
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())
            return false;
        vector<int> s1freq(26);
        vector<int> s2freq(26);
        for(int i=0; i<s1.size(); i++){
            s1freq[s1[i]-97]++;
        }
        int i=0, j=0;
        while(j<s2.size()){
            if(j-i < s1.size()){
                s2freq[s2[j]-97]++;
                bool isequa = checkequal(s1freq, s2freq);
                if(isequa)
                    return true;
                j++;
                continue;
            }
            s2freq[s2[j]-97]++;
            s2freq[s2[i]-97]--;
            //check if frequency equal in both vectors
            bool isequal = checkequal(s1freq, s2freq);
            if(!isequal){
                i++;
                j++;
            }
            else if(isequal)
                return true;
        }
        return false;
    }
};
