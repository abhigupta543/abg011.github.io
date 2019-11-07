#include <bits/stdc++.h>

using namespace std;

void dfs1(int index, stack<int> &s, vector<int> graph[], bool visited[]){
    visited[index] = true;
    for(auto a : graph[index]){
        if(!visited[a]) dfs1(a, s, graph, visited);
    }
    s.push(index);
}

void dfs2(int index, vector<int> graph[], bool visited[]){
    visited[index] = true;
    for(auto a : graph[index]){
        if(!visited[a]) dfs2(a, graph, visited);
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<string> A(N);
        for(int i=0; i<N; i++){
            cin >> A[i];
        }

        //Make graph
        vector<int> graph[26];
        for(int i=0; i<N; i++){
            int len = A[i].size();
            int from = A[i][0] - 97;
            int to = A[i][len-1] - 97;
            graph[from].push_back(to);
        }

    //Kosaraju's Algo. #SCC should be 1
        stack<int> s;
        bool visited[26] = {0};
        
        //filling stack
        for(int i=0; i<26; i++){
            if(graph[i].size() == 0) continue;
            if(!visited[i]) dfs1(i, s, graph, visited);
        }

        //transpose graph
        vector<int> graphPrime[26];
        for(int i=0; i<26; i++){
            for(auto a : graph[i]){
                graphPrime[a].push_back(i);
            }
        }

        //emptying stack
        int count = 0; 
        for(int i=0; i<26; i++) visited[i] = false;

        while(!s.empty()){
            int t = s.top();
            s.pop();
            //cout << t << endl;
            if(!visited[t]){
                dfs2(t, graphPrime, visited);
                count++;
            }  
        } 

        //cout << count << endl;

        if(count == 1){
            int flag = 0;
            for(int i=0; i<26; i++){
                if(graph[i].size() != graphPrime[i].size()){
                    flag++;
                    break;
                }
            }
            cout << 1-flag << endl;
        }
        else cout << "0\n";
    }

    return 0;
}
