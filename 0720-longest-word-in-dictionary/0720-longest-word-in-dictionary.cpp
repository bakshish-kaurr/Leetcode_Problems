class Solution {
public:
    bool build(string str,unordered_map<string,int> &mp)
    {
        if(str.empty())
        return true;
        if(mp.find(str)==mp.end())
        return false;
        for(int i=0;i<str.size();i++)
        {
            string temp=str;
            temp.erase(i,1);
            if(build(temp,mp))
            return true;
        }
        return false;
    }
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        unordered_map<string,int>mp;
        for(auto word: words)
        {
            mp[word]++;
        }
        int maxLen=0;
        string ans="";
        for(auto word: words)
        {
            if(build(word,mp))
            {
                if(word.size()>maxLen)
                {
                    ans=word;
                    maxLen=word.size();
                }
            }
        }
        return ans;
    }
};