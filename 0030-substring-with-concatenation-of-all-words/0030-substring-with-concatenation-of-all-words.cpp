class Solution {
public:

    // tracking individual word kaa count
    unordered_map<string,int>map;

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        
        for(int i =0;i<words.size();i++){
            map[words[i]]++;
        }

        int wordlength = words[0].length();

        // offset logic-> start -> 0,1,2 <wrdlength

        for(int offset = 0; offset < wordlength; offset++){
            unordered_map<string,int> visited;
            // ans mila kya check kern k liye we , need track count
            int count =0;

            // ab main wordlenght k substring uthauga and check keruga 
            for(int i = offset; i+wordlength <= s.length();i = i+wordlength){
                string substr = s.substr(i,wordlength);
                // check wheather substr is valid or not

                if(map.find(substr) == map.end()){
                    // invalid string 
                    // purane sare answer ko bhulna chaiye 
                    visited.clear();
                    count = 0;
                    continue;
                }
                else{
                    // valid string 
                    visited[substr]++;
                    count++;

                    // game changer
                    while(visited[substr] > map[substr]){
                        // hr word removal per visited and count dono me se 
                        // wo word hatega
                        string temp = s.substr(i-(count-1)*wordlength , wordlength);
                        visited[temp]--;
                        count--;
                    }

                    // ans mila kya 
                    if(count == words.size()){
                        ans.push_back(i-(count-1)*wordlength);
                        
                    }
                }
            }
        }
        return ans;

    }
};