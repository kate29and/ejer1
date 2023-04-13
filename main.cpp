#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;
void metodo1(string& bin,int s);
void metodo2(string& bin,int s);
void codificar(string& blo) ;
void prime(string& blo, int i);
void dec(string& bl);

int main() {

    string nom;
    cout<<"Ingresa el archivo de entrada ";
    cin>>nom;
    ifstream inputFile(nom);
    string bin;
    char c;

    while (inputFile.get(c)) {
        bin+=c;
    }

    int n=0,s=0;
    cout<<"Ingresa  semilla ";
    cin>>s;
    inputFile.close();

    cout<<"Ingresa el metodo de decodificacion 1 o 2: ";
    cin>>n;
    if (n==1){
        metodo1(bin, s);
    }
    else if (n==2){
        metodo2(bin, s);
    }
     cout<<bin;

}

void metodo1(string& bin,int n) {

    ofstream outputFile("metodo1.txt"); // modo escritura
    string bl;
    if (!outputFile) {
        cout << "Error al crear archivo de salida" << endl;
    }
    int num0= 0, num1 = 0;
    string blo = bin.substr(0, n); //crear la primera subcadena
    for (int j = 0; j+n<= (bin.length()); j += n){

        string blo1 = bin.substr(j+n, n);//crear la segunda subcadena
        if (j<=n-1) {

            for (int i = 0; i < n; i++) {
                prime(blo, i);
            }

            bl+=blo;
        }
        for (int i = 0; i < blo.length(); i++) {
            if (blo[i] == '1') {
                num1++;
            }
            else if (blo[i] == '0'){
                num0++;
            }
        }
        if ((num1==num0)) {
            for (int i = 0; i < n; i++) {
                prime(blo1, i);
            }
            bl+=blo1;
        }
        else if (num0 > num1) {
            for (int i = 1; i <n; i += 2) {
                prime(blo1,i);
            }
            bl+=blo1;
        }
        else if (num1> num0){
            for (int i = 2; i < n; i += 3) {
                prime(blo1,i);
            }
            bl+=blo1;

        }
        num0= 0;
        num1 = 0;
        blo=blo1;

    }
    dec(bl);
    outputFile.write(bl.c_str(), bl.size());
    outputFile.close();
}

void metodo2(string& bin,int n) {
    ofstream outputFile("metodo2.txt"); // modo escritura
    string bl;
    if (!outputFile) {
        cout << "Error al crear archivo de salida" << endl;
    }


    for (int j = 0; j+n<= (bin.length()); j += n){
        string blo = bin.substr(j, n); //crear la primera subcadena

        for(int i=0;i<n;i++){
            if(i!=n-1){
                bl+=blo[i+1];
            }
            else {
                bl+=blo[0];
            }
        }
    }
    outputFile.write(bl.c_str(), bl.size());
    dec(bl);
    outputFile.close();
}

void dec(string& bl){
    ofstream outputFile("texto.txt"); // modo escritura
    if (!outputFile) {
        cout << "Error al crear archivo de salida" << endl;
    }
    string ascii="";
    for (int i = 0; i < bl.size(); i += 8) {
        bitset<8> bits(bl.substr(i, 8));
        char c = char(bits.to_ulong());
        ascii += c;
    }
    cout << ascii << endl;
    outputFile.write(ascii.c_str(), ascii.length());
    outputFile.close();
}



void prime(string& blo, int i){
    if (blo[i]=='0'){
        blo[i]='1';

    }
    else if(blo[i]=='1'){
        blo[i]='0';
    }
}
