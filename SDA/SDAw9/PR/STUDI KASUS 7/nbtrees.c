#include "nbtrees.h"

void CreateTree(Isi_Tree X, int Jml_Node) {
    for (int i = 1; i <= Jml_Node; i++) {
        X[i].info = ' ';
        X[i].ps_fs = NIL;
        X[i].ps_nb = NIL;
        X[i].ps_pr = NIL;
    }
}

bool IsEmpty(Isi_Tree P) {
    return P[1].info == ' ';
}

//preroder secara rekursif
void PreOrder(Isi_Tree P, address idx) {
    if (idx != NIL) {
        printf("%c ", P[idx].info);
        PreOrder(P, P[idx].ps_fs);
        PreOrder(P, P[idx].ps_nb);
    }
}
// //preorder non rekursif
// void PreOrderNonRekursif(Isi_Tree P, int Jml_Node) {
//     int stack[JML_MAKS];
//     int top = -1;    
//     if (Jml_Node == 0) return;
//     stack[++top] = 1; // Mulai dari root
//     while (top != -1) {
//         int idx = stack[top--];
//         printf("%c ", P[idx].info);
//         // Push Next Brother terlebih dahulu agar First Son diproses lebih dulu
//         if (P[idx].ps_nb != NIL) {
//             stack[++top] = P[idx].ps_nb;
//         }
//         if (P[idx].ps_fs != NIL) {
//             stack[++top] = P[idx].ps_fs;
//         }
//     }
// }

//inorder secara rekursif
void InOrder(Isi_Tree P, address idx) {
    if (idx != NIL) {
        InOrder(P, P[idx].ps_fs);
        printf("%c ", P[idx].info);
        InOrder(P, P[idx].ps_nb);
    }
}
// // inorder non rekursif
// void InOrderNonRekursif(Isi_Tree P, int Jml_Node) {
//     int stack[JML_MAKS];
//     int top = -1;
//     int idx = 1;
//     while (idx != NIL || top != -1) {
//         while (idx != NIL) {
//             stack[++top] = idx;
//             idx = P[idx].ps_fs;
//         }
//         idx = stack[top--];
//         printf("%c ", P[idx].info);
//         idx = P[idx].ps_nb;
//     }
// }

//postorder rekursif
void PostOrder(Isi_Tree P, address idx) {
    if (idx != NIL) {
        PostOrder(P, P[idx].ps_fs);
        PostOrder(P, P[idx].ps_nb);
        printf("%c ", P[idx].info);
    }
}
// //postorder non rekursif
// void PostOrderNonRekursif(Isi_Tree P, int Jml_Node){
//     int stack1[JML_MAKS], stack2[JML_MAKS];
//     int top1 = -1, top2 = -1;
//     if Jml_Node == 0) return;
//     stack1[++top1] = 1;
//     while (top1 != -1){
//         int idx = stack1[top1--];
//         stack2[++top2] = idx;
//         if (P[idx].ps_fs != NIL){
//             stack[++top1] = P[idx].ps_fs;
//         }
//         if (P[idx].ps_fs != NIL){
//             stack1[++top1] = P[idx].ps_nb;
//         }
//     }
//     while (top2 != -1){
//         printf("%c ", P[stack2[top2--]].info);
//     }
// }


void LevelOrder(Isi_Tree P, int Jml_Node) {
    for (int i = 1; i <= Jml_Node; i++) {
        if (P[i].info != ' ') {
            printf("%c ", P[i].info);
        }
    }
}
// // levelorder non rekursif
// void LevelOrderNonRekursif(Isi_Tree P, int Jml_Node){
//     int queue[JML_MAKS];
//     int front = 0, rear = 0;
//     if (Jml_Node == 0) return;
//     queue[rear++] = 1;
//     while (front != rear){
//         int idx = queue[front++];
//         printf("%c ", P[idx].info);
//         if (P[idx].ps_fs != NIL){
//             queue[rear++] = P[idx].ps_fs;
//         }
//         if (P[idx].ps_nb != NIL){
//             queue[rear++] = P[idx].ps_nb;
//         }
//     }
// }

void PrintTree(Isi_Tree P, int Jml_Node) {
    printf("Node\tInfo\tParent\tFirst Son\tNext Brother\n");
    for (int i = 1; i <= Jml_Node; i++) {
        printf("%d\t%c\t%d\t%d\t%d\n", i, P[i].info, P[i].ps_pr, P[i].ps_fs, P[i].ps_nb);
    }
}

bool Search(Isi_Tree P, infotype X, int Jml_Node) {
    for (int i = 1; i <= Jml_Node; i++) {
        if (P[i].info == X) {
            return true;
        }
    }
    return false;
}

int nbElmt(Isi_Tree P, int Jml_Node) {
    int count = 0;
    for (int i = 1; i <= Jml_Node; i++) {
        if (P[i].info != ' ') {
            count++;
        }
    }
    return count;
}

int nbDaun(Isi_Tree P, int Jml_Node) {
    int count = 0;
    for (int i = 1; i <= Jml_Node; i++) {
        if (P[i].info != ' ' && P[i].ps_fs == NIL) {
            count++;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X, int Jml_Node) {
    for (int i = 1; i <= Jml_Node; i++) {
        if (P[i].info == X) {
            int level = 0;
            address parent = P[i].ps_pr;
            while (parent != NIL) {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1; // Tidak ditemukan
}

int Depth(Isi_Tree P, address idx) {
    if (idx == NIL) {
        return 0;
    }
    int depthFs = Depth(P, P[idx].ps_fs);
    int depthNb = Depth(P, P[idx].ps_nb);
    return 1 + (depthFs > depthNb ? depthFs : depthNb);
}

int Max(int Data1, int Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}
