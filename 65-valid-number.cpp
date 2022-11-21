class Solution {
public:
    //valid number
    //(sign)[A.B](e/E (int))
    bool NumOrDot(char c){
        if(c>='0'&&c<='9'||c=='.') return true;
        else return false;
    }
    bool isNumber(string s) {
        auto p=s.begin();
        if(*p=='+'||*p=='-') p++;
        int cntDot=0;
        int cntNum=0;
        while(p<s.end()&&NumOrDot(*p)){
            if(*p=='.') cntDot++;
            else cntNum++;
            p++;
        }
        if(cntDot>=2||cntNum==0){
            return false;
        }
        if(p<s.end()){
            if((*p)!='e'&&(*p)!='E'){
                return false;
            }
            //p = e/E
            p++;
            if(*p=='+'||*p=='-') p++;
            cntDot=0;
            cntNum=0;
            while(p<s.end()&&NumOrDot(*p)){
                if(*p=='.') cntDot++;
                else cntNum++;
                p++;
            }
            if(cntDot>0||cntNum==0) return false;
        }
        if(p==s.end()) return true;
        else return false;
    }
};
