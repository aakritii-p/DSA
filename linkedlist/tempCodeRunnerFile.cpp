
struct node* reverse(int k, struct node* head)
{
    if(!head)
      return NULL;
    head->prev = NULL;
    struct node* current = head;
    struct node* prevnode;
    struct node* newhead;
    int count = 0;
    while(count<k && current!=NULL)
    {
        newhead=current;
        prevnode = current->prev;
        current->prev = current->next;
        current->next = prevnode;
        current = current->prev;
        count++;
    }
    if(count>=k)
    {
        head->next = reverse(k,current);
    }
    return newhead;
}