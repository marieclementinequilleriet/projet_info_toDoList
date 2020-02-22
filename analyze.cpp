#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Task.h"
#include "Date.h"


std::vector<Task> get_tasks(std::string const chemin)
{

    //on ouvre le fichier dans lequel on a stocké les taches à la dernière sauvegarde
    std::ifstream aLire;
    aLire.open(chemin);
    // on crée un vecteur qui contiendra toutes les taches
    std::vector<Task> liste_Taches(0);

    if (aLire)
    {
        std::string enregistrement;
        bool fini;
        fini = !(std::getline(aLire, enregistrement)); //pas sûre de mon code
        while (!fini)
        {
            std::vector<std::string> attributs(0);
            char c;
            std::string mot = "";
            for (unsigned i = 0; i < enregistrement.size(); i++)
            {
                c = enregistrement[i];
                // '/' marque le changement d'attribut, on le stocke alors dans le vecteur, sinon on engrange les lettres
                if (c == '/')
                {
                    attributs.push_back(mot);
                    mot = "";
                }
                else
                {
                    mot.push_back(c);
                }
            }
            // à ce moment, la ligne a été entièrement lue, tous les attibuts sont stockés
            Task tache = Task();
            tache.set_id(string_to_int(attributs[0]));
            tache.set_title(attributs[1]);
            tache.set_description(attributs[2]);
            tache.set_creation(string_to_Date(attributs[3]));
            tache.set_closure(string_to_Date(attributs[4]));
            tache.set_dueFor(string_to_Date(attributs[5]));
            tache.set_status(attributs[6]);
            tache.set_advancement(string_to_int(attributs[7]));
            tache.set_priority(attributs[8]);
            tache.set_comments(attributs[9]);
            for (int i = 10; i < attributs.size(); i++)
            {
                tache.add_subTask(string_to_int(attributs[i]));
            }
            fini = !(std::getline(aLire, enregistrement));
            liste_Taches.push_back(tache);
        }
        // à ce moment là, le fichier entier a été lu
        aLire.close() ;
    }
    else
    {
        std::cout << "Erreur, le fichier n'est pas ouvert" << std::endl;
    }

    return liste_Taches;
}


void enregistrer(std::vector<Task> listeTaches,std::string const chemin) 
{

    std::ofstream enEcriture (chemin.c_str()) ;
    if (enEcriture)
    {
        for (long unsigned int i = 0 ; i< listeTaches.size() ; i++)
        {   
            std::string tache_en_string = Task_to_string(listeTaches[i]);
            enEcriture<< tache_en_string << "\n" ;
        }
        enEcriture.close() ;
    }
    else
    {
       std::cout<< "Erreur, le fichier n'est pas ouvert"  << std::endl ;
    }
} 