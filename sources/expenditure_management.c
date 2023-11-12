#include <stdio.h>

// 지출 관리 자동화 프로젝트 

// 17일까지: 1. 카테고리 편집 기능, 2. 당월 예산 저장 기능 

// 1. 지출을 따로 저장할 카테고리를 편집합니다. 
// 카테고리를 삭제하는 기능을 추가합니다. 

// 2. 분류별로 사용할 예산과 총액을 입력받습니다. 
// 필수적으로 발생할 금액을 입력받아 총액과 따로 저장합니다. 


void edit_category(); // 카테고리 편집 기능 



int main() {
	while (1) {
		int choice; 
		printf("원하는 기능을 선택해 주세요. (1. 지출 추가, 2. 카테고리 편집, 3. 종료): ");
		scanf_s("%d", &choice);
		if (choice == 1) {
			printf("지출 항목을 추가합니다. \n");
		}

		else if (choice == 2) {
			printf("기존 카테고리를 편집합니다. \n");
			edit_category();
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

void edit_category() {
	char category_names[50][10] = { "식비", "취미", "의료", "교통", "교육", "생활", "이체", "기타" }; // 카테고리의 이름을 저장할 배열 
	int category_count = 7; // 카테고리 수를 저장


	while (1) {
		// 카테고리 출력 
		for (int i = 0; i < category_count; i++) {
			printf("%d %s ", i + 1, category_names[i]);
		}

		int choice_category;
		printf("(1. 카테고리 삭제, 2. 카테고리 편집 종료): ");
		scanf_s("%d", &choice_category);

		if (choice_category == 1) {
			int del_category;
			printf("삭제를 원하는 카테고리의 번호를 선택해주세요.\n");
			scanf_s("%d", &del_category);

			// 배열을 한 칸씩 당겨 삭제. 
			for (int i = del_category - 1; i < category_count-1; i++) {
				for (int j = 0; j < 10; j++) {
					category_names[i][j] = category_names[i + 1][j];
				}	
			}
			category_count -= 1;
			printf("삭제가 완료되었습니다.\n");
		}
		else if (choice_category == 2) {
			printf("카테고리 편집을 종료합니다.\n");
			break;
		}
		else {
			printf("잘못된 선택입니다.\n");
			continue;
		}
	}
}