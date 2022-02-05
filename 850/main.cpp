#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>

int main()
{
    std::vector<std::vector<int>> mat = {{93516,44895,94753,69358},{13141,52454,59740,71232},{22877,11159,85255,61703},{11917,8218,84490,36637},{75914,29447,83941,64384},{22490,71433,64258,74059},{18433,51177,87595,98688},{70854,80720,91838,92304},{46522,49839,48550,94096},{95435,37993,99139,49382},{10618,696,33239,45957},{18854,2818,57522,78807},{61229,36593,76550,41271},{99381,90692,99820,95125}};
    std::vector<int> arr = {};
    int num = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.rectangleArea(mat);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;

    std::cout << output;

    // for (int i: output){
    //     std::cout << i << ' ';
    // }

    // for (auto i: output){
    //     for (int j: i){
    //         std::cout << j << ' ';
    //     }
    //     std::cout << '\n';
    // }

    return 0;
}