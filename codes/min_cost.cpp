#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<vector<int>> A(N);
        for(int i=0; i<N; i++){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
            for(int j=0; j<N; j++){
                int temp;                                                                                                                                               
                cin >> temp;
                A[i].push_back(temp);
            }
        }

        priority_queue<pair<int, int>> q;
        unordered_set<int> uset;
        int distance[N][N];

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                distance[i][j] = INT_MAX;
            }
        }

        distance[0][0] = A[0][0];
        q.push(pair<int, int>(-1*A[0][0], 0));
        //int count = 4; 
        while(uset.size() != N*N){
            //count--;
            pair<int, int> p = q.top();
            int a = p.second;
            int X = a/N;
            int Y = a%N;
            //cout << X << " " << Y << endl;
            q.pop();
            //cout << "size : " << q.size() <<endl;
            uset.insert(a);

            int Xs[4] = {X+1, X-1, X, X};
            int Ys[4] = {Y, Y, Y-1, Y+1};

            for(int i=0; i<4; i++){
                //cout << "here" <<  X << " " << Y <<endl;
                if(Xs[i]>=0 && Xs[i]<N && Ys[i]>=0 && Ys[i]<N && (uset.find(Xs[i]*N + Ys[i]) == uset.end())){
                    distance[Xs[i]][Ys[i]] = (distance[X][Y] + A[Xs[i]][Ys[i]] < distance[Xs[i]][Ys[i]]) ? distance[X][Y] + A[Xs[i]][Ys[i]] : distance[Xs[i]][Ys[i]];
                    q.push(pair<int, int>(-1*distance[Xs[i]][Ys[i]], (Xs[i]*N)+Ys[i]));
                }
            }
        }

        // for(int i=0; i<N; i++){
        //     for(int j=0; j<N; j++){
        //         cout << distance[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << distance[N-1][N-1] << endl;
    }
    return 0;
}
