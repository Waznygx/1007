#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	FILE* pf = fopen("C:\\Users\\�����˵�Ȧ��Ů��\\source\\repos\\lianxi\\1007\\test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
////�������																			
////   fopen: No such file or directory

//int main()
//{
//	FILE* pf = fopen("M:\\myfile.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fputs("fopen example", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	int ret = fgetc(stdin);
//	printf("%c ", ret);
//	ret = fgetc(stdin);
//	printf("%c ", ret);
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("M:\\myfile.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	fputs("hello world", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//int main()
//{
//	char arr[40] = { 0 };
//	FILE* pf = fopen("M:\\myfile.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct MyStruct
//{
//	char c[20];
//	int i;
//	double d;
//};
//int main()
//{
//	struct MyStruct s[2] = { { "abcd",4,9.1 }, {"efg",9,12.23} };
//	FILE* pf = fopen("M:\\myfile.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fwrite(&s, sizeof(struct MyStruct), 2, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct MyStruct
//{
//	char c[20];
//	int i;
//	double d;
//};
//int main()
//{
//	struct MyStruct s[2] = {0};
//	FILE* pf = fopen("M:\\myfile.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fread(&s, sizeof(struct MyStruct), 2, pf);
//	printf("%s,%d,%lf\n", s->c, s->i, s->d);
//	printf("%s,%d,%lf\n", s[1].c,s[1].i,s[1].d);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
////�����abcd,4,9.100000
////      efg,9,12.230000

//int main()
//{
//	FILE* pf = fopen("M:\\test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	fputs("this     an apple", pf);
//	fseek(pf,6, SEEK_SET);
//	fputs("is", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	long size = 0;
//	FILE* pf = fopen("M:\\test.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	fseek(pf, 0, SEEK_END);
//	size = ftell(pf);
//	printf("%ld\n", size);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
////�����17��this__is_an_apple=4+2+2+5+4��

//int main()
//{
//	FILE* pf = fopen("M:\\test.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//t
//	fseek(pf, 1, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//i
//	fseek(pf, 4, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//s
//
//	int ret = ftell(pf);
//	printf("%d\n", ret);//8
//	
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//t
//	fclose(pf);
//
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	int c = 0;
//	FILE* pf = fopen("M:\\test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//	}
//	while ((c = fgetc(pf)) != EOF)
//	{
//		putchar(c);
//	}
//	puts("");
//	if (ferror(pf))
//	{
//		puts("I/O error when reading\n");
//	}
//	else if (feof(pf))
//	{
//		puts("EOF(End Of File) reading successfully\n");
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

int main()
{
	FILE* pfread = fopen("M:\\test.txt", "r");
	if (pfread == NULL)
	{
		perror("fopen");
		return 1;
	}
	FILE* pfwrite = fopen("M:\\test1.txt", "w");
	if (pfwrite == NULL)
//����ڶ����ļ�����"M:\text1.txt"���޷��򿪣����磬����Ȩ���������̿ռ䲻�㣩��fopen����������NULL
//�ر��Ѿ��򿪵ĵ�һ���ļ�,�Է�ֹ�����������س���ʹ��һ���Ѿ��رյ��ļ�
	{
		fclose(pfread);
		pfread = NULL;
	}
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF)
//ʹ��fgetc������pfreadָ����ļ��ж�ȡһ���ַ���������洢�ڱ���ch��
	{
		fputc(ch, pfwrite);
//����ȡ���ַ�д�뵽pfwriteָ����ļ�
	}
	if (feof(pfread))
	{
		printf("normal end\n");
	}
	else if (feof(pfread))
	{
		printf("error\n");
	}
	fclose(pfwrite);
	pfwrite = NULL;
	fclose(pfread);
	pfread = NULL;
	return 0;
}