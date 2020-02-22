#ifndef TASK
#define TASK

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"

class Task 
{
    public :
    Task() ;
    Task(int id, std::string titre , std::string description , Date creation , Date cloture , Date limite , std::string statut , 
    int avancement , std::string priorite , std::string commentaire , std::vector<int> sousTache) ; 
    void set_id (int nvelId) ;
    void set_title (std::string nveauTitre) ;
    void set_description(std::string nvelleDescr) ;
    void set_creation (Date nvelleCreation) ;
    void set_closure (Date nvelleCloture) ;
    void set_dueFor (Date nvelleLimite) ;
    void set_status (std::string nveauStatut);
    void set_advancement( int pourcentage) ;
    void set_priority (std::string nvellePriorite);
    void set_comments (std::string nveauCommentaire) ;
    void add_subTask (int idNvelleSousTache) ;
    void del_subTask(int idExSousTache) ;

    int get_id () ;
    std::string get_title () ;
    std::string get_description() ;
    Date get_creation () ;
    Date get_closure () ;
    Date get_dueFor () ;
    std::string get_status ();
    int get_advancement( ) ;
    std::string get_priority ();
    std::string get_comments () ;
    std::vector<int> get_subTasks() ;

    void print_task() ;
    void print_subTasks() ;
    void end_task() ;
    

    private :
    int m_id ;
    std::string m_title ;
    std::string m_description ;
    Date m_creation ;
    Date m_dueFor ;
    Date m_closure ;
    std::string m_status ;
    int m_advancement ;
    std::string m_priority ;
    std::string m_comments ;
    std::vector<int> m_subTask ;
} ;

std::string subTask_to_string(std::vector<int> sousTache) ;
std::string Task_to_string (Task tache) ;

#endif