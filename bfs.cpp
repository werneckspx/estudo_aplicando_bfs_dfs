#include "BFS.hpp"

void BFS::printPath(vector<int>& pi, int start, int target) {
    stack<int> path;
    int current = target;
        
    while (current != -1) {
        path.push(current);
        current = pi[current];
    }
        
    cout << "Caminho encontrado: ";
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << endl;
}

void BFS::executar(Grafo& grafo, int inicial, int final) {
    int vertices = grafo.getNumVertices();
    vector<vector<int>>& adj = grafo.getAdjList();

    auto start = chrono::high_resolution_clock::now();
    vector<string> cor(vertices, "BRANCO");
    vector<int> pi(vertices, -1);
    vector<int> d(vertices, numeric_limits<int>::max());
    int iteracao = 0;

    cout << "================================" << endl;
    cout << "INÍCIO DA BUSCA EM LARGURA (BFS)" << endl;
    cout << "================================" << endl;
    cout << "Nó Inicial: " << inicial << endl;
    cout << "Nó Final: " << final << endl;
    cout << "================================" << endl;

    cor[inicial] = "CINZA";
    d[inicial] = 0;
    pi[inicial] = -1;

    queue<int> Q;
    Q.push(inicial);
    bool found = false;

    while (!Q.empty() && !found) {
        iteracao++;
        int u = Q.front();
        Q.pop();

        cout <<endl << "-----------------------------------" << endl;
        cout << "Iteração " << iteracao << ": Analisando nó " << u << endl;
        cout << "-----------------------------------" << endl;
        
        cout << "Estado atual do nó " << u << ":" << endl;
        cout << "  Cor: CINZA" << endl;
        cout << "  Distância da origem: " << d[u] << endl;
        cout << "  Predecessor: " << pi[u] << endl;
        
        cout << endl << "Vizinhos do nó " << u << ":" << endl;
        
        for (int v : adj[u]) {
            cout << endl << "  Explorando vizinho: " << v << endl;
            
            if (cor[v] == "BRANCO") {
                cout << "    Status: NÃO VISITADO" << endl;
                cout << "    Ação: Marcando para exploração" << endl;
                
                cor[v] = "CINZA";
                d[v] = d[u] + 1;
                pi[v] = u;
                Q.push(v);

                cout << "    Detalhes após marcação:" << endl;
                cout << "      Nova cor: CINZA" << endl;
                cout << "      Distância: " << d[v] << endl;
                cout << "      Predecessor: " << u << endl;

                if (v == final) {
                    found = true;
                    cout << endl << "  *** NÓ FINAL ENCONTRADO! ***" << endl;
                    break;
                }
            } else {
                cout << "    Status: JÁ VISITADO (Cor: " 
                          << (cor[v] == "CINZA" ? "CINZA" : "PRETO") << ")" << endl;
            }
        }
        
        cor[u] = "PRETO";
        cout << endl << "Nó " << u << " marcado como PRETO (completamente explorado)" << endl;
    }

    cout << endl << "================================" << endl;
    cout << "RESUMO DA BUSCA" << endl;
    cout << "================================" << endl;

    if (found) {
        cout <<endl<< endl << "Nó " << final << " encontrado!" << endl;
        cout << "Distância do nó " << inicial << " até o nó " << final 
                  << ": " << d[final] << endl;
        
        cout<< endl << "CAMINHO ENCONTRADO:" << endl;
        printPath(pi, inicial, final);
    } else {
        cout << "Não foi possível encontrar um caminho até o nó " << final << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Tempo de execução: " << duration.count() << " ms" << endl;
}