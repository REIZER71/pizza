#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Pizza 
{
protected:
	string name;
	int size[4]{ 25,30,35,40 };
	unsigned int price;
	unsigned int cheeseAm;
	unsigned int saltAm;
	const unsigned int  cheesePrice= 10;
	const unsigned int saltPrice = 5;//геттер
	unsigned int PizzaPriceMod;
public:
	void setName(string some_name) { name = some_name; }
	void setPrice(unsigned int some_price) { price = some_price; }
	void setCheeseAm(unsigned int some_cheeseAm) { cheeseAm = some_cheeseAm; }
	void setSaltAm(unsigned int some_saltAm) { saltAm = some_saltAm; }
	int setMod(unsigned int MyMod) { PizzaPriceMod = MyMod; return (PizzaPriceMod); }
	unsigned int getSalt() const { return (saltPrice); }
	unsigned int getCheese() const { return (cheesePrice); }
	unsigned int getSize(int i) const { return (size[i]); }
	unsigned int getPrice() const { return (PizzaPriceMod); }
	virtual void info()
	{
		cout <<size[0]<< name << "sample text with "
		<< cheeseAm << "cheese slices and " 
		<< saltAm << "salt" << endl;
	}
	int mathMagic(int i, int cheeseAm, int saltAm, int mod)
	{
		int chz;
		int saltpr;
		int PizzaSizeMod;
		int priceM;
		chz = cheeseAm * getCheese();
		saltpr = saltAm * getSalt();
		PizzaSizeMod = getSize(i) * 13;
		priceM = mod;
		price = priceM + PizzaSizeMod + chz + saltpr;
		return (price);
	}
};
class Pepperoni:virtual public Pizza
{public:
	int mod;
	int price;
	int sized;
	Pepperoni(int i,  int cheese, int salt)
	{
		setName("Pepperoni");
		mod = setMod(50);
		saltAm = salt;
		cheeseAm = cheese;
		sized = size[i];
		price = mathMagic(i, cheese, salt, mod);
		
	};
	unsigned int getPr() const { return (price); }
	int getS() const { return (sized); }
	int getsalt() const { return (saltAm); }


	void info() override
	{
		cout <<"Tasty "<<getS()<<" cm " << name << endl
			<< " with pepperoni sausage and ketchup also" << endl << "have "
			<< cheeseAm << "  slices (non canon if it more than 0) and "
			<< saltAm << " salt" << endl<<"Price: "<< getPr()<<" V-bucks" << endl;
	}
};
class CheesePizza:virtual public Pizza
{
public:
	int mod;
	int price;
	int sized;
	CheesePizza(int i, int cheese, int salt)
	{
		setName("4 types of cheese");
		mod = setMod(35);
		saltAm = salt;
		cheeseAm = cheese;
		sized = size[i];
		price = mathMagic(i, cheese, salt, mod);

	};
	unsigned int getPr() const { return (price); }
	int getS() const { return (sized); }
	int getsalt() const { return (saltAm); }


	void info() override
	{
		cout << "A good " << getS() << " cm " << name <<endl <<
			" with parmezan, robiola, gruyere and mozarella also" << endl << "have "
			<< cheeseAm << "  slices (More cheese!) and " 
			<< saltAm << " salt" << endl << "Price: " << getPr() << " V-bucks" << endl;
	}

};
class PineapplePizza:virtual public Pizza
{
public:
	int mod;
	int price;
	int sized;
	PineapplePizza(int i, int cheese, int salt)
	{
		setName("pineapple pizza");
		mod = setMod(20);
		saltAm = salt;
		cheeseAm = cheese;
		sized = size[i];
		price = mathMagic(i, cheese, salt, mod);

	};
	unsigned int getPr() const { return (price); }
	int getS() const { return (sized); }
	int getsalt() const { return (saltAm); }


	void info() override
	{
		cout << "Exotic " << getS() << " cm " << name<<endl
			<< " with pineapples (it was a mistake) also " << endl<< "have "
			<< cheeseAm << "  slices (you can't do it worse) and " 
			<< saltAm << " salt" << endl << "Price: " << getPr() << " V-bucks" << endl;
	}
};
class Margarita:virtual public Pizza
{
public:
	int mod;
	int price;
	int sized;
	Margarita(int i, int cheese, int salt)
	{
		setName("Margarita");
		mod = setMod(15);
		saltAm = salt;
		cheeseAm = cheese;
		sized = size[i];
		price = mathMagic(i, cheese, salt, mod);

	};
	unsigned int getPr() const { return (price); }
	int getS() const { return (sized); }
	int getsalt() const { return (saltAm); }


	void info() override
	{
		cout << "Classic" << getS() << " cm " << name << endl
			<< " with cheese, tomatoes and basilic also" << endl << "have "
			<< cheeseAm << "  slices (now it's looks like 4 types of cheese) and "
			<< saltAm << " salt" << endl << "Price: " << getPr() << " V-bucks" << endl;
	}
};

void console() 
{	
	vector<Pizza *> pizza;
	int ammount = 0;
	static int debt;
	int number;
	int cheese;
	int salt;
	int i;
	bool ending = 1;
	while (ending != 0) {
		cout << "Please choose from list:" << endl
			<< "1) Pepperoni (press 1)" << endl
			<< "2) 4 types of cheese (press 2)" << endl
			<< "3) pineapple pizza (press 3)" << endl
			<< "4) Margarita (press 4)" << endl;
		cin >> number;
		cout << "do you want extra cheese in your pizza?" << endl
			<< "(if you want it, please write how much cheese do you want" << endl
			<< "else write 0 )" << endl;
		cin >> cheese;
		cout << "do you want extra salt in your pizza?" << endl
			<< "(if you want it, please write how much salt do you want" << endl
			<< "else write 0 )" << endl;
		cin >> salt;
		cout << "please choose pizza size" << endl
			<< "25 (press 0)" << endl
			<< "30 (press 1)" << endl
			<< "35 (press 2)" << endl
			<< "40 (press 3)" << endl;
		cin >> i;
		if (i <= 0 or i > 3)
			cout << "something went wrong, try again" << endl;
		else {
			if (number == 1)
			{
				Pepperoni piza(i, cheese, salt);
				pizza.push_back(new Pepperoni(i, cheese, salt));
				debt += piza.getPr();
			}
			else if (number == 2)
			{
				CheesePizza piza(i, cheese, salt);
				pizza.push_back(new CheesePizza(i, cheese, salt));
				debt += piza.getPr();
			}
			else if (number == 3)
			{
				PineapplePizza piza(i, cheese, salt);
				pizza.push_back(new PineapplePizza(i, cheese, salt));
				debt += piza.getPr();
			}
			else if (number == 4)
			{
				Margarita piza(i, cheese, salt);
				pizza.push_back(new Margarita(i, cheese, salt));
				debt += piza.getPr();
			}
			pizza[ammount]->info();//важные строки
			cout << endl << "Final price: " << debt << " V-bucks" << endl;
			ammount++;
		}
			cout << "add something?" << endl
				<< "YES (press 1)    NO (press 0)" << endl;
			cin >> ending;
	}
	for (i = 0; i < ammount; i++) 
	{
		cout << i + 1 << ')';
		pizza[i]->info();
		cout<<endl;
	}
			
		cout << endl << "Final price: " << debt << " V-bucks" << endl;
}
	

int main()
{
	console();
}