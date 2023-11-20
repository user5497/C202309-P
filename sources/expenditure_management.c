#include <stdio.h>
#include <string.h> // strcmp
// ���� ���� �ڵ�ȭ ������Ʈ 

// 28����������: ���� �м� ��� - �Һ� �ݾ� ��� ���. 
// �� ���꺰 ��� �ݾװ� �� �Һ���� ����. (�Һ� �ݾ� �Է¹޴� ���. )

// 1. ī�װ� ���� ��ɿ� �߰�/ ������ �ֱ�. (���߿� �ð� ������ )

void EditCategory(); // ī�װ� ���� ���. 
void SaveExpenditure(); // ���� ���� ���. 

char category_names[50][10] = { "�ĺ�", "���", "�Ƿ�", "����", "����", "��Ȱ", "��ü", "��Ÿ" }; // ī�װ��� �̸��� ������ �迭 
int category_count = 7; // ī�װ� ���� ����
int budget[50] = { 0 }; // ���� �ݾ��� ����. 
int essential_ex[50] = { 0 }; // �ʼ� ���� �ݾ� ���� ����. 


int main() {
	// 1. ���� ����. 
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
	//for (int i = 0; i < category_count; i++) {
		//printf("%s %d ", category_names[i], budget[i]);
	//}
	

	// �� �� ���� 
	while (1) {
		int choice; 
		// ���� ��ư�� �����ϴ� ���� ���� ������ ����� �м� ����. 
		// ���� ���� ��� ���� �� ���� ���� ���Ḧ ������ �� �ְ�, �߰��߰��� ���̺��ϵ��� �����ϱ�. 
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
			// �м��� �����մϴ�. 
			break;
		}

		else {
			printf("�־��� �������� ��� �ּ���. \n"); // ������ �̿� ���� ���� 
			continue;
		}
	}
}



void SaveExpenditure() {
	int expenditure[50]; // ������ ������ �迭 
	char input_cate[1][10]; // ���� �߻� ī�װ� 
	int valid_cate = 0; // ī�װ� ���� Ȯ�� �뵵
	int index_cate; // �Է¹��� ���� ��ġ Ȯ�� 


	printf("������ �߻��� ī�װ��� �Է��� �ּ���. ");
	while (valid_cate != 1) {
		scanf_s("%s", &input_cate, (int)sizeof(input_cate));
		for (int i = 0; i < category_count; i++) {
			if (strcmp(input_cate, category_names[i]) == 0) {
				index_cate = i;
				valid_cate = 1;
			}
		}
		if (valid_cate != 1) { // ���� ī�װ� �Է¹޴� ��� ���� 
			printf("�������� �ʴ� ī�װ��Դϴ�. �ٽ� �Է��� �ּ���.");
			continue;
		}
	}
	
	

	// ���� �ݾ� �Է¹ް� �ش� ī�װ� ���꿡�� ���̳ʽ�
	// �߻��ϰ� �ִ� ������ �Ѿ׵� �����ؾ� ��. 

	int total_expenditure[50]; // ī�װ��� ���� �Ѿ� 
	int new_expenditure[50]; // ���� �߻��ϴ� ����

	printf("���� �߻� �ݾ��� �Է��� �ּ���. ");
	while (1) {
		scanf_s("%d ", &new_expenditure);
		if (new_expenditure <= 0) { // ����, 0 ���� 
			printf("�߻��� ������ �Է��� �ּ���.");
		}
		else {
			
		}
		
	}
	
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