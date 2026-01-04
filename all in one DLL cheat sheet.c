#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int info;
    struct node *next;
};

// Insert at beginning
struct node* insert_begin(struct node* f, int data) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->prev = NULL;
    newnode->next = f;
    if (f) f->prev = newnode;
    return newnode;
}

// Insert at end
struct node* insert_end(struct node* f, int data) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = NULL;
    if (f == NULL) {
        newnode->prev = NULL;
        return newnode;
    }
    struct node* current = f;
    while (current->next) current = current->next;
    current->next = newnode;
    newnode->prev = current;
    return f;
}

// Insert at position (1-based)
struct node* insert_at_position(struct node* f, int data, int pos) {
    if (pos == 1) return insert_begin(f, data);
    struct node* current = f;
    for (int i = 1; i < pos -1 && current; i++) current = current->next;
    if (current == NULL) {
        printf("Position %d invalid\n", pos);
        return f;
    }
    struct node* newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = current->next;
    newnode->prev = current;
    if (current->next) current->next->prev = newnode;
    current->next = newnode;
    return f;
}

// Insert after a given value (first occurrence)
struct node* insert_after_value(struct node* f, int target, int data) {
    struct node* current = f;
    while (current && current->info != target) current = current->next;
    if (!current) {
        printf("Value %d not found\n", target);
        return f;
    }
    struct node* newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = current->next;
    newnode->prev = current;
    if (current->next) current->next->prev = newnode;
    current->next = newnode;
    return f;
}

// Delete at beginning
struct node* delete_begin(struct node* f) {
    if (!f) return NULL;
    struct node* temp = f;
    f = f->next;
    if (f) f->prev = NULL;
    free(temp);
    return f;
}

// Delete at end
struct node* delete_end(struct node* f) {
    if (!f) return NULL;
    if (!f->next) { free(f); return NULL; }
    struct node* current = f;
    while (current->next) current = current->next;
    current->prev->next = NULL;
    free(current);
    return f;
}

// Delete at position (1-based)
struct node* delete_at_position(struct node* f, int pos) {
    if (!f) return NULL;
    if (pos == 1) return delete_begin(f);
    struct node* current = f;
    for (int i = 1; i < pos && current; i++) current = current->next;
    if (!current) {
        printf("Position %d invalid\n", pos);
        return f;
    }
    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;
    free(current);
    return f;
}

// Delete target (first occurrence)
struct node* delete_target(struct node* f, int target) {
    struct node* current = f;
    while (current && current->info != target) current = current->next;
    if (!current) {
        printf("Value %d not found\n", target);
        return f;
    }
    if (current == f) return delete_begin(f);
    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;
    free(current);
    return f;
}

// Reverse DLL
struct node* reverse(struct node* f) {
    struct node *current = f, *prev = NULL, *nextnode;
    while (current) {
        nextnode = current->next;
        current->next = prev;
        current->prev = nextnode;
        prev = current;
        current = nextnode;
    }
    return prev;
}

// Search for element (returns 1 if found else 0)
int search(struct node* f, int target) {
    struct node* current = f;
    while (current) {
        if (current->info == target) return 1;
        current = current->next;
    }
    return 0;
}

// Count nodes
int count_nodes(struct node* f) {
    int count = 0;
    struct node* current = f;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// Display forward
void display(struct node* f) {
    struct node* current = f;
    if (!f) { printf("List empty\n"); return; }
    printf("NULL <-> ");
    while (current) {
        printf("%d <-> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
}

// Display reverse
void display_reverse(struct node* f) {
    if (!f) { printf("List empty\n"); return; }
    struct node* current = f;
    while (current->next) current = current->next;
    printf("NULL <-> ");
    while (current) {
        printf("%d <-> ", current->info);
        current = current->prev;
    }
    printf("NULL\n");
}

// Check palindrome
int is_palindrome(struct node* f) {
    if (!f) return 1;
    struct node* start = f;
    struct node* end = f;
    while (end->next) end = end->next;
    while (start != end && start->prev != end) {
        if (start->info != end->info) return 0;
        start = start->next;
        end = end->prev;
    }
    return 1;
}

// Find middle element (fast-slow pointer)
int find_middle(struct node* f) {
    if (!f) {
        printf("List empty\n");
        return -1; // or any sentinel
    }
    struct node* slow = f;
    struct node* fast = f;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->info;
}

// Insertion sort (data swap version)
struct node* insertion_sort(struct node* f) {
    if (!f) return NULL;
    struct node *i, *j;
    int temp;
    for (i = f; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
    return f;
}

// Main for testing
int main() {
    struct node* first = NULL;

    first = insert_end(first, 3);
    first = insert_end(first, 1);
    first = insert_end(first, 4);
    first = insert_end(first, 1);
    first = insert_end(first, 5);

    printf("Original List:\n");
    display(first);

    first = insertion_sort(first);
    printf("Sorted List:\n");
    display(first);

    printf("Is palindrome? %s\n", is_palindrome(first) ? "Yes" : "No");

    printf("Middle element: %d\n", find_middle(first));

    printf("Display reverse:\n");
    display_reverse(first);

    first = reverse(first);
    printf("List after reverse:\n");
    display(first);

    return 0;
}
