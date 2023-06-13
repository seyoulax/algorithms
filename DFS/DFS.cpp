#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> gh(n);
vector<bool> is_atd(n, false);

void dfs(int cur){
    cout << cur << "\n";
    is_atd[cur] = true;
    for(int i : gh[cur]){
        if(!is_atd[i]){
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> n >> k;
    gh.resize(n);
    is_atd.resize(n);
    for(int i = 0; i < k; i++){
        int v1, v2;
        cin >> v1 >> v2;
        gh[v1 - 1].push_back(v2 - 1);
        gh[v2 - 1].push_back(v1 - 1);
    }
    dfs(0);
    return 0;
}