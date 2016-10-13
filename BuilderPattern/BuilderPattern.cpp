#if 0
#include <iostream>

using namespace std;

/* Interface that will be returned as the product from builder */
class HousePlan {
public:
	virtual void setWindow(string window) = 0;
	virtual void setDoor(string door) = 0;
	virtual void setBathroom(string bathroom) = 0;
	virtual void setKitchen(string kitchen) = 0;
	virtual void setFloor(string floor) = 0;
};

/* Concrete class for the HousePlan interface */
class House :public HousePlan {
private:
	string window, door, kitchen, bathroom, floor;

public:
	void setWindow(string window)
	{
		this->window = window;
	}

	void setDoor(string door)
	{
		this->door = door;
	}

	void setBathroom(string bathroom)
	{
		this->bathroom = bathroom;
	}

	void setKitchen(string kitchen)
	{
		this->kitchen = kitchen;
	}

	void setFloor(string floor)
	{
		this->floor = floor;
	}
};

/* Builder Class */
class HouseBuilder
{
public:
	/* Abstract functions to build parts */
	virtual void buildWindow() = 0;
	virtual void buildDoor() = 0;
	virtual void buildKitchen() = 0;
	virtual void buildBathroom() = 0;
	virtual void buildFloor() = 0;
	/* The product is returned by this function */
	virtual House* getHouse() = 0;
};

/* Concrete class for the builder interface */
class LavishHouse :public HouseBuilder {
private:
	House *house;
public:
	LavishHouse()
	{
		house = new House();
	}

	void buildWindow()
	{
		house->setWindow("French Window");
	}

	void buildDoor()
	{
		house->setDoor("Wooden Door");
	}

	void buildBathroom()
	{
		house->setBathroom("Modern Bathroom");
	}

	void buildKitchen()
	{
		house->setKitchen("Modular Kitchen");
	}

	void buildFloor()
	{
		house->setFloor("Wooden Floor");
	}

	House* getHouse()
	{
		return this->house;
	}
};

/* Another Concrete class for the builder interface */
class NormalHouse :public HouseBuilder {
private:
	House *house;
public:
	NormalHouse()
	{
		house = new House();
	}

	void buildWindow()
	{
		house->setWindow("Normal Window");
	}

	void buildDoor()
	{
		house->setDoor("Metal Door");
	}

	void buildBathroom()
	{
		house->setBathroom("Regular Bathroom");
	}

	void buildKitchen()
	{
		house->setKitchen("Regular Kitchen");
	}

	void buildFloor()
	{
		house->setFloor("Mosaic Floor");
	}

	House* getHouse()
	{
		return this->house;
	}
};

/* The Director. Constructs the house */
class Contractor
{
private:
	HouseBuilder *houseBuilder;

public:
	Contractor(HouseBuilder *houseBuilder)
	{
		this->houseBuilder = houseBuilder;
	}

	House *getHouse()
	{
		return houseBuilder->getHouse();
	}

	void buildHouse()
	{
		houseBuilder->buildWindow();
		houseBuilder->buildDoor();
		houseBuilder->buildBathroom();
		houseBuilder->buildKitchen();
		houseBuilder->buildFloor();
	}
};

/* Example on how to use the Builder design pattern */
int main()
{
	HouseBuilder *lavishHouseBldr = new LavishHouse();
	HouseBuilder *normalHouseBldr = new NormalHouse();

	Contractor *ctr1 = new Contractor(lavishHouseBldr);
	Contractor *ctr2 = new Contractor(normalHouseBldr);

	ctr1->buildHouse();
	House *house1 = ctr1->getHouse();
	cout << "Constructed: " << house1;

	ctr2->buildHouse();
	House *house2 = ctr2->getHouse();
	cout << "Constructed: " << house2;
}
#endif // 0