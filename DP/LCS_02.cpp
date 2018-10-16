#include <bits/stdc++.h>
using namespace std;

void LCS_length( string a, string b )
{
    int m = a.length();
    int n = b.length();

    int LCSlen[m+1][n+1];
    //char lcs[m+1][n+1];

    memset(LCSlen,0,sizeof(LCSlen));
    //memset(lcs,'-',sizeof(lcs));

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if( a[i-1] == b[j-1] ){
                LCSlen[i][j] = 1+ LCSlen[i-1][j-1];
            }
            else{
                LCSlen[i][j] = max(LCSlen[i-1][j],LCSlen[i][j-1]);
            }
        }
    }

//    for(int i = 0; i <= m; i++){ //DP Table for counting length
//        for(int j = 0; j <= n; j++){
//            cout << LCSlen[i][j] << " ";
//        }
//        cout << endl;
//    }


    int index = LCSlen[m][n];
    char lcs[index];
    lcs[index] = '\0';

    int i = m,j = n;

    while( i > 0 && j > 0 ){
        if(a[i-1] == b[j-1]){
            lcs[index-1] = a[i-1];
            i--;
            j--;
            index--;
        }
        else if(LCSlen[i-1][j] > LCSlen[i][j-1]) i--;
        else j--;
    }
    cout << "String A = " << a << "\nString B = " << b << "\nLCS is : " << lcs << endl << "Length of LCS : " << LCSlen[m][n];



}

int main()
{
    string A = "stone";
    string B = "longest";

    LCS_length(A,B);

    return 0;
}
