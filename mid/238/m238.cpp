#include <vector>
using namespace std;
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int size = nums.size();
    int product = 1;
    vector<int> zeros;
    for (int i = 0; i < size; i++) {
      if (nums[i] == 0) {
        zeros.push_back(i);
      } else {
        product *= nums[i];
      }
    }

    int idx = 0;
    int zero_size = zeros.size();
    if (zero_size >= 2) {
      product = 0;
    }
    vector<int> sol(size, 0);
    if (zero_size == 0) {
      for (int i = 0; i < size; i++) {
        sol[i] = product / nums[i];
      }
    } else {
      for (int i = 0; i < zero_size; i++) {
        sol[zeros[i]] = product;
      }
    }
    return sol;
  }
};
