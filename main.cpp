#include <iostream>
#include <vector>
using namespace std;

void addArestas(vector<int> adj[], int u, int v){
    adj[u].push_back(v);//add v a lista de adj de u
    adj[v].push_back(u);//add u a lista de adj de v
}

void imprimir(const vector<int> adj[], int v){
    for (int i = 1; i < v; i++)
    {
        cout << i << " -> ";
        for (int vizinho: adj[i])
        {
            cout << vizinho << " e ";
        }
        cout << endl;
    }
}

/*
1 2_|3 4_ 5
6_ 7_ 8_ 9| 10_
11| 12 13 14_ 15_
16| 17| 18_ 19_ 20
21 22 23 24 25
*/

int main(){
    int v = 26;

    vector<int> adj[v];

    addArestas(adj,21,22);
    addArestas(adj,21,16);
    addArestas(adj,16,11);
    addArestas(adj,22,23);
    addArestas(adj,22,17);
    addArestas(adj,17,12);
    addArestas(adj,23,24);
    addArestas(adj,12,13);
    addArestas(adj,24,25);
    addArestas(adj,13,14);
    addArestas(adj,13,18);
    addArestas(adj,25,20);
    addArestas(adj,18,19);
    addArestas(adj,20,19);
    addArestas(adj,14,15);
    addArestas(adj,14,9);
    addArestas(adj,9,8);
    addArestas(adj,8,3);
    addArestas(adj,8,7);
    addArestas(adj,7,6);
    addArestas(adj,3,4);
    addArestas(adj,6,1);
    addArestas(adj,1,2);
    addArestas(adj,4,5);
    addArestas(adj,5,10);

    imprimir(adj,v);
}