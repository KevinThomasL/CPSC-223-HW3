
#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "vector_collection.h"

using namespace std;


// Test 1
TEST(BasicListTest, CorrectSize) {
  VectorCollection<string,double> c;
  ASSERT_EQ(0, c.size());
  c.add("b", 10.0);
  ASSERT_EQ(1, c.size());
  c.add("a", 20.0);
  ASSERT_EQ(2, c.size());
  c.add("c", 20.0);
  ASSERT_EQ(3, c.size());
  ASSERT_NE(-1, c.size());	//Make sure the size doesnt go above
  ASSERT_NE(4, c.size());	//or below the bounds necessary
}

// Test 2
TEST(BasicListTest, SimpleFind) {
  VectorCollection<string,double> c;
  double v;
  ASSERT_EQ(false, c.find("b", v));
  c.add("b", 10.0);
  ASSERT_EQ(true, c.find("b", v));
  ASSERT_EQ(10.0, v);
  ASSERT_EQ(false, c.find("a", v));
  c.add("a", 20.0);
  ASSERT_EQ(true, c.find("a", v));
  ASSERT_EQ(20.0, v);
}

// Test 3
TEST(BasicListTest, SimpleRemoveElems) {
  VectorCollection<string,int> c;
  c.add("b", 10);
  c.add("a", 20);
  c.add("d", 30);
  c.add("c", 30);
  ASSERT_EQ(4, c.size());
  int v;
  c.remove("a");
  ASSERT_EQ(3, c.size());
  ASSERT_EQ(false, c.find("a", v));
  c.remove("b");
  ASSERT_EQ(2, c.size());
  ASSERT_EQ(false, c.find("b", v));  
  c.remove("c");
  ASSERT_EQ(1, c.size());
  ASSERT_EQ(true, c.find("d", v));  //make sure it is removing correct elems
  ASSERT_EQ(30, v);  //
  ASSERT_EQ(false, c.find("c", v));  
  c.remove("d");
  ASSERT_EQ(0, c.size());
  ASSERT_EQ(false, c.find("c", v));
  c.add("ef", 40.0);  //make sure remove works on 2 strings
  ASSERT_EQ(1, c.size());  //
  c.remove("ef");  //
  ASSERT_EQ(c.find("ef", v), false);  // 
  ASSERT_EQ(c.size(), 0);  //
}

// Test 4
TEST(BasicListTest, SimpleRange) {
  VectorCollection<int,string> c;
  c.add(50, "e");
  c.add(10, "a");
  c.add(30, "c");
  c.add(40, "d");
  c.add(60, "f");
  c.add(20, "b");
  vector<string> vs;
  c.find(20, 40, vs);
  ASSERT_EQ(3, vs.size());
  // note that the following "find" is a C++ built-in function
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "a"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "b"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "c"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "d"));
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "e"));  
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "f"));  
}

// Test 5
TEST(BasicListTest, SimpleSort) {
  VectorCollection<string,int> c;
  c.add("b", 5);
  c.add("a", -10);  //test to work with negative numbers
  c.add("f", 50);
  c.add("d", 30);
  c.add("c", 20);
  c.add("e", 40);
  c.add("h", 100);  //tests working with numbers larger than two digits
  c.add("i", 500);
  c.add("g", 75);
  c.add("k", 50000);
  c.add("j", 4000);
  vector<string> sorted_ks;
  c.sort(sorted_ks);
  ASSERT_EQ(11, sorted_ks.size());
  // check if in sorted order
  for (int i = 0; i < int(sorted_ks.size()) -1; ++i)
    ASSERT_LE(sorted_ks[i], sorted_ks[i+1]);
}

// TODO: ... additional tests ...

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

