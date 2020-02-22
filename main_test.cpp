#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "Task.h"
#include "Date.h"
#include "analyze.h"
#include "action.h"

int main()
{
    std::vector<Task> liste_Taches = get_tasks("utilisateur1.txt") ;
    afficher_tout(liste_Taches) ;
    std::cout << "ok" ;
    enregistrer( liste_Taches , "Mic" ) ;
    std::cout <<"ok2" ;
    return 0 ;
}