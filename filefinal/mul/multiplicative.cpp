

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int key,ciphercode;
    string plaintext,ciphertext, mainCipher;

    char p[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

 //   cout<<"Enter the plaintext : ";

 //   getline(cin, plaintext);



 // Read from the text file
ifstream MyReadFile("input.txt");
string myText;
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
  // Output the text from the file
       plaintext = myText;
}

// Close the file
MyReadFile.close();



    cout<<"Enter the key : ";
    cin>>key;
    int len = plaintext.length();

    // check multiplicative is possible or not
    while(true){
        if(__gcd(26,key)!=1)
        {
            cout<<"Invalid key!"<<endl<<"Please Enter a Valid key: ";
            cin>>key;
        }
        else
            break;
    }



    // Encryption
    for(int i=0;i<len;i++){
        for(int j=0;j<26;j++){
            if(plaintext[i]==p[j]){
                 ciphercode = (j*key)%26;
                break;
            }
        }
        if(plaintext[i]!=' '){
            ciphertext+=c[ciphercode];
            mainCipher+=c[ciphercode];
        }

        else
            ciphertext+=' ';
    }

    cout<<endl<<"Cipher : "<<mainCipher<<endl;


    // Decryption
    int q, r1=26, r2=key, r, t1=0, t2=1, t, inverk;

//finding inverse key
 /*       while(r2!=0){
            q=r1/r2;
            r=r1%r2;
            t=t1-(q*t2);

            r1=r2;
            r2=r;
            t1=t2;
            t2=t;

        }
        if(inverk<0)
            inverk = t1+t2;
        else
            inverk = t1;
 */
        // another way to finding the inverse key
        int inverseCount = 1;
        while(true){
            if((key*inverseCount)%26 == 1){
                inverk = inverseCount;
                break;
            }
            inverseCount++;
        }

        cout<<"inverse key: "<<inverk;

       // decryption
        string newPlaintext;
        int plaincode;
        for(int i=0;i<ciphertext.length();i++){
        for(int j=0;j<26;j++){
            if(ciphertext[i]==c[j]){
                 plaincode = (j*inverk)%26;
                break;
            }
        }
        if(ciphertext[i]!=' ')
            newPlaintext+=p[plaincode];
        else
            newPlaintext+=' ';
    }
    cout<<endl<<"Decrypted Plaintext : "<<newPlaintext<<endl;



return 0;
}
