/* PROGRAM TO PERFORM POLYNOMIAL ADDITION AND MULTIPLICATION USING LINKED 
LIST */ 
#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node { 
    int coeff; 
    int pow; 
    struct Node* next; 
} Node; 
Node* createNode(int coeff, int pow) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->coeff = coeff; 
    newNode->pow = pow; 
    newNode->next = NULL; 
    return newNode; 
} 
Node* insertNode(Node* head, int coeff, int pow) { 
    if (coeff == 0) return head;  // skip zero coefficients 
 
    Node* newNode = createNode(coeff, pow); 
    if (head == NULL || pow > head->pow) { 
        newNode->next = head; 
        return newNode; 
    } 
    Node* temp = head; 
    Node* prev = NULL; 
    while (temp != NULL && temp->pow > pow) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp != NULL && temp->pow == pow) { 
        temp->coeff += coeff;  // merge like terms 
        free(newNode); 
        if (temp->coeff == 0) {  // remove zero terms 
            if (prev == NULL) 
                head = temp->next; 
            else 
                prev->next = temp->next; 
            free(temp); 
        } 
    } else { 
        newNode->next = temp; 
        if (prev != NULL) 
            prev->next = newNode; 
    } 
    return head; 
} 
void display(Node* poly) { 
    if (!poly) { 
        printf("0\n"); 
        return; 
    } 
    while (poly != NULL) { 
        if (poly->coeff > 0 && poly != NULL) printf("+"); 
        printf("%dx^%d", poly->coeff, poly->pow); 
        poly = poly->next; 
    } 
    printf("\n"); 
} 
Node* addPoly(Node* poly1, Node* poly2) { 
    Node* result = NULL; 
    while (poly1 != NULL) { 
        result = insertNode(result, poly1->coeff, poly1->pow); 
        poly1 = poly1->next; 
    } 
    while (poly2 != NULL) { 
        result = insertNode(result, poly2->coeff, poly2->pow); 
        poly2 = poly2->next; 
    } 
    return result; 
} 
Node* multiplyPoly(Node* poly1, Node* poly2) { 
    Node* result = NULL; 
    for (Node* p1 = poly1; p1 != NULL; p1 = p1->next) { 
        for (Node* p2 = poly2; p2 != NULL; p2 = p2->next) { 
            result = insertNode(result, p1->coeff * p2->coeff, p1->pow + 
p2->pow); 
        } 
    } 
    return result; 
} 
Node* readPoly() { 
    Node* poly = NULL; 
    int n, coeff, pow; 
    printf("Enter number of terms: "); 
    scanf("%d", &n); 
    printf("Enter each term as: coefficient power\n"); 
    for (int i = 0; i < n; i++) { 
        scanf("%d %d", &coeff, &pow); 
        poly = insertNode(poly, coeff, pow); 
    } 
    return poly; 
} 
void freePoly(Node* poly) { 
    while (poly != NULL) { 
        Node* temp = poly; 
        poly = poly->next; 
        free(temp); 
    } 
} 
int main() { 
    Node* poly1 = NULL; 
    Node* poly2 = NULL; 
    Node* sum = NULL; 
    Node* product = NULL; 
 
    printf("Enter first polynomial:\n"); 
    poly1 = readPoly(); 
 
    printf("Enter second polynomial:\n"); 
    poly2 = readPoly(); 
 
    printf("\nPolynomial 1: "); 
    display(poly1); 
 
    printf("Polynomial 2: "); 
    display(poly2); 
 
    sum = addPoly(poly1, poly2); 
    printf("\nSum: "); 
    display(sum); 
 
    product = multiplyPoly(poly1, poly2); 
    printf("Product: "); 
    display(product); 
 
    freePoly(poly1); 
    freePoly(poly2); 
    freePoly(sum); 
    freePoly(product); 
 
    return 0; 
} 
 
