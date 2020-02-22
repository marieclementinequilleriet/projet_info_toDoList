#include<iostream>

#include "Task.h"

Task::Task() 
{
    m_id=0  ;
    m_title="" ;
    m_description="" ;
    m_creation= Date();
    m_closure=Date();
    m_dueFor=Date();
    m_status="";
    m_advancement=0;
    m_priority = "";
    m_comments="";
    std::vector<int> sousTache(0) ;
    m_subTask=sousTache ;
}

Task::Task(int id, std::string titre , std::string description , Date creation , Date limite ,Date cloture , std::string statut , 
int avancement , std::string priorite , std::string commentaire , std::vector<int> sousTache) 
{
    m_id=id ;
    m_title=titre ;
    m_description=description ;
    m_creation= creation;
    m_closure=cloture;
    m_dueFor=limite;
    m_status=statut;
    m_advancement=avancement;
    m_priority = priorite;
    m_comments=commentaire;
    m_subTask=sousTache ; 
} 


void Task::set_id (int nvelId)
{
    m_id = nvelId ;
}

void Task::set_title(std::string nveauTitre)
{
    m_title = nveauTitre ;
}

void Task::set_description(std::string nvelleDescr) 
{
    m_description=nvelleDescr ;
}

void Task::set_creation (Date nvelleCreation) 
{
    m_creation=nvelleCreation ;
}

void Task::set_closure(Date nvelleCloture)
{
    m_closure=nvelleCloture ;
}

void Task::set_dueFor (Date nvelleLimite)
{
    m_dueFor=nvelleLimite ;
}

void Task::set_status (std::string nveauStatut)
{
    m_status=nveauStatut ;
}

void Task::set_advancement( int pourcentage) 
{
    m_advancement=pourcentage ;
}

void Task::set_priority (std::string nvellePriorite)
{
    m_priority = nvellePriorite ;
}

void Task::set_comments (std::string nveauCommentaire) 
{
    m_comments=nveauCommentaire ;
}

void Task::add_subTask (int idNvelleSousTache) 
{
    m_subTask.push_back(idNvelleSousTache) ;
}

void Task::del_subTask(int idExSousTache) 
{
    //est-ce que c'est vraiment le truc archi hors programme à utiliser ?
    m_subTask.erase(m_subTask.begin() + idExSousTache) ;
}


int Task::get_id ()
{
    return m_id ;
} ;
std::string Task::get_title () 
{
    return m_title ;
}
std::string Task::get_description() 
{
    return m_description ;
}
Date Task::get_creation () 
{
    return m_creation ;
}
Date Task::get_closure () 
{
    return m_closure ;
}
Date Task::get_dueFor () 
{
    return m_dueFor ;
}
std::string Task::get_status ()
{
    return m_status ;
}
int Task::get_advancement( ) 
{
    return m_advancement ;
}
std::string Task::get_priority ()
{
    return m_priority ;
}
std::string Task::get_comments () 
{
    return m_comments ;
}
std::vector<int> Task::get_subTasks() 
{
    return m_subTask ;
}

void Task::print_task() 
{
    std::cout << "Tâche n° "<< m_id << " : " << m_title << std::endl ;
    std::cout << "Description : "<< m_description << std::endl ;
    std::cout << m_status << " : " << m_advancement <<"% d'avancement" <<std::endl;
    std::cout << "Créé le : " ;
    m_creation.afficher_date();
    std::cout << "A rendre le : " ;
    m_dueFor.afficher_date();
    //on regarde si la tache est terminée
    if (m_closure.getDay()!=0)
    {std::cout << "Fini le : " ;
    m_closure.afficher_date() ;}
    {std::cout << "La tâche n'est pas clôturée" << std::endl ;}
    std::cout << "Priorité : " << m_priority << std::endl ;
    std::cout << m_comments<<std::endl ;
    //affichage des sous taches 
    int nbSousTaches (m_subTask.size());
    if (nbSousTaches == 0)
    { 
        std::cout<< "Pas de sous-tâches" <<std::endl ;
    }
    else
    {
        std::cout << "Sous-tâches à réaliser : " << std::endl ;
        for (int i(0) ; i< nbSousTaches ; i++) 
        { std::cout << m_subTask[i] << std::endl ; }
    }

    
}

void Task::print_subTasks()
{
    int nbSousTaches (m_subTask.size());
    if (nbSousTaches == 0)
    { 
        std::cout<< "Pas de sous-tâches" <<std::endl ;
    }
    else
    {
        std::cout << "Sous-tâches à réaliser : " << std::endl ;
        for (int i(0) ; i< nbSousTaches ; i++) 
        { std::cout << m_subTask[i] << std::endl ; }
    }

}

void Task::end_task() 
{
    m_status="Termine" ;
    m_advancement=100 ;
    set_closure(saisir_date());
}

std::string Task_to_string (Task tache)
{
    std::string res = "" ;
    res = std::to_string(tache.get_id()) +"/" + tache.get_title() +"/" + tache.get_description() +"/" + tache.get_creation().Date_to_string()
    +"/" + tache.get_closure().Date_to_string() +"/" + tache.get_dueFor().Date_to_string() +"/" + tache.get_status() +"/" + 
    std::to_string(tache.get_advancement()) +"/" + tache.get_priority() +"/" + tache.get_comments()
    +"/" + subTask_to_string(tache.get_subTasks())  ;
    return res ;
    
}

std::string subTask_to_string(std::vector<int> sousTache)
{
    std::string res = "" ;
    for(long unsigned int i = 0 ; i<sousTache.size() ; i++)
    {
        res+=(std::to_string(res[i])) ;
        res+=('/');
    }
    return res ;
}

