#include <stdio.h>
#include <stdlib.h> // ���� �޸𸮿�
#include <string.h> // strcmp


// ���� ���� �ڵ�ȭ ������Ʈ // 


// 28����������: ���� �м� ��� - �Һ� �ݾ� ��� ���. 
// �� ���꺰 ��� �ݾװ� �� �Һ���� ����. (�Һ� �ݾ� �Է¹޴� ���. )

//����
//char category_names[50][10] = { "�ĺ�", "���", "�Ƿ�", "����", "����", "��Ȱ", "��ü", "��Ÿ" }; // ī�װ��� �̸��� ������ �迭
//int category_count = 7; // ī�װ� ���� ����

// �׽�Ʈ��
char category_names[50][10] = { "�ĺ�", "���"}; 
int category_count = 2;

void EditCategory(int* budget, int* essential_ex); // ī�װ� ���� ���. 
void SaveExpenditure(int* budget, int* essential_ex); // ���� ���� ���. 

int main() {
	// 1. ���� ����. 

	int* budget = (int*)malloc(sizeof(int) * category_count); // ���� �ݾ��� ����. 
	int* essential_ex = (int*)malloc(sizeof(int) * category_count); // �ʼ� ���� �ݾ� ���� ����. 

	printf("�� ī�װ��� ������ �Ҵ��� �ּ���. \n");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) { // ���� ����
			scanf_s("%d", &budget[i]);
			if (budget[i] < 0) {
				printf("������ ������ �� �����ϴ�. �ٽ� �Է��� �ּ���. ");
				continue;
			}
			else {
				break;
			}
		}
	}
	printf("\n");

	// �׽�Ʈ 
	//for (int i = 0; i < category_count; i++) {
		//printf("%d %d ", i + 1, budget[i]);
	//}


	printf("�߻��� �ʼ� ������ �Է����ּ���. ");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		while (1) {
			scanf_s("%d", &essential_ex[i]);
			if (budget[i] < essential_ex[i]) {
				printf("������ ���꺸�� ������ �� Ů�ϴ�. �ٽ� �Է��� �ּ���. ");
				continue;
			}
			else if (essential_ex < 0) {
				printf("������ �Է��� �� �����ϴ�. �ٽ� �Է��� �ּ���. ");
				continue;
			}
			else { // ���� ���� �ʼ� ������ ���� ����. 
				budget[i] = budget[i] - essential_ex[i];
				break;
			}
		}
	}
	printf("���� �Ҵ��� �Ϸ�Ǿ����ϴ�. \n");

	// �Ҵ� �Ϸ� �׽�Ʈ�� ���
	for (int i = 0; i < category_count; i++) {
		printf("%s %d ", category_names[i], budget[i]);
	}


	// �� �� ���� 
	while (1) {
		int choice;
		// ���� ��ư�� �����ϴ� ���� ���� ������ ����� �м� ����. 
		// ���� ���� ��� ���� �� ���� ���� ���Ḧ ������ �� �ְ�, �߰��߰��� ���̺��ϵ��� �����ϱ�. 
		printf("���ϴ� ����� ������ �ּ���. (1. ���� �߰�, 2. ī�װ� ����, 3. ����): ");
		scanf_s("%d", &choice);
		if (choice == 1) {
			printf("���� �׸��� �߰��մϴ�. \n");
			SaveExpenditure(budget, essential_ex);

		}

		else if (choice == 2) {
			printf("���� ī�װ��� �����մϴ�. \n");
			EditCategory(budget, essential_ex);
		}

		else if (choice == 3) {
			printf("���α׷��� �����մϴ�. \n");
			// �м��� �����մϴ�. 
			free(budget);
			free(essential_ex);
			break;
		}

		else {
			printf("�־��� �������� ��� �ּ���. \n"); // ������ �̿� ���� ���� 
			continue;
		}
	}
}



void SaveExpenditure(int* budget, int* essential_ex) {
	int input_expenditure = 0; // ���� ����
	int* total_expenditure = (int*)malloc(sizeof(int) * 100); // ī�װ��� ���� �߻� ��Ȳ
	char* input_cate = (char*)malloc(sizeof(char) * 100); // ���� �߻� ī�װ�
	int valid_cate = 0; // ī�װ� ���� Ȯ�� �뵵
	int input_index = 0; // �Է¹��� ī�װ� ���� ��ġ ����


	printf("������ �߻��� ī�װ��� �Է��� �ּ���. ");
	while (valid_cate !=1) {
		scanf_s("%s", input_cate, (int)sizeof(input_cate));
		for (int i = 0; i < category_count; i++) {
			if (strcmp(input_cate, category_names[i]) == 0) { // strcmp -> 0 ��ġ
				input_index = i; // ī�װ� ��ġ ����. 
				valid_cate = 1;
				break;
			}
		}
		if (valid_cate == 0) { // ���� ī�װ� �Է¹޴� ��� ���� 
			printf("�������� �ʴ� ī�װ��Դϴ�. �ٽ� �Է��� �ּ���.");
			continue;
		}
	}

	
	// ���� �ݾ� �Է¹ް� �ش� ī�װ� ���꿡�� ���̳ʽ�
	// �߻��ϰ� �ִ� ������ �Ѿ׵� �����ؾ� ��. 
	printf("�߻��� ���� �ݾ��� �Է����ּ���.");
	scanf_s("%d", &input_expenditure);
	total_expenditure[input_index] += input_expenditure; // ī�װ������� �Ѿ� ����
	budget[input_index] -= input_expenditure; // ���꿡�� ���̳ʽ�


	// �׽�Ʈ
	printf("input_expenditure: %d ", input_expenditure);
	printf("budget: %d ",budget[input_index]);

	free(input_cate);
	free(total_expenditure);
}



void EditCategory(int* budget, int* essential_ex) {
	while (1) {
		// ī�װ� ��� 
		for (int i = 0; i < category_count; i++) {
			printf("%d %s ", i + 1, category_names[i]);
		}

		int choice_category;
		printf("(1. ī�װ� ����, 2. ī�װ� ���� ����): ");
		scanf_s("%d", &choice_category);

		if (choice_category == 1) {
			if (category_count == 1) {
				printf("�ּ� �� �� �̻��� ī�װ��� �����ؾ� �մϴ�. "); // ī�װ� ���� ���� ���� 
			}
			else {
				int del_category;
				printf("������ ���ϴ� ī�װ��� ��ȣ�� �������ּ���.\n");
				scanf_s("%d", &del_category);

				// ������ �Ҵ�� ī�װ� ���� ����
				if (budget[del_category] != 0) {
					printf("�ش� ī�װ��� �Ҵ�� ������ �����մϴ�. ");
					break;
				}

				// �迭�� �� ĭ�� ��� ����.
				for (int i = del_category - 1; i < category_count - 1; i++) {
					for (int j = 0; j < 10; j++) {
						category_names[i][j] = category_names[i + 1][j];
					}
				}
				category_count -= 1;
				printf("������ �Ϸ�Ǿ����ϴ�.\n");
				printf(category_names);
			}
		}
		else if (choice_category == 2) {
			printf("ī�װ� ������ �����մϴ�.\n");
			break;
		}
		else {
			printf("�߸��� �����Դϴ�.\n");
		}
	}
}