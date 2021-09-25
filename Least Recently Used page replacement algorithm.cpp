#include<bits/stdc++.h>
using namespace std;

int m ,n;
vector<int> store[1005];

int j = 0;

void fun(deque<int> dq){
    for(int i = 0 ; i<dq.size() ; ++i){
        store[j].push_back(dq[i]);
    }
    ++j;

}

int main(){

    int page;
    cout<<"Number of pages : ";

    cin >> page ;

    cout<<"Number of Memory Page Frame:";
    cin >> m;

    cout<<"Reference String size :";
    cin >> n;


    vector<int> str(n);

    for(int i = 0 ; i<n ; ++i){
        cin >> str[i];
    }
    deque<int> dq;

    int k = 0;

    int c = 0;
    while(k != n){

        if(k<m){
            dq.push_front(str[k]);
            fun(dq);
        }else{
           dq.pop_back();
           dq.push_front(str[k]);
           fun(dq);
        }
        ++k;
    }

    cout<<endl;



    for(int i = 0 ; i<n ; ++i){
            for(int j = 0 ; j<store[i].size(); ++j){
                cout<<store[i][j]<<" ";
            }
            cout<<"   ";
    }


   return 0;
}
/*

3 22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1


*/
