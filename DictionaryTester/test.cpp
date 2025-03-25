#include "pch.h"

TEST(ArrayDictCase, addTest) {
  ArrayDictionary<int, double> testDict;
  EXPECT_EQ(testDict.getNumberOfItems(), 0);
  EXPECT_TRUE(testDict.isEmpty());

  testDict.add(1, 2.0);
  testDict.add(13, 3.0);
  EXPECT_EQ(testDict.getNumberOfItems(), 2);
  EXPECT_FALSE(testDict.isEmpty());
}

TEST(ArrayDictCase, getters) {
  ArrayDictionary<int, double> testDict;
  EXPECT_THROW(testDict.getItem(1), NotFoundException);
  testDict.add(1, 2.1);
  testDict.add(11, 2.5);
  testDict.add(13, 2.2);
  EXPECT_EQ(testDict.getItem(1), 2.1);
  EXPECT_EQ(testDict.getItem(13), 2.2);
  EXPECT_EQ(testDict.getItem(11), 2.5);
}

