#ifndef DEPARTEMENT_HH_INCLUDED
#define DEPARTEMENT_HH_INCLUDED
#include <vector>
#include <string>
#include "Agent.hh"

using namespace std;

class Departement
{
    public:
        Departement(string ,vector<Agent>);
        Departement(string);
        void addAgents(Agent);
        Agent* searchAgent(string);
        void supprimerAgents(string);
        void afficherAgents();
        int nombreTotalAgents();
        int nombreAgProcheRet();
        string getNom()const;
        vector<Agent> getListeAgent()const;

    protected:

    private:
        string nom;
        vector<Agent> listeAgent;

};



#endif // DEPARTEMENT_HH_INCLUDED
