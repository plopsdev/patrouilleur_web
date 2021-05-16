#pragma once
# include <string>
# include <iostream>
namespace ArduinoPIDmotorspeed {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			findPorts();
			//
			//TODO: Add the constructor code here
			//
			
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
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		String^ mStr;
		String^ speed;
		String^ speeg;
		int setSpeed;
		int setPos;

	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label7;



	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox6;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel1;



	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox11;

	private: System::Windows::Forms::TextBox^ textBox12;

	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ textBox14;

		   int i;

		   /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			   System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			   System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			   System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			   this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->label17 = (gcnew System::Windows::Forms::Label());
			   this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->label12 = (gcnew System::Windows::Forms::Label());
			   this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			   this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			   this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			   this->label16 = (gcnew System::Windows::Forms::Label());
			   this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			   this->panel3 = (gcnew System::Windows::Forms::Panel());
			   this->panel4 = (gcnew System::Windows::Forms::Panel());
			   this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label13 = (gcnew System::Windows::Forms::Label());
			   this->label14 = (gcnew System::Windows::Forms::Label());
			   this->label15 = (gcnew System::Windows::Forms::Label());
			   this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			   this->groupBox1->SuspendLayout();
			   this->groupBox2->SuspendLayout();
			   this->groupBox4->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // serialPort1
			   // 
			   this->serialPort1->PortName = L"COM9";
			   this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Form1::serialPort1_DataReceived_1);
			   // 
			   // button2
			   // 
			   this->button2->BackColor = System::Drawing::Color::Chartreuse;
			   this->button2->Location = System::Drawing::Point(81, 26);
			   this->button2->Margin = System::Windows::Forms::Padding(4);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(109, 36);
			   this->button2->TabIndex = 0;
			   this->button2->Text = L"Run motor";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click_1);
			   // 
			   // button3
			   // 
			   this->button3->BackColor = System::Drawing::Color::Gray;
			   this->button3->Location = System::Drawing::Point(81, 69);
			   this->button3->Margin = System::Windows::Forms::Padding(4);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(109, 38);
			   this->button3->TabIndex = 1;
			   this->button3->Text = L"Stop motor";
			   this->button3->UseVisualStyleBackColor = false;
			   this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click_1);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(11, 35);
			   this->textBox1->Margin = System::Windows::Forms::Padding(4);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(113, 22);
			   this->textBox1->TabIndex = 2;
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(296, 35);
			   this->textBox2->Margin = System::Windows::Forms::Padding(4);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(112, 22);
			   this->textBox2->TabIndex = 3;
			   this->textBox2->Text = L"0.015";
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(372, 77);
			   this->button1->Margin = System::Windows::Forms::Padding(4);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(112, 36);
			   this->button1->TabIndex = 6;
			   this->button1->Text = L"SET Values";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			   // 
			   // textBox3
			   // 
			   this->textBox3->Location = System::Drawing::Point(413, 35);
			   this->textBox3->Margin = System::Windows::Forms::Padding(4);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(112, 22);
			   this->textBox3->TabIndex = 4;
			   this->textBox3->Text = L"0.01";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(8, 16);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(123, 17);
			   this->label1->TabIndex = 6;
			   this->label1->Text = L"Set SpeedG (rpm)";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(296, 16);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(24, 17);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"kP";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(413, 16);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(18, 17);
			   this->label3->TabIndex = 8;
			   this->label3->Text = L"kI";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(534, 16);
			   this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(25, 17);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"kD";
			   // 
			   // textBox4
			   // 
			   this->textBox4->Location = System::Drawing::Point(534, 35);
			   this->textBox4->Margin = System::Windows::Forms::Padding(4);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(111, 22);
			   this->textBox4->TabIndex = 5;
			   this->textBox4->Text = L"0.01";
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick_1);
			   // 
			   // chart1
			   // 
			   chartArea1->Name = L"ChartArea1";
			   this->chart1->ChartAreas->Add(chartArea1);
			   this->chart1->Location = System::Drawing::Point(22, 173);
			   this->chart1->Margin = System::Windows::Forms::Padding(4);
			   this->chart1->Name = L"chart1";
			   series1->ChartArea = L"ChartArea1";
			   series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			   series1->Color = System::Drawing::Color::Red;
			   series1->IsVisibleInLegend = false;
			   series1->MarkerColor = System::Drawing::Color::White;
			   series1->Name = L"Series1";
			   series2->ChartArea = L"ChartArea1";
			   series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			   series2->Color = System::Drawing::Color::Blue;
			   series2->Name = L"Series2";
			   this->chart1->Series->Add(series1);
			   this->chart1->Series->Add(series2);
			   this->chart1->Size = System::Drawing::Size(1054, 385);
			   this->chart1->TabIndex = 11;
			   this->chart1->Text = L"chart1";
			   title1->Name = L"RPM function of time";
			   this->chart1->Titles->Add(title1);
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->label17);
			   this->groupBox1->Controls->Add(this->textBox14);
			   this->groupBox1->Controls->Add(this->panel2);
			   this->groupBox1->Controls->Add(this->panel1);
			   this->groupBox1->Controls->Add(this->textBox7);
			   this->groupBox1->Controls->Add(this->label5);
			   this->groupBox1->Controls->Add(this->label7);
			   this->groupBox1->Controls->Add(this->textBox5);
			   this->groupBox1->Controls->Add(this->textBox4);
			   this->groupBox1->Controls->Add(this->label4);
			   this->groupBox1->Controls->Add(this->label3);
			   this->groupBox1->Controls->Add(this->label2);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->textBox3);
			   this->groupBox1->Controls->Add(this->button1);
			   this->groupBox1->Controls->Add(this->textBox2);
			   this->groupBox1->Controls->Add(this->textBox1);
			   this->groupBox1->Location = System::Drawing::Point(261, 10);
			   this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			   this->groupBox1->Size = System::Drawing::Size(654, 147);
			   this->groupBox1->TabIndex = 13;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Setting";
			   // 
			   // label17
			   // 
			   this->label17->AutoSize = true;
			   this->label17->Location = System::Drawing::Point(137, 16);
			   this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label17->Name = L"label17";
			   this->label17->Size = System::Drawing::Size(122, 17);
			   this->label17->TabIndex = 20;
			   this->label17->Text = L"Set SpeedD (rpm)";
			   // 
			   // textBox14
			   // 
			   this->textBox14->Location = System::Drawing::Point(146, 35);
			   this->textBox14->Margin = System::Windows::Forms::Padding(4);
			   this->textBox14->Name = L"textBox14";
			   this->textBox14->Size = System::Drawing::Size(113, 22);
			   this->textBox14->TabIndex = 19;
			   // 
			   // panel2
			   // 
			   this->panel2->BackColor = System::Drawing::Color::Blue;
			   this->panel2->Location = System::Drawing::Point(277, 94);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(15, 18);
			   this->panel2->TabIndex = 18;
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::Red;
			   this->panel1->Location = System::Drawing::Point(126, 92);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(15, 18);
			   this->panel1->TabIndex = 17;
			   // 
			   // textBox7
			   // 
			   this->textBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(224)));
			   this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->textBox7->Enabled = false;
			   this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox7->ForeColor = System::Drawing::Color::Black;
			   this->textBox7->Location = System::Drawing::Point(157, 92);
			   this->textBox7->Margin = System::Windows::Forms::Padding(4);
			   this->textBox7->Name = L"textBox7";
			   this->textBox7->ReadOnly = true;
			   this->textBox7->Size = System::Drawing::Size(113, 20);
			   this->textBox7->TabIndex = 16;
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(154, 71);
			   this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(133, 17);
			   this->label5->TabIndex = 15;
			   this->label5->Text = L"Motor 2 speed(rpm)";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(8, 71);
			   this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(133, 17);
			   this->label7->TabIndex = 14;
			   this->label7->Text = L"Motor 1 speed(rpm)";
			   // 
			   // textBox5
			   // 
			   this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(224)));
			   this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->textBox5->Enabled = false;
			   this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox5->ForeColor = System::Drawing::Color::Black;
			   this->textBox5->Location = System::Drawing::Point(8, 91);
			   this->textBox5->Margin = System::Windows::Forms::Padding(4);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->ReadOnly = true;
			   this->textBox5->Size = System::Drawing::Size(113, 20);
			   this->textBox5->TabIndex = 13;
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->Controls->Add(this->button7);
			   this->groupBox2->Controls->Add(this->label12);
			   this->groupBox2->Controls->Add(this->textBox6);
			   this->groupBox2->Controls->Add(this->label9);
			   this->groupBox2->Controls->Add(this->comboBox3);
			   this->groupBox2->Controls->Add(this->comboBox4);
			   this->groupBox2->Controls->Add(this->label11);
			   this->groupBox2->Controls->Add(this->button4);
			   this->groupBox2->Location = System::Drawing::Point(22, 2);
			   this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			   this->groupBox2->Size = System::Drawing::Size(1085, 556);
			   this->groupBox2->TabIndex = 18;
			   this->groupBox2->TabStop = false;
			   // 
			   // button7
			   // 
			   this->button7->Location = System::Drawing::Point(279, 128);
			   this->button7->Margin = System::Windows::Forms::Padding(4);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(100, 36);
			   this->button7->TabIndex = 22;
			   this->button7->Text = L"INIT POS";
			   this->button7->UseVisualStyleBackColor = true;
			   this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			   // 
			   // label12
			   // 
			   this->label12->AutoSize = true;
			   this->label12->Location = System::Drawing::Point(415, 60);
			   this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label12->Name = L"label12";
			   this->label12->Size = System::Drawing::Size(31, 17);
			   this->label12->TabIndex = 21;
			   this->label12->Text = L"Info";
			   // 
			   // textBox6
			   // 
			   this->textBox6->Location = System::Drawing::Point(418, 84);
			   this->textBox6->Multiline = true;
			   this->textBox6->Name = L"textBox6";
			   this->textBox6->ReadOnly = true;
			   this->textBox6->Size = System::Drawing::Size(237, 80);
			   this->textBox6->TabIndex = 18;
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Location = System::Drawing::Point(59, 140);
			   this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(66, 17);
			   this->label9->TabIndex = 17;
			   this->label9->Text = L"Baudrate";
			   // 
			   // comboBox3
			   // 
			   this->comboBox3->FormattingEnabled = true;
			   this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"9600", L"115200" });
			   this->comboBox3->Location = System::Drawing::Point(132, 137);
			   this->comboBox3->Name = L"comboBox3";
			   this->comboBox3->Size = System::Drawing::Size(121, 24);
			   this->comboBox3->TabIndex = 16;
			   this->comboBox3->Text = L"9600";
			   // 
			   // comboBox4
			   // 
			   this->comboBox4->FormattingEnabled = true;
			   this->comboBox4->Location = System::Drawing::Point(132, 91);
			   this->comboBox4->Name = L"comboBox4";
			   this->comboBox4->Size = System::Drawing::Size(121, 24);
			   this->comboBox4->TabIndex = 15;
			   this->comboBox4->Text = L"COM4";
			   // 
			   // label11
			   // 
			   this->label11->AutoSize = true;
			   this->label11->Location = System::Drawing::Point(68, 94);
			   this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(39, 17);
			   this->label11->TabIndex = 12;
			   this->label11->Text = L"COM";
			   // 
			   // button4
			   // 
			   this->button4->Location = System::Drawing::Point(279, 80);
			   this->button4->Margin = System::Windows::Forms::Padding(4);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(100, 35);
			   this->button4->TabIndex = 6;
			   this->button4->Text = L"INIT SPEED";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			   // 
			   // groupBox4
			   // 
			   this->groupBox4->Controls->Add(this->textBox13);
			   this->groupBox4->Controls->Add(this->label16);
			   this->groupBox4->Controls->Add(this->trackBar1);
			   this->groupBox4->Controls->Add(this->panel3);
			   this->groupBox4->Controls->Add(this->panel4);
			   this->groupBox4->Controls->Add(this->textBox8);
			   this->groupBox4->Controls->Add(this->label6);
			   this->groupBox4->Controls->Add(this->label8);
			   this->groupBox4->Controls->Add(this->textBox9);
			   this->groupBox4->Controls->Add(this->textBox10);
			   this->groupBox4->Controls->Add(this->label10);
			   this->groupBox4->Controls->Add(this->label13);
			   this->groupBox4->Controls->Add(this->label14);
			   this->groupBox4->Controls->Add(this->label15);
			   this->groupBox4->Controls->Add(this->textBox11);
			   this->groupBox4->Controls->Add(this->textBox12);
			   this->groupBox4->Location = System::Drawing::Point(252, 5);
			   this->groupBox4->Margin = System::Windows::Forms::Padding(4);
			   this->groupBox4->Name = L"groupBox4";
			   this->groupBox4->Padding = System::Windows::Forms::Padding(4);
			   this->groupBox4->Size = System::Drawing::Size(836, 152);
			   this->groupBox4->TabIndex = 14;
			   this->groupBox4->TabStop = false;
			   this->groupBox4->Text = L"Setting";
			   // 
			   // textBox13
			   // 
			   this->textBox13->Location = System::Drawing::Point(77, 112);
			   this->textBox13->Margin = System::Windows::Forms::Padding(4);
			   this->textBox13->Name = L"textBox13";
			   this->textBox13->Size = System::Drawing::Size(112, 22);
			   this->textBox13->TabIndex = 22;
			   this->textBox13->Text = L"0";
			   this->textBox13->DoubleClick += gcnew System::EventHandler(this, &Form1::textBox13_DoubleClick);
			   // 
			   // label16
			   // 
			   this->label16->AutoSize = true;
			   this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label16->Location = System::Drawing::Point(115, 74);
			   this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label16->Name = L"label16";
			   this->label16->Size = System::Drawing::Size(120, 25);
			   this->label16->TabIndex = 21;
			   this->label16->Text = L"Position (°)";
			   // 
			   // trackBar1
			   // 
			   this->trackBar1->Location = System::Drawing::Point(8, 28);
			   this->trackBar1->Maximum = 1920;
			   this->trackBar1->Name = L"trackBar1";
			   this->trackBar1->Size = System::Drawing::Size(375, 56);
			   this->trackBar1->TabIndex = 20;
			   this->trackBar1->TabStop = false;
			   this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			   // 
			   // panel3
			   // 
			   this->panel3->BackColor = System::Drawing::Color::Blue;
			   this->panel3->Location = System::Drawing::Point(699, 118);
			   this->panel3->Name = L"panel3";
			   this->panel3->Size = System::Drawing::Size(15, 18);
			   this->panel3->TabIndex = 18;
			   // 
			   // panel4
			   // 
			   this->panel4->BackColor = System::Drawing::Color::Red;
			   this->panel4->Location = System::Drawing::Point(548, 116);
			   this->panel4->Name = L"panel4";
			   this->panel4->Size = System::Drawing::Size(15, 18);
			   this->panel4->TabIndex = 17;
			   // 
			   // textBox8
			   // 
			   this->textBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(224)));
			   this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->textBox8->Enabled = false;
			   this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox8->ForeColor = System::Drawing::Color::Black;
			   this->textBox8->Location = System::Drawing::Point(579, 116);
			   this->textBox8->Margin = System::Windows::Forms::Padding(4);
			   this->textBox8->Name = L"textBox8";
			   this->textBox8->ReadOnly = true;
			   this->textBox8->Size = System::Drawing::Size(113, 20);
			   this->textBox8->TabIndex = 16;
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(576, 95);
			   this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(129, 17);
			   this->label6->TabIndex = 15;
			   this->label6->Text = L"Motor 2 position (°)";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Location = System::Drawing::Point(430, 95);
			   this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(129, 17);
			   this->label8->TabIndex = 14;
			   this->label8->Text = L"Motor 1 position (°)";
			   // 
			   // textBox9
			   // 
			   this->textBox9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(224)));
			   this->textBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->textBox9->Enabled = false;
			   this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox9->ForeColor = System::Drawing::Color::Black;
			   this->textBox9->Location = System::Drawing::Point(430, 115);
			   this->textBox9->Margin = System::Windows::Forms::Padding(4);
			   this->textBox9->Name = L"textBox9";
			   this->textBox9->ReadOnly = true;
			   this->textBox9->Size = System::Drawing::Size(113, 20);
			   this->textBox9->TabIndex = 13;
			   // 
			   // textBox10
			   // 
			   this->textBox10->Location = System::Drawing::Point(628, 55);
			   this->textBox10->Margin = System::Windows::Forms::Padding(4);
			   this->textBox10->Name = L"textBox10";
			   this->textBox10->Size = System::Drawing::Size(111, 22);
			   this->textBox10->TabIndex = 5;
			   this->textBox10->Text = L"0.1";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Location = System::Drawing::Point(628, 36);
			   this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(25, 17);
			   this->label10->TabIndex = 9;
			   this->label10->Text = L"kD";
			   // 
			   // label13
			   // 
			   this->label13->AutoSize = true;
			   this->label13->Location = System::Drawing::Point(507, 36);
			   this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label13->Name = L"label13";
			   this->label13->Size = System::Drawing::Size(18, 17);
			   this->label13->TabIndex = 8;
			   this->label13->Text = L"kI";
			   // 
			   // label14
			   // 
			   this->label14->AutoSize = true;
			   this->label14->Location = System::Drawing::Point(390, 36);
			   this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label14->Name = L"label14";
			   this->label14->Size = System::Drawing::Size(24, 17);
			   this->label14->TabIndex = 7;
			   this->label14->Text = L"kP";
			   // 
			   // label15
			   // 
			   this->label15->AutoSize = true;
			   this->label15->Location = System::Drawing::Point(63, 9);
			   this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label15->Name = L"label15";
			   this->label15->Size = System::Drawing::Size(102, 17);
			   this->label15->TabIndex = 6;
			   this->label15->Text = L"Set position (°)";
			   // 
			   // textBox11
			   // 
			   this->textBox11->Location = System::Drawing::Point(507, 55);
			   this->textBox11->Margin = System::Windows::Forms::Padding(4);
			   this->textBox11->Name = L"textBox11";
			   this->textBox11->Size = System::Drawing::Size(112, 22);
			   this->textBox11->TabIndex = 4;
			   this->textBox11->Text = L"0.1";
			   // 
			   // textBox12
			   // 
			   this->textBox12->Location = System::Drawing::Point(390, 55);
			   this->textBox12->Margin = System::Windows::Forms::Padding(4);
			   this->textBox12->Name = L"textBox12";
			   this->textBox12->Size = System::Drawing::Size(112, 22);
			   this->textBox12->TabIndex = 3;
			   this->textBox12->Text = L"0.5";
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1124, 620);
			   this->Controls->Add(this->groupBox2);
			   this->Controls->Add(this->chart1);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->groupBox4);
			   this->Controls->Add(this->groupBox1);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Form1";
			   this->Text = L"Form1";
			   this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load_1);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   this->groupBox4->ResumeLayout(false);
			   this->groupBox4->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion


	private: void findPorts(void) {
		array<Object^>^ objectArray = SerialPort::GetPortNames();
		this->comboBox4->Items->AddRange(objectArray);
	}

	private: System::Void Form1_Load_1(System::Object^ sender, System::EventArgs^ e) {
		groupBox2->Show();
		groupBox1->Hide();
		this->chart1->ChartAreas["ChartArea1"]->AxisY->Maximum = setSpeed + 500;
	}
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		serialPort1->WriteLine("vs_start");	//start motor
	}
	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
		serialPort1->WriteLine("vs_stop");		//stop motor
	}
	private: System::Void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) {
		i++;
		
		array<wchar_t>^ id = {':'};
		array<String^>^ StringArray = mStr->Split(':');

		
			this->chart1->Series["Series1"]->Points->AddXY(i, StringArray[0]);
			textBox5->Text = StringArray[0];
			textBox9->Text = StringArray[0];
		try {
			this->chart1->Series["Series2"]->Points->AddXY(i, StringArray[1]);
			textBox7->Text = StringArray[1];
			textBox8->Text = StringArray[1];
				
			
		}
		catch (Exception^) {
			;
		}
		
			this->chart1->ChartAreas["ChartArea1"]->AxisX->Minimum = i - 500;	//shift x-axis
			this->chart1->ChartAreas["ChartArea1"]->AxisY->Minimum = 0;
		

	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		try {
			setSpeed = System::Convert::ToInt32(textBox1->Text);
			this->chart1->ChartAreas["ChartArea1"]->AxisY->Maximum = setSpeed + 300;	//adjust y-axis max value
			serialPort1->WriteLine("vs_speedG" + textBox1->Text);	//send set_speed to Arduino
			serialPort1->WriteLine("vs_speedD" + textBox14->Text);	//send set_speed to Arduino
			serialPort1->WriteLine("vs_kp" + textBox2->Text);	//send kP to Arduino
			serialPort1->WriteLine("vs_ki" + textBox3->Text);	//send kI to Arduino
			serialPort1->WriteLine("vs_kd" + textBox4->Text);	//send kD to Arduino
		}
		catch (Exception^) {
		
			MessageBox::Show("Complete all fields");
		}
	}
	private: System::Void serialPort1_DataReceived_1(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
		try {
			mStr = serialPort1->ReadLine();
		}
		catch (Exception^) {
			MessageBox::Show("Can't read messages from device");
		}
	}
	
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox6->Text = String::Empty;
		if (this->comboBox3->Text == String::Empty || this->comboBox4->Text == String::Empty)
			this->textBox6->Text = "Please Select Port Settings";
		else {
			try {
				// make sure port isn't open	
				if (!this->serialPort1->IsOpen) {
					this->serialPort1->PortName = this->comboBox4->Text;
					//this->textBox1->Text=this->comboBox1->Text;
					this->serialPort1->BaudRate = Int32::Parse(this->comboBox3->Text);
					//this->textBox1->Text=this->comboBox2->Text;
					//open serial port 
					this->serialPort1->Open();
					timer1->Start();
					mStr = "0";
					i = 300;
					groupBox2->Hide();
					groupBox1->Show();
					groupBox4->Hide();

				}
				else
					this->textBox6->Text = "Port isn't openned";
			}
			catch (Exception^) {
				this->textBox6->Text = "Port access denied";
			}
			

		}
	}




private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	
	 this->label16->Text = trackBar1->Value.ToString();
	 try {
		 setPos = System::Convert::ToInt32(trackBar1->Value.ToString());
		 this->chart1->ChartAreas["ChartArea1"]->AxisY->Maximum = setPos + 300;	//adjust y-axis max value
		 serialPort1->WriteLine("vs_set_pos" + trackBar1->Value.ToString());	//send set_POSITION to Arduino
		 serialPort1->WriteLine("vs_kp" + textBox12->Text);	//send kP to Arduino
		 serialPort1->WriteLine("vs_ki" + textBox11->Text);	//send kI to Arduino
		 serialPort1->WriteLine("vs_kd" + textBox10->Text);	//send kD to Arduino
	 }
	 catch (Exception^) {

		 MessageBox::Show("Complete all fields");
	 }
	 
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBox6->Text = String::Empty;
	if (this->comboBox3->Text == String::Empty || this->comboBox4->Text == String::Empty)
		this->textBox6->Text = "Please Select Port Settings";
	else {
		try {
			// make sure port isn't open	
			if (!this->serialPort1->IsOpen) {
				this->serialPort1->PortName = this->comboBox4->Text;
				//this->textBox1->Text=this->comboBox1->Text;
				this->serialPort1->BaudRate = Int32::Parse(this->comboBox3->Text);
				//this->textBox1->Text=this->comboBox2->Text;
				//open serial port 
				this->serialPort1->Open();
				timer1->Start();
				mStr = "0";
				i = 300;
				groupBox2->Hide();
				groupBox1->Hide();
				groupBox4->Show();

			}
			else
				this->textBox6->Text = "Port isn't openned";
		}
		catch (Exception^) {
			this->textBox6->Text = "Port access denied";
		}


	}

}


private: System::Void textBox13_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	try {
		setPos = System::Convert::ToInt32(textBox13->Text);
		this->chart1->ChartAreas["ChartArea1"]->AxisY->Maximum = setPos + 300;	//adjust y-axis max value
		serialPort1->WriteLine("vs_set_pos" + textBox13->Text);	//send set_POSITION to Arduino
		serialPort1->WriteLine("vs_kp" + textBox12->Text);	//send kP to Arduino
		serialPort1->WriteLine("vs_ki" + textBox11->Text);	//send kI to Arduino
		serialPort1->WriteLine("vs_kd" + textBox10->Text);	//send kD to Arduino
	}
	catch (Exception^) {

		MessageBox::Show("Complete all fields");
	}
}


};
	
}



	

