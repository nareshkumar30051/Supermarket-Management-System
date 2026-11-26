#include "common.h"
void placeOrder(struct Product products[],int count)
{
    char customername[50];
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    printf("Enter Customer Name: ");
    fgets(customername, 50, stdin);
    customername[strcspn(customername,"\n")]='\0';
    viewProducts(products,count);
    int id,quantity,index,loyaltyid,totalitems=0,orderConfirmed;
    char choice;
    float subtotal=0;
    int orderedquantity[100]={0};
    struct Sale sale;
    do{
        printf("Enter Product ID: ");
        scanf("%d",&id);
        index=searchProduct(products,count,id);
        if(index==-1){
            printf("Product Not found!");
        }
        else{
            printf("Enter Quantity: ");
            scanf("%d",&quantity);
            if(quantity>0 && quantity<=products[index].quantity-orderedquantity[index])
            {
                subtotal=subtotal+(products[index].price*quantity);
                totalitems+=quantity;
                orderedquantity[index]+=quantity;
                printf("Product added successfully!\n");
                printf("Current subtotal:   %.2f\n",subtotal);
            }
            else{
                printf("Invalid Quantity or Insufficeint Stock!\n");
            }
        }

        printf("Add Another Product? (Y/N)");
        scanf(" %c",&choice);
    }while(choice=='y'||choice=='Y');
    if(subtotal==0){
        printf("No product selected! Ordered Cancelled.\n");
        return ;
    }
    printf("Confirm Order?(1=Yes,0=No): ");
    scanf("%d",&orderConfirmed);
    if(orderConfirmed==1){
        printf("Order Confirmed!\n");
        for(int i=0;i<count;i++){
            products[i].quantity=products[i].quantity-orderedquantity[i];
        }
        saveProducts(products,count);
    }
    else{
        printf("Order Cancelled!\n");
        return;
    }
    loyaltyid=getLoyaltyID(customername);
    float discount=0,finalamount=0;
    discount=calculateDiscount(subtotal);
    finalamount=subtotal-discount;
    strcpy(sale.customerName,customername);
    sale.loyaltyID=loyaltyid;
    sale.totalItems=totalitems;
    sale.subtotal=subtotal;
    sale.discount=discount;
    sale.finalAmount=finalamount;
    saveSale(sale);
    printf("\nCustomer Bill");
    printf("Loyalty ID :%d\n",loyaltyid);
    printf("Customer Name:%s\n",customername);
    printf("Total items: %d\n",totalitems);
    printf("Subtotal: Rs. %.2f\n",subtotal);
    printf("Discount: Rs. %.2f\n",discount);
    printf("Final Amount = %.2f\n",finalamount);
    printf("===\n");


}