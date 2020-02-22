#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "Task.h"
#include "Date.h"
#include "analyze.h"
#include "action.h"


int main ()
{
    bool utilisateur ;
    std::string chemin ;
    std::vector<Task> liste_Taches ;
    utilisateur = deja_utilisateur() ;
    system("clear") ;
    chemin = fichier(utilisateur) ;
    system("clear") ;
    liste_Taches = mes_Taches(utilisateur,chemin) ;
    char action = 'Z';
    Task tache = Task() ;
    do
    {
        action = actions_standards() ;
        switch (action)
        {
        case 'C':
            tache = creer_tache(liste_Taches) ;
            liste_Taches.push_back(tache) ;
            break;
        case 'M' :
            if (liste_Taches.size() !=0)
            {
                modifier_tache(liste_Taches) ;
            }
            else
            {
                std::cout << "Vous n'avez pas de taches enregistrées" << std::endl ;
            }
            break;
        case 'A' :
            afficher_tout(liste_Taches) ;
            break ;
        case 'D' :
            afficher_tache(liste_Taches) ;
            break ;
        case 'Q' :
            enregistrer(liste_Taches, chemin) ;
            system("clear") ;
            return 0;
            break;
        
        default:
            std::cout << "Cette instruction n'existe pas" << std::endl ;
            break;
        }
    }
    while (action != 'Q') ;
    return 0;
}  


