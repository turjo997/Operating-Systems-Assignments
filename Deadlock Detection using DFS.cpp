#include<bits/stdc++.h>
using namespace std;


int nodes, edges;
vector <int> graph[10000];
int visited[10000];

vector<char> cycle;

int par[10000];
int stack_[10000];

char ch[10000];

map<char , int> mp;
map<char , int> :: iterator it;
bool ok = false;

void print(int temp , int y){

       char ch1,ch2;

       ch1 = ch[temp];
       ch2 = ch[y];
       cycle.clear();

       cycle.push_back(ch2);

       while(temp!=y){
           cycle.push_back(ch[temp]);
           temp = par[temp] ;
       }

       cycle.push_back(ch2);


       for(int i = cycle.size() - 1 ; i>=0 ; --i){
         cout<<cycle[i]<<" ";
       }
       cout<<endl;

      cycle.clear();

}
void dfs(int src){

   if(!visited[src]){

        visited[src] = 1;
        stack_[src] = 1;

        for(int i=0; i<graph[src].size(); i++)
        {
            int next = graph[src][i];

            if(visited[next] == 0){
                par[next] = src;
                dfs(next);
            }
            else if(stack_[next])
            {
                ok = true;
                cout<<"Deadlock Detected Among nodes: ";
                print(src,next);
            }
        }
    }


    stack_[src] = 0;

    visited[src] = 2;
}

void fun(){

     memset(visited , 0 , sizeof(visited));
     memset(par , 0 , sizeof(par));
     memset(stack_, 0 , sizeof(stack_));

       for(int i = 1 ; i<=nodes ; ++i){
       if(visited[i] == 0){
        dfs(i);
        par[i] = i;

        }
    }
    if(!ok){
        cout<<"No Cycle Exist"<<endl;
    }
}

int main()
{

    cout<<"Enter the number of nodes: "<<endl;
    cin >> nodes;


    for(int i = 1 ; i<=nodes ; ++i){
        cin >> ch[i];
        mp[ch[i]] = i;
    }

    cout<<"Enter the number of Edges: "<<endl;
    cin >> edges;

    for (int i = 0; i < edges; i++){
        char u, v;
        cin >> u >> v;
        graph[mp[u]].push_back(mp[v]);
    }


   fun();


    return 0;
}


/*


9 
1 2 3 4 5 6 7 8 9
9
1 2
2 3
3 4
3 6
4 5
7 2
7 8
9 7
8 9



4
1 2 3 4
5
1 2
2 4
4 3
2 3
3 1



9 
1 2 3 4 5 6 7 8 9
11
1 2
1 4
2 3
6 2
3 6
4 5
5 1
5 8
7 4
8 7
8 9




3
A B C
4
A B
B A
B C
C A



13
R A C S D T B E F U V W G
13
R A
A S
C S
W F
F S
D S
U D
G U
V G
E V
D T
B T
T E
*/

