#include "common.h"
#include <stdlib.h>
// Load products from file
void loadProducts(struct Product p[], int *count) {
    FILE *fp = fopen("products.txt", "r");
    *count = 0;
    if (!fp) return;

    while (*count < MAX_PRODUCTS &&
           fscanf(fp, "%d %49s %f %d",
                  &p[*count].id, p[*count].name,
                  &p[*count].price, &p[*count].quantity) == 4)
        (*count)++;

    fclose(fp);
}

// Save products to file
void saveProducts(struct Product p[], int count) {
    FILE *fp = fopen("products.txt", "w");
    if (!fp) return;

    for (int i = 0; i < count; i++)
        fprintf(fp, "%d %s %.2f %d\n",
                p[i].id, p[i].name, p[i].price, p[i].quantity);

    fclose(fp);
}

// Search product
int searchProduct(struct Product p[], int count, int id) {
    for (int i = 0; i < count; i++)
        if (p[i].id == id) return i;
    return -1;
}

// Add product
void addProduct(struct Product p[], int *count) {
    if (*count >= MAX_PRODUCTS) return;

    struct Product x;
    printf("Enter ID, Name, Price, Quantity: ");
    if (scanf("%d %49s %f %d", &x.id, x.name,
              &x.price, &x.quantity) != 4) return;

    if (searchProduct(p, *count, x.id) != -1 ||
        x.price < 0 || x.quantity < 0) {
        printf("Invalid or duplicate product!\n");
        return;
    }

    p[(*count)++] = x;
    saveProducts(p, *count);
    printf("Product added!\n");
}

// View products
void viewProducts(struct Product p[], int count) {
    printf("\nID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++)
        printf("%d\t%s\t%.2f\t%d\n",
               p[i].id, p[i].name, p[i].price, p[i].quantity);
}

// Update product
void updateProduct(struct Product p[], int count) {
    int id;
    viewProducts(p,count);
    printf("Enter Product ID: ");
    if (scanf("%d", &id) != 1) return;

    int i = searchProduct(p, count, id);
    if (i == -1) {
        printf("Not found!\n");
        return;
    }

    printf("Enter new Price and Quantity: ");
    float price;
    int quantity;
    if (scanf("%f %d", &price, &quantity) != 2 ||
        price < 0 || quantity < 0) return;

    p[i].price = price;
    p[i].quantity = quantity;
    saveProducts(p, count);
    printf("Updated!\n");
}

// Delete product
void deleteProduct(struct Product p[], int *count) {
    int id;
    printf("Enter Product ID: ");
    if (scanf("%d", &id) != 1) return;

    int i = searchProduct(p, *count, id);
    if (i == -1) {
        printf("Not found!\n");
        return;
    }

    for (int j = i; j < *count - 1; j++)
        p[j] = p[j + 1];

    (*count)--;
    saveProducts(p, *count);
    printf("Deleted!\n");
}

// Low stock alert
void checkLowStock(struct Product p[], int count) {
    for (int i = 0; i < count; i++)
        if (p[i].quantity <= LOW_STOCK_LIMIT)
            printf("Low Stock: %s (%d left)\n",
                   p[i].name, p[i].quantity);
}

// Inventory menu
void inventoryMenu(struct Product p[], int *count) {
    int choice, id, i;

    do {
        printf("\n1.Add \n2.View \n3.Search \n4.Update");
        printf("\n5.Delete \n6.Low Stock \n0.Exit\n");

        if (scanf("%d", &choice) != 1) return;

        switch (choice) {
            case 1: addProduct(p, count); break;
            case 2: viewProducts(p, *count); break;
            case 3:
                printf("Enter ID: ");
                if (scanf("%d", &id) != 1) return;
                i = searchProduct(p, *count, id);
                if (i == -1) printf("Not found!\n");
                else printf("%s %.2f %d\n", p[i].name,
                            p[i].price, p[i].quantity);
                break;
            case 4: updateProduct(p, *count); break;
            case 5: deleteProduct(p, count); break;
            case 6: checkLowStock(p, *count); break;
        }
    } while (choice != 0);
}
