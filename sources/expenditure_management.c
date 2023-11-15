#include <stdio.h>

// 지출 관리 자동화 프로젝트 

// 17일까지: 1. 카테고리 편집 기능, 2. 당월 예산 저장 기능 

// 1. 카테고리 편집 기능에 추가/ 편집도 넣기. (나중에 시간 남으면 )

void EditCategory(); // 카테고리 편집 기능. 
void SaveExpenditure(); // 지출 저장 기능. 

char category_names[50][10] = { "식비", "취미", "의료", "교통", "교육", "생활", "이체", "기타" }; // 카테고리의 이름을 저장할 배열 
int category_count = 7; // 카테고리 수를 저장
int budget[50] = {0}; // 예산 금액을 저장. 
int essential_ex[50] = {0}; // 필수 지출 금액 따로 저장. 

int main() {
	// 1. 예산 설정. 
	printf("각 카테고리에 예산을 할당해 주세요. \n");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		scanf_s("%d", &budget[i]);
	}
	printf("\n");

	// 테스트 - 오류 발생 중 
	for (int i = 0; i < category_count; i++) {
		printf("%d %d ", i + 1, budget[i]);
	}
	


	printf("발생할 필수 지출을 입력해주세요. ");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		scanf_s("%d", &essential_ex[i]);
		if (essential_ex[i] != 0) {
			if (budget[i] < essential_ex[i]) {
				printf("설정된 예산보다 지출이 더 큽니다. 다시 입력해 주세요. ");
				// 구현 필요 


			}
			else {
				budget[i] = budget[i] - essential_ex[i];
			}
		}
	}
	printf("예산 할당이 완료되었습니다. \n");

	// 할당 완료 테스트용 출력
	for (int i = 0; i < category_count; i++) {
		printf("%s %d", category_names[i], budget[i]);
	}
	

	// 할 일 선택 
	while (1) {
		int choice; 
		printf("원하는 기능을 선택해 주세요. (1. 지출 추가, 2. 카테고리 편집, 3. 종료): ");
		scanf_s("%d", &choice);
		if (choice == 1) {
			printf("지출 항목을 추가합니다. \n");
			SaveExpenditure();
		}

		else if (choice == 2) {
			printf("기존 카테고리를 편집합니다. \n");
			EditCategory();
		}

		else if (choice == 3) {
			printf("프로그램을 종료합니다. \n");
			break;
		}

		else {
			printf("주어진 선택지를 골라 주세요. \n"); // 선택지 이외 예외 제거 
			continue;
		}
	}
}



void SaveExpenditure() {
	int expenditure[50][10]; // 지출을 저장할 배열 
	printf("지출이 발생한 카테고리와 금액을 입력해 주세요. ");
}



void EditCategory() {
	while (1) {
		// 카테고리 출력 
		for (int i = 0; i < category_count; i++) {
			printf("%d %s ", i + 1, category_names[i]);
		}

		int choice_category;
		printf("(1. 카테고리 삭제, 2. 카테고리 편집 종료): ");
		scanf_s("%d", &choice_category);

		if (choice_category == 1) {
			if (category_count== 1) { 
				printf("최소 한 개 이상의 카테고리가 존재해야 합니다. "); // 카테고리 전부 삭제 차단 
			}
			else {
				int del_category;
				printf("삭제를 원하는 카테고리의 번호를 선택해주세요.\n");
				scanf_s("%d", &del_category);
				
				// 예산이 할당된 금액 제거 금지
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