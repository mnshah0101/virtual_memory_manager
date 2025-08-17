#include <iostream>
#include "PageTable.hpp"

using namespace std;

int main() {
    PageTable<4, 2> pt;

    cout << "Allocating 10 bytes (3 pages, 4 bytes each):\n";
    int addr1 = pt.allocatePage(10);
    cout << "Allocated at address: " << addr1 << endl;

    cout << "Allocating 5 bytes (2 pages):\n";
    int addr2 = pt.allocatePage(5);
    cout << "Allocated at address: " << addr2 << endl;

    cout << "\nRetrieving from addr1:\n";
    int* p1 = pt.getPage(addr1 * 4); 
    if (p1) cout << "Got valid pointer!\n";
    cout << &p1 << endl;

    cout << "\nRetrieving from addr2:\n";
    int* p2 = pt.getPage(addr2 * 4);
    if (p2) cout << "Got valid pointer!\n";
    cout << &p2 << endl;

    cout << "\nTesting invalid address:\n";
    int* bad = pt.getPage(9999);
    if (!bad) cout << "Correctly nullptr.\n";

    return 0;
}
