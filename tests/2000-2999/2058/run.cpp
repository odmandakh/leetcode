#include "runner.h"
#include "problems/2000-2999/2058.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2058",
      "Find the Minimum and Maximum Number of Nodes Between Critical Points",
      Parse::intVecBracketed,  // input: [1,2,3,...] -- built into a linked list below
      Parse::intVecBracketed,  // output: [minDistance, maxDistance]
      [](auto vals) {
        ListNode dummy;
        ListNode* tail = &dummy;
        for (int v : vals) {
          tail->next = new ListNode(v);
          tail = tail->next;
        }
        return Solution().nodesBetweenCriticalPoints(dummy.next);
      });
}
