#include<bits/stdc++.h>
using namespace std;
string encrypt(string &Plaintext, int key){
    string cipherText = "";
    int j = 0;
    for(int i = 0; i < Plaintext.size(); i++){
        cipherText += ((Plaintext[i] - 'a' + key) % 26) + 'a';
        key = Plaintext[i] - 'a';
    }
    return cipherText;
}
string decrypt(string &cipherText, int key){
    string Plaintext = "";
    int j = 0;
    for(int i=0; i<cipherText.size(); i++){
        Plaintext += ((cipherText[i] - 'a' - key + 26) % 26) + 'a';
        key = (cipherText[i] - 'a' - key + 26) % 26;
    }
    return Plaintext;
}
string Capital(string str){
    for(int i=0; i<str.size(); i++){
        str[i] = (char)(str[i] - 32);
    }
    return str;
}
string validation(string &str){
    string valid = "";
    for(int i = 0; i<str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z') valid += str[i];
        else if(str[i] >= 'A' && str[i] <= 'Z') valid += (str[i] + 32);
        else continue;
    }
    return valid;
}
int main(){
    string Plaintext, cipherText, ResultPlaintext;
    int key;
    cout<<"Input Your PlainText String: ";
    getline(cin, Plaintext);
    cout<<"Input Your Key: ";
    cin>>key;

    Plaintext = validation(Plaintext);
    cout<<endl<<"Your PlainText is: "<<Plaintext<<endl;

    cout<<endl<<"Encryption: ";
    cipherText = encrypt(Plaintext, key);
    cout<<"(Done)"<<endl;

    cout<<"CipherText (Encrypted Result) = "<<Capital(cipherText)<<endl<<endl;

    cout<<"Decryption: ";
    ResultPlaintext = decrypt(cipherText, key);
    cout<<"(Done)"<<endl;

    cout<<"Decryption Result Plaintext = "<<ResultPlaintext<<endl;
    return 0;
}
