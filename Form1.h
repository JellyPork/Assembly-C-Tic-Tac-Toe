#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used
/*
Proyecto Final - OAC - 7/1/2022
Tic Tac Toe - Gato
- Ramses Felix Prado
- Alex Chang Rojas
*/

#include "Header1.h"
#include "Header2.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <basetsd.h>



//extern "C" INT64 sumarPunto(INT64);

namespace CppCLRWinFormsProject {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  using namespace std;

#pragma managed(push, off)
  //FUNCIONES ASM
  //Funcion para sumar un punto a un jugador
  int sumarPunto(int puntajeActual) {
      int puntajeNuevo = 0;

      _asm {
          mov eax, 0
          mov eax, puntajeActual
          inc eax

          mov puntajeNuevo, eax
      }

      return puntajeNuevo;
  }

  int turnoJugador(int turno) {
      int turnoNuevo = 0;
      _asm {
          mov eax, 0
          mov eax, turno
          
          sub eax, 2h

          jz EQUALS
          jnz NOT_EQUALS
          
          EQUALS:
          mov ebx, 1h
          mov turnoNuevo, ebx
          jmp L1
          
          NOT_EQUALS:
          mov ebx, 2h
          mov turnoNuevo, ebx

          L1:
          
      };
      return turnoNuevo;
      
  }

  int verificarX(int a, int b, int c) {
      int lineaVerificada = 0;//Si el valor regresado es correcto
      _asm {

          mov eax, 0
          mov ebx, 0
          mov ecx, 0

          mov eax, a
          mov ebx, b
          mov ecx, c

          add eax, ebx
          add eax, ecx

          sub eax, 15 //X = 5 , O = 2


          jz EQUALS
          jnz NOT_EQUALS

          EQUALS :
          mov ebx, 30
              mov lineaVerificada, ebx
              jmp L1

              NOT_EQUALS :
          mov ebx, 0
              mov lineaVerificada, ebx

              L1 :
          mov ax, 0
      };
      return lineaVerificada;
  }

  int verificarO(int a, int b, int c) {
      int numOVerificada = 0;
      _asm {
          mov eax, 0
          mov ebx, 0
          mov ecx, 0

          mov eax, a
          mov ebx, b
          mov ecx, c

          add eax, ebx
          add eax, ecx

          sub eax, 6


          jz EQUALS
          jnz NOT_EQUALS

          EQUALS:
          mov ebx, 15
          mov numOVerificada, ebx
          jmp L1

          NOT_EQUALS :
          mov ebx, 0
          mov numOVerificada, ebx

          L1 :
          mov ax, 0
      };
      return numOVerificada;
  }

  int verificarGanador(int puntuacionX, int puntuacionO) {
      int ganador;
      _asm {
          mov eax,puntuacionX
          mov ebx, puntuacionO

          sub eax, 3h

          jz EQUALS_X

          sub ebx, 3h
          jz EQUALS_O
          jnz NOT_EQUALS

          EQUALS_X:
          mov eax, 24
          mov ganador, eax
          jmp L1

          EQUALS_O :
          mov ebx, 33
          mov ganador, ebx
          jmp L1

          NOT_EQUALS:
          mov eax, 0
          mov ganador, eax

          L1:
      };
      
      return ganador;
  }





#pragma managed(pop)
  /// <summary>
  /// Summary for Form1
  /// </summary>
  public ref class Form1 : public System::Windows::Forms::Form
  {
  public:
    Form1(void)
    {
      InitializeComponent();
      //
      //TODO: Add the constructor code here
      //

      // uncomment to execute the rk1-utils:
      //    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used

    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~Form1()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::Panel^ panel1;
  protected:
  private: System::Windows::Forms::Label^ label1;
  private: System::Windows::Forms::Panel^ panel2;
  private: System::Windows::Forms::Button^ button7;
  private: System::Windows::Forms::Button^ button8;
  private: System::Windows::Forms::Button^ button9;
  private: System::Windows::Forms::Button^ button4;
  private: System::Windows::Forms::Button^ button5;
  private: System::Windows::Forms::Button^ button6;
  private: System::Windows::Forms::Button^ button3;
  private: System::Windows::Forms::Button^ button2;
  private: System::Windows::Forms::Button^ button1;
  private: System::Windows::Forms::Panel^ panel3;
  private: System::Windows::Forms::Label^ labelPlayerX;

  private: System::Windows::Forms::Label^ label3;
  private: System::Windows::Forms::Label^ label2;
  private: System::Windows::Forms::Button^ newGameButton;

  private: System::Windows::Forms::Button^ resetButton;

  private: System::Windows::Forms::Label^ labelPlayerO;






  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->button7 = (gcnew System::Windows::Forms::Button());
        this->button8 = (gcnew System::Windows::Forms::Button());
        this->button9 = (gcnew System::Windows::Forms::Button());
        this->button4 = (gcnew System::Windows::Forms::Button());
        this->button5 = (gcnew System::Windows::Forms::Button());
        this->button6 = (gcnew System::Windows::Forms::Button());
        this->button3 = (gcnew System::Windows::Forms::Button());
        this->button2 = (gcnew System::Windows::Forms::Button());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->labelPlayerO = (gcnew System::Windows::Forms::Label());
        this->labelPlayerX = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->newGameButton = (gcnew System::Windows::Forms::Button());
        this->resetButton = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel3->SuspendLayout();
        this->SuspendLayout();
        // 
        // panel1
        // 
        this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
        this->panel1->Controls->Add(this->label1);
        this->panel1->Location = System::Drawing::Point(8, 3);
        this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(1368, 141);
        this->panel1->TabIndex = 0;
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 26, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(478, 40);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(353, 52);
        this->label1->TabIndex = 0;
        this->label1->Text = L"Juego de Gato";
        this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
        // 
        // panel2
        // 
        this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
        this->panel2->Controls->Add(this->button7);
        this->panel2->Controls->Add(this->button8);
        this->panel2->Controls->Add(this->button9);
        this->panel2->Controls->Add(this->button4);
        this->panel2->Controls->Add(this->button5);
        this->panel2->Controls->Add(this->button6);
        this->panel2->Controls->Add(this->button3);
        this->panel2->Controls->Add(this->button2);
        this->panel2->Controls->Add(this->button1);
        this->panel2->Controls->Add(this->panel3);
        this->panel2->Location = System::Drawing::Point(8, 161);
        this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(1368, 594);
        this->panel2->TabIndex = 1;
        // 
        // button7
        // 
        this->button7->BackColor = System::Drawing::Color::WhiteSmoke;
        this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button7->Location = System::Drawing::Point(33, 407);
        this->button7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->button7->Name = L"button7";
        this->button7->Size = System::Drawing::Size(158, 142);
        this->button7->TabIndex = 10;
        this->button7->UseVisualStyleBackColor = false;
        this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
        // 
        // button8
        // 
        this->button8->BackColor = System::Drawing::Color::WhiteSmoke;
        this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button8->Location = System::Drawing::Point(273, 407);
        this->button8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->button8->Name = L"button8";
        this->button8->Size = System::Drawing::Size(158, 142);
        this->button8->TabIndex = 9;
        this->button8->UseVisualStyleBackColor = false;
        this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
        // 
        // button9
        // 
        this->button9->BackColor = System::Drawing::Color::WhiteSmoke;
        this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button9->Location = System::Drawing::Point(516, 407);
        this->button9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->button9->Name = L"button9";
        this->button9->Size = System::Drawing::Size(158, 142);
        this->button9->TabIndex = 8;
        this->button9->UseVisualStyleBackColor = false;
        this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
        // 
        // button4
        // 
        this->button4->BackColor = System::Drawing::Color::WhiteSmoke;
        this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button4->Location = System::Drawing::Point(33, 218);
        this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->button4->Name = L"button4";
        this->button4->Size = System::Drawing::Size(158, 142);
        this->button4->TabIndex = 7;
        this->button4->UseVisualStyleBackColor = false;
        this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
        // 
        // button5
        // 
        this->button5->BackColor = System::Drawing::Color::WhiteSmoke;
        this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button5->Location = System::Drawing::Point(273, 218);
        this->button5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->button5->Name = L"button5";
        this->button5->Size = System::Drawing::Size(158, 142);
        this->button5->TabIndex = 6;
        this->button5->UseVisualStyleBackColor = false;
        this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
        // 
        // button6
        // 
        this->button6->BackColor = System::Drawing::Color::WhiteSmoke;
        this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button6->Location = System::Drawing::Point(516, 218);
        this->button6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->button6->Name = L"button6";
        this->button6->Size = System::Drawing::Size(158, 142);
        this->button6->TabIndex = 5;
        this->button6->UseVisualStyleBackColor = false;
        this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
        // 
        // button3
        // 
        this->button3->BackColor = System::Drawing::Color::WhiteSmoke;
        this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button3->Location = System::Drawing::Point(516, 29);
        this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->button3->Name = L"button3";
        this->button3->Size = System::Drawing::Size(158, 142);
        this->button3->TabIndex = 4;
        this->button3->UseVisualStyleBackColor = false;
        this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
        // 
        // button2
        // 
        this->button2->BackColor = System::Drawing::Color::WhiteSmoke;
        this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button2->Location = System::Drawing::Point(273, 29);
        this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->button2->Name = L"button2";
        this->button2->Size = System::Drawing::Size(158, 142);
        this->button2->TabIndex = 3;
        this->button2->UseVisualStyleBackColor = false;
        this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
        // 
        // button1
        // 
        this->button1->BackColor = System::Drawing::Color::WhiteSmoke;
        this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button1->Location = System::Drawing::Point(33, 29);
        this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(158, 142);
        this->button1->TabIndex = 2;
        this->button1->UseVisualStyleBackColor = false;
        this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
        // 
        // panel3
        // 
        this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
        this->panel3->Controls->Add(this->labelPlayerO);
        this->panel3->Controls->Add(this->labelPlayerX);
        this->panel3->Controls->Add(this->label3);
        this->panel3->Controls->Add(this->label2);
        this->panel3->Controls->Add(this->newGameButton);
        this->panel3->Controls->Add(this->resetButton);
        this->panel3->Location = System::Drawing::Point(802, 15);
        this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(514, 486);
        this->panel3->TabIndex = 1;
        // 
        // labelPlayerO
        // 
        this->labelPlayerO->BackColor = System::Drawing::Color::WhiteSmoke;
        this->labelPlayerO->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
        this->labelPlayerO->Font = (gcnew System::Drawing::Font(L"MS Gothic", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelPlayerO->Location = System::Drawing::Point(200, 115);
        this->labelPlayerO->Name = L"labelPlayerO";
        this->labelPlayerO->Size = System::Drawing::Size(282, 33);
        this->labelPlayerO->TabIndex = 15;
        this->labelPlayerO->Text = L"0";
        this->labelPlayerO->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // labelPlayerX
        // 
        this->labelPlayerX->BackColor = System::Drawing::Color::WhiteSmoke;
        this->labelPlayerX->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
        this->labelPlayerX->Font = (gcnew System::Drawing::Font(L"MS Gothic", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelPlayerX->Location = System::Drawing::Point(200, 54);
        this->labelPlayerX->Name = L"labelPlayerX";
        this->labelPlayerX->Size = System::Drawing::Size(282, 33);
        this->labelPlayerX->TabIndex = 14;
        this->labelPlayerX->Text = L"0";
        this->labelPlayerX->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // label3
        // 
        this->label3->AutoSize = true;
        this->label3->Font = (gcnew System::Drawing::Font(L"MS Gothic", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label3->Location = System::Drawing::Point(19, 120);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(166, 28);
        this->label3->TabIndex = 13;
        this->label3->Text = L"Jugador O: ";
        this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
        // 
        // label2
        // 
        this->label2->AutoSize = true;
        this->label2->Font = (gcnew System::Drawing::Font(L"MS Gothic", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->Location = System::Drawing::Point(18, 54);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(166, 28);
        this->label2->TabIndex = 1;
        this->label2->Text = L"Jugador X: ";
        this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
        // 
        // newGameButton
        // 
        this->newGameButton->BackColor = System::Drawing::Color::WhiteSmoke;
        this->newGameButton->Location = System::Drawing::Point(14, 349);
        this->newGameButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->newGameButton->Name = L"newGameButton";
        this->newGameButton->Size = System::Drawing::Size(482, 76);
        this->newGameButton->TabIndex = 12;
        this->newGameButton->Text = L"NEW GAME";
        this->newGameButton->UseVisualStyleBackColor = false;
        this->newGameButton->Click += gcnew System::EventHandler(this, &Form1::newGameButton_Click);
        // 
        // resetButton
        // 
        this->resetButton->BackColor = System::Drawing::Color::WhiteSmoke;
        this->resetButton->Location = System::Drawing::Point(14, 223);
        this->resetButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->resetButton->Name = L"resetButton";
        this->resetButton->Size = System::Drawing::Size(482, 76);
        this->resetButton->TabIndex = 11;
        this->resetButton->Text = L"RESET";
        this->resetButton->UseVisualStyleBackColor = false;
        this->resetButton->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->ClientSize = System::Drawing::Size(1386, 778);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->Name = L"Form1";
        this->Text = L"Form1";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->ResumeLayout(false);

    }

    int turn = 1; //1 para X, 2 para O
    //Boolean checker;
    int plusone;//Scoreboard actualizado
    int scoreActual;//Score temporal para calculos
    int scoreX, scoreO = 0;

    //temporales
    int butt1, butt2, butt3, butt4, butt5, butt6, butt7, butt8, butt9 = 0;
    

    
#pragma endregion

   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.
    

    
    
    //Funcion para reiniciar los botones
    void Enable_False() {
        button1->Enabled = false;
        button2->Enabled = false;
        button3->Enabled = false;
        button4->Enabled = false;
        button5->Enabled = false;
        button6->Enabled = false;
        button7->Enabled = false;
        button8->Enabled = false;
        button9->Enabled = false;
    }

    void resetButt() {
        butt1 = 0;
        butt2 = 0;
        butt3 = 0;
        butt4 = 0;
        butt5 = 0;
        butt6 = 0;
        butt7 = 0;
        butt8 = 0;
        butt9 = 0;
    }


    void noseTengoMimi() {
        

        if (button1->Text == "X") {
            butt1 = 5;
        }
        else if (button1->Text == "O") {
            butt1 = 2;
        }
        else {
            butt1 = 0;
        }

        if (button2->Text == "X") {
            butt2 = 5;
        }
        else if (button2->Text == "O") {
            butt2 = 2;
        }
        else {
            butt2 = 0;
        }

        if (button3->Text == "X") {
            butt3 = 5;
        }
        else if (button3->Text == "O") {
            butt3 = 2;
        }
        else {
            butt3 = 0;
        }

        if (button4->Text == "X") {
            butt4 = 5;
        }
        else if (button4->Text == "O") {
            butt4 = 2;
        }
        else {
            butt4 = 0;
        }


        if (button5->Text == "X") {
            butt5 = 5;
        }
        else if (button5->Text == "O") {
            butt5 = 2;
        }
        else {
            butt5 = 0;
            
        }


        if (button6->Text == "X") {
            butt6 = 5;
        }
        else if (button6->Text == "O") {
            butt6 = 2;
        }
        else {
            butt6 = 0;
        }


        if (button7->Text == "X") {
            butt7 = 5;
        }
        else if (button7->Text == "O") {
            butt7 = 2;
        }
        else {
            butt7 = 0;
        }

        if (button8->Text == "X") {
            butt8 = 5;
        }
        else if (button8->Text == "O") {
            butt8 = 2;
        }
        else {
            butt8 = 0;
        }

        if (button9->Text == "X") {
            butt9 = 5;
        }
        else if(button9->Text == "O") {
            butt9 = 2;
        }
        else {
            butt9 = 0;
        }

    }

    void ganadorEncontrado() {
        scoreX = int::Parse(labelPlayerX->Text);
        scoreO = int::Parse(labelPlayerO->Text);
        int ganador = verificarGanador(scoreX, scoreO);
        if (ganador == 24) {
            MessageBox::Show("Ganador Del Juego es X", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            resetButt();
            resetGame();
        }
        else if (ganador == 33) {
            MessageBox::Show("Ganador Del Juego es O", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            resetButt();
            resetGame();
        }
        
    }

    void score() {
        
        noseTengoMimi();
        if (verificarO(butt1,butt2,butt3) == 15) {
            button1->BackColor = System::Drawing::Color::DeepPink;
            button2->BackColor = System::Drawing::Color::DeepPink;
            button3->BackColor = System::Drawing::Color::DeepPink;
            MessageBox::Show("Ganador de la Ronda es: O", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerO->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerO->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarO(butt3, butt5, butt7) == 15) {
            button3->BackColor = System::Drawing::Color::DeepPink;
            button5->BackColor = System::Drawing::Color::DeepPink;
            button7->BackColor = System::Drawing::Color::DeepPink;
            MessageBox::Show("Ganador de la Ronda es: O", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerO->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerO->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        /*if (button1->Text == "O" && button2->Text == "O" && button3->Text == "O") {
            

        }*/
        noseTengoMimi();
        if (verificarO(butt1, butt4, butt7) == 15) {
            button1->BackColor = System::Drawing::Color::DeepPink;
            button4->BackColor = System::Drawing::Color::DeepPink;
            button7->BackColor = System::Drawing::Color::DeepPink;
            MessageBox::Show("Ganador de la Ronda es: O", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerO->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerO->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarO(butt1, butt5, butt9) == 15) {
            button1->BackColor = System::Drawing::Color::DeepPink;
            button5->BackColor = System::Drawing::Color::DeepPink;
            button9->BackColor = System::Drawing::Color::DeepPink;
            MessageBox::Show("Ganador de la Ronda es: O", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerO->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerO->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarO(butt4, butt5, butt6) == 15) {
            button4->BackColor = System::Drawing::Color::DeepPink;
            button5->BackColor = System::Drawing::Color::DeepPink;
            button6->BackColor = System::Drawing::Color::DeepPink;
            MessageBox::Show("Ganador de la Ronda es: O", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerO->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerO->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarO(butt7, butt8, butt9) == 15) {
            button7->BackColor = System::Drawing::Color::DeepPink;
            button8->BackColor = System::Drawing::Color::DeepPink;
            button9->BackColor = System::Drawing::Color::DeepPink;
            MessageBox::Show("Ganador de la Ronda es: O", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerO->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerO->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarO(butt2, butt5, butt8) == 15) {
            button2->BackColor = System::Drawing::Color::DeepPink;
            button5->BackColor = System::Drawing::Color::DeepPink;
            button8->BackColor = System::Drawing::Color::DeepPink;
            MessageBox::Show("Ganador de la Ronda es: O", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerO->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerO->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarO(butt3, butt6, butt9) == 15) {
            button3->BackColor = System::Drawing::Color::DeepPink;
            button6->BackColor = System::Drawing::Color::DeepPink;
            button9->BackColor = System::Drawing::Color::DeepPink;
            MessageBox::Show("Ganador de la Ronda es: O", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerO->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerO->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        /// Verificador de Jugador X
        noseTengoMimi();
        if (verificarX(butt1, butt2, butt3) == 30) {
            button1->BackColor = System::Drawing::Color::PowderBlue;
            button2->BackColor = System::Drawing::Color::PowderBlue;
            button3->BackColor = System::Drawing::Color::PowderBlue;
            MessageBox::Show("Ganador de la Ronda es: X", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerX->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerX->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }

        noseTengoMimi();
        if (verificarX(butt3, butt5, butt7) == 30) {
            button3->BackColor = System::Drawing::Color::PowderBlue;
            button5->BackColor = System::Drawing::Color::PowderBlue;
            button7->BackColor = System::Drawing::Color::PowderBlue;
            MessageBox::Show("Ganador de la Ronda es: X", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerX->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerX->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarX(butt1,butt4,butt7)  == 30) {
            button1->BackColor = System::Drawing::Color::PowderBlue;
            button4->BackColor = System::Drawing::Color::PowderBlue;
            button7->BackColor = System::Drawing::Color::PowderBlue;
            MessageBox::Show("Ganador de la Ronda es: X", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerX->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerX->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarX(butt1, butt5, butt9) == 30) {
            button1->BackColor = System::Drawing::Color::PowderBlue;
            button5->BackColor = System::Drawing::Color::PowderBlue;
            button9->BackColor = System::Drawing::Color::PowderBlue;
            MessageBox::Show("Ganador de la Ronda es: X", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerX->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerX->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarX(butt4, butt5, butt6) == 30) {
            button4->BackColor = System::Drawing::Color::PowderBlue;
            button5->BackColor = System::Drawing::Color::PowderBlue;
            button6->BackColor = System::Drawing::Color::PowderBlue;
            MessageBox::Show("Ganador de la Ronda es: X", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerX->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerX->Text = Convert::ToString(plusone);
            Enable_False();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarX(butt7, butt8, butt9) == 30) {
            button7->BackColor = System::Drawing::Color::PowderBlue;
            button8->BackColor = System::Drawing::Color::PowderBlue;
            button9->BackColor = System::Drawing::Color::PowderBlue;
            MessageBox::Show("Ganador de la Ronda es: X", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerX->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerX->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarX(butt2, butt5, butt8) == 30) {
            button2->BackColor = System::Drawing::Color::PowderBlue;
            button5->BackColor = System::Drawing::Color::PowderBlue;
            button8->BackColor = System::Drawing::Color::PowderBlue;
            MessageBox::Show("Ganador de la Ronda es: X", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);
            scoreActual = int::Parse(labelPlayerX->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerX->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
        }
        noseTengoMimi();
        if (verificarX(butt3, butt6, butt9) == 30) {
            button3->BackColor = System::Drawing::Color::PowderBlue;
            button6->BackColor = System::Drawing::Color::PowderBlue;
            button9->BackColor = System::Drawing::Color::PowderBlue;
            MessageBox::Show("Ganador de la Ronda es: X", "Tic Tac Toe", MessageBoxButtons::OK, MessageBoxIcon::Information);            scoreActual = int::Parse(labelPlayerX->Text);
            plusone = sumarPunto(scoreActual);
            labelPlayerX->Text = Convert::ToString(plusone);
            Enable_False();
            resetButt();
            ganadorEncontrado();
            
        }

    }



  private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
  }
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
  }
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
    resetButt();
    turn = 1;
    button1->Enabled = true;
    button2->Enabled = true;
    button3->Enabled = true;
    button4->Enabled = true;
    button5->Enabled = true;
    button6->Enabled = true;
    button7->Enabled = true;
    button8->Enabled = true;
    button9->Enabled = true;

    button1->Text = "";
    button2->Text = "";
    button3->Text = "";
    button4->Text = "";
    button5->Text = "";
    button6->Text = "";
    button7->Text = "";
    button8->Text = "";
    button9->Text = "";
    newGameButton->Enabled = true;

    button1->BackColor = System::Drawing::Color::WhiteSmoke;
    button2->BackColor = System::Drawing::Color::WhiteSmoke;
    button3->BackColor = System::Drawing::Color::WhiteSmoke;
    button4->BackColor = System::Drawing::Color::WhiteSmoke;
    button5->BackColor = System::Drawing::Color::WhiteSmoke;
    button6->BackColor = System::Drawing::Color::WhiteSmoke;
    button7->BackColor = System::Drawing::Color::WhiteSmoke;
    button8->BackColor = System::Drawing::Color::WhiteSmoke;
    button9->BackColor = System::Drawing::Color::WhiteSmoke;

  }
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    if (turn == 1) {
        button1->Text = "X";
        turn = turnoJugador(turn);
        //turn = 2;
    }
    else {
        button1->Text = "O";
        turn = turnoJugador(turn);
        
    }
    score();
    button1->Enabled = false;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    if (turn == 1) {
        button2->Text = "X";
        turn = turnoJugador(turn);
        //turn = 2;
    }
    else {
        button2->Text = "O";
        turn = turnoJugador(turn);

    }
    score();
    button2->Enabled = false;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
    if (turn == 1) {
        button3->Text = "X";
        turn = turnoJugador(turn);
        //turn = 2;
    }
    else {
        button3->Text = "O";
        turn = turnoJugador(turn);

    }
    score();
    button3->Enabled = false;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
    if (turn == 1) {
        button4->Text = "X";
        turn = turnoJugador(turn);
        //turn = 2;
    }
    else {
        button4->Text = "O";
        turn = turnoJugador(turn);

    }
    score();
    button4->Enabled = false;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
    if (turn == 1) {
        button5->Text = "X";
        turn = turnoJugador(turn);
        //turn = 2;
    }
    else {
        button5->Text = "O";
        turn = turnoJugador(turn);

    }
    score();
    button5->Enabled = false;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
    if (turn == 1) {
        button6->Text = "X";
        turn = turnoJugador(turn);
        //turn = 2;
    }
    else {
        button6->Text = "O";
        turn = turnoJugador(turn);

    }
    score();
    button6->Enabled = false;
}


private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
    if (turn == 1) {
        button7->Text = "X";
        turn = turnoJugador(turn);
        //turn = 2;
    }
    else {
        button7->Text = "O";
        turn = turnoJugador(turn);

    }
    score();
    button7->Enabled = false;
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
    if (turn == 1) {
        button8->Text = "X";
        turn = turnoJugador(turn);
        //turn = 2;
    }
    else {
        button8->Text = "O";
        turn = turnoJugador(turn);

    }
    score();
    button8->Enabled = false;
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
    if (turn == 1) {
        button9->Text = "X";
        turn = turnoJugador(turn);
        //turn = 2;
    }
    else {
        button9->Text = "O";
        turn = turnoJugador(turn);

    }
    score();
    button9->Enabled = false;
}

//Reseteo Automatico
       
       void resetGame() {
           resetButt();
           turn = 1;
           button1->Enabled = true;
           button2->Enabled = true;
           button3->Enabled = true;
           button4->Enabled = true;
           button5->Enabled = true;
           button6->Enabled = true;
           button7->Enabled = true;
           button8->Enabled = true;
           button9->Enabled = true;

           button1->Text = "";
           button2->Text = "";
           button3->Text = "";
           button4->Text = "";
           button5->Text = "";
           button6->Text = "";
           button7->Text = "";
           button8->Text = "";
           button9->Text = "";
           newGameButton->Enabled = true;
           labelPlayerO->Text = "0";
           labelPlayerX->Text = "0";

           button1->BackColor = System::Drawing::Color::WhiteSmoke;
           button2->BackColor = System::Drawing::Color::WhiteSmoke;
           button3->BackColor = System::Drawing::Color::WhiteSmoke;
           button4->BackColor = System::Drawing::Color::WhiteSmoke;
           button5->BackColor = System::Drawing::Color::WhiteSmoke;
           button6->BackColor = System::Drawing::Color::WhiteSmoke;
           button7->BackColor = System::Drawing::Color::WhiteSmoke;
           button8->BackColor = System::Drawing::Color::WhiteSmoke;
           button9->BackColor = System::Drawing::Color::WhiteSmoke;
       }
//Interfaz resetea todo
private: System::Void newGameButton_Click(System::Object^ sender, System::EventArgs^ e) {
    resetButt();
    turn = 1;
    button1->Enabled = true;
    button2->Enabled = true;
    button3->Enabled = true;
    button4->Enabled = true;
    button5->Enabled = true;
    button6->Enabled = true;
    button7->Enabled = true;
    button8->Enabled = true;
    button9->Enabled = true;

    button1->Text = "";
    button2->Text = "";
    button3->Text = "";
    button4->Text = "";
    button5->Text = "";
    button6->Text = "";
    button7->Text = "";
    button8->Text = "";
    button9->Text = "";
    labelPlayerO->Text = "0";
    labelPlayerX->Text = "0";

    button1->BackColor = System::Drawing::Color::WhiteSmoke;
    button2->BackColor = System::Drawing::Color::WhiteSmoke;
    button3->BackColor = System::Drawing::Color::WhiteSmoke;
    button4->BackColor = System::Drawing::Color::WhiteSmoke;
    button5->BackColor = System::Drawing::Color::WhiteSmoke;
    button6->BackColor = System::Drawing::Color::WhiteSmoke;
    button7->BackColor = System::Drawing::Color::WhiteSmoke;
    button8->BackColor = System::Drawing::Color::WhiteSmoke;
    button9->BackColor = System::Drawing::Color::WhiteSmoke;
}


private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
}; // end of class Form1
} // end of namespace CppCLRWinFormsProject



