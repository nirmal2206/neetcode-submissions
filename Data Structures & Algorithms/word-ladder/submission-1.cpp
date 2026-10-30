class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if(!wordSet.count(endWord)) return 0;

        unordered_set<string> front = {beginWord};
        unordered_set<string> back = {endWord};

        wordSet.erase(beginWord);
        wordSet.erase(endWord);

        int level = 1;

        while(!front.empty() && !back.empty()){
            // Always expand the smaller frontier.
            if(front.size() > back.size()){
                front.swap(back);
            }

            unordered_set<string> next;

            for(string word: front){
                for(int i=0;i<word.size();++i){
                    char original = word[i];

                    for(char ch='a'; ch<='z'; ++ch){
                        if(ch == original) continue;

                        word[i] = ch;
                        
                        // if word exists in back queue then we connect 
                        if(back.count(word)) return level+1;

                        if(wordSet.find(word) != wordSet.end()){
                            next.insert(word);
                            wordSet.erase(word);
                        }
                    }
                    word[i] = original; // replace original char
                }
            }
            front = std::move(next);
            level++;
        }
        return 0;
    }
};
