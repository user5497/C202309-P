#include <stdio.h>
#include "func.h" 


// 카테고리별 예산을 입력받는 기능. 
void Input_budget(struct Expenditure* exp, char (*category_names)[10], int category_count) {

	FILE* file;
	fopen_s(&file, "expenditure.txt", "r"); 
	if (file == NULL) {
		printf("파일을 작성할 수 없습니다.\n");
		fclose(file);
	}

	int line_num = 1; // 짝수 줄만 출력하기 위한 index용.
	char text[100]; // 파일 내용 저장용


	for (int i = 0; i < category_count; i++) {
		while (fgets(text, sizeof(text), file) != NULL) {
			if (line_num % 2 == 0) { // 짝수 줄
				printf("%s", text);
				break; // 한 줄만 출력. 
			}
			line_num++;
		}

		fseek(file, 0, SEEK_CUR); // 파일의 현재 위치로 이동
		line_num = 1;

		printf("%s: ", category_names[i]);
	
		while (1) {
			scanf_s("%d", &exp->budget[i]);
			if (exp->budget[i] < 0) { // 음수 제외
				printf("음수는 저장할 수 없습니다. 다시 입력해 주세요. ");
				continue;
			}
			else {
				break;
			}
		}
		printf("\n");
	}
	
	fclose(file);
	// 테스트 
	//for (int i = 0; i < category_count; i++) {
		//printf("%d %d ", i + 1, budget[i]);
	//}
}

// 카테고리별 필수 지출 금액을 입력받는 기능. 
void Input_essential_ex(struct Expenditure* exp, char(* category_names)[10], int category_count) {
	printf("발생할 필수 지출을 입력해주세요. ");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) {
			scanf_s("%d", &exp->essential_ex[i]);
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

