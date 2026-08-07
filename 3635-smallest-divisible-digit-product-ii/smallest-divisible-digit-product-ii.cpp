class Solution {
public:
    int A,B,C,D;
    vector<vector<int>> dp;
    int dax[10],dbx[10],dcx[10],ddx[10];

    void initDigitTables(){
        for(int i=0;i<10;i++) dax[i]=dbx[i]=dcx[i]=ddx[i]=0;
        dax[2]=1;
        dbx[3]=1;
        dax[4]=2;
        dcx[5]=1;
        dax[6]=1; dbx[6]=1;
        ddx[7]=1;
        dax[8]=3;
        dbx[9]=2;
    }

    int minDigitsNeeded(int ra,int rb,int rc,int rd){
        if(ra<0) ra=0; if(ra>A) ra=A;
        if(rb<0) rb=0; if(rb>B) rb=B;
        if(rc<0) rc=0;
        if(rd<0) rd=0;
        return rc+rd+dp[ra][rb];
    }

    string buildSuffix(long long L,int ra,int rb,int rc,int rd){
        string res(L,'1');
        long long pos=0;
        while(pos<L && (ra>0||rb>0||rc>0||rd>0)){
            long long remLen = L-pos-1;
            for(int digit=1; digit<=9; digit++){
                int nra=max(ra-dax[digit],0);
                int nrb=max(rb-dbx[digit],0);
                int nrc=max(rc-dcx[digit],0);
                int nrd=max(rd-ddx[digit],0);
                if(minDigitsNeeded(nra,nrb,nrc,nrd) <= remLen){
                    res[pos]=char('0'+digit);
                    ra=nra;rb=nrb;rc=nrc;rd=nrd;
                    break;
                }
            }
            pos++;
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        long long tt=t;
        A=B=C=D=0;
        while(tt%2==0){tt/=2;A++;}
        while(tt%3==0){tt/=3;B++;}
        while(tt%5==0){tt/=5;C++;}
        while(tt%7==0){tt/=7;D++;}
        if(tt!=1) return "-1";

        initDigitTables();

        dp.assign(A+1, vector<int>(B+1, -1));
        dp[0][0]=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        int digs[6]={2,3,4,6,8,9};
        while(!q.empty()){
            auto [i,j]=q.front(); q.pop();
            for(int k=0;k<6;k++){
                int e=digs[k];
                int ni=min(i+dax[e], A);
                int nj=min(j+dbx[e], B);
                if(dp[ni][nj]==-1){
                    dp[ni][nj]=dp[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }

        int n=num.size();
        vector<int> prefA(n+1,0), prefB(n+1,0), prefC(n+1,0), prefD(n+1,0);
        int firstZero=-1;
        for(int k=0;k<n;k++){
            int digit = num[k]-'0';
            if(digit==0 && firstZero==-1) firstZero=k;
            prefA[k+1]=prefA[k]+dax[digit];
            prefB[k+1]=prefB[k]+dbx[digit];
            prefC[k+1]=prefC[k]+dcx[digit];
            prefD[k+1]=prefD[k]+ddx[digit];
        }

        if(firstZero==-1){
            if(prefA[n]>=A && prefB[n]>=B && prefC[n]>=C && prefD[n]>=D){
                return num;
            }
        }

        int startI = (firstZero==-1)? n-1 : firstZero;

        for(int i=startI;i>=0;i--){
            int L=n-1-i;
            int pa=prefA[i], pb=prefB[i], pc=prefC[i], pd=prefD[i];
            int startE = (num[i]-'0')+1;
            for(int e=startE;e<=9;e++){
                int ca=pa+dax[e], cb=pb+dbx[e], cc=pc+dcx[e], cd=pd+ddx[e];
                int ra=max(A-ca,0), rb=max(B-cb,0), rc=max(C-cc,0), rd=max(D-cd,0);
                if(minDigitsNeeded(ra,rb,rc,rd) <= L){
                    string suffix = buildSuffix(L,ra,rb,rc,rd);
                    return num.substr(0,i) + char('0'+e) + suffix;
                }
            }
        }

        int M = minDigitsNeeded(A,B,C,D);
        long long targetLen = max((long long)(n+1), (long long)M);
        return buildSuffix(targetLen, A,B,C,D);
    }
};