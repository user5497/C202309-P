#pragma once

struct Expenditure {
	int* budget; // ���� ����
	int* cost; // ����� ����
	int* essential_ex; // �ʼ� ���� �ݾ� ����. 
	int* total_expenditure; // ī�װ��� ���� �߻� ��Ȳ 
};

// ī�װ��� ������ �Է¹޴� ���. 
void Input_budget(struct Expenditure* exp, char(*category_names)[10], int category_count);

void Input_essential_ex(struct Expenditure* exp, char(*category_names)[10], int category_count);