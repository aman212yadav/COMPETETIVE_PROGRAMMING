// problem link - https://leetcode.com/problems/evaluate-division
class Solution {
public:

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double> > dist;
        for(int i=0;i<equations.size();i++){
            auto &k=equations[i];
            dist[k[0]][k[1]]=values[i];
            dist[k[1]][k[0]]=1.0/values[i];
            dist[k[0]][k[0]]=1.0;
            dist[k[1]][k[1]]=1.0;
        }
        for(auto &k : dist){
            for(auto &i : dist[k.first]){

                for(auto &j:dist[k.first]){
                    dist[i.first][j.first]=dist[i.first][k.first]*dist[k.first][j.first];
                }

            }
        }
        vector<double> v;
        for(auto &k:queries){
           if(dist.find(k[0])!=dist.end() && dist[k[0]].find(k[1])!=dist[k[0]].end()){
               v.push_back(dist[k[0]][k[1]]);
           }else{
               v.push_back(-1.0);
           }
        }
        return v;

    }
};
