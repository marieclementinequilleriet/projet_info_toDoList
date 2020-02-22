#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Task.h"
#include "analyze.h"


bool deja_utilisateur() ;
std::string fichier(bool dej_util) ;
std::vector<Task> mes_Taches (bool dej_util , std::string fichier) ;
char actions_standards() ;
void afficher_tout(std::vector<Task> liste_Taches)  ;
void afficher_tache(std::vector<Task> liste_Taches)  ;
void modifier_tache(std::vector<Task>& liste_Taches) ;
Task creer_tache(std::vector<Task>& liste_Taches) ;

#endif