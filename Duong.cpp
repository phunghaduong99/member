#include<conio.h>
#include<string.h>
#include<stdio.h>

struct sv {
	int Age; 
	int ID; 
	int Group_id;
	char Name[100];
};

int Scanf(sv *member)
{	
	printf("\nNhap vao ID: ");
	scanf("%d", &member->ID);
	printf("\nNhap vao Group_id: ");
	scanf("%d", &member->Group_id);
	printf("\nNhap vao Age: ");
	scanf("%d", &member->Age);
	printf("\nNhap vao Name: ");
	fflush(stdin);
	gets(member->Name);

}

void Add(sv *member, int *n, int b)
{  
	int i;
	for(i=*n; i<(*n+b); i++)
	Scanf(&member[i]);
	*n= *n+b;
}

int Find(sv *member, int ID)
{	
	int member_a;
	while(ID != member->ID)
	{
		member = member +1;
		member_a++;
	}
	return member_a;
}

void Delete(sv *member, int *n, int member_a )
{
	member = member+ member_a -1;
	while( member_a  <= *n)
	{
		member->ID= (member+1)->ID;
		member= member+1;
		member_a = member_a+1;
	}
	*n= *n-1;
}

void Printf(sv *member, int member_a )
{
	member= member+ member_a;
	printf("\nThanh vien can tim co: ");
	printf("\nID la: %d", member->ID);
	printf("\nGroup_id la: %d", member->Group_id);
	printf("\nAge la: %d", member->Age);
	fflush(stdin);
	printf("\nName la: %s \n", member->Name );
}

void Edit(sv *member, int number, int member_a)
{
	member= member+ member_a;
	if(number == 1)
		{
			printf("\nNhap ID thay the: ");
			scanf("%d",&member->ID);
		}
	else if(number == 2)
		{
			printf("\nNhap Group_id thay the: ");
			scanf("%d",&member->Group_id);
		}
	else if(number == 3)
		{
			printf("\nNhap Age thay the: ");
			scanf("%d",&member->Age);
		}
	else if(number == 4)
		{
			printf("\nNhap Name thay the: ");
			fflush(stdin);
			gets(member->Name);
		}
	else printf("\nNhap vao cac so 1,2,3,4. ");
}


int main()
{	
	sv sv1[100];
	int n;
	printf("\nNhap so thanh vien: ");
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	Scanf(&sv1[i]); 
	
	int i;
	Nhap: ;
	printf("\nChon muc tuong ung: ");
	printf("\n0. Thoat chuong trinh. ");
	printf("\n1. Them thanh vien. ");
	printf("\n2. Xoa thanh vien. ");
	printf("\n3. Tim thanh vien bang ID.");
	printf("\n4. Sua thanh vien bang ID.");
	A: ;
	printf("\nMuc can chon la: ");
	scanf("%d", &i);
	if(i!=0 && i!=1 && i!= 2 && i!=3 &&i != 4)
		{
			printf("\nBan hay nhap vao 0, 1, 2, 3 hoac 4.");
			goto A;
		}
	switch(i)
	{
		case 1: 
				{	
					int b;
					printf("\nThem may thanh vien: ");
					scanf("%d",&b);
					Add(&sv1[2], &n, b);
					goto Nhap;
				}
		case 2: 
				{	
					int ID;
					printf("\nNhap vao ID thanh vien can xoa: ");
					scanf("%d", &ID);
					Delete(&sv1[0], &n, Find(&sv1[0],ID));	
					goto Nhap;
				}	
		case 3: 
				{
					int ID;
					printf("\nNhap vao ID thanh vien can tim: ");
					scanf("%d", &ID);
					Printf(&sv1[0], Find(&sv1[0], ID));
					goto Nhap;
				}	
		case 4: 
				{
					int ID, number;
					printf("\nNhap vao ID thanh vien can tim: ");
					scanf("%d", &ID);
					Printf(&sv1[0], Find(&sv1[0], ID));
					printf("\nThong tin can sua la: ");
					printf("\t1.ID \t2.Group_id \t3.Age \t4.Name");
					printf("\nNhap vao 1,2,3 hoac 4: ");
					scanf("%d", &number);
					Edit(&sv1[0], number, Find(&sv1[0],ID));
					goto Nhap;
				}
		case 0: 
					printf("\n0. Thoat chuong trinh");
					break;
		
	}
	







}
