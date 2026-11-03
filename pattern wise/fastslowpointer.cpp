

#include <iostream>
using namespace std;

// 1. LeetCode जो बैकग्राउंड में छुपा कर रखता है (बर्तन)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 1 -https://leetcode.com/problems/linked-list-cycle-ii/description
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
     // Phase 1: Detect whether a cycle exists
         ListNode*slow=head;
          ListNode*fast=head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        // No cycle
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
        // Phase 2: Find the starting node of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

//2-
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Key Idea:
// Use two pointers with a fixed gap to locate and remove the nth node from the end in one pass.
// Consider:
// How would you handle the edge case where the node to be removed is the head itself using a dummy node?

//  पहला कदम: Fast पॉइंटर को शुरुआत से n कदम आगे भेज दो। अब Fast और Slow के बीच n की दूरी हो गई है।
//  दूसरा कदम: अब Fast और Slow दोनों को एक-एक कदम आगे बढ़ाओ, तब तक जब तक Fast लिस्ट के एकदम आख़िरी नोड को पार न कर जाए (यानी Fast == NULL न हो जाए)।
//  नतीजा: चूँकि दोनों के बीच n की दूरी थी, जब Fast आख़िरी छोर पर गिरेगा, तब Slow पॉइंटर ठीक उस नोड के पीछे (एक कदम पहले) खड़ा होगा जिसे हमें डिलीट करना है!
//  हटाना (Deletion): अब बस Slow->next को Slow->next->next से जोड़ दो। n-th नोड बीच में से कट जाएगा।
class Solution {
public:
       ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* dummy=new ListNode(0,head);
       ListNode* slow=dummy;
       ListNode* fast=dummy;

   for(int i=0;i<=n;i++){
    fast=fast->next;
   }
   while(fast!=NULL){
   slow=slow->next;
   fast=fast->next;
   }  //अब jis node को delete करना है, slow 
   //उससे एक पहले वाली node में पहुंच जाएगा और फिर हम उसको next pointer assign करके ///उसको delete कर देंगे।

   slow->next= slow->next->next;
   return dummy->next;
    }
};
