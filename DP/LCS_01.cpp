#include <bits/stdc++.h>
using namespace std;

void LCS(string a,string b)
{
    int lcs[a.size()+1][b.size()+1];
    char B[a.size() +1][b.size()+1];
    memset(lcs,0,sizeof(lcs));
    memset(B,'-',sizeof(B));

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if( a[i - 1] == b[j - 1]){ //String is 0-indexed
                lcs[i][j] = 1 + lcs[i-1][j-1];
                B[i][j] = '~';
            }
            else if(lcs[i-1][j] >= lcs[i][j-1]){
                lcs[i][j] = lcs[i-1][j];
                B[i][j] = '^';
            }
            else{
                lcs[i][j] = lcs[i][j-1];
                B[i][j] = '<';
            }
        }
    }

    for(int i = 0; i <= a.size(); i++){ //DP Table for counting length
        for(int j = 0; j <= b.size(); j++){
            cout << lcs[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\n";

    for(int i = 0; i <= a.size(); i++){ //DP table tracking LCS
        for(int j = 0; j <= b.size(); j++){
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\n";
    string x = "";

    for(int i = a.size(),j = b.size(); i > 0;){
            if(B[i][j] == '~'){
//                i--;
//                j--;
                //cout << a[i-1] << ' ';
                x += a[i-1];
                i--;
                j--;
            }
            else if(B[i][j] == '^') i--;
            else j--;
    }

    cout << x << endl;

}

//void PRINT_LCS(char *b,string a,int i,int j)
//{
//    if(i == 0 || b == 0) return;
//
//    if(b[i][j] == '~'){
//        PRINT_LCS(b,a,i-1,j-1);
//        cout << a[i];
//    }
//    else if(b[i][j] == '^') PRINT_LCS(b,a,i-1,j);
//    else PRINT_LCS(b,a,i,j-1);
//}


int main()
{
//    string s1 = "bd";
//    string s2 = "abcd";

    string s1 = "STONE";
    string s2 = "LONGEST";
    LCS(s1,s2);

    return 0;
}
