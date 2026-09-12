struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    while (list1 != NULL)
    {
        struct ListNode* newNode = malloc(sizeof(struct ListNode));

        newNode->val = list1->val;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        struct ListNode* newNode = malloc(sizeof(struct ListNode));

        newNode->val = list2->val;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        list2 = list2->next;
    }

    int swapped = 1;

    while (swapped == 1)
    {
        swapped = 0;
        struct ListNode* current = head;

        while (current != NULL && current->next != NULL)
        {
            if (current->val > current->next->val)
            {
                int temp = current->val;
                current->val = current->next->val;
                current->next->val = temp;
                swapped = 1;
            }

            current = current->next;
        }
    }

    return head;
}