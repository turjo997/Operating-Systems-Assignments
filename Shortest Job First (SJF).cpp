
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p ,x = 0, save=0;

    cout<<"Enter the number of process: "<<endl;
    cin >> p;

    vector<int> avt(p) , ct(p);
    vector<pair<int,int>>  v , v1 , v2;

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

    int y = ct[save];

    int t = p-1;
    int ct_bool[p+10] = {0};

    v.push_back(make_pair(save , y));


    while(t--){

    int mn = INT_MAX;

    int mn1 = INT_MAX;

    int ind = 0;


    for(int i = 0 ; i<p ; ++i){
         if(avt[i]<y && i != save && ct_bool[i] == 0){
               mn = min(mn , ct[i]);

               if(mn < mn1){
                 ind = i;
                 mn1 = mn;
               }
         }
    }
       ct_bool[ind] = 1;
       v.push_back(make_pair(ind , ct[ind]));
       y+=mn1;

    }


      v1.push_back(make_pair(save, 0));
      v2.push_back(make_pair(save , ct[save]));


     for(int i = 0 ; i<p-1 ; ++i){

         x+=v[i].second;

         v1.push_back(make_pair(v[i+1].first , x - avt[v[i+1].first]));
         v2.push_back(make_pair(v[i+1].first , v1[i+1].second + ct[v[i+1].first]));

    }

    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());



    cout<<endl;


     float tot_waitingtime , tot_turnaroundtime;

     tot_waitingtime = tot_turnaroundtime = 0;

     for(int i = 0 ; i<p ; ++i){
         tot_waitingtime+=v1[i].second;
         tot_turnaroundtime+=v2[i].second;
     }
    for(int i = 0 ; i<p ; ++i){
        cout<<"Process "<<i+1<<" Waiting Time : "<<v1[i].second

        <<" Turnaround Time : "<<v2[i].second<<endl<<endl;;
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
