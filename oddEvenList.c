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
                ganjiltail->next = current;    
                ganjiltail = current;
            
            }
        }
        
        else {
           if (genaphead == NULL){
            genaphead = genaptail = current;
            
           }
           else {
            genaptail->next = current;
            genaptail = current;
           }
        }
         
           struct ListNode* nextNode = current->next;       //memutus pointer ke node lama
           current->next = NULL;  
           current = nextNode;    
   
    }

    if (ganjiltail != NULL) {            //menyambungkan ganjil tail dan genap
        ganjiltail->next = genaphead;
    }
    
    if (genaptail != NULL) {
        genaptail->next = NULL;
    }
    

    return ganjilhead;
};
