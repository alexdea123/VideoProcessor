#include <iostream>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <chrono>


int main() {
    // new creates a pointer, so we don't say 'new VideoCapture()'
    cv::VideoCapture cap = cv::VideoCapture("sample.avi");
    // alternatively:
    // cv::VideoCapture cap("sample.avi");
    cv::Mat frame;
   
    if(!cap.isOpened()) {
        std::cerr<<"Error opening capture.\n";
        return 1;
    }
    std::cout<<"Success opening capture!\n";

    if(!cap.read(frame)) {
        std::cerr<<"Error reading capture.\n";
        return 1;
    } else {
        std::cout<<"Width: " << frame.cols << " Height: " << frame.rows << "\n";
    }

    int32_t f_counter = 0;
    auto time_1 = std::chrono::steady_clock::now();

    while (cap.read(frame)) {
        f_counter++;
    }
    
    std::cout<<"\n" << f_counter;
    auto time_2 = std::chrono::steady_clock::now();

    std::cout<<time_2 - time_1 << " latency\n";
    std::cout<<"End of Program\n";
    return 0;
}