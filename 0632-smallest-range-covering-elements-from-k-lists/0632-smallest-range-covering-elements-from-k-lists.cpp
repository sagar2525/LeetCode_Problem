class info{
    public:
        int data;
        int rindex;
        int cindex;


        info(int a,int b ,int c){
            data = a;
            rindex = b;
            cindex = c;
        }
};

class compare{
    public:
        bool operator()(info* a,info* b){
            return a->data > b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<info* , vector<info*> , compare> pq;
        vector<int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        // proccess first k elemnt 
        int totalrow = nums.size();
        int totalcolumn = nums[0].size();

        for(int row =0 ; row<totalrow ;row++){
            int element = nums[row][0];
            info* temp = new info(element , row , 0);
            pq.push(temp);
            maxi = max(maxi,element);
            mini = min(mini,element);
        }

        int ans_start = mini;
        int ans_end = maxi;


        // proccessing
        while(!pq.empty()){
            info* front = pq.top();
            pq.pop();

            int frontdata = front->data;
            int front_rindex = front->rindex;
            int front_cindex = front->cindex;

            mini = frontdata;
            // ans update 
            if((maxi-mini)<(ans_end-ans_start)){
                ans_start = mini;
                ans_end = maxi;

            }

            int currtotalcolumns = nums[front_rindex].size();

            if(front_cindex+1<currtotalcolumns){
                int element = nums[front_rindex][front_cindex+1];
                info* temp = new info(element,front_rindex,front_cindex+1);
                maxi = max(maxi,element);
                pq.push(temp);

            }
            else{
                break;
            }
        }
        ans.push_back(ans_start);
        ans.push_back(ans_end);
        return ans;
    }
};