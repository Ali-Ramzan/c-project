#include<iostream>
#include<fstream>
using namespace std;
struct books
{
	string name,author;
	int edition,shelf;
};
struct student
{
	string REGno,name,DUEdate;
	int fine;
	books issued;
};
void Delete(books array[],string b,int &total);
struct librarian
{
	void issue(books ar[],student arr[],int &total,int &totlstd)
	{
		student s;
		string a;
		cout<<"which book wanna issue: ";
		cin>>a;
		int i;
		for(int j=0;j<total;j++)
		{if(a==ar[j].name)
		{i=1;}
	}
		if(i=1)
		{
		cout<<"student's name: ";
		cin>>arr[totlstd].name;
		cout<<"student's registration number: ";
		cin>>arr[totlstd].REGno;
		cout<<"Due Date: ";
		cin>>arr[totlstd].DUEdate;
		arr[totlstd].fine=0;
		i=0;
		while(i<total)
		{
			if(ar[i].name==a)
			{
				arr[totlstd].issued.name=ar[i].name;
				arr[totlstd].issued.edition=ar[i].edition;
				arr[totlstd].issued.author=ar[i].author;
				arr[totlstd].issued.shelf=ar[i].shelf;
				break;
			}
			i++;
		}
		totlstd++;
		Delete(ar,a,total);
		cout<<endl<<"    @Book has been issued@"<<endl<<endl<<"       **--Now Remaining Books--**"<<endl;
		i=0;
		while(i<total)
		{
			cout<<"Book Name: "<<ar[i].name<<endl<<"Edition No.: "<<ar[i].edition<<endl<<"Author Name: "<<ar[i].author<<endl<<"Shelf No.: "<<ar[i].shelf<<endl<<endl;
			i++;
		}
			}else{cout<<"     Sorry! book not found "<<endl<<endl;
		}
		}
	void addfine(student arr[],int totlstd)
	{
		string s;
		cout<<"name the student .you want to add fine"<<endl;
		cin>>s;
		int ck=0;
		for(int i=0;i<totlstd;i++)
		{
			if(s==arr[i].name)
			{
				arr[i].fine=arr[i].fine+10;
				cout<<"      --Fine added successfully--"<<endl;
				ck++;
				break;
			}
		}
		if(ck==0)
		{
			cout<<"No Student found !"<<endl<<endl;
		}
	}
	void Checkrecord(student arr[],int totlstd)
	{
		if(totlstd>1)
		{for(int i=0;i<totlstd-1;i++)
		{
			cout<<"name:  "<<arr[i].name<<endl<<"Registration No :"<<arr[i].REGno<<endl<<"Date of Issuance: "<<arr[i].DUEdate<<endl<<"Book issued: "<<arr[i].issued.name<<endl<<"edition: "<<arr[i].issued.edition<<endl<<"Author's name: "<<arr[i].issued.author<<endl<<"Shelf No.: "<<arr[i].issued.shelf<<endl<<"Fine: "<<arr[i].fine<<endl<<endl;
		}
		}
		else{cout<<"   No data available!"<<endl;
		}
	
	}
};
void add(books ar[],int &total);
void edit(books array[]);
void search(books array[],int &total);
bool login(string a[]);
bool recep(string a[],int pass);
void Return(student arr[],books ar[],int &totlstd,int &total);


int main()
{
	librarian lib;
	student arr[12];
	ifstream b;
	b.open("std.txt");
	int i=0,totlstd;
	while(!b.eof())
	{
		b>>arr[i].name;
		b>>arr[i].REGno;
		b>>arr[i].DUEdate;
		b>>arr[i].fine;
		b>>arr[i].issued.name;
		b>>arr[i].issued.edition;
		b>>arr[i].issued.author;
		b>>arr[i].issued.shelf;
		i++;
	}
	totlstd=i;
	b.close();
	books ar[20];
	ifstream a;
	a.open("books.txt");
	i=0;
	while(!a.eof())
	{
		a>>ar[i].name;
		a>>ar[i].edition;
		a>>ar[i].author;
		a>>ar[i].shelf;
		i++;
	}
	a.close();
	int total=i;
	ifstream lg;
	lg.open("log.txt");
	string log[11];
	i=0;
	while(!lg.eof())
	{
		lg>>log[i];
		i++;
	}
	lg.close();
	int pass=i;




cout<<totlstd;


	cout<<":*--Welcome to Library Management System--*:"<<endl<<"                                                "<<" __"<<endl<<"                                                "<<"('')"<<endl<<"                                                "<<"(--)"<<endl<<"                                                "<<".--."<<endl<<"(Please login to access this system)"<<endl<<"   1)as Reception"<<endl<<"   2)as Librarian"<<endl<<"Choose option: ";
	int op;
	cin>>op;
	if(op==1)
	{
		if(recep(log,pass)==true)
		{
		while(op!=3)
		{
		cout<<"1)Search Books"<<endl<<"2)Return Book"<<endl<<"3) Exit"<<endl<<"enter Option:";
		cin>>op;
		if(op==1)
		{
			search(ar,total);
			continue;
		}
		else if(op==2)
		{
			Return(arr,ar,totlstd,total);
			cout<<"  )BOOK RETURNED("<<endl;
			continue;
		}
		else if(op==3)
		{
			exit(1);
		}
		}
		}
	}
	else if(op==2)
	{
		if(login(log) == true)
		{
		while(op!=8)
		{
		cout<<"1-Search Books"<<endl<<"2-Add Books"<<endl<<"3-Edit Books"
		<<endl<<"4-Delete Books"<<endl<<"5-Issue Book"<<endl<<"6-Add Fine"<<endl<<"7-Check Record of Students"<<endl<<"8-Exit"<<endl<<"Choose the option: ";
		cin>>op;
		if(op==1)
		{
			search(ar,total);
		}
		else if(op==2)
		{
			add(ar,total);
		}
		else if(op==3)
		{
			edit(ar);
		}
		else if(op==4)
		{
			cout<<"Enter a Book u wanna delete: ";
			string b;
			cin>>b;
			Delete(ar,b,total);
		}
		else if(op==5)
		{
			lib.issue(ar,arr,total,totlstd);
		}
		else if(op==6)
		{
			lib.addfine(arr,totlstd);
		}
		else if(op==7)
		{
			lib.Checkrecord(arr,totlstd);
		}
		else if(op==8)
		{
			exit(1);
		}
		}
		}
	}
	
	
	
	
	
	
	
	
	ofstream out;
	out.open("std.txt");
	i=0;
	while(i<totlstd)
	{
		out<<arr[i].name<<' '<<arr[i].REGno<<' '<<arr[i].DUEdate<<' '<<arr[i].fine<<arr[i].issued.name<<arr[i].issued.edition<<arr[i].issued.author<<' '<<arr[i].issued.shelf<<'\n';
	
		i++;
	}
	out.close();
	
	ofstream ot;
	ot.open("books.txt");
	i=0;
	while(i<total)
	{

		ot<<ar[i].name<<' '<<ar[i].edition<<' '<<ar[i].author<<' '<<ar[i].shelf<<'\n';
		i++;
	}
	ot.close();
	return 0;
}









void add(books ar[],int &total)
{
	cout<<"Enter book Name:";
	cin>>ar[total].name;
	cout<<endl<<"Enter book Edition:";
	cin>>ar[total].edition;
	cout<<endl<<"Enter Author's Name:";
	cin>>ar[total].author;
	cout<<endl<<"Enter the Shelf No. where u want to place:";
	cin>>ar[total].shelf;
	total=total+1;
	cout<<"   @ Book is added Successfully=@"<<endl<<endl;
}
void edit(books array[])
{
	int i=0,c;
	cout<<"enter book u wanna edit"<<endl;
	string b;
	cin>>b;
	while(array[i].name!=b)
	{
		i++;
	}
	cout<<"enter new book name"<<endl;
	cin>>b;
	array[i].name=b;
	cout<<"enter new edition number"<<endl;
	cin>>c;
	array[i].edition=c;
	cout<<"enter new author name"<<endl;
	cin>>b;
	array[i].author=b;
	cout<<"enter new shelf number"<<endl;
	cin>>c;
	array[i].shelf=c;
	cout<<"   --Book edited successfully--"<<endl<<endl;
}
void Delete(books array[],string b,int &total)
{
	int c=0,i=0;
	while(array[i].name!=b)
	{
		i++;
	}
	ofstream out;
	out.open("books.txt");
	while(c<total)
	{
		if(c==i)
		{
			c++;
			continue;
		}
		out<<array[c].name<<' '<<array[c].edition<<' '<<array[c].author<<' '<<array[c].shelf<<'\n';
		c++;
	}
	out.close();
	ifstream a;
	a.open("books.txt");
	i=0;
	while(!a.eof())
	{
		a>>array[i].name;
		a>>array[i].edition;
		a>>array[i].author;
		a>>array[i].shelf;
		i++;
	}
	a.close();
	total=i-1;
	cout<<"Now total books="<<total<<endl;
}
void search(books array[],int &total)
{
	int c,i=0,chk=0;
	string b;
	cout<<")-(SEARCH BY)-("<<endl<<"  1-book name"<<endl<<"  2-edition number"<<endl<<"  3-author name"<<endl<<"  4-shelf number"<<endl;
	cin>>c;
	if(c==1)
	{
		cout<<"enter name:"<<endl;
		cin>>b;
		while(i<total)
		{
			if(array[i].name==b)
			{
				cout<<"Book Name: "<<array[i].name<<endl<<"Edition No.: "<<array[i].edition<<endl<<"Author Name: "<<array[i].author<<endl<<"Shelf No.: "<<array[i].shelf;
				chk++;
				cout<<endl<<"    ****   "<<endl;
			}
			i++;
		}
		if(chk==0)
		{
			cout<<"sorry! no book found"<<endl;
		}
	}
	else if(c==2)
	{
		cout<<"enter edition:"<<endl;
		cin>>c;
		while(i<total)
		{
			if(array[i].edition == c)
			{
				cout<<"Book Name: "<<array[i].name<<endl<<"Edition No.: "<<array[i].edition<<endl<<"Author Name: "<<array[i].author<<endl<<"Shelf No.: "<<array[i].shelf;
				cout<<endl<<"    ****   "<<endl;
				chk++;
			}
			i++;
		}
		if(chk==0)
		{
			cout<<"sorry! no book found"<<endl;
		}
	}
	else if(c==3)
	{
		cout<<"enter name of author:"<<endl;
		cin>>b;
		while(i<total)
		{
			if(array[i].author==b)
			{
				cout<<"Book Name: "<<array[i].name<<endl<<"Edition No.: "<<array[i].edition<<endl<<"Author Name: "<<array[i].author<<endl<<"Shelf No.: "<<array[i].shelf;
				cout<<endl<<"    ****   "<<endl;
				chk++;
			}
			i++;
		}
		if(chk==0)
		{
			cout<<"sorry! no book found"<<endl;
		}
	}
	else if(c==4)
	{
		cout<<"enter shelf number:"<<endl;
		cin>>c;
		while(i<total)
		{
			if(array[i].shelf==c)
			{
				cout<<"Book Name: "<<array[i].name<<endl<<"Edition No.: "<<array[i].edition<<endl<<"Author Name: "<<array[i].author<<endl<<"Shelf No.: "<<array[i].shelf;
				cout<<endl<<"    ****   "<<endl;
				chk++;
			}
			i++;
		}
		if(chk==0)
		{
			cout<<"sorry! no book found"<<endl;
		}
	}
}
bool login(string a[])
{
	cout<<"Enter login username: ";
	string c;
	cin>>c;
	cout<<"Enter login password: ";
	string d;
	cin>>d;
	if(a[0]==c)
	{
		if(a[1]==d)
		{
			return true;
		}else{cout<<endl<<"   ! Incorrect username or password !"<<endl<<endl;
		login(a);
		}
	}
	else{
		cout<<endl<<"   ! Incorrect username or password !"<<endl<<endl;
		login(a);
	}
}
bool recep(string a[],int pass)
{
	cout<<"Enter your name with code:";
	string b;
	cin>>b;
	int i=2;
	while(i<pass)
	{
		if(a[i]==b)
		{
			return true;
			break;
		}
		i++;
	}
	if(i==pass)
	{
		cout<<endl<<"   ! Incorrect username or code !"<<endl<<endl;
		recep(a,pass);
	}
	
}
void Return(student arr[],books ar[],int &totlstd,int &total)
{
	string reg;
	cout<<"Enter your Registration Number:";
	cin>>reg;
	int i=0,j=0;
	while(i<totlstd)
	{
		if(reg == arr[i].REGno)
		{break;
		}
	}
	int c=i;
	totlstd=totlstd-1;
	ar[total].name;
	ar[total].edition;
	ar[total].author;
	ar[total].shelf;
	total++;
	i=0;
	while(i<totlstd)
	{
	if(i==c)
	{
		i++;
		continue;
	}
	arr[i].name=arr[j].name;
	arr[i].REGno=arr[j].REGno;
	arr[i].DUEdate=arr[j].DUEdate;
	arr[i].fine=arr[j].fine;
	arr[i].issued.name=arr[j].issued.name;
	arr[i].issued.edition=arr[j].issued.edition;
	arr[i].issued.author=arr[j].issued.author;
	arr[i].issued.shelf=arr[j].issued.shelf;
	i++;
	j++;
	}
}

		
		


