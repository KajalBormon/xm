#include<bits/stdc++.h>
using namespace std;

int main(){

    int keySize, count=0;
    string plaintext,PlainText="", newPlaintext="", ciphertext="";
    char p[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
// input plaintext
    cout<<"Give a plaintext : ";
    getline(cin, plaintext);

    int len = plaintext.length();
//remove space
    for(int i=0; i<len; i++){
        if(plaintext[i]!=' '){
            PlainText+=plaintext[i];
        }
    }
    int length = PlainText.length();
//encryption :
    for(int i=0; i<length; i=i+2){
        ciphertext+=c[PlainText[i]-'A'-32];
    }

    for(int i=1; i<length; i=i+2){
        ciphertext+=c[PlainText[i]-'A'-32];
    }

    cout<<"Ciphertext : "<<ciphertext;


// decryption
    int half;
    if(length%2==0){
        half = length/2;
    }
    else{
        half = (length/2)+1;
    }
//cout<<endl<<half<<endl;
    for(int i=0; i<half; i++){
        newPlaintext+=p[32-('a'-ciphertext[i])];
        if((i+half)<length){
            newPlaintext+=p[32-('a'-ciphertext[i+half])];
        }

    }

    cout<<"Plaintext : "<< newPlaintext;

    return 0;
}
