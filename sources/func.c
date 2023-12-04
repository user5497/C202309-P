#include "func.h" 

// 카테고리별 예산을 입력받는 기능. 
void Input_budget(struct Expenditure* exp) {
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) { // 음수 제외
			scanf_s("%d", exp->budget[i]);
			if (exp->budget[i] < 0) {
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
}

void Input_essential_ex(struct Expenditure* exp) {
	printf("발생할 필수 지출을 입력해주세요. ");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) {
			scanf_s("%d", exp->essential_ex[i]);
			if (exp->budget[i] < exp->essential_ex[i]) {
				printf("설정된 예산보다 지출이 더 큽니다. 다시 입력해 주세요. ");
				continue;
			}
			else if (exp->essential_ex[i] < 0) {
				printf("음수는 입력할 수 없습니다. 다시 입력해 주세요. ");
				continue;
			}
			else { // 범위 내의 필수 지출일 때만 저장. 
				exp->budget[i] = exp->budget[i] - exp->essential_ex[i];
				break;
			}
		}
	}
}

// 카테고리 편집 기능. 
// 조금 줄일까 고민중
void EditCategory(struct Expenditure* exp,int category_count) {
	while (1) {
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

// 지출 저장 기능. 
void SaveExpenditure(int* budget, int* essential_ex) {
	char* input_cate = (char*)malloc(sizeof(char) * 100); // 지출 발생 카테고리
	int valid_cate = 0; // 카테고리 존재 확인 용도
	int input_index = 0; // 입력받은 카테고리 존재 위치 저장


	int input_expenditure = 0; // 지출 저장
	int* total_expenditure = (int*)malloc(sizeof(int) * 100); // 카테고리별 지출 발생 현황


	printf("지출이 발생한 카테고리를 입력해 주세요. ");
	while (valid_cate != 1) {
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
	printf("budget: %d ", budget[input_index]);

	free(input_cate);
	free(total_expenditure);
}