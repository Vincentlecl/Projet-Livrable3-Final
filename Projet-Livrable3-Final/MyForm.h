#pragma once
#include "Services.h"
#include <iostream>
#include <string>
#include "Personne.h"


namespace P6new {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r?sum?e de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis?es.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgv_enr;
	protected:


	private: System::Windows::Forms::Button^ btn_insert;
	private: System::Windows::Forms::Button^ btn_delete;
	private: System::Windows::Forms::Button^ btn_update;

	private: System::Windows::Forms::TextBox^ txt_idPersonne;
	private: System::Windows::Forms::TextBox^ text_IdPersonnel;
	private: System::Windows::Forms::TextBox^ txt_nom;
	private: System::Windows::Forms::TextBox^ txt_prenom;

	private: System::Windows::Forms::TextBox^ txt_IdSuperieur;
	private: System::Windows::Forms::TextBox^ txt_ligne;
	private: System::Windows::Forms::TextBox^ txt_CP;
	private: System::Windows::Forms::TextBox^ txt_ville;



	private: NS_Comp_Svc::CLservices^ oSvc;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;


	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txt_IdAdresse;
	private: System::Windows::Forms::DateTimePicker^ dt_DateEmbauche;


	private: System::Data::DataSet^ oDs;
	protected:

	private:

		void reloadDataPeronnel() {
			ArrayList^ list = this->oSvc->selectPersonnes();
			this->dgv_enr->Columns->Clear();
			this->dgv_enr->Columns->Add("id Personne", "id Personne");
			this->dgv_enr->Columns->Add("id Personnel", "id Personnel");
			this->dgv_enr->Columns->Add("id Adresse", "id Adresse");
			this->dgv_enr->Columns->Add("nom", "nom");
			this->dgv_enr->Columns->Add("prenom", "prenom");
			this->dgv_enr->Columns->Add("date Embauche", "date Embauche");
			this->dgv_enr->Columns->Add("id Superieur", "id Superieur");
			this->dgv_enr->Rows->Clear();
			for (int i = 0;i < list->Count;i++) {
				Personne^ p = (Personne^) list[i];
				//DataRow^ dr= dt->Rows->Add(p->id, p->nom, p->prenom);
				DataGridViewRow^ row = gcnew DataGridViewRow();
				row->CreateCells(this->dgv_enr, p->ID_Personne, p->personnel->ID_Personnel,p->adresse->ID_Adresse ,p->Nom, p->Prenom, p->personnel->DateEmbauche, p->personnel->ID_Personnel_Superieur);
				row->Tag = p;
				this->dgv_enr->Rows->Add(row);
			}
		}
		/// <summary>
		/// Variable n?cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M?thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m?thode avec l'?diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgv_enr = (gcnew System::Windows::Forms::DataGridView());
			this->btn_insert = (gcnew System::Windows::Forms::Button());
			this->btn_delete = (gcnew System::Windows::Forms::Button());
			this->btn_update = (gcnew System::Windows::Forms::Button());
			this->txt_idPersonne = (gcnew System::Windows::Forms::TextBox());
			this->txt_nom = (gcnew System::Windows::Forms::TextBox());
			this->txt_prenom = (gcnew System::Windows::Forms::TextBox());
			this->txt_IdSuperieur = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->text_IdPersonnel = (gcnew System::Windows::Forms::TextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txt_ligne = (gcnew System::Windows::Forms::TextBox());
			this->txt_CP = (gcnew System::Windows::Forms::TextBox());
			this->txt_ville = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->dt_DateEmbauche = (gcnew System::Windows::Forms::DateTimePicker());
			this->txt_IdAdresse = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_enr))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgv_enr
			// 
			this->dgv_enr->AllowUserToAddRows = false;
			this->dgv_enr->AllowUserToDeleteRows = false;
			this->dgv_enr->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->dgv_enr->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dgv_enr->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dgv_enr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_enr->Location = System::Drawing::Point(12, 12);
			this->dgv_enr->Name = L"dgv_enr";
			this->dgv_enr->ReadOnly = true;
			this->dgv_enr->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_enr->Size = System::Drawing::Size(1089, 329);
			this->dgv_enr->TabIndex = 0;
			this->dgv_enr->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dgv_enr_CellClick);
			// 
			// btn_insert
			// 
			this->btn_insert->Location = System::Drawing::Point(185, 606);
			this->btn_insert->Name = L"btn_insert";
			this->btn_insert->Size = System::Drawing::Size(75, 37);
			this->btn_insert->TabIndex = 2;
			this->btn_insert->Text = L"INS";
			this->btn_insert->UseVisualStyleBackColor = true;
			this->btn_insert->Click += gcnew System::EventHandler(this, &MyForm::btn_insert_Click);
			// 
			// btn_delete
			// 
			this->btn_delete->Enabled = false;
			this->btn_delete->Location = System::Drawing::Point(784, 606);
			this->btn_delete->Name = L"btn_delete";
			this->btn_delete->Size = System::Drawing::Size(75, 37);
			this->btn_delete->TabIndex = 3;
			this->btn_delete->Text = L"DEL";
			this->btn_delete->UseVisualStyleBackColor = true;
			this->btn_delete->Click += gcnew System::EventHandler(this, &MyForm::btn_delete_Click);
			// 
			// btn_update
			// 
			this->btn_update->Location = System::Drawing::Point(481, 606);
			this->btn_update->Name = L"btn_update";
			this->btn_update->Size = System::Drawing::Size(75, 37);
			this->btn_update->TabIndex = 4;
			this->btn_update->Text = L"UPD";
			this->btn_update->UseVisualStyleBackColor = true;
			this->btn_update->Click += gcnew System::EventHandler(this, &MyForm::btn_update_Click);
			// 
			// txt_idPersonne
			// 
			this->txt_idPersonne->Enabled = false;
			this->txt_idPersonne->Location = System::Drawing::Point(95, 29);
			this->txt_idPersonne->Name = L"txt_idPersonne";
			this->txt_idPersonne->Size = System::Drawing::Size(307, 20);
			this->txt_idPersonne->TabIndex = 5;
			// 
			// txt_nom
			// 
			this->txt_nom->Location = System::Drawing::Point(95, 102);
			this->txt_nom->Name = L"txt_nom";
			this->txt_nom->Size = System::Drawing::Size(307, 20);
			this->txt_nom->TabIndex = 6;
			// 
			// txt_prenom
			// 
			this->txt_prenom->Location = System::Drawing::Point(95, 127);
			this->txt_prenom->Name = L"txt_prenom";
			this->txt_prenom->Size = System::Drawing::Size(307, 20);
			this->txt_prenom->TabIndex = 7;
			// 
			// txt_IdSuperieur
			// 
			this->txt_IdSuperieur->Location = System::Drawing::Point(95, 179);
			this->txt_IdSuperieur->Name = L"txt_IdSuperieur";
			this->txt_IdSuperieur->Size = System::Drawing::Size(307, 20);
			this->txt_IdSuperieur->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"ID Personne";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(60, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Nom";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(46, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Prenom";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(5, 156);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Date Embauche";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(23, 182);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"ID Superieur";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 58);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"ID Personnel";
			// 
			// text_IdPersonnel
			// 
			this->text_IdPersonnel->Enabled = false;
			this->text_IdPersonnel->Location = System::Drawing::Point(95, 55);
			this->text_IdPersonnel->Name = L"text_IdPersonnel";
			this->text_IdPersonnel->Size = System::Drawing::Size(307, 20);
			this->text_IdPersonnel->TabIndex = 16;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->txt_ligne);
			this->groupBox2->Controls->Add(this->txt_CP);
			this->groupBox2->Controls->Add(this->txt_ville);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Location = System::Drawing::Point(586, 360);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(427, 223);
			this->groupBox2->TabIndex = 18;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Adresse";
			// 
			// txt_ligne
			// 
			this->txt_ligne->Location = System::Drawing::Point(85, 81);
			this->txt_ligne->Name = L"txt_ligne";
			this->txt_ligne->Size = System::Drawing::Size(307, 20);
			this->txt_ligne->TabIndex = 5;
			// 
			// txt_CP
			// 
			this->txt_CP->Location = System::Drawing::Point(85, 55);
			this->txt_CP->Name = L"txt_CP";
			this->txt_CP->Size = System::Drawing::Size(307, 20);
			this->txt_CP->TabIndex = 4;
			// 
			// txt_ville
			// 
			this->txt_ville->Location = System::Drawing::Point(85, 29);
			this->txt_ville->Name = L"txt_ville";
			this->txt_ville->Size = System::Drawing::Size(307, 20);
			this->txt_ville->TabIndex = 3;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(46, 84);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(33, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Ligne";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(15, 58);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Code Postal";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(53, 32);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(26, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Ville";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->dt_DateEmbauche);
			this->groupBox3->Controls->Add(this->txt_IdAdresse);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->txt_idPersonne);
			this->groupBox3->Controls->Add(this->txt_nom);
			this->groupBox3->Controls->Add(this->txt_prenom);
			this->groupBox3->Controls->Add(this->text_IdPersonnel);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->txt_IdSuperieur);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Location = System::Drawing::Point(24, 360);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(444, 223);
			this->groupBox3->TabIndex = 18;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Informations G?n?ral";
			// 
			// dt_DateEmbauche
			// 
			this->dt_DateEmbauche->Location = System::Drawing::Point(95, 153);
			this->dt_DateEmbauche->Name = L"dt_DateEmbauche";
			this->dt_DateEmbauche->Size = System::Drawing::Size(307, 20);
			this->dt_DateEmbauche->TabIndex = 19;
			// 
			// txt_IdAdresse
			// 
			this->txt_IdAdresse->Enabled = false;
			this->txt_IdAdresse->Location = System::Drawing::Point(95, 79);
			this->txt_IdAdresse->Margin = System::Windows::Forms::Padding(2);
			this->txt_IdAdresse->Name = L"txt_IdAdresse";
			this->txt_IdAdresse->Size = System::Drawing::Size(307, 20);
			this->txt_IdAdresse->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(28, 81);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(59, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"ID Adresse";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1113, 672);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->btn_update);
			this->Controls->Add(this->btn_delete);
			this->Controls->Add(this->btn_insert);
			this->Controls->Add(this->dgv_enr);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_enr))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->oSvc = gcnew NS_Comp_Svc::CLservices();
		this->reloadDataPeronnel();
	}
	private: System::Void btn_insert_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Personne^ p = gcnew Personne();
		p->Nom = this->txt_nom->Text;
		p->Prenom = this->txt_prenom->Text;
		p->personnel = gcnew Personnel();
		p->personnel->DateEmbauche = this->dt_DateEmbauche->Value;
		p->personnel->ID_Personnel_Superieur = System::Convert::ToInt32(this->txt_IdSuperieur->Text);
		p->adresse = gcnew Adresse();
		p->adresse->Ville = this->txt_ville->Text;
		p->adresse->CP = System::Convert::ToInt32(this->txt_CP->Text);
		p->adresse->Ligne = this->txt_ligne->Text;

		this->oSvc->add(p);

		this->reloadDataPeronnel();
	}
	private: System::Void btn_delete_Click(System::Object^ sender, System::EventArgs^ e) {

		this->oSvc->deletePerso(System::Convert::ToInt32(this->txt_idPersonne->Text));
		this->reloadDataPeronnel();
	}
	private: System::Void dgv_enr_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (this->dgv_enr->CurrentRow->IsNewRow)
			return;
		Personne^ p = (Personne^) this->dgv_enr->CurrentRow->Tag;
		this->txt_idPersonne->Text = System::Convert::ToString(p->ID_Personne);
		this->text_IdPersonnel->Text = System::Convert::ToString(p->personnel->ID_Personnel);
		this->txt_IdAdresse->Text = System::Convert::ToString(p->adresse->ID_Adresse);
		this->txt_nom->Text = p->Nom;
		this->txt_prenom->Text = p->Prenom;
		this->dt_DateEmbauche->Value = p->personnel->DateEmbauche;
		this->txt_IdSuperieur->Text = System::Convert::ToString(p->personnel->ID_Personnel_Superieur);
		this->txt_ville->Text = p->adresse->Ville;
		this->txt_CP->Text = System::Convert::ToString(p->adresse->CP);
		this->txt_ligne->Text = p->adresse->Ligne;
		this->btn_delete->Enabled = true;
	}

private: System::Void btn_update_Click(System::Object^ sender, System::EventArgs^ e) {

	Personne^ p = (Personne^)this->dgv_enr->CurrentRow->Tag;
	p->Nom = this->txt_nom->Text;
	p->Prenom = this->txt_prenom->Text;
	p->personnel->DateEmbauche = this->dt_DateEmbauche->Value;
	p->personnel->ID_Personnel_Superieur = System::Convert::ToInt32(this->txt_IdSuperieur->Text);
	p->adresse->Ville = this->txt_ville->Text;
	p->adresse->CP = System::Convert::ToInt32(this->txt_CP->Text);
	p->adresse->Ligne = this->txt_ligne->Text;
	this->oSvc->update(p);
	this->reloadDataPeronnel();
}
};
}