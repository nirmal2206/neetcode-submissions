class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if(wordSet.find(endWord) == wordSet.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int level = 1;

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;++i){
                string word = q.front();
                q.pop();

                for(int j=0;j<word.size();++j){
                    char original = word[j];

                    for(char ch='a'; ch<='z';++ch){
                        word[j] = ch;

                        if(word == endWord) return level+1;

                        // valid neighbour not yet visited
                        if(wordSet.find(word) != wordSet.end()){
                            q.push(word); 
                            wordSet.erase(word); // remove the word as it is visited
                        }
                    }

                    word[j] = original; // restore
                }
            }

            ++level;
        }

        return 0;
    }
};
