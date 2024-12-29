#include<iostream>
using namespace std;

#define MAX 999

class Dijkstras{
public:
    int v;
    int dist[20],path[20];
    int visited[20];
    int src;
    int cm[20][20];
    int cnt=0;

    void read(){
        cout<<"Enter the number of vertices:"<<endl;
        cin>>v;
        cout<<"Enter the cost matrix:"<<endl;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cin>>cm[i][j];
            }
        }
    }

    void init(){
        cout<<"Enter the source"<<endl;
        cin>>src;
        visited[0]=src;
        cnt=1;

        for(int i=0;i<v;i++){
            if(i==src){
                dist[i]=0;
            }else{
                dist[i]=MAX;
            }
        }

        for(int i=0;i<v;i++){
            path[i]=src;
        }
    }

    int getmin(int f1,int f2){
        if(f1<f2){
            return f1;
        }else{
            return f2;
        }
    }

    int findMin(){
        int min=MAX;
        int min_index=0;
        for(int i=0;i<v;i++){
            if(visited[i]==-1 && dist[i]<=min)
            {
                min=dist[i];
                min_index=i;
            }
        }
        return min_index;
    }

    void dijkstra(){
        for(int i=0;i<v-1;i++){
            int u=findMin();
            visited[u]=1;

            for(int v=0;v<this->v;v++){
                if(visited[v]==-1 && cm[u][v] && dist[u]+cm[u][v]<dist[v]){
                    dist[v]=dist[u]+cm[u][v];
                    path[v]=u;
                }
            }
        }
    }
};

int main(){
    Dijkstras dj;
    dj.read();
    dj.init();
    for(int i=0;i<dj.v;i++){
        dj.visited[i]=-1;
    }
    dj.dijkstra();

    cout<<"\nDistance array from source vertex "<<dj.src<<":"<<endl;
    for(int i=0;i<dj.v;i++){
        if(dj.dist[i]==MAX){
            cout<<"Vertex "<<i<<" is unreachable"<<endl;
        }else{
            cout<<"Vertex "<<i<<": "<<dj.dist[i]<<endl;
        }
    }

    return 0;
}
