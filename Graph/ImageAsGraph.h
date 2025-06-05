//
// Created by abdo on 3/23/25.
//

#ifndef IMAGEASGRAPH_H
#define IMAGEASGRAPH_H
#include <vector>
#include <iostream>

struct ImageGraph {

private:

    int left {};
    int right{};
    int bottom {};
    int top{};
    int rows{};
    int cols{};
    std::vector<int> flattenArray;

    std::vector<int> getNeighbors(int index){
        std::vector<int> result;
        int i = index / cols; // Row index
        int j = index % cols; // Column index

        if (j > 0)        result.push_back(flattenArray[index - 1]);  // Left
        if (j < cols - 1) result.push_back(flattenArray[index + 1]);  // Right
        if (i > 0)        result.push_back(flattenArray[index - cols]); // Top
        if (i < rows - 1) result.push_back(flattenArray[index + cols]); // Bottom
        return result;
    }

public:
    ImageGraph(int rows , int cols) {
        this->rows = rows;
        this->cols= cols;
        for (int i = 0 ; i< rows * cols;i++) {
            flattenArray.push_back(i);
        }
    }

    void printNeighbours() {
        for (int i = 0 ;i < rows * cols ;i++ ) {
            std::vector<int> result = getNeighbors(i);
            std::cout << "Node: " << i << " has neighbours: "
            << result[0] << " " <<  result[1] << " " << result[2]
            << " " << result[3] << std::endl;
        }
    }
};



inline void testCase() {
    ImageGraph test(3 , 4);
    test.printNeighbours();
}


#endif //IMAGEASGRAPH_H
