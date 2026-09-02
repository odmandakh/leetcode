#include <algorithm>
#include <climits>
#include <vector>


using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ASSISTED: AI provided the single-pass critical-point-tracking solution logic directly.
class Solution {
 public:
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    ListNode* prev = head;
    ListNode* curr = head->next;
    int idx = 1;

    int firstIdx = -1, lastIdx = -1, minDist = INT_MAX;

    while (curr->next) {
      bool isCritical = (curr->val > prev->val && curr->val > curr->next->val) ||
                         (curr->val < prev->val && curr->val < curr->next->val);
      if (isCritical) {
        if (firstIdx == -1) {
          firstIdx = idx;
        } else {
          minDist = min(minDist, idx - lastIdx);
        }
        lastIdx = idx;
      }
      prev = curr;
      curr = curr->next;
      ++idx;
    }

    if (firstIdx == -1 || firstIdx == lastIdx) return {-1, -1};
    return {minDist, lastIdx - firstIdx};
  }
};

