

// Trigger Keywords: "Range sum/product", "Except itself", "Balance left vs right", "Cumulative total".
// Problem Solved: Eliminates $O(N^2)$ nested loops when an element's answer depends on the data existing on both its left and right sides.
// Core Logic: Never look back using inner loops. Make one pass Left $\rightarrow$ Right to record the running total (Prefix/History), and one pass Right $\rightarrow$ Left (Suffix/Future). The answer at index i is the mathematical combination of its Prefix and Suffix.
// https://leetcode.com/problems/find-the-middle-index-in-array/description/
// 1991. Find the Middle Index in Array

// for  loop कर रही है, मतलब उसकी जगह पर यही लिख सकते हैं। यही पूरी वो चीज calculate कर।

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
      //  यह C++ का "for-each" लूप है। इसमें इंडेक्स (i) का कोई झंझट नहीं होता।
// पढ़ने का तरीका: "For every 'num' inside 'nums'..."
// यह सीधा 'nums' में से एक-एक नंबर (num) निकालता है और totalSum में जोड़ता जाता है।
        for(int num : nums) {
            totalSum += num;
        }
        int leftSum = 0; // शुरुआत में लेफ्ट में कुछ नहीं है, तो sum 0 है  / Step 2: एक-एक करके हर इंडेक्स पर जाओ
        for(int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];// Right Sum निकालने का सॉलिड फार्मूला
            if(leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};


// https://leetcode.com/problems/maximum-product-subarray/description/
// // Pattern: Prefix & Suffix Traversal (Kadane's Variant)
// पहचान (When to use): Array में "Subarray" का "Maximum Product (गुणा)" निकालना हो, और ऐरे में Negative नंबर या Zero मौजूद हों।
// ब्रह्मास्त्र (Core Logic): एक बार Left से Right गुणा करते जाओ, और एक बार Right से Left। अगर रास्ते में कहीं 0 मिल जाए, तो प्रोडक्ट को रीसेट करके वापस 1 कर दो। जो भी सबसे बड़ी वैल्यू मिले, वही आंसर है!


class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int max_ans=nums[0];
      int p=1;
      int s=1;
      for(int i=0;i<nums.size();i++){
      if(p == 0) p=1;
      if(s == 0) s=1;
       p=p*nums[i];
       s=s*nums[nums.size()-1-i];
      max_ans=max(max_ans,max(p,s)) ;
      }
    return max_ans;

    }
};

https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        // Step 1: Left to Right (Prefix भर रहे हैं)
        int prefix = 1;
        for(int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix = prefix * nums[i]; 
        }
        // Step 2: Right to Left (Suffix निकाल कर सीधे ans में गुणा कर रहे हैं)
        int suffix = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * suffix;
            suffix = suffix * nums[i];
        }
        return ans;
    }
};