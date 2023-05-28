/*
Sem-6 LP-II AI
Practical-1 : Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected graph and develop a recursive algorithm for searching all the vertices of a graph or tree data structure.
*/

#include<iostream>
#include<queue>
using namespace std;

void dfs(int);
void bfs(int);

queue <int> que;

class createGraphTree
{
public:
    static int graphtr[100][100],visited[100];
    static int vertices,start;

    static void tree()
    {
        int vertices,adjacent;
        char ch;
        
        cout<<"How many vertices in your graph or tree : ";
        cin>>(createGraphTree::vertices);

        for(int i=0;i<createGraphTree::vertices;i++)
            for(int j=0;j<createGraphTree::vertices;j++)
                createGraphTree::graphtr[i][j]=0;
        

        for(int i=0;i<createGraphTree::vertices;i++)
        {
            cout<<"How many vertices connected to vertex "<<i<<" : ";
            cin>>vertices;
            for(int j=0;j<vertices;j++)
            {
                cout<<"Enter adjacent vertex of vertex "<<i<<" : ";
                cin>>adjacent;
                graphtr[i][adjacent]=1;
                graphtr[adjacent][i]=1;
            }
        }

        createGraphTree::displaygraph();

        do{
            cout<<"Enter starting vertex : ";
            cin>>createGraphTree::start;

            for(int i=0;i<createGraphTree::vertices;i++)
                createGraphTree::visited[i] = 0;

            cout<<"DFS : ";
            dfs(start);

            for(int i=0;i<createGraphTree::vertices;i++)
                createGraphTree::visited[i] = 0;

            que.push(createGraphTree::start);
            createGraphTree::visited[createGraphTree::start] = 1;
            cout<<"\nBFS : ";
            bfs(createGraphTree::start);
            cout<<"\nDo you want to make again find DFS & BFS with another vertex (y or n) : ";
            cin>>ch;
        }while(ch=='y'||ch=='Y');
    }

    static void displaygraph()
    {
        cout<<"Adjacent Matrix : "<<endl;
        for(int i=0;i<createGraphTree::vertices;i++)
        {   
            for(int j=0;j<createGraphTree::vertices;j++)
                cout<<"   "<<graphtr[i][j];
            
            cout<<endl;
        }
    }
};

int createGraphTree::vertices=0,start;
int createGraphTree::start;
int createGraphTree::graphtr[100][100];
int createGraphTree::visited[100];

void dfs(int start)
{
    cout<<"  "<<start;
    createGraphTree::visited[start] = 1;    
    for(int i=0;i<createGraphTree::vertices;i++)
        if(createGraphTree::graphtr[start][i] == 1 && createGraphTree::visited[i] == 0)
            dfs(i);
}

void bfs(int start)
{
    cout<<"  "<<start;
    if(!que.empty())
        que.pop();
    for(int i=0;i<createGraphTree::vertices;i++)
    {
        if(createGraphTree::graphtr[start][i] == 1 && createGraphTree::visited[i] == 0)
        {
            que.push(i);
            createGraphTree::visited[i] = 1;
        }
    }
    if(!que.empty())
        bfs(que.front());
}   

int main()
{
    char ch;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"\t\t\tWelcome"<<endl;
    cout<<"\t\tGraph & Tree Traversal"<<endl;
    cout<<"----------------------------------------------------------"<<endl;

    do{
        createGraphTree::tree();
        cout<<"\nDo you want to make again one graph or tree(y or n) : ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');

    return 0;
}