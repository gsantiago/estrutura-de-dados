#include <stdio.h>
#include "get_double.h"

int main() {
  double price, tip;

  price = get_double("Enter price meal: ", 0, 1000);
  tip = get_double("Enter tip amount (percent): ", 0, 100);

  double tip_amount = price * tip / 100;
  double total = price + tip_amount;

  printf("Tip amount: %lf\n", tip_amount);
  printf("Total amount: %lf\n", total);

  return 0;
}
