#include <stdio.h>
#include <stdlib.h> // 동적 메모리용
#include <string.h> // strcmp
#include "func.h" 
#include "choice_func.h"

// 지출 관리 자동화 프로젝트 // 


//원본
//char category_names[50][10] = { "식비", "취미", "의료", "교통", "교육", "생활", "이체", "기타" }; // 카테고리의 이름을 저장할 배열
//int category_count = 7; // 카테고리 수를 저장
// 테스트용
char category_names[50][10] = { "식비", "취미" };
int category_count = 2;
// 카테고리 수랑 이름도 나중에 파일 입출력 기능 배우면 구조체에 넣는 거 시도해보기

int main() {
	// 1. 예산 설정. 
	// 예산 원형 따로 저장해두기 
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
		exp->save_percentage = 0;
	}
	

	// 카테고리별 예산 입력받기.
	printf("각 카테고리에 예산을 할당해 주세요. \n");
	Input_budget(exp, category_names, category_count);

	// 필수 지출 금액 저장. 
	Input_essential_ex(exp, category_names, category_count);


	printf("예산 할당이 완료되었습니다. \n");
	// 원형복사하기 
	memcpy(exp->cost, exp->budget, category_count * sizeof(int));


	// 할당 완료 테스트용 출력
	//for (int i = 0; i < category_count; i++) {
		//printf("%s %d ", category_names[i], exp->cost[i]);
	//}


	// 할 일 선택 
	while (1) {
		int choice;
		printf("원하는 기능을 선택해 주세요. (1. 지출 추가, 2. 카테고리 편집, 3. 종료): \n");
		scanf_s("%d", &choice);

		if (choice == 1) {
			printf("지출 항목을 추가합니다. \n");
			SaveExpenditure(exp, &category_names, category_count);
		}


		else if (choice == 2) {
			printf("기존 카테고리를 편집합니다. \n");
			// 카테고리 출력 
			for (int i = 0; i < category_count; i++) {
				printf("%d %s ", i + 1, category_names[i]);
			}
			EditCategory(exp, &category_names, category_count);
		}


		else if (choice == 3) {
			int save_on = 0; // 평가 기능 활성화 여부 
			printf("지출 분석을 시작하겠습니까? (1. 활성화 / 0. 종료): ");
			scanf_s("%d", &save_on);
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

			// 메모리 할당 해제, 여기 확인 필요. 
			for (int i = 0; i < category_count; i++) {
				free(exp->budget[i]);
				free(exp->cost[i]);
				free(exp->essential_ex[i]);
				free(exp->total_expenditure[i]);
				free(exp->save_budget[i]);
			}
			break;
		}


		else {
			printf("주어진 선택지를 골라 주세요. \n"); // 선택지 이외 예외 제거 
			continue;
		}
	}
}



// 12/15 달성도 평가 완성하기 
// 예산을 아낀 정도에 의한 달성도 평가. 


// 22일 최종 기능: 예산 설정 추천 기능 진행하기. 
// 지난 활동 베이스 
// 시간 남으면 보안 기능(비밀번호 입력으로 입장) 기능 추가하기. 



