#include <stdio.h>
#include <stdlib.h> // 동적 메모리용
#include <string.h> // strcmp
#include "func.h" 
#include "choice_func.h"

// 지출 관리 자동화 프로젝트 // 


char category_names[50][10] = { "식비", "취미", "의료", "교통", "교육", "생활", "이체", "기타" }; // 카테고리의 이름을 저장할 배열
int category_count = 7; // 카테고리 수를 저장


int main() {
	// 1. 예산 설정. 
	struct Expenditure* exp = (struct Expenditure*)malloc(category_count * sizeof(struct Expenditure));

	// 예산과 필수 지출 배열 동적 할당. 
	exp->budget = (int*)malloc(category_count * sizeof(int));
	exp->cost = (int*)malloc(category_count * sizeof(int));
	exp->essential_ex = (int*)malloc(category_count * sizeof(int));
	
	// 카테고리별 지출 발생 현황, 
	exp->total_expenditure = (int*)malloc(category_count * sizeof(int));

	// 아낀 정도를 저장. 
	exp->save_budget = (int*)malloc(category_count * sizeof(int));
	exp->save_percentage = (int*)malloc(category_count * sizeof(int));


	// 메모리 할당 실패 처리 
	if (exp->budget == NULL || exp->cost == NULL || exp->essential_ex == NULL || exp->total_expenditure == NULL || exp->save_budget == NULL) {
		printf("메모리 할당에 실패했습니다.\n");
		exit(EXIT_FAILURE); // 종료 
	}

	// 초기화
	for (int i = 0; i < category_count; i++) {
		exp->total_expenditure[i] = 0;
		exp->cost[i] = 0;
		exp->save_budget[i] = 0;
		exp->save_percentage[i] = 0;
	}
	

	// 카테고리별 예산 입력받기.
	printf("각 카테고리에 예산을 할당해 주세요. \n");
	InputBudget(exp, category_names, category_count);

	// 필수 지출 금액 저장. 
	InputEssentialEx(exp, category_names, category_count);


	printf("\n예산 할당이 완료되었습니다. \n");
	// 원형복사하기 
	memcpy(exp->cost, exp->budget, category_count * sizeof(int));

	// 할당 완료 테스트용 출력
	//for (int i = 0; i < category_count; i++) {
		//printf("%s %d ", category_names[i], exp->cost[i]);
	//}


	// 할 일 선택 
	while (1) {
		int choice;
		printf("원하는 기능을 선택해 주세요. (1. 지출 추가, 2. 카테고리 편집, 3. 종료):");
		choice = InputIntOnly();

		if (choice == 1) {
			printf("\n지출 항목을 추가합니다. \n");
			SaveExpenditure(exp, &category_names, category_count);
		}


		else if (choice == 2) {
			printf("\n기존 카테고리를 편집합니다. \n");
			// 카테고리 출력 
			for (int i = 0; i < category_count; i++) {
				printf("%d %s ", i + 1, category_names[i]);
			}
			EditCategory(exp, &category_names, category_count);
		}


		else if (choice == 3) {
			int save_on = 0; // 평가 기능 활성화 여부 
			printf("\n지출 분석을 시작하겠습니까? (1. 활성화 / 0. 종료): ");
			save_on = InputIntOnly();

			if (save_on == 1) {
				Evaludation(exp, &category_names, category_count);
				break;
			}
			else if (save_on == 0) {
				printf("프로그램을 종료합니다. \n");
				break;
			}
			else {
				printf("선택지를 골라 주세요. ");
				continue;
			}

			// 메모리 할당 해제, 
			free(exp->budget);
			free(exp->cost);
			free(exp->essential_ex);
			free(exp->total_expenditure);
			free(exp->save_budget);
			free(exp->save_percentage);
			
			break;
		}


		else {
			printf("주어진 선택지를 골라 주세요. \n"); // 선택지 이외 예외 제거 
			continue;
		}
	}
}