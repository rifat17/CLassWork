#include <bits/stdc++.h>
using namespace std;


void PRINT_LCS(vector < vector<char> > b,string A, int i,int j)
{
    if( i == 0 || j == 0 ) return;
    if(b[i-1][j-1] == '*'){
        PRINT_LCS(b,A,i-1,j-1);
        cout << A[i-1];
    }
    else if( b[i-1][j-1] == '^' ){
        PRINT_LCS(b,A,i-1,j);
    }
    else{
        PRINT_LCS(b,A,i,j-1);
    }
}

void LCS_L( string A, string B)
{
    int m = A.length();
    int n = B.length();

    vector< vector<int> > L(m+1, vector<int> (n+1) );

    //cout << L[2][4]; //works! yes!

    vector < vector<char> > b(m, vector<char> (n) );

    //cout << b[1][3]; //works! yes!

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(A[i-1] == B[j-1]){
                L[i][j] = 1+ L[i-1][j-1];
                b[i-1][j-1] = '*'; //* if found
            }
            else if(L[i-1][j] >= L[i][j-1]){
                L[i][j] = L[i-1][j];
                b[i-1][j-1] = '^'; //from up
            }
            else{
                L[i][j] = L[i][j-1];
                b[i-1][j-1] = '<'; //from left
            }
        }
    }

//    for(int i = 0; i < L.size(); i++){
//        for(int j = 0; j < L[i].size(); j++){
//            cout << L[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//    for(int i = 0; i < b.size(); i++){
//        for(int j = 0; j < b[i].size(); j++){
//            cout << b[i][j] << " ";
//        }
//        cout << "\n";
//    }

    cout << "LCS Length is : " << L[m][n] << "\nLCS is : ";

    PRINT_LCS(b,A,m,n);

}

int main()
{
    string s1 = "bd";
    string s2 = "abcd";

    // string s1,s2;
    // cin >> s1 >> s2;


    LCS_L( s1, s2 );


    return 0;
}
