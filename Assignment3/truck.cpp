/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#include "truck.h"

Truck::Truck(string input)
{
	string line;
	int count = 0;
	try {

		Instream.open(input);
		Outstream.open("log.txt");

		if (Instream.is_open()) {
			if (getline(Instream, line))
			{
				this->driver = line;
				getline(Instream, line);
				this->truckWeight = stoi(line);
				getline(Instream, line);
				this->startCity = line;
				getline(Instream, line);
				this->endCity = line;
				getline(Instream, line);
				this->maxPackages = stoi(line);
			}
		}
	}// End try
	catch (exception io)
	{
		cout << "Error: " << io.what();
	}// End catch

	if (Outstream.is_open()) {
		Outstream << "Driver name: " << this->driver << endl
			<< "Unloaded truck weight: " << this->truckWeight << endl
			<< "Source city: " << this->startCity << endl
			<< "Destination city: " << this->endCity << endl
			<< "Maximum packages truck can carry: " << this->maxPackages << endl;
	}
}// End truck


void Truck::load()
{
	string line, Type;
	double price = 0;
	int tnum, weight, type;
	if (Outstream.is_open()) {
		Outstream << "\nPACKAGE LOADING INFORMATION:\n"
			<< "----------------------------" << endl;
	}
	if (Instream.is_open()) {
		while (getline(Instream, line))
		{
			tnum = stoi(line);
			getline(Instream, line);
			weight = stoi(line);
			type = findType(tnum);

			try {
				switch (type) {
				case 0:
					Type = "letter";
					price = 0.05 * weight;
					this->letterWeight += weight;
					this->pPackage = unique_ptr<Package>(new Letter(tnum, weight, type));
					this->pPackage->setName(Type);
					break;
				case 1:
					Type = "box";
					price = 2 * weight;
					this->crateWeight += weight;
					this->pPackage = unique_ptr<Crate>(new Box(tnum, weight, type));
					this->pPackage->setName(Type);
					break;
				case 2:
					Type = "wood crate";
					price = 2.50 * weight;
					this->crateWeight += weight;
					this->pPackage = unique_ptr<Crate>(new Crate_Wood(tnum, weight, type));
					this->pPackage->setName(Type);
					break;
				case 3:
					Type = "metal crate";
					price = 3.00 * weight;
					this->crateWeight += weight;
					this->pPackage = unique_ptr<Crate>(new Crate_Metal(tnum, weight, type));
					this->pPackage->setName(Type);
					break;
				default:
					Type = "unknown";
					price = 0;
					this->pPackage = nullptr;
					break;
				} // End Switch

				if (type == -1 || this->pPackage == nullptr)
					throw PackageException("UNKNOWN PACKAGE TYPE");

				if (!this->pPackage->weightTest())
				{
					if (Type == "letter")
						this->letterWeight -= weight;
					else
						this->crateWeight -= weight;
					throw PackageException("TOO HEAVY");
				}

				if (this->PackageNum < this->maxPackages)
				{
					this->packages.push_back(move(this->pPackage));
					if (Outstream.is_open()) {
						Outstream << "Package Type: " << this->packages[PackageNum]->getName() << endl
							<< "Tracking Number: " << this->packages[PackageNum]->getTracking() << endl
							<< "Weight: " << this->packages[PackageNum]->getWeight();
						if (this->packages[PackageNum]->getType() == 0)
							Outstream << " ounces" << endl;
						else
							Outstream << " pounds" << endl;

						//cout << this->pPackage->getTracking();
						Outstream << "LOADED\n" << endl;
					}
					this->PackageNum++;
					this->cost += price;
				} // Package Number Count

				else
				{
					if (Type == "letter")
						this->letterWeight -= weight;
					else
						this->crateWeight -= weight;
					throw PackageException("TRUCK FULL");
				}

			} // End try
			catch (PackageException& e)
			{
				//this->pPackage->print();
				if (Outstream.is_open()) {
					Outstream << "Package Type: " << Type << endl
						<< "Tracking Number: " << tnum << endl
						<< "Weight: " << weight << endl;
					Outstream << "NOT LOADED: " << e.what() << endl << endl;
				}
			} // End PackageException

		} // End While
	} // End if Input File is open

	if (Outstream.is_open()) {
		Outstream << "LOADED TRUCK WEIGHT: " << this->truckWeight + this->crateWeight << " pounds, " << this->letterWeight << " ounces\n" << endl;
	}

	/* Close Input File */
	Instream.close();

}// End load

void Truck::drive()
{
	if (Outstream.is_open()) {
		Outstream << "DRIVING TRUCK FROM " << this->startCity << " TO " << this->endCity << "...\n"
			<< "ARRIVED AT " << this->endCity << endl << endl;
	}
} // End drive

void Truck::unload()
{
	double totalWeight = this->crateWeight + ((double) this->letterWeight / 16);

	if (Outstream.is_open()) {

		Outstream << "PACKAGE UNLOADING INFORMATION:\n"
			<< "------------------------------" << endl;

		for (size_t i = 0; i < packages.size(); ++i) {

			Outstream << "Package Type: " << this->packages[i]->getName() << endl
				<< "Tracking Number: " << this->packages[i]->getTracking() << endl
				<< "Weight: " << this->packages[i]->getWeight();

			if (this->packages[i]->getType() == 0)
				Outstream << " ounces\n" << endl;
			else
				Outstream << " pounds\n" << endl;
			//this->pPackage->print();

		} // End for
		Outstream << "FINAL TRUCK INFORMATION:\n"
			<< "------------------------\n"
			<< "Packages Delivered: " << this->PackageNum
			<< "\nTotal cost: $" << setprecision(2) << fixed
		    << this->cost << endl;

	}

	Outstream.close();

} // End unload

/*
 * Helper method to determine package type.
 * Takes the tracking number as input and % 10 to find last digit.
 * The last digit determines the package type.
 */
int Truck::findType(int tnum) {
	int temp = tnum;

	if (temp % 10 == 0) // Letter
		return 0;

	else if (temp % 10 == 1) // Box
		return 1;

	else if (temp % 10 == 2) // Wooden Crate
		return 2;

	else if (temp % 10 == 3) // Metal Crate
		return 3;

	return -1;
} // End findType
