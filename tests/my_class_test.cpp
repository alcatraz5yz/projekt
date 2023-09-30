#include <gtest/gtest.h>
#include "my_class.h"

TEST(MyClassTest, AddTest) {
    MyClass obj;
    EXPECT_EQ(obj.add(1, 2), 3);
    EXPECT_EQ(obj.add(-1, 2), 1);
}
