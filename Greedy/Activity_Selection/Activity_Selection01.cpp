#include <bits/stdc++.h>
using namespace std;

struct work
{
    int workID;
    int s; //to hold staring time
    int f; //to hold finishing time
};

/*
1 1 3
2 0 4
3 1 2
4 4 6
5 2 9
6 5 8
7 3 5
8 4 5
*/

vector<work> select_activity( vector<work> activities)
{
    vector<work> selected_activities;
    selected_activities.push_back(activities[0]);
    int k = 0;


    for(int i = 1; i < activities.size(); i++){
        if( activities[i].s > activities[k].f ){
            selected_activities.push_back(activities[i]);
            k = i;
        }
    }

    return selected_activities;


}

bool cmp(work a, work b)
{
    return (a.f < b.f);
}

int main()
{

    freopen("Activity_Selection01.txt" , "r" , stdin );
    vector<work> activity;

    int s,f,id;
    work x;

    while( scanf("%d%d%d",&id,&s,&f) != EOF ){
        x.workID = id;
        x.s = s;
        x.f = f;
        activity.push_back(x);
    }

    sort(activity.begin(),activity.end(),cmp);

    vector<work> activity1 = select_activity( activity );

    cout << "WOrkID : " << " Starting Time : " << " Ending Time : " << " \n";

    for(int i = 0; i < activity1.size(); i++){
        cout << setw (9) << activity1[i].workID << setw (19) << activity1[i].s << setw (19) << activity1[i].f << " \n";
    }

    return 0;
}
