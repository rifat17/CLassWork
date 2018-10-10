#include <bits/stdc++.h>
using namespace std;
void cutDP(int pi[],int l)
{
    int dp[l+1][l+1];
    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= l; j++){
            if( i <= j){
                dp[i][j] = max(dp[i-1][j],pi[i-1] + dp[i][j-i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    for(int i = 0; i <= l; i++){
        for(int j = 0; j <=l ; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Max : " << dp[l][l] << endl;

    for(int i = l, j = l; i > 0 ;){
        if(dp[i][j] != 0 && dp[i][j] > dp[i-1][j]){
            cout << i << endl;
            j -= i;
        }
        else i--;
    }
}


int main()
{
    int pi[] = {2,5,9,6,7};
    int n = 5;
    cutDP(pi,n);

    return 0;
}
