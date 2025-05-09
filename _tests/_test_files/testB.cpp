#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

#include "../_test_includes/random.h"
#include "../_test_includes/utilities.h"
#include "../_test_includes/timer.h"

//------------------------------------------------------------------------------------------
//Files we are testing:



//------------------------------------------------------------------------------------------

using namespace std;

bool test_template(){
  Timer t;
  t.start();
  const bool debug = false;
  return true;
}


TEST(AddEntry, TemplateTest) {
  bool success = test_template();
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testA.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

