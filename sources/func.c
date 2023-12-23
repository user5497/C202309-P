#include <stdio.h>
#include "func.h" 


// ī�װ��� ������ �Է¹޴� ���. 
void Input_budget(struct Expenditure* exp, char (*category_names)[10], int category_count) {

	FILE* file;
	fopen_s(&file, "expenditure.txt", "r"); 
	if (file == NULL) {
		printf("������ �ۼ��� �� �����ϴ�.\n");
		fclose(file);
	}

	int line_num = 1; // ¦�� �ٸ� ����ϱ� ���� index��.
	char text[100]; // ���� ���� �����


	for (int i = 0; i < category_count; i++) {
		while (fgets(text, sizeof(text), file) != NULL) {
			if (line_num % 2 == 0) { // ¦�� ��
				printf("%s", text);
				break; // �� �ٸ� ���. 
			}
			line_num++;
		}

		fseek(file, 0, SEEK_CUR); // ������ ���� ��ġ�� �̵�
		line_num = 1;

		printf("%s: ", category_names[i]);
	
		while (1) {
			scanf_s("%d", &exp->budget[i]);
			if (exp->budget[i] < 0) { // ���� ����
				printf("������ ������ �� �����ϴ�. �ٽ� �Է��� �ּ���. ");
				continue;
			}
			else {
				break;
			}
		}
		printf("\n");
	}
	
	fclose(file);
	// �׽�Ʈ 
	//for (int i = 0; i < category_count; i++) {
		//printf("%d %d ", i + 1, budget[i]);
	//}
}

// ī�װ��� �ʼ� ���� �ݾ��� �Է¹޴� ���. 
void Input_essential_ex(struct Expenditure* exp, char(* category_names)[10], int category_count) {
	printf("�߻��� �ʼ� ������ �Է����ּ���. ");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) {
			scanf_s("%d", &exp->essential_ex[i]);
			if (exp->budget[i] < exp->essential_ex[i]) {
				printf("������ ���꺸�� ������ �� Ů�ϴ�. �ٽ� �Է��� �ּ���. ");
				continue;
			}
			else if (exp->essential_ex[i] < 0) {
				printf("������ �Է��� �� �����ϴ�. �ٽ� �Է��� �ּ���. ");
				continue;
			}
			else { // ���� ���� �ʼ� ������ ���� ����. 
				exp->budget[i] = exp->budget[i] - exp->essential_ex[i];
				break;
			}
		}
	}
}

