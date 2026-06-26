#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // create a frequency map to find the most frequent tasks
        unordered_map<char, int> umap;
        for (char task : tasks) {
            umap[task]++;
        }

        // use a max heap to keep the most frequent tasks at the top
        priority_queue<int> maxheap;
        for (auto& [task, freq] : umap) {
            maxheap.push(freq);
        }

        // create a queue (that would take in pairs) to store a combination
        // of frequency and cooldown time so that we know when next to carry
        // out a certain task
        queue<pair<int, int>> cooldown;

        int time = 0;

        // set a while loop that keeps going as long as maxheap and cooldown
        // are not empty
        while (!maxheap.empty() || !cooldown.empty()) {
            // set a time that variable that increases by 1 each turn of the loop 
            time++;

            // if the maxheap is not empty, we can retrieve the top count (i.e the
            // frequency value of the highest frequency task) and then reduce this
            // frequency count by 1 (to signify carrying out one task).
            if (!maxheap.empty()) {
                int cnt = maxheap.top(); 
                maxheap.pop();

                cnt--;

                // if this current reduced freq value is greater than 0, then we push
                // this current frequency count alongside its cooldown time (which
                // would be calculated as 'time + n') into the cooldown pair. 
                // NB: If the count is 0, then theres no need as that task has been
                // exhausted.
                if (cnt > 0) {
                    cooldown.push({cnt, time + n});
                }
            }

            // we check the cooldown time of the element at the front of the cooldown
            // queue (which would be the element the would be next in line for the
            // next task). If the 'cooldown time' is equal to the current value of our 
            // time variable, then that task is ready to be carried out so we push the 
            // 'freq count' back to the maxheap and pop that pair from te queue
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxheap.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        // After the loops are done, we must have gotten the total no. of least run time
        // it takes the CPU to complete all the tasks and we return it (i.e the time variable)
        return time;
    }
};