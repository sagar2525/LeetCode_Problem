class Solution {
public:

bool can(vector<int>& counts,vector<int>& quantity,int ithcustomer){
    // base case 
    if(ithcustomer == quantity.size()){
        return true;
    }

    for(int i =0;i<counts.size();i++){
        if(counts[i]>= quantity[ithcustomer]){
            counts[i] -= quantity[ithcustomer];
            if(can(counts,quantity,ithcustomer+1)){
                return true;
            }
            counts[i] += quantity[ithcustomer];
        }
    }
    return false;
}
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> countmap;
        for(auto num : nums){
            countmap[num]++;
        }
        vector<int> counts;
        for(auto it:countmap){
            counts.push_back(it.second);
        }
        sort(quantity.rbegin(),quantity.rend());
        return can(counts,quantity,0);
    }
};