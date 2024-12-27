#ifndef AGENT_HH_INCLUDED
#define AGENT_HH_INCLUDED

#include <string>
#include <chrono>

using namespace std;

struct Date{
    int j;
    int m;
    int a;
};

class Agent
{
    public:

        Agent(string,string,string,string,string,string,int,int,int);
        int calculerAge();
        int anneeAvRetraite();
        void afficherInfos();
        Date getDateNaiss();
        void setDateNaiss(int,int,int);
        string getMatricule()const;
        string getGrade()const;
        string getGenre()const;
        string getPrenom()const;
        string getDepartment()const;
        string getNom()const;





    private:
        string matricule;
        string nom;
        string prenom;
        string genre;
        string grade;
        Date dateNaissance;
        string departement;
};



#endif // AGENT_HH_INCLUDED
