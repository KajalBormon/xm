
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char p[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[]={'N','O','A','T','R','B','E','C','F','U','X','D','Q','G','Y','L','K','H','V','I','J','M','P','Z','S','W'};
    string plaintext, newPlaintext, ciphertext="", CipherText="";

//    cout<<"Enter the plaintext : ";
//    getline(cin, plaintext);


// read plaintext from file
    ifstream MyReadFile("input.txt");
    string myText;
    while (getline (MyReadFile, myText)) {
       plaintext = myText;
    }

MyReadFile.close();


    int len = plaintext.length();




    //encryption
    int cipher;
    for(int i=0; i<len; i++){
        for (int j = 0; j < 26; ++j) {
            if (plaintext[i]==p[j]) {
                cipher = j;
            }
        }
        if(plaintext[i]!=' '){
            ciphertext+=c[cipher];
            CipherText+=c[cipher];
        }
        else{
            CipherText+=' ';
        }

    }

    cout<<"Ciphertext : "<<ciphertext<<endl;

    // decryption
    int plain;
    for(int i=0; i<len; i++){
        for (int j = 0; j < 26; ++j) {
            if (CipherText[i]==c[j]) {
                plain = j;
            }
        }
        if(plaintext[i]!=' '){
            newPlaintext+=p[plain];

        }
        else{
            newPlaintext+=' ';
        }

    }
    cout<<"Decrypted plaintext : "<<newPlaintext<<endl;

return 0;
}
