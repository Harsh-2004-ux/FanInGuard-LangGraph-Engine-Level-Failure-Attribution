class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> st;
        for(auto &it:wordList){
            st.insert(it);
        }
        queue<pair<string,int>> q;
        int n=st.size();
        vector<char> letter(26);
        for(int i=0;i<26;i++){
            letter[i]= char('a'+ i);
        }
        q.push({beginWord,1});

        while(!q.empty()){
            auto it=q.front();
            string word=it.first;
            int cnt=it.second;
            q.pop();
            if(word==endWord) return cnt;
            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(int j=0;j<26;j++){
                    word[i]=letter[j];
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,cnt+1});
                    }
                }
                word[i]=ch;
            }
        }

        return 0;
    }
};
