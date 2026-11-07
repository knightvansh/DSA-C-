
/*
LeetCode पर जब भी तुम Tree का कोई सवाल खोलते हो, तो सबसे बड़ी प्रॉब्लम यह होती है कि LeetCode तुम्हें एक बना-बनाया फंक्शन देता है (Main Function)। तुम उस फंक्शन के नाम और उसके अंदर पास होने वाले वेरिएबल्स (Parameters) को बदल नहीं सकते।

यहीं से पैदा होता है यह फैसला कि: मुझे अपना खुद का एक नया फंक्शन (Helper) बनाना पड़ेगा, या मैं LeetCode वाले फंक्शन से ही काम चला लूँ?

इसे हम 3 साफ हिस्सों में बाँटते हैं। हर हिस्से का "क्यों (Why)" और "कैसे (How)" ध्यान से पढ़ना।

1. THE CALCULATOR (बिना Helper के काम चलाना)
कहाँ लगेगा: जब तुम्हें पूरी ट्री से सिर्फ एक सिंगल जवाब चाहिए (जैसे एक नंबर, या True/False) और वो जवाब सीधे नीचे वाले नोड्स से जुड़कर बन सकता है।
Examples: Height of Tree, Sum of Nodes, Identical Trees, Balanced Tree.
क्यों (Why) यहाँ Helper नहीं लगता?
क्योंकि LeetCode ने जो फंक्शन तुम्हें दिया है, उसकी रिटर्न टाइप (Return Type) तुम्हारे काम के लिए एकदम परफेक्ट है।
अगर सवाल है "पेड़ की ऊंचाई बताओ", तो LeetCode का फंक्शन होगा: int maxDepth(TreeNode* root).
चूँकि तुम्हें जवाब में एक int ही चाहिए, और हर नोड अपने लेफ्ट और राइट से int ही मांगेगा, तो तुम्हें अलग से कुछ बनाने की ज़रूरत ही नहीं है।
कैसे (How) काम करता है?
यह "Bottom-Up" (नीचे से ऊपर) काम करता है।
तुम रूट पर खड़े हो।
तुम सीधा लेफ्ट वाले को कॉल मारते हो: int left = maxDepth(root->left);
तुम सीधा राइट वाले को कॉल मारते हो: int right = maxDepth(root->right);
दोनों के जवाब आते हैं, तुम उन्हें जोड़ते/कम्पेयर करते हो और रिटर्न कर देते हो। कोई एक्स्ट्रा मेमोरी या थैला नहीं चाहिए।

2. THE COLLECTOR (Helper Function बनाना ही पड़ेगा)
कहाँ लगेगा: जब तुम्हें पूरी ट्री में घूमकर बहुत सारी वैल्यूज एक लिस्ट (vector) में इकट्ठी करनी हों, या ट्री में घूमते हुए किसी एक 'ग्लोबल वैल्यू' (Max/Min) को लगातार अपडेट करना हो।
Examples: Pre/In/Post Order Traversals, Diameter of Tree, Right View, Max Path Sum.

क्यों (Why) यहाँ Helper फंक्शन बनाना पड़ता है?
इसे बहुत ध्यान से समझना, यह सबसे बड़ा रीज़न है:
मान लो सवाल In-order Traversal का है। LeetCode तुम्हें देता है: vector<int> inorderTraversal(TreeNode* root).
अगर तुम इसी फंक्शन के अंदर रिकर्शन लगाओगे, तो जब भी यह फंक्शन कॉल होगा (हर नोड के लिए), C++ हर बार एक नया vector बना देगा! तुम्हारे पास 100 नोड्स हैं, तो मेमोरी में 100 अलग-अलग खाली वेक्टर बन जाएंगे। हमें 100 वेक्टर नहीं चाहिए, हमें सिर्फ एक वेक्टर चाहिए जिसमें सारे 100 नोड्स अपनी वैल्यू डालें।
C++ में एक ही वेक्टर सबको कैसे बाँटें?
"Pass by Reference (&)" के जरिए।
लेकिन LeetCode वाले फंक्शन में तो &ans पास करने की जगह ही नहीं है!इसीलिए मजबूरी में हमें अपना खुद का एक फंक्शन (Helper) बनाना पड़ता है: void solve(TreeNode* root, vector<int>& ans). अब यह ans मेमोरी में फिक्स हो गया, और सारे नोड्स इसी एक वेक्टर में डेटा डालेंगे।

Diameter वाले में Helper क्यों लगता है?
क्योंकि Diameter निकालने के लिए हमें हर नोड की Height निकालनी पड़ती है। C++ का फंक्शन एक बार में सिर्फ एक ही चीज़ रिटर्न कर सकता है (Height)। लेकिन हमें Height के साथ-साथ एक 'Max Diameter' भी सेव करते चलना है। 
चूँकि फंक्शन दो चीज़ें रिटर्न नहीं कर सकता, हम एक 'जुगाड़' लगाते हैं: हम Helper में int& maxi पास कर देते हैं। फंक्शन Height रिटर्न करता रहता है, और छुपके-छुपके maxi को अपडेट करता रहता है।
कैसे (How) काम करता है?
LeetCode वाले मेन फंक्शन में एक खाली vector या int maxi = 0 बनाओ।
अपने बनाए Helper फंक्शन को कॉल करो और उसमें उस वेरिएबल को & के साथ पास कर दो।
Helper पूरा काम करेगा और उसे भर देगा।
मेन फंक्शन से उस भरे हुए वेरिएबल को रिटर्न कर दो।

3. THE QUEUE GANG (Recursion की जगह BFS लगाना)
कहाँ लगेगा: जब भी सवाल में ट्री को "Level (मंज़िल)" के हिसाब से, या "View (ऊपर/नीचे/दाएं/बाएं से देखने)" के हिसाब से प्रोसेस करना हो।
Examples: Level Order, Top View, Bottom View, Zig-Zag.

क्यों (Why) यहाँ Recursion / Helper काम नहीं करता?
Recursion का जन्मजात नेचर है DFS (गहराई में जाना)। रिकर्शन हमेशा ट्री में सबसे पहले एकदम नीचे वाले पत्ते (Leaf) तक भागता है, फिर वापस आता है।
अगर तुमसे कोई कहे कि "पहले लेवल 1 के सारे नोड्स बताओ, फिर लेवल 2 के बताओ", तो तुम रिकर्शन से यह काम आसानी से कर ही नहीं सकते! क्योंकि रिकर्शन हॉरिजॉन्टल (आड़ा) नहीं चलता, वो वर्टिकल (सीधा नीचे) चलता है।
हॉरिजॉन्टल चलने के लिए कंप्यूटर साइंस में BFS (Breadth-First Search) बना है, जो कि queue (लाइन) का इस्तेमाल करके चलता है।
कैसे (How) काम करता है?

कोई Helper नहीं बनता। LeetCode वाले मेन फंक्शन में ही काम होता है।
एक queue बनाते हैं। रूट को लाइन में खड़ा करते हैं।
while(!q.empty()) का लूप चलाते हैं।
आगे वाले को बाहर निकालते हैं (pop), उसका डेटा प्रिंट/सेव करते हैं, और उसके लेफ्ट/राइट बच्चों को लाइन के पीछे खड़ा कर देते हैं।

🎯 FINAL SUMMARY (दिमाग में स्कैन करने का तरीका)
जब भी स्क्रीन पर नया सवाल आए, खुद से सिर्फ 3 सवाल पूछना:

क्या मुझे हॉरिजॉन्टल (लेवल-बाय-लेवल) जाना है या व्यू (Top/Bottom) देखना है?
जवाब हाँ: रिकर्शन भूल जाओ। Queue लगाओ। (Category 3)
जवाब ना: अगले सवाल पर जाओ।
क्या मुझे एक ही लिस्ट में बहुत सारा डेटा इकट्ठा करना है, या कोई ग्लोबल Max/Min वेरिएबल हर स्टेप पर अपडेट करना है?
जवाब हाँ: अपना खुद का Helper बनाओ, उसमें & के साथ वेरिएबल पास करो। (Category 2)
जवाब ना: अगले सवाल पर जाओ।
क्या मुझे सिर्फ एक फाइनल नंबर (जैसे सम, ऊंचाई) या True/False चाहिए?
जवाब हाँ: कोई Helper मत बनाओ। सीधे LeetCode के फंक्शन में left और right को कॉल करो और रिटर्न कर दो। (Category 1)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
Problem Name: Binary Tree preorder Traversal
Link: https://leetcode.com/submissions/detail/2181683214/
Pattern: Tree Traversal (Helper Function)
INTUITION: 
- Go deep left, print/store root, go deep right.
- Use a helper function and pass the vector by reference (&) to avoid global variables.

EDGE CASES / BUGS I FACED:
- ALWAYS check `if (root == NULL) return;` first. Missing this causes a 'member access within null pointer' runtime error!
- Check if the platform uses `root->val` (LeetCode) or `root->data` (GFG).

TIME COMPLEXITY: O(N) - visiting every node once.
SPACE COMPLEXITY: O(H) - where H is the height of the tree (recursion stack).
*/
class Solution {
public:
  void solve(TreeNode* root, vector<int> &ans)
  {
   if(root == NULL) {return;}
   ans.push_back(root->val);
   solve(root->left,ans);
    solve(root->right,ans);
  }
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> ans;
      solve(root,ans);//थैले को रेफरेंस से पास कर दिया//
      return ans;  
    }
};


// Problem Name: Binary Tree Inorder Traversal
// Link:https://leetcode.com/submissions/detail/2182923079/
// Pattern: Tree Traversal (Helper Function)

class Solution {
public:
void solve(TreeNode* root, vector<int>&ans){
    if (root == NULL) {
    return;
}
    solve(root->left,ans);
    ans.push_back(root->val);
    solve(root->right,ans);

   }
vector<int> inorderTraversal(TreeNode* root)
{
vector<int> ans;
solve(root,ans);
return ans; 
}
};


 //Left, right, root  - post-order//
class Solution {
public:
     void postorder(TreeNode* root,vector<int>& ans){
      if(root == NULL){
        return;
      }
      postorder(root->left,ans);
      postorder(root->right,ans);
      ans.push_back(root->val);
     }

    vector<int> postorderTraversal(TreeNode* root) {
     vector<int> ans;
     postorder(root,ans);
     return ans;
    }  
  };





 class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>> ans;
       // Edge case: empty tree returns empty result.
       if(root == NULL){
        return ans;
         }
    queue<TreeNode *> q;
    q.push(root);
    
 while(!q.empty()){
    int size=q.size();
    vector<int> level;
    for(int i=0;i<size;i++){
      TreeNode*current=q.front();
        q.pop();
        level.push_back(current->val);
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
            }
     ans.push_back(level);
     
      } 
     
     return ans  ;
    }
    
};

// Time Complexity: O(N) – each node is visited once in an ideal BFS traversal.
// Space Complexity: O(N) – due to the queue storing at most one level of nodes




