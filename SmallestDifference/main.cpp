//
//  main.cpp
//  SmallestDifference
//
//  Created by adeeb mohammed on 11/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

/*
    here the time complexity of the algorithm is as follows
    O(nLog(n) + mLog(m))  n->size of first array n->size of second array
    here the above is the time complexity of the sorting algorithm
    the complexity of the the while loop portion is o(m+n) that is not relevant comparing
    to sort time complexity
    Space complexity is o(1)
 */

std::vector<int> smallestDifference(std::vector<int> arrayOne, std::vector<int> arrayTwo) {
    int  idx_1 = 0;
    int  idx_2 = 0;
    
    int  num_1 = 0;
    int  num_2 = 0;
    int  difference = 0;
    std::vector<int> result;
    
    std::sort(arrayOne.begin(),arrayOne.end());
    std::sort(arrayTwo.begin(), arrayTwo.end());
    
    int smallestDifference = INT_MAX;
  
    
    while(idx_1 < arrayOne.size() && idx_2 < arrayTwo.size()){
        num_1 = arrayOne.at(idx_1);
        num_2 = arrayTwo.at(idx_2);
        difference = abs(num_1 - num_2);
        if(difference == 0){
            result = {num_1,num_2};
            break;
        }else if(num_1 < num_2){
            idx_1++;
        }else{
            idx_2++;
        }
        if(smallestDifference > difference){
            smallestDifference = difference;
            result = {num_1,num_2};
        }
    }
    
    return result;
}


int main(int argc, const char * argv[]) {
    auto arrayOne = {-1,5,10,20,28,3};
    auto arrayTwo = {26,134,135,15,17};
    auto result = smallestDifference(arrayOne,arrayTwo);
    for(auto number : result){
        std::cout << number << " ";
    }
    return 0;
}
