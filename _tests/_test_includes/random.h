#ifndef B_RANDOM_H
#define B_RANDOM_H
#include <limits>
#include <iostream>
#include <set>
#include <vector>
#include <iomanip>
#include "utilities.h"
using namespace std;

template<typename T=int>
class Random{
  public:
  Random(T low = T(), T hi = numeric_limits<T>::max());
  void unique(T a[], int size);
  void unique(vector<T> &v, int size);
  T *unique_array(int size);
  T *random_array(int size);
  vector<T> random_vector(int size);
  vector<T> unique_vector(int size);
  T in_range(T low, T high);
  T in_range();
  T next_unique(T low, T high);
  T next_unique();
  T checksum(T a[], int size);

private:
  T _low;
  T _high;
  int _MAX_;
  vector<T> _list;
  typename vector<T>::iterator _it;
  set<T> _set;
};
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
template <typename T>
void unique(T a[], int size, T low = T(), T high = (T() + 1 * 1000));
template <typename T>
int r_in_range(int low=0, int high=(T() + 1 * 1000));
template <typename T>
int *even_array(int capacity, int start=T());
template <typename T>
int *odd_array(int capacity, int start=T()+1);
/****************************************************************************

*****************************************************************************/
template <typename T>
Random<T>::Random(T low, T high):_low(low), _high(high)
{
    const bool debug = false;
    if (debug)
        cout << "Random::Random(" << low << ", "<<high<<")"<<endl;

    _MAX_ = _high - _low + 1;
    
    if (debug)
        cout << "Random::Random(): leaving..."<<endl;
  }
template <typename T>
void Random<T>::unique(T a[], int size){
    const bool debug = false;
    if (debug)
        cout << "Random::unique(" << size << ")"<<endl;

    if (size > _high - _low + 1){
        cout << "RANDOM::UNIQUE: SIZE IS LARGER THAN RANGE" << size<<" v. "<<_low<<" .. "<<_high<<endl;
        throw "RANDOM::UNIQUE: SIZE IS LARGER THAN RANGE";
    }
    vector<T> v;
    int i = 0;
    unique(v, size);
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++){
        a[i++] = *it;
    }

        if (debug)
            cout << "Random::unique: Leaving....  " << endl;
}

template <typename T>
void Random<T>::unique(vector<T>& v, int size){
        const bool debug = false;
        if (debug)
            cout << "Random::unique(vector, " << size << ")"<<endl;

        if (size > _high - _low + 1){
            cout << "RANDOM::UNIQUE: SIZE IS LARGER THAN RANGE" 
                             <<size<<" > " <<_high <<" - " <<_low<<" + 1"<< endl;
            throw "RANDOM::UNIQUE: SIZE IS LARGER THAN RANGE";
        } 
      set<T> s;
      int i = 0;
      while (s.size() < size)
      {
          T num = in_range();
          if (s.find(num) == s.end())//does not contain
          { //log n
              s.insert(num);
              v.push_back(num);
              if (debug)
                  cout << "Random::unique: adding [" << num << "] to vector (set|vector size) ("<<s.size()<<"|"<<v.size()<<")/"<<size<< endl;
          }
          else{
              if (debug){
                  cout << num << " has already been added: " << v << endl;
              }
          }
	}
      if (debug)
          cout << "Random::unique (vector): Leaving...."<<endl;
  }
template<typename T>
T* Random<T>::unique_array(int size){
    T *arr = new T[size];
    unique(arr, size);
    return arr;
}

template <typename T>
T* Random<T>::random_array(int size){
    const bool debug = false;
    if(debug){
        cout << "Random::random_array(" << size << ")" << endl;
    }
    T *arr = new T[size];
    for (int i = 0; i < size; i++){
        arr[i] = in_range();
    }
    if (debug){
        cout << "returning: ";
        print_array(arr, size);
    }
    return arr;
}
template <typename T>
vector<T> Random<T>::random_vector(int size){
    T *arr = random_array(size);
    vector<T> v = init_vector(arr, size);
    delete[] arr;
    return v;
}
template <typename T>
vector<T> Random<T>::unique_vector(int size){
    T *arr = unique_array(size);
    vector<T> v(arr);
    delete[] arr;
    return v;
}

template <typename T>
T Random<T>::in_range(T low, T high){
  const bool debug = false;
  if (debug)
      cout << "Random::in_range("<<low<<", "<<high<<") top"<<endl;

  T random = static_cast<T>(low + (rand() % static_cast<int>((high - low + 1))));
  if (debug){
      cout << "Random::in_range("<<low<<", "<<high<<") returning: "<< random << endl;
  }
  return random;
}
template <typename T>
T Random<T>::in_range(){
    const bool debug = false;
    if (debug)
        cout << "Random::in_range() top"<<endl;
    return in_range(_low, _high);
}

template <typename T>
T Random<T>::next_unique(T low, T high){
    if(_set.size() == high-low+1){
        cout << "RANDOM::NEXT_UNIQUE: TOO MANY NUMBERS" 
                <<"size: "<<_set.size()<<" v. "<<high<<" - "<<low<<" + "<<1<< endl;
        throw "RANDOM::NEXT_UNIQUE: TOO MANY NUMBERS";
    }
    T num;
    do
    {
        num = in_range(low, high);
    } while (_set.find(num) != _set.end());
    _set.insert(num);
    return num;
  
}
template <typename T>
T Random<T>::next_unique(){
    return next_unique(_low, _high);
}



template <typename T>
T Random<T>::checksum(T a[], int size){
  T sum = 0;
  for(int i = 0; i < size; i++) {
      sum += a[i];
  }

  return sum/size;
}
template <typename T>
T r_in_range(T low, T high){
  const bool debug = false;
    if (debug)
        cout << "in_range("<<low<<", "<<high<<") top"<<endl;

  T random = static_cast<T>(low + (rand() % static_cast<int>((high - low + 1))));
  if (debug){
      cout << "in_range(low, high): returning: " << random << endl;
  }
  return random;
}
template <typename T>
T *even_array(int capacity, T start)
{
  if (start % 2 != 0)
      start++;
  T *arr = new T[capacity];
  for (int i = 0; i < capacity; i++){
      arr[i] = start + i * 2;
  }
  return arr;
}
template <typename T>
T *odd_array(int capacity, T start)
{
  if (start % 2 != 1)
      start--;
  T *arr = new T[capacity];
  for (int i = 0; i < capacity; i++){
      arr[i] = start + i * 2;
  }
  return arr;
}
template <typename T>
void unique(T a[], int size, T low, T high){
  const bool debug = false;
  if (debug)
      cout << "Random::unique(vector, " << size << ")"<<endl;

  if (size > high - low + 1){
      cout << "UNIQUE: SIZE IS LARGER THAN RANGE" 
            <<size<<" > " <<high <<" - " <<low<<" + 1"<< endl;
      throw "UNIQUE: SIZE IS LARGER THAN RANGE";
  } 
  set<T> s;
  int i = 0;
  while (s.size() < size)
  {
      T num = r_in_range(low, high);
      if (contains(s, num))//does not contain
      { //log n
          s.insert(num);
          a[i++] = num;
          if (debug)
              cout << "unique: adding [" << num << "] to vector (set|vector size) ("<<s.size()<<"|"<<i<<")/"<<size<< endl;
      }
      else{
          if (debug){
              cout << num << " has already been added: " << s << endl;
          }
      }
  }
  if (debug)
      cout << "Random::unique (vector): Leaving...."<<endl;
}


template<typename T>
vector<T> random_vector(int size, const T& low, const T& high){
    vector<T> v;
    for (int i = 0; i<size; i++){
        v.push_back(r_in_range(low, high));
    }
    return v;
}



#endif