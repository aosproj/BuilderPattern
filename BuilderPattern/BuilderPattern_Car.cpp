#include <iostream>

enum carType
{
	CITYCAR,
	CABRIOLET,
	SPORTS
};

/* Product */
class Car {
private:
	int16_t numseats;
	carType carVersion;
	bool tripComputer;
	bool GPS;
	bool AWD;
public:
	Car():tripComputer(false),GPS(false),AWD(false){}

	void setSeats(int16_t seatcnt) { numseats = seatcnt; }
	void setCarVersion(carType ver) { carVersion = ver; }
	void setTripComp(bool tripcomp) { tripComputer = tripcomp; }
	void setGPS(bool gpsstat) { GPS = gpsstat; }
	void setAWD(bool awdstat) { AWD = awdstat; }

	void getCarInfo()
	{
		switch (this->carVersion) {
		case carType::CITYCAR:
			std::cout << "Car is a City Car" << std::endl;
			break;
		case carType::CABRIOLET:
			std::cout << "Car is a Cabriolet" << std::endl;
			break;
		case carType::SPORTS:
			std::cout << "Car is a Sports Car" << std::endl;
			break;
		}

		std::cout << "No. of Seats is " << this->numseats << std::endl;

		if (this->tripComputer)
		{
			std::cout << "Car Equipped with a TripComputer" << std::endl;
		}

		if (this->GPS)
		{
			std::cout << "Car Equipped with a GPS" << std::endl;
		}

		if (this->AWD)
		{
			std::cout << "Car is an All Wheel Drive" << std::endl;
		}
	}
};

/* Abstract Builder */
class CarBuilder{
public:
	virtual void seatCount(int16_t seatcnt)=0;
	virtual void setCarType() = 0;
	virtual void setTripComputer() {};
	virtual void setGPS() {};
	virtual void setAWD() {};
	virtual Car* getCar() = 0;
};

/* Concrete Builder 1*/
class CityCar :public CarBuilder
{
private:
	Car *carobj;
public:
	CityCar()
	{
		carobj = new Car();
	}
	void seatCount(int16_t seatcnt);
	void setCarType();
	void setTripComputer();

	Car* getCar()
	{
		return this->carobj;
	}

	~CityCar()
	{
		delete carobj;
	}
};

void CityCar::seatCount(int16_t seatcnt)
{
	carobj->setSeats(seatcnt);
}

void CityCar::setCarType()
{
	carobj->setCarVersion(carType::CITYCAR);
}

void CityCar::setTripComputer()
{
	carobj->setTripComp(true);
}

/* Concrete Builder 2*/
class SportsCar :public CarBuilder
{
private:
	Car *carobj;
public:
	SportsCar()
	{
		carobj = new Car();
	}
	void seatCount(int16_t seatcnt);
	void setCarType();
	void setTripComputer();
	void setGPS();
	void setAWD();
	Car* getCar()
	{
		return this->carobj;
	}
};

void SportsCar::seatCount(int16_t seatcnt)
{
	carobj->setSeats(seatcnt);
}

void SportsCar::setCarType()
{
	carobj->setCarVersion(carType::SPORTS);
}

void SportsCar::setTripComputer()
{
	carobj->setTripComp(true);
}

void SportsCar::setGPS()
{
	carobj->setGPS(true);
}

void SportsCar::setAWD()
{
	carobj->setAWD(true);
}


/* The Director. Constructs the house */
class CarManuFacturer
{
private:
	CarBuilder *carBuilder;
	int16_t numseats;
public:
	CarManuFacturer(CarBuilder *carBuilder, int16_t numseats)
	{
		this->carBuilder = carBuilder;
		this->numseats = numseats;
	}

	Car *getCar()
	{
		return carBuilder->getCar();
	}

	void buildCar()
	{
		carBuilder->seatCount(numseats);
		carBuilder->setCarType();
		carBuilder->setAWD();
		carBuilder->setGPS();
		carBuilder->setTripComputer();
	}
};

/* Example on how to use the Builder design pattern */
int main()
{
	CarBuilder *citycar = new CityCar();
	CarBuilder *sportscar = new SportsCar();

	CarManuFacturer *ctr1 = new CarManuFacturer(citycar,4);
	CarManuFacturer *ctr2 = new CarManuFacturer(sportscar,2);

	ctr1->buildCar();
	Car *car1 = ctr1->getCar();
	car1->getCarInfo();

	std::cout << std::endl;

	ctr2->buildCar();
	Car *car2 = ctr2->getCar();
	car2->getCarInfo();
}