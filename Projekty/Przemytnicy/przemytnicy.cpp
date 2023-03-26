#include "przemytnicy.h"

Graf::Graf()
{

}

void Graf::createVertices(int ile)
{
    for(int i = 0; i < ile; i++)
    {
        vector<edge> vec;
        vertexList.push_back(vec);
    }
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    vertexList[i_Vertex_Index_1].push_back(edge(i_Vertex_Index_1, i_Vertex_Index_2));
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2, int waga)
{
    vertexList[i_Vertex_Index_1].push_back(edge(i_Vertex_Index_1, i_Vertex_Index_2, waga));
}

void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    auto it = vertexList[i_Vertex_Index_1].begin();

    for(int i = 0; i < vertexList[i_Vertex_Index_1].size(); i++)
    {
        edge edge(int i_Vertex_Index_1, int i_Vertex_Index_2);
        if(vertexList[i_Vertex_Index_1][i].vertex_Index2 == i_Vertex_Index_2)
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
        if(vertexList[i_Vertex_Index_1][i].vertex_Index2 == i_Vertex_Index_2)
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
    vector<int> neighbourVec;

    for(int i = 0; i < vertexList[idx].size(); i++)
    {
        neighbourVec.push_back(vertexList[idx][i].vertex_Index2);
    }

    return neighbourVec;
}

void Graf::printNeighbourIndices(int idx)
{
    cout << "Sasiedzi wierzcholka " << idx << ": ";

    if(vertexList[idx].empty())
        cout << "Pusta";

    for(int i = 0; i < vertexList[idx].size(); i++)
    {
        cout << vertexList[idx][i].vertex_Index2 << " waga: " << vertexList[idx][i].waga << ", ";
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

    int first, second, third;

    int count = 0;
    int v;
    
    while(!file.eof())
    {
        if(count == 0)
        {
            file >> first;
            //cout << first << endl;
            v = first;
            wagi = new int[v];
            createVertices(first);
        }

        count++;
        if(count < v + 1)
        {
            file >> first;
            wagi[count - 1] = first;
            //cout << first << endl;
        }

        else if(count == v + 1)
        {
            file >> first;
        }
        
        else
        {
            file >> first >> second >> third;
            //cout << first << " " << second << " " << third << endl;
            addEdge(first-1, second-1, third);
        }
        
    }
    file.close();
}

void Graf::clear()
{
    vertexList.clear();
}

bool mniejsze(edge zm1, edge zm2)
{
    return zm1.vertex_Index2 < zm2.vertex_Index2;
}

void Graf::sortt()
{
    for(int i = 0; i < vertexList.size(); i++)
    {
        sort(vertexList[i].begin(), vertexList[i].end(), mniejsze);
    }
}

void Graf::przemytnicy()
{
    int koszt = 0.5 * wagi[0];

    int size = vertexList.size();

    int dist[size][size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    
    for(int i = 0; i < vertexList.size(); i++)
    {
        for(int j = 0; j < vertexList[i].size(); j++)
        {
            //cout << "Dla " << i << " " << vertexList[i][j].vertex_Index2 << endl;
            dist[i][vertexList[i][j].vertex_Index2] = vertexList[i][j].waga;
        }
    }

    for(int k = 0; k < size; k++)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        cout << endl;
        for(int j = 0; j < size; j++)
        {
            cout << dist[i][j] << "   ";
        }
    }

    cout << endl;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if((dist[0][j] + dist[j][0] + 0.5 * wagi[j]) < koszt)
                koszt = (dist[0][j] + dist[j][0] + 0.5 * wagi[j]);
        }
    }

    cout << "Koszt wynosi: " << koszt << endl;
}


void test()
{
    Graf* G = new Graf();
    G->readFromFile("C:\\Users\\Igor\\Desktop\\c++ progamiki\\algorytmy2\\przemytnicy\\test.txt");
    
    G->sortt();
    G->przemytnicy();
}