#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    //creating array to check if we were here
    vector<bool> is_atd(n, false);
    //create graph
    vector<vector<int>> graph(n);
    for(int cur = 0; cur < k; cur++){
        int i, j;
        cin >> i >> j;
        graph[i - 1].push_back(j - 1);
        graph[j - 1].push_back(i - 1);
    }
    //creating queue
    queue<int> Q;
    Q.push(0);
    while((int)Q.size() != 0){
        int current = Q.front();
        Q.pop();
        cout << current << " ";
        is_atd[current] = true;
        for(int i : graph[current]){
            if(!is_atd[i]) {
                Q.push(i);
            }
        }
    }
    return 0;
}
