#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;
//----------------------------------------------------------------------------------------
//          COPY BASIC_TEST INTO THIS FILE.
//                    AND THEN,
//         DO NOT EDIT THIS FILE ANY FURTHER
//----------------------------------------------------------------------------------------

bool basic_test(bool debug=false){
  return true;
}
TEST(BASIC_TEST, BasicTest) {
  
  //EXPECT_EQ(1, <your individual test functions are called here>);

  EXPECT_EQ(1, basic_test());
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

/*



*/
