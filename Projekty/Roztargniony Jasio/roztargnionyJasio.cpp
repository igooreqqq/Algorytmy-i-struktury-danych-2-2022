#include "roztargnionyJasio.h"

Graf::Graf()
{
    
}

void Graf::createVertices(int ile)
{
    for(int i = 0; i < ile; i++)
    {
        vector<int> vec;
        vertexList.push_back(vec);
    }
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    if(!checkEdge(i_Vertex_Index_1, i_Vertex_Index_2))
        vertexList[i_Vertex_Index_1].push_back(i_Vertex_Index_2);
}

void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    auto it = vertexList[i_Vertex_Index_1].begin();

    for(int i = 0; i < vertexList[i_Vertex_Index_1].size(); i++)
    {
        if(vertexList[i_Vertex_Index_1][i] == i_Vertex_Index_2)
        {
            vertexList[i_Vertex_Index_1].erase(it);
        }
        it++;
    }
}

bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    for(int i = 0; i < vertexList[i_Vertex_Index_1].size(); i++)
    {
        if(vertexList[i_Vertex_Index_1][i] == i_Vertex_Index_2)
        {
            return true;
        }
    }

    return false;
}

int Graf::vertexDegree(int idx)
{
    return vertexList[idx].size();
}

vector<int> Graf::getNeighbourIndices(int idx)
{
    return vertexList[idx];
}

void Graf::printNeighbourIndices(int idx)
{
    cout << "Sasiedzi wierzcholka " << idx << ": ";

    if(vertexList[idx].empty())
        cout << "Pusta";

    for(int i = 0; i < vertexList[idx].size(); i++)
    {
        cout << vertexList[idx][i] << ", ";
    }
    cout << endl;
}

int Graf::getNumberOfEdges()
{
    int count = 0;
    for(int i = 0; i < vertexList.size(); i++)
    {
        count += vertexList[i].size();
    }

    return count;
}

void Graf::readFromFile(string path)
{
    clear();
    fstream file(path, std::ios_base::in);

    int first;

    int count = 0;
    int count1 = 0;

    while(!file.eof())
    {
        if(count == 0)
        {
            file >> first;
            cout << first << endl;
            createVertices(first);
            count++;
        }

        file >> first;
        addEdge(count1, first-1);
        addEdge(first-1, count1);
        count1++;
    }

    file.close();
}

void Graf::clear()
{
    vertexList.clear();
}

void Graf::DFS(int vertex, bool visited[])
{
    visited[vertex] = true;
    vector<int> adjList = vertexList[vertex];

    vector<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
    {
        if (!visited[*i])
        DFS(*i, visited);
    }
}

bool mniejsze(int zm1, int zm2)
{
    return zm1 < zm2;
}

void Graf::sortt()
{
    for(int i = 0; i < vertexList.size(); i++)
    {
        sort(vertexList[i].begin(), vertexList[i].end(), mniejsze);
    }
}

int Graf::roztargnionyJasio()
{
    bool* visited = new bool[vertexList.size()];
    int* rozbite = new int[vertexList.size()];
 
    
    int count = 0;
    for (int v = 0; v < vertexList.size(); v++)
        visited[v] = false;
 
    cout << "Przykladowo nalezy rozbic skarbonki: ";
    for (int v = 0; v < vertexList.size(); v++) {
        if (visited[v] == false) {
            DFS(v, visited);
            count += 1;
            if(v == vertexList.size() - 1)
                cout << ++v << ". ";
            else
                cout << ++v << ", ";
        }
    }
 
    return count;
}

void test2()
{
    Graf* G = new Graf();
    G->readFromFile("C:\\Users\\Igor\\Desktop\\c++ progamiki\\algorytmy2\\skarbonki\\skarbonki.txt");
    G->sortt();
    cout << "Trzeba rozbic co najmniej: " << G -> roztargnionyJasio() << " skarbonek." << endl;
}