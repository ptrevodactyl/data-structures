#include "../linkedList.hpp"
#include <gtest/gtest.h>

TEST(linkedListTests, DemonstrateGTestMacros) {
    mydata::LinkedList<int> ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    EXPECT_TRUE(ll.size() == 4);
}