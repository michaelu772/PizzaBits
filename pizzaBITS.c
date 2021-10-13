#include <stdio.h>

#define MUSHROOMS   0x01
#define ONIONS      0x02
#define ANCHOVIES   0x04
#define PEPPERONI   0x08
#define JALAPENOS   0x10
#define OLIVES      0x20
#define PINEAPPLE   0x40
#define HAM         0x80
#define ING_SIZE    8

const int INGREDIENTS[ING_SIZE] = {MUSHROOMS, ONIONS, ANCHOVIES, PEPPERONI, JALAPENOS, OLIVES, PINEAPPLE, HAM};
const char* INGREDIENT_NAMES[ING_SIZE] = {"MUSHROOMS", "ONIONS", "ANCHOVIES", "PEPPERONI", "JALAPENOS", "OLIVES", "PINEAPPLE", "HAM"};

void dec_to_bit(int num);
void decode_pizza(int pizza);
int order_pizza(void);

int main(void)
{
    auto int pizza = 0;
    //pizza = PINEAPPLE|HAM|ONIONS|PEPPERONI;
    pizza = order_pizza();
    printf("The pizza has a decimal value of %d.\n", pizza);
    dec_to_bit(pizza);
    decode_pizza(pizza);
    return 0;
}

void decode_pizza(int pizza) {
    auto int i, rShift, bitCounter = 0;
    
    for (i = (sizeof(int) * 8); i >= 0; --i) {
        if(rShift & 1) {
            printf("This pizza contains %s(0x%.2x)\n", INGREDIENT_NAMES[i], INGREDIENTS[i]);
        }
        rShift = pizza>>(i - 1);
    }
}

int order_pizza() {
    auto int input, pizza = 0;
    printf("Please enter decimal value of the toppings you would like on your pizza followed by an enter.\n");
    printf("Press CTRL+D to finish ordering.\nMENU:");
    for (int i = 0; i < ING_SIZE; ++i) {
        printf("\t%s(%d)\n", INGREDIENT_NAMES[i], INGREDIENTS[i]);
    }
    while (EOF != scanf("%d", &input)) {
        pizza |= input;
    }
    return pizza;
}

void dec_to_bit(int num) {
    auto int intVal, i, rShift, bitCounter = 0;

    for(i = (sizeof(int) * 8); i > 0; --i) {
        if(bitCounter % 16 == 0 && 0 != bitCounter) {
	        printf(" ");
	        }
        ++bitCounter;

        rShift = num>>(i - 1);

        if(rShift & 1) {
	        printf("1");
	        ++bitCounter;
	        }
	    else {
	        printf("0");
	        ++bitCounter;
	        }
        }
     printf("\n");
}