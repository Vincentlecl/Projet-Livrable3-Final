#pragma once
#include "Adresse.h"
#include "Personnel.h"


ref class Personne
{
public:
	int ID_Personne;
	//int ID_Personnel;
	System::String^ Nom;
	System::String^ Prenom;
	System::Boolean^ BoolSuppr;
	Personnel^ personnel;
	//System::DateTime^ DateEmbauche;
	//System::Int32^ ID_Personnel_Superieur;
	Adresse^ adresse;
};