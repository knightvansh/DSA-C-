//
// M × N matrix दिया हुआ है, जिसमें M और N हमारे number of rows and columns को represent कर रहे हैं। उसके बाद next line में हमें '*' और '.' दिया रहेगा, जो बताएगा कि '*' का मतलब है कि उस particular cell में हमारा पत्थर पड़ा हुआ है, और '.' का मतलब है कि पत्थर उस cell में नहीं पड़ा है।

// मान लो M × N की value 4 × 4 है, तो हमें 4 lines में यह पूरा दिया रहेगा कि कैसे-कैसे उसमें पत्थर भरना है, '*' और '.' करके। फिर उसके बाद उसमें number of instructions दिया हुआ है, जो बताएगा कि कितने instructions uncle हमें देंगे। उसके बाद एक final है कि हमें पत्थर को right घुमाना है या left घुमाना है। यह हमारा input है।



// अब हमारी condition यह है कि सबसे पहले सबसे पहले, जो box दिया हुआ है, पत्थर वाला, उसमें हमें gravity की मदद से जो पत्थर ऊपर रखे हुए हैं, यानी कि जो हवा में लटके हैं, उनको नीचे की ओर गिरा देना है। मतलब कि कोई पत्थर हवा में नहीं रहेगा, जो box में सबसे नीचे आ जाए। ऐसी situation करनी है। इसके लिए एक function लिखना है, gravity वाला। 
// उसके बाद उसको जो given instruction रहेगा, उसके हिसाब से right या left rotate करना है। हमारे example में अभी दिया हुआ है right rotate करना है, तो right कर देंगे। उसके बाद फिर से gravity को function apply करेंगे, जिससे जो पत्थर हवा में लटका है, उसको वापस नीचे की ओर box में गिरा देंगे। //
#include <bits/stdc++.h>
using namespace  std;

vector<string,string> box;
int m = box.size();  
int n = box[0].size(); 

int main() {
    int m, n;
    cin >> m >> n; 
    vector<string> box(m);
    for (int i = 0; i < m; i++) {
        cin >> box[i];
    }ह
    applyGravity(box);
    box = rotateRight(box);      //Right और left rotate करने के लिए //
    applyGravity(box);        //घुमाने के बाद जो पत्थर दीवार पर गए, उन्हें फिर नीचे गिराया//

    // 3. आउटपुट प्रिंट कर दिया
    for (int i = 0; i < box.size(); i++) {
        cout << box[i] << endl;
    }

    return 0;
}