
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int key1, key2,ciphercode;
    string plaintext,ciphertext,mainCipher, T;

    char p[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    cout<<"Enter the plaintext : ";

    getline(cin, plaintext);

    cout<<"Enter two key for Affine Cipher : ";
    cin>>key1>>key2;
    int len = plaintext.length();

    // Affine Cipher Encryption
    // multiplicative first
    for(int i=0;i<len;i++){
        for(int j=0;j<26;j++){
            if(plaintext[i]==p[j]){
                 ciphercode = (j*key1)%26;
                break;
            }
        }
        if(plaintext[i]!=' ')
            ciphertext+=p[ciphercode];
        else
            ciphertext+=' ';
    }

   // cout<<endl<<"Multiplicative Cipher : "<<ciphertext<<endl;

    T = ciphertext;

   // cout<<"next plain text T : "<<T<<endl;

    //Additive second
    string CipherText="";

    for(int i=0;i<T.length();i++){
        for(int j=0;j<26;j++){
            if(T[i]==p[j]){
                 ciphercode = (j+key2)%26;
                break;
            }
        }
        if(T[i]!=' '){
            CipherText+=c[ciphercode];
            mainCipher+=c[ciphercode];
        }
        else
            CipherText+=' ';
    }

    cout<<endl<<"Affine Cipher Text : "<<mainCipher<<endl;





    //Affine cipher Decryption

     // Additive first 
    int plaincode;
    string addCipherText="";
    for(int i=0; i<CipherText.length(); i++){
        for(int j=0;j<26;j++){
            if(CipherText[i]==c[j]){
                if(j-key2<0)
                    plaincode = (j-key2+26)%26;
                else
                    plaincode = (j-key2)%26;
                break;
            }
        }
        if(CipherText[i]!=' ')
            addCipherText += c[plaincode];
        else
            addCipherText += ' ';
  
    }


// multiplicative second
    int q, r1=26, r2=key1, r, t1=0, t2=1, t, inverk;
    //cout<<__gcd(26,7);
    if(__gcd(26,key1)!=1)
        cout<<"Multiplicative decryption is not possible"<<endl;
    else{
        while(r2!=0){
            q=r1/r2;
            r=r1%r2;
            t=t1-(q*t2);

            r1=r2;
            r2=r;
            t1=t2;
            t2=t;

        }
        inverk = t1+t2;
        cout<<inverk;

        string finalPlaintext="";
        int PlainCode;
        for(int i=0;i<addCipherText.length();i++){
        for(int j=0;j<26;j++){
            if(addCipherText[i]==c[j]){
                 PlainCode = (j*inverk)%26;
                break;
            }
        }
        if(addCipherText[i]!=' ')
            finalPlaintext+=p[PlainCode];
        else
            finalPlaintext+=' ';
    }
    cout<<endl<<"Affine Decrypted Plain Text : "<<finalPlaintext<<endl;

    }


return 0;
}
