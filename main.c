#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node
    {
        struct node *prev;
        int huruf;
        struct node *next;
    };
    struct node *head = NULL,*temp = NULL,*temp2 = NULL,*cursor = NULL,*hapus = NULL,*nextc = NULL;

int main()
{


    int pil, stat=0, count=0;
    int a;

    do
    {

    system("cls");
    printf("PROGRAM EDITOR TEKS\n");
    printf("===================\n\n");

    printf("Menu:\n1. Print\n2. Add Char\n3. Delete Char\n4. Shift Left\n5. Shift Right\n6. Exit\n\nPilihan: ");

    scanf("%d",&pil);
        switch(pil)
        {
        case 1:
            {
                temp2 = head;
                if(head == NULL)
                {
                    printf("Tidak ada karakter yang dapat ditampilkan!\n");
                    system("pause");
                    break;
                }
                printf("Output: ");
                while(temp2->next!=NULL)
                {
                    printf("%d ", temp2->huruf);
                    temp2 = temp2->next;
                }
                printf("%d", temp2->huruf);
                printf("\n\n");
                system("pause");
                            break;
                        }
        case 2:
            {
                if(head==NULL)
                {
                    temp=(struct node *)malloc(sizeof(struct node));
                    temp->prev=NULL;
                    temp->next=NULL;
                    head=temp;
                    cursor=temp;
                    printf("\nMasukkan karakter : ");
                    scanf("%d", &cursor->huruf);
                    /*strcpy(, a[0]);*/
                    count++;
                    printf("\nKarakter %d berhasil ditambahkan!\n\n", a);
                    system("pause");
                }
                else if(cursor->next==NULL)
                {
                    temp=(struct node *)malloc(sizeof(struct node));
                    temp->prev=cursor;
                    temp->next=NULL;
                    cursor->next=temp;
                    cursor=temp;
                    printf("\nMasukkan karakter : ");
                    scanf("%d", &cursor->huruf);
                    /*strcpy(cursor->huruf, a);*/
                    count++;
                    printf("\nkarakter %d berhasil ditambahkan!\n\n", cursor->huruf);
                    system("pause");
                }
                else
                {
                    nextc=cursor->next;
                    temp=(struct node *)malloc(sizeof(struct node));
                    temp->next=nextc;
                    temp->prev=cursor;
                    nextc->prev=temp;
                    cursor->next=temp;
                    cursor=cursor->next;
                    printf("\nMasukkan karakter : ");
                    /*gets(cursor->huruf);*/
                    scanf("%d", &cursor->huruf);
                    count++;
                    printf("\nkarakter %d berhasil ditambahkan!\n\n", cursor->huruf);
                    system("pause");
                }
                break;
            }
        case 3:
            {
                if(head==NULL)
        printf("Maaf, tidak ada karakter dalam editor!\n");
    else if(cursor->prev==NULL)
    {
        printf("Maaf, tidak ada karakter di sebelah kiri yang dapat dihapus!\n");
    }
    else if(cursor->next==NULL)
    {
        hapus=cursor;
        cursor=cursor->prev;
        cursor->next=NULL;
        free(hapus);
        printf("Berhasil menghapus!\n");
    }
    else
    {
        hapus=cursor;
        cursor=cursor->prev;
        cursor->next=hapus->next;
        hapus->next->prev=cursor;
        free(hapus);
        printf("Berhasil menghapus!\n");
    }
    system("pause");



                break;
            }
        case 4:
            {
                if(head==NULL)
        printf("Maaf, tidak ada karakter dalam editor!\n");
    else if(cursor->prev==NULL)
        printf("Maaf, cursor telah berada di sisi paling kiri!\n");
    else
    {
        cursor=cursor->prev;
        printf("Cursor sekarang berada di karakter %d.\n", cursor->huruf);
    }
    system("pause");
                break;
            }
        case 5:
            {

    if(head==NULL)
        printf("Maaf, tidak ada karakter dalam editor!\n");
    else if(cursor->next==NULL)
        printf("Maaf, cursor telah berada di sisi paling kanan!\n");
    else
    {
        cursor=cursor->next;
        printf("Cursor sekarang berada di karakter %d.\n", cursor->huruf);
    }
    system("pause");
                break;
            }
        case 6:
            {
                stat=1;
                break;
            }
        default:
            {
                printf("Maaf, inputan salah!\n");
                system("pause");
                break;
            }
        }

    }
    while(stat==0);
    return(0);
}

/*
struct node
{
	struct node *prev;
	char huruf;
	struct node *next;
};
struct node *head = NULL,*temp = NULL,*temp2 = NULL,*cursor = NULL,*hapus = NULL,*nextc = NULL;

int pil, stat=0, count=0;
char a;

void header()
{
    system("cls");
    printf("PROGRAM EDITOR TEKS\n");
    printf("===================\n\n");
}

void menu()
{
    printf("Menu:\n1. Print\n2. Add Char\n3. Delete Char\n4. Shift Left\n5. Shift Right\n6. Exit\n\nPilihan: ");
}

void print()
{
    system("cls");
    header();
    temp2 = head;
	if(head == NULL)
	{
		printf("Tidak ada huruf yang dapat ditampilkan!\n");
		system("pause");
		return;
	}
	printf("Output: ");
	while(temp2->next!=NULL)
	{
		printf("%c ", temp2->huruf);
		temp2 = temp2->next;
	}
	printf("%c", temp2->huruf);
	printf("\n\n");
	system("pause");
}

void add()
{

    system("cls");
    header();
    if(head==NULL)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
        cursor=temp;
        printf("\nMasukkan karakter : ");
        scanf("%c", &cursor->huruf);
        count++;
        printf("\nkarakter %c berhasil ditambahkan!\n\n", cursor->huruf);
        system("pause");
    }
    else if(cursor->next==NULL)
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        temp->prev=cursor;
        temp->next=NULL;
        cursor->next=temp;
        cursor=temp;
        printf("\nMasukkan karakter : ");
        gets(cursor->huruf);
        count++;
        printf("\nkarakter %c berhasil ditambahkan!\n\n", cursor->huruf);
        system("pause");
    }
    else
    {
        nextc=cursor->next;
        temp=(struct node *)malloc(1*sizeof(struct node));
        temp->next=nextc;
        temp->prev=cursor;
        nextc->prev=temp;
        cursor->next=temp;
        cursor=cursor->next;
        printf("\nMasukkan karakter : ");
        gets(cursor->huruf);
        count++;
        printf("\nkarakter %c berhasil ditambahkan!\n\n", cursor->huruf);
        system("pause");
    }
}

void delete_()
{
    system("cls");
    header();
    if(head==NULL)
        warning(2);
    else if(cursor->prev==NULL)
    {
        hapus=cursor;
        cursor=cursor->next;
        head=cursor;
        cursor->prev=NULL;
        free(hapus);
    }
    else if(cursor->next==NULL)
    {
        hapus=cursor;
        cursor=cursor->prev;
        free(hapus);
        printf("Berhasil menghapus!\n");
    }
    else
    {
        hapus=cursor;
        cursor=cursor->prev;
        cursor->next=hapus->next;
        hapus->next->prev=cursor;
        free(hapus);
        printf("Berhasil menghapus!\n");
    }
    system("pause");
}

void shift_left()
{
    system("cls");
    header();
    if(head==NULL)
        warning(2);
    else if(cursor->prev==NULL)
        warning(3);
    else
    {
        cursor=cursor->prev;
        printf("Cursor sekarang berada di karakter %c.", cursor->huruf);
    }
    system("pause");
}

void shift_right()
{
    system("cls");
    header();
    if(head==NULL)
        warning(2);
    else if(cursor->next==NULL)
        warning(4);
    else
    {
        cursor=cursor->next;
        printf("Cursor sekarang berada di karakter %c.", cursor->huruf);
    }
    system("pause");
}

void warning(int n)
{
    system("cls");
    header();
    switch(n)
    {
    case 1:
        {
            printf("Maaf, inputan salah!\n");
            break;
        }
    case 2:
        {
            printf("Maaf, tidak ada karakter dalam editor!\n");
            break;
        }
    case 3:
        {
            printf("Maaf, cursor telah berada di sisi paling kiri!\n");
            break;
        }
    case 4:
        {
            printf("Maaf, cursor telah berada di sisi paling kanan!\n");
            break;
        }
    }

}

int main()
{
    do
    {
        header();
        menu();
        scanf("%d",&pil);
        switch(pil)
        {
        case 1:
            {
                print();
                break;
            }
        case 2:
            {
                add();
                break;
            }
        case 3:
            {
                delete_();
                break;
            }
        case 4:
            {
                shift_left();
                break;
            }
        case 5:
            {
                shift_right();
                break;
            }
        case 6:
            {
                stat=1;
                break;
            }
        default:
            {
                warning(1);
                break;
            }
        }
    }
    while(stat==0);
    return 0;
}

int addNodeBottom(int val, node *head)
{
    node *newNode = (node*)malloc(sizeof(node));

    if(newNode == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory for new node.\n");
        exit(-1);
    }

    newNode->value = val;
    newNode->next = NULL;

    if(head->next == NULL)
    {
        head->next = newNode;
        printf("added at beginning\n");
    }

    else
    {
        node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        printf("added later\n");
    }
}
*/

