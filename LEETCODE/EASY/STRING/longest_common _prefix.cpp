// problem link - https://leetcode.com/problems/longest-common-prefix
struct node{
    char c;
    int count;
    node *arr[26];
    node(char cc){
        c=cc;
        count=0;
        for(int i=0;i<26;i++)
            arr[i]=NULL;
    }
};
class Solution {
public:
     // time complexity - O(sum of length of all strings)
    // space complexity - O(sum of length of all strings * 26)
    node* insert(string s,node *root){
        node *temp=root;
        for(int i=0;i<s.size();i++){
            if(temp->arr[s[i]-'a']!=NULL){
                temp=temp->arr[s[i]-'a'];
                temp->count++;
            }else{
                temp->arr[s[i]-'a']=new node(s[i]);
                temp=temp->arr[s[i]-'a'];
                temp->count++;
            }
        }
        return root;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
return "";}
        node *root=new node('*');
        for(auto k : strs){
                 root=insert(k,root);
        }
        string s=strs[0],ss="";
        int i=0;
        while(root && i<s.size() &&root->arr[s[i]-'a']->count==strs.size()){
            root=root->arr[s[i]-'a'];
            ss=ss+root->c;
            i++;
        }
        return ss;
    }
};
