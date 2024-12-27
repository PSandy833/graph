// #include <iostream>
// #include "gtest/gtest.h"
// #include "graph.h"
// #include "graph.cpp"

// using namespace std;

// TEST(testing, test01)
// {
// 	graph g;
//     ASSERT_TRUE(g.addVertex("Chicago"));
//     ASSERT_FALSE(g.addVertex("Chicago")); // should return false since "Chicago" already exists
//     ASSERT_TRUE(g.addVertex("New York"));
//     ASSERT_EQ(2, g.NumVertices()); // should have two vertices now
// }
// TEST(testing, test02) {
//     graph g;
//     g.addVertex("A");
//     g.addVertex("B");
//     g.addVertex("C");
//     ASSERT_TRUE(g.addEdge("A", "B", 1.0));
//     ASSERT_TRUE(g.addEdge("B", "C", 2.0));
//     ASSERT_FALSE(g.addEdge("D", "C", 3.0));
//     ASSERT_FALSE(g.addEdge("A", "D", 4.0));
//     double weight;
//     ASSERT_TRUE(g.getWeight("A", "B", weight));
//     ASSERT_EQ(weight, 1.0);
//     ASSERT_TRUE(g.getWeight("B", "C", weight));
//     ASSERT_EQ(weight, 2.0);
//     ASSERT_FALSE(g.getWeight("A", "C", weight));
// }
// TEST(testing, test03)
// {
//     graph G;
//     G.addVertex("A");
//     G.addVertex("B");
//     G.addEdge("A", "B", 5.0);

//     double weight;
//     bool result = G.getWeight("A", "B", weight);
//     ASSERT_TRUE(result);
//     ASSERT_DOUBLE_EQ(weight, 5.0);

//     // Test a non-existent edge
//     result = G.getWeight("B", "A", weight);
//     ASSERT_FALSE(result);
// }
// TEST(testing, test04) {
//     graph g;
//     g.addVertex("A");
//     g.addVertex("B");
//     g.addVertex("C");
//     g.addEdge("A", "B", 1.0);
//     g.addEdge("A", "C", 2.0);

//     set<string> expected = {"B", "C"};
//     set<string> result = g.neighbors("A");

//     EXPECT_EQ(expected, result);
// }
// TEST(testing, test05) {
//   graph g;
//   g.addVertex("A");
//   g.addVertex("B");
//   g.addVertex("C");
//   vector<string> vertices = g.getVertices();
//   ASSERT_EQ(3, vertexList.size());
//   EXPECT_EQ("A", vertexList[0]);
//   EXPECT_EQ("B", vertexList[1]);
//   EXPECT_EQ("C", vertexList[2]);
// }


// int main()
// {
//     ::testing::InitGoogleTest();

//     //
//     // run all the tests, returns 0 if they
//     // all pass and 1 if any fail:
//     //
//     int result = RUN_ALL_TESTS();

//     return result;
// }

#include "graph.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

TEST(testing, test01) {
  graph g;
  ASSERT_TRUE(g.addVertex("Chicago"));
  ASSERT_TRUE(g.addVertex("New York"));
  ASSERT_TRUE(2 == g.NumVertices()); // should have two vertices now
}

TEST(testing, test02) {
  graph g;
  g.addVertex("A");
  g.addVertex("B");
  g.addVertex("C");
  ASSERT_TRUE(g.addEdge("A", "B", 1.0));
  ASSERT_TRUE(g.addEdge("B", "C", 2.0));
  ASSERT_FALSE(g.addEdge("D", "C", 3.0));
  ASSERT_FALSE(g.addEdge("A", "D", 4.0));
  double weight;
  ASSERT_TRUE(g.getWeight("A", "B", weight));
  ASSERT_TRUE(weight == 1.0);
  ASSERT_TRUE(g.getWeight("B", "C", weight));
  ASSERT_TRUE(weight == 2.0);
  ASSERT_FALSE(g.getWeight("A", "C", weight));
}
TEST(testing, test03) {
  graph G;
  G.addVertex("A");
  G.addVertex("B");
  G.addEdge("A", "B", 5.0);

  double weight;
  bool result = G.getWeight("A", "B", weight);
  ASSERT_TRUE(result);
  ASSERT_TRUE(weight == 5.0);

  // Test a non-existent edge
  result = G.getWeight("B", "A", weight);
  ASSERT_FALSE(result);
}
TEST(testing, test04) {
  graph g;
  g.addVertex("A");
  g.addVertex("B");
  g.addVertex("C");
  g.addEdge("A", "B", 1.0);
  g.addEdge("A", "C", 2.0);

  set<string> expected = {"B", "C"};
  set<string> result = g.neighbors("A");

  ASSERT_TRUE(expected == result);
}
TEST(testing, test05) {
  graph g;
  g.addVertex("A");
  g.addVertex("B");
  g.addVertex("C");
  vector<string> vertices = g.getVertices();
  ASSERT_TRUE(3 == vertices.size());
  ASSERT_TRUE("A" == vertices[0]);
  ASSERT_TRUE("B" == vertices[1]);
  ASSERT_TRUE("C" == vertices[2]);
}

int main() {
  ::testing::InitGoogleTest();

  //
  // run all the tests, returns 0 if they
  // all pass and 1 if any fail:
  //
  int result = RUN_ALL_TESTS();

  return result;
}
