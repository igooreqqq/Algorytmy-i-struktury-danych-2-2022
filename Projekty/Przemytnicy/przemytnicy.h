#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>

#define INF 99999

using namespace std;

struct edge
{
    int vertex_Index1;
    int vertex_Index2;
    float waga;

public:
    edge(int i_Vertex_Index1, int i_Vertex_Index2);
    edge(int i_Vertex_Index_1, int i_Vertex_Index_2, float i_weight); 
};

edge::edge(int i_Vertex_Index1, int i_Vertex_Index2)
{
    vertex_Index1 = i_Vertex_Index1;
    vertex_Index2 = i_Vertex_Index2;
    waga = 0;
}

edge::edge(int i_Vertex_Index_1, int i_Vertex_Index_2, float i_weight)
{
    vertex_Index1 = i_Vertex_Index_1;
    vertex_Index2 = i_Vertex_Index_2;
    waga = i_weight;
}

class Graf
{
    vector<vector<edge>> vertexList;
    void clear();
    int* wagi;
    
public:
    Graf();
    void createVertices(int ile);    
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2); 
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2, int waga); 
    void removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    int vertexDegree(int idx); 
    std::vector<int> getNeighbourIndices(int idx);
    void printNeighbourIndices(int idx);
    int getNumberOfEdges();
    void readFromFile(std::string path);

    void sortt();
    void przemytnicy();
};