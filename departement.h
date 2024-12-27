#ifndef DEPARTEMENT_H_INCLUDED
#define DEPARTEMENT_H_INCLUDED

#include <string>
#include "agent.h"


class Departement
{
    public:
        Departement();
        virtual ~Departement();
        void addAgents(Agent);
        Agent searchAgent(string);
        void supprimerAgents(string);
        void afficherAgents();
        int nombreTotAlAgents();
        int nombreAgRet();

    protected:

    private:
        string nom;
        vector<Agent> listeAgent;

};


#endif // DEPARTEMENT_H_INCLUDED
