






//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
// Pattern: Fixed-size Sliding Window + HashMap (Frequency Map)
// पहचान: Subarray की लम्बाई K फिक्स हो, और सारे एलिमेंट्स Distinct (अलग-अलग) चाहिए हों।
// ब्रह्मास्त्र: K साइज़ की एक खिड़की बनाओ। खिड़की को आगे खिसकाते जाओ—नए वाले को जोड़ो, पुराने वाले को हटाओ। Distinct चेक करने के लिए एक HashMap रखो। जब Map का साइज़ K के बराबर हो, तब अपना Max Sum अपडेट कर लो।

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long currentSum = 0;
        unordered_map<int, int> freq; // एलिमेंट्स की गिनती रखने के लिए
        
        for(int i = 0; i < nums.size(); i++) {
            // 1. नए एलिमेंट को विंडो में अंदर लाओ
            currentSum += nums[i];
            freq[nums[i]]++;
            
            // 2. अगर विंडो K से बड़ी हो गई, तो सबसे पुराने (पीछे वाले) एलिमेंट को बाहर निकालो
            if(i >= k) {
                int outElement = nums[i - k];
                currentSum -= outElement; // सम में से घटाओ
                freq[outElement]--;       // गिनती कम करो
                
                // अगर गिनती 0 हो गई, तो Map से पूरी तरह हटा दो 
                if(freq[outElement] == 0) {
                    freq.erase(outElement);
                }
            }
            // 3. अगर विंडो का साइज़ K पहुँच गया है (i >= k - 1) 
            // और Map का साइज़ भी K है (मतलब कोई डुप्लीकेट नहीं है)
            if(i >= k - 1 && freq.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};


//https://leetcode.com/problems/sliding-window-maximum/description/

















https://leetcode.com/problems/max-consecutive-ones/description/





