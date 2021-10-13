#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;
int main(){
    cout<<fixed<<setprecision(2);
    cout<<"how many items do you need? ";
    int x;
    cin>>x;
    int *items = new int[x];
    auto *price = new double[x];
    double sum = 0;
    for(int i = 0 ; i < x ; i++){
        while(true){
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"enter the numeric value: ";
                cout<<"Enter the price of item "<<++i<<':';
                cin>>price[i];
                cout<<"Enter the quantity of item "<<++i<<':';
                cin>>items[i];
                sum += price[i]*items[i];
                i--;
            }
            else{
                cout<<"Enter the price of item "<<i+1<<':';
                cin>>price[i];
                cout<<"Enter the quantity of item "<<i+1<<':';
                cin>>items[i];
                sum += price[i]*items[i];
                break;
            }
        }
    }
    double t;
    cout<<"enter the tax rate:";
    cin>>t;
    double tax = (t * sum)/100;
    cout<<"subtotal : "<<sum<<'$'<<endl;
    cout<<"tax : "<<tax<<'$'<<endl;
    cout<<"total : "<<tax + sum<<endl;
}
