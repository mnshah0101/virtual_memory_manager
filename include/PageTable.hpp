#pragma once
#include <vector>
#include "TLB.hpp"

template <int PAGE_SIZE, int TLB_SIZE=16>
class PageTable {
private:
    std::vector<int*> pageTable;
    int alloc_pointer;
    TLB<TLB_SIZE> tlb;

public:
    PageTable() : alloc_pointer(0), pageTable(1000, nullptr) {}

    int allocatePage(double memory_needed) {
        int pages = static_cast<int>((memory_needed + PAGE_SIZE - 1) / PAGE_SIZE);

        int base_addr = alloc_pointer;
        for (int i = 0; i < pages; i++) {
            pageTable[alloc_pointer] = new int[PAGE_SIZE]();
            alloc_pointer++;
        }
        return base_addr; 
    }

    int* getPage(int memory_address) {
        int* cached = tlb.get(memory_address);
        if (cached) return cached;

        int page_idx = memory_address / PAGE_SIZE;
        int offset   = memory_address % PAGE_SIZE;

        if (page_idx < 0 || page_idx >= alloc_pointer) return nullptr;
        int* ptr = pageTable[page_idx] + offset;

        tlb.add(memory_address, ptr);
        return ptr;
    }
};
