class Solution {
public:


    bool possible(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){

        multiset<int>st(workers.begin(), workers.begin() + mid);
        int used = 0;

        for(int i = mid-1; i >= 0; i--){

            auto it = prev(st.end());

            if(*it >= tasks[i]){
                st.erase(it);
            }else if(used >= pills){
                return false;
            }else{
                auto ls = st.lower_bound(tasks[i] - strength);
                if(ls == st.end()){
                    return false;
                }
                st.erase(ls);
                used++;
            }

        }

        return true;

    }


    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        
        int n = tasks.size();
        int m = workers.size();

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());

        int l = 0;
        int r = min(n, m);

        int ans = 0;

        while(l <= r){

            int mid = (l + r) / 2;

            if(possible(tasks, workers, pills, strength, mid)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }

        }

        return ans;

    }
};