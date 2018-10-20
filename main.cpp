#include<iostream>
#include<string>

using namespace std;
 
// Customer class
class Customer
{
public:
  Customer (const string& name) : name_(name){}
  const string& Name(void)
  {
    return name_;
  }
private:
  Customer(); //not allowed
  string name_;
};
 
// The 'Subsystem ClassA' class
class Bank
{
public:
  bool HasSufficientSavings(Customer c, int amount)
  {
    cout << "Check bank for " <<c.Name()<<endl;
    return true;
  }
};
 
// The 'Subsystem ClassB' class
class Credit
{
public:
  bool HasGoodCredit(Customer c, int amount)
  {
    cout << "Check credit for " <<c.Name()<<endl;
    return true;
  }
};
 
// The 'Subsystem ClassC' class
class Loan
{
public:
  bool HasGoodCredit(Customer c, int amount)
  {
    cout << "Check loans for " <<c.Name()<<endl;
    return true;
  }
};
 
// The 'Facade' class
class Mortgage
{
public:
  bool IsEligible(Customer cust, int amount)
  {
    cout << cust.Name() << " applies for a loan for $" << amount <<endl;
    bool eligible = true;
 
    eligible = bank_.HasSufficientSavings(cust, amount);
 
    if(eligible)
      eligible = loan_.HasGoodCredit(cust, amount);
 
    if(eligible)
      eligible = credit_.HasGoodCredit(cust, amount);
 
    return eligible;
  }
 
private:
  Bank bank_;
  Loan loan_;
  Credit credit_;
};
 
//The Main method
int main()
{
  Mortgage mortgage;
  Customer customer("Brad Pitt");
 
  bool eligible = mortgage.IsEligible(customer, 1500000);
 
  cout << "\n" << customer.Name() << " has been " << (eligible ? "Approved" : "Rejected") << endl;
 
  return 0;
}
