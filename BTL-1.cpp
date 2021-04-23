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
void Cout(EL *employeeList,int n){             //Thong ke tinh do co bao nhieu nhan vien
int dem=1;
for(int i=0;i<n;i++){
if(strcmp((employeeList+i)->Province,(employeeList+i+1)->Province)==0){
dem++;      
       }
        else{
        printf("\n%s co %d nhan vien!",(employeeList+i)->Province,dem);
        dem==1;
}
    }
}

