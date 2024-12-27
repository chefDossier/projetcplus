#ifndef REGION_H_INCLUDED
#define REGION_H_INCLUDED

#include <string>
#include "departement.h"


class Region
{
    public:
        Region();
        virtual ~Region();
        void ajouterDepartements();
        void addStatGlobale();


    protected:

    private:
        vector<Departement> departements;
};

#endif // REGION_H_INCLUDED
