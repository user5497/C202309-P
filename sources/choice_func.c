#include "func.h" 

// 시간날 때 프린트문이랑 기능이랑 분리해서 함수 줄이는 작업하기. 


// 지출 저장 기능. 
void SaveExpenditure(struct Expenditure* exp, char(*category_names)[10], int category_count) {

	char input_cate[10]; // 카테고리 최대 글자수 10
	int valid_cate = 0; // 카테고리 존재 확인 용도
	int input_index = 0; // 입력받은 카테고리 존재 위치 저장
	int input_expenditure = 0; //일시적 지출 저장. 


	printf("지출이 발생한 카테고리를 입력해 주세요. ");
	while (valid_cate != 1) {
		scanf_s("%s", &input_cate, (int)sizeof(input_cate));
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



	printf("발생한 지출 금액을 입력해주세요.");
	scanf_s("%d", &input_expenditure);

	// 테스트
	printf("input_index %d\n", input_index);
	// 오류 
	// 이상한 값이 저장되어있음. input_index가 범위 벗어난건가? 저장공간이 부족한가? 
	printf("total_expenditure %d\n", exp->total_expenditure[input_index]);
	


	// 예산 초과 경고만, 음수 연산 허용. 
	if (exp->total_expenditure[input_index] > exp->budget[input_index]) {
		printf("설정 예산을 초과했습니다. \n");
	}

	exp->total_expenditure[input_index] += input_expenditure; // 카테고리별 지출 총액 저장
	exp->cost[input_index] -= input_expenditure; // 예산에서 마이너스
	

	// 각 예산별 사용 금액과 총 소비액을 제시. 
	// 해당 카테고리 사용 금액 / 총 예산
	// 예산 원형 저장 필요성. 
	printf("해당 카테고리에서의 총 사용 금액:%d / 예산: %d\n", exp->total_expenditure[input_index], exp->budget[input_index]);
	printf("%d원 남았습니다. ", exp->total_expenditure[input_index] - exp->budget[input_index]);
}


// 카테고리 편집 기능. 
void EditCategory(struct Expenditure* exp, char(*category_names)[10], int category_count) {

	int choice_category = 0; // 선택지 선택. 
	int del_category = 0; // 삭제할 카테고리 선택. 

	while (1) {
		printf("(1. 카테고리 삭제, 2. 카테고리 편집 종료): ");
		scanf_s("%d", &choice_category);

		// 카테고리 삭제 선택. 
		if (choice_category == 1) {

			if (category_count == 1) { // 카테고리 전부 삭제 차단 
				printf("최소 한 개 이상의 카테고리가 존재해야 합니다. ");
				continue;
			}

			printf("삭제를 원하는 카테고리의 번호를 선택해주세요.\n");
			scanf_s("%d", &del_category);



			//테스트 , 1은 정상 작동하는데 2는 못 받아옴. index 문제인 듯? 
			printf("budget %d",exp->budget[del_category]);

			// 예산이 할당된 카테고리 제거 금지
			if (exp->budget[del_category] != 0) {
				printf("해당 카테고리에 할당된 예산이 존재합니다. ");
				continue;
			}



			// 삭제 진행.
			for (int i = del_category - 1; i < category_count - 1; i++) {
				for (int j = 0; j < 10; j++) {
					category_names[i][j] = category_names[i + 1][j]; // 배열을 한 칸씩 당겨 삭제.
				}
			}
			category_count -= 1;

			printf("삭제가 완료되었습니다.\n");
			printf(category_names);
		
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




// 총 지출액 평가 기능. 
void Evaludation(struct Expenditure* exp, char(*category_names)[10], int category_count) {
	// 지출액이 예산 넘어가면 경고해주기
}