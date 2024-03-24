#include <bits/stdc++.h>

std::vector<std::vector<int>> G;
std::vector<int> d;
std::vector<int> p;
std::queue<int> q;

void bfs(int start){
    q.push(start);
    d[start] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int next : G[cur]){
            if(d[next] == -1) {
                std::cout << cur << ":" << next << " ";
                q.push(next);
                d[next] = d[cur] + 1;
                p[next] = cur;
            }
        }
    }
}

std::vector<int> get_j(int from, int to){
    std::vector<int> result;
    int v = p[to - 1];
    while(v != from - 1){
        result.push_back(v);
        v = p[v];
    }
    return result;
}

int main(){
    int n, fr, t;
    std::cin >> n;
    G.assign(n, std::vector<int> ());
    p.assign(n, 0);
    d.assign(n, -1);

    for(int i = 0; i < n; i++){
        for(int y = 0; y < n; y++){
            int f;
            std::cin >> f;
            if(f == 1){
                G[i].push_back(y);
                G[y].push_back(i);
            }
        }
    }

//    for(std::vector<int> c : G){
//        for(int cur : c) std::cout << cur << " ";
//        std::cout << "\n";
//    }


    std::cin >> fr >> t;

    bfs(fr - 1);

    for(int i = 0; i < n; i++) std::cout << d[i] << " " << p[i] << "\n";

    if(d[t - 1] == -1) std::cout << -1;
    else{
        std::vector<int> to_rev;
        to_rev = get_j(fr, t);
        std::cout << to_rev.size() + 1 << "\n";
        std::cout << fr << " ";
        for(int i = to_rev.size() - 1; i >= 0; i--) std::cout << to_rev[i] + 1 << " ";
        std::cout << t << " ";
    }

    return 0;
}

