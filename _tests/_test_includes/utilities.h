#ifndef BARKESHLI_TEST_UTILS
#define BARKESHLI_TEST_UTILS
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

using namespace std;

template <typename T>
ostream& operator <<(ostream& outs, vector<T>& v){
  outs << "{";
  for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
  {
    outs << setw(4) << *it;
  }
  outs << "}";
  return outs;
}

template <typename T>
ostream& operator <<(ostream& outs, set<T>& v){
  outs << "||";

  for (typename set<T>::iterator it= v.begin(); it != v.end(); it++)
  {
    outs << setw(4) << *it;
  }
  outs << "||";
  return outs;
}
template <typename T>
ostream& operator <<(ostream& outs, list<T>& l){
  outs << "||";

  for (typename list<T>::iterator it= l.begin(); it != l.end(); it++)
  {
    outs << setw(4) << *it;
  }
  outs << "||";
  return outs;
}
template <typename T>
ostream& print_array(T* a, int size, ostream& outs=cout){
  outs << "[("<<setw(4)<<size<<")";
  for (int i = 0; i < size; i++){
    cout.precision(1);
    outs << fixed << setw(4) << a[i];
  }
  outs<<"]"<<endl;
  return outs;
}
template <typename T>
set<T> init_set(T* arr, int size){
  set<T> s;
  for (int i = 0; i < size; i++)
  {
    s.insert(arr[i]);
  }
  return s;
}
template <typename T>
bool contains(const set<T>& s, const T& key){
  return !(s.find(key) == s.end());
}
template <typename T>
vector<T> init_vector(T* arr, int size){
  vector<T> v;
  for (int i = 0; i < size; i++)
  {
    v.push_back(arr[i]);
  }
  return v;
}
#endif