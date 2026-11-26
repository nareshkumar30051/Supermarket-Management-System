
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define LOW_STOCK_LIMIT 5
#define LOYALTY_LIMIT 5000
#define LOYALTY_DISCOUNT 0.05

// Product Structure
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Sales Structure
struct Sale {
    char customerName[50];
    int loyaltyID;
    int totalItems;
    float subtotal;
    float discount;
    float finalAmount;
};

// Naresh - Inventory Functions
void loadProducts(struct Product products[], int *count);
void saveProducts(struct Product products[], int count);
void inventoryMenu(struct Product products[], int *count);
void addProduct(struct Product products[], int *count);
void viewProducts(struct Product products[], int count);
int searchProduct(struct Product products[], int count, int id);
void updateProduct(struct Product products[], int count);
void deleteProduct(struct Product products[], int *count);
void checkLowStock(struct Product products[], int count);

// Abbas - Billing Functions
void placeOrder(struct Product products[], int count);

// Munesh - Reports and Loyalty Functions
int getLoyaltyID(char customerName[]);
float calculateDiscount(float subtotal);
void saveSale(struct Sale sale);
void generateSalesReport(void);

#endif
