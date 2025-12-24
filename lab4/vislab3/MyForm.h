#pragma once

#include "Stdr.h"
#include "postfix.h"
#include <msclr/marshal_cppstd.h>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

namespace vislab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class MyForm : public Form
	{
	private:
		stdr* stdrr;
		Table* t;

		TextBox^ textBox2;
		Button^ button2;
		Button^ buttonCalculate;
		RichTextBox^ richTextBox2;
		RichTextBox^ richTextBox3;
		DataGridView^ dataGridView1;        // Таблица приоритетов
		DataGridView^ dataGridViewVars;     // Таблица переменных
		Label^ label2;
		Label^ label3;
		Label^ label5;
		Label^ label6;
		Label^ labelVars;
		Label^ labelResult;


		DataGridViewTextBoxColumn^ Column1;
		DataGridViewTextBoxColumn^ Column2;
		DataGridViewTextBoxColumn^ Column3;
		DataGridViewTextBoxColumn^ Column4;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->Column1 = (gcnew DataGridViewTextBoxColumn());
			this->Column2 = (gcnew DataGridViewTextBoxColumn());
			this->Column3 = (gcnew DataGridViewTextBoxColumn());
			this->Column4 = (gcnew DataGridViewTextBoxColumn());
			this->label2 = (gcnew Label());
			this->textBox2 = (gcnew TextBox());
			this->label3 = (gcnew Label());
			this->button2 = (gcnew Button());
			this->buttonCalculate = (gcnew Button());
			this->dataGridView1 = (gcnew DataGridView());
			this->dataGridViewVars = (gcnew DataGridView());
			this->richTextBox2 = (gcnew RichTextBox());
			this->richTextBox3 = (gcnew RichTextBox());
			this->label5 = (gcnew Label());
			this->label6 = (gcnew Label());
			this->labelVars = (gcnew Label());
			this->labelResult = (gcnew Label());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewVars))->BeginInit();
			this->SuspendLayout();

			// label2
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(12, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(191, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Введите задачу:";

			// textBox2
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->textBox2->Location = System::Drawing::Point(209, 83);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(446, 26);
			this->textBox2->TabIndex = 1;

			// label3
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::IndianRed;
			this->label3->Location = System::Drawing::Point(234, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(327, 37);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Постфиксная форма";

			// button2
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
			this->button2->Location = System::Drawing::Point(661, 69);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(98, 52);
			this->button2->TabIndex = 4;
			this->button2->Text = L"перевести";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew EventHandler(this, &MyForm::button2_Click);

			// dataGridView1 — таблица приоритетов
			this->dataGridView1->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< DataGridViewColumn^ >(4) {
				this->Column1, this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 490);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(411, 59);
			this->dataGridView1->TabIndex = 5;

			this->Column1->HeaderText = L"(";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column2->HeaderText = L")";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column3->HeaderText = L"+-";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column4->HeaderText = L"*/";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;

			// richTextBox2 — postfix output
			this->richTextBox2->BackColor = SystemColors::Info;
			this->richTextBox2->Location = System::Drawing::Point(40, 148);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(694, 150);
			this->richTextBox2->TabIndex = 6;

			// richTextBox3 — stack animation
			this->richTextBox3->BackColor = SystemColors::Info;
			this->richTextBox3->Location = System::Drawing::Point(40, 321);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->Size = System::Drawing::Size(694, 150);
			this->richTextBox3->TabIndex = 7;

			// label5
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(368, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 17);
			this->label5->TabIndex = 9;
			this->label5->Text = L"postfix";

			// label6
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(344, 301);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 17);
			this->label6->TabIndex = 10;
			this->label6->Text = L"StackAnimation";

			// labelVars — надпись "Переменные"
			this->labelVars->AutoSize = true;
			this->labelVars->Location = System::Drawing::Point(430, 490);
			this->labelVars->Text = L"Переменные:";
			this->labelVars->Visible = false;

			// dataGridViewVars — таблица для ввода значений переменных
			this->dataGridViewVars->Location = System::Drawing::Point(430, 510);
			this->dataGridViewVars->Size = System::Drawing::Size(250, 100);
			this->dataGridViewVars->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewVars->AllowUserToAddRows = false;
			this->dataGridViewVars->ReadOnly = false;
			this->dataGridViewVars->Visible = false;

			// buttonCalculate
			this->buttonCalculate->Location = System::Drawing::Point(690, 510);
			this->buttonCalculate->Size = System::Drawing::Size(80, 30);
			this->buttonCalculate->Text = L"Вычислить";
			this->buttonCalculate->Click += gcnew EventHandler(this, &MyForm::buttonCalculate_Click);
			this->buttonCalculate->Visible = false;

			// labelResult
			this->labelResult->Location = System::Drawing::Point(690, 550);
			this->labelResult->AutoSize = true;
			this->labelResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, FontStyle::Bold));
			this->labelResult->Text = L"";
			this->labelResult->Visible = true;

			// Form
			this->ClientSize = System::Drawing::Size(800, 620);
			this->Controls->Add(this->labelResult);
			this->Controls->Add(this->buttonCalculate);
			this->Controls->Add(this->dataGridViewVars);
			this->Controls->Add(this->labelVars);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold));
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewVars))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	public:
		MyForm(void)
		{
			InitializeComponent();
			t = new Table();
			stdrr = new stdr(t);
			dataGridView1->Rows->Add("0", "1", "2", "3");
		}

	protected:
		~MyForm()
		{
			delete stdrr;
			delete t;
			if (components) delete components;
		}

	private:
		void DisplayStack(::Stack<char>& stack, const std::string& output) {
			if (stack.isEmpty()) {
				richTextBox3->Text = "{}";
			}
			else {
				::Stack<char> temp = stack;
				std::string rev = "";
				while (!temp.isEmpty()) {
					rev = temp.Top() + std::string(" ") + rev;
					temp.Pop();
				}
				if (!rev.empty() && rev.back() == ' ') {
					rev.pop_back();
				}
				richTextBox3->Text = "{ " + gcnew String(rev.c_str()) + "}";
			}
			richTextBox2->Text = gcnew String(output.c_str());
			richTextBox3->ScrollToCaret();
			Application::DoEvents();
			System::Threading::Thread::Sleep(500);
		}

		int getPriority(char op) {
			switch (op) {
			case '(': return 0;
			case ')': return 1;
			case '+':
			case '-': return 2;
			case '*':
			case '/': return 3;
			default:  return -1;
			}
		}

		std::string ReplaceVariables(const std::string& infix, const std::map<char, long>& varMap)
		{
			std::string result = "";
			for (char c : infix)
			{
				if (std::isalpha(static_cast<unsigned char>(c)))
				{
					auto it = varMap.find(c);
					if (it == varMap.end())
						throw std::runtime_error("Не задано значение для переменной: " + std::string(1, c));
					result += std::to_string(it->second);
				}
				else
				{
					result += c;
				}
			}
			return result;
		}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox2->Text = "";
		richTextBox3->Text = "";
		labelResult->Text = "";

		String^ input = textBox2->Text;
		if (input->Trim()->Length == 0) {
			MessageBox::Show("Введите выражение!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		msclr::interop::marshal_context ctx;
		std::string nativeInput = ctx.marshal_as<std::string>(input);

		stdrr->setText(nativeInput);
		if (!stdrr->isValid()) {
			MessageBox::Show("Строка не прошла проверку!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Сбор уникальных переменных
		std::set<char> variables;
		for (char c : nativeInput) {
			if (std::isalpha(static_cast<unsigned char>(c))) {
				variables.insert(c);
			}
		}

		// Настройка таблицы переменных
		dataGridViewVars->Rows->Clear();
		dataGridViewVars->Columns->Clear();

		auto colVar = gcnew DataGridViewTextBoxColumn();
		colVar->HeaderText = "Переменная";
		colVar->ReadOnly = true;
		dataGridViewVars->Columns->Add(colVar);

		auto colVal = gcnew DataGridViewTextBoxColumn();
		colVal->HeaderText = "Значение";
		dataGridViewVars->Columns->Add(colVal);

		for (char var : variables) {
			array<String^>^ row = { gcnew String(std::string(1, var).c_str()), "" };
			dataGridViewVars->Rows->Add(row);
		}

		// Показать/скрыть UI для переменных
		bool hasVars = !variables.empty();
		labelVars->Visible = hasVars;
		dataGridViewVars->Visible = hasVars;
		buttonCalculate->Visible = hasVars;
		// НИЧЕГО НЕ ВЫВОДИМ в richTextBox
	}

	private: System::Void buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::map<char, long> varMap;

		for each (DataGridViewRow ^ row in dataGridViewVars->Rows)
		{
			if (!row->Cells[0]->Value || !row->Cells[1]->Value) continue;
			String^ varStr = row->Cells[0]->Value->ToString();
			String^ valStr = row->Cells[1]->Value->ToString();

			if (varStr->Length != 1) continue;
			char var = static_cast<char>(varStr[0]);
			if (!std::isalpha(static_cast<unsigned char>(var))) continue;

			long val;
			try {
				val = System::Convert::ToInt64(valStr);
			}
			catch (...) {
				MessageBox::Show("Некорректное значение для переменной: " + varStr, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			varMap[var] = val;
		}

		// Получаем исходное инфиксное выражение
		msclr::interop::marshal_context ctx;
		std::string infix = ctx.marshal_as<std::string>(textBox2->Text);

		// Заменяем переменные на числа
		std::string numericInfix;
		try {
			numericInfix = ReplaceVariables(infix, varMap);
		}
		catch (const std::exception& ex) {
			MessageBox::Show(gcnew String(ex.what()), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		richTextBox2->Text = "";
		richTextBox3->Text = "";
		labelResult->Text = "";

		std::string output = "";
		::Stack<char> opStack;
		DisplayStack(opStack, output);

		try {
			for (char c : numericInfix) {
				if (std::isdigit(static_cast<unsigned char>(c))) {
					output += c;
				}
				else if (c == '(') {
					opStack.Push(c);
				}
				else if (c == ')') {
					while (!opStack.isEmpty() && opStack.Top() != '(') {
						output += opStack.Top();
						opStack.Pop();
						DisplayStack(opStack, output);
					}
					if (!opStack.isEmpty() && opStack.Top() == '(') {
						opStack.Pop();
					}
				}
				else if (c == '+' || c == '-' || c == '*' || c == '/') {
					while (!opStack.isEmpty() &&
						opStack.Top() != '(' &&
						getPriority(opStack.Top()) >= getPriority(c)) {
						output += opStack.Top();
						opStack.Pop();
						DisplayStack(opStack, output);
					}
					opStack.Push(c);
				}
				DisplayStack(opStack, output);
			}

			while (!opStack.isEmpty()) {
				output += opStack.Top();
				opStack.Pop();
				DisplayStack(opStack, output);
			}
		}
		catch (...) {
			MessageBox::Show("Ошибка в анимации вычисления!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		
		std::string spacedInfix = "";
		for (char c : numericInfix) {
			if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
				spacedInfix += " ";
				spacedInfix += c;
				spacedInfix += " ";
			}
			else {
				spacedInfix += c;
			}
		}

		
		std::istringstream cleanIss(spacedInfix);
		std::string token, cleanInfix = "";
		while (cleanIss >> token) {
			if (!cleanInfix.empty()) cleanInfix += " ";
			cleanInfix += token;
		}

		// Преобразуем в постфикс с пробелами
		std::string postfixWithSpaces = "";
		::Stack<char> evalStack;

		std::istringstream exprIss(cleanInfix);
		while (exprIss >> token) {
			if (std::all_of(token.begin(), token.end(), ::isdigit)) {
				postfixWithSpaces += token + " ";
			}
			else if (token == "(") {
				evalStack.Push('(');
			}
			else if (token == ")") {
				while (!evalStack.isEmpty() && evalStack.Top() != '(') {
					postfixWithSpaces += evalStack.Top();
					postfixWithSpaces += " ";
					evalStack.Pop();
				}
				if (!evalStack.isEmpty()) evalStack.Pop(); // убрать '('
			}
			else if (token == "+" || token == "-" || token == "*" || token == "/") {
				char op = token[0];
				while (!evalStack.isEmpty() && evalStack.Top() != '(' &&
					getPriority(evalStack.Top()) >= getPriority(op)) {
					postfixWithSpaces += evalStack.Top();
					postfixWithSpaces += " ";
					evalStack.Pop();
				}
				evalStack.Push(op);
			}
		}

		while (!evalStack.isEmpty()) {
			postfixWithSpaces += evalStack.Top();
			postfixWithSpaces += " ";
			evalStack.Pop();
		}

		if (!postfixWithSpaces.empty() && postfixWithSpaces.back() == ' ')
			postfixWithSpaces.pop_back();

		// === ВЫЧИСЛЕНИЕ ===
		try {
			long result = EvaluatePostfix(postfixWithSpaces);
			labelResult->Text = "Результат: " + result.ToString();
		}
		catch (const std::exception& ex) {
			MessageBox::Show(gcnew String(ex.what()), "Ошибка вычисления", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private:
		long EvaluatePostfix(const std::string& expr) {
			::Stack<long> stack;
			std::istringstream iss(expr);
			std::string token;

			while (iss >> token) {
				if (token == "+" || token == "-" || token == "*" || token == "/") {
					if (stack.isEmpty())
						throw std::runtime_error("Недостаточно операндов");
					long b = stack.Top(); stack.Pop();
					if (stack.isEmpty())
						throw std::runtime_error("Недостаточно операндов");
					long a = stack.Top(); stack.Pop();

					if (token == "+") stack.Push(a + b);
					else if (token == "-") stack.Push(a - b);
					else if (token == "*") stack.Push(a * b);
					else if (token == "/") {
						if (b == 0)
							throw std::runtime_error("Деление на ноль");
						stack.Push(a / b);
					}
				}
				else {
					try {
						long num = std::stol(token);
						stack.Push(num);
					}
					catch (...) {
						throw std::runtime_error("Некорректный токен: " + token);
					}
				}
			}

			if (stack.isEmpty())
				throw std::runtime_error("Пустое выражение");
			if (stack.getSize() != 1)
				throw std::runtime_error("Лишние операнды в выражении");

			return stack.Top();
		}
	};
}