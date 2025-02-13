#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

class Pizza
{
  private:
  std:: string pizzaType;//[3] = {"deep dish", "hand tossed", "pan"};
  std:: string pizzaSize;
  int toppings;

  public:
  Pizza(std:: string pizzaType, std:: string pizzaSize, int toppings)
  {
    this->pizzaType = pizzaType;
    this->pizzaSize = pizzaSize;
    this->toppings = toppings;
  }
  //gets and sets
  std:: string getType(){return pizzaType;}
  void setType(std:: string type){pizzaType = type;}

  std:: string getSize(){return pizzaSize;}
  void setSize(std:: string size){pizzaSize = size;}

  int getToppings(){return toppings;}
  void setToppings(int topping){toppings = topping;}

  void displayPizzaDesc()
  {
    std:: cout<< "\n" + pizzaSize + ", " + pizzaType + ", " + std:: to_string(toppings) + " topping pizza";
  }

  float pizzaPrice()
  {
    float toppingPrice = toppings * 2;
    float sizePrice;
    float totalPrice;
    if (pizzaSize == "small")
    {
      sizePrice = 10;
    }
    else if(pizzaSize == "medium")
    {
      sizePrice = 14;
    }
    else if(pizzaSize == "large")
    {
      sizePrice = 17;
    }
    totalPrice = sizePrice + toppingPrice;
    return totalPrice;
  }
};//end pizza class

class Order
{
  private:
  std:: vector<Pizza> pizzaVector;
  std:: string name;
  int phoneNum;

  public:

  Order(std:: string name, int phoneNum)
  {
    this->name = name;
    this->phoneNum = phoneNum;
  }
//function to add pizza object into vecotr
  void addPizza(Pizza onePizza)
  {
    onePizza.pizzaPrice();
    pizzaVector.push_back(onePizza);
  }
//function to display the total order by going through the pizza vector
  void displayOrder()
  {
    float total = 0;
    for (Pizza onePizza :pizzaVector)
      {
        onePizza.displayPizzaDesc();
        total += onePizza.pizzaPrice();
      }
    std:: cout << "\nYour total is: $" << total;
    
  }
  
};//end order class

Pizza inputOrder();

int main() 
{
  std:: cout<<std::setprecision(2)<<std::fixed;
  std:: string name;
  int phoneNum;
  char morePizza;
  /*
  Order newOrder("Mustfa", 324234123);
  Pizza onePizza;
  onePizza.setSize("Small");
  onePizza.setToppings(3);
  onePizza.setType("Hand tossed");
  newOrder.addPizza(onePizza);
  newOrder.displayOrder();
  */
  //user input for name and phone num
  std:: cout<< "\nWhat is the name for your order? ";
  std:: getline(std:: cin, name);
  std:: cout<< "\nWhat is the phone number for your order? ";
  std:: cin >> phoneNum;
  while(std::cin.fail())
    {
      std::cout<<"\nError. Please enter a phone number: ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin>>phoneNum;
    }
  std::cin.clear();
  std:: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  //creation for new order when running
  Order newOrder(name, phoneNum);
  //do while loop for the user/customer to keep adding pizzas
  do
    {
      newOrder.addPizza(inputOrder());
      std:: cout<< "Would you like another pizza? y/n";
      std:: cin >> morePizza;
      morePizza = std::tolower(morePizza);
    }while(morePizza == 'y');
  newOrder.displayOrder();

  
}

//function to display pizza options and return a single pizza which is added to the vector
Pizza inputOrder()
  {
    int typeNum, sizeNum, toppings;
    std:: string pizzaType, size;
    std:: cout << "\nWhat type of pizza would you like? \n1. Hand tossed \n2. Deep dish \n3. Pan";
    std:: cin >> typeNum;
    while(std::cin.fail() || typeNum < 1 || typeNum > 3)
    {
      std::cout<<"\nPlease enter the number of your option \n1. Hand tossed \n2. Deep dish \n3. Pan ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin>>typeNum;
    }
    std:: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch(typeNum)
      {
        case 1:
          pizzaType = "Hand Tossed";
        break;
        case 2:
          pizzaType = "Deep dish";
        break;
        case 3:
          pizzaType = "Pan";
        break;
      }
    std:: cout << "\nWhat size " + pizzaType + " pizza would you like? \n1. Small - $10 \n2. Medium - $14\n3. Large - $17 ";
    std:: cin >> sizeNum;
    while(std::cin.fail() || sizeNum < 1 || sizeNum > 3)
    {
      std::cout<<"\nPlease enter the number of your option \n1. Small - $10 \n2. Medium - $14\n3. Large - $17 ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin>>sizeNum;
    }
    std:: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch(sizeNum)
      {
        case 1:
          size = "Small";
        break;
        case 2:
          size = "Medium";
        break;
        case 3:
          size = "Large";
        break;
        //maybe default validate
      }
    std:: cout << "\nHow many toppings would you like? ($2 each): ";
    std:: cin >> toppings;
    while(std::cin.fail() || toppings < 0)
    {
      std::cout<<"\nPlease enter the number of toppings you would like: ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin>>toppings;
    }
    std:: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    Pizza onePizza(pizzaType, size, toppings);
    
    return onePizza;
  }