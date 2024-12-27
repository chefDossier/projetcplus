#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

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
        Agent();
        virtual ~Agent();
        void initialize();
        int calculerAge(int,int);
        int anneeAvRetraite(int,int);
        void afficherInfos();
        Date getDateNaiss();
        void setDateNaiss();





    private:
        string matricule;
        string nom;
        string prenom;
        Date dateNaissance;
        char genre;
        string grade;
        string departement;
};


#endif // AGENT_H_INCLUDED
