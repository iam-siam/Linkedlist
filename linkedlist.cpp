#include<bits/stdc++.h>

using namespace std;

#define logline(x) cout << x << endl;
#define logspc(x) cout << x << " ";


class ListNode {
    
    public:

    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;  
    } 

};


//printing the entire linkedlist
void display(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


void display2(ListNode* head1, ListNode* head2) {
    
    while (head1 != NULL) {
        cout << head1->val << " ";
        head1 = head1->next;
    }
    cout << endl;

    while (head2 != NULL) {
        cout << head2->val << " ";
        head2 = head2->next;
    }
    cout << endl;
}



//push element to the last
void push_back(ListNode* &head, int val) {
    ListNode* newnode = new ListNode(val);
    ListNode* temp = head;

    if (head == NULL) {
        head = newnode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;

}


//push element to the front
void push_front(ListNode* &head, int val) {
    ListNode* newnode = new ListNode(val);
    newnode->next = head;
    head = newnode;
}


//count how many nodes in linkedlist
int count_nodes(ListNode* head) {
    int count = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}


// delete node with index position
void delete_inx(ListNode* &head, int inx) {
    int count = 0;
    int func_var = count_nodes(head);
    ListNode* temp = head;
    if (inx > func_var) {
        logline("greater than size");
    }
    else {
        while (inx-1 > 0) {
            temp = temp->next;
            inx--;
        }
        temp->next = temp->next->next;
    }
}


//push element to the specific index
void push_spec_inx(ListNode* &head, int inx, int val) {
    int count = 0;
    ListNode* newnode = new ListNode(val);
    ListNode* temp = head;
    int func_var = count_nodes(head);
    
    if (inx > func_var)
        logline("greater than size");

    while (count < inx-1) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}



//middle block of a linkedlist
ListNode* middle_node(ListNode* head) {

    int cnt = count_nodes(head);
    cout << cnt;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return (cnt%2==0) ? slow->next : slow;
  

}



// delete node without head note
void deleteNode(ListNode *nt) {
    nt->val = nt->next->val;
    // node* t = nt->next;
    nt->next = nt->next->next;
}


//remove duplicate value
void remove_dup_value(ListNode* &head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* vfast = fast->next;

   while (fast != NULL && fast->next != NULL) {
       if (fast->val == fast->next->val)
           fast->next = fast->next->next;
        else 
            fast = fast->next;
   }

}




// reverse order
ListNode* revOrder(ListNode* head) {
   
    ListNode* prev = NULL;
    while (head != NULL) {
        ListNode* newnode = new ListNode(head->val);
        newnode->next = prev;
        prev = newnode;
        head = head->next;
    }
    return prev;

}


bool isPalindrome(ListNode *head) {
    
    ListNode* p = revOrder(head);
    while (head != NULL && p != NULL) {
        if (head->val != p->val)
            return false;
        head = head->next;
        p = p->next;
    }

    return true;
}



//note
ListNode* remove_same_value(ListNode* &head, int val) {

    ListNode* fast = head;
    ListNode* slow = NULL;
    ListNode* temp = head;


    if (head == NULL)
        return head;

    while (temp && temp->val == val) {
        temp = temp->next;
    }
    
    head = temp;
    while (temp) {
        if (temp->next != NULL && temp->next->val == val)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }

    return head;

}


//merge two likedlist
//note
ListNode* merge(ListNode* headA, ListNode* headB) {

    ListNode* temp = new ListNode(0);
    ListNode* head = temp;

    while (headA && headB) {
        if (headA->val < headB->val) {
            temp->next = headA;
            headA = headA->next;
        }
        else {
            temp->next = headB;
            headB = headB->next;
        }
        temp = temp->next;
    }

    if (!headA)
        temp->next = headB;
    else 
        temp->next = headA;

    return head->next;
}


// swap note 
//note
ListNode* swap_nodes(ListNode* head, int k) {

    ListNode* right = head;
    ListNode* left = head;
    ListNode* temp = NULL;
    int i = 0;
    
    while (i < k-1) {
        right = right->next;
        i++;
    }
    temp = right;
    right = right->next;
    
    while (right) {
        left = left->next;
        right = right->next;
    }

    swap(left->val, temp->val);
    return head;

}
    


void odd_even_list(ListNode* &head) {

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (odd != NULL && even!=NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;

}



ListNode* rev2(ListNode* head, ListNode* headB) {

    ListNode* head = new node(0);
    ListNode* curr = head;

    ListNode* A = revOrder(headA);
    ListNode* B = reverse(headB);


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
        curr->next = new ListNode(s%10);
        curr = curr->next;
        c = s/10;
    }
    return head->next;

}



vector<ListNode*> splitListToParts(ListNode* root, int k) {

    int cnt = count_nodes(root);
    vector<ListNode*> vec;





}








int main() {


    ListNode* head = NULL;

    push_back(head, 1);
    push_back(head, 2);
    push_back(head, 3);
    push_back(head, 4);
    push_back(head, 5);


    // ListListNode* t = revOrder(head);
    // display(t);

    cout << 5%3;
}