#include <iostream>
#include <vector>




using namespace std;


// class node {
//     public:
//     int val;
//     node* next;

//     node(int data) {
//         val = data;
//         next = NULL;
//     }
// };

struct node {
    int val;
    node* next;
    
    node() {
        val = 0;
        next = NULL;
    }

    node(int data) {
        val = data;
        next = NULL;
    }
};

//printing the entire linkedlist
void display(node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


//count how many nodes in linkedlist
int count_nodes(node* head) {
    int count = 0;
    node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}


// add node to the last
void last(node* &head, int val) {
    node* newnode = new node(val);
    node* temp = head;

    if (head == NULL) {
        head = newnode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;

}


// all odd elements in the list will go to left and 
// all even elements will go to right
node* evenOddlist(node* head) {

    node* even = head->next;
    node* odd = head;
    node* evenHead = even;

    while (odd!=NULL && even!= NULL && even->next!=NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    
    odd->next = evenHead;
    return head;


}



// NOTE: O(N^2) 
// linkedlist will rotate by k time
node* rotateRight(node* &head, int k) {

    int count = count_nodes(head);
    if (count%k == 0 || count == k) return head;

    node* temp = head;
    node* fast = head->next;
    node* slow = head;
    for (int i = 1; i <= k; i++) {
        while (fast->next != NULL) {
            slow = slow->next;
            fast =fast->next;
        }
        slow->next = NULL;
        fast->next = head;
        head = fast;

        fast = head->next;
        slow = head;

    }

    return head;
    

}





// Given the head of a linked list,
// remove the nth node from the end of the list and return its head.
node* removefromlast(node* head, int k) {



    int cnt = count_nodes(head);
    
    if (cnt > 1 && k == cnt)
        head = head->next;

    if (cnt == 1 && k != 0)
        return NULL;

    int rem = cnt-k, i = 0;
    node* dummy = new node(0);
    node* curr = dummy;
    node* temp = head;


    while (i < rem) {
        curr->next = temp;
        curr = curr->next;
        temp = temp->next;
        i++;
    }
    curr->next = temp->next;
    return head;


}



//reverse LL from given left index to right index
node* reverseII(node* head, int left, int right) {

   int temp;
  

   while (left < right) {

       node* slow = head, *fast = head;
       for (int i = 1; i < left; i++) {
           slow = slow->next;
       }

       for (int i = 1; i < right; i++) {
           fast = fast->next;
       }

       temp = slow->val;
       slow->val = fast->val;
       fast->val = temp;
       left++;
       right--;

   }

   return head;
   


}




node* reverse(node* head) {
        
    node *p = NULL;
    node *c = head;
    node *n = NULL;
    while (c) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    
    return p;
        
}



//Reorder the list to be on the following form:
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
node* reorderList(node* head) {

    node *first = head;
    node *second = head;

    // finding second half list
    while (first->next != NULL && first->next->next != NULL) {
        second = second->next;
        first = first->next->next;
    }
    first = second->next;
    second->next = NULL;


    //reverse second half list    
    second = NULL;
    while (first) {
        node* temp = first->next;
        first->next = second;
        second = first;
        first = temp;
    }

    // merge second half with first half  
    first = head;
    while (first) {
        node* temp = first->next;
        first->next = second;
        first = second;
        second = temp;
    }

    return head;


}




// add two number
node* addTwoNumber_1(node* headA, node* headB) {

    node* head = new node(0);
    node* curr = head;
    int carry = 0, sum = 0, tempA, tempB;

    while (headA  || headB  || carry) {

        if (headA) {
            tempA = headA->val;
            headA = headA->next;
        }
        else 
            tempA = 0;

        if (headB) {
            tempB = headB->val;
            headB = headB->next;
        }
        else 
            tempB = 0;

        sum = tempA+tempB+carry;
        curr->next = new node(sum%10);
        curr = curr->next;
        carry = sum/10;

    }

    return head->next;


}


node* addTwoNumber_2(node* headA, node* headB) {

    node* head = new node(0);
    node* curr = head;

    node* A = reverse(headA);
    node* B = reverse(headB);

    // return (A, B);

    int i = 0, c = 0, s = 0, ta = 0, tb = 0;

    while (A || B || c) {
        if (A) {
            ta = A->val;
            A = A->next;
        }
        else
            ta = 0;

        if (B) {
            tb = B->val;
            B = B->next;
        }
        else
            tb = 0;


        s = ta+tb+c;
        curr->next = new node(s%10);
        curr = curr->next;
        c = s/10;
    }
    return reverse(head->next);

    


}


// LL will divided 2 list
node* half_the_LL(node* head) {

    node* dummy = new node(0);
    node* curr = dummy;
    node* fast = head->next;
    node* slow = head;


    while (fast != NULL) {
        fast = fast->next;
        if (fast == NULL) break;
        fast = fast->next;
        slow = slow->next;
    }

    curr = slow->next;
    slow->next = NULL;
    return head;


}






// You are given two linked lists: list1 and list2 of sizes n and m respectively.
// Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
node* mergeInBetween(node* list1, int a, int b, node* list2) {

    node* temp1 = list1, *temp2 = list1, *temp3 = list2;
    int x = 1;

    //temp1 will move until x less than a
    while (x < a && temp1) {
        temp1 = temp1->next;
        x++;
    }

    x = 0;
    //temp2 will move until x less than or equal to b
    while (x <= b && temp2) {
        temp2 = temp2->next;
        x++;
    }

    //temp3 will hold last element memory, so that we can connect to temp2
    while (temp3->next != NULL) {
        temp3 = temp3->next;
    }

    temp1->next = list2;
    temp3->next = temp2;

    return list1;


    

}



// reverse LL by K node
node* reverse_by_kNode(node* head, int k) {
        
    node *p = NULL;
    node *c = head;
    node *n = NULL;
    int index = 0;
    while (index < k && c!=NULL) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        index++;
    }
    
    return p;
        
}



node *reverseKGroup(node *head, int k) {
    
    int index = 0;
    node *ptr = head;
    node *temp = head;
    node *dummy = new node(0);
    node *curr = dummy;
    
    // we will move temp right if index less than k
    // Example : if k = 2 and LL is 1-2-3-4-5, 
    // then temp will hold 3-4-5
    while (index < k) {
        temp = temp->next;
        index++;
    }

    //then, we are connect temp[3-4-5] to curr[0]
    //so, curr will be[0-3-4-5]
    curr->next = temp;

    //ptr = head. So ptr will be[1-2-3-4-5]
    //k = 2. Finaly this[reverse_by_kNode] function will reverse first k element
    //now t hold [2-1]
    node *t = reverse_by_kNode(ptr, k);

    node *x = new node(0);
    
    node *y = x;

    //now, y[0], after y->next = t, it will hold y[0-2-1]
    y->next = t;    
    
    while (y->next != NULL) {
        y = y->next;
    }

    // curr[0-3-4-5], to avoid 0, we do this
    curr = curr->next;

    //y[0-2-1], after doing this, y will be[0-2-1-3-4-5]
    y->next = curr;

    return x->next;
   
}



node *mergeKLists(vector<node*> lists) {

    vector<int> num;
    for (node *list : lists) {
        while (list) {
            num.push_back(list->val);
            list = list->next;
        }
    }

    sort(num.begin(), num.end());
    node *dummy = new node(0);
    node *temp = dummy;

    for (int n : num) {
        temp->next = new node(n);
        temp = temp->next;
    }

    return dummy->next;



}


// Given the head of a linked list and a value x,
// partition it such that all nodes less than x
// come before nodes greater than or equal to x.
node *partition(node *head, int k) {


    node *mainFast = new node(0);
    node *fast = mainFast;

    node *mainSlow = new node(0);
    node *slow = mainSlow;

    while (head != NULL) {

        if (head->val < k) {
            fast->next = head;
            fast = fast->next;
        }

        else {
            slow->next = head;
            slow = slow->next;
        }

        head = head->next;
    }

    slow->next = NULL;
    fast->next = mainSlow->next;
    return mainFast->next;















    // node *before_head = new node(0);
    // node *before = before_head;
    // node *after_head = new node(0);
    // node *after = after_head;

    // while (head != NULL) {

    //     if (head->val < k) {
    //         before->next = head;
    //         before = before->next;
    //     }
    //     else {
    //         after->next = head;
    //         after = after->next;
    //     }
    //     head = head->next;
    // }

    // after->next = NULL;
    // before->next = after_head->next;
    // // return after_head;
    // return before_head->next;
    

 






}



int kNode_from_middle(node *head, int k) {

    node *t = head;
    int cnt = count_nodes(head);
    int half = (cnt/2)+1-k, i = 0;
    

    if (cnt <= 0)
        return -1;
    
    for (i = 0; i < half-1; i++) {
        t = t->next;
    }

    return t->val;

   
    

}





// node *revKnode(node *head, int k) {

//     int i = 1, j = 1;
//     node *temp = head;
//     node *temp2 = head;
//     node *slow = head; 
//     node *fast = head->next;

//     node *d = new node(0);
//     node *m = new node(0);
//     node *c = d;
//     node *n = m;
    
//     while (i <= k) {

//         if (i%2 != 0) {
//             while (j < k) {
//                 temp2 = temp2->next;
//                 j++;
//             }
//             n->next = temp2->next;
//             temp2->next = NULL;

//             node *t = reverse_by_kNode(temp, k);
//             c->next = t;
//             while (c->next != NULL) {
//                 c = c->next;
//             }
            
//             c->next = n->next;
        
//             // break;
//         }
        
//         i++;
//     }

//     return d->next;




// }

int main() {

    node* headA = NULL;

  
    last(headA, 3);
    last(headA, 4);
    last(headA, 7);
    last(headA, 5);
    last(headA, 6);
    last(headA, 6);
    last(headA, 15);
    last(headA, 61);
    last(headA, 16);

    
  
}