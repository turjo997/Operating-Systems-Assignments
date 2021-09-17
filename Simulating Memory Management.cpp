#include<bits/stdc++.h>
using namespace std;

vector<int> holes , req;

int n , m;

void first_fit(){
    vector<int> holes1 , req1;

    for(int i = 0 ; i<n ; ++i){
        holes1.push_back(holes[i]);
    }
    for(int i = 0 ; i<m ; ++i){
        req1.push_back(req[i]);
    }

    bool done = false;
      for(int i = 0 ; i<m ; ++i){
           int x = req1[i];
           bool ok = false;
           bool ok1 = false;
           int c = 0;
              for(int j = 0 ; j<n ; ++j){
                  int y = holes1[j];
                  ++c;
                    if(x <= y){
                        ok = true;
                        holes1[j]-=x;
                        break;
                    }
                    if(c == n && !ok){
                        ok1 = true;
                        break;
                    }

              }
               if(ok1){
                done = true;
                break;
              }

      }
      if(!done){

        cout<<"NO External Fragmentation !!!"<<endl;
      }else{

        int sum = 0;
        for(int j = 0 ; j<n ; ++j){
            sum+=holes1[j];
        }

         cout<<"External Fragmentation: "<<sum<<endl;
      }

}

void best_fit(){
    vector<int> holes1 , req1;

    for(int i = 0 ; i<n ; ++i){
        holes1.push_back(holes[i]);
    }
    for(int i = 0 ; i<m ; ++i){
        req1.push_back(req[i]);
    }

    bool done = false;
      for(int i = 0 ; i<m ; ++i){
           int x = req1[i];
           bool ok = false;
           bool ok1 = false;
           int c = 0;
           int mn = INT_MAX;
           int mn1 = INT_MAX;

              for(int j = 0 ; j<n ; ++j){
                  int y = holes1[j];
                  ++c;
                  int ind ;
                    if(x <= y){
                      ok = true;
                      mn = min(mn , y-x);

                      if(mn < mn1){
                         ind = j;
                         mn1 = mn;
                      }
                    }

                    if(c == n && ok){
                        holes1[ind] -= x;
                        ok1 = true;
                    }

              }
               if(!ok1){
                done = true;
                break;
              }

      }

    if(!done){

        cout<<"NO External Fragmentation !!!"<<endl;
      }else{

        int sum = 0;
        for(int j = 0 ; j<n ; ++j){
            sum+=holes1[j];
        }

         cout<<"External Fragmentation: "<<sum<<endl;

      }

}


void worst_fit(){
    vector<int> holes1 , req1;

    for(int i = 0 ; i<n ; ++i){
        holes1.push_back(holes[i]);
    }
    for(int i = 0 ; i<m ; ++i){
        req1.push_back(req[i]);
    }
    bool done = false;

      for(int i = 0 ; i<m ; ++i){
           int x = req1[i];
           bool ok = false;
           bool ok1 = false;
           int c = 0;
           int mx = 0;
           int mx1 = 0;

              for(int j = 0 ; j<n ; ++j){
                  int y = holes1[j];
                  ++c;
                  int ind ;
                    if(x <= y){
                      ok = true;
                      mx = max(mx , y-x);

                      if(mx > mx1){
                         ind = j;
                         mx1 = mx;
                      }
                    }
                    if(c == n && ok){
                        holes1[ind] -= x;
                        ok1 = true;
                    }

              }
               if(!ok1){
                done = true;
                break;
              }

      }

         if(!done){

        cout<<"NO External Fragmentation !!!"<<endl;
      }else{

        int sum = 0;
        for(int j = 0 ; j<n ; ++j){
            sum+=holes1[j];
        }

         cout<<"External Fragmentation: "<<sum<<endl;

      }
}


int main(){

    cin >> n >> m;

    cout<<"Memory Holes : "<<endl;
    for(int i = 0 ; i<n ; ++i){
        int x ; cin >> x;

        holes.push_back(x);
    }

    cout<<"Memory Requests : "<<endl;

    for(int i = 0 ; i<m ; ++i){
        int x ; cin >> x;

        req.push_back(x);
    }

    cout<<endl;
    cout<<"First Fit : "<<endl; first_fit();

    cout<<endl;

    cout<<"Best Fit : "<<endl;  best_fit();

    cout<<endl;

    cout<<"Worst Fit : "<<endl;  worst_fit();







  return 0 ;
}

/*

5 10
50 200 70 115 15
100 10 35 15 23 6 25 55 88 40

*/
