#include "action.h"

bool deja_utilisateur()
{
    std::cout << "Bienvenue dans votre gestionnaire de tâche." << std::endl;
    std::cout << "Avez-vous déjà un compte utilisateur ?" << std::endl;
    std::cout << " Tapez O pour Oui et N pour Non" << std::endl;
    char reponse;
    std::cin >> reponse;
    bool utilisateur{reponse == 'O'};
    return utilisateur;
}

std::string fichier(bool dej_util)
{
    std::string nom_utilisateur;
    if (dej_util)
    {
        std::cout << "Entrez votre nom d'utilisateur" << std::endl;
    }
    else
    {
        std::cout << " Créez votre nom d'utilisateur (sans espaces)" << std::endl;
        std::cout << "Attention, si vouq le perdez, vous ne pourrez plus accéder à vos tâches" << std::endl ;
    }
    std::cin >> nom_utilisateur;
    nom_utilisateur += ".txt";
    return nom_utilisateur;
}

std::vector<Task> mes_Taches(bool dej_util, std::string fichier)
{
    std::vector<Task> liste_Taches(0);
    if (dej_util)
    {
        liste_Taches = get_tasks(fichier);
    }
    return liste_Taches;
}

char actions_standards()
{
    std::cout << "Pour créer une tâche, tapez C" << std::endl;
    std::cout << "Pour modifier une tâche, tapez M" << std::endl;
    std::cout << "Pour afficher toutes les tâches, tapez A" << std::endl;
    std::cout << "Pour afficher les détails d'une tâche, tapez D" << std::endl;
    std::cout << "Pour quitter le gestionnaire de tâches, tapez Q" << std::endl;
    char res;
    std::cin >> res;
    system("clear");
    return res;
}

void afficher_tout(std::vector<Task> liste_Taches)
{
    std::cout << "Voici toutes vos taches" << std::endl;
    if (liste_Taches.size() == 0)
    {
        std::cout << "Vous n'avez pas de tâches enregistrées" << std::endl;
    }
    else
    {
        for (long unsigned int i = 0; i < liste_Taches.size(); i++)
        {
            std::cout << "n°" << liste_Taches[i].get_id() << "     " << liste_Taches[i].get_title() << "       "
                      << liste_Taches[i].get_status() << std::endl;
        }
    }
}

void afficher_tache(std::vector<Task> liste_Taches)
{
    int id;
    std::cout << "Entrez l'identifiant de la tâche à afficher" << std::endl;
    std::cin >> id;
    if (id >= 0 && id < liste_Taches.size())
    {
        liste_Taches[id].print_task();
    }
    else
    {
        std::cout << "Cette tache n'existe pas" << std::endl;
    }
}

void modifier_tache(std::vector<Task> &liste_Taches)
{
    std::cout << "Connaissez-vous l'identifiant de la tache à modifier ?  (O/N)" << std::endl;
    char connu;
    std::cin >> connu;
    if (connu == 'N')
    {
        afficher_tout(liste_Taches);
    }
    else
    {
    }
    std::cout << "Entrez le numéro de la tâche à modifier" << std::endl;
    int a_modifier{0};
    std::cin >> a_modifier;
    if (a_modifier >= 0 && a_modifier < liste_Taches.size())
    {
        system("clear");
        liste_Taches[a_modifier].print_task();
        char non_fini = 'O';
        do
        {
            std::cout << "Pour clore la tache, tapez 0" << std::endl;
            std::cout << "Pour modifier, un attribut tapez le numéro correspondant :" << std::endl;
            std::cout << "1          Titre" << std::endl;
            std::cout << "2          Description" << std::endl;
            std::cout << "3          Date de création" << std::endl;
            std::cout << "4          Date de fin" << std::endl;
            std::cout << "5          Date limite" << std::endl;
            std::cout << "6          Statut" << std::endl;
            std::cout << "7          Avancement" << std::endl;
            std::cout << "8          Priorité" << std::endl;
            std::cout << "9          Commentaire" << std::endl;
            std::cout << "10         Sous taches" << std::endl;
            std::cout << "Pour quitter, tapez 11" << std::endl;
            int nombre;
            std::cin >> nombre;
            switch (nombre)
            {
            case 0:
                liste_Taches[a_modifier].end_task();
                system("clear");
                break;
            case 1:
            {
                std::cout << "Entrez votre nouveau titre" << std::endl;
                std::cout << "Prière de ne pas utiliser le symbole / dans votre texte" << std::endl;
                std::string attribut;
                std::cin.ignore();
                std::getline(std::cin, attribut);
                liste_Taches[a_modifier].set_title(attribut);
                system("clear");
            }
            break;
            case 2:
            {
                std::cout << "Entrez votre nouvelle description" << std::endl;
                std::cout << "Prière de ne pas utiliser le symbole / dans votre texte" << std::endl;
                std::string attribut;
                std::cin.ignore();
                std::getline(std::cin, attribut);
                liste_Taches[a_modifier].set_description(attribut);
                system("clear");
            }
            break;
            case 3:
            {
                std::cout << "Entrez votre nouvelle date de création" << std::endl;
                std::cin.ignore();
                Date attribut = saisir_date();
                liste_Taches[a_modifier].set_creation(attribut);
                system("clear");
            }
            break;
            case 4:
            {
                std::cout << "Entrez votre nouvelle date de fin" << std::endl;
                std::cin.ignore();
                Date attribut = saisir_date();
                liste_Taches[a_modifier].set_closure(attribut);
                system("clear");
            }
            break;
            case 5:
            {
                std::cout << "Entrez votre nouvelle date limite" << std::endl;
                std::cin.ignore();
                Date attribut = saisir_date();
                liste_Taches[a_modifier].set_closure(attribut);
                system("clear");
            }
            break;
            case 6:
            {
                std::cout << "Entrez le statut actuel de la tâche" << std::endl;
                std::cout << " Pas commencé / En cours / Terminé" << std::endl;
                std::string attribut;
                std::cin.ignore();
                std::getline(std::cin, attribut);
                liste_Taches[a_modifier].set_status(attribut);
                system("clear");
            }
            break;
            case 7:
            {
                std::cout << "Entrez l'avancement actuel de la tâche (en %)" << std::endl;
                int attribut;
                std::cin >> attribut;
                liste_Taches[a_modifier].set_advancement(attribut);
                system("clear");
            }
            break;
            case 8:
            {
                std::cout << "Entrez l'état de priorité de la tâche " << std::endl;
                std::cout << "Lointain / Normal / Urgent" << std::endl;
                std::string attribut;
                std::cin >> attribut;
                liste_Taches[a_modifier].set_priority(attribut);
                system("clear");
            }
            break;
            case 9:
            {
                std::cout << "Entrez vos nouveaux commentaires" << std::endl;
                std::cout << "Prière de ne pas utiliser le symbole / dans votre texte" << std::endl;
                std::string attribut;
                std::cin.ignore();
                std::getline(std::cin, attribut);
                liste_Taches[a_modifier].set_comments(attribut);
                system("clear");
            }
            break;

            case 10:
                liste_Taches[a_modifier].print_subTasks();
                std::cout << "Pour ajouter une sous_tache, tapez A" << std::endl;
                std::cout << "Pour supprimer une sous-tache, tapez S" << std::endl;
                char a_faire;
                std::cin >> a_faire;
                system("clear");
                if (a_faire == 'A')
                {
                    std::cout << "Quelle sous tâche voulez-vous ajouter ? Entrez son identifiant " << std::endl;
                    afficher_tout(liste_Taches);
                    int a_ajouter;
                    std::cin >> a_ajouter;
                    liste_Taches[a_modifier].add_subTask(a_ajouter);
                    system("clear");
                }
                else
                {
                    if (a_faire == 'S')
                    {
                        std::cout << "Quelle sous tâche voulez-vous supprimer ? Entrez son identifiant " << std::endl;
                        afficher_tout(liste_Taches);
                        int a_supprimer;
                        std::cin >> a_supprimer;
                        liste_Taches[a_modifier].del_subTask(a_supprimer);
                        system("clear");
                    }
                }

                break;
            case 11:
                break;

            default:
                std::cout << "Erreur : le symbole entré n'est pas reconnu" << std::endl;
                modifier_tache(liste_Taches);
                break;
            }
            std::cout << "Voulez-vous modifier un autre attribut ?  (O/N)" << std::endl;
            std::cin >> non_fini;
            system("clear");
        } while (non_fini == 'O');
    }
    else
    {
        std::cout << "Cette tache n'existe pas" << std::endl;
    }
}

Task creer_tache(std::vector<Task> &liste_Taches)
{
    Task nouvelle_tache = Task();
    nouvelle_tache.set_id(liste_Taches.size());
    std::cout << "Quel est le titre de votre tache ?" << std::endl;
    std::cout << "Prière de ne pas utiliser le symbole / dans votre texte" << std::endl;
    std::string titre;
    std::cin.ignore();
    std::getline(std::cin, titre);
    nouvelle_tache.set_title(titre);
    system("clear");
    std::cout << "Entrez une description de votre tache." << std::endl;
    std::cout << "Prière de ne pas utiliser le symbole / dans votre texte" << std::endl;
    std::cout << "Pour passer, appuyez sur entrée" << std::endl;
    std::string description;
    std::getline(std::cin, description);
    nouvelle_tache.set_description(description);
    system("clear");
    std::cout << "Entrez la date de création de la tâche" << std::endl;
    Date creation;
    creation = saisir_date();
    nouvelle_tache.set_creation(creation);
    system("clear");
    std::cout << "Entrez la date limite de réalisation de la tache" << std::endl;
    Date limite;
    limite = saisir_date();
    nouvelle_tache.set_dueFor(limite);
    system("clear");
    std::cout << "Entrez le statut actuel de la tâche" << std::endl;
    std::cout << " Pas commencé / En cours / Terminé" << std::endl;
    std::string statut;
    std::cin.ignore();
    std::getline(std::cin, statut);
    nouvelle_tache.set_status(statut);
    system("clear");
    std::cout << "Entrez l'état de priorité de la tâche " << std::endl;
    std::cout << "Lointain / Normal / Urgent" << std::endl;
    std::string priorite;
    std::cin >> priorite;
    nouvelle_tache.set_priority(priorite);
    system("clear");
    std::cout << "Entrez vos commentaires" << std::endl;
    std::cout << "Prière de ne pas utiliser le symbole / dans votre texte" << std::endl;
    std::cout << "Pour passer, appuyez sur entrée" << std::endl;
    std::string commentaires;
    std::cin.ignore();
    std::getline(std::cin, commentaires);
    nouvelle_tache.set_comments(commentaires);
    system("clear");
    std::cout << "Voulez-vous ajouter une sous tâche ? (O/N) " << std::endl;
    char reponse;
    std::cin >> reponse;
    system("clear");
    while (reponse == 'O')
    {
        std::cout << "Quelle sous tâche voulez-vous ajouter ? Entrez son identifiant " << std::endl;
        afficher_tout(liste_Taches);
        int a_ajouter;
        std::cin >> a_ajouter;
        nouvelle_tache.add_subTask(a_ajouter);
        system("clear");
        std::cout << "Voulez-vous ajouter une sous tâche ? (O/N) " << std::endl;
        std::cin >> reponse;
        system("clear");
    }
    std::cout << "Terminé" << std::endl;

    return nouvelle_tache;
}