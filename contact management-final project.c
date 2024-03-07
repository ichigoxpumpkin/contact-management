/*
Kelompok    : F4
Kelas       : F
Nama Anggota:
Zerina Nur Salsabila                    (2208561019)
Ni Putu Eka Marita Anggarini            (2208561032)
M. Satrio Adiansyah                     (2208561039)
David Brave Moarota Zebua               (2208561063)
I Gusti Agung Istri Agrivina Shyta Devi (2208561107)
Ahmad Royyan Fath                       (2208561119)
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define tab printf("\t\t\t")

struct list
{
	char firstName[10];
	char lastName[10];
	char nomor[20];
	char email[30];
	char kota[10];

}person, check;


void tambahkontak()
{
    FILE *fp;
    fp=fopen("contact.txt", "a+");
	system("cls");
	tab;  printf("===============================\n");
	tab;  printf("||        TAMBAH KONTAK      ||\n");
	tab;  printf("===============================\n");
	tab;  printf("Masukkan nama awal            :" ); fflush(stdin); gets(person.firstName);
	tab;  printf("Masukkan nama akhir           :"); fflush(stdin); gets(person.lastName);
	tab;  printf("Masukkan nomor                :"); fflush(stdin); gets(person.nomor);
	tab;  printf("Masukkan email                :"); fflush(stdin); gets(person.email);
    tab;  printf("Masukkan kota tinggal (1 kata):"); fflush(stdin); gets(person.kota);

    fprintf(fp, "%s %s %s %s %s\n", person.firstName, person.lastName,person.nomor, person.email, person.kota);
    fclose(fp);
    tab;  printf("=====BERHASIL=====\n\n");

    system("pause");
}

void editkontak()
{
    int ch, f=0,g=0, option;
    FILE *fp, *newrec;
    fp=fopen("contact.txt","r");
    newrec=fopen("temp.txt","w");
    system("cls");
    tab;  printf("============================\n");
    tab;  printf("||        EDIT KONTAK     ||\n");
    tab;  printf("============================\n");
    tab;  printf("enter name (awal dan akhir): "); fflush(stdin); scanf("%s", check.firstName); scanf("%s", check.lastName);

    while(fscanf(fp, "%s %s %s %s %s\n", person.firstName, person.lastName, person.nomor, person.email, person.kota) != EOF)
    {
        if( (strcmpi(check.firstName, person.firstName)==0) && (strcmpi(check.lastName, person.lastName)==0) )
        {
           f=1;
           do
           {
                tab;  printf("=============================\n");
                tab;  printf("||        EDIT KONTAK      ||\n");
                tab;  printf("=============================\n");
                tab;  printf("apa yang ingin kamu edit?\n");
                tab;  printf("1. nama awal\n");
                tab;  printf("2. nama akhir \n");
                tab;  printf("3. nomor\n");
                tab;  printf("4. email\n");
                tab;  printf("5. kota tinggal\n");
                tab;  printf("0. kembali\n");
                tab;  printf("=============================\n");

                tab;  printf("        Enter option : "); scanf("%d", &ch);
                switch (ch)
                {
                    case 1:
                        tab;  printf("masukkan nama awal baru: "); fflush(stdin); gets(person.firstName);
                        tab;  printf("=====BERHASIL=====\n\n");
                        system("pause");
                        break;
                    case 2:
                        tab;  printf("masukkan nama akhir baru: "); fflush(stdin); gets(person.lastName);
                        tab;  printf("=====BERHASIL=====\n\n");
                        system("pause");
                        break;
                    case 3:
                        tab;  printf("masukkan nomor baru: "); fflush(stdin); gets(person.nomor);
                        tab;  printf("=====BERHASIL=====\n\n");
                        system("pause");
                        break;
                    case 4:
                        tab;  printf("masukkan email baru: "); fflush(stdin); gets(person.email);
                        tab;  printf("=====BERHASIL=====\n\n");
                        system("pause");
                        break;
                    case 5:
                        tab;  printf("masukkan kota tinggal baru: "); fflush(stdin); gets(person.kota);
                        tab;  printf("=====BERHASIL=====\n\n");
                        system("pause");
                        break;
                    case 0:
                        fprintf(newrec, "%s %s %s %s %s\n", person.firstName, person.lastName,person.nomor, person.email, person.kota);

                        break;

                }


           }while (ch!=0);
        }
        else
        {
            fprintf(newrec, "%s %s %s %s %s\n", person.firstName, person.lastName,person.nomor, person.email, person.kota);
        }
    }
    fclose(fp);
    fclose(newrec);
    remove("contact.txt");
    rename("temp.txt", "contact.txt");
    if(f==0)
    {
        printf("nama tidak ditemukan \n\n");
        system("pause");
    }

}

void carikontak()
{
    int f=0;
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    tab;  printf("================================\n");
    tab;  printf("||         CARI KONTAK        ||\n");
    tab;  printf("================================\n");
    tab;  printf("masukkan nama (awal dan akhir):"); fflush(stdin); scanf("%s", check.firstName); scanf("%s",check.lastName);

    while(fscanf(fp, "%s %s %s %s %s\n", person.firstName, person.lastName, person.nomor, person.email, person.kota) != EOF)
    {
        if( (strcmpi(check.firstName, person.firstName)==0) && (strcmpi(check.lastName, person.lastName)==0) )
        {
            f=1;
            tab;  printf("Nama      : %s %s\n", person.firstName, person.lastName);
            tab;  printf("Nomor     : %s\n", person.nomor);
            tab;  printf("Email     : %s\n", person.email);
            tab;  printf("Id Line   : %s\n", person.kota);
            system("pause");
            break;
        }
    }
    fclose(fp);
    if(f==0)
    {
        printf("nama tidak ditemukan \n\n");
        system("pause");
    }
}

void daftarkontak()
{
    int f=0;
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    tab;  printf("==========================================================================================\n");
    tab;  printf("||                                    DAFTAR KONTAK                                     ||\n");
    tab;  printf("==========================================================================================\n\n\n");

    tab;  printf("==========================================================================================\n");
    tab;  printf("%s%-20s%s%-20s%s%-30s%s%-10s%s\n","||","NAMA", "||","NOMOR","||", "EMAIL", "||","KOTA", "||"); //10 spaces before the string
    tab;  printf("==========================================================================================\n");


   while(fscanf(fp, "%s %s %s %s %s\n", person.firstName, person.lastName, person.nomor, person.email, person.kota) != EOF)
    {
        f=1;
        const char* s1 =strcat(person.firstName, " ");
        const char* s2 = strcat(s1, person.lastName);
        tab;  printf("%s%-20s%s%-20s%s%-30s%s%-10s%s\n","||", s2, "||", person.nomor, "||", person.email,"||", person.kota);
        tab;  printf("==========================================================================================\n");
    }

    fclose(fp);
    if(f==0)
    {
        printf("kontak tidak ditemukan \n\n");
        system("pause");
    }
    system("pause");
}

void hapuskontak()
{
    int ch, f=0;
    FILE *fp, *newrec;
    fp=fopen("contact.txt","r");
    newrec=fopen("temp.txt","w");
    system("cls");
    tab;  printf("=============================\n");
    tab;  printf("||        HAPUS KONTAK     ||\n");
    tab;  printf("=============================\n");
    tab;  printf("enter nama (awal dan akhir):"); fflush(stdin); scanf("%s", check.firstName); scanf("%s", check.lastName);

    while(fscanf(fp, "%s %s %s %s %s\n", person.firstName, person.lastName, person.nomor, person.email, person.kota) != EOF)
    {
        if( (strcmpi(check.firstName, person.firstName)==0) && (strcmpi(check.lastName, person.lastName)==0) )
        {
            f=1;
        }
        else
        {
            fprintf(newrec, "%s %s %s %s %s\n", person.firstName, person.lastName, person.nomor, person.email, person.kota);
        }
    }
    fclose(fp);
    fclose(newrec);
    remove("contact.txt");
    rename("temp.txt", "contact.txt");
    if(f==0)
    {
        tab;  printf("kontak tidak ditemukan \n\n");
        system("pause");
    }
    else
    {
        tab;  printf("=====BERHASIL=====\n\n");
        system("pause");

    }


}


void main()
{
	int ch;
	do
	{
	    system("cls");

	    tab;  printf("========================================================================\n");
	    tab;  printf("||                    CONTACT MANAGEMENT PROGRAM                      ||\n  ");
	    tab;  printf("|| made by the most astonishing, distinguished, and stunning F4 group ||\n");
		tab;  printf("========================================================================\n");
		tab;  printf("||                            MAIN MENU                               ||\n");
		tab;  printf("========================================================================\n");
		tab;  printf("1. tambah kontak\n ");
		tab;  printf("2. edit kontak\n"  );
		tab;  printf("3. cari kontak\n"  );
		tab;  printf("4. daftar kontak\n");
		tab;  printf("5. hapus kontak\n" );
		tab;  printf("0. keluar\n"       );
		tab;  printf("========================================================================\n");
		tab;  printf("   Masukkan opsi : "); scanf("%d", &ch);
		switch (ch)
		{
		case 1: tambahkontak();  break;
		case 2: editkontak  ();    break;
		case 3: carikontak  ();  break;
		case 4: daftarkontak();    break;
		case 5: hapuskontak ();  break;
		}
	} while (ch != 0);



}
