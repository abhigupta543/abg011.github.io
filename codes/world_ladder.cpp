vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //dict.push_back(start);
    //dict.push_back(end);
    
    vector<vector<string>> ans;
    
    set<string> dictSet(dict.begin(), dict.end());
    dictSet.insert(end);
    set<string> visited;
    queue<vector<string>> q;
    vector<string> path;
    path.push_back(start);
    visited.insert(start);
    q.push(path);
    int minSize = INT_MAX;
    while(!q.empty()){
        vector<string> currPath = q.front();
        q.pop();
        int moves = currPath.size();
        visited.insert(currPath[moves-1]);
        if(moves > minSize) continue;
        if(currPath[moves-1] != end){
            string last = currPath[moves-1];
            for(int i=0; i<last.size(); i++){
                string neew = last;
                for(int j=0; j<26; j++){
                    neew[i] = 'a'+j;
                    if(dictSet.find(neew)!=dictSet.end() && visited.find(neew)==visited.end()){
                        vector<string> temp = currPath;
                        temp.push_back(neew);
                        q.push(temp);
                    }
                }
            }
        }
        else{
            ans.push_back(currPath);
            minSize = moves;
        }
    }
    return ans;
}
