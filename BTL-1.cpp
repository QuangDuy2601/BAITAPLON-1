//Bai Tap Lon
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct employee_st{
	char Name[30];
	char Province[30];
	int Day;
	int Month;
	int Year;
};
typedef struct employee_st EL;
void Nhap1(EL *nv){
	fflush(stdin);
	printf("\nNhap ten nhan vien:");
	gets(nv->Name);
	printf("\nNhap tinh o cua nhan vien:");
	gets(nv->Province);
	printf("\nNhap ngay,thang,nam sinh cua nhan vien:");
	scanf("%d%d%d",&nv->Day,&nv->Month,&nv->Year);
}
void Input(EL *employeeList , int &n ){          //Nhap thong tin nhan vien
	printf("\nNhap so luong nhan vien :");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("\nNhap thong tin nhan vien %d",i+1);
		Nhap1((employeeList+i));
	}
}
void Output(EL *employeeList,int n){           //Xuat thong tin nhan vien
	printf("\nThong tin cua nhan vien la:");
	printf("\nSTT\tHoten\t\t    Tinh\t\tNgaysinh");
	for(int i=0;i<n;i++){
		printf("\n%d\t%-20s%-20s%-2d/%d/%d",i+1,(employeeList+i)->Name,(employeeList+i)->Province,(employeeList+i)->Day,(employeeList+i)->Month,(employeeList+i)->Year);
	}
}
void Output1(EL *t){                                //Xuat thong tin 1 nhan vien
	printf("\n%-20s%-20s%-2d/%d/%d",t->Name,t->Province,t->Day,t->Month,t->Year);
}
void Search(EL *employeeList,int n){              
	char province[30];
	int dem=0;
	fflush(stdin);
	printf("\nNhap ten tinh can tim:");
	gets(province);
	for(int i=0;i<n;i++){
		if(strcmp((employeeList+i)->Province,province)==0) dem++;
	}
	if(dem!=0){
		printf("\nThong tin cua nhan vien thuoc tinh %s :",province);
		printf("\nHoten\t\t    Tinh\t\tNamSinh");
		for(int i=0;i<n;i++){
			if(strcmp((employeeList+i)->Province,province)==0){
			 Output2((employeeList+i));
		  }
		}
	}
 	else printf("Khong co nhan vien cua tinh %s!!!!!",province);	
}
void Recordfile(EL *employeeList,int n){                    //Ghi thong tin nhan vien vao file nhi phan
	FILE * fp;
	fp= fopen ("employee.dat","wb");
	fprintf(fp,"\t%-20s\n","DANH SACH THONG TIN NHAN VIEN");
	fprintf(fp,"%-5s%-20s%-20s%-10s","STT","Hoten","Tinh","Ngaysinh");
	for(int i=0;i<n;i++){
		fprintf(fp,"\n%-5d%-20s%-20s%-2d/%d/%d",i+1,(employeeList+i)->Name,(employeeList+i)->Province,(employeeList+i)->Day,(employeeList+i)->Month,(employeeList+i)->Year);
	}
	fprintf(fp,"\n\n \t\t\t%-10s","~~~HET~~~");
	fclose(fp);
}
void Delete(EL *employeeList,int &n){         //Xoa nhan vien theo stt
	int t;
	printf("\nNhap STT nhan vien muon xoa:");
	scanf("%d",&t);
	for(int i=t-1;i<n-1;i++){
		*(employeeList+i)=*(employeeList+i+1);
	}
	--n;
}
void Add(EL *employeeList,int &n){                //Them nhan vien moi
	for(int i=n;i>n-1;i--){
		*(employeeList+i)=*(employeeList+i-1);
	}
	printf("\nNhap thong tin nhan vien muon them:");
	Nhap1((employeeList+n-1));
	++n;
}
void Menu(EL *employeeList,int &n){
int t;
int flat=1;
while(flat!=0){
printf("\n\t\t~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~");
printf("\n 1.Nhap du lieu cua tung nhan vien.");
printf("\n 2.Sap xep,thong ke va hien thi thong tin nhan vien theo tinh (Z->A).");
printf("\n 3.Tim nhan vien theo tinh.");
printf("\n 4.Ghi vao tap tin nhi phan employee.dat.");
printf("\n 5.Xoa nhan vien.");
printf("\n 6.Them nhan vien.");
printf("\n 7.Nhan 0 de thoat!!!");
printf("\n---------------------------------");
printf("\nLua chon cua ban:");
scanf("%d",&t);
switch(t){
case 1:
Input(employeeList,n);
break;
case 2:
   Sort(employeeList,n);
   Output(employeeList,n);
   Cout(employeeList,n);
break;
case 3:
    Search(employeeList,n);
break;
case 4:
     Recordfile(employeeList,n);
 break;
case 5:
  Delete(employeeList,n);
  Sort(employeeList,n);
  Output(employeeList,n);
  break;
case 6:
      Add(employeeList,n);
      Sort(employeeList,n);
  Output(employeeList,n);
  break;  
   
default:
       printf("\n\t~~~~~~~~Thank for watching!!!!~~~~~~~~");
       flat=0;  
}
  }
}

