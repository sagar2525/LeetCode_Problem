class MedianFinder {
public:

    priority_queue<int> maxheap;
    priority_queue<int, vector<int> , greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.size() == minheap.size()){
            if(num > findMedian()){
                minheap.push(num);
            }
            else{
                maxheap.push(num);
            }
        }
        else if(maxheap.size()+1 == minheap.size()){
            // min heap bada hai 
            if(num>findMedian()){
                
                int element = minheap.top();
                minheap.pop();
                maxheap.push(element);
                minheap.push(num);
            }
            else{
                maxheap.push(num);
            }
        }
        else if(maxheap.size() == minheap.size()+1){
            // max heap ka size bada hai 
            if(num > findMedian()){
                minheap.push(num);
            }
            else{
                int element = maxheap.top();
                maxheap.pop();
                minheap.push(element);
                maxheap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxheap.size() == 0 && minheap.size() ==0){
            return 0;
        }
        else if(maxheap.size() == minheap.size() ){
            return (minheap.top()+maxheap.top())/2.0;
        }
        else if(maxheap.size()+1 == minheap.size()){
            return minheap.top();
        }
        else if(maxheap.size() == minheap.size()+1){
            return maxheap.top();
        }
        else{
            return -1;
        }

    }
};

