#pragma once
// �ʼ� ������� �Է¹޴� ���. 
void Input_essential_ex(struct Expenditure* exp, char(*category_names)[10], int category_count);

// ī�װ� ���� ���. 
void EditCategory(struct Expenditure* exp, char(*category_names)[10], int category_count);

// ���� ���� ���. 
void SaveExpenditure(struct Expenditure* exp, char(*category_names)[10], int category_count);

// ���� �м� ���
void Evaludation(struct Expenditure* exp, char(*category_names)[10], int category_count);