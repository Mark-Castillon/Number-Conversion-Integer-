#include <iostream>
#include <stdio.h>
#include<string>
#include<vector>
#include<sstream>
#include<limits>
#include<algorithm>
#include<stack>
#include<math.h>
using namespace std;
//--------------------------------------------
class check{
	public:
		static bool binary(string binary){
			int len = binary.length();
			if(len > 64) return 0;
			for(int i = 0 ; i < len ;i++)
				if(!(binary[i] == '0'||binary[i] == '1'))
					return 0;
			return 1;
		}
		static bool decimal(string decimal){
			int len = decimal.length();
			if(len > 18 )return 0;
			for(int i = 0 ; i < len ; i++)
				if(!(decimal[i] >= '0' && decimal[i] <= '9'))
					return 0;

			return 1;
		}
		static bool hexadecimal(string hexadecimal){
			int len = hexadecimal.length();
			if(len > 12) return 0;
			for(int i = 0 ; i < len ; i++)
				if(!(hexadecimal[i] >= '0' && hexadecimal[i] <= '9') && !(hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F'))
					return 0;
			return 1;
		}
		static bool octal(string octal){
			int len = octal.length();
			if(len > 21) return 0;
			for(int i = 0 ; i < len ; i++)
				if(!(octal[i] >='0' && octal[i] <='7'))
					return 0;
			return 1;
		}
};
//--------------------------------------------
void binarytodecimal( string binary ){

	long long decimal = 0, base_val = 1, len = binary.length() ;

	for (int i = len - 1; i >= 0; i--,base_val*=2)
		if(binary[i]=='1')
			decimal += base_val;

	cout << decimal << "\n" ;

}
void decimaltobinary( long long decimal ){

	vector<bool> binary (64) ;
	int idx=0;

	while (decimal > 0){

		binary[idx] = decimal & 1;
		decimal >>= 1;
		idx++;

	}
	idx--;
	while(idx >= 0)
		cout << binary[idx--] ;
	cout << "\n";

}
void octaltodecimal( long long octal ){


	long long decimal = 0, base_val = 1 ;

	while(octal){

		decimal += ( octal % 10 ) * base_val;
		octal /= 10	;
		base_val *= 8;

	}

	cout << decimal << "\n";

}
void decimaltooctal( long long decimal ){


	vector<int> octal (22);
	int idx = 0;

	while(decimal){

		octal[idx] = decimal % 8;
		decimal >>= 3;
		idx++;

	}
	idx--;
	while(idx >= 0)
		cout << octal[idx--] ;
	cout << "\n";

}
//--------------------------------------------
char singleDigitPreprocees(int n)
{
    if(n<10) return n+'0';
    else if(n >= 10){
        return 'A'+(n-10);
    }
}
int toDecimal(string number,int base )
{
    int ans = 0;
    int size = number.length();

    for(int i=0;i<size;i++)
    {
        if(number[i]>='A')
        {
            ans += (number[i]-'A'+10) *pow(base,size-i-1);
        }
        else
        {
            ans += (number[i]-'0') *pow(base,size-i-1);
        }
    }
    return ans;
}
string decimalTo(int decimal,int base = 16)
{
    stack<char> remainders;
    if(decimal == 0) return "0";
    while(decimal > 0)
    {
        char rem = singleDigitPreprocees(decimal%base);
        decimal = decimal/base;
        remainders.push(rem);
    }

    string ans = "";
    while(!remainders.empty())
    {
        ans += remainders.top();
        remainders.pop();
    }
    return ans;
}
string binaryToOctal(string binary)
{
    int size = binary.length();
    int index = size-1;

    stack<char> oct;

    while(index >= 0)
    {
        string substring;
        if(index-0 < 3)
        {
            substring = binary.substr(0,index+1);
        }
        else
        {
            substring = binary.substr(index-2,3);
        }

        index-=3;
        int dec = toDecimal(substring,2);
        oct.push(dec+'0');
    }

    string octal = "";
    while(!oct.empty())
    {
        octal += oct.top();
        oct.pop();
    }
    return octal;
}
string octalToBinary(string octal)
{
    int size = octal.length();
    string binary="";
    for(int i=0;i<size;i++)
    {
        string x= "";
        if(x.length()<3)
        {
            if(x.length()==1)
                x = "00"+x;
            else{
                x = "0"+x;
            }
        }
        binary += x;
    }
    return binary;
}
//--------------------------------------------
void binarytoHex(int n){
    int s=0;
    int i=1;
    int j=0;
    char hexanum[100];
    while(n>0){
        int r=n%10;
        s=s+r*i;
        n/=10;
        i*=2;
    }

    while(s>0){
        int r1=s%16;
        if(r1<10){
            hexanum[j]=r1+48;
            j++;
        }
        else{
            hexanum[j]=r1+55;
            j++;
        }
        s/=16;

    }
    for(int k=j-1; k>=0; k--)
        cout << hexanum[k];

}
void hex2binary(string hex){
    int result = 0;
    for (int i=0; i<hex.length(); i++) {
        if (hex[i]>=48 && hex[i]<=57)
        {
            result += (hex[i]-48)*pow(16,hex.length()-i-1);
        } else if (hex[i]>=65 && hex[i]<=70) {
            result += (hex[i]-55)*pow(16,hex.length( )-i-1);
        }
    }
    int binary[32];
    int i = 0;
    while (result > 0) {
        binary[i] = result % 2;
        result/= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << binary[j];

}
void octaltohex(int n){
    int s=0;
    int i=1;
    int j=0;
    char hexanum[100];
    while(n>0){
        int r=n%10;
        s=s+r*i;
        n/=10;
        i*=8;
    }

    while(s>0){
        int r1=s%16;
        if(r1<10){
            hexanum[j]=r1+48;
            j++;
        }
        else{
            hexanum[j]=r1+55;
            j++;
        }
        s/=16;

    }
    for(int k=j-1; k>=0; k--)
        cout << hexanum[k];
}
void hex2octal(string hex){
    int result = 0;
    for (int i=0; i<hex.length(); i++) {
        if (hex[i]>=48 && hex[i]<=57)
        {
            result += (hex[i]-48)*pow(16,hex.length()-i-1);
        } else if (hex[i]>=65 && hex[i]<=70) {
            result += (hex[i]-55)*pow(16,hex.length( )-i-1);
        }
    }
    int octal[32];
    int i = 0;
    while (result > 0) {
        octal[i] = result % 8;
        result/= 8;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << octal[j];

}
//--------------------------------------------
void binarytodecimal ( string binary );
void decimaltobinary ( long long decimal );
void octaltodecimal ( long long octal );
void decimaltooctal ( long long decimal );
//--------------------------------------------
char singleDigitPreprocees(int n);
string decimalTo(int decimal,int base);
int toDecimal(string number,int base);
string binaryToOctal(string binary);
string octalToBinary(string octal);
//--------------------------------------------
void binarytoHex(int n);
void hex2binary(string hex);
void octaltohex(int n);
void hex2octal(string hex);
//--------------------------------------------
int display_menu(){
	system("cls");
	cout<<"\n\n\t\t\t NUMBER CONVERSION SYSTEM\n\n";
	cout<<"\t\t===========================================\n\n";
	cout<<"\t\t\t1. Binary to Decimal\n\n\t\t\t2. Decimal to Binary\n\n\t\t\t3. Octal to Decimal\n\n\t\t\t4. Decimal to Octal\n\n";
	cout<<"\t\t\t5. Decimal to Hexadecimal\n\n\t\t\t6. Hexadecimal to Decimal\n\n\t\t\t7. Binary to Octal\n\n\t\t\t8. Octal to Binary\n\n";
	cout<<"\t\t\t9. Binary to Hexadecimal\n\n\t\t\t10. Hexadecimal to Binary\n\n\t\t\t11. Octal to Hexadecimal\n\n\t\t\t12. Hexadecimal to Octal\n\n";
	cout<<"\t\t\t13. Exit\n\n";
	cout<<"    SELECT OPTION : \t";
}
inline void input_prompt(string original,string modified){
	cout << "\n\n\t\t"<< original << " to " << modified << " Conversion\n\n";
	cout << "\tEnter " << original <<" number to convert it into its " << modified << " equivalent:\n\t";
}
inline void output_prompt(string res){
	cout << "\n\tEquivalent "<< res <<" number : ";
}
inline void error(){
	cout << "\n\tIncorrect input format !";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
inline void pause(){

	cout<<"\n\tPress Enter to continue...";
	getchar();
}
int main(){
	system("MODE CON COLS=80 LINES=45");
	int option;
	do{
		display_menu();
		cin >> option;
		while(cin.fail()){
			cout<<"\n\tIncorrect option !";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press Enter to continue...";
			getchar();
			display_menu();
			cin >> option;

		}
		switch(option){
			case 1 : {
				system("cls");
				string binary;
				input_prompt("Binary","Decimal");
				cin.ignore();
				getline(cin, binary);
				if(!check::binary(binary))
					error();
				else{
					output_prompt("Decimal");
					binarytodecimal(binary);
				}
				pause();
				break;
			}
			case 2 : {
				system("cls");
				string decimal;
				input_prompt("Decimal","Binary");
				cin.ignore();
				getline(cin, decimal);
				if( cin.fail()||!check::binary(decimal))
					error();
				else{
					output_prompt("Binary");
					int decimalNum;
					istringstream iss(decimal);
					iss>>decimalNum;
					decimaltobinary(decimalNum);
				}
				pause();
				break;
			}
			case 3 : {
				system("cls");
				string octal;
				input_prompt("Octal","Decimal");
				cin.ignore();
				getline(cin, octal);
				if(cin.fail()||!check::octal(octal))
					error();
				else{
					output_prompt("Decimal");
					long long octalNum;
					istringstream iss(octal);
					iss >> octalNum;
					octaltodecimal(octalNum);
				}
				pause();
				break;
			}
			case 4 : {
				system("cls");
				string decimal;
				input_prompt("Decimal","Octal");
				cin.ignore();
				getline(cin, decimal);
				if(cin.fail()||!check::decimal(decimal))
					error();
				else{
					output_prompt("Octal");
					long long decimalNum;
					istringstream iss(decimal);
					iss >> decimalNum;
					decimaltooctal(decimalNum);
				}
				pause();
				break;
			}
			case 5 : {
				system("cls");
				string decimal;
				input_prompt("Decimal","Hexadecimal");
				cin.ignore();
				getline(cin, decimal);
				if(cin.fail()||!check::decimal(decimal))
					error();
				else{
					output_prompt("Hexadecimal");
					int decimalNum;
					istringstream iss(decimal);
					iss >> decimalNum;
					cout << decimalTo(decimalNum,16);
				}
				pause();
				break;
			}
			case 6 : {
				system("cls");
				string hexadecimal;
				input_prompt("Hexadecimal","Decimal");
				cin.ignore();
				getline(cin, hexadecimal);
				if(!check::hexadecimal(hexadecimal))
					error();
				else{
					output_prompt("Hexadecimal");
					cout << toDecimal(hexadecimal,16);

				}
				pause();
				break;
			}
			case 7 : {
				system("cls");
				string binary;
				input_prompt("Binary","Octal");
				cin.ignore();
				getline(cin, binary);
				if(!check::binary(binary))
					error();
				else{
					output_prompt("Octal");
					cout << binaryToOctal(binary);
				}
				pause();
				break;
			}
			case 8 : {
				system("cls");
				string octal;
				input_prompt("Octal","Binary");
				cin.ignore();
				getline(cin, octal);
				if(cin.fail()||!check::octal(octal))
					error();
				else{
					output_prompt("Binary");
					cout << octalToBinary(octal);
				}
				pause();
				break;
			}
			case 9 : {
				system("cls");
				string binary;
				input_prompt("Binary","Hexadecimal");
				cin.ignore();
				getline(cin, binary);
				if(!check::binary(binary))
					error();
				else{
					output_prompt("Hexadecimal");
					istringstream iss(binary);
					int binaryNum;
					iss >> binaryNum ;
					binarytoHex(binaryNum);
				}
				pause();
				break;
			}
			case 10 : {
				system("cls");
				string hexadecimal;
				input_prompt("Hexadecimal","Binary");
				cin.ignore();
				getline(cin, hexadecimal);
				if(!check::hexadecimal(hexadecimal))
					error();
				else{
					output_prompt("Binary");
					hex2binary(hexadecimal);
				}
				pause();
				break;
			}
			case 11 : {
				system("cls");
				string octal;
				input_prompt("Octal","Hexadecimal");
				cin.ignore();
				getline(cin, octal);
				if(cin.fail()||!check::octal(octal))
					error();
				else{
					output_prompt("Hexadecimal");
					int octalNum;
					istringstream iss(octal);
					iss >> octalNum;
					octaltohex(octalNum);
				}
				pause();
				break;
			}
			case 12 : {
				system("cls");
				string hexadecimal;
				input_prompt("Hexadecimal","Octal");
				cin.ignore();
				getline(cin, hexadecimal);
				if(!check::hexadecimal(hexadecimal))
					error();
				else{
					output_prompt("Octal");
					hex2octal(hexadecimal);
				}
				pause();
				break;
			}
			default :
				cout<<"\n\tBye !  :)";
				break;
		}
	}while(option != 13);
}
