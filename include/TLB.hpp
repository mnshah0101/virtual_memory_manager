#pragma once

#include <unordered_map>
#include <climits>

template <int N>
class TLB {
private:
    std::unordered_map<int, int*> tlb;       
    std::unordered_map<int, int> access_cnt;
    int counter;

public:
    TLB() : counter(0) {
        tlb.reserve(N);
        access_cnt.reserve(N);
    }

    void add(int key, int* value) {
        if (tlb.size() >= N) {
            int lru_key = -1;
            int min_count = INT_MAX;
            for (auto& entry : access_cnt) {
                if (entry.second < min_count) {
                    min_count = entry.second;
                    lru_key = entry.first;
                }
            }
            if (lru_key != -1) {
                tlb.erase(lru_key);
                access_cnt.erase(lru_key);
            }
        }
        tlb[key] = value;
        access_cnt[key] = counter++;
    }

    int* get(int key) {
        auto it = tlb.find(key);
        if (it == tlb.end()) return nullptr;
        access_cnt[key] = counter++;
        return it->second;
    }
};
