#pragma once

struct Expenditure { 
	int* budget; // ���� ����(�ʼ� ���� �ݾ� ����)
	int* cost; // ���� ���̳ʽ� �� ������ ����� ����. 
	int* essential_ex; // �ʼ� ���� �ݾ� ����. 
	int* total_expenditure; // ī�װ��� ���� �߻� ��Ȳ 
	int* save_budget; // ���꿡�� ������ ���� �ݾ� ����. ���� ���Ǽ��� ���� ������. 
	int* save_percentage; // �Ƴ� ������ %�� ����. 
};

// ī�װ��� ������ �Է¹޴� ���. 
void Input_budget(struct Expenditure* exp, char(*category_names)[10], int category_count);

// ī�װ��� �ʼ� ���� �ݾ��� �Է¹޴� ���. 
void Input_essential_ex(struct Expenditure* exp, char(*category_names)[10], int category_count);