#ifndef ANALYZE
#define ANALYZE

#include <iostream>
#include<string>
#include<vector>
#include <fstream>
#include "Date.h"
#include "Task.h"


std::vector<Task> get_tasks(std::string const chemin) ;
void enregistrer(std::vector<Task> listeTaches,std::string const chemin) ;

#endif