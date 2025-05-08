#include "nbtrees.h"
#include <stdio.h>
#include <stdlib.h>

void displayMenu(){
    printf("\n====== Menu program nbtree =====\n");
    printf("1. traversal preorder\n");
    printf("2. traversal inorder\n");
    printf("3. traversal postorder\n");
    printf("4. traversal levelorder\n");
    printf("5. print tree\n");
    printf("6. search node tree");
    printf("7. jumlah daun/leaf\n");
    printf("8. mencari level node tree\n");
    printf("9. kedalaman tree\n");
    printf("10. membandingkan 2 node tree\n");
    printf("11. exit\n");
}

void pause(){
    printf("\n---klik apapun untuk melanjutkan\n");
    getchar();
}

int main(){
    Isi_Tree tree;
    int Jml_Node = 0;
    int choice;
    char input;
    char node1, node2;

    printf("masukkan jumlah node untuk tree: ");
    scanf("%d", &Jml_Node);
    getchar();

    if(Jml_Node < 1 || Jml_Node > JML_MAKS){
        printf("jumlah node tidak valid(1-%d)\n", JML_MAKS);
        return 1;
    }

    CreateTree(tree, Jml_Node);

    printf("\nmasukkan data untuk tree:\n");
    for(int i = 1; i <= Jml_Node; i++){
        printf("node %d:\n info: ", i);
        scanf(" %c", &tree[i].info);
        
        printf(" first son (indeks, 0 jika tidak ada): ");
        scanf("%d", &tree[i].ps_fs);

        printf(" next brother (indeks, o jika tidak ada): ");
        scanf("%d", &tree[i].ps_nb);

        printf(" parent (indeks, 0 jika tidak ada); ");
        scanf("%d", &tree[i].ps_pr);

        printf("\n");
    }

    do{
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                printf("\ntraversal preorder: ");
                PreOrder(tree, 1);
                printf("\n");
                pause();
            break;

            case 2:
                printf("\ntraversal inorder: ");
                InOrder(tree, 1);
                printf("\n");
                pause();
            break;

            case 3:
                printf("\ntraversal postorder; ");
                PostOrder(tree, 1);
                printf("\n");
                pause();
            break;

            case 4:
                printf("\ntraversal levelorder; ");
                LevelOrder(tree, Jml_Node);
                printf("\n");
                pause();
            break;

            case 5:
                printf("\nseluruh node pada nbtree:\n");
                PrintTree(tree, Jml_Node);
                pause();
            break;

            case 6:
                printf("\nmasukkan node yang dicari (char): ");
                scanf(" %c", &input);
                if(Search(tree, input, Jml_Node)){
                    printf("node '%c' ditemukan\n", input);
                } else{
                    printf("node '%c' tidak ditemukan\n", input);
                }
                pause();
            break;

            case 7:
                printf("\njumlah daun/leaf pada tree: %d\n", nbDaun(tree, Jml_Node));
                pause();
            break;

            case 8:
                printf("\nmasukkan node untuk mencari level (char): ");
                scanf(" %c", &input);
                int level = Level(tree, input, Jml_Node);
                if(level != -1){
                    printf("level node '%c' adalah %d\n", input, level);
                } else{
                    printf("node '%c' tidak ditemukan\n", input);
                }
                pause();
            break;

            case 9:
                printf("\nkedalaman tree: %d\n", Depth(tree, 1));
                pause();
            break;

            case 10:
                printf("\nmasukkan node pertama (char); ");
                scanf(" %c", &node1);
                printf("masukkan node kedua (cjar): ");
                scanf(" %c", &node2);

                int level1 = Level(tree, node1, Jml_Node);
                int level2 = Level(tree, node2, Jml_Node);

                if(level1 == -1 || level2 == -1){
                    printf("salaj satu atau kedua node tdiak ditemukan\n");
                } else if(level1 > level2){
                    printf("node '%c' lebih dalam daripada node '%c'\n", node1, node2);
                } else if(level2 > level1){
                    printf("node '%c' lebih dalam daripada node '%c'\n", node2, node1);
                } else{
                    printf("kedua node berada pada level yang sama (%d)\n", level1);
                }
                pause();
            break;

            case 11:
                printf("\nprogram selesai\n");
            break;

            default:
                printf("\npilihan tidak valid, cob lgi\n");
                pause();
        }
    } while(choice != 11);

    return 0;
}