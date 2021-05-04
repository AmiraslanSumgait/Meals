#include<iostream>
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
	 void show() {
		cout << "Name: " << name << endl;
		cout << "Fats: " << fats << endl;
		cout << "Protein: " << protein << endl;
		cout << "Carbohydrate: " << carbohydrates << endl;
		cout << "Calori: " << kcal << endl;
	}
	//virtual ~Ingredient() = 0;

};
class Mushrooms :public Ingredient {
public:
	Mushrooms(const string name, const double& fat, const double& protein, const double& carbohydrates, const int& kcal) :Ingredient(name, fat, protein, carbohydrates, kcal) {

	}
};
class Meat :public Ingredient {
public:
	Meat(const string name, const double& fat, const double& protein, const double& carbohydrates, const int& kcal) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{

	}

};
class Spices :public Ingredient {
public:
	Spices(const string name, const double& fat, const double& protein, const double& carbohydrates, const int& kcal) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{

	}
	

};
class Cheese :public Ingredient {
public:
	Cheese(const string name, const double& fat, const double& protein, const double& carbohydrates, const int& kcal) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{

	}

};
class Tomatoes :public Ingredient {
public:
	Tomatoes(const string name, const double& fat, const double& protein, const double& carbohydrates, const int& kcal) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{

	}

};
struct RecipeItem {
	Ingredient* ingredient;
	int amount;
	RecipeItem(Ingredient* ingredient, int amount)
	{

	}
	
};
class Dish {
	RecipeItem** ingredients;
	int count;
	string name;
	Dish(RecipeItem**ingredients,int count,const string&name)
	{
		this->ingredients = ingredients;
	}
public:
	Dish() :ingredients(), count(), name()
	{

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

	virtual void printRecipe()const {
		for (size_t i = 0; i < count; i++)
		{
			ingredients[i]->ingredient->show();
		}
	}
	//virtual ~Dish() = 0;


};
class Pizza :public Dish {
public:
	void taste() override {
		cout << "It's a delicious" << endl;
	}
};
class Kabab :public Dish {
public:
	void taste()override {
		cout << "The taste of its meat is very pleasant" << endl;
	}
};
class Dolma :public Dish {
public:

	void taste() override {
		cout << "The meat of dolma tastes very good" << endl;
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

	Oven()
	{
		//dish = new Pizza("Bomba Pizza");
	}
};

class Pot :public CookingDevice {

public:
	Pot()
	{
		//dish = new Dolma("Dolma");
	}

};

class Brazier :public CookingDevice {

public:
	Brazier()
	{
		//dish = new Kabab("Babat Kabab");
	}
	
};
void main() {
	Meat* meat = new Meat("Meat", 16, 23, 10, 100);
	Dish dish;
	dish.addIngredient(meat, 200);
	dish.printRecipe();
	
}
