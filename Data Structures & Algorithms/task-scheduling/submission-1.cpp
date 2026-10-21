class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        priority_queue<int> maxHeap;

        for(char task:tasks){
            freq[task - 'A']++;
        }

        for(int f: freq){
            if(f>0)
            maxHeap.push(f);
        }

        int time=0;

        while(!maxHeap.empty()){
            int slots = n+1;
            vector<int> waiting;

            while(slots > 0 && !maxHeap.empty()){
                int remaining = maxHeap.top() - 1;
                maxHeap.pop();

                if(remaining > 0) waiting.push_back(remaining);

                ++time;
                --slots;
            }

            for(int f: waiting){
                maxHeap.push(f);
            }

            // Count unused slots as idle time if tasks remain.
            if(!maxHeap.empty()) time+=slots;
        }

        return time;
    }
};
