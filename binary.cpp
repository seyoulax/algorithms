#include <bits/stdc++.h>

std::vector<int> v;

int binary_left(int elem){
    int l, r;
    l = -1, r = v.size();
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(v[mid] >= elem) r = mid;
        else l = mid;
    }
    return r;
}

int binary_right(int elem){
    int l, r;
    l = -1, r = v.size();
    while(l + 1 < r){
        int mid = (l + r) / 2;
//        std::cout << v[mid] << "\n";
        if(v[mid] <= elem) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    int n, k;
    std::cin >> n >> k;
//    std::vector<int> ques(k, 0);
    v.assign(n, 0);
    for(int i = 0; i < n; i++) std::cin >> v[i];
    for(int i = 0; i < k; i++){
        int cur_q;
        std::cin >> cur_q;
        int left = binary_left(cur_q), right = binary_right(cur_q);
//        std::cout << left << " " << right << "\n";
        if(v[left] != cur_q || v[right] != cur_q) std::cout << 0 << "\n";
        else std::cout << left+1 << " " << right+1 << "\n";
    }
    return 0;
}