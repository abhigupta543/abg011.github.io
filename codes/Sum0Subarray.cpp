#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i=0; i<N; i++) cin >> A[i];
        unordered_map<int, int> umap;
        int sum=0, count=0;
        for(int i=0; i<N; i++){
            sum+=A[i];
            if(sum == 0) count++;
            if(umap.find(sum) == umap.end()){
                umap.insert(pair<int, int>(sum, 1));
            }
            else{
                count+=umap.find(sum)->second;
                umap.find(sum)->second++;
            }
        }
        cout << count << endl;
    }
    return 0;
}