
#include<bits/stdc++.h>
using namespace std;
string encrypt(string &Plaintext, string keyStream){
    string cipherText = "";
    int j = 0;
    for(int i=0; i<Plaintext.size(); i++){
        cipherText += ((Plaintext[i] - 'a' + keyStream[j] - 'a') % 26) + 'a';
        j = (j+1) % keyStream.size();
    }
    return cipherText;
}
string decrypt(string &cipherText, string keyStream){
    string Plaintext = "";
    int j = 0;
    for(int i=0; i<cipherText.size(); i++){
        Plaintext += ((cipherText[i] - 'a' - keyStream[j] + 'a' + 26) % 26) + 'a';
        j = (j+1) % keyStream.size();
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
    string Plaintext, cipherText, ResultPlaintext, keyStream;
    cout<<"Input Your PlainText String: ";
    getline(cin, Plaintext);
    cout<<"Input Your Key stream (string): ";
    cin>>keyStream;

    Plaintext = validation(Plaintext);
    cout<<endl<<"Your PlainText is: "<<Plaintext<<endl;

    cout<<endl<<"Encryption: ";
    cipherText = encrypt(Plaintext, keyStream);
    cout<<"(Done)"<<endl;

    cout<<"CipherText (Encrypted Result) = "<<Capital(cipherText)<<endl<<endl;

    cout<<"Decryption: ";
    ResultPlaintext = decrypt(cipherText, keyStream);
    cout<<"(Done)"<<endl;

    cout<<"Decryption Result Plaintext = "<<ResultPlaintext<<endl;
    return 0;
}
