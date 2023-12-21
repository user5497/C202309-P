#include "func.h" 
#include <stdio.h>

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
		scanf_s("%d", &choice_category);

		// 카테고리 삭제 선택. 
		if (choice_category == 1) {

			if (category_count == 1) { // 카테고리 전부 삭제 차단 
				printf("최소 한 개 이상의 카테고리가 존재해야 합니다. ");
				continue;
			}

			printf("삭제를 원하는 카테고리의 번호를 선택해주세요.\n");
			scanf_s("%d", &del_category);

			del_category = del_category-1; // 인덱스 벗어나는 거 방지. 

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


// 달성도 평가(지출 분석 기능)
void Evaludation(struct Expenditure* exp, char(*category_names)[10], int category_count) {

	// 파일 생성 기능 같은 거 배우면 달의 종료를 선택할 수 있고, 중간중간에 세이브하도록 개선하기. 
	// 파일 기능 추가하면 서류 기능 부분도 수정하기.
	// 최초 예산 설정 시 추천하고 시작하도록 개선하기 - > 누적 추천 기능 개선? 시간 없을 듯. 
	// 테스트 기능, 미완 
	/*
	FILE* file;
	fopen_s(&file,"expenditure.txt", "a");
	if (file != NULL) {
		fclose(file);
		printf("파일을 열 수 없습니다. 작성할 수 없습니다.\n"); // 개선 고민. 
	}
	*/

	


	for (int i = 0; i < category_count; i++) {
		exp->save_budget[i] = exp->budget[i] - exp->total_expenditure[i]; 
		printf("%s에서의 총 사용 금액:%d / 예산: %d (남은금액: %d)\n", category_names[i], exp->total_expenditure[i], exp->budget[i],exp->save_budget[i]);
		//fprintf(file, "%s에서의 총 사용 금액:%d / 예산: %d (남은금액: %d)\n", category_names[i], exp->total_expenditure[i], exp->budget[i], exp->save_budget[i]);
		// fprintf(file,"최초 예산, 필수 지출 예산."); 
		

		// 추천 기능
		// 아낀 금액도 저장할 필요성. 
		// 10% ~30% 사용 -> 예산을 너무 크게 설정함. 50%(20% 확대) 수치로 예산을 설정할 것을 권고 
		// 31%~60% 사용 -> 예산을 크게 설정한 것으로 간주, 80% 수치로 예산 축소 권고 
		// 61 ~ 80% 사용 -> 적정 수치로 간주. 
		// 81 ~ 100% 사용 -> 적정 수치이나, 위험 경고 제시. 

		// 101 ~ 150 -> 너무 적은 예산 설정, 130% 정도 예산 확대 권고 
		// 151~~~ -> 150% 수치로 예산 확대 권고 
		

		// 사용 금액과 최초 예산이 같은 경우, 0으로 나누는 경우 차단. 
		if (exp->save_budget[i] == 0) { 
			printf("모든 예산을 사용했습니다.\n");
		}
		else if (exp->save_budget[i] > 0) { // 예산 미만 지출
			printf("%2f%% 아꼈습니다.\n", ((float)exp->save_budget[i]/exp->budget[i])*100);
		}
		else if (exp->save_budget[i] < 0) { // 예산 초과 지출 
			printf("%2f%% 초과했습니다.\n", ((float)exp->save_budget[i]/exp->budget[i])*100);
		}
		else {
			printf("전부 사용했습니다. ");
		}
	}
	//fclose(file);
	

	
}



