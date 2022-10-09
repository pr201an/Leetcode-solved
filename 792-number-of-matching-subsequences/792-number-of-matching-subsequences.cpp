class Solution {
public:
    bool LCS(string  s1,string s2){
        int n=s1.size(),m=s2.size();
        int j=0;
        for(int i=0;i<n and j<m;i++)
            if(s1[i]==s2[j])j++;
        return j==m;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> hm;
        int count=0;
        for(auto s2: words)
            hm[s2]++;
        
        for(auto it: hm) 
            if(LCS(s,it.first))
                count=count+it.second;
        return count;
    }
};