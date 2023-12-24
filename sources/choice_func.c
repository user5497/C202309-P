#include <stdio.h>
#include "func.h" 


// 소비 금액 저장 기능. 
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
	while (1) {
		if ((input_expenditure = InputIntOnly()) < 0) {// 음수 제외 
			printf("음수는 저장할 수 없습니다. 다시 입력해 주세요.\n");
		}
		else { // 정상 입력. 
			break;
		}
	}

	exp->total_expenditure[input_index] += input_expenditure; // 카테고리별 지출 총액 저장
	exp->cost[input_index] -= input_expenditure; // 예산에서 마이너스

	// 예산 초과 경고만, 음수 연산 허용. 
	if (exp->total_expenditure[input_index] > exp->budget[input_index]) {
		printf("설정 예산을 초과했습니다. \n");
	}


	// 각 예산별 사용 금액과 총 소비액 제시. 
	// 해당 카테고리 사용 금액 / 총 예산 
	printf("해당 카테고리에서의 총 사용 금액:%d / 예산: %d\n", exp->total_expenditure[input_index], exp->budget[input_index]);
	printf("%d원 남았습니다. ", exp->cost[input_index]);

}


// 카테고리 편집 기능. 
void EditCategory(struct Expenditure* exp, char(*category_names)[10], int category_count) {

	int choice_category = 0; // 선택지 선택. 
	int del_category = 0; // 삭제할 카테고리 선택. 

	while (1) {
		printf("(1. 카테고리 삭제, 2. 카테고리 편집 종료): ");
		choice_category = InputIntOnly();

		// 카테고리 삭제 선택. 
		if (choice_category == 1) {

			if (category_count == 1) { // 카테고리 전부 삭제 차단 
				printf("최소 한 개 이상의 카테고리가 존재해야 합니다. ");
				continue;
			}

			printf("삭제를 원하는 카테고리의 번호를 선택해주세요.(예산이 할당되지 않은 카테고리만 삭제할 수 있습니다)\n");
			
			del_category = InputIntOnly(); 
			del_category = del_category-1; // 인덱스 벗어나는 거 방지. 

			// 예산이 할당된 카테고리 제거 금지
			if (exp->budget[del_category] != 0) {
				printf("해당 카테고리에 할당된 예산이 존재합니다. \n");
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


// 달성도 평가(지출 분석 기능)
void Evaludation(struct Expenditure* exp, char(*category_names)[10], int category_count) {
	
	FILE* file;
	fopen_s(&file,"expenditure.txt", "w"); // 1회차 내용만 저장.
	if (file == NULL) {
		printf("파일을 작성할 수 없습니다.\n"); 
		fclose(file);
	}
	

	for (int i = 0; i < category_count; i++) {
		exp->save_budget[i] = exp->budget[i] - exp->total_expenditure[i]; 
		printf("%s에서의 총 사용 금액:%d / 예산: %d (남은금액: %d)\n", category_names[i], exp->total_expenditure[i], exp->budget[i],exp->save_budget[i]);
		printf("사용된 필수 지출 금액: %d\n", exp->essential_ex[i]);
		fprintf(file, "%s에서의 총 사용 금액:%d / 예산: %d (남은금액: %d)\n", category_names[i], exp->total_expenditure[i], exp->budget[i], exp->save_budget[i]);
		
	
		// percentage 수치 저장. 
		if (exp->save_budget[i] == 0) { // 사용 금액과 최초 예산이 같은 경우, 0으로 나누는 경우 차단. 
			exp->save_percentage[i] = 0;
		}
		else {
			exp->save_percentage[i] = ((float)exp->save_budget[i] / exp->budget[i])*100;
		}


		// 예산 초과,미만 지출 여부 판단. 
		if (exp->save_budget[i] > 0) { // 예산 미만 지출
			printf("%f%% 아꼈습니다.\n", ((float)exp->save_percentage[i]));
		}
		else if (exp->save_budget[i] < 0) { // 예산 초과 지출 
			printf("%f%% 초과했습니다.\n", ((float)exp->save_percentage[i]));
		}
		else { // save_budget[i] == 0
			printf("모든 예산을 사용했습니다.\n");
		}

		
		// 예산 추천. 
		if (exp->save_percentage[i] < 0) { // 초과
			if (-150 <= exp->save_percentage[i] && exp->save_percentage[i] <= -100) {
				printf("예산을 초과하여 사용하셨습니다.\n");
				printf("차후 %f원으로 예산을 늘릴 것을 추천합니다.\n ", (float)exp->budget[i] * 1.3);
				fprintf(file, "%s의 예산을 %f원으로 할 것을 추천합니다. ", category_names[i], (float)exp->budget[i] * 1.3);
			}
			else {
				printf("예산을 150%%초과하여 사용하셨습니다.\n");
				printf("차후 %f원으로 예산을 늘릴 것을 추천합니다.\n ", (float)exp->budget[i] * 1.5);
				fprintf(file, "%s의 예산을 %f원으로 설정할 것을 추천합니다.\n ", category_names[i], (float)exp->budget[i] * 1.5);
			}
		}
		
		else if (exp->save_percentage[i] > 0) { // 미만 
			if (exp->save_percentage[i] <= 30) {
				printf("예산의 30%% 이하를 사용하셨습니다.\n"); // 20% 확대 수치로 예산을 설정할 것을 권고 
				printf("차후 %f원으로 예산을 줄일 것을 추천합니다.\n ", (float)exp->budget[i] * 0.5);
				fprintf(file, "%s의 예산을 %f원으로 설정할 것을 추천합니다. ", category_names[i], (float)exp->budget[i] * 0.5);
			}
			else if (30 < exp->save_percentage[i] && exp->save_percentage[i] <= 60) {
				printf("예산의 60%% 이하를 사용하셨습니다.\n");
				printf("차후 %f원으로 예산을 줄일 것을 추천합니다.\n ", (float)exp->budget[i] * 0.8);
				fprintf(file, "%s의 예산을 %f원으로 설정할 것을 추천합니다.\n ", category_names[i], (float)exp->budget[i] * 0.8);
			}
			else if (60 < exp->save_percentage[i] && exp->save_percentage[i] <= 100) {
				printf("60~100%%의 에산을 사용하셨습니다. \n");
				printf("적정 수치입니다.\n");
				fprintf(file, "%s의 예산을 %f원으로 설정할 것을 추천합니다.\n ", category_names[i], (float)exp->budget[i]); // 유지
			}
		}

		else { // (exp->total_expenditure[i] == 0)
			printf("예산을 사용하지 않으셨습니다.\n");
			fprintf(file, "지난 달에 예산을 사용하지 않으셨습니다.\n");
		}

		printf("\n"); //가독성
	}
	fclose(file);
}

