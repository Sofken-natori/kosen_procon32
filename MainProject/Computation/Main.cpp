#include"KosenProcon32.hpp"
#include"HTTPCommunication.hpp"
#include"AboutProblem.hpp"
#include"Restore.hpp"
#include"GameData.hpp"
#include"Algorithm.hpp"

int main()
{

    Procon32::HTTPCommunication http;
    http.GETProblem();

    Procon32::AboutProblem pp;
    pp.GETProblemInfo();
    pp.WRITEProblemInfo();

    http.POSTAnswer();
    
    //Procon32::Restore restore;
    //restore.RestoreImage();

    //Procon32::Algorithm AA;

    //Procon32::GameData data;

    //while (data.POSTnum <= 10)
    //{
    //    AA.algorithm();
    //}

    Procon32::GameData game;
    game.ShowAll();

    std::cout << "System end" << std::endl;
    
    return 0;
}