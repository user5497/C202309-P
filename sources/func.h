#pragma once

struct Expenditure {
	int* budget; // ���� �ݾ� ����
	int* essential_ex; // �ʼ� ���� �ݾ� ����. 
	int* input_expenditure; //���� ����. 
	int* total_expenditure; // ī�װ��� ���� �߻� ��Ȳ 
};

// ī�װ��� ������ �Է¹޴� ���. 
void Input_budget(struct Expenditure* exp);

// �ʼ� ������� �Է¹޴� ���. 
void Input_essential_ex(struct Expenditure* exp);

// ī�װ� ���� ���. 
void EditCategory(struct Expenditure* exp);

// ���� ���� ���. 
void SaveExpenditure(struct Expenditure* exp);