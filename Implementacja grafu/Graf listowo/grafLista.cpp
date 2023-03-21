#include "grafLista.h"

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

    int first, second;

    int count = 0;

    while(!file.eof())
    {
        if(count == 0)
        {
            file >> first;
            cout << first << endl;
            createVertices(first);
            count++;
        }

        file >> first >> second;
        addEdge(first, second);
    }

    file.close();
}

void Graf::clear()
{
    vertexList.clear();
}

void test1()
{
    Graf* G = new Graf();    
    G->createVertices(10);
    G->addEdge(1, 2);
    G->addEdge(2, 3);
    G->addEdge(1, 5);
    std::cout << G->vertexDegree(1)<<"\n";
    std::cout << G->vertexDegree(8) << "\n";
    G->printNeighbourIndices(1);
    G->printNeighbourIndices(1);
    std::cout << G->checkEdge(1, 2)<<"\n";
    G->removeEdge(1, 2);
    G->printNeighbourIndices(1);
    std::cout << G->checkEdge(1, 2) << "\n\n\n\n\n";   
}

void test2()
{
    Graf* G = new Graf();
    G->readFromFile("C:\\Users\\igor0\\Documents\\C++ pograms\\algorytmy2\\grafLista\\Graf1.txt");
    G->printNeighbourIndices(1);
    std::cout << G->getNumberOfEdges() << endl;
}