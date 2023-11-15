#include <stdio.h>

// ���� ���� �ڵ�ȭ ������Ʈ 

// 17�ϱ���: 1. ī�װ� ���� ���, 2. ��� ���� ���� ��� 

// 1. ī�װ� ���� ��ɿ� �߰�/ ������ �ֱ�. (���߿� �ð� ������ )

void EditCategory(); // ī�װ� ���� ���. 
void SaveExpenditure(); // ���� ���� ���. 

char category_names[50][10] = { "�ĺ�", "���", "�Ƿ�", "����", "����", "��Ȱ", "��ü", "��Ÿ" }; // ī�װ��� �̸��� ������ �迭 
int category_count = 7; // ī�װ� ���� ����
int budget[50] = {0}; // ���� �ݾ��� ����. 
int essential_ex[50] = {0}; // �ʼ� ���� �ݾ� ���� ����. 

int main() {
	// 1. ���� ����. 
	printf("�� ī�װ��� ������ �Ҵ��� �ּ���. \n");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		scanf_s("%d", &budget[i]);
	}
	printf("\n");

	// �׽�Ʈ - ���� �߻� �� 
	for (int i = 0; i < category_count; i++) {
		printf("%d %d ", i + 1, budget[i]);
	}
	


	printf("�߻��� �ʼ� ������ �Է����ּ���. ");
	for (int i = 0; i < category_count; i++) {
		printf("%s: ", category_names[i]);
		scanf_s("%d", &essential_ex[i]);
		if (essential_ex[i] != 0) {
			if (budget[i] < essential_ex[i]) {
				printf("������ ���꺸�� ������ �� Ů�ϴ�. �ٽ� �Է��� �ּ���. ");
				// ���� �ʿ� 


			}
			else {
				budget[i] = budget[i] - essential_ex[i];
			}
		}
	}
	printf("���� �Ҵ��� �Ϸ�Ǿ����ϴ�. \n");

	// �Ҵ� �Ϸ� �׽�Ʈ�� ���
	for (int i = 0; i < category_count; i++) {
		printf("%s %d", category_names[i], budget[i]);
	}
	

	// �� �� ���� 
	while (1) {
		int choice; 
		printf("���ϴ� ����� ������ �ּ���. (1. ���� �߰�, 2. ī�װ� ����, 3. ����): ");
		scanf_s("%d", &choice);
		if (choice == 1) {
			printf("���� �׸��� �߰��մϴ�. \n");
			SaveExpenditure();
		}

		else if (choice == 2) {
			printf("���� ī�װ��� �����մϴ�. \n");
			EditCategory();
		}

		else if (choice == 3) {
			printf("���α׷��� �����մϴ�. \n");
			break;
		}

		else {
			printf("�־��� �������� ��� �ּ���. \n"); // ������ �̿� ���� ���� 
			continue;
		}
	}
}



void SaveExpenditure() {
	int expenditure[50][10]; // ������ ������ �迭 
	printf("������ �߻��� ī�װ��� �ݾ��� �Է��� �ּ���. ");
}



void EditCategory() {
	while (1) {
		// ī�װ� ��� 
		for (int i = 0; i < category_count; i++) {
			printf("%d %s ", i + 1, category_names[i]);
		}

		int choice_category;
		printf("(1. ī�װ� ����, 2. ī�װ� ���� ����): ");
		scanf_s("%d", &choice_category);

		if (choice_category == 1) {
			if (category_count== 1) { 
				printf("�ּ� �� �� �̻��� ī�װ��� �����ؾ� �մϴ�. "); // ī�װ� ���� ���� ���� 
			}
			else {
				int del_category;
				printf("������ ���ϴ� ī�װ��� ��ȣ�� �������ּ���.\n");
				scanf_s("%d", &del_category);
				
				// ������ �Ҵ�� �ݾ� ���� ����
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