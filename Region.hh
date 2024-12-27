#ifndef REGION_HH_INCLUDED
#define REGION_HH_INCLUDED

#include <string>
#include "Departement.hh"

using namespace std;


class Region
{
    public:
        Region(vector<Departement>);
        void ajouterDepartements(Departement);
        void afficherStatGlobale();
        vector<Departement> getDepartment() const;


    protected:

    private:
        vector<Departement> listedepartements;
};


#endif // REGION_HH_INCLUDED
