#include <iostream>
#include <string>
using namespace std;

// Product Base and Child Classes:

class Product
{
	private:
		static int Productcount;
	
    protected:
        string productName;
        int quantity;
        double volume_per_product;
        double volume_total_product;
        
    public: 
        // Default Constructor
        Product()
        {
            productName = "";
            quantity = 0;
            volume_per_product = 0;
            volume_total_product = 0;
            Productcount++;
        }
        
        
        // Parameterized Constructor
        Product(string productName, int quantity, double volume_per_product)
        {
            this -> productName = productName;
            this -> quantity = quantity;
            this -> volume_per_product = volume_per_product;
            this -> volume_total_product = (volume_per_product * quantity);
            Productcount++;
        }
        
        
        // Copy Constructor
        Product(const Product& other)
        {
            this -> productName = other.productName;
            this -> quantity = other.quantity;
            this -> volume_per_product = other.volume_per_product;
            this -> volume_total_product = other.volume_total_product;
            Productcount++;
        }
        
        // Virtual Destructor (It is virtual to avoid hindering polymorphism.)
        virtual ~Product() 
		{
		    Productcount--;
		}
        
        // Some virtual Necessary Functions:
        virtual void displayInfo() const 
        {
            cout << " Product: " << productName << endl;
            cout << " Quantity: " << quantity << endl;
            cout << " Volume Per Product: " << volume_per_product << endl;
            cout << " Total Volume: " << volume_total_product << endl;
        }

        // Abstract func
        virtual double calculateStorageCost() const = 0;
        
        // OVERLOAD
        void changeQuantity(int amount)
        {
            quantity += amount;
            volume_total_product = quantity * volume_per_product;
        }

        void changeQuantity(int amount, bool isIncrease)
        {    
            if(isIncrease)
            {
            	quantity += amount;
			}
            else
            {
                quantity -= amount;
			}
			
			volume_total_product = quantity * volume_per_product;
        }
         
        //Getters
        
        virtual string getType() const
        {
            return "Product";
        }
        
        int getQuantity() const 
        {
        	return quantity;
		}
		
		static int getProductCount()
		{
			return Productcount;
		}
		
		int get_volume_per_product() const
		{
			return volume_per_product;
		}	
			
		int get_volume_total_product() const
		{
			return volume_total_product;
		}
		
        // Friend Functions
		friend double calculateTotalCost(Product* products[], int size);
		friend double calculateTotalVolume(Product* products[], int size);
		
		
};

class GeneralProduct : public Product
{
	private:
		static int GeneralProductCount;
		
    public:
        GeneralProduct() : Product() 
		{
		    GeneralProductCount++;
		}

        GeneralProduct(string productName, int quantity, double volume_per_product): Product(productName, quantity, volume_per_product) 
		{
			GeneralProductCount++;
		}

        GeneralProduct(const GeneralProduct& other) : Product(other) 
		{
		    GeneralProductCount++;
		}

        ~GeneralProduct() override 
		{
			GeneralProductCount--;
		}

        void displayInfo() const override
        {
            Product::displayInfo();
        }

        double calculateStorageCost() const override
        {
            return volume_total_product * 2;
        }

        string getType() const override
        {
            return "General Product";
        }
        
        static int getGeneralProductCount()
		{
			return GeneralProductCount;
		}
};

class HeavyProduct: public Product
{
	private:
		static int HeavyProductcount;
		
    protected:
        double weightFee;
    
    public: 
        // Child Class's Default Constructor
        HeavyProduct() : Product()
        {
            this -> weightFee = 0; 
            HeavyProductcount++;
        }
    
        // Child Class's Parameterized Constructor
        HeavyProduct(string productName, int quantity, double volume_per_product, double weightFee) : Product(productName, quantity, volume_per_product)
        {
            this -> weightFee = weightFee;
            HeavyProductcount++;
        }
    
        // Child Class's Copy Constructor
        HeavyProduct(const HeavyProduct& other) : Product(other)
        {
            this -> weightFee = other.weightFee;
            HeavyProductcount++;
        }
    
        // Child Class's Destructor 
        ~HeavyProduct() override 
		{
			HeavyProductcount--;
		}
    
        // Override displayInfo
        void displayInfo() const override
        {
            Product::displayInfo(); // Calling Base Class's Function
            cout << " Weight Fee: " << weightFee << endl;
            cout << " Total Cost: " << calculateStorageCost() << endl;
        }

        // Override calculateStorageCost
        double calculateStorageCost() const override
        {
            return volume_total_product * 2 + weightFee;
        }
        
		static int getHeavyProductCount()
		{
			return HeavyProductcount;
		}
        
        virtual string getType() const
        {
            return "Heavy Product";
        }
        
        int getWeightFee() const
        {
        	return weightFee;
		}
};

class FragileProduct: public Product
{
	private:
		static int FragileProductcount;
		
    protected:     
        double protectionCost;

    public:
        FragileProduct() : Product()
        {
            this -> protectionCost = 0;
            FragileProductcount++;
        }

        FragileProduct(string productName, int quantity, double volume_per_product, double protectionCost) : Product(productName, quantity, volume_per_product)
        {
            this -> protectionCost = protectionCost;
            FragileProductcount++;
        }
    
        FragileProduct(const FragileProduct& other) : Product(other)
        {
            this -> protectionCost = other.protectionCost;
            FragileProductcount++;
        }
    
        ~FragileProduct() override 
		{
			FragileProductcount--;
		}
    
        void displayInfo() const override
        {
            Product::displayInfo();
            cout << " Protection Cost: " << protectionCost << endl;
            cout << " Total Cost: " << calculateStorageCost() << endl;
        }

        double calculateStorageCost() const override
        {
            return volume_total_product * 2 + protectionCost;
        }
        
		static int getFragileProductCount()
		{
			return FragileProductcount;
		}
		
		int getProtectionCost() const
		{
			return protectionCost;
		}
        
        virtual string getType() const
        {
            return "Fragile Product";
        }
};

class NuclearProduct : public Product
{
	private:
		static int NuclearProductcount;
		
    protected:
        double hazardLevel;

    public:
        NuclearProduct() : Product()
        {
            this -> hazardLevel = 0;
            NuclearProductcount++;
        }

        NuclearProduct(string productName, int quantity, double volume_per_product, double hazardLevel) : Product(productName, quantity, volume_per_product)
        {
            this -> hazardLevel = hazardLevel;
            NuclearProductcount++;
        }
    
        NuclearProduct(const NuclearProduct& other) : Product(other)
        {
            this -> hazardLevel = other.hazardLevel;
            NuclearProductcount++;
        }
    
        ~NuclearProduct() override 
		{
		NuclearProductcount--;
		}
    
        void displayInfo() const override
        {
            Product::displayInfo();
            cout << " Hazard Level: " << hazardLevel << endl;
            cout << " Total Cost: " << calculateStorageCost() << endl;
        }

        double calculateStorageCost() const override
        {
            return volume_total_product * 5 + (hazardLevel * 100);
        }
        
        static int getNuclearProductCount()
        {
        	return NuclearProductcount;
		}
        
        int getHazardLevel() const
        {
        	return hazardLevel;
		}
        
		virtual string getType() const
        {
            return "Nuclear Product";
        }    
};

int Product::Productcount = 0;
int GeneralProduct::GeneralProductCount = 0;
int HeavyProduct::HeavyProductcount = 0;
int FragileProduct::FragileProductcount = 0;
int NuclearProduct::NuclearProductcount = 0;


// Friend Func Example:
double calculateTotalCost(Product* products[], int size)
{
    double total = 0;

    for(int i = 0; i < size; i++)
    {
        total += products[i]->calculateStorageCost();
    }

    return total;
}

double calculateTotalVolume(Product* products[], int size)
{
    double total = 0;

    for(int i = 0; i < size; i++)
    {
        total += products[i]->get_volume_total_product();
    }

    return total;
}


// Product Arrays!

Product* products[50];
int currentProductCount = 0;

void creatingArrays()
{
	for (int i = 0; i < 50; i++)
    {
        products[i] = NULL;
    }
}

// Some Necessary useful Funcs:

bool cin_fail_shortcut_method()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        system("cls");
        cout << "\n Please enter valid data. " << endl;
        return true;
    }
    return false;
}

void press_enter_to_continue()
{
    cout << "\n Press Enter to continue...";
    cin.ignore(1000, '\n');
    cin.get();      
}

void OperationSuccess()
{
	cout << "\n Successful!" << endl; 
}


// Creating Struct
struct ProductData
{
    string name;
    int quantity;
    double volume;
    double extra; // For weightFee / protectionCost / hazardLevel 
};


// Sub Menu's choose functions:

// choose_1 funcs

void choose_1_Insert_General()
{
	choose_1_Insert_General:
	
	// Struct!
    ProductData data;
	
	cout << "\n Enter Product Name: "<< endl;
	cin >> data.name;
	
	if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_General;
	}
	
	cout << "\n Enter Quantity: "<< endl;
	cin >> data.quantity;
	
	if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_General;
	}
	
	cout << "\n Enter volume per product (This is the Last Question.): "<< endl;
	cin >> data.volume;
	
	if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_General;
	}
	products[currentProductCount] = new GeneralProduct(data.name, data.quantity, data.volume);
    currentProductCount++;
}

void choose_1_Insert_Heavy()
{
	choose_1_Insert_Heavy:
	
	// Struct!
    ProductData data;
	
	cout << "\n Enter Product Name: "<< endl;
	cin >> data.name;
	
	if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Heavy;
	}
	
	cout << "\n Enter Quantity: "<< endl;
	cin >> data.quantity;
	
	if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Heavy;
	}
	
	cout << "\n Enter Weight Fee: "<< endl;
	cin >> data.extra;
	
	if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Heavy;
	}
	
	cout << "\n Enter volume per product (This is the Last Question.): "<< endl;
	cin >> data.volume;
	
	if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Heavy;
	}
	
	products[currentProductCount] = new HeavyProduct(data.name, data.quantity, data.volume,data.extra);
    currentProductCount++;	
}

void choose_1_Insert_Fragile()
{
	choose_1_Insert_Fragile:
	
	// Struct!
    ProductData data;

    cout << "\n Enter Product Name: "<< endl;
    cin >> data.name;
    
    if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Fragile;
	}

    cout << "\n Enter Quantity: "<< endl;
    cin >> data.quantity;

    if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Fragile;
	}

    cout << "\n Enter Protection Cost: "<< endl;
    cin >> data.extra;
    
    if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Fragile;
	}

    cout << "\n Enter volume per product (This is the Last Question.): "<< endl;
    cin >> data.volume;
    
    if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Fragile;
	}

    products[currentProductCount] = new FragileProduct(data.name, data.quantity, data.volume, data.extra);
    currentProductCount++;
}

void choose_1_Insert_Nuclear()
{
	choose_1_Insert_Nuclear:
		
	// Struct!
    ProductData data;

    cout << "\n Enter Product Name: " << endl;
    cin >> data.name;
    
    if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Nuclear;
	}
    
    cout << "\n Enter Quantity: " << endl;
    cin >> data.quantity;
    
    if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Nuclear;
	}

    cout << "\n Enter Hazard Level: " << endl;
    cin >> data.extra;
        
    if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Nuclear;
	}

    cout << "\n Enter volume per product (This is the Last Question.): " << endl;
    cin >> data.volume;
        
    if (cin_fail_shortcut_method())
	{
		system("cls");
        cout << "\n Please provide accurate product information! " << endl;
        press_enter_to_continue();
        system("cls");
        goto choose_1_Insert_Nuclear;
	}

    products[currentProductCount] = new NuclearProduct(data.name, data.quantity, data.volume, data.extra);
    currentProductCount++;	
}

void choose_1_Insert()
{
	int choose;

    while (true)
    {
    	system("cls");
        cout << "\n <== Insert Product Operations ==> " << endl;
        cout << "\n 1-) General Product " << endl;
        cout << "\n 2-) Heavy Product " << endl;
        cout << "\n 3-) Fragile Product " << endl;
        cout << "\n 4-) Nuclear Product " << endl;
        cout << "\n 0-) Back to Main Menu " << endl;
        cout << "\n Please Choose the operation: ";

        cin >> choose;
        if (cin_fail_shortcut_method())
        {
           continue;
        }

        if (choose == 1)
        {
        	system("cls");
            choose_1_Insert_General();
            system("cls");
            OperationSuccess();
            press_enter_to_continue();    
        }
        else if (choose == 2)
        {
        	system("cls");
            choose_1_Insert_Heavy();
            system("cls");
            OperationSuccess();
            press_enter_to_continue(); 
        }
        else if (choose == 3)
        {
        	system("cls");
            choose_1_Insert_Fragile();
            system("cls");
            OperationSuccess();
            press_enter_to_continue(); 
        }
        else if (choose == 4)
        {
        	system("cls");
            choose_1_Insert_Nuclear();
            system("cls");
            OperationSuccess();
            press_enter_to_continue(); 
        }
        else if (choose == 0)
        {
            system("cls");
            break; 
        }
        else
        {
            system("cls");
            cout << "\n Please enter valid data. " << endl;
            press_enter_to_continue();
        }
    }
}

void choose_1_Delete()
{
	choose_1_delete:
	
	int choose;
	while (true)
	{
	    system("cls");
	    cout << " \n All Products \n" << endl;
	    cout << " \n ------------------ \n" << endl;
	
	    for (int i = 0; i < currentProductCount; i++)
        {
    	cout << " "<< i + 1 << ". Product " << "(" << products[i] -> getType() << ") " << endl;
        products[i]->displayInfo();
        if(products[i] -> getType() == "General Product") {cout << " Total Cost: " << products[i] -> calculateStorageCost() << endl; cout << " \n ------------------ \n" << endl;}
        else{cout << " \n ------------------ \n" << endl;}
		}
    
    
        cout << "Please enter the item order number of the item you wish to delete. (If you want to exit, just enter 0.)" << endl;

        cin >> choose;
        
        if(choose == 0)
        {
		    break;        	
		}
    
        if(cin_fail_shortcut_method())
        {
    	    continue;
	    }
	    
	    else if(choose > currentProductCount)
		{
			system("cls");
            cout << "\n Please provide accurate product information! " << endl;
            press_enter_to_continue();
            goto choose_1_delete;
		}
		
		else
		{
			int index = choose - 1;
	    	delete products[index];
	
	    	// For avoid memory problem.
        	for (int i = index; i < currentProductCount - 1; i++)
        	{
            	products[i] = products[i + 1];
        	}

        	products[currentProductCount - 1] = NULL;
        	currentProductCount--;
        
        	system("cls");
        	OperationSuccess();
        	press_enter_to_continue();  
		} 
	}

}

void choose_1_ShowAll()
{
	system("cls");
	cout << " \n All Products \n" << endl;
	cout << " \n ------------------ \n" << endl;
	
	for (int i = 0; i < currentProductCount; i++)
    {
    	cout << " "<< i + 1 << ". Product " << "(" << products[i] -> getType() << ") " << endl;
        products[i]->displayInfo();
        if(products[i] -> getType() == "General Product") {cout << " Total Cost: " << products[i] -> calculateStorageCost() << endl; cout << " \n ------------------ \n" << endl;}
        else{cout << " \n ------------------ \n" << endl;}
    }
    
    press_enter_to_continue();
}

// choose_2 funcs
void choose_2_IncreaseStock()
{
	int choose;
	int increasequantity;
	
	choose_2_inc_main:
	
	while (true)
	{
	    system("cls");
	    cout << " \n All Products \n" << endl;
	    cout << " \n ------------------ \n" << endl;
	
	    for (int i = 0; i < currentProductCount; i++)
        {
    	cout << " "<< i + 1 << ". Product " << "(" << products[i] -> getType() << ") " << endl;
        products[i]->displayInfo();
        if(products[i] -> getType() == "General Product") {cout << " Total Cost: " << products[i] -> calculateStorageCost() << endl; cout << " \n ------------------ \n" << endl;}
        else{cout << " \n ------------------ \n" << endl;}
		}
    
    
        cout << "Please enter the item order number of the item you wish to Increase Stock. (If you want to exit, just enter 0.)" << endl;
        cin >> choose;
    
        if(cin_fail_shortcut_method())
        {
    	    continue;
	    }
    
        if(choose == 0)
        {
        	system("cls");
		    break;        	
		}
		
		else if(choose > currentProductCount)
		{
			system("cls");
            cout << "\n Please provide accurate product information! " << endl;
            press_enter_to_continue();
            goto choose_2_inc_main;
		}
		
		else
		{
			int index = choose - 1;
	    
	    	system("cls");
	    	cout << "How much do you want to increase the stock of the product you have selected below? \n ------------------ \n" << endl; 
	    
	    	cout << " "<< index + 1 << ". Product " << "(" << products[index] -> getType() << ") " << endl;
        	products[index]->displayInfo();
        	if(products[index] -> getType() == "General Product") {cout << " Total Cost: " << products[index] -> calculateStorageCost() << endl; cout << " \n ------------------ \n" << endl;}
        	else{cout << " \n ------------------ \n Please Enter the Quantity => " << endl;}
        	cin >> increasequantity;
        
        	products[index] -> changeQuantity(increasequantity);	
        	
        	system("cls");
            OperationSuccess();
            press_enter_to_continue();  
		}
    }
}

void choose_2_DecreaseStock()
{
	int choose;
	int decreasequantity;
	
	choose_2_dec_main:
	
	while (true)
	{
	    system("cls");
	    cout << " \n All Products \n" << endl;
	    cout << " \n ------------------ \n" << endl;
	
	    for (int i = 0; i < currentProductCount; i++)
        {
    	cout << " "<< i + 1 << ". Product " << "(" << products[i] -> getType() << ") " << endl;
        products[i]->displayInfo();
        if(products[i] -> getType() == "General Product") {cout << " Total Cost: " << products[i] -> calculateStorageCost() << endl; cout << " \n ------------------ \n" << endl;}
        else{cout << " \n ------------------ \n" << endl;}
		}
    
    
        cout << "Please enter the item order number of the item you wish to Decrease Stock. (If you want to exit, just enter 0.)" << endl;
        cin >> choose;
    
        if(cin_fail_shortcut_method())
        {
    	    continue;
	    }
    
        if(choose == 0)
        {
        	system("cls");
		    break;        	
		}
		
		else if(choose > currentProductCount)
		{
			system("cls");
            cout << "\n Please provide accurate product information! " << endl;
            press_enter_to_continue();
            goto choose_2_dec_main;
		}
		
		else
		{
			int index = choose - 1;
	    
	    	system("cls");
	    	cout << "How much do you want to decrease the stock of the product you have selected below? \n ------------------ \n" << endl; 
	    
	    	cout << " "<< index + 1 << ". Product " << "(" << products[index] -> getType() << ") " << endl;
        	products[index]->displayInfo();
        	if(products[index] -> getType() == "General Product") {cout << " Total Cost: " << products[index] -> calculateStorageCost() << endl; cout << " \n ------------------ \n" << endl;}
        	else{cout << " \n ------------------ \n Please Enter the Quantity => " << endl;}
        	cin >> decreasequantity;
        
            if (decreasequantity > products[index] -> getQuantity())
            {
            	system("cls");
            	cout << "\n The amount of stock you wish to delete cannot exceed the amount currently in stock! " << endl;
            	press_enter_to_continue();
            	goto choose_2_dec_main;
			}
			
			else
			{
			    products[index] -> changeQuantity(decreasequantity,false);	
        	    system("cls");
                OperationSuccess();
                press_enter_to_continue();  
			}
		}
    }
}


// Main Menu choose functions:

void choose_1()
{
    int choose;

    while (true)
    {
    	system("cls"); 
        cout << "\n <== Product Operations ==> " << endl;
        cout << "\n 1-) Insert Product " << endl;
        cout << "\n 2-) Delete Product " << endl;
        cout << "\n 3-) Show all Products " << endl;
        cout << "\n 0-) Back to Main Menu " << endl;
        cout << "\n Please Choose the operation: ";

        cin >> choose;
        
        if (cin_fail_shortcut_method())
        {
           continue;
        }

        if (choose == 1)
        {
            choose_1_Insert();
        }
        else if (choose == 2)
        {
            choose_1_Delete();
        }
        else if (choose == 3)
        {
            choose_1_ShowAll();
        }
        else if (choose == 0)
        {
            break; 
        }
        else
        {
            system("cls");
            cout << "\n Please enter valid data. " << endl;
            press_enter_to_continue();
        }
    }
};

void choose_2()
{
    int choose;

    while (true)
    {
    	system("cls");
        cout << "\n <== Stock Operations ==> " << endl;
        cout << "\n 1-) Increasing the stock of the existing product " << endl;
        cout << "\n 2-) Decreasing the stock of the existing product " << endl;
        cout << "\n 0-) Back to Main Menu " << endl;
        cout << "\n Please Choose the operation: ";

        cin >> choose;
        if (cin_fail_shortcut_method())
        {
           continue;
        }

        if (choose == 1)
        {
        	system("cls");
            choose_2_IncreaseStock();
        }
        else if (choose == 2)
        {
        	system("cls");
            choose_2_DecreaseStock();
        }
        else if (choose == 0)
        {
            system("cls");
            break; 
        }
        else
        {
            system("cls");
            cout << "\n Please enter valid data. " << endl;
        }
    }
};

void choose_3()
{
	system("cls");
	cout << " \n All Products \n" << endl;
	cout << " \n ------------------ \n" << endl;
	
	for (int i = 0; i < currentProductCount; i++)
    {
    	cout << " "<< i + 1 << ". Product " << "(" << products[i] -> getType() << ") " << endl;
        products[i]->displayInfo();
        if(products[i] -> getType() == "General Product") {cout << " Total Cost: " << products[i] -> calculateStorageCost() << endl; cout << " \n ------------------ \n" << endl;}
        else{cout << " \n ------------------ \n" << endl;}
    }
    
    
    cout << " \n ##################################################################" << endl;
    cout << " \n Type Of All Products => " << currentProductCount << endl;
    cout << " \n Type Of General Products => " << GeneralProduct::getGeneralProductCount() << endl;
    cout << " \n Type Of Heavy Products => " << HeavyProduct::getHeavyProductCount() << endl;
    cout << " \n Type Of Fragile Products => " << FragileProduct::getFragileProductCount()<< endl;
    cout << " \n Type Of Nuclear Products => " << NuclearProduct::getNuclearProductCount() << endl;
    cout << " \n Occupancy rate => " << currentProductCount << " / 50" << endl;
    
    double TotalCost = calculateTotalCost(products, currentProductCount);
    double TotalVolume = calculateTotalVolume(products, currentProductCount);
    
    cout << " \n ##################################################################" << endl;
    cout << " \n Total Volume => " << TotalVolume << endl;
    cout << " \n Total Cost => " << TotalCost << " TL" << endl;

    press_enter_to_continue();
};


// Main Function

int main(int argc, char** argv) 
{
    int choose;

    while (true)
    {
    	system("cls");
        cout << "\n <== Welcome the Warehouse Management App ==> " << endl;
        cout << "\n 1-) Product Operations " << endl;
        cout << "\n 2-) Stock Operations " << endl;
        cout << "\n 3-) Report Operation " << endl;
        cout << "\n 0-) Exit " << endl;
        cout << "\n Please Choose the operation: ";

        cin >> choose;

        // Checking the input for valid/invalid inputs
        if (cin_fail_shortcut_method())
        {
           continue;
        }

        if (choose == 1)
        {
            system("cls");
            choose_1();
        }
        else if (choose == 2)
        {
            system("cls");
            choose_2();
        }
        else if (choose == 3)
        {
            system("cls");
            choose_3();
        }
        else if (choose == 0)
        {
            cout << "\n Exiting program... " << endl;
            break;
        }
        else
        {
            system("cls");
            cout << "\n Please enter valid data." << endl;
            press_enter_to_continue();
        }
    }
    
    return 0;
};