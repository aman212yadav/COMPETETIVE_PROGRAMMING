class Solution {
public:
    bool static cmp(vector<int> &a,vector<int> &b){
        if(a[1]==b[1])
            return a[0]>b[0];
        return a[1]>b[1];
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int> > ans;
        for(auto k : restaurants){
            if((k[2]==0 && veganFriendly) || k[3]>maxPrice || k[4]>maxDistance)
                continue;
            ans.push_back(k);
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int> ans1;
        for(auto k : ans)
            ans1.push_back(k[0]);
        return ans1;
    }
};
