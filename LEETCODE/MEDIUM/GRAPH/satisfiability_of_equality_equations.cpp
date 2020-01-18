// problem link - https://leetcode.com/problems/satisfiability-of-equality-equations
// time complexity - O(n^2) can be optimised to O(nlogn) by optimising union find
class Solution {
public:
    int find(int x,int f[]){
        if(x!=f[x])
        {
            f[x]=find(f[x],f);
        }
        return f[x];
    }
    bool equationsPossible(vector<string>& equations) {
          int f[26];
        for(int i=0;i<26;i++)
        {f[i]=i;

        }

        for(auto k : equations){
                 if(k[1]=='=')
                     f[find(k[0]-'a',f)]=find(k[3]-'a',f);
                }
        for(auto k:equations){
            if(k[1]=='!' && find(k[0]-'a',f)==find(k[3]-'a',f))
                return false;

        }
        return true;


    }
};
