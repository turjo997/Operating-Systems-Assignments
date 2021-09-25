#include<bits/stdc++.h>
using namespace std;

vector<int> str , v , v1 , v2;
vector<int>::iterator it;
int m , n;


void fifo(){
   v.clear();

     int k = 0 , cnt = 0;
     for(int i = 0 ; i<n ; ++i){

            if(i<m){
                v.push_back(str[i]);
                ++cnt;
                 for(int j = 0 ; j<v.size();  ++j){
                 cout<<v[j]<<" " ;
                }
                 cout<<endl;
            }else{
             it = std::find (v.begin(), v.end(), str[i]);

               if(it != v.end()){
                 continue;
               }else{
                ++cnt;
                 v[k] = str[i];
                 ++k;
                  if(k == m) {
                    k = 0;
                 }
                for(int j = 0 ; j<v.size();  ++j){
                 cout<<v[j]<<" " ;
                }
                cout<<endl;
               }
            }
     }
   cout<<"Number of page fault using FIFO Page replacement Algorithm: "<<cnt<<endl;
   cout << "Pages Fault Rate: ";
   cout << ((cnt*1.0/str.size())*100.0) << endl;
}

void optimal(){

     int cnt = 0;

     for(int i = 0 ; i<n ; ++i){

            if(i<m){
                v1.push_back(str[i]);
                ++cnt;
                 for(int j = 0 ; j<v1.size();  ++j){
                 cout<<v1[j]<<" " ;
                }cout<<endl;
            }else{
               it = std::find (v1.begin(), v1.end(), str[i]);

               if(it != v1.end()){
                 continue;
               }else{
                ++cnt;
                int save ,mx = -1 , mx1 = -1;
                for(int j = 0 ; j<v1.size();  ++j){
                     int ind = -1;
                       for(int l = i ; l<n ; ++l){
                         if(v1[j] == str[l]){
                            ind = l;
                            break;
                         }
                       }
                       if(ind == -1){
                        save = v1[j];break;
                       }else{
                       mx = max(mx , ind);
                       if(mx > mx1){
                        save = v[j];
                        mx1 = mx;
                       }
                       }
                }
                 it = std::find (v1.begin(), v1.end(), save);
                 int pos = it - v1.begin();
                 v1[pos] = str[i];

                for(int j = 0 ; j<v1.size();  ++j){
                 cout<<v1[j]<<" " ;
                }
                 cout<<endl;

               }

            }
     }
   cout<<"Number of page fault using Optimal Page replacement Algorithm: "<<cnt<<endl;
   cout << "Pages Fault Rate: ";
   cout << ((cnt*1.0/str.size())*100.0) << endl;
}

void LRU(){

   v.clear();
     int cnt = 0;

     for(int i = 0 ; i<n ; ++i){

            if(i<m){
                v.push_back(str[i]);
                ++cnt;
                 for(int j = 0 ; j<v.size();  ++j){
                 cout<<v[j]<<" " ;
                }cout<<endl;
            }else{
               it = std::find (v.begin(), v.end(), str[i]);

               if(it != v.end()){
                 continue;
               }else{
                ++cnt;
                int mn = INT_MAX , mn1 = INT_MAX;
                int save;
                for(int j = 0 ; j<v.size();  ++j){
                     int ind = INT_MAX;
                       for(int l = i-1 ; l>=0 ; --l){
                         if(v[j] == str[l]){
                            ind = l;
                            break;
                         }
                       }
                       if(ind == INT_MAX){
                        save = v[j];
                        break;
                       }else{
                       mn = min(mn , ind);
                       if(mn < mn1){
                        save = v[j];
                        mn1 = mn;
                       }
                    }
                }
                 it = std::find (v.begin(), v.end(), save);
                 int pos = it - v.begin();
                 v[pos] = str[i];

                for(int j = 0 ; j<v.size();  ++j){
                 cout<<v[j]<<" " ;
                }
                 cout<<endl;

               }

            }
     }
   cout<<"Number of page fault using Least Recently Used Page replacement Algorithm: "<<cnt<<endl;
   cout << "Pages Fault Rate: ";
   cout << ((cnt*1.0/str.size())*100.0) << endl;
}

int main()
{


    int page;
    cout<<"Number of pages : ";

    cin >> page ;

    cout<<"Number of Memory Page Frame:";
    cin >> m;

    cout<<"Number of Page References: ";
    cin >> n;


    for(int i = 0 ; i<n ; ++i){
        int x ; cin >> x;

        str.push_back(x);
    }




   fifo();
   cout<<endl;
   cout<<endl;
   optimal();
   cout<<endl;
   cout<<endl;
   LRU();





    return 0;
}
/*
3 20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

3 22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
*/
