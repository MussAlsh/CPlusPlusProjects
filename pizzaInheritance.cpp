#include <iostream>
#include <vector>
#include <iomanip>
#include <string>


class Pizza
{
  private:
    std:: string size;
    std:: string type;
    std:: vector<std::string> toppings;
    double price, totalPrice, toppingPrice;

    

    void calculatePizza()
    {
      //std::cout<<size;
      if(size == "small")
        price += 10.00;
      else if(size == "medium")
        price += 14.00;
      else if(size == "large")
        price += 17.00;
      //std::cout<<price;
      toppingPrice = toppings.size() * 2;

      totalPrice = price + toppingPrice;
      std::cout<<toppingPrice;
    }

    public:
      Pizza(std:: string size, std:: string type, std:: vector<std::string> toppings)
      {
        this->size = size;
        this->type = type;
        this->toppings = toppings;
        calculatePizza();
      }
      //overload << to print pizza info
      friend std:: ostream& operator<<(std:: ostream& output, Pizza onePizza)
      {
        output << "You ordered a ";
        output << onePizza.size << " ";
        output << onePizza.type << " pizza with ";
        for(std:: string toppings: onePizza.toppings)
          output << toppings << " ";
        output << "\n\n\tPizza Price: $ " << onePizza.totalPrice;
    
        return output;
      }
      //gets for each variable
      std:: string getSize(){return size;}
      std:: string getType(){return type;}
      std::vector<std::string> getToppings(){return toppings;}
      double getPrice(){return totalPrice;}
};//end pizza class

class DeliveredPizza: public Pizza
{
  private:
    double deliveryFee, totalPrice;
    std:: string address;

  public:

    DeliveredPizza(std::string size, std:: string type, std:: vector<std::string> toppings, std:: string address)
  :Pizza(size, type, toppings)
    {
      //delivery fee based on the price of the order
      if(getPrice()>20)
      {
        deliveryFee = 3.50;
      }
      else if(getPrice()<20)
      {
        deliveryFee = 5;
      }
      totalPrice = getPrice() + deliveryFee;
      this->address = address;
    }
    //overload output
    friend std:: ostream& operator<<(std:: ostream& output, DeliveredPizza onePizza)
    {
      output << "You ordered a ";
      output << onePizza.getSize() << " ";
      output << onePizza.getType() << " pizza with ";
      for(std:: string toppings: onePizza.getToppings())
        output << toppings << " ";
      output << "\nDelivery Fee: "<< onePizza.deliveryFee;
      output << "\nTotal Price: " << onePizza.totalPrice;
      output << "\n\nDelivered to: " << onePizza.address;
    
      return output;
    }
};//end delivered pizza class


void takeOrder(std::string &size,std::string &type, std::vector<std::string> &toppings);


int main() 
{
  std:: cout<<std::setprecision(2)<<std::fixed;
  std:: vector<std::string> toppings; //= {"Pepperoni", "Mushrooms", "Onions", "Green Pepper", "Tomatoes", "Jalapenos"};
  std:: string size, type, address;
  int orderType;
  takeOrder(size, type, toppings);
  std:: cout<<"\nWould you like 1 - pick up or 2 - delivery?";
  std:: cin>>orderType;
  while(std::cin.fail() || orderType < 1 || orderType > 2)
  {
    std::cout<<"Please enter a valid option  \n1 - pick up \n2 - delivery";
    std::cin.clear();
    std::cin.ignore();
    std::cin>>orderType;
  }
  std::cin.ignore();
  if(orderType == 1)
  {
    Pizza onePizza(size, type, toppings);
    std:: cout<<onePizza;
  }
  else if(orderType == 2)
  {
    std:: cout<< "\nPlease enter your address: \n";
    getline(std::cin, address);
    DeliveredPizza onePizza(size, type, toppings, address);
    std:: cout<<onePizza;
  }



  return 0;
}

void takeOrder(std::string &size,std::string &type, std::vector<std::string> &toppings)
{
  int toppingChoice, sizeChoice, typeChoice;
  std::cout << "\nWhat size pizza would you like to order?\n\t\t1 - small\n\t\t2 - medium\n\t\t3 - large\n\t---->";
  std:: cin>>sizeChoice;
  while(std::cin.fail() || sizeChoice < 1 || sizeChoice > 3)
  {
    std::cout << "\nPlease select an available option\n\t\t1 - small\n\t\t2 - medium\n\t\t3 - large\n\t---->";
    std::cin.clear();
    std::cin.ignore();
    std:: cin>>sizeChoice;
  }
  switch(sizeChoice)
  {
    case 1:
      size = "small";
      break;
    case 2:
      size = "medium";
      break;
    case 3:
      size = "large";
      break;
  }
  std:: cout<< "What type of crust would you like to order?\n\t\t1 - classic\n\t\t2 - deep dish\n\t\t3 - thin crust\n\t---->";
  std:: cin>> typeChoice;
  std::cin.ignore();
  //validate
  while(std::cin.fail() || typeChoice < 1 || typeChoice > 3)
  {
    std:: cout<< "\nPlease select an available option.\n\t\t1 - classic\n\t\t2 - deep dish\n\t\t3 - thin crust\n\t---->";
    std::cin.clear();
    std::cin.ignore();
    std:: cin>> typeChoice;
  }
  switch(typeChoice)
  {
    case 1:
      type = "classic";
      break;
    case 2:
      type = "deep dish";
      break;
    case 3:
      type = "thin crust";
      break;
    default:
      std::cout<<"Please select an available option";
      break;
  }
  do
  {
  std:: cout<< "Choose from the following toppings or 0 to quit";
  std:: cout<< "\n\t\t1 - Pepperoni\n\t\t2 - Mushrooms\n\t\t3 - Onions\n\t\t4 - Green Pepper\n\t\t5 - Tomatoes\n\t\t6 - Jalapenos";
  std:: cin>>toppingChoice;
    while(std::cin.fail() || toppingChoice < 0 || toppingChoice > 6)
      {
        std:: cout<< "\nError! \nChoose a number from the following toppings or 0 to quit";
  std:: cout<< "\n\t\t1 - Pepperoni\n\t\t2 - Mushrooms\n\t\t3 - Onions\n\t\t4 - Green Pepper\n\t\t5 - Tomatoes\n\t\t6 - Jalapenos";
        std::cin.clear();
        std::cin.ignore();
  std:: cin>>toppingChoice;
      }
  switch(toppingChoice)
    {
      case 1:
        toppings.push_back("Pepperoni");
        break;
      case 2:
        toppings.push_back("Mushrooms");
        break;
      case 3:
        toppings.push_back("Onions");
        break;
      case 4:
        toppings.push_back("Green pepper");
        break;
      case 5:
        toppings.push_back("Tomatoes");
        break;
      case 6:
        toppings.push_back("Jalapenos");
        break;
      default:
        std::cout<<"\nPlease select an available option";
        break;
    }
  }while(toppingChoice != 0);
}
