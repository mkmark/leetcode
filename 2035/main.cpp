#include <vector>
#include <iostream>
#include "solution-2.cpp"
#include <chrono>

int main()
{
    std::vector<std::vector<int>> mat = {{}};
    std::vector<int> arr = {297086,-2715219,-3147793,-2798815,-2847810,-3179899,-2958772,-2819139,-2821877,-3118313,-2760393,-2930704,-3114573,-3235278,-2741699,-3048749,-2783335,-2869798,-2858150,-2736107,-2937451,-2985149,-3203694,-2762567,-2679932,-2774493,73350,73124,-2932087,-3082944};
    int num = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.minimumDifference(arr);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;

    std::cout << output << std::endl;

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
