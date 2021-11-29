#pragma once


ref class Personnel
{
public:
	int ID_Personne;
	int ID_Personnel;
	int ID_Adresse;
	System::String^ Nom;
	System::String^ Prenom;
	System::Boolean^ BoolSuppr;
	System::DateTime^ DateEmbauche;
	System::Int32^ ID_Personnel_Superieur;
	System::String^ Ville;
	System::Int32^ CP;
	System::String^ Ligne;
};