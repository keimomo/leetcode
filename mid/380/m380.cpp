#include <random>
#include <unordered_map>
#include <vector>
using namespace std;
class RandomizedSet {
public:
  vector<int> myarray;
  unordered_map<int, int> mymap;
  random_device rd;
  mt19937 gen;
  RandomizedSet() {}

  bool insert(int val) {
    if (mymap.find(val) != mymap.end()) {
      return false;
    } else {
      myarray.push_back(val);
      mymap.insert({val, myarray.size() - 1});
    }
    return true;
  }

  bool remove(int val) {
    if (mymap.find(val) == mymap.end()) {
      return false;
    }
    int size = myarray.size();
    int idx = mymap[val];
    int last_elem = myarray[size - 1];
    if (idx != size - 1) {
      myarray[idx] = last_elem;
      mymap[last_elem] = idx;
    }

    myarray.pop_back();
    mymap.erase(val);
    return true;
  }

  int getRandom() {
    uniform_int_distribution<> distrib(0, myarray.size() - 1);
    int random_idx = distrib(gen);
    return myarray[random_idx];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
