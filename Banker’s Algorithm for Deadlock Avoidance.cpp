#include<bits/stdc++.h>
using namespace std;


int main(){

       int p,r;

       cout<<"Enter the no. of processes: "<<endl;
       cin >> p;

       cout<<"Enter the no. of resources: "<<endl;
       cin >> r;


       vector<int> allo[p] , max_[p] , need[p] , tot(r)  , avail , safe;

       int q = 0;
       while(q != p){
            cout<<"Process "<<q+1<<endl;

               for(int j = 0 ; j<r ; ++j){
                    cout<<"Maximum value for resource "<<j+1<<":";
                    int x ; cin >> x;
                    max_[q].push_back(x);
                    cout<<endl;
               }
               for(int j = 0 ; j<r ; ++j){
                    cout<<"Allocated from resource "<<j+1<<":";
                    int x ; cin >> x;
                    allo[q].push_back(x);
                    cout<<endl;
               }

          ++q;
       }


       for(int i = 0 ; i<r ; ++i){
            cout<<"Enter total value of resource : "<<i+1<<" ";
            cin >> tot[i];
            cout<<endl;
       }

      for(int i = 0 ; i<r ; ++i){
           int sum = 0;
           for(int j = 0 ; j<p ; ++j){
               sum+=allo[j][i];
           }
           avail.push_back(tot[i] - sum);
       }



      for(int i = 0 ; i<p; ++i){
           for(int j = 0 ; j<r ; ++j){
               need[i].push_back(max_[i][j] - allo[i][j]);
           }
       }

      int flag[p] = {0};
      int cnt = 0;

      while(cnt != p){
              for(int i = 0 ; i<p; ++i){
                 if(flag[i] == 0){
                     int c = 0 ;
                     for(int j = 0 ; j<r ; ++j){
                          if(avail[j] >= need[i][j]){
                            c++;
                          }else{
                             break;
                          }
                          if(c == r){
                               flag[i] = 1;
                               ++cnt;
                               for(int k = 0 ; k<r ; ++k){
                                  avail[k]+=allo[i][k];
                               }
                              safe.push_back(i+1);
                               i = -1;
                          }
                     }

                   }

               }
      }


      cout<<endl<<endl;


     cout<<"The System is currently in safe state and < ";
      for(int i = 0 ; i<p ; ++i){
        cout<<safe[i]<<" ";
      }
      cout<<" > is the safe sequence.";




   return 0;
}


/*


4 3
1 0 0
5 1 1
2 1 1
0 0 2
3 2 2
6 1 3
3 1 4
4 2 2
9 3 6



5
4
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
3 14 12 12

*/

