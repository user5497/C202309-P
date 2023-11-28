#include <stdio.h>
#include <stdlib.h> // 동적 메모리용
#include <string.h> // strcmp


// 지출 관리 자동화 프로젝트 // 


// 28일정도까지: 지출 분석 기능 - 소비 금액 계산 기능. 
// 각 예산별 사용 금액과 총 소비액을 제시. (소비 금액 입력받는 기능. )

//원본
//char category_names[50][10] = { "식비", "취미", "의료", "교통", "교육", "생활", "이체", "기타" }; // 카테고리의 이름을 저장할 배열
//int category_count = 7; // 카테고리 수를 저장

// 테스트용
char category_names[50][10] = { "식비", "취미"}; 
int category_count = 2;

void EditCategory(int* budget, int* essential_ex); // 카테고리 편집 기능. 
void SaveExpenditure(int* budget, int* essential_ex); // 지출 저장 기능. 

int main() {
	// 1. 예산 설정. 

	int* budget = (int*)malloc(sizeof(int) * category_count); // 예산 금액을 저장. 
	int* essential_ex = (int*)malloc(sizeof(int) * category_count); // 필수 지출 금액 따로 저장. 

	printf("각 카테고리에 예산을 할당해 주세요. \n");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) { // 음수 제외
			scanf_s("%d", &budget[i]);
			if (budget[i] < 0) {
				printf("음수는 저장할 수 없습니다. 다시 입력해 주세요. ");
				continue;
			}
			else {
				break;
			}
		}
	}
	printf("\n");

	// 테스트 
	//for (int i = 0; i < category_count; i++) {
		//printf("%d %d ", i + 1, budget[i]);
	//}


	printf("발생할 필수 지출을 입력해주세요. ");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) {
			scanf_s("%d", &essential_ex[i]);
			if (budget[i] < essential_ex[i]) {
				printf("설정된 예산보다 지출이 더 큽니다. 다시 입력해 주세요. ");
				continue;
			}
			else if (essential_ex < 0) {
				printf("음수는 입력할 수 없습니다. 다시 입력해 주세요. ");
				continue;
			}
			else { // 범위 내의 필수 지출일 때만 저장. 
				budget[i] = budget[i] - essential_ex[i];
				break;
			}
		}
	}
	printf("예산 할당이 완료되었습니다. \n");

	// 할당 완료 테스트용 출력
	for (int i = 0; i < category_count; i++) {
		printf("%s %d ", category_names[i], budget[i]);
	}


	// 할 일 선택 
	while (1) {
		int choice;
		// 종료 버튼을 선택하는 순간 달의 끝으로 여기고 분석 시작. 
		// 파일 생성 기능 같은 거 배우면 달의 종료를 선택할 수 있고, 중간중간에 세이브하도록 개선하기. 
		printf("원하는 기능을 선택해 주세요. (1. 지출 추가, 2. 카테고리 편집, 3. 종료): ");
		scanf_s("%d", &choice);
		if (choice == 1) {
			printf("지출 항목을 추가합니다. \n");
			SaveExpenditure(budget, essential_ex);

		}

		else if (choice == 2) {
			printf("기존 카테고리를 편집합니다. \n");
			EditCategory(budget, essential_ex);
		}

		else if (choice == 3) {
			printf("프로그램을 종료합니다. \n");
			// 분석을 시작합니다. 
			free(budget);
			free(essential_ex);
			break;
		}

		else {
			printf("주어진 선택지를 골라 주세요. \n"); // 선택지 이외 예외 제거 
			continue;
		}
	}
}



void SaveExpenditure(int* budget, int* essential_ex) {
	int input_expenditure = 0; // 지출 저장
	int* total_expenditure = (int*)malloc(sizeof(int) * 100); // 카테고리별 지출 발생 현황
	char* input_cate = (char*)malloc(sizeof(char) * 100); // 지출 발생 카테고리
	int valid_cate = 0; // 카테고리 존재 확인 용도
	int input_index = 0; // 입력받은 카테고리 존재 위치 저장


	printf("지출이 발생한 카테고리를 입력해 주세요. ");
	while (valid_cate !=1) {
		scanf_s("%s", input_cate, (int)sizeof(input_cate));
		for (int i = 0; i < category_count; i++) {
			if (strcmp(input_cate, category_names[i]) == 0) { // strcmp -> 0 일치
				input_index = i; // 카테고리 위치 저장. 
				valid_cate = 1;
				break;
			}
		}
		if (valid_cate == 0) { // 없는 카테고리 입력받는 경우 제외 
			printf("존재하지 않는 카테고리입니다. 다시 입력해 주세요.");
			continue;
		}
	}

	
	// 지출 금액 입력받고 해당 카테고리 예산에서 마이너스
	// 발생하고 있는 지출의 총액도 저장해야 함. 
	printf("발생한 지출 금액을 입력해주세요.");
	scanf_s("%d", &input_expenditure);
	total_expenditure[input_index] += input_expenditure; // 카테고리별지출 총액 저장
	budget[input_index] -= input_expenditure; // 예산에서 마이너스


	// 테스트
	printf("input_expenditure: %d ", input_expenditure);
	printf("budget: %d ",budget[input_index]);

	free(input_cate);
	free(total_expenditure);
}



void EditCategory(int* budget, int* essential_ex) {
	while (1) {
		// 카테고리 출력 
		for (int i = 0; i < category_count; i++) {
			printf("%d %s ", i + 1, category_names[i]);
		}

		int choice_category;
		printf("(1. 카테고리 삭제, 2. 카테고리 편집 종료): ");
		scanf_s("%d", &choice_category);

		if (choice_category == 1) {
			if (category_count == 1) {
				printf("최소 한 개 이상의 카테고리가 존재해야 합니다. "); // 카테고리 전부 삭제 차단 
			}
			else {
				int del_category;
				printf("삭제를 원하는 카테고리의 번호를 선택해주세요.\n");
				scanf_s("%d", &del_category);

				// 예산이 할당된 카테고리 제거 금지
				if (budget[del_category] != 0) {
					printf("해당 카테고리에 할당된 예산이 존재합니다. ");
					break;
				}

				// 배열을 한 칸씩 당겨 삭제.
				for (int i = del_category - 1; i < category_count - 1; i++) {
					for (int j = 0; j < 10; j++) {
						category_names[i][j] = category_names[i + 1][j];
					}
				}
				category_count -= 1;
				printf("삭제가 완료되었습니다.\n");
				printf(category_names);
			}
		}
		else if (choice_category == 2) {
			printf("카테고리 편집을 종료합니다.\n");
			break;
		}
		else {
			printf("잘못된 선택입니다.\n");
		}
	}
}