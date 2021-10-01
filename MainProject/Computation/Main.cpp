#include"KosenProcon32.hpp"
#include"HTTPCommunication.hpp"


int main()
{
    cv::Mat image = cv::imread("bbb.ppm");
    imshow("", image);
    cv::waitKey();

    

    Procon32::HTTPCommunication http;
    http.GETProblem();

    std::cout << "end" << std::endl;

    return 0;
}