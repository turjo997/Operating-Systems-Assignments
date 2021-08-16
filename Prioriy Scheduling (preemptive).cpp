#include<bits/stdc++.h>
using namespace std;

int n ;

int cp[1000] ;
vector<int> prio;
vector<pair<int,int>> wai , cp1 , turn,ar1 , v ,ar , v1;


int fun(int c){
    int mn = INT_MAX , mn1 = INT_MAX;
    int ind =-1;
     sort(ar.begin() , ar.end());

     for(int i = 0 ;i<n ; ++i){
            if(ar[i].first <= c && cp[ar[i].second]!=0){
                mn = min(mn , prio[ar[i].second]);
                if(mn < mn1){
                    ind = ar[i].second ;
                    mn1 = mn;
                }
            }
     }

     return ind;
}


int main()
{
     cout<<"Enter the total process : " <<endl;
     cin >> n;

       cout<<"Enter the arival time : " <<endl;
     for(int i = 0 ; i<n ; ++i){
        int x ; cin >> x;
        ar.push_back(make_pair(x,i));
        ar1.push_back(make_pair(i,x));
    }
    int tot = 0;


      cout<<"Enter the cpu time : " <<endl;
    for(int i = 0 ; i<n ; ++i){
        int y ; cin >> y;
        cp[i] = y;
        cp1.push_back(make_pair(i,y));
        tot+=y;
    }

    cout<<"Enter the priorities : " <<endl;
     for(int i = 0 ; i<n ; ++i){
        int z ; cin >> z;
        prio.push_back(z);
    }

    int ex_cp[10000]= {0};

    int c = 0;
    int ind ;

         while(c != tot){
               ind =  fun(c);
               if(cp[ind]>0){
                cp[ind]--;
                ex_cp[ind]++;
               }
               v.push_back(make_pair(ind , ex_cp[ind]));
               ex_cp[ind] = 0;
               c++;
          }
       
          for(int i = 0 ; i<v.size(); ++i){
                int z = v[i].first;
                int cnt = 1;
                while(z == v[i+1].first && i !=v.size()-1){
                    cnt+=v[i].second + v[i+1].second -1;
                    ++i;
                }
                  v1.push_back(make_pair(z , cnt));
          }
            cout<<endl;

         int w = 0;


         for(int i = 0 ; i<v1.size() ; ++i){
              w+=v1[i].second;
              v1[i].second = w;
         }


          int vis[10000]  = {0};

          sort(ar1.begin() , ar1.end());

          wai.push_back(make_pair(ar[0].second, 0));
          vis[ar[0].second] = 1;


        int sum = 0 , ind1;
         for(int i = 0 ; i< v1.size()-1; ++i){
              sum = v1[i].second;
              ind1 = v1[i+1].first;
              if(vis[ind1] == 0 && i != v.size()-1){
                  wai.push_back(make_pair(ind1 , sum - ar1[ind1].second));
                  vis[ind1] = 1;
              }

         }
         sort(wai.begin() , wai.end());
         cout<<endl;

         int wait[10000] = {0};
         int turn[10000] = {0};


       for(int i = 0 ; i<v1.size() ; ++i){
               int q = v1[i].first; // index
               int q1 = v1[i].second; // value
                 for(int j = i+1 ; j<v1.size() ; ++j){
                        if(q == v1[j].first){
                            wait[q] += abs(q1 - v1[j-1].second);
                            q = v1[j].second + 1;
                        }
                  }
           }
           cout<<endl;
           cout<<endl;


            cout<<"Gantt Chart : ----------------------"<<endl;

            for(int i = 0 ; i<v1.size()-1; ++i){
                cout<< "p"<<v1[i].first+1<<"---";
            }
             cout<< "p"<<v1[v1.size()-1].first+1<<endl;

             for(int i = 0 ; i<v1.size()-1; ++i){
                cout<<v1[i].second<<"---";
            }
             cout<<v1[v1.size()-1].second<<endl;

             cout<<"-----------------------------------"<<endl;





             cout<<endl;
             cout<<endl;

         float tot_waitingtime , tot_turnaroundtime;

         tot_waitingtime = tot_turnaroundtime = 0;


          for(int i = 0; i<n ; ++i){
            wait[i]+=wai[i].second;
            turn[i]+=wait[i] + cp1[i].second;

            tot_waitingtime+=wait[i];
            tot_turnaroundtime+=turn[i];
            cout<<"Process "<<i+1<<" Waiting Time : "<<wait[i]

            <<" Turnaround Time : "<<turn[i]<<endl<<endl;
          }


              cout<<endl;
              cout << "Average Waiting time : " << tot_waitingtime / n <<endl;
              cout<<endl;
              cout << "Average TurnAround time : " << tot_turnaroundtime / n <<endl;


    return 0;
}
