/*DataStructureOperations */

#include <stdio.h>
#include <stdlib.h>
/* Program usage instructions before main (see line 106) */
struct Node
{                       // definition of a node in a list
    int data;           // an integer
    struct Node* next;  // pointer to the next element in the list
};

// Question 1 (implementation of the swap function):
void swap(int *a, int *b)
{
    /* we will create a temporary variable named temp
       and store the value of a */
    int temp = *a;   
    *a = *b;    /* we will copy the value of b to a */
    *b = temp;  /* we will copy the value of the temp variable (i.e., the value of a) to b */

    /* Answers to the questions:
    -->1. The use of variable addresses (with the & operator) is necessary because the swap function
            needs to access the original variables in memory. By providing
            the addresses, the function can modify the values of these variables directly in memory,
            instead of working with copies of their values. This is achieved through the use of pointers.
    -->2. If the function is declared as void swap(int a, int b) and called as swap(x, y) without using pointers,
        then the values of the variables x and y will not change. This is because the parameters a and b will be
        local variables of the swap function, and any changes to them will not affect the original
        variables x and y that are outside the function. The function will work with copies of the values of
        x and y and not with the variables themselves. */
}

/* Question 2 (implementation of find_min_max_array): The function finds the minimum (min) and maximum (max) element
   of an integer array (A[]). */
void find_min_max_array(int A[], int size, int *min, int *max)
{
    *min = A[0]; /* Initialize min with the first element of the array */
    *max = A[0]; /* Initialize max with the first element of the array */

    /* we will start from the second element (i=1), because we have already used A[0] for initialization. */
    for(int i=1; i< size; i++) 
    {
        if (A[i] < *min) /* If A[i] is less than *min, then *min is updated with the new value. */
        {
            *min = A[i]; /* Update min */
        }
        if (A[i] > *max) /* If A[i] is greater than *max, then *max is updated with the new value. */
        {
            *max = A[i];
        }
    }
}

// implementation of reverse_array 
void reverse_array(int A[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(&A[i], &A[size - 1 - i]); // swap elements using the swap function
    }
}

// Question 3 (implementation of find_min_max_list):
void find_min_max_list(struct Node* head, int *min, int *max)
{
    if(head == NULL)
    {
        return; /* If the list is empty, do nothing */
    }
    
    *min = head->data; /* Initialize min with the first element of the list. */
    *max = head->data; /* Initialize max with the first element of the list. */

    struct Node* current = head->next;   /* start from the second element - node */
    while (current != NULL)
    {
        if(current->data < *min)
        {
            *min = current->data;     /* Update min if a smaller element is found */
        }
        if (current->data > *max)
        {
            *max = current->data;   /* Update max if a larger element is found */
        }
        current = current->next;    /* Move to the next element */
    }
}

// implementation of reverse_list
struct Node* reverse_list(struct Node* head)
{
    struct Node* prev = NULL;    /* pointer to the previous node */
    struct Node* current = head;  /* pointer to the current node */
    struct Node* next = NULL;    /* pointer to the next node */

    while(current != NULL)
    {
        next = current->next;   /* store the next node */
        current->next = prev;   /* reverse the pointer of the current node */
        prev = current;         /* move the prev pointer to the current node */
        current = next;         /* move the current pointer to the next node */
    }

    head = prev; // update the head of the list
    return head; // return the new head of the list
}

/*               |---------------PROGRAM USAGE INSTRUCTIONS---------------|
   The program includes 5 functions that manage an array and a linked list,
   performing operations to find the minimum/maximum value, reverse values, and swap values.
                               ||----->FUNCTIONS<-----||
   - Step 1 --> Function "swap": Swaps the values of two variables using a temporary storage.
   - Step 2 --> Function "find_min_max_array": Finds the smallest and largest value in an integer array
                           and updates the "min" and "max" variables.
   - Step 3 --> Function "reverse_array": Reverses the elements of an array using the "swap" function.
   - Step 4 --> Function "find_min_max_list": Traverses a linked list and finds the smallest and largest value.
   - Step 5 --> Function "reverse_list": Reverses a linked list by changing the pointers of the nodes.
                               |||---MAIN FUNCTION---|||
    ----A. An array A[7] is defined, initialized with predefined values, and printed on the screen.
    ----B. The find_min_max_array function is called to find the minimum and maximum values of the array, printing the results.
    ----C. The array is reversed with reverse_array and its new form is printed.
    ----D. A linked list is created using the values of the array and printed on the screen.
    ----E. The find_min_max_list function is called to find the minimum and maximum values of the list, displaying the results.
    ----F. The list is reversed with reverse_list and its new form is displayed.                                
*/

int main()
{
    int A[7];                    // integer array with 7 positions, for testing the functions
    int size;                    // the size of the array 
    int i;                       // auxiliary variable for loop implementation
    int min, max;                // variables that will be used for results 
                                 // that will be returned as the smallest and largest
                                 // values from the functions
    struct Node* head;           // pointer to the start of the list
    struct Node* temp;           // auxiliary pointer in the list
    struct Node* new_node;       // pointer that will be used to create a new node
    
    // array initialization for testing
    A[0] = 4;                    
    A[1] = 5;
    A[2] = 8;
    A[3] = 2;
    A[4] = 9;
    A[5] = 8;
    A[6] = 1;
    size = 7;

    printf("\n\t\t------|| PROGRAM START ||------\n");
    // display the array on the screen
    printf("\nA--> Initial Array: ");    
    for (i = 0; i < size; i++)
    {   // each element is traversed
        printf("%d ", A[i]);     // and printed on the screen
    }
    printf("\n");
    
    // call and display results of find_min_max_array
    find_min_max_array(A, size, &min, &max); 
    printf("B--> Min in array: %d, Max in array: %d\n", min, max);

    // call and display results of reverse_array
    reverse_array(A, size);
    printf("C--> Array after reversal: ");
    for (i = 0; i < size; i++)
    {   // each element is traversed
        printf("%d ", A[i]);     // and printed on the screen
    }
    printf("\n");

    // create list for testing
    head = NULL;    // first element
    temp = NULL;    // auxiliary pointer to the last element
    for (i = 0; i < size; i++)
    {
        // integers from the array are inserted into the list
        new_node = (struct Node*)malloc(sizeof(struct Node));  // new node
        new_node->data = A[i];     // with the element from the array
        new_node->next = NULL;     // which will be the last at this moment
        if (head == NULL) {        // if it is the first element of the list
            head = new_node;       // place the pointer there
        } else {                   // otherwise 
            temp->next = new_node; // place it at the end
        }
        temp = new_node;           // and make this the last
    }

    // display the list on the screen
    printf("D--> Initial list: ");  
    struct Node* current = head;    // start from the first element
    while (current != NULL)
    {       // visit each element until the last
        printf("%d -> ", current->data);  // print the data field
        current = current->next;    // move to the next element
                                    // to continue the loop
    }
    printf("NULL\n");

    // call and display results of find_min_max_list
    find_min_max_list(head, &min, &max);
    printf("E--> Min in list: %d, Max in list: %d\n", min, max);

    // call and display results of reverse_list
    head = reverse_list(head);
    printf("F--> List after reversal: ");
    current = head;             // start from the first element
    while (current != NULL)
    {   // visit each element until the last
        printf("%d -> ", current->data); // print the data field
        current = current->next;    // move to the next element
                                    // to continue the loop
    }
    printf("NULL\n");
    printf("\n\t\t------|| PROGRAM END ||-------\n");

    
    return 0;
}
