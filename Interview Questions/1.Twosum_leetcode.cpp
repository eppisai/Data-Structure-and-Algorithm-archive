class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> num;
        map<int,int> ar;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(ar[target - nums[i]]){
            ans.push_back(ar[target - nums[i]]);
            ans.push_back(i);
            return ans;
            }
            num.push_back(make_pair(nums[i],i));
            ar[nums[i]] = i;
        }
        sort(num.begin(),num.end());
        int pt1 = 0,pt2 = nums.size() - 1,sum;
        
        sum = num[pt1].first + num[pt2].first;

        while(pt1 < pt2){
           if(sum == target){
            ans.push_back(num[pt1].second);
            ans.push_back(num[pt2].second);
            return ans;
           }
           if(sum > target){
               sum = sum - num[pt2].first;
               pt2--;
               sum += num[pt2].first;
           } 
           else{
               sum = sum - num[pt1].first;
               pt1++;
               sum += num[pt1].first;
           }
        }
        return ans;
        
    }
};