#ifndef DATE
#define DATE

#include <iostream>
#include <string> 
#include <vector>

class Date
{
    public :
    Date() ;
    Date(int jour, int mois, int annee) ;
    void afficher_date() ;
    int getDay() ;
    std::string Date_to_string() ;

    private :
    int m_jour ;
    int m_mois ;
    int m_annee ;
} ;

Date saisir_date() ;

int string_to_int(std::string nombre) ;

Date string_to_Date(std::string date) ;

#endif