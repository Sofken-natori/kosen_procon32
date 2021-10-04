#include"KosenProcon32.hpp"
#include"HTTPCommunication.hpp"
#include"AboutProblem.hpp"
#include"GameData.hpp"


int main()
{
    //cv::Mat image = cv::imread("bbb.ppm");
    //imshow("", image);
    //cv::waitKey(0);

    

    Procon32::HTTPCommunication http;
    http.GETProblem();

    Procon32::AboutProblem pp;
    pp.GETProblemInfo();
    pp.WRITEProblemInfo();

   // http.POSTAnswer();

    Procon32::GameData data;
    data.ShowAll();

    std::cout << "System end" << std::endl;

    return 0;
}