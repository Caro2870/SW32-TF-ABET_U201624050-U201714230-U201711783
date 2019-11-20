#pragma once
#include "CFileExp.h"
#include <vector>
#include <algorithm>
#include <msclr\marshal_cppstd.h>
namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
		CFileExp* fileExp;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txtEmpieza;
	private: System::Windows::Forms::TextBox^  txtCotiene;


	private: System::Windows::Forms::TextBox^  txtTermina;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  txtMenor;
	private: System::Windows::Forms::TextBox^  txtIgual;


	private: System::Windows::Forms::TextBox^  txtMayor;

	private: System::Windows::Forms::Button^  button1;
			 msclr::interop::marshal_context context;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->fileExp = new CFileExp;
	
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete this->fileExp;
		}
	private: System::Windows::Forms::TextBox^  txtFile;
	private: System::Windows::Forms::Button^  buttOpen;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtBuscar;

	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::RadioButton^  rButtNombre;
	private: System::Windows::Forms::RadioButton^  rButtTam;
	private: System::Windows::Forms::RadioButton^  rButtExtension;
	private: System::Windows::Forms::RadioButton^  rButtFecha;

	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->txtFile = (gcnew System::Windows::Forms::TextBox());
			this->buttOpen = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBuscar = (gcnew System::Windows::Forms::TextBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->rButtNombre = (gcnew System::Windows::Forms::RadioButton());
			this->rButtTam = (gcnew System::Windows::Forms::RadioButton());
			this->rButtExtension = (gcnew System::Windows::Forms::RadioButton());
			this->rButtFecha = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtEmpieza = (gcnew System::Windows::Forms::TextBox());
			this->txtCotiene = (gcnew System::Windows::Forms::TextBox());
			this->txtTermina = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtMenor = (gcnew System::Windows::Forms::TextBox());
			this->txtIgual = (gcnew System::Windows::Forms::TextBox());
			this->txtMayor = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtFile
			// 
			this->txtFile->Location = System::Drawing::Point(118, 9);
			this->txtFile->Name = L"txtFile";
			this->txtFile->Size = System::Drawing::Size(298, 20);
			this->txtFile->TabIndex = 0;
			// 
			// buttOpen
			// 
			this->buttOpen->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->buttOpen->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttOpen->Location = System::Drawing::Point(437, 7);
			this->buttOpen->Name = L"buttOpen";
			this->buttOpen->Size = System::Drawing::Size(155, 23);
			this->buttOpen->TabIndex = 1;
			this->buttOpen->Text = L"Abrir archivo";
			this->buttOpen->UseVisualStyleBackColor = false;
			this->buttOpen->Click += gcnew System::EventHandler(this, &MyForm::Magic);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::GhostWhite;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label2->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(3, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Ingresar  archivo";
			// 
			// txtBuscar
			// 
			this->txtBuscar->Location = System::Drawing::Point(42, 110);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(177, 20);
			this->txtBuscar->TabIndex = 20;
			this->txtBuscar->TextChanged += gcnew System::EventHandler(this, &MyForm::txtBuscar_TextChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(567, 485);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(97, 20);
			this->radioButton2->TabIndex = 19;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Ascendente";
			this->radioButton2->UseVisualStyleBackColor = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(443, 484);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(104, 20);
			this->radioButton1->TabIndex = 18;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Descendente";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightSlateGray;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button4->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(517, 529);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Ordenar";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::Info;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(443, 250);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(165, 23);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Filtrar por Nombres";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::filtrar_c_nombres);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::GhostWhite;
			this->button2->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(225, 107);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Buscar";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::buscar);
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->ForeColor = System::Drawing::SystemColors::InfoText;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(12, 146);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(416, 484);
			this->listBox1->TabIndex = 13;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// rButtNombre
			// 
			this->rButtNombre->AutoSize = true;
			this->rButtNombre->BackColor = System::Drawing::Color::CadetBlue;
			this->rButtNombre->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rButtNombre->Location = System::Drawing::Point(42, 43);
			this->rButtNombre->Name = L"rButtNombre";
			this->rButtNombre->Size = System::Drawing::Size(75, 20);
			this->rButtNombre->TabIndex = 21;
			this->rButtNombre->TabStop = true;
			this->rButtNombre->Text = L"Nombre";
			this->rButtNombre->UseVisualStyleBackColor = false;
			// 
			// rButtTam
			// 
			this->rButtTam->AutoSize = true;
			this->rButtTam->BackColor = System::Drawing::Color::CadetBlue;
			this->rButtTam->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rButtTam->Location = System::Drawing::Point(42, 75);
			this->rButtTam->Name = L"rButtTam";
			this->rButtTam->Size = System::Drawing::Size(75, 20);
			this->rButtTam->TabIndex = 22;
			this->rButtTam->TabStop = true;
			this->rButtTam->Text = L"Tamaño";
			this->rButtTam->UseVisualStyleBackColor = false;
			// 
			// rButtExtension
			// 
			this->rButtExtension->AutoSize = true;
			this->rButtExtension->BackColor = System::Drawing::Color::CadetBlue;
			this->rButtExtension->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rButtExtension->Location = System::Drawing::Point(134, 43);
			this->rButtExtension->Name = L"rButtExtension";
			this->rButtExtension->Size = System::Drawing::Size(86, 20);
			this->rButtExtension->TabIndex = 23;
			this->rButtExtension->TabStop = true;
			this->rButtExtension->Text = L"Extension";
			this->rButtExtension->UseVisualStyleBackColor = false;
			// 
			// rButtFecha
			// 
			this->rButtFecha->AutoSize = true;
			this->rButtFecha->BackColor = System::Drawing::Color::CadetBlue;
			this->rButtFecha->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rButtFecha->Location = System::Drawing::Point(134, 75);
			this->rButtFecha->Name = L"rButtFecha";
			this->rButtFecha->Size = System::Drawing::Size(61, 20);
			this->rButtFecha->TabIndex = 24;
			this->rButtFecha->TabStop = true;
			this->rButtFecha->Text = L"Fecha";
			this->rButtFecha->UseVisualStyleBackColor = false;
			this->rButtFecha->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rButtFecha_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlText;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(461, 134);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 18);
			this->label1->TabIndex = 25;
			this->label1->Text = L"FILTRAR POR NOMBRE:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlText;
			this->label3->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(435, 284);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(149, 16);
			this->label3->TabIndex = 26;
			this->label3->Text = L"FILTRAR POR TAMAÑO:";
			// 
			// txtEmpieza
			// 
			this->txtEmpieza->Location = System::Drawing::Point(524, 163);
			this->txtEmpieza->Name = L"txtEmpieza";
			this->txtEmpieza->Size = System::Drawing::Size(100, 20);
			this->txtEmpieza->TabIndex = 27;
			// 
			// txtCotiene
			// 
			this->txtCotiene->Location = System::Drawing::Point(524, 208);
			this->txtCotiene->Name = L"txtCotiene";
			this->txtCotiene->Size = System::Drawing::Size(100, 20);
			this->txtCotiene->TabIndex = 28;
			// 
			// txtTermina
			// 
			this->txtTermina->Location = System::Drawing::Point(524, 186);
			this->txtTermina->Name = L"txtTermina";
			this->txtTermina->Size = System::Drawing::Size(100, 20);
			this->txtTermina->TabIndex = 29;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(435, 167);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 16);
			this->label4->TabIndex = 30;
			this->label4->Text = L"Empieza con";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(442, 211);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 15);
			this->label5->TabIndex = 31;
			this->label5->Text = L"Contiene";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->Location = System::Drawing::Point(434, 188);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(77, 15);
			this->label6->TabIndex = 32;
			this->label6->Text = L"Termina con";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(434, 341);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 15);
			this->label7->TabIndex = 39;
			this->label7->Text = L"Menor que";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(434, 367);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(45, 15);
			this->label8->TabIndex = 38;
			this->label8->Text = L"Igual a";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(434, 317);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(66, 15);
			this->label9->TabIndex = 37;
			this->label9->Text = L"Mayor que";
			// 
			// txtMenor
			// 
			this->txtMenor->Location = System::Drawing::Point(508, 338);
			this->txtMenor->Name = L"txtMenor";
			this->txtMenor->Size = System::Drawing::Size(100, 20);
			this->txtMenor->TabIndex = 36;
			// 
			// txtIgual
			// 
			this->txtIgual->Location = System::Drawing::Point(508, 364);
			this->txtIgual->Name = L"txtIgual";
			this->txtIgual->Size = System::Drawing::Size(100, 20);
			this->txtIgual->TabIndex = 35;
			// 
			// txtMayor
			// 
			this->txtMayor->Location = System::Drawing::Point(508, 314);
			this->txtMayor->Name = L"txtMayor";
			this->txtMayor->Size = System::Drawing::Size(100, 20);
			this->txtMayor->TabIndex = 34;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Info;
			this->button1->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(443, 402);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(165, 32);
			this->button1->TabIndex = 33;
			this->button1->Text = L"Filtrar  por Tamaño";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::filtrar_c_tamaño);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Highlight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(672, 661);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->txtMenor);
			this->Controls->Add(this->txtIgual);
			this->Controls->Add(this->txtMayor);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtTermina);
			this->Controls->Add(this->txtCotiene);
			this->Controls->Add(this->txtEmpieza);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->rButtFecha);
			this->Controls->Add(this->rButtExtension);
			this->Controls->Add(this->rButtTam);
			this->Controls->Add(this->rButtNombre);
			this->Controls->Add(this->txtBuscar);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttOpen);
			this->Controls->Add(this->txtFile);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"FILEEXP";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void Magic(System::Object^  sender, System::EventArgs^  e) {
		string name = context.marshal_as<string>(txtFile->Text);
		this->fileExp->scanear(name);
	}

	private: System::Void buscar(System::Object^  sender, System::EventArgs^  e) {
		listBox1->Items->Clear();
		if (rButtNombre->Checked) {
			string name = context.marshal_as<string>(txtBuscar->Text);
			vector<CArchivo*> nombre = this->fileExp->buscar_archivo_nombre(name);
			if (!nombre.empty()) {
				for (int i = 0; i < nombre.size(); ++i) {
					string s = nombre[i]->getRuta();
					String^ n = gcnew String(s.c_str());
					listBox1->Items->Add(n);
				}
			} else {
				MessageBox::Show("No se encontro elemento >:v");
			}
			
		} else if (rButtExtension->Checked) {
			string exte = context.marshal_as<string>(txtBuscar->Text);
			vector<CArchivo*> extension = this->fileExp->buscar_archivo_exten(exte);
			if (!extension.empty()) {
				for (int i = 0; i < extension.size(); ++i) {
					string s = extension[i]->getRuta();
					String^ n = gcnew String(s.c_str());
					listBox1->Items->Add(n);
				}
			}
			else {
				MessageBox::Show("No se encontro elemento >:v");
			}
		} else if (rButtFecha->Checked) {
			string date = context.marshal_as<string>(txtBuscar->Text);
			vector<CArchivo*> fecha = this->fileExp->buscar_archivos_fecha(date);
			if (!fecha.empty()) {
				for (int i = 0; i < fecha.size(); ++i) {
					string s = fecha[i]->getRuta();
					String^ n = gcnew String(s.c_str());
					listBox1->Items->Add(n);
				}
			}
			else {
				MessageBox::Show("No se encontro elemento >:v");
			}
		} else if (rButtTam->Checked) {
			long long numero = Int64::Parse(txtBuscar->Text);
			vector<CArchivo*> tamaño = this->fileExp->buscar_archivo_tamaño(numero);
			if (!tamaño.empty()) {
				for (int i = 0; i < tamaño.size(); ++i) {
					string s = tamaño[i]->getRuta();
					String^ n = gcnew String(s.c_str());
					listBox1->Items->Add(n);
				}
			}
			else {
				MessageBox::Show("No se encontro elemento >:v");
			}
		}

	}
	private: System::Void filtrar_c_nombres(System::Object^  sender, System::EventArgs^  e) {
		listBox1->Items->Clear();
		if (txtEmpieza->Text != "") {
			string ini = context.marshal_as<string>(txtEmpieza->Text);
			vector<CArchivo*> v = this->fileExp->filtrado_columnas_nombres_inicial(ini);
			if (!v.empty()) {
				for (int i = 0; i < v.size(); ++i) {
					string s = v[i]->getRuta();
					String^ n = gcnew String(s.c_str());
					listBox1->Items->Add(n);
				}
			} else {
				MessageBox::Show("No hay elementos");
			}

		} else if (txtTermina->Text != "") {
			string fin = context.marshal_as<string>(txtTermina->Text);
			vector<CArchivo*> v = this->fileExp->filtrardo_columnas_nombres_final(fin);
			if (!v.empty()) {
				for (int i = 0; i < v.size(); ++i) {
					string s = v[i]->getRuta();
					String^ n = gcnew String(s.c_str());
					listBox1->Items->Add(n);
				}
			}
			else {
				MessageBox::Show("No hay elementos");
			}

		} else if (txtCotiene->Text != "") {
			string con = context.marshal_as<string>(txtCotiene->Text);
			vector<string> v = this->fileExp->filtrardo_columnas_nombres_contiene(con[0]);
			if (!v.empty()) {
				for (int i = 0; i < v.size(); ++i) {
					String^ n = gcnew String(v[i].c_str());
					listBox1->Items->Add(n);
				}
			} else {
				MessageBox::Show("No hay elementos");
			}
		}

	}
	private: System::Void filtrar_c_tamaño(System::Object^  sender, System::EventArgs^  e) {
		listBox1->Items->Clear();
		if (txtMayor->Text != "") {
			long long tam = Int64::Parse(txtMayor->Text);
			vector<CArchivo*> v = this->fileExp->filtrardo_columnas_tamaño_mayor(tam);
			if (!v.empty()) {
				for (int i = 0; i < v.size(); ++i) {
					string m = v[i]->getRuta();
					String^ n = gcnew String(m.c_str());
					listBox1->Items->Add(n);
				}
			} else {
				MessageBox::Show("No hay elementos");
			}

		} else if (txtMenor->Text != "") {
			long long men = Int64::Parse(txtMenor->Text);
			vector<CArchivo*> v = this->fileExp->filtrardo_columnas_tamaño_menor(men);
			if (!v.empty()) {
				for (int i = 0; i < v.size(); ++i) {
					string m = v[i]->getRuta();
					String^ n = gcnew String(m.c_str());
					listBox1->Items->Add(n);
				}
			} else {
				MessageBox::Show("No hay elementos");
			}

		} else if (txtIgual->Text != "") {
			long long igual = Int64::Parse(txtIgual->Text);
			vector<CArchivo*> v = this->fileExp->filtrardo_columnas_tamaño_igual(igual);
			if (!v.empty()) {
				for (int i = 0; i < v.size(); ++i) {
					string s = v[i]->getRuta();
					String^ n = gcnew String(s.c_str());
					listBox1->Items->Add(n);
				}
			} else {
				MessageBox::Show("No hay elementos");
			}

		}
	}
private: System::Void txtBuscar_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void rButtFecha_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	vector<string> v = this->getElements();

	string* elem = new string[v.size()];

	for (int i = 0; i < v.size(); ++i)
		elem[i] = v[i];

	if (radioButton2->Checked)
		this->fileExp->ordenarAscendente(elem, v.size());
	if (radioButton1->Checked)
		this->fileExp->ordenarDescendente(elem, v.size());
	listBox1->Items->Clear();

	for (int i = 0; i < v.size(); ++i) {
		String^ n = gcnew String(elem[i].c_str());
		listBox1->Items->Add(n);
	}
}
		 private:vector<string> getElements() {
			 vector<string> elementos;
			 for (int i = 0; i < listBox1->Items->Count; ++i) {
				 String^ prueba = listBox1->Items[i]->ToString();
				 string con = context.marshal_as<string>(prueba);
				 elementos.push_back(con);
			 }
			 return elementos;
		 }
	private: System::Void Sort(System::Object^  sender, System::EventArgs^  e) {
		vector<string> v = this->getElements();

		string* elem = new string[v.size()];

		for (int i = 0; i < v.size(); ++i)
			elem[i] = v[i];

		if (radioButton2->Checked)
			this->fileExp->ordenarAscendente(elem, v.size());
		if (radioButton1->Checked)
			this->fileExp->ordenarDescendente(elem, v.size());
		listBox1->Items->Clear();

		for (int i = 0; i < v.size(); ++i) {
			String^ n = gcnew String(elem[i].c_str());
			listBox1->Items->Add(n);
		}

	}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
