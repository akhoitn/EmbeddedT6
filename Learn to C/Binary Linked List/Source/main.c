#include "../Header/func.h"

int main()
{
    Node *head = NULL;

    srand(time(NULL));
    for (int i = 0; i < 5000; i++)
    {
        int value = rand() % 5000 + 1;
        add_node_sort(&head, value);
    }

    add_node_sort(&head, 2456);

    print_list(head);

    CenterPoint *ptr = centerPoint(head);

    int value = 2456;
    CenterPoint *result = binarySearch(ptr, value);
    if (result != NULL)
    {
        printf("find it %d\n", result->value);
    }
    else
    {
        printf("not to find\n");
    }

    return 0;
}