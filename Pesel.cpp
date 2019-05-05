#include<iostream>
using namespace std;
class Pesel
{
	public:
	string pesel;
	Pesel(string p)
	{
		pesel=p;
	}
	void validatePESEL(Pesel &pesel1)
	{
		int suma,i;
		string rok,miesiac,dzien,x,y,plec,m=" mezczyzna ",k=" kobieta ";
		bool t=false;
		if(pesel.size()==11)
		{
			suma=((pesel[0]-48)*1)+((pesel[1]-48)*3)+((pesel[2]-48)*7)+((pesel[3]-48)*9)+((pesel[4]-48)*1)+((pesel[5]-48)*3)+((pesel[6]-48)*7)+((pesel[7]-48)*9)+((pesel[8]-48)*1)+((pesel[9]-48)*3)+((pesel[10]-48)*1);
			for(i=0;i<pesel.size();i++)
			{
				if(pesel[i]>47 and pesel[i]<58)
				{
					t=true;
				}
				else
				{
	             cout<<" Bledny pesel   nie same cyfry "<<endl;
	             t=false;
                 break;;
				}
			}
			if(t)
			{
				if(suma%10==0)
				{
					if(pesel[2]=='0' or pesel[2]=='1')
					{
						rok="19";
						x=pesel[0];
						y=pesel[1];
						rok=rok+x+y;
						x=pesel[2];
						y=pesel[3];
						miesiac=x+y;
						x=pesel[4];
						y=pesel[5];
						dzien=x+y;
						if(pesel[9]%2==0)
						plec=k;
						else
						plec=m;
						cout<<"Pesel "<<pesel<<" Rok "<<rok<<" Miesiac "<<miesiac<<" Dzien "<<dzien<<" Plec "<<plec<<endl;
					}
					else
					{
					rok="20";
						x=pesel[0];
						y=pesel[1];
						rok=rok+x+y;
						x=pesel[2];
						y=pesel[3];
						miesiac=x+y;
						if(miesiac[0]=='2')
						{
							miesiac[0]='0';
						}
						if(miesiac[0]=='3')
						{
							miesiac[0]='1';
						}
						x=pesel[4];
						y=pesel[5];
						dzien=x+y;
						if(pesel[9]%2==0)
						plec=k;
						else
						plec=m;
						cout<<"Pesel "<<pesel<<" Rok "<<rok<<" Miesiac "<<miesiac<<" Dzien "<<dzien<<" Plec "<<plec<<endl;	
					}
				}
				else
				{
					cout<<" Bledny pesel  zle suma kontrolna "<<endl;
				}			
			}
		}
		else
		{
			cout<<" Bledny pesel  zla dlugosc "<<endl;
		}
	}
	void wypisz()
	{
		cout<<pesel<<endl;
	}
};
int main()
{
	Pesel pesel1("99102205912");
	pesel1.wypisz();
	pesel1.validatePESEL(pesel1);
}
