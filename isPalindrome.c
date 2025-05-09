include<stdio.h>
include<stdbool.h>

 struct ListNode {
 int val;
 struct ListNode *next;
};

bool isPalindrome(struct ListNode* head){
    
    int stack [105]; //105 sesuai syarat di soal
    int count = 0;   //nyimpan panjang node
    int end = 0;     //perbandingan node dan stack
    
    struct ListNode* temp = head;

  // ngitung panjang node
    while (temp != NULL) {
        count++;
        temp = temp->next;
        }
 // nyimpan isi node secara terbalik di array stack
        temp = head;
    for (int i = count-1; i >= 0; i--){
        stack[i] =  temp->val;
        temp = temp->next;
    }

// ngecek apakah isi node dan array stack sama
        temp = head;
    for (int i = 0; i < count; i++){
        if(stack[i] == temp->val){
            end++;
            temp = temp->next;
        }
        else{
            continue;
        }
    }
        
      if (end == count){
        return true;
      }
      else{
        return false;
      }
    }
