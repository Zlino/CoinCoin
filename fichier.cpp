#include "fichier.hpp"
using namespace std;

fichier* fichier::instance = 0;

fichier::fichier()
{}

void fichier::ecrire(string hash_coin, string coin)
{
    std::string tmp = hash_coin.substr(0,7);

    if (hash_coin.substr(0,7) == "ccccccc")
    {
        ofstream fichier_purse;
        fichier_purse.open("purse.txt", ios::out | ios::app);
    
        if(fichier_purse)
        {
            fichier_purse << coin <<endl ;
            fichier_purse.close();
        }
        else
        {
            cerr << "Impossible d'ouvrir le fichier !" << endl;
        }
    }
}

fichier* fichier::getInstance()
{
    if (instance == 0)
    {
        instance = new fichier();
    }

    return instance;
}