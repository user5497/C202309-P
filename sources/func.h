#pragma once

struct Expenditure {
	int* budget; // ���� �ݾ� ����
	int* essential_ex; // �ʼ� ���� �ݾ� ����. 
	int* total_expenditure; // ī�װ��� ���� �߻� ��Ȳ 
};

// ī�װ��� ������ �Է¹޴� ���. 
void Input_budget(struct Expenditure* exp, char* category_names, int category_count);

