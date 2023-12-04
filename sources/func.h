#pragma once

struct Expenditure {
	int* budget; // 예산 금액 저장
	int* essential_ex; // 필수 지출 금액 저장. 
	int* input_expenditure; //지출 저장. 
	int* total_expenditure; // 카테고리별 지출 발생 현황 
};

// 카테고리별 예산을 입력받는 기능. 
void Input_budget(struct Expenditure* exp);

// 필수 지출액을 입력받는 기능. 
void Input_essential_ex(struct Expenditure* exp);

// 카테고리 편집 기능. 
void EditCategory(struct Expenditure* exp);

// 지출 저장 기능. 
void SaveExpenditure(struct Expenditure* exp);