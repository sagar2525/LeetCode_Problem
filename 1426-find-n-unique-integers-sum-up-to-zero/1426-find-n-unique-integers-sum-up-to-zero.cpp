class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr;
        if(n&1){
            arr.push_back(0);
            n--;
        }
        int i =n;
        while(i>0){
            arr.push_back(-i);
            arr.push_back(i);
            i--;
            i--;
        }
        return arr;
    }
};