#include <stdio.h>
#include <string.h>
#include "common.h"

#define LOYALTY_LIMIT 5000
#define DISCOUNT_RATE 0.05

// Calculate discount amount
float calculateDiscount(float subtotal)
{
    if (subtotal >= LOYALTY_LIMIT)
    {
        return subtotal * DISCOUNT_RATE;
    }

    return 0;
}

// Find existing customer or generate a new loyalty ID
int getLoyaltyID(char customerName[])
{
    FILE *fp;
    int id, highestID = 1000;
    char name[100];

    fp = fopen("customers.txt", "r");

    if (fp != NULL)
    {
        while (fscanf(fp, "%d|%99[^\n]\n", &id, name) == 2)
        {
            if (id > highestID)
            {
                highestID = id;
            }

            if (strcmp(name, customerName) == 0)
            {
                fclose(fp);
                return id;
            }
        }

        fclose(fp);
    }

    // Generate a new unique ID
    id = highestID + 1;
    

    fp = fopen("customers.txt", "a");

    if (fp == NULL)
    {
        printf("Unable to open customers.txt\n");
        return -1;
    }

    fprintf(fp, "%d|%s\n", id, customerName);

    fclose(fp);

    return id;
}

// Save completed sale
void saveSale(struct Sale sale)
{
    FILE *fp;

    fp = fopen("sales.txt", "a");

    if (fp == NULL)
    {
        printf("Unable to open sales.txt\n");
        return;
    }

    fprintf(fp, "%.2f|%d\n", sale.finalAmount, sale.totalItems);

    fclose(fp);
}

// Display sales report
void generateSalesReport()
{
    FILE *fp;

    float amount;
    float revenue = 0;

    int items;
    int totalItems = 0;
    int transactions = 0;

    fp = fopen("sales.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo sales record found.\n");
        return;
    }

    while (fscanf(fp, "%f|%d", &amount, &items) == 2)
    {
        revenue = revenue + amount;
        totalItems = totalItems + items;
        transactions++;
    }

    fclose(fp);

    printf("\n========== SALES REPORT ==========\n");
    printf("Total Revenue: Rs. %.2f\n", revenue);
    printf("Total Transactions: %d\n", transactions);
    printf("Total Items Sold: %d\n", totalItems);
    printf("=================================\n");
}
