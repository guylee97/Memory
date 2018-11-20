#include <stdio.h>
#include <string.h>

void sort_name(int n, struct individual *id);
void sort_birth(int n, struct individual *id);

struct birth
{
	int year;
	int month;
	int day;
};


struct individual
{
	char name[20];
	struct birth mybirth;
	char gender[10];
	char phonenumber[30];
};

struct individual ida[10];
struct individual temp;


int main()
{

	int i;
	int n = 15;
	struct individual *id;
	id = (struct individual *)malloc(sizeof(struct individual) * n);


	printf("\n����� ������ �Է��Ͻʴϱ�?(7~10) :  ");
	scanf_s("%d", &n, 4);
	getchar();


	for (i = 0; i < n; i++)
	{
		printf("\n%d��° ���� �Է�", i);
		printf("\n�̸� :  ", i);
		scanf_s("%s", &id[i].name, 20);
		printf("\n���� : ", i);
		scanf_s("%d", &id[i].mybirth.year, sizeof(id[i].mybirth.year));
		printf("\n���� : ", i);
		scanf_s("%d", &id[i].mybirth.month, sizeof(id[i].mybirth.month));
		printf("\n���� : ", i);
		scanf_s("%d", &id[i].mybirth.day, sizeof(id[i].mybirth.day));
		printf("\n����(��/��) : ", i);
		scanf_s("%s", &id[i].gender, 10);
		getchar();
		printf("\n��ȭ��ȣ(���� �ʰ� �Է�) : ", i);
		scanf_s("%s", &id[i].phonenumber, 20);
		printf("\n");
	}

	printf("�̸�\t�������\t����\t��ȭ��ȣ\t \n");

	for (i = 0; i < n; i++)
	{
		printf("%s\t %d,%d,%d\t %s\t %s\t \n", id[i].name, id[i].mybirth.year, id[i].mybirth.month, id[i].mybirth.day, id[i].gender, id[i].phonenumber);
	}

	sort_name(n, id);

	printf("\n\n");
	printf("�̸�\t�������\t����\t��ȭ��ȣ\t \n");

	for (i = 0; i < n; i++)
	{
		printf("%s\t %d,%d,%d\t %s\t %s\t \n", id[i].name, id[i].mybirth.year, id[i].mybirth.month, id[i].mybirth.day, id[i].gender, id[i].phonenumber);
	}

	sort_birth(n, id);

	printf("\n\n");
	printf("�̸�\t�������\t����\t��ȭ��ȣ\t \n");

	for (i = 0; i < n; i++)
	{
		printf("%s\t %d,%d,%d\t %s\t %s\t \n", id[i].name, id[i].mybirth.year, id[i].mybirth.month, id[i].mybirth.day, id[i].gender, id[i].phonenumber);
	}


	system("pause");
	return 0;
}




void sort_name(int n, struct individual *id)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{

		for (j = 0; j < n - 1; j++)
		{
			if (strcmp(id[j].name, id[j + 1].name) < 0)
			{
				temp = id[j];
				id[j] = id[j + 1];
				id[j + 1] = temp;
			}

		}

	}

}

void sort_birth(int n, struct individual *id)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{

		for (j = 0; j < n - 1; j++)
		{
			if (id[j].mybirth.year>id[j + 1].mybirth.year)
			{
				temp = id[j];
				id[j] = id[j + 1];
				id[j + 1] = temp;
			}

			else if (id[j].mybirth.month>id[j + 1].mybirth.month&&id[j].mybirth.year == id[j + 1].mybirth.year)
			{
				temp = id[j];
				id[j] = id[j + 1];
				id[j + 1] = temp;
			}

			else if (id[j].mybirth.day>id[j + 1].mybirth.day&&id[j].mybirth.month == id[j + 1].mybirth.month&&id[j].mybirth.year == id[j + 1].mybirth.year)
			{
				temp = id[i];
				id[i] = id[j + 1];
				id[j + 1] = temp;
			}

		}

	}
}