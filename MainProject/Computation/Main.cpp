#include"KosenProcon32.hpp"
#include"HTTPCommunication.hpp"
#include"AboutProblem.hpp"


int main()
{
    //cv::Mat image = cv::imread("bbb.ppm");
    //imshow("", image);
    //cv::waitKey(0);

    

    //Procon32::HTTPCommunication http;
    //http.GETProblem();

    //Procon32::AboutProblem pp;
    //pp.GETProblemInfo();
    //pp.WRITEProblemInfo();

    Procon32::HTTPCommunication http;
    http.POSTAnswer();

    std::cout << "System end" << std::endl;

    return 0;
}