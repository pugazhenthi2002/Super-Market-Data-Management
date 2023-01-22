#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void MainDecoration();

int Item_ID_gen=1,Cust_ID_gen=1;
string NewUser="1234",NewPass="1234";

struct Items
{
	int Item_ID;
	string Item_name;
	double Cost_per_unit;
	int Stock;
};
vector<Items>ItemList;

struct Customer
{
	int CustomerID;
	vector<int>Ordered_ItemID;
	vector<string>ItemsOrdered;
	vector<int>Quantity;
	double TotalBill;
};
vector<Customer>CustomerList;


void InsertItems()
{
	cout<<"------------------------------\nWelcome to Insert Page\n------------------------------\n\nHow many new Items do you want to Enter: ";
	int No_of_Entries;
	cin>>No_of_Entries;
	struct Items ItemEntry[No_of_Entries];
	for(int i=0;i<No_of_Entries;i++)
	{
		ItemEntry[i].Item_ID=Item_ID_gen;
		cout<<"\nEnter the Item Name:";
		cin>>ItemEntry[i].Item_name;
		cout<<"Cost Per Unit:";
		cin>>ItemEntry[i].Cost_per_unit;
		cout<<"Number of Stock:";
		cin>>ItemEntry[i].Stock;
		ItemList.push_back(ItemEntry[i]);
		Item_ID_gen++;
	}
	cout<<endl;
	cout<<"\t\t\t\t***Items Entered Successfully***\n";
	cout<<"\n------------------------------------------------------------\n";

}

void UpdateItems()
{
	if(ItemList.empty())
	{
		cout<<"\n\t\t*** List is Empty ***\n\n";
		return;
	}
	int UpdateID,UpdToken,UpdVal,ItemCheck;
	while(1)
	{	
		ItemCheck=0;
		cout<<"------------------------------\nWelcome to Update Page\n------------------------------\n1. Update Cost Value:\n2. Update Stocks\n3. Exit\n\nEnter the Update Token: ";
		cin>>UpdToken;
		if(UpdToken==1 || UpdToken==2)
		{
			switch(UpdToken)
			{
				case 1: cout<<"Which Item ID to be updated: ";
						cin>>UpdateID;
						for(int i=0;i<ItemList.size();i++)
						{
							if(ItemList[i].Item_ID==UpdateID)
							{
								ItemCheck=1;
							}
						}
						if(ItemCheck==0)
						{
							cout<<"\n------------------------------\n  *** Invalid Item ID ***\n------------------------------\n";
							continue;
						}
						
						cout<<"Update the Cost Value: ";
						cin>>UpdVal;
						ItemList[UpdateID-1].Cost_per_unit=UpdVal;
						break;
						
				case 2: cout<<"Which Item ID to be updated: ";
						cin>>UpdateID;
						for(int i=0;i<ItemList.size();i++)
						{
							if(ItemList[i].Item_ID==UpdateID)
							{
								ItemCheck=1;
							}
						}
						if(ItemCheck==0)
						{
							cout<<"\n------------------------------\n  *** Invalid Item ID ***\n------------------------------\n";
							continue;
						}
						cout<<"Update the Stock Value: ";
						cin>>UpdVal;
						ItemList[UpdateID-1].Stock+=UpdVal;
						break;
			}
		}
		else if(UpdToken==3)
		{
			break;
		}
		else
		{
			cout<<"\n\t\t*** Invalid Update Token ***\n------------------------------------------------------------\n";
		}
	}
	cout<<"\n\t\t\t\t***Items Entered Successfully***\n";
	
	
}

void ViewItems()
{
	
	cout<<"\t\t\tItem Details\n";
	if(ItemList.empty())
	{
		cout<<"\n\t\t*** List is Empty ***\n\n";
		return;
	}
	cout<<"------------------------------------------------------------\nItemID\tItemName\tCost_per_unit  Remaining Stock\n------------------------------------------------------------\n";
	for(auto& a:ItemList)
	{
		cout<<a.Item_ID<<"\t"<<a.Item_name<<"\t\t"<<a.Cost_per_unit<<"\t\t"<<a.Stock<<endl;
	}
	cout<<"\n------------------------------------------------------------\n";
}

void PasswordChange(string OldPass)
{
	while(1)
	{
		cout<<"Re-enter Old Password: ";
		cin>>OldPass;
		if(OldPass==NewPass)
		{
			cout<<"\nEnter new password: ";
			cin>>NewPass;
			cout<<"\n\t\t\t***Password Changed Successfully***\n";
			break;
		}
		else
		{
			cout<<"\n\t\t\t!!! Wrong Password\n";
			cout<<"\n------------------------------------------------------------\n";
		}
		
	}
	cout<<"\n------------------------------------------------------------\n";
}




void Administrator()
{
	string OldUser,OldPass;
	cout<<"Enter the Admin Username: ";
	cin>>OldUser;
	cout<<"Admin Password: ";
	cin>>OldPass;
	if(OldUser==NewUser && OldPass==NewPass)
	{
		int AdminToken;
		while(1)
		{
			cout<<"------------------------------\nWelcome to Admin Page\n------------------------------\n1. Insert Items\n2. Update Items\n3. View Items\n4. Change Password\n0. Exit\n\nEnter the Admin Token: ";
			cin>>AdminToken;
			cout<<"\n------------------------------------------------------------\n";
			if(AdminToken==0)
			{
				cout<<endl;
				break;
			}
			else if(AdminToken>0 && AdminToken<5)
			{
				switch(AdminToken)
				{
					case 1: InsertItems();break;
					case 2: UpdateItems();break;
					case 3: cout<<endl;ViewItems();break;
					case 4: PasswordChange(OldPass); break;
				}
			}
			else
			cout<<"\n\t\t*** Invalid Admin Token ***\n------------------------------------------------------------\n";
		}
	}
	else
	{
		cout<<"\n\t\t*** Mismatch Username and Password ***\n\n*********************************************************\n";
	}
}

void CashEntry()
{
	cout<<"---------------------------------------------------------------------\n\t\t\t*** Customer "<<Cust_ID_gen<<" ***\n---------------------------------------------------------------------\n";
	struct Customer CustomerEntry;
	
	
	int ItemID_entry,entry=1,ItemCheck,EntryCheck=0;
	double Quan_Entry,Cost_Entry,Total_Cost=0;
	string check_entry;
	
	while(entry)
	{
		ItemCheck=0;
		cout<<"\nIs there Items for entry? ";
		cin>>check_entry;
		if(check_entry=="Yes" || check_entry=="yes")
		{
			cout<<"------------------------------\n\t*** Entry"<<entry<<" ***\n------------------------------\n";
			cout<<"\nEnter the Item ID: ";
			cin>>ItemID_entry;
			for(int i=0;i<ItemList.size();i++)
			{
				if(ItemList[i].Item_ID==ItemID_entry)
				{
					ItemCheck=1;
				}
			}
			if(ItemCheck==0)
			{
				cout<<"\n------------------------------\n  *** Invalid Item ID ***\n------------------------------\n";
				continue;
			}
			
			cout<<"Item Name: "<<ItemList[ItemID_entry-1].Item_name<<endl;
			cout<<"Quantities in Kilo: ";
			cin>>Quan_Entry;
			
			if(ItemList[ItemID_entry-1].Stock>Quan_Entry)
			{
				CustomerEntry.CustomerID=Cust_ID_gen;
				ItemList[ItemID_entry-1].Stock-=Quan_Entry;
				EntryCheck=1;
			}
			else
			{
				cout<<"\n------------------------------\t\t*** Not Enough Stock ***\n------------------------------\n";
				continue;
			}
			
			Cost_Entry=(ItemList[ItemID_entry-1].Cost_per_unit)*Quan_Entry;
			cout<<"Cost of Item "<<entry<<": "<<Cost_Entry<<"\n-----------------------------\n";
			Total_Cost+=Cost_Entry;
			
			CustomerEntry.Ordered_ItemID.push_back(ItemID_entry);
			CustomerEntry.ItemsOrdered.push_back(ItemList[ItemID_entry-1].Item_name);
			CustomerEntry.Quantity.push_back(Quan_Entry);
		}
		else
		{
			break;
		}
		entry++;
	}
		if(EntryCheck)
		{
			cout<<"\n\n\t\t\t*** Total Bill: "<<Total_Cost<<" ***\n\n";
			CustomerEntry.TotalBill=Total_Cost;
			CustomerList.push_back(CustomerEntry);
			Cust_ID_gen++;
		}
	
}

void Customer_Details()
{
	if(CustomerList.empty())
	{
		cout<<"\n\t\t*** List is Empty ***\n\n";
		return;
	}
	cout<<"\n\t\t\tCustomer Details\n\n";
	cout<<"-------------------------------------------------------------------------------------------\nCustomerID\tTotal Cost\tItems Details\n-------------------------------------------------------------------------------------------\n";
	for(auto a:CustomerList)
	{
		cout<<a.CustomerID<<"\t\t"<<a.TotalBill<<"\t\t";
		for(int i=0;i<a.Ordered_ItemID.size();i++,cout<<"  ")
		{
			cout<<a.Ordered_ItemID[i]<<". "<<a.ItemsOrdered[i]<<'-'<<a.Quantity[i]<<"Kilo";
		}
		cout<<"\n";
	}
	cout<<endl<<endl;
}

void Cashier()
{
	while(1)
	{
		int CashToken;
		cout<<"------------------------------\nWelcome to Cash Counter Page\n------------------------------\n1. Cash Entry\n2. Customer Details\n3. Exit\n\nEnter the Cashier Token: ";
		cin>>CashToken;
		cout<<"\n------------------------------\n";
		if(CashToken==1 || CashToken==2)
		{
			switch(CashToken)
			{
				case 1: CashEntry();break;
				case 2: Customer_Details();break;
			}
		}
		else if(CashToken==3)
		{
			break;
		}
		else
		{
			cout<<"\n\t\t\t *** Invalid Cashier Token ***\n\n";
		}
	}
}

int main()
{
	cout<<"******************* Welcome to Super-Market Bill Counter *******************\n\n";
	int a;
	while(1)
	{
		MainDecoration();
		cout<<"Enter the Main Token: ";
		cin>>a;
		cout<<"\n*********************************************************\n";
		if(a==3)
		{
			cout<<"\n\n\t\t\t*** THANK YOU ***\t\t\t\n\n";
			break;
		}
		else if(a==1 || a==2)
		{
			switch(a)
			{
				case 1:	Administrator();break;
				case 2: Cashier();break;
			}
		}
		else
		{
			cout<<"\n\t\t\t *** Invalid Main Token ***\n\n";
		}
	}
	return 0;
}

void MainDecoration()
{
	string str_admin="1. Administrator",str_cashier="2. Cashier",str_close="3. Exit";
	int a=str_admin.length(),b=str_cashier.length(),c=str_close.length();
	
	int flag=max(a,b);
	for(int row=1;row<=7;row++)
	{
		for(int col=1,i=0;col<=flag*2;col++)
		{
			if(row==1 || col==1 || col==flag*2 || row==7)
			cout<<'*';
			else if(row==3 && i<=a && col>=7)
			{
				cout<<str_admin[i];
				i++;
			}
			else if(row==4 && i<=b && col>=7)
			{
				cout<<str_cashier[i];
				i++;
			}
			else if(row==5 && i<=c && col>=7)
			{
				cout<<str_close[i];
				i++;
			}
			else
			cout<<' ';
		}
		cout<<'\n';
	}
	cout<<'\n';
}
