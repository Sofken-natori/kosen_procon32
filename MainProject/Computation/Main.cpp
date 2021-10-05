#include"KosenProcon32.hpp"
#include"HTTPCommunication.hpp"
#include"AboutProblem.hpp"
#include"Restore.hpp"

int main()
{

    //Procon32::HTTPCommunication http;
    //http.GETProblem();

    Procon32::AboutProblem pp;
    pp.GETProblemInfo();
    pp.WRITEProblemInfo();

   // http.POSTAnswer();
    
    Procon32::Restore restore;
    restore.RestoreImage();

    std::cout << "System end" << std::endl;

    return 0;
}