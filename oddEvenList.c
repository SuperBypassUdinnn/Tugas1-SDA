#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* ganjilhead = NULL; //membuat 2 pointer pemisah ganjil dan genap
    struct ListNode* ganjiltail = NULL;
    struct ListNode* genaphead = NULL;
    struct ListNode* genaptail = NULL;

    while (current != NULL){

        if (current->val % 2 != 0){ 
            if (ganjilhead == NULL){ 
                ganjilhead = ganjiltail = current; // inisialisasi ganjilhead sekaligus ganjiltail
            }
            else {
                ganjiltail->next = current;    //menghimpun angka ganjil
                ganjiltail = current;
            }
        }
        
        else {
            if (genaphead == NULL){              
            genaphead = genaptail = current; // inisialisasi genaphead sekaligus genaptail
            }
            else {
                genaptail->next = current; // menghimpun angka genap
                genaptail = current;
            }
        }
         
        struct ListNode* nextNode = current->next; //memutus pointer ke node lama
        current->next = NULL;  
        current = nextNode;    
    }

    if (genaphead != NULL){
        genaptail->next = NULL; // memutus pointer ke node genap terakhir
    }

    if (ganjilhead != NULL) {
        ganjiltail->next = genaphead; // menggabungkan ganjil dan genap
    }
    else return genaphead; // jika tidak ada angka ganjil, kembalikan genaphead
    
    return ganjilhead;
}