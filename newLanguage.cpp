#include <iostream>
#include <string>


//start with integer class that is able to add nums
//Integer x, y
//overload = operator to accept nums
//function that takes in a string that prints question ?(what u need)
//print function that takes in a value and prints it
//print(5.3+4.3) should work, overload or template
//namespace, class, CPU class/object inside of namespace
namespace muss
{
  class Integer
  {
    private:
      int x;
    public:
      Integer operator+(Integer adding) //add Int
      {
        adding.x = this->x + adding.x;
        return adding;
      }
      Integer operator-(Integer subtracting) //subtract Int
      {
        subtracting.x = this->x + subtracting.x;
        return subtracting;
      }
      Integer operator*(Integer multiply)// times Int
      {
        multiply.x = this->x * multiply.x;
        return multiply;
      }
      Integer operator/(Integer divide) // divide int
      {
        divide.x = this->x * divide.x;
        return divide;
      }
      bool operator>(Integer greater)
      {
        if (this->x > greater.x)
          return true;
        else
          return false;
      }
      bool operator<(Integer less)
      {
        if (this->x < less.x)
          return true;
        else
          return false;
      }
      bool operator==(Integer is)
      {
        if (this->x == is.x)
          return true;
        else
          return false;
      }
      bool operator!=(Integer isnot)
      {
        if (this->x != isnot.x)
          return true;
        else
          return false;
      }
      void operator=(int x)
      {
        this->x = x;
      }

      friend std:: ostream& operator<<(std:: ostream& output, Integer &num)
      {
        output << num.x;
        return output;
      }
  };//end integer class
//not hcanging inside use template
//use inheritence or virtual when slightly different inside
//template for input only changes the variable not string
  class Words
  {

    private:
    std:: string x;

    public:
      void operator=(std:: string x)
      {
        this->x = x;
      }
      bool operator==(Words is)
      {
        if (this->x == is.x)
          return true;
        else
          return false;
      }
      bool operator!=(Words isnot)
      {
        if (this->x != isnot.x)
          return true;
        else
          return false;
      }

      friend std:: ostream& operator<<(std:: ostream& output, Words &word)
      {
        output << word.x;
        return output;
      }

      friend std:: istream& operator>>(std::istream& input, Words &word)
      {
        input >> word.x;
        return input;
      }
};//end string class

class Letter
  {

    private:
      char x;

    public:
      void operator=(char x)
      {
        this->x = x;
      }
      bool operator==(Letter is)
      {
        if (this->x == is.x)
          return true;
        else
          return false;
      }
      bool operator!=(Letter isnot)
      {
        if (this->x != isnot.x)
          return true;
        else
          return false;
      }

      friend std:: ostream& operator<<(std:: ostream& output, Letter &oneLetter)
      {
        output << oneLetter.x;
        return output;
      }

      friend std:: istream& operator>>(std::istream& input, Letter &oneLetter)
      {
        input >> oneLetter.x;
        return input;
      }
};//end string class

class Dooble
{
  private:
    double x;
  public:
    Dooble operator+(Dooble adding)
    {
      adding.x = this->x + adding.x;
      return adding;
    }
    Dooble operator-(Dooble subtracting)
    {
      subtracting.x = this->x + subtracting.x;
      return subtracting;
    }
    Dooble operator*(Dooble multiply)
    {
      multiply.x = this->x * multiply.x;
      return multiply;
    }
    Dooble operator/(Dooble divide)
    {
      divide.x = this->x * divide.x;
      return divide;
    }
    bool operator>(Dooble greater)
    {
      if (this->x > greater.x)
        return true;
      else
        return false;
    }
    bool operator<(Dooble less)
    {
      if (this->x < less.x)
        return true;
      else
        return false;
    }
    bool operator==(Dooble is)
    {
      if (this->x == is.x)
        return true;
      else
        return false;
    }
    bool operator!=(Dooble isnot)
    {
      if (this->x != isnot.x)
        return true;
      else
        return false;
    }
    void operator=(double x)
    {
      this->x = x;
    }
    
    friend std:: ostream& operator<<(std:: ostream& output, Dooble &doub)
    {
      output << doub.x;
      return output;
    }
    
    friend std:: istream& operator>>(std::istream& input, Dooble &doub)
    {
      input >> doub.x;
      return input;
    }
};//end double class

class Levitate
{
  private:
    double x;
  public:
    Levitate operator+(Levitate adding)
    {
      adding.x = this->x + adding.x;
      return adding;
    }
    Levitate operator-(Levitate subtracting)
    {
      subtracting.x = this->x + subtracting.x;
      return subtracting;
    }
    Levitate operator*(Levitate multiply)
    {
      multiply.x = this->x * multiply.x;
      return multiply;
    }
    Levitate operator/(Levitate divide)
    {
      divide.x = this->x * divide.x;
      return divide;
    }
    bool operator>(Levitate greater)
    {
      if (this->x > greater.x)
        return true;
      else
        return false;
    }
    bool operator<(Levitate less)
    {
      if (this->x < less.x)
        return true;
      else
        return false;
    }
    bool operator==(Levitate is)
    {
      if (this->x == is.x)
        return true;
      else
        return false;
    }
    bool operator!=(Levitate isnot)
    {
      if (this->x != isnot.x)
        return true;
      else
        return false;
    }
    void operator=(double x)
    {
      this->x = x;
    }
    
    friend std:: ostream& operator<<(std:: ostream& output, Levitate &ghost)
    {
      output << ghost.x;
      return output;
    }
    
    friend std:: istream& operator>>(std::istream& input, Levitate &ghost)
    {
      input >> ghost.x;
      return input;
    }
};//end double class

  template<typename showMe>
  void write(showMe whatever)
  {
    std::cout <<"\n"<< whatever;
  }
  template<typename gimme>
  gimme acceptNum(std::string question, gimme whatever)
  {
    std::cout<<"\n" <<question;
    std::cin>>whatever;
    return whatever;
  }


};//end my namespace





using namespace muss;

int main() 
{
  //testing int
  Integer int1, int2, int3, int4;
  int1 = 5;
  int2 = 10;
  write(int1);
  int3 = int1 + int2;
  write(int3);
  int4 = int3 * int2;
  write(int4);
  //testing strings
  Words yes;
  yes = "hello";
  yes = acceptNum("What is your favorite food?", yes);
  write(yes);
  //testing double
  Dooble dub1, dub2, dub3;
  dub1 = 2.5;
  dub2 = 5.8;
  dub1 = dub1 + dub2;
  write(dub1);
  dub3 = acceptNum("Enter a decimal number: ", dub3);
  write(dub3);
  //testing float
  Levitate flt1, flt2, flt3;
  bool check;
  flt1 = 4.34;
  flt2 = 5.14;
  flt1 = flt1 + flt2;
  write(flt1);
  flt3 = acceptNum("Enter a decimal number: ", flt3);
  write(flt3);
  check = flt3 > flt1;
  write(check);
  
 
  
  return 0;
}
