#include<iostream>
using namespace std;
class Cake
{
private:
	char* CakeType;
	int CakeSize;
	int NumOfCholate;
	bool DecorationFlower;
public:
	Cake()
	{
		CakeType = nullptr;
		CakeSize = 0;
		NumOfCholate = 0;
		DecorationFlower = 0;
	}
	Cake(char* CakeT,int Cakesiz,int NumCholate,bool Dflower)
	{
		int size = (strlen(CakeT)+1);
		CakeType = new char[size];
		strcpy_s(CakeType, size, CakeT);
		CakeSize = Cakesiz;
		NumOfCholate = NumCholate;
		DecorationFlower = Dflower;


	}
	void TextalDescription()
	{
		if (DecorationFlower)
		{
			cout << "This cake is " << CakeSize << " tier,";
			cout << CakeType << " with flower decor and has " << NumOfCholate << " pieces of chocolates\n";
		}
		else
		{
			cout << "This cake is " << CakeSize << " tier,";
			cout << CakeType <<" with " << NumOfCholate << " pieces of chocolates\n";

		}
	}
	double calculatePrice()
	{
		double price;
		if (CakeSize == 1)
		{
			 price= 15  + (0.5 * NumOfCholate);
			 if (DecorationFlower)
			 {
				 price = price + 7;
			 }
		}
		else if (CakeSize == 2)
		{
			price = 25  + (1.0 * NumOfCholate);
			if (DecorationFlower)
			{
				price = price + 13;
			}
		}
		else if (CakeSize == 3)
		{
			price= 35 + (1.5 * NumOfCholate);
			if (DecorationFlower)
			{
				price = price + 13;

			}
		}
		return price;
	}
	void setCakeType(char* CakeT)
	{
		int size = (strlen(CakeT) + 1);
		CakeType = new char[size];
		strcpy_s(CakeType, size, CakeT);

	}
	char* getCakeType()
	{
		char* CakeT;
		int size = strlen(CakeType) + 1;
		CakeT = new char[size];
		strcpy_s(CakeT, size, CakeType);
		return CakeType;
	}
	void setCakeSize(int Cakesiz)
	{
		CakeSize = Cakesiz;

	}
	int getCakesize()
	{
		return CakeSize;

	}
	void setNumOfCholate (int NumCholate)
	{
		NumOfCholate = NumCholate;

	}
	int getNumOfCholate()
	{
		return NumOfCholate;

	}
	void SetDecorationFlower(bool DFlower)
	{
		DecorationFlower = DFlower;

	}
	~Cake()
	{
		delete[] CakeType;
		CakeType = nullptr;
	}

	
};
int main()
{
	char caketype[50] = { 'c','h','o','c','o','l','a','t','e',' ','c','a','k','e' };
	Cake obj(caketype, 3, 4, true);
	obj.TextalDescription();
	cout<<obj.calculatePrice();
}