// problem link - https://leetcode.com/contest/weekly-contest-172/problems/minimum-number-of-taps-to-open-to-water-a-garden/
// space complexity - O(N)
// time complexity - O(n*n)

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=1;
        for(int k=0;k<=min(n,ranges[0]);k++){
            dp[k]=1;
        }
        for(int i=1;i<=n;i++){
            int mi=INT_MAX;
            if(i-ranges[i]<=0)
            {  dp[i]=1;
              for(int j=max(0,i-ranges[i]);j<=min(n,i+ranges[i]);j++)
                 dp[j]=1;
            }else{
              for(int j=max(0,i-ranges[i]);j<=min(n,i+ranges[i]);j++)
                 mi=min(mi,dp[j]);
                if(mi==INT_MAX)
                    continue;
                for(int j=max(0,i-ranges[i]);j<=min(n,i+ranges[i]);j++)
                    dp[j]=min(1+mi,dp[j]);

            }
        }


        int ma=INT_MIN;

        for(int i=0;i<=n;i++)
        { if(dp[i]==INT_MAX)
                return -1;
         ma=max(ma,dp[i]);
        }
        return ma;
    }
};
