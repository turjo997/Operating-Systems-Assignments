#include<bits/stdc++.h>
using namespace std;


int main(){

     int n ;

     cout<<"Enter the total process: "<<endl;
     cin >> n ;


     vector<int> cp(n) , ari;
     vector<pair<int,int>> ar , v , wai,turn;


     cout<<"Enter the arrival time: "<<endl;
     for(int i = 0 ; i<n ; ++i){
        int x ; cin >> x;
        ar.push_back(make_pair(x,i));
        ari.push_back(x);
     }


     cout<<"Enter the CPU or Burst time: "<<endl;
     for(int i = 0 ;i<n ; ++i){
        cin >> cp[i];
     }


     sort(ar.begin() , ar.end());


     int sum = 0;
      v.push_back(make_pair(sum , ar[0].second));
     for(int i = 0 ; i<n; ++i){
        sum+=cp[ar[i].second];
        if(i<n-1)v.push_back(make_pair(sum , ar[i+1].second));
     }


     float tot_waitingtime , tot_turnaroundtime;

     tot_waitingtime = tot_turnaroundtime = 0;

     for(int i = 0 ; i<n ; ++i){
        wai.push_back(make_pair(v[i].second+1 , v[i].first-ari[v[i].second]));
        turn.push_back(make_pair(v[i].second+1 , wai[i].second+cp[v[i].second]));
        tot_waitingtime+=wai[i].second;
        tot_turnaroundtime+=turn[i].second;
     }

      sort(wai.begin() , wai.end());
      sort(turn.begin() , turn.end());



     for(int i = 0 ; i<n ; ++i){
        cout<<"Process "<<i+1<<" Waiting Time : "<<wai[i].second

        <<" Turnaround Time : "<<turn[i].second<<endl<<endl;;
      }


    cout << "Average Waiting time : " << tot_waitingtime / n <<endl;
    cout<<endl;
    cout << "Average TurnAround time : " << tot_turnaroundtime / n <<endl;




     cout<<endl;


    cout<<"Gantt Chart : -------------------"<<endl;

    for(int i = 0 ; i<v.size()-1; ++i){
        cout<< "p"<<v[i].second+1<<"---";
    }
     cout<< "p"<<v[v.size()-1].second+1<<endl;

    int sum1 = 0;
    for(int i = 1 ; i<v.size(); ++i){

        cout<<v[i].first<<"---";
    }
    cout<<sum<<endl;

    cout<<"-----------------------------------"<<endl;



    return 0;
}

