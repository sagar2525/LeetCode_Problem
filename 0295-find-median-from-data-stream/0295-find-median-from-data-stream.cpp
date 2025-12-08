class MedianFinder {
public:
    priority_queue<int> maxheap; // left side
    priority_queue<int, vector<int>, greater<int>> minheap; // right side
    double median;

    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {

        // Case 1: both heaps same size
        if(maxheap.size() == minheap.size()){

            if(num > median){
                // insert in right
                minheap.push(num);
                median = minheap.top();
            }
            else{
                // insert in left
                maxheap.push(num);
                median = maxheap.top();
            }
        }

        // Case 2: maxheap bigger (left side has extra element)
        else if(maxheap.size() == minheap.size() + 1){

            if(num > median){
                // insert in right (balanced automatically)
                minheap.push(num);
            }
            else{
                // left already bigger → rebalance before adding
                int element = maxheap.top();
                maxheap.pop();
                minheap.push(element);

                maxheap.push(num);
            }

            // update median (even count)
            median = (maxheap.top() + minheap.top()) / 2.0;
        }

        // Case 3: minheap bigger (right side has extra element)
        else if(minheap.size() == maxheap.size() + 1){

            if(num > median){
                // right already bigger → rebalance before adding
                int element = minheap.top();
                minheap.pop();
                maxheap.push(element);

                minheap.push(num);
            }
            else{
                // insert in left (balanced automatically)
                maxheap.push(num);
            }

            // update median (even count)
            median = (maxheap.top() + minheap.top()) / 2.0;
        }
    }
    
    double findMedian() {
        return median;
    }
};
