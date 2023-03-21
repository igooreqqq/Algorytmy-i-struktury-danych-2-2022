#include "grafMacierz.h"

Graf::Graf()
{
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < 1000; j++)
        {
            matrix[i][j] = false;
        }
    }
}

void Graf::createVertices(int ile)
{
    /*for(int i = 0; i < ile; i++)
    {
        matrix[i][i] = true;
    }*/

    this->numberOfVertices = ile;
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    matrix[i_Vertex_Index_1][i_Vertex_Index_2] = true;
}

void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    matrix[i_Vertex_Index_1][i_Vertex_Index_2] = false;
}

bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    if(matrix[i_Vertex_Index_1][i_Vertex_Index_2] == true)
        return true;

    return false;
}

int Graf::vertexDegree(int idx)
{
    int count = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(matrix[idx][i] == true && idx != i)
            count++;
    }

    return count;
}

vector<int> Graf::getNeighbourIndices(int idx)
{
    vector<int> vec;

    for(int i = 0; i < 1000; i++)
    {
        if(matrix[idx][i] == true && idx != i)
            vec.push_back(i);
    }

    return vec;
}

void Graf::printNeighbourIndices(int idx)
{
    vector<int> vec = getNeighbourIndices(idx);
    cout << "Sasiedzi: ";
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ", ";
    }

    cout << "\n";
}

int Graf::getNumberOfEdges()
{
    int count = 0;

    for(int i = 0; i < numberOfVertices; i++)
    {
        for(int j = 0; j < numberOfVertices; j++)
        {
            if(matrix[i][j] == true /*& i != j*/)
                count++;
        }
    }

    return count;
}

void Graf::clear()
{
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < 1000; j++)
        {
            matrix[i][j] = false;
        }
    }
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
    G->readFromFile("C:\\Users\\igor0\\Documents\\C++ pograms\\algorytmy2\\grafMacierz\\Graf1.txt");
    G->printNeighbourIndices(1);
    std::cout << G->getNumberOfEdges();
}