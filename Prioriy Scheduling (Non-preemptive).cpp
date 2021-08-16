
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p ,x = 0, save=0;

    cout<<"Enter the number of process: "<<endl;
    cin >> p;

    vector<int> avt(p) , ct(p) , pr(p);
    vector<pair<int,int>>  v , wai , turn,turn1;

    cout<<"Enter the CPU times "<<endl;
    for(int i = 0 ; i<p ; ++i){
        cin >> ct[i];
    }

    cout<<"Enter the Arrival times "<<endl;
      for(int i = 0 ; i<p ; ++i){
        cin >> avt[i];
        if(avt[i] == 0) {
            save = i;
        }
    }

    cout<<"Enter the Priority values "<<endl;
    for(int i = 0 ; i<p ; ++i){
        cin >> pr[i];
    }

    int y = ct[save];

    int t = p-1;
    int ct_bool[p+10] = {0};

    v.push_back(make_pair(save , y));


    while(t--){

    int mn = INT_MAX;

    int mn1 = INT_MAX;

    int ind = 0;


    for(int i = 0 ; i<p ; ++i){
         if(avt[i]<=y && i != save && ct_bool[i] == 0){
               mn = min(mn , pr[i]);

               if(mn < mn1){
                 ind = i;
                 mn1 = mn;

               }
         }
    }
       ct_bool[ind] = 1;
       v.push_back(make_pair(ind , ct[ind]));
       y+=ct[ind];

    }


      wai.push_back(make_pair(save, 0));
      turn.push_back(make_pair(save , ct[save]));


      int x1 = 0;
     for(int i = 0 ; i<p-1 ; ++i){

         x+=v[i].second;
         wai.push_back(make_pair(v[i+1].first , x - avt[v[i+1].first]));
         turn.push_back(make_pair(v[i+1].first , wai[i+1].second + ct[v[i+1].first]));
    }
    x+=v[p-1].second;


    sort(wai.begin() , wai.end());
    sort(turn.begin() , turn.end());

    cout<<endl;


     float tot_waitingtime , tot_turnaroundtime;

     tot_waitingtime = tot_turnaroundtime = 0;

     for(int i = 0 ; i<p ; ++i){
         tot_waitingtime+=wai[i].second;
         tot_turnaroundtime+=turn[i].second;
     }
    for(int i = 0 ; i<p ; ++i){
        cout<<"Process "<<i+1<<" Waiting Time : "<<wai[i].second

        <<" Turnaround Time : "<<turn[i].second<<endl<<endl;
    }


    cout << "Average Waiting time : " << tot_waitingtime / p <<endl;
     cout<<endl;
    cout << "Average TurnAround time : " << tot_turnaroundtime / p <<endl;

    cout<<endl;


    cout<<"Gantt Chart : -------------------"<<endl;

    for(int i = 0 ; i<v.size()-1; ++i){
        cout<< "p"<<v[i].first+1<<"---";
    }
     cout<< "p"<<v[v.size()-1].first+1<<endl;

    int sum = 0;
    for(int i = 0 ; i<v.size()-1; ++i){
        sum+=v[i].second;
        cout<<sum<<"---";
    }
    cout<<sum+v[v.size()-1].second<<endl;

    cout<<"-----------------------------------"<<endl;

    return 0;
}
