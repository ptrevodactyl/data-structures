#include "../linkedList.hpp"
#include <gtest/gtest.h>
#include <crtdbg.h>

#define list mydata::LinkedList

TEST(linkedListTests, append) {
    list<int> ll;
    
    ll.append(1);
    EXPECT_TRUE(ll.getSize() == 1);
    EXPECT_TRUE(ll.getHead() == 1);
    EXPECT_TRUE(ll.getTail() == 1);

    ll.prepend(3);
    EXPECT_TRUE(ll.getSize() == 2);
    EXPECT_TRUE(ll.getHead() == 3);
    EXPECT_TRUE(ll.getTail() == 1);
}

TEST(linkedListTests, show) {
    list<int> ll;

    for(int i = 0; i < 100000; ++i) ll.append(rand() % 100000);

    EXPECT_NO_FATAL_FAILURE(ll.show());
    EXPECT_NO_FATAL_FAILURE(std::cout << ll);
}

TEST(linkedListTests, destructor) {
    list<int> *ll = new list<int>();
    for(int i = 0; i < 100; ++i) ll->append(rand() % 100);
    delete ll;
}