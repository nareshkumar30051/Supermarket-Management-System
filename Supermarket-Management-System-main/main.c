#include "common.h"
int main()
{
    struct Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;
    loadProducts(products, &count);
    checkLowStock(products, count);
    do
    {
        printf("\n===== SUPERMARKET MANAGEMENT SYSTEM =====\n");
        printf("1. Inventory Management\n");
        printf("2. Customer Order & Billing\n");
        printf("3. Sales Reports\n");   
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
{
    printf("Please enter a valid number!\n");

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    continue;
}
        switch(choice)
        {
            case 1:
                inventoryMenu(products, &count);
                break;
            case 2:
                placeOrder(products, count);
                break;
            case 3:
                generateSalesReport();
                break;
            case 4:
                printf("Thank you for using our system!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
    return 0;
}