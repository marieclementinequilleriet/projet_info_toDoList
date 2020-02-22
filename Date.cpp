#include "Date.h"

Date::Date() : m_jour(0) , m_mois(0) , m_annee(0)
{

}

Date::Date(int jour,int mois, int annee) : m_jour(jour) , m_mois(mois) , m_annee(annee)
{

}


void Date::afficher_date()
{
    std::cout << m_jour <<"/"<<m_mois<<"/"<<m_annee<< std::endl  ;
}

int Date::getDay()
{
    return m_jour ;
}


Date saisir_date() 
{
    int jour ;
    int mois ;
    int annee ;
    std::cout<< "Jour ?" << std::endl ;
    std::cin >> jour ;
    std::cout<< "Mois ?" << std::endl ;
    std::cin >> mois ;
    std::cout<< "Année ?" << std::endl ;
    std::cin >> annee ;
    return Date(jour,mois,annee) ;
}

int string_to_int(std::string nombre)
{
    return std::atoi(nombre.c_str()) ;
}

Date string_to_Date(std::string date) 
{
    std::vector<std::string> recupere(3,"") ;
    /*for (int j {0} ; j<3; j++)
    {
        recupere[j]="";
    }*/
    int i = 0 ;
    for (unsigned j = 0 ; j < date.size() ; j++)
    {
        if (date[j] ==' ')
        {
            i+=1 ;
        }
        else
        {
            recupere[i].push_back(date[j]);
        }
    }
    int jour = string_to_int(recupere[0]);
    int mois = string_to_int(recupere[1]);
    int annee = string_to_int(recupere[2]) ;
    return Date(jour,mois,annee) ;
}

std::string Date::Date_to_string() 
{
    std::string res ;
    res = std::to_string(m_jour) + " "+ std::to_string(m_mois) +" "+ std::to_string(m_annee) ;
    return res ;
}