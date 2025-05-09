#include "gtest/gtest.h"
#include "../!includes/consts.h"
#include "../!test_includes/random.h"
#include "../!test_includes/utilities.h"

#include "../set.h"
using namespace std;

// TEST(CTORTest, DefaultCTOR) {
//   Vector v;
//   EXPECT_EQ(0, v.size());
// }
bool verify_union(int* a, int sizeA, int* b, int sizeB, int* final, int sizeF){
  const bool debug = false;
  if (debug){
    cout << "verify_union("<<endl<<'\t';
    print_array(a, sizeA);
    cout << '\t';
    print_array(b, sizeB);
    cout << '\t';
    print_array(final, sizeF);
    cout <<")"<< endl;
  }
  
  Random rand_a(0, sizeA - 1);      //picking a random index
  Random rand_b(0, sizeB - 1);
  int timesA = r_in_range(sizeA / 2, sizeA);  //test this many items
  int timesB = r_in_range(sizeB / 2, sizeB);
  
  set<int> s = init_set(final, sizeF);        //place final in a set for quick search

  if (debug){
    cout << "here is  your final set: " << s << endl;
  }
  
  //any element of a must be in final:
  
  for (int i = 0; i < timesA; i++){
    int next = rand_a.in_range();     //pick a random element
    if (!contains(s, a[next])){       //it should be in the final
      if (true){
        cout << "verify_union failed: a["<<next<<"]: " 
             << a[next] << " not in " << s << endl;
      }
      return false;
    }
  }

  //any element of b must be in final:

  for (int i = 0; i < timesB; i++){
    int next = rand_b.in_range();
    if (!contains(s, b[next])){
      if (true){
        cout << "verify_union failed: b["<<next<<"]: " 
             << b[next] << " not in " << s << endl;
      }
      return false;
    }
  }
    return true;
}

bool verify_intersection(int* a, int sizeA, int* b, int sizeB, int* final, int sizeF){
  const bool debug = false;
  if (debug){
    cout << "verify_intersection("<<endl<<'\t';
    print_array(a, sizeA);
    cout << '\t';
    print_array(b, sizeB);
    cout << '\t';
    print_array(final, sizeF);
    cout <<")"<< endl;
  }
  Random rand_f(0, sizeF - 1);              //random indices of final
  int timesF = r_in_range(sizeF / 2, sizeF);//number of items to test

  set<int> set_a = init_set(a, sizeA);      //lists a and b
  set<int> set_b = init_set(b, sizeB);
  if(debug){
    cout << "here is  your sets: " << endl
        <<'\t'<< set_a << endl
        <<'\t'<< set_b << endl;
  }
  
  //any element in final must be both in a or b:

  for (int i = 0; i < timesF; i++){
    int next = rand_f.in_range();           //pick any random element in final           
    if (!contains(set_a, final[next]) ||    //must be in both a AND b
        !contains(set_b, final[next])){
      if (true){
        cout << "verify_intersection failed: final["<<next<<"]: " << final[next] << " not in " <<endl
              <<'\t'<< set_a << endl
              <<'\t'<<set_b<<endl;
      }
      return false;
    }
  }
    return true;
}


TEST(UnionTest, IterationTest) {
  const bool debug = false;
  const int MAX_ARRAY = 15;
  const int MIN_ARRAY = 5;
  const int VALUES_RANGE = 30;
  //Random array_size(MIN_ARRAY, MAX_ARRAY);
  Random values(0, VALUES_RANGE);

  for (int i = 0; i < 20; i++)
  {
    //int a[MAX], b[MAX], final[MAX];
    int sizeA, sizeB, sizeF;

    sizeA = r_in_range(MIN_ARRAY, MAX_ARRAY);
    sizeB = r_in_range(MIN_ARRAY, MAX_ARRAY);
    int *a = values.unique_array(sizeA);
    int *b = values.unique_array(sizeB);
    int *final = new int[sizeA + sizeB];

    sizeF = 0;
    array_union(a, sizeA, b, sizeB, final, sizeF);

    if (debug){
      cout <<"["<<i<<"]"<< "=======================" << endl;
      cout << "UnionTest: " << endl;
      print_array(a, sizeA);
      print_array(b, sizeB);
      print_array(final, sizeF);
      cout << "===============" << endl;
    }
    EXPECT_EQ(1, verify_union(a, sizeA, b, sizeB, final, sizeF));

    if (a) delete[] a;
    if (b) delete[] b;
    if (final) delete[] final;
  }
}
TEST(UnionTest, EmptyTest) {
  const bool debug = true;
  const int MAX_ARRAY = 15;
  const int MIN_ARRAY = 5;
  const int VALUES_RANGE = 30;
  
  Random array_size(MIN_ARRAY, MAX_ARRAY);
  Random values(0, VALUES_RANGE);
  int sizeA, sizeB, sizeF;
  int *a, *b, *final;

  sizeA = r_in_range(MIN_ARRAY, MAX_ARRAY); //random in range
  a = values.unique_array(sizeA);           //array of sizeA filled with random in range 'values'

  sizeB = 0;                                //B is empty
  b = nullptr;

  final = new int[sizeA];                   //allocagte same size as a

  sizeF = 0;
  array_union(a, sizeA, b, sizeB, final, sizeF);  //test 
  if (debug){
    cout <<"=======================" << endl;
    cout << "Union EmptyTest: " << endl;
    print_array(a, sizeA);
    print_array(b, sizeB);
    print_array(final, sizeF);
    cout << "===============" << endl;
  }

  EXPECT_EQ(1, verify_union(a, sizeA, b, sizeB, final, sizeF));

  //now, the other way around:
  sizeF = 0;
  array_union(b, sizeB, a, sizeA, final, sizeF);
  if (debug){
    cout <<"=======================" << endl;
    cout << "Union EmptyTest: " << endl;
    print_array(b, sizeB);
    print_array(a, sizeA);
    print_array(final, sizeF);
    cout << "===============" << endl;
  }

  EXPECT_EQ(1, verify_union(a, sizeA, b, sizeB, final, sizeF));

    if (a) delete[] a;
    if (b) delete[] b;
    if (final) delete[] final;

}
TEST(IntersectionTest, IterationTest) {
  const int MAX_ARRAY = 10;
  const int MIN_ARRAY = 5;
  const int VALUES_RANGE = 30;
  Random array_size(MIN_ARRAY, MAX_ARRAY);
  Random values(0, VALUES_RANGE);

  for(int i = 0; i < 20; i++) {
    //int a[MAX], b[MAX], final[MAX];
    int sizeA, sizeB, sizeF=0;

    sizeA = r_in_range(MIN_ARRAY, MAX_ARRAY);
    sizeB = r_in_range(MIN_ARRAY, MAX_ARRAY);
    int *a = values.unique_array(sizeA);
    int *b = values.unique_array(sizeB);
    int *final = new int[max(sizeA, sizeB)];

    intersection(a, sizeA, b, sizeB, final, sizeF);

    EXPECT_EQ(1, verify_intersection(a, sizeA, b, sizeB, final, sizeF));
    if (a) delete[] a;
    if (b) delete[] b;
    if (final) delete[] final;
  }
}
TEST(IntersectionTest, EmptyTest) {
  const bool debug = true;
  const int MAX_ARRAY = 15;
  const int MIN_ARRAY = 5;
  const int VALUES_RANGE = 30;
  Random array_size(MIN_ARRAY, MAX_ARRAY);
  Random values(0, VALUES_RANGE);
  int sizeA, sizeB, sizeF;
  int *a, *b, *final;

  sizeA = r_in_range(MIN_ARRAY, MAX_ARRAY);
  a = values.unique_array(sizeA);           //array of sizeA filled with random in range 'values'

  sizeB = 0;
  b = nullptr;

  final = new int[sizeA];  //same size as a

  sizeF = 0;
  intersection(a, sizeA, b, sizeB, final, sizeF);
  if (debug){
    cout << "=======================" << endl;
    cout << "intersection EmptyTest: " << endl;
    print_array(a, sizeA);
    print_array(b, sizeB);
    print_array(final, sizeF);
    cout << "===============" << endl;
  }

  EXPECT_EQ(1, verify_intersection(a, sizeA, b, sizeB, final, sizeF));

  //now, the other way around:
  sizeF = 0;
  intersection(b, sizeB, a, sizeA, final, sizeF);
  if (debug){
    cout << "=======================" << endl;
    cout << "intersection EmptyTest: " << endl;
    print_array(b, sizeB);
    print_array(a, sizeA);
    print_array(final, sizeF);
    cout << "===============" << endl;
  }

  EXPECT_EQ(1, verify_intersection(a, sizeA, b, sizeB, final, sizeF));

    if (a) delete[] a;
    if (b) delete[] b;
    if (final) delete[] final;

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testA.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

