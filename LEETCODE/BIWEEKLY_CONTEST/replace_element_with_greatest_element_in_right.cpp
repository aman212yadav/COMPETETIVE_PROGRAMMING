class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        stack<int> stk;
        int n=arr.size(),ma=-1;
        vector<int> v(n);
        for(int i=n-1;i>=0;i--){

                v[i]=ma;
            ma=max(ma,arr[i]);
        }
        return v;

    }
};
