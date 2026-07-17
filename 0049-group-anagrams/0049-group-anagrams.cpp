class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        map<string,int>mp;
        vector<string>temp;
        int idx=0;
        for(auto s:strs){
            string tem=s;
            sort(s.begin(),s.end());
            if(mp.find(s)!=mp.end()){
                int tidx=mp[s];
                result[tidx].push_back(tem);
            }
            else{
                temp.push_back(tem);
                mp[s]=idx;
                idx++;
                result.push_back(temp);
                temp.pop_back();
            }
        }
        return result;
    }
};