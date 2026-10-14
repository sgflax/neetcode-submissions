class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> nei;

        wordList.push_back(beginWord);
        for(string word : wordList){
            for(int j = 0; j < word.size(); j++){
                string pattern = word;
                pattern[j] = '*';
                nei[pattern].push_back(word);
            }
        }

        unordered_set<string> visit{beginWord};
        queue<string> q;
        q.push(beginWord);
        int res = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string front = q.front();
                q.pop();
                if(front == endWord) return res;
                for(int j = 0; j < front.size(); j++){
                    string pattern = front;
                    pattern[j] = '*';
                    for(const string newWord : nei[pattern]){
                        if(!visit.contains(newWord)){
                            visit.insert(newWord);
                            q.push(newWord);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
