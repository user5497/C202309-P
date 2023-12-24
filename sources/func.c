#include <stdio.h>
#include "func.h" 


// ī�װ��� ������ �Է¹޴� ���. 
void InputBudget(struct Expenditure* exp, char(*category_names)[10], int category_count) {

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
			if ((exp->budget[i] = InputIntOnly()) < 0) {// ���� ���� 
				printf("������ ������ �� �����ϴ�. �ٽ� �Է��� �ּ���.\n");
			}
			else { // ���� �Է�. 
				break;
			}
		}
		
		printf("\n");
	}

	fclose(file);
	/* �׽�Ʈ
	for (int i = 0; i < category_count; i++) {
		printf("%d %d ", i + 1, exp->budget[i]);
	}
	*/
}

// ī�װ��� �ʼ� ���� �ݾ��� �Է¹޴� ���. 
void InputEssentialEx(struct Expenditure* exp, char(* category_names)[10], int category_count) {
	printf("�߻��� �ʼ� ������ �Է����ּ���. ");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) {

			while (1) {
				if ((exp->essential_ex[i] = InputIntOnly()) < 0) {// ���� ���� 
					printf("������ ������ �� �����ϴ�. �ٽ� �Է��� �ּ���.\n");
					while (getchar() != '\n');
				}
				else { // ���� �Է�. 
					break;
				}
			}

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

// ������ �Է¹޴� ���
int InputIntOnly() {
	int num;

	while (1) { // �Է� ���� ����
		if (scanf_s("%d", &num) != 1) {
			printf("���ڸ� �Է��ؾ� �մϴ�. �ٽ� �Է��� �ּ���.\n");
			while (getchar() != '\n');
		}
		else {
			return num;
		}	
	}
}