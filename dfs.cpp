#include <bits/stdc++.h>

std::vector<std::vector<int>> M;
std::vector<bool> visited;
std::vector<std::vector<int>> components;

void dfs(int cur){
    components[components.size() - 1].push_back(cur);
    visited[cur] = true;
    for(int v : M[cur]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    int n, m, count = 0;
    std::cin >> n >> m;
    M.assign(n, std::vector<int>());
    visited.assign(n, false);
    for(int i = 0; i < m; i++){
        int u, v;
        std::cin >> u >> v;
        M[u - 1].push_back(v - 1);
        M[v - 1].push_back(u - 1);
    }

    for(int v = 0; v < n; v++){
        if(!visited[v]){
            components.push_back(std::vector<int>());
            dfs(v);
            for(int i : visited) std::cout << i << " ";
            count++;
            std::cout << "\n";
        }
    }
    std::cout << count << "\n";
    for(std::vector<int> comp : components){
        std::cout << comp.size() << "\n";
        for(int i : comp) std::cout << i + 1 << " ";
        std::cout << "\n";
    }

}