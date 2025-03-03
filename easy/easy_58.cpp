#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  int lengthOfLastWord(std::string s) {
    int len = s.length();
    bool lastword = false;
    int sequence = 0;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] != ' ') {
        if (!lastword) {
          lastword = true;
        }
        sequence++;
      } else if (lastword) {
        return sequence;
      }
    }

    return sequence;
  }
};

int main() {
  Solution s;
  int var = s.lengthOfLastWord("hey mia");
  cout << var << endl;
}
