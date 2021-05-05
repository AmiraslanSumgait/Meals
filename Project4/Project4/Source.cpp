#include<iostream>
#include<windows.h>
using namespace std;
class Ingredient {
protected:
	string name;
	double fats;
	double protein;
	double carbohydrates;
	int kcal;
public:
	Ingredient():name(),fats(),protein(),carbohydrates(),kcal()
	{

	}
	Ingredient(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal)
	{
		SetName(name);
		SetFats(fats);
		SetCarbohydrate(carbohydrates);
		SetProtein(protein);
		SetCalori(kcal);

	}
	string& GetName() {
		return name;
	}
	double& GetFats() {
		return fats;
	}
	double& GetProtein() {
		return protein;
	}
	double& GetCarbohydrate() {
		return carbohydrates;
	}
	int& GetCalori() {
		return kcal;
	}
	void SetName(const string& name) {
		this->name = name;
	}
	void SetFats(const double& fats) {
		this->fats = fats;
	}
	void SetProtein(const double& protein) {
		this->protein = protein;
	}
	void SetCarbohydrate(const double& carbohydrates) {
		this->carbohydrates = carbohydrates;
	}
	void SetCalori(const int& kcal) {
		this->kcal = kcal;
	}
	virtual void show() {
		
		cout << "Name: " << name << endl;
		cout << "Fats: " << fats << endl;
		cout << "Protein: " << protein << endl;
		cout << "Carbohydrate: " << carbohydrates << endl;
		cout << "Calori: " << kcal << endl;
		cout << endl;
		
	}


};
class Mushrooms :public Ingredient {
	string country;
public:
	Mushrooms(const string name,const string country, const double& fat, const double& protein, const double& carbohydrates, const int& kcal) :Ingredient(name, fat, protein, carbohydrates, kcal) {
		this->country = country;
	}
	void show() {

		cout << "Name: " << name << endl;
		cout << "Country: " << country << endl;
		cout << "Fats: " << fats << endl;
		cout << "Protein: " << protein << endl;
		cout << "Carbohydrate: " << carbohydrates << endl;
		cout << "Calori: " << kcal << endl;
		cout << endl;

	}
};
class Meat :public Ingredient {
	string typesOf;
public:
	Meat(const string name,const string typesOf ,const double& fat, const double& protein, const double& carbohydrates, const int& kcal) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{
		this->typesOf = typesOf;
	}
	void show() {
		cout << "Name: " << name << endl;
		cout << "Types of: " << typesOf << endl;
		cout << "Fats: " << fats << endl;
		cout << "Protein: " << protein << endl;
		cout << "Carbohydrate: " << carbohydrates << endl;
		cout << "Calori: " << kcal << endl;
		cout << endl;
	}
	
};
class Spices :public Ingredient {
	string typesOf;
public:
	Spices(const string name, const string typesOf, const double& fat, const double& protein, const double& carbohydrates, const int& kcal) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{
		this->typesOf = typesOf;
	}
	void show() {
		cout << "Name: " << name << endl;
		cout << "Types of: " << typesOf << endl;
		cout << "Fats: " << fats << endl;
		cout << "Protein: " << protein << endl;
		cout << "Carbohydrate: " << carbohydrates << endl;
		cout << "Calori: " << kcal << endl;
		cout << endl;
	}

};
class Cheese :public Ingredient {
	string country;
public:
	Cheese(const string name,const string country,const double& fat, const double& protein, const double& carbohydrates, const int& kcal) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{
		this->country = country;
	}
	void show() {
		cout << "Name: " << name << endl;
		cout << "Country: " << country << endl;
		cout << "Fats: " << fats << endl;
		cout << "Protein: " << protein << endl;
		cout << "Carbohydrate: " << carbohydrates << endl;
		cout << "Calori: " << kcal << endl;
		cout << endl;
	}
};
class Tomatoes :public Ingredient {
	string country;
public:
	Tomatoes(const string name,const string country, const double& fat, const double& protein, const double& carbohydrates, const int& kcal) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{
		this->country = country;
	}
	void show() {
		cout << "Name: " << name << endl;
		cout << "Country: " << country << endl;
		cout << "Fats: " << fats << endl;
		cout << "Protein: " << protein << endl;
		cout << "Carbohydrate: " << carbohydrates << endl;
		cout << "Calori: " << kcal << endl;
		cout << endl;
	}

};
struct RecipeItem {
	Ingredient* ingredient;
	int amount;
	RecipeItem():ingredient(),amount()
	{

	}
	RecipeItem(Ingredient* ingredient, int amount)
	{
		this->ingredient = ingredient;
		this->amount = amount;
	}
	
};
class Dish {
protected:
	RecipeItem** ingredients;
	int count;
	string name;
	
public:
	Dish() :ingredients(), count(), name()
	{

	}
	const int& GetCount()const {
		return count;
	}
	void SetCount(const int&count) {
		this->count = count;
	}
	Dish(RecipeItem** ingredients, int count, const string& name)
	{
		this->ingredients = ingredients;
		this->count = count;
		this->name = name;
	}

	
	void addIngredient(Ingredient* ingredient, int amount) {
		auto newIingredients = new RecipeItem * [count + 1];

		for (size_t i = 0; i < count; i++)
		{
			newIingredients[i] = ingredients[i];
		}
		auto newRecipeItem = new RecipeItem(ingredient, amount);
		newIingredients[count] = newRecipeItem;
		delete[] ingredients;
		ingredients = newIingredients;
		newIingredients =nullptr;
		count += 1;
	}
	virtual void taste() {
		cout << "I do not know what is this ? " << endl;
	}

	virtual void printRecipe() {
		for (size_t i = 0; i < count; i++)
		{
			
			ingredients[i]->ingredient->show();
			cout << endl;
		}
	}
	


};
class Pizza :public Dish {
public:
	void taste() override {
		cout << "\n\nCustomer: Pizza tastes fantastic.Thank you for your order" << endl;
	}
	void SetCount(const int&count) {
		this->count = count;
	}
	void printRecipe()override   {
		cout << "-------Pizza Info-------" << endl;
		for (size_t i = 0; i < count; i++)
		{
			ingredients[i]->ingredient->show();
		}
	}
};
class Kabab :public Dish {
public:
	void taste()override {
		cout << "\n\nCustomer: Kabab tastes flavorsome .Thank you for your order" << endl;
	}
	void printRecipe()override {
		cout << "-------Kabab Info-------" << endl;
		for (size_t i = 0; i < count; i++)
		{
			ingredients[i]->ingredient->show();
		}
	}
};
class Dolma :public Dish {
public:
	void printRecipe()override {
		cout << "-------Dolma Info-------" << endl;
		for (size_t i = 0; i < count; i++)
		{
			ingredients[i]->ingredient->show();
		}
	}
	void taste() override {
		cout << "\n\nCustomer: Dolma tastes amazing.Thank you for your order" << endl;
	}

};
class CookingDevice {
protected:
	Dish* dish;
	bool isCooked;
	int second;
	virtual void cook() {

	}
};
class Oven :public CookingDevice {
public:

	Oven(Dish*dish,bool isCooked,int second)
	{
		this->dish = dish;
		this->isCooked = isCooked;
		this->second = second;
	}
	void cook() {
		while (second >= 0) {
			system("cls");
			cout << "Oven is working......." << endl;
			cout << "It will be ready:" << second << "second" << endl;
			Sleep(1000);
			second--;
			
		}
		cout << "=======Hope you enjoy what we've made for you=======" << endl;
		Sleep(2000);
		
	}
};

class Pot :public CookingDevice {

public:
	Pot(Dish* dish, bool isCooked, int second)
	{
		this->dish = dish;
		this->isCooked = isCooked;
		this->second = second;
	}
	void cook() {
		while (second >= 0) {
			system("cls");
			cout << "Pot is working......." << endl;
			cout << "It will be ready:" << second << "second" << endl;
			Sleep(1000);
			second--;

		}
		cout << "=======Hope you enjoy what we've made for you=======" << endl;
		Sleep(3000);

	}
};

class Brazier :public CookingDevice {

public:
	Brazier(Dish* dish, bool isCooked, int second)
	{
		this->dish = dish;
		this->isCooked = isCooked;
		this->second = second;
	}
	void cook() {
		while (second >= 0) {
			system("cls");
			cout << "Brazier is working........" << endl;
			cout << "It will be ready:" << second << "second" << endl;
			Sleep(1000);
			second--;

		}
		cout << "=======Hope you enjoy what we've made for you=======" << endl;
		Sleep(2000);

	}
	
};

class Menu {
	Menu()
	{

	}
public:
	static void orderMenu();
};

void Menu::orderMenu() {
	int counter = 0;
	Meat* meat = new Meat("Venison","Pork", 16, 23, 10, 100);
	Spices* spices = new Spices("Allspice","Black pepper", 4.3, 1, 20, 35);
	Cheese* cheese = new Cheese("Taleggio","Italia", 6.8, 5.9, 0.3, 86);
	Tomatoes* tomatoes = new Tomatoes("Tigeralla","Turkey", 0.2, 0.9, 3.9, 18);
	Mushrooms* mushrooms = new Mushrooms("Buttom","Germany", 0, 3, 3, 21);
	cout << "Good evening,which dish would you like to order?" << endl;
	cout << "[1]Pizza\n[2]Kabab\n[3]Dolma" << endl;
	int x; cin >> x;
	if (x == 1) {
		Pizza pizza;
		cout << "Select ingredient:" << endl;
		cout << "[1]Meat\n[2]Spices\n[3]Cheese\n[4]Tomatoes\n[5]Mushrooms" << endl;
		int y; cin >> y;
		if (y == 1) {
			pizza.addIngredient(meat, 2000);
		}
		else if (y == 2) pizza.addIngredient(spices, 300);
		else if (y == 3) pizza.addIngredient(cheese, 600);
		else if (y == 4) pizza.addIngredient(tomatoes, 400);
		else if (y == 5) pizza.addIngredient(mushrooms, 100);
		while (true) {
			cout << "Would you anything else?\n1)Yes\n2)No" << endl;
			int z;
			cin >> z;
			if (z == 2) break;
			else {
				cout << "Select another ingredient:" << endl;
				cout << "[1]Meat\n[2]Spices\n[3]Cheese\n[4]Tomatoes\n[5]Mushrooms" << endl;
				int a;
				cin >> a;
				if (a == 1) {
					pizza.addIngredient(meat, 2000);
				}
				if (a == 2) {
					pizza.addIngredient(spices, 300);
				}
				else if (a == 3) {
					pizza.addIngredient(cheese, 400);
				}
				else if (a == 4) {
					pizza.addIngredient(tomatoes, 1000);
				}
				else if (a == 5) {
					pizza.addIngredient(mushrooms, 100);
				}
			}

			
		}
		Oven oven(&pizza,true,10);
		oven.cook();
		system("cls");
		pizza.printRecipe();
		pizza.taste();
	}
	if (x == 2) {
		Kabab kabab;
		cout << "Select ingredient:" << endl;
		cout << "[1]Meat\n[2]Spices\n[3]Cheese\n[4]Tomatoes\n[5]Mushrooms" << endl;
		int y; cin >> y;
		if (y == 1) {
			kabab.addIngredient(meat, 2000);
		}
		else if (y == 2) kabab.addIngredient(spices, 300);
		else if (y == 3) kabab.addIngredient(cheese, 600);
		else if (y == 4) kabab.addIngredient(tomatoes, 400);
		else if (y == 5) kabab.addIngredient(mushrooms, 100);
		while (true) {
			cout << "Would you anything else?\n1)Yes\n2)No" << endl;
			int z;
			cin >> z;
			if (z == 2) break;
			else {
				cout << "Select another ingredient:" << endl;
				cout << "[1]Meat\n[2]Spices\n[3]Cheese\n[4]Tomatoes\n[5]Mushrooms" << endl;
				int a;
				cin >> a;
				if (a == 1) {
					kabab.addIngredient(meat, 2000);
				}
				if (a == 2) {
					kabab.addIngredient(spices, 300);
				}
				else if (a == 3) {
					kabab.addIngredient(cheese, 400);
				}
				else if (a == 4) {
					kabab.addIngredient(tomatoes, 1000);
				}
				else if (a == 5) {
					kabab.addIngredient(mushrooms, 100);
				}
			}


		}
		Brazier brazier(&kabab, true, 8);
		brazier.cook();
		system("cls");
		kabab.printRecipe();
		kabab.taste();
	}
	if (x == 3) {
		Dolma dolma;
		cout << "Select ingredient:" << endl;
		cout << "[1]Meat\n[2]Spices\n[3]Cheese\n[4]Tomatoes\n[5]Mushrooms" << endl;
		int y; cin >> y;
		if (y == 1) {
			dolma.addIngredient(meat, 2000);
		}
		else if (y == 2) dolma.addIngredient(spices, 300);
		else if (y == 3) dolma.addIngredient(cheese, 600);
		else if (y == 4) dolma.addIngredient(tomatoes, 400);
		else if (y == 5) dolma.addIngredient(mushrooms, 100);
		while (true) {
			cout << "Would you anything else?\n1)Yes\n2)No" << endl;
			int z;
			cin >> z;
			if (z == 2) break;
			else {
				cout << "Select another ingredient:" << endl;
				cout << "[1]Meat\n[2]Spices\n[3]Cheese\n[4]Tomatoes\n[5]Mushrooms" << endl;
				int a;
				cin >> a;
				if (a == 1) {
					dolma.addIngredient(meat, 2000);
				}
				if (a == 2) {
					dolma.addIngredient(spices, 300);
				}
				else if (a == 3) {
					dolma.addIngredient(cheese, 400);
				}
				else if (a == 4) {
					dolma.addIngredient(tomatoes, 1000);
				}
				else if (a == 5) {
					dolma.addIngredient(mushrooms, 100);
				}
			}


		}
		Pot pot(&dolma, true, 7);
		pot.cook();
		system("cls");
		dolma.printRecipe();
		dolma.taste();
	}
	
}
void main() {
	Menu::orderMenu();
}
