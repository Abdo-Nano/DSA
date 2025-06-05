//
// Created by abdo on 3/23/25.
//

#ifndef ADJACENCYBASEDREPR_H
#define ADJACENCYBASEDREPR_H
#include <iostream>
#include <vector>
#include <algorithm>


class Node{
public:
    std::string from;
    std::string to;
    int cost{};
    std::vector<std::string> edges;

    Node(const std::string & from , const std::string & to , int cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
        this->edges.push_back(to);
    }
    bool operator < (const Node& another)const  {
        return this->from < another.from;
    }
};

typedef std::vector<Node> Graph;

bool compareByToThenCost(const Node & first , const Node& second) {
    if (first.to == second.to) {
        return first.cost < second.cost;
    }
    return first.to < second.to;
}


void testCases() {

    std::vector<Node> arr;
    Node first{"cairo" , "giza" , 10};
    Node second{"monfia" , "assiot" , 10};
    Node third{"cairo" , "elbehera" , 10};
    Node fourth{"egypt" , "outside" , 10};

    arr.push_back(fourth);
    arr.push_back(second);
    arr.push_back(first);
    arr.push_back(third);

    std::sort(arr.begin() , arr.end() );

    for (const Node& node : arr) {
        std::cout << "From: " << node.from
        << " To: " << node.to << " cost: "
        << node.cost << std::endl;
    }
}


#endif //ADJACENCYBASEDREPR_H
