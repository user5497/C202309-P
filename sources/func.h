#pragma once

// 나눌지 고민. 
struct Expenditure { 
	int* budget; // 예산 원형
	int* cost; // 변경될 예산
	int* essential_ex; // 필수 지출 금액 저장. 
	int* total_expenditure; // 카테고리별 지출 발생 현황 
	int* save_budget; // 예산에서 지출을 제한 금액 저장. 연산 편의성을 위해 만들어둠. 
	int* save_percentage; // 아낀 정도를 %로 저장. 
};

// 카테고리별 예산을 입력받는 기능. 
void Input_budget(struct Expenditure* exp, char(*category_names)[10], int category_count);

void Input_essential_ex(struct Expenditure* exp, char(*category_names)[10], int category_count);