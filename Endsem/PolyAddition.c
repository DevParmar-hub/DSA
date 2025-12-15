#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create a new node
struct Node* newNode(int coeff, int exp) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}

// Insert node in descending order of exponent
struct Node* insertTermSorted(struct Node* head, int coeff, int exp) {
    struct Node* temp = newNode(coeff, exp);

    // Empty list or new node has higher exponent than head
    if(head == NULL || exp > head->exp) {
        temp->next = head;
        return temp;
    }

    struct Node* curr = head;
    while(curr->next != NULL && curr->next->exp >= exp) {
        curr = curr->next;
    }

    // If a term with same exponent exists, add coefficients
    if(curr->exp == exp) {
        curr->coeff += coeff;
        free(temp);
        return head;
     }
    // Insert in proper position
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// Print polynomial
void printPoly(struct Node* head) {
    struct Node* curr = head;
    if(curr == NULL) {
        printf("0\n");
        return;
    }

    while(curr != NULL) {
        if(curr->exp != 0)
            printf("%dx^%d", curr->coeff, curr->exp);
        else
            printf("%d", curr->coeff);

        if(curr->next != NULL) printf(" + ");
        curr = curr->next;
    }
    printf("\n");
}

// Add two polynomials (already sorted)
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    while(p1 != NULL) {
        result = insertTermSorted(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while(p2 != NULL) {
        result = insertTermSorted(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Example usage
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Polynomial 1 (unordered): 2 + 5x^3 + 4x^2
    poly1 = insertTermSorted(poly1, 2, 0);
    poly1 = insertTermSorted(poly1, 5, 3);
    poly1 = insertTermSorted(poly1, 4, 2);

    // Polynomial 2 (unordered): 1 + 3x^3 + 2x
    poly2 = insertTermSorted(poly2, 1, 0);
    poly2 = insertTermSorted(poly2, 3, 3);
    poly2 = insertTermSorted(poly2, 2, 1);

    printf("Polynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    struct Node* sum = addPoly(poly1, poly2);
    printf("Sum: ");
    printPoly(sum);

    return 0;
}
