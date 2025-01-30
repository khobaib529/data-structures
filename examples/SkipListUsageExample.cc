#include <iostream>
#include <string>
#define NDEBUG 1

#include "ds/skiplist.h"
#include "util/arena.h"

struct IntComparator {
    int operator()(const int& a, const int& b) const {
        if (a < b) return -1;
        if (a > b) return +1;
        return 0;
    }
};

int main() {
    IntComparator cmp;
    ds::Arena arena;
    ds::SkipList<int, IntComparator> list(cmp, &arena);
    
    // Insert some elements. Note: Duplicate elements will be ignored
    list.Insert(33);
    list.Insert(12);
    list.Insert(28);
    list.Insert(3);
    list.Insert(33);
    list.Insert(24);
    list.Insert(24);

    // Iterating Over SkipList
    ds::SkipList<int, IntComparator>::Iterator it(&list);
    it.SeekToFirst();
    std::cout << "SkipList elements: ";
    while (it.Valid()) {
        std::cout << it.key() << " ";
        it.Next();
    }
    std::cout << std::endl;
    return 0;
}