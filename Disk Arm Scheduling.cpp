#include<bits/stdc++.h>
using namespace std;
int heads , req , pos;


void FCFS(vector<int> request){

    int sum = 0;
    cout<<pos<<"-> ";
    for(int i = 0 ; i<req ; ++i){
            if(i == 0){
                sum +=abs(pos - request[i]);
            }else{
                sum += abs(request[i-1] - request[i]);
            }

            if(i<req-1){
                cout<<request[i]<<"-> ";
            }
    }
    cout<<request[req-1]<<endl;

    cout<<endl;

    cout<<"Total cylinder movement: "<<sum<<endl;
}

void SSTF(vector<int> request){

          int flag[req] = {0};

          vector<int> v;
          int cnt = 0;

          while(cnt !=req){

                  int mn = INT_MAX , mn1 = INT_MAX;
                  int ind = -1;
                   for(int i = 0 ; i<req ; ++i){
                        if(flag[i] == 0){
                             mn = min(mn , abs(pos - request[i]));

                             if(mn < mn1){
                               ind  = i;
                               mn1 = mn;
                             }
                        }
                   }
                   v.push_back(request[ind]);
                   flag[ind] = 1;

                   ++cnt;
          }

    int sum = 0;
    cout<<pos<<"-> ";
    for(int i = 0 ; i<req ; ++i){
            if(i == 0){
                sum +=abs(pos - v[i]);
            }else{
                sum += abs(v[i-1] - v[i]);
            }

            if(i<req-1){
                cout<<v[i]<<"-> ";
            }
    }
    cout<<v[req-1]<<endl;

    cout<<endl;

    cout<<"Total cylinder movement: "<<sum<<endl;


}

void CSCAN(vector<int> request){

    vector<int> v,v1;
    sort(request.begin() , request.end());

    v.push_back(pos);

    for(int i = 0 ; i<req ; ++i){
        if(request[i] > pos)
             v.push_back(request[i]);
    }
    v.push_back(heads-1);
    v1.push_back(0);

     for(int i = 0 ; i<req ; ++i){
        if(request[i] < pos)
             v1.push_back(request[i]);
    }


    int sum = 0;
    for(int i = 0 ; i<v.size()-1 ; ++i){

           sum += abs(v[i+1] - v[i]);

            if(i<v.size()-1){
                cout<<v[i]<<"-> ";
            }
    }
    cout<<v[v.size()-1]<<"->";

       for(int i = 0 ; i<v1.size()-1 ; ++i){

           sum += abs(v1[i+1] - v1[i]);

            if(i<v1.size()-1){
                cout<<v1[i]<<"-> ";
            }
    }
    cout<<v1[v1.size()-1];



    cout<<endl;

    cout<<"Total cylinder movement: "<<sum<<endl;


}

int main(){

    cout<<"Number of heads :";
    cin >> heads;


    cout<<"Number of Cylinder Requests :";
    cin >> req;


    cout<<"Current head position :";
    cin >> pos;


    vector<int> request(req);

    cout<<"Cylinder requests :";

    for(int i = 0 ; i<req ; ++i){
        cin >> request[i];
    }


    FCFS(request); cout<<endl;
    SSTF(request); cout<<endl;
    CSCAN(request);




  return 0;
}


/*
200
8
53
98 183 37 122 14 124 65 67


*/
