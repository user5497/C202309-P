#pragma once
// 필수 지출액을 입력받는 기능. 
void Input_essential_ex(struct Expenditure* exp, char(*category_names)[10], int category_count);

// 카테고리 편집 기능. 
void EditCategory(struct Expenditure* exp, char(*category_names)[10], int category_count);

// 지출 저장 기능. 
void SaveExpenditure(struct Expenditure* exp, char(*category_names)[10], int category_count);

// 지출 분석 기능
void Evaludation(struct Expenditure* exp, char(*category_names)[10], int category_count);