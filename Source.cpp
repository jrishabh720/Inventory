#include"Invoices.h"

vector<CMstProduct>vecProduct;

int CInvoices::m_nInvoiceNumber = 1;
vector <CInvoices> vecAllInvoice;

void new_entry()
{
	CInvoices *ptemp = new CInvoices(vecProduct);
	vecAllInvoice.push_back((*ptemp));
	delete(ptemp);
}

void allProduct()
{
	cout << "PNo. Products " << endl;
	int nTemp = 1;
	for (auto &x : vecProduct)
	{
		cout << setw(5) << nTemp << "  ";
		nTemp++;
		x.getProductName();
		cout << endl;
	}
}

void addProduct() {
	while (1) {
		system("CLS");
		cout << "Operations - " << endl;
		cout << "1 Insert Product" << endl;
		cout << "2 Done" << endl;
		int nOp;
		cin >> nOp;
		system("CLS");
		if (nOp == 1)
		{
			CMstProduct *t = new CMstProduct;
			vecProduct.push_back(*t);
			delete(t);
			t = NULL;
		}
		else
		{
			break;
		}
	}
}

void takeTask() {
	while (1) {
		system("CLS");

		cout << "Operations[Vaucher] - " << endl;
		cout << "1 New Entry" << endl;
		cout << "2 List All" << endl;
		cout << "3 Display" << endl;
		cout << endl << "Operation[Product]" << endl;
		cout << "4 New Entry" << endl;
		cout << "5 List All" << endl;
		cout << "6 Update Product" << endl;
		cout << endl << "7 Close" << endl;
		cout << "Choose your operations - ";
		int nOperation;
		cin >> nOperation;
		system("CLS");
		switch (nOperation) {
		case 1:
			new_entry();
			break;
		case 2:
			cout << "|  Inv No";
			cout << "   | Cust_Name           ";
			cout << "   | No of Products   ";
			cout << "| Net       |" << "   m_nDate   |" << endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			for (auto x : vecAllInvoice)
			{
				x.giveInvoiceNumber();
				x.giveCustName();
				x.giveNumberOfProduct();
				x.giveNetAmount();
			}
			int nExit;
			cout << "Enter 1 to exit - ";
			cin >> nExit;
			break;
		case 3:
			cout << "Enter Invoice No. - ";
			int t_inv;
			cin >> t_inv;
			system("CLS");
			vecAllInvoice[t_inv - 1].giveProductInfo(vecProduct);
			{
				int nExit;
				cout << "Enter 1 to exit - ";
				cin >> nExit;
			}
			break;
		case 4:
			system("CLS");
			addProduct();
			break;
		case 5:
			cout << "All Products " << endl;
			allProduct();
			{
				int nExit;
				cout << "Enter 1 to exit - ";
				cin >> nExit;
			}
			break;
		case 6:
			cout << "All Products " << endl;
			allProduct();
			cout << "Enter the product number for update - ";
			int nTemp;
			cin >> nTemp;
			vecProduct[nTemp].updatePrice();
			break;
		case 7:
			return;
		default:
			cout << "Wrong Input" << endl;
			break;
		}
	}
}

int main() {

	addProduct();

	takeTask();

	system("pause");
}