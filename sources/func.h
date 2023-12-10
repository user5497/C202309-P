#pragma once

struct Expenditure {
	int* budget; // 예산 원형
	int* cost; // 변경될 예산
	int* essential_ex; // 필수 지출 금액 저장. 
	int* total_expenditure; // 카테고리별 지출 발생 현황 
};

// 카테고리별 예산을 입력받는 기능. 
void Input_budget(struct Expenditure* exp, char(*category_names)[10], int category_count);

void Input_essential_ex(struct Expenditure* exp, char(*category_names)[10], int category_count);