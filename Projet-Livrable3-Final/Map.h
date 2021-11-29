#pragma once
namespace compMappage
{
	ref class Map
	{
	private:
		System::String^ sSql;
		int IdPersonne;
		System::String^ nom;
		System::String^ prenom;
		System::Boolean^ BoolSuppr = false;
		System::DateTime^ DateEmbauche;
		System::Int32^ IdSuperieur;
		System::String^ Ville;
		System::Int32^ CP;
		System::String^ Ligne;
		System::Boolean^ AdresseFact = false;
		System::Boolean^ AdresseLivr = false;
		int IdAdresse;
	public:
		System::String^ Select(void);
		System::String^ Insert(void);
		System::String^ DeletePerso(void);
		System::String^ Update(void);
		void setId(int);
		void setNom(System::String^);
		void setPrenom(System::String^);
		void setDateEmbauche(System::DateTime^);
		void setIdSuperieur(System::Int32^);
		void setBoolSuppr();
		void setVille(System::String^);
		void setCP(System::Int32^);
		void setLigne(System::String^);
		void setIdAdresse(int);
		//void setAdresseFact();
		//void setAdresseLivr();
		int getId(void);
		System::String^ getNom(void);
		System::String^ getPrenom(void);
	};
}