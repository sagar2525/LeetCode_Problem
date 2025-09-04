class Solution {
public:

vector<int> nextsmaller(vector<int> &input){

    stack<int> s;
    s.push(-1);


    vector<int>ans(input.size());
    for(int i=input.size()-1;i>=0;i--){
        int curr = input[i];

        while(s.top() !=-1 && input[s.top()]>=curr){
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);

    }
    return ans;

}

vector<int> prevsmaller(vector<int> &input){

    stack<int> s;
    s.push(-1);


    vector<int>ans(input.size());
    for(int i=0;i<input.size();i++){
        int curr = input[i];

        while(s.top() !=-1 && input[s.top()]>=curr){
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);

    }
    return ans;

}
    int largestRectangleArea(vector<int>& heights) {
        // step 1 prevsmaller output
    vector<int> prev = prevsmaller(heights);
    // step 2 next smaller 
    vector<int> next = nextsmaller(heights);


    int maxarea = INT_MIN;
    int size = heights.size();

    for(int i=0;i<heights.size();i++){
        int length = heights[i];

        if(next[i]==-1){
            next[i] = size;
        }
        int width = next[i]-prev[i]-1;

        int area = length * width;
        maxarea = max(maxarea,area);
    }
    return maxarea;
    }
};