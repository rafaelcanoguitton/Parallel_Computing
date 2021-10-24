#include <stdio.h>
//Defining linked list class
struct list_node_s
{
    int data;
    struct list_node_s *next;
};
int Member(int value, struct list_node_s *head_p)
{
    struct list_node_s *curr_p = head_p;
    while (curr_p != NULL && curr_p->data < value)
        curr_p = curr_p->next;
    if (curr_p == NULL || curr_p->data > value)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int Insert(int value, struct list_node_s **head_p)
{
    struct list_node_s *curr_p = *head_p;
    struct list_node_s *pred_p = NULL;
    struct list_node_s *temp_p;
    while (curr_p != NULL && curr_p->data < value)
    {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }
    if (curr_p == NULL || curr_p->data > value)
    {
        temp_p = malloc(sizeof(struct list_node_s));
        temp_p->data = value;
        temp_p->next = curr_p;
        if (pred_p == NULL)
            *head_p = temp_p;
        else
            pred_p->next = temp_p;
        return 1;
    }
    else
    {
        return 0;
    }
}
int Print(struct list_node_s *head_p)
{
    struct list_node_s *curr_p = head_p;
    while (curr_p != NULL)
    {
        printf("%d ", curr_p->data);
        curr_p = curr_p->next;
    }
    printf("\n");
    return 1;
}
int main()
{
    struct list_node_s *head_p = NULL;
    int i;
    for (i = 0; i < 10; i++)
    {
        Insert(i, &head_p);
    }
    Print(head_p);
    return 0;
}