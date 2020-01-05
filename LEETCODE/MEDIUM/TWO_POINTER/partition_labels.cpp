// problem link - https://leetcode.com/problems/partition-labels
// time complexity - O(N)
// space complexity - O(N)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int first[26],second[26];
        for(int i=0;i<26;i++){
            first[i]=-1;
            second[i]=-1;
        }
        for(int i=0;i<s.size();i++){
            if(first[s[i]-'a']==-1){
                first[s[i]-'a']=i;
            }
            second[s[i]-'a']=i;
        }
        vector<int> v;
        int idx=0;
        while(idx<s.size()){
            int ma=second[s[idx]-'a'],st=idx;
            if(idx==ma){
                v.push_back(1);
                idx++;
                continue;
            }
            idx++;
            while(idx<=ma){
                ma=max(ma,second[s[idx]-'a']);
                idx++;
            }
            v.push_back(ma-st+1);

        }
        return v;
    }
};
