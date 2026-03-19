#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(int val){
        value = val;
        next = NULL;
    }
};

struct List{
    Node* head;
    Node* tail;

    List(){
        head=tail=NULL;
    }

    void pushFront(int val){
        Node* newNode = new Node(val);
        if (head==NULL)
        {
            head=tail=newNode;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }

    void pushBack(int val){
        Node* newNode = new Node(val);
        if (head==NULL)
        {
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void accessNodes(){
        Node* temp = head;
        int pos = 3; 
        int count = 1;
        while(temp != NULL && count < pos){
            temp = temp->next;
            count++;
        }
        if(temp != NULL)
            cout << "Node at position " << pos << " is: " << temp->value << endl;
        else
            cout << "Position exceeds list length" << endl;

    }

    void popFront(){
        if(head==NULL){
            cout << "Linked List is empty" << endl;
            return;
        }
        Node* temp = head ;
        head = head->next;
        temp->next=NULL;

        delete temp;
    }

    void popBack(){
        if (head==NULL)
        {
            return;
        }
        Node* temp = head;
        while (temp->next!=tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insertAfter(int val,int key){
        Node* temp = head;
        while (temp!=NULL)
        {
            if (temp->value==key)
            {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next=newNode;
            }
            temp = temp->next;
        }
    }

    void popNode(int key){
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* current = head;
        while (current->next!=NULL && current->next->value!=key)
        {
            current = current->next;
        }
        if (current->next == NULL)
        {
            cout << "value not found" << endl;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void deleteList() {

        Node* temp;

        while (head != NULL) {  
            temp= head;      
            head = head->next;  
            delete temp;        
        }

        cout << "Linked List deleted successfully!" << endl;
    }

    
    void printReverseRecursive(Node* node) {
        if (node == NULL)
        return;
        
        printReverseRecursive(node->next);
        cout << node->value << "->";
    }
    
    void displayReverseRec() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        
        printReverseRecursive(head);
        cout << "NULL" << endl;
    }

    static List mergeLists(List& l1, List& l2) {
        
        List newList;
        
        Node* temp = l1.head;
        while (temp != NULL) {
            newList.pushBack(temp->value);
            temp = temp->next;
        }
        temp = l2.head;
        while (temp != NULL) {
            newList.pushBack(temp->value);
            temp = temp->next;
        }
        
        return newList;
    }

    int listSize(){
        int count = 0;
        Node* temp = head;
        while (temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }

    int countOccurrences(int key) {

        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            if (temp->value == key) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    void printList(){
        Node* temp = head;
        while (temp!=NULL)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    List l1;
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushBack(3);
    cout << "Linked List 1 : " << endl;
    l1.printList();
    int size = l1.listSize();
    cout << "Size: " << size << endl;
    int key = 3;
    int result = l1.countOccurrences(key);
    cout << key << " found " << result << " times" << endl;

    return 0;
}