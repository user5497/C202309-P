#include <stdio.h>

// ���� ���� �ڵ�ȭ ������Ʈ 

// 17�ϱ���: 1. ī�װ� ���� ���, 2. ��� ���� ���� ��� 

// 1. ������ ���� ������ ī�װ��� �����մϴ�. 
// ī�װ��� �����ϴ� ����� �߰��մϴ�. 

// 2. �з����� ����� ����� �Ѿ��� �Է¹޽��ϴ�. 
// �ʼ������� �߻��� �ݾ��� �Է¹޾� �Ѿװ� ���� �����մϴ�. 


void edit_category(); // ī�װ� ���� ��� 



int main() {
	while (1) {
		int choice; 
		printf("���ϴ� ����� ������ �ּ���. (1. ���� �߰�, 2. ī�װ� ����, 3. ����): ");
		scanf_s("%d", &choice);
		if (choice == 1) {
			printf("���� �׸��� �߰��մϴ�. \n");
		}

		else if (choice == 2) {
			printf("���� ī�װ��� �����մϴ�. \n");
			edit_category();
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

void edit_category() {
	char category_names[50][10] = { "�ĺ�", "���", "�Ƿ�", "����", "����", "��Ȱ", "��ü", "��Ÿ" }; // ī�װ��� �̸��� ������ �迭 
	int category_count = 7; // ī�װ� ���� ����


	while (1) {
		// ī�װ� ��� 
		for (int i = 0; i < category_count; i++) {
			printf("%d %s ", i + 1, category_names[i]);
		}

		int choice_category;
		printf("(1. ī�װ� ����, 2. ī�װ� ���� ����): ");
		scanf_s("%d", &choice_category);

		if (choice_category == 1) {
			int del_category;
			printf("������ ���ϴ� ī�װ��� ��ȣ�� �������ּ���.\n");
			scanf_s("%d", &del_category);

			// �迭�� �� ĭ�� ��� ����. 
			for (int i = del_category - 1; i < category_count-1; i++) {
				for (int j = 0; j < 10; j++) {
					category_names[i][j] = category_names[i + 1][j];
				}	
			}
			category_count -= 1;
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
		}
		else if (choice_category == 2) {
			printf("ī�װ� ������ �����մϴ�.\n");
			break;
		}
		else {
			printf("�߸��� �����Դϴ�.\n");
			continue;
		}
	}
}