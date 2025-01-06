class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        if(!head) return nullptr;
        
        Node* temp=head;
        
        while(temp){
            int a=m,b=n;
            Node* prev=NULL;
            while(a-- && temp){
                prev=temp;
                temp=temp->next;
            }
            while(b-- && temp){
                temp=temp->next;
            }
            prev->next=temp;
        }
        return head;
    }
};
