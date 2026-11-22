class Solution {
public:
bool bloom(vector<int>&bloomDay,int day ,int m,int k){

    int cnt = 0;
    int b = 0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i] <= day){
            cnt++;
            if(cnt == k){
                b++;
                cnt = 0;
            }
        } else {
            cnt = 0;
        }
    }
    return b >= m;

}

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int ans = INT_MAX;
        if(1LL*m*k>n){
            return -1;
        }
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){
            int mid = (low+high)/2;

            if(bloom(bloomDay,mid,m,k)){
                ans = mid;
                high = mid-1;
                
            }else {
                low = mid+1;
            }
        }
        return ans;
    }
};