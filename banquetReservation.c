//Mustfa Alshara
//CIS-170
#include <stdio.h>

char determineBanquetRoom(int guestNum);
float determineRoomPrice(char roomChoice);
float determineFoodPrice(int guestNum);
float determineEquipmentPrice();
void displayPrices(char roomChoice, int guestNum, float prices[]);

int main()
{
  int guestNum;
  char roomChoice;
  float roomPrice, foodPrice, equipmentPrice;
  float prices[4] = {0.00, 0.00, 0.00, 0.00};
  
  printf("Welcome to Holiday Banquet Center!");
  printf("\nHow many guests do you expect? ");
  scanf("%d", &guestNum);
  while (guestNum < 15 || guestNum > 250)
    {
      printf("Invalid input, must be 15-250.");
      printf("\nHow many guests do you expect? ");
      scanf("%d", &guestNum);
    }
  roomChoice = determineBanquetRoom(guestNum);
  roomPrice = determineRoomPrice(roomChoice);
  foodPrice = determineFoodPrice(guestNum);
  equipmentPrice = determineEquipmentPrice();
  
  prices[1] = roomPrice;
  prices[2] = foodPrice;
  prices[3] = equipmentPrice;
  
  displayPrices(roomChoice, guestNum, prices);
  
  return 0;
}
//-----------------------------------------------------------
char determineBanquetRoom(int guestNum)
{
  char roomChoice;
  
  printf("Based on the number of guests, \n you have the choice of the following rooms:");
  if (guestNum >= 15 && guestNum <= 25)
    {
      printf("\nC - Cozy Cabin");
    }
  if (guestNum >= 15 && guestNum <= 75)
    {
      printf("\nP - Purple parlor");
    }
  if (guestNum >= 50 && guestNum <= 125)
    {
      printf("\nD - Deluxe Dining");
    }
  if (guestNum >= 50 && guestNum <= 150)
    {
      printf("\nB - Big Ballroom");
    }
  if (guestNum >= 100 && guestNum <= 250)
    {
      printf("\nG - Grand Guestroom");
    }
  printf("\nPlease choose from the available rooms above: --> ");
  scanf("\n %c", &roomChoice);

  return roomChoice; 
}
//-----------------------------------------------------------
float determineRoomPrice(char roomChoice)
{
  float roomPrice;
  switch(roomChoice)
  {
    case 'c': case 'C':
      roomPrice = 250.00;
      break;
    case 'p': case 'P':
      roomPrice = 250.00;
      break;
    case 'd': case 'D':
      roomPrice = 500.00;
      break;
    case 'b': case 'B':
      roomPrice = 500.00;
      break;
    case 'g': case 'G':
      roomPrice = 750.00;
      break;
    default:
      roomPrice = 0.0;
      break;
  }
  return roomPrice;
}
//---------------------------------------------------------------------
float determineFoodPrice(int guestNum)
{
  int entreeChoice;
  float pricePer = 0.0, foodPrice;
  char dessertChoice;
  printf("Would you like one main entree or two?");
  scanf("%d", &entreeChoice);
  switch(entreeChoice)
    {
      case 1:
        pricePer += 17.00;
        break;
      case 2:
        pricePer += 19.50;
        break;
      default:
        printf("Invalid choice, try again!");
        printf("Would you like one main entree or two?");
        scanf("%d", &entreeChoice); 
    }

  printf("Would you like dessert Y/N? ");
  scanf("\n%c", &dessertChoice);
  switch(dessertChoice)
    {
      case 'y': case 'Y':
          pricePer += 2.00;
          break;
      case 'n': case 'N':
          break;
    }

  foodPrice = pricePer * guestNum;

  return foodPrice; 
}
//---------------------------------------------------------------------------------
float determineEquipmentPrice()
{
  float equipmentPrices[5] = {100.00, 25.00, 50.00, 10.00, 5.00};
  int equipmentChoice;
  float equipmentTotal = 0.0;
  char equipment;
  printf("Would you like any equipment? Y/N");
  scanf("\n%c", &equipment);

  while(equipment == 'y' || equipment == 'Y')
    {
      printf("\n1 - Projector  $ %.2f", equipmentPrices[0]);
      printf("\n2 - Screen  $ %.2f", equipmentPrices[1]);
      printf("\n3 - Sound Box  $ %.2f", equipmentPrices[2]);
      printf("\n4 - 8-foot Table  $ %.2f", equipmentPrices[3]);
      printf("\n5 - Easel  $ %.2f", equipmentPrices[4]);
      printf("\nEnter a choice or 0 to quit: ");
      scanf("%d", &equipmentChoice);
      
      switch(equipmentChoice)
      {
        case 5:
          equipmentTotal += 5.00;
          break;
        case 4:
          equipmentTotal += 10.00;
          break;
        case 3:
          equipmentTotal += 50.00;
          break;
        case 2:
          equipmentTotal += 25.00;
          break;
        case 1:
          equipmentTotal += 100.00;
          break;
        case 0:
          break;
      }
      printf("\nYour equipment cost is currently %.2f", equipmentTotal);
      printf("\nDo you need more equipment? Y/N");
      scanf("\n%c", &equipment);
    }
    
  return equipmentTotal;
}

void displayPrices(char roomChoice, int guestNum, float prices[])
{
  float serviceFee, finalPrice, subTotal;

  subTotal = prices[1] + prices[2] + prices[3];
  printf("Your quote to rent the %c for %d guests will be: ", roomChoice, guestNum);
  printf("\nRoom Price  %.2f", prices[1]);
  printf("\nFood Price  %.2f", prices[2]);
  printf("\nEquipment Price  %.2f", prices[3]);

  serviceFee = subTotal * .21;
  printf("\nService Fee  %.2f", serviceFee);

  finalPrice = subTotal + serviceFee;
  printf("\nTotal Cost  %.2f", finalPrice);
}

