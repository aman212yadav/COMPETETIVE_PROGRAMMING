// problem link     - https://leetcode.com/problems/letter-case-permutation
// time complexity  - O(n*2^(number of alphabets))
// space complexity - O(2^(number of alphabets))
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int co=0,n=S.size();
        for(auto k : S)
        {   if(isalpha(k))
            co++;

        }
        vector<string> answer;
        for(long k=0;k<(1<<co);k++){
            int j=0;
            string ans="";
            for(int i=0;i<n;i++){
                if(isalpha(S[i])){
                    if(k&(1<<j))
                    {
                        if(S[i]>='a' && S[i]<='z')
                            ans+=toupper(S[i]);
                        else
                            ans+=tolower(S[i]);
                    }else{
                        ans+=S[i];

                    }
                        j++;
                }else{
                    ans+=S[i];
                }

            }
            answer.push_back(ans);

        }
        return answer;


    }
};
