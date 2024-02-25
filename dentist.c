#include <stdio.h>
#include <stdlib.h>

struct patient {
    char nama [50];
    int nomor;
};

struct patient customer[100];
int numCustomer = 0;


void addCustomerFunction(){
    struct patient newCustomer;
    system("cls");
    printf("(tanpa spasi)    Nama     ===>");
    scanf("%s", newCustomer.nama);
    system("cls");
    printf("    Nomor    ===>");
    scanf("%d", &newCustomer.nomor);

    customer[numCustomer] = newCustomer;
    numCustomer++;

    printf("Customer berhasil ditambahkan.\n");

    printf("\nTekan tombol apa pun untuk kembali ke menu");
    getchar();
    getchar();
    menu();
}

void treatment() {
    system("cls");

    if(numCustomer > 0){
    printf("Pelanggan yang dalam proses perawatan:\n");
    printf("---------------------------------\n");
    printf("Nama: %s\n", customer[0].nama);
    printf("Nomor: %d\n", customer[0].nomor);
    printf("---------------------------------\n");
    }else{
        printf("Pelanggan yang dalam proses perawatan: Tidak ada\n");
    }

    printf("\nTekan tombol apa pun untuk kembali ke menu");
    getchar();
    getchar();
    menu();
}

void checkout() {
    system("cls");
    if (numCustomer == 0) {
        printf("Tidak ada pelanggan dalam antrian.\n");
    }else{
    printf("Pelanggan yang selesai perawatan:\n");
    printf("---------------------------------\n");
    printf("Nama: %s\n", customer[0].nama);
    printf("Nomor: %d\n", customer[0].nomor);
    printf("---------------------------------\n");

    for (int i = 0; i < numCustomer - 1; i++) {
        customer[i] = customer[i + 1];
    }
    numCustomer--;
    }

    if (numCustomer > 0) {
        printf("Pelanggan selanjutnya:\n");
        printf("Nama: %s\n", customer[0].nama);
        printf("Nomor: %d\n", customer[0].nomor);
        printf("---------------------------------\n");
    } else {
        printf("Tidak ada pelanggan berikutnya.\n");
    }

    printf("\nTekan tombol apa pun untuk kembali ke menu");
    getchar();
    getchar();
    menu();
}

void waitingList(){
    system("cls");

    if(numCustomer > 1){
        printf("Pelanggan yang dalam antrian:\n");
        printf("---------------------------------\n");
        for (int i = 1; i < numCustomer; i++) {
            printf("Nama: %s\n", customer[i].nama);
            printf("Nomor: %d\n", customer[i].nomor);
            printf("---------------------------------\n");
        }
    }else{
        printf("Pelanggan yang dalam antrian: Tidak ada\n");
    }

    printf("\nTekan tombol apa pun untuk kembali ke menu");
    getchar();
    getchar();
    menu();    
}

void menu (){
	
    printf("Dentist APP Menu \n");
    printf("1. Add Customer \n");
    printf("2. Treatment \n");
    printf("3. Check Out \n");
    printf("4. Waiting List \n");
    printf("5. Exit \n");
    
    int pilihan;
    scanf("%d", &pilihan);
    switch (pilihan)
        {
        case 1:
            addCustomerFunction();
            break;
        case 2:
            treatment();
            break;
        case 3:
            checkout();
            break;
        case 4:
            waitingList();
            break;
        case 5:
            system("cls");
            return 1;
            break;
        default:
            printf("Pilih input 1-5!!");
            system("cls");
            menu();
            break;
        }
}

int main (){
    system("cls");
    menu();

    return 0;
}
