class Solution {
public:
    string customSortString(string order, string s) {
         map<char,int> m;
           for(int i=0;i<s.size();i++){
               m[s[i]]++;
           }
           string ans;
           for(int j=0;j<order.size();j++){
               if(m.find(order[j])!=m.end()){
                   while(m[order[j]]>0){
                       ans.push_back(order[j]);
                       m[order[j]]--;
                   }
               }
           }
           for(auto i:m){
               while(i.second>0){
                   ans.push_back(i.first);
                   i.second--;
               }
           }
           return ans;

          
    }
};
