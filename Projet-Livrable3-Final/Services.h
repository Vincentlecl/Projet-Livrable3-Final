#pragma once
#include "Map.h"
#include "Cad.h"
#include "Personnel.h"

namespace NS_Comp_Svc
{
	ref class CLservices
	{
	private:
		compData::Cad^ oCad;
		compMappage::Map^ oMappTB;
	public:
		CLservices(void);
		System::Data::DataSet^ selectionnerToutesLesPersonnes(System::String^);
		System::Collections::ArrayList^ select();
		void update(int IdPersonne, int IdAdresse, System::String^ nom, System::String^ prenom, System::DateTime^ DateEmbauche, int IdSuperieur, System::String^ Ville, int CP, System::String^ Ligne);
		void ajouterUnPersonnel(System::String^ nom, System::String^ prenom, System::DateTime^ DateEmbauche, int IdSuperieur, System::String^ Ville, int CP, System::String^ ligne);
		void deletePerso(int IdPersonne);
	};
}