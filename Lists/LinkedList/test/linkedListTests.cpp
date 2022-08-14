#include "../linkedList.hpp"
#include <gtest/gtest.h>

#define list mydata::LinkedList

TEST(linkedListTests, append) {
    list<int> ll;
 
    for(int i = 0; i < 100; i++) ll.append(i);
}

TEST(linkedListTests, show) {
    list<int> ll;

    for(int i = 0; i < 100; ++i) ll.append(rand() % 100);

    EXPECT_NO_FATAL_FAILURE(ll.show());
    EXPECT_NO_FATAL_FAILURE(std::cout << ll);
}

TEST(linkedListTests, pop_begin) {
    EXPECT_NO_FATAL_FAILURE(
        list<int> ll;
        for(int i = 0; i < 100; i++) ll.append(i);
        while(ll.size() > 0) ll.pop_begin();
        ll.pop_begin();
    );
}

TEST(linkedListTests, destructor) {
    EXPECT_NO_FATAL_FAILURE(
        list<int> *ll = new list<int>();
        for(int i = 0; i < 100; ++i) ll->append(rand() % 100);
        delete ll;
    );
}

TEST(linkedListTests, iterator) {
    list<int> ll;
    for(int i = 0; i < 10; ++i) ll.append(i);
    int i = 0;
    for(auto num : ll) {
        std::cout << num << ' ';
        EXPECT_TRUE(num == i);
        i++;
    }
}