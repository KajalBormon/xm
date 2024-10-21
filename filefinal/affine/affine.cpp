
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int key1, key2,ciphercode;
    string plaintext,ciphertext,mainCipher, T, CipherText;

    char p[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

 //   cout<<"Enter the plaintext : ";

 //   getline(cin, plaintext);

 // input plaintext from file
    ifstream MyReadFile("input.txt");
    string myText;
    while (getline (MyReadFile, myText)) {
       plaintext = myText;
    }
MyReadFile.close();

// input two keys
    cout<<"Enter two key for Affine Cipher : ";
    cin>>key1>>key2;
    int len = plaintext.length();

    //check multiplicative inverse key is valid or not
    while(true){
        if(__gcd(26,key1)!=1)
        {
            cout<<"Invalid key1 !"<<endl<<"Please Enter a Valid key1: ";
            cin>>key1;
        }
        else
            break;
    }

    // Affine Cipher Encryption
    // multiplicative first
    for(int i=0;i<len;i++){
        for(int j=0;j<26;j++){
            if(plaintext[i]==p[j]){
                 ciphercode = ((j*key1)+key2)%26;
                break;
            }
        }
        if(plaintext[i]!=' ')
        {
            ciphertext+=c[ciphercode];
            CipherText+=c[ciphercode];
        }
        else
            CipherText+=' ';
    }


    cout<<endl<<"Affine Cipher Text : "<<ciphertext<<endl;



     // way to finding the inverse key
        int inverk, inverseCount = 1;
        while(true){
            if((key1*inverseCount)%26 == 1){
                inverk = inverseCount;
                break;
            }
            inverseCount++;
        }

        cout<<"inverse key: "<<inverk;


    //Affine cipher Decryption

    int plaincode;
    string newPlainText="";
    for(int i=0; i<CipherText.length(); i++){
        for(int j=0;j<26;j++){
            if(CipherText[i]==c[j]){
                if(j-key2<0)
                    plaincode = ((j-key2+26)*inverk)%26;
                else
                    plaincode = ((j-key2)*inverk)%26;
                break;
            }
        }
        if(CipherText[i]!=' ')
            newPlainText += p[plaincode];
        else
            newPlainText += ' ';

    }

    cout<<endl<<"Affine Decrypted Plain Text : "<<newPlainText<<endl;


return 0;
}

