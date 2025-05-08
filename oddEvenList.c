#include<stdio.h>
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

        if (current->val % 2 != 0){            //jika ganjilhead masih kosong inisialisasi ganjilhead bersamaan dengan tail
            if (ganjilhead == NULL){
            ganjilhead = ganjiltail = current;
            
            }
            else {
                ganjiltail->next = current;    //menghimpun angka ganjil
                ganjiltail = current;
            
            }
        }
        
        else {
           if (genaphead == NULL){              // inisialisasi genaphead sekaligus genaptail
            genaphead = genaptail = current;
            
           }
           else {
            genaptail->next = current;           // menghimpun angka genap
            genaptail = current;
           }
        }
         
           struct ListNode* nextNode = current->next;       //memutus pointer ke node lama
           current->next = NULL;  
           current = nextNode;    
   
    }

    if (ganjilhead != NULL) {            //menyambungkan ganjil tail dan genap
        ganjiltail->next = genaphead;
    }
    
    else (genaphead != NULL) {
        genaptail->next = NULL;
    }
    

    return ganjilhead;
};
