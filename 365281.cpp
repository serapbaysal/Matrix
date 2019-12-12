#include <iostream> //Kutuphaneler tanimlandi
#include <stdlib.h>
#include<fstream>
#include <iostream>
#include <stdio.h>
#include<math.h>
using namespace std;

template<class T> //Template class olusturuldu
class Matrix     //Matrix sinifi tanimlandi
{
   public:
        Matrix();                      //Default constructor
        Matrix(int row,int col);       //Parametreli constructor
        Matrix(int row,int col,int deg);//
        Matrix(int row,int col,char harf);//
        Matrix<T> Transpose(); //Üye fonsiyonlar  (transpoz)
        Matrix<T>Inverse();   //(ters)
        Matrix<T> emul(Matrix);//Eleman düzeyinde carpma
        int Determinant(); //determinant
        void accept();// Kullanicidan matris alan fonksiyon
        void displayScreen();//Ekrana yazdirma
        void displayFile();//Dosyaya yazdirma
        void resize(int,int);//Boyut degistirme


                                // asiri yüklenmis operatorler
        Matrix<T> operator +(const Matrix<T> &mtrs);//(matris toplama)
        Matrix<T> operator +(const int num);//(scalar toplama)
        Matrix<T> operator -(const Matrix<T> &mtrs);// (matris cikarma)
        Matrix<T> operator -(const int num);//(scalar cikarma)
        Matrix<T> operator *(const Matrix<T> &mtrs);//(matris carpma)
        Matrix<T> operator *(const int num);//scalar carpma
        Matrix<T> operator /(const int num);//scalar bolme
        Matrix<T> operator %(const int num);//scalar mod
        Matrix<T> operator ^(const int num);//kuvvet
        Matrix<T> operator =(const int num);
       // virtual ~Matrix<T>();

    protected:
        int **p,m,n;//Veriler


    private:



};


template<class A>
class Table: public Matrix<int>//Table sinifi
{


    string **t; //veriler




public:
    Table();//Default constructor
    Table(int r,int c, int d);//Parametreli constructor
    Table(int,int,char);
    void print();//Ekrana yazdirma
    void print1();


};
template <class rgb>
class Image:public Matrix<int>//Image sinifi
{
    string baslik;   //veriler
    struct tur{
        int red;
        int green;
        int blue;
    };
public:
    Image(); //Default constructor
    Image(int width,int height);//Parametreli constructor
    void imread(string filename,string format);//Uye fonksiyon


};



template<class T>// satir ve sutun bilgisiyle
Matrix<T>::Matrix(int row,int col) //matris olusturan fonksiyon
{
   m=row;
   n=col;
   p=new int *[m];
   for(int i=0;i<m;i++){
    p[i]= new int [n];
   }

}
template<class T>
Matrix<T> :: Matrix(){//Default olarak matris olusturan fonksiyon
    m=10;
    n=10;
    p= new int *[m];//dinamik
     for (int i = 0; i < m; i++)//dizi
        p[i] = new int[n];//olusturma
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++){
                p[a][b]=0;
            }
        }


}
template<class T>//Satir sutun ve degerle
Matrix<T>:: Matrix(int row,int col,int deg){// matris olusturan fonksiyon
    m=row;
    n=col;

    p= new int *[m];
    for (int i = 0; i < m; i++)
        p[i] = new int[n];
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++){
                p[a][b]=deg;
                cout << " " <<p[a][b];
            }
            cout<< endl;
        }

}

template<class T>
Matrix<T>::Matrix(int row,int col,char harf){
    m=row;
    n=col;
    p= new int *[m];
    for (int i = 0; i < m; i++)
        p[i] = new int[n];
        if(harf=='e'){//Birim matris olusturma
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++){
                if(a==b){
                    p[a][b]=1;
                }
                if(a!=b){
                    p[a][b]=0;
                }
            }
        }


        }
        if(harf=='r'){//Random degerli matris olusturma
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++){
                    p[a][b]=rand()%255;

            }
        }



        }


}
template<class T>//Kullanicidan alinan degerlerle
void Matrix<T>::accept(){// matris olusturan fonksiyon
    cout<<"Enter matrix elements:";
       for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
             cin >> p[i][j];
          }
       }
}

template<class T>
void Matrix<T>::displayScreen(){//Ekrana yazdirma

       for(int i = 0; i < m; i++)
       {
          for(int j = 0; j < n; j++)
          {
             cout << " " <<  p[i][j];
          }
          cout << endl;
       }
}
template<class T>
void Matrix<T>::displayFile(){//Dosyaya yazdirma
   ofstream matris("Matris.txt",ios::app);

     for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            matris << " "<< p[i][j];
          }
          matris<< " " << endl;
       }


}
template <class T>
void Matrix<T>::resize(const int rows, const int cols){
    Matrix m1(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
                m1.p[i][j]=this->p[i][j];

        }
    }






}




template<class T>
Matrix<T> Matrix<T>::operator +(const Matrix<T> &m2){//Matris toplama
     Matrix sonuc(m, n);
     if(m==m2.m&&n==m2.n){
         for(int i = 0; i < m; i++)
       {
          for(int j = 0; j < n; j++)
          {
             sonuc.p[i][j] = p[i][j] + m2.p[i][j];
          }
     }

}
return sonuc;
}
template<class T>
Matrix<T> Matrix<T>::operator +(const int num)//scalar toplama
{
    Matrix sonuc(m,n);


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                sonuc.p[i][j]=p[i][j]+num;

        }
    }
    return sonuc;
}

template<class T>
Matrix<T> Matrix<T>::operator -(const int num){//scalar cikarma
    Matrix sonuc(m, n);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                sonuc.p[i][j]=p[i][j]-num;

        }
    }
    return sonuc;
}
template<class T>
Matrix<T> Matrix<T>:: operator -(const Matrix<T> &m2){//matris cikarma
    Matrix sonuc(m,n);
    if(m==m2.m&&n==m2.n){
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sonuc.p[i][j]=p[i][j] - m2.p[i][j];
        }
    }
    }

    return sonuc;
}

template<class T>
Matrix<T> Matrix<T>::operator  *(const Matrix<T> &m2){//matris carpma
 Matrix sonuc(m,m2.n);
 if(m2.m==n){
    for(int i = 0; i < m; i++)
       {
          for(int j = 0; j < m2.n; j++)
          {
              sonuc.p[i][j]=0;
              for(int k=0;k<n;k++){
                sonuc.p[i][j] = sonuc.p[i][j] + (p[i][k]*m2.p[k][j]);
              }

          }
 }
 }




return sonuc;


    }
template<class T>
Matrix<T> Matrix<T>::operator ^(const int num){//us alma
    Matrix<T> sonuc(m,m);
    if(m==n){

   for(int i = 0; i < m; i++)
       {
          for(int j = 0; j < n; j++)
          {
              sonuc.p[i][j]=0;
              for(int k=0;k<n;k++){
                sonuc.p[i][j] = sonuc.p[i][j] + (p[i][k]*p[k][j]);

              }


          }
 }

    }
    return sonuc;
}
template<class T>
Matrix<T> Matrix<T>::operator =(const int num){
    Matrix<T> sonuc(m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sonuc.p[i][j]=num;
        }
    }
    return sonuc;
    }


template<class T>
Matrix<T> Matrix<T> ::operator *(const int num){//scalar carpma
Matrix sonuc(m, n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sonuc.p[i][j]=p[i][j]*num;
        }
    }
    return sonuc;
}
template<class T>
Matrix<T> Matrix<T> ::operator /(const int num){//scalar bolme
    Matrix sonuc(m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sonuc.p[i][j]=p[i][j]/num;
        }
    }
    return sonuc;
}
template<class T>
Matrix<T> Matrix<T>::operator %(const int num){//mod alma
    Matrix sonuc(m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sonuc.p[i][j]=p[i][j]%num;
        }
    }
    return sonuc;
}
template<class T>
int Matrix<T>::Determinant(){
    int ratio,det;
    if(m==n){
        for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
              if(j>i)
			  {

              ratio = p[j][i]/p[i][i];
              for(int k = 0; k < n; k++){
                 p[j][k] -= ratio * p[i][k];
                        }
                 }
                     }
                       }
                 det = 1;
                  for(int a = 0; a < n; a++)
                      det *= p[a][a];

return det;
    }
    else{
        cout << "HATA!";
        return 0;
    }

}
template<class T>
Matrix<T> Matrix<T>::Transpose(){//Transpoz
    Matrix *m1=new Matrix<int>(n,m);


    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
          m1->p[i][j]=this->p[j][i];
    }
  }
 return *m1;
}
template<class T>
Matrix<T> Matrix<T>::emul(Matrix a){//eleman duzeyinde carpma

    Matrix sonuc(m,n,0);
    Matrix *s1=&sonuc;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sonuc.p[i][j]=this->p[i][j]*a.p[i][j];

        }
    }
    return *s1;
}

template <class T>
Matrix<T> Matrix<T>::Inverse(){//Ters
    if(m==n){
            Matrix matris(m,n,'e');//Ters alinirkan kullanilacak birim matris
    Matrix *m1=&matris;
    float d,k;
    for(int i=0;i<m;i++){//Gauss Jordan kullanilarak ters alma islemi
            d=p[i][i];
            for(int j=0;j<n;j++){
                p[i][j]=p[i][j]/d;
                matris.p[i][j]=matris.p[i][j]/d;
            }
            for(int x=0;x<m;x++){
                if(x!=i){
                    k=p[x][i];
                    for(int j=0;j<n;j++){
                        p[x][j]=p[x][j]-(p[i][j]*k);
                        matris.p[x][j]=matris.p[x][j]-(matris.p[i][j]*k);
                    }
                }
            }

    }

    return *m1;

    }



}

template<class A>
Table<A>::Table(){//default constructor ile tablo
    m=11;
    n=11;
    t= new string *[m];

    for (int i = 0; i < m; i++)
        t[i] = new string [n];

        t[0][0]=" ";//sutun isimleri
        t[0][1]=" A";
        t[0][2]="B";
        t[0][3]="C";
        t[0][4]="D";
        t[0][5]="E";
        t[0][6]="F";
        t[0][7]="G";
        t[0][8]="H";
        t[0][9]="I";
        t[0][10]="J";

        t[1][0]=" 1";//satir isimleri
        t[2][0]=" 2";
        t[3][0]=" 3";
        t[4][0]=" 4";
        t[5][0]=" 5";
        t[6][0]=" 6";
        t[7][0]=" 7";
        t[8][0]=" 8";
        t[9][0]=" 9";
        t[10][0]="10";
        for(int a=1;a<m;a++){
            for(int b=1;b<n;b++){
                t[a][b]="0";//deger


            }
        }

}
template<class A>

Table<A>::Table(int r,int c,int d){

    m=r;
    n=c;
    string harfler[]={"A","B","C","D","E","F","G","H","I",//Sutun isimlerinde
   "J","K","L","M","N","P","R","S","T","U","V","W","X","Y","Z"};//kullanilacak harflerin tutuldugu dizi
    char sayilar[100];//Satir isimlerinde ve degerde kullanilacak dizi
    for(int a=0;a<100;a++){
        sayilar[a]=a;
    }

    t= new string *[m];
    p=new int *[m];
    for (int i = 0; i < m; i++)
        t[i] = new string [n];
        for(int i=0;i<m;i++)
            p[i]= new int[n];
        for(int i=0;i<m;i++){
            t[0][i]=harfler[i];//Sutun isimleri
}

        for(int a=0;a<m;a++){
            for(int b=1;b<n;b++){
                    p[a][0]=sayilar[a];//satir isimleri

                        p[a][b]=sayilar[d];
                        }

        }
}
template<class A>
Table<A>::Table(int r,int c,char ch){
    m=r;
    n=c;
    if(ch=='r'){
        string harfler[]={"A","B","C","D","E","F","G","H",//Sutun isimleri icin
                          "I","J","K","L","M","N","P","R",
                          "S","T","U","V","W","X","Y","Z"};
    int sayilar[100];
    for(int a=0;a<100;a++){
        sayilar[a]=a;
    }



    t= new string *[m];
    p=new int *[m];
    for (int i = 0; i < m; i++)
        t[i] = new string [n];
        for(int i=0;i<m;i++)
            p[i]= new int[n];
        for(int i=0;i<m;i++){
            t[0][i]=harfler[i];
}

        for(int a=0;a<m;a++){
            for(int b=1;b<n;b++){
                    p[a][0]=sayilar[a];

                        p[a][b]=rand()%256;
                        }

        }
    }


}
template<class A>
void Table<A>::print(){// default constructor icin yazdirma


    for(int a=0;a<m;a++){
        for(int b=0;b<n;b++){
            cout<< " " << t[a][b];



        }

        cout << endl;

    }

}
template<class A>
void Table<A>::print1(){//Yazdirma


    for(int a=0;a<m;a++){
        for(int b=0;b<n;b++){
            cout<< " " <<p[a][b]<< t[a][b];



        }

        cout << endl;

    }

}


template<class rgb>
Image<rgb>::Image(){//Default constructor
     p= new string *[m];

    for (int i = 0; i < m; i++)
        p[i] = new string [n];
    m=255;
    n=255;
    tur pixel;
    p=new int *[m];
    for(int i=0;i<m;i++)
        p[i]=new int [n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            pixel.blue=0;//pixel degerleri
            pixel.green=0;
            pixel.red=0;
        }
    }


}

template<class rgb>
Image<rgb>::Image(int width,int height){//Parametreli constructor
    m=width;
    n=height;
    tur pixel;
    p=new int *[m];
    for(int i=0;i<m;i++)
        p[i]=new int [n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            pixel.blue=0;
            pixel.green=0;
            pixel.red=0;
        }
    }
}




int main()
{
   int secim;
   int secim2;
   cout<< "Matris(1):"<<endl;
   cout << "Tablo(2):"<<endl;
   cin >> secim2;
   if(secim2==1){
    Matrix<int> *m1=new Matrix<int>;
    Matrix<int> m2(3,2,1);
    Matrix<int> m3(3,4,9);


    Matrix<int> *m4=new Matrix<int>(5,5,'e');
    Matrix<int> *m5=new Matrix<int>(15,15,'r');
    Matrix<int> *m6=new Matrix<int>(3,3);


    cout << "m4:"<<endl;
    m4->displayScreen();
    m4->displayFile();
    cout<< "m5:"<<endl;
    m5->displayScreen();
    m5->displayFile();
    cout << "m6:";
    m6->accept();
    m6->displayScreen();
    m6->displayFile();



    cout << "Matrix-Matrix islemleri(1)"<< endl;
    cout << "Matrix-Scalar islemleri(2)"<< endl;
    cout << "Matrix islemleri(3)"<< endl;
    cout << "Yapmak istediginiz islem turunu seciniz."<<endl;
    cin >> secim;
    if(secim==1){
            Matrix<int> sonuc1;
            Matrix<int> sonuc2;
            Matrix<int> sonuc3;
            Matrix<int> m7(4,4,2);
            Matrix<int> m8(4,4,8);

            sonuc1=m7+m8;

            sonuc2=m7-m8;

            sonuc3=m7*m8;
            cout << "Toplama:"<<endl;
            sonuc1.displayScreen();
            sonuc1.displayFile();
            cout<< "Cikarma:"<<endl;
            sonuc2.displayScreen();
            sonuc2.displayFile();
            cout<< "Carpma:"<<endl;
            sonuc3.displayScreen();
            sonuc3.displayFile();






    }
    if(secim==2){
        Matrix<int> sonuc1;
        Matrix<int> sonuc2;
        Matrix<int> sonuc3;
        Matrix<int> sonuc4;
        Matrix<int> sonuc5;
        Matrix<int> sonuc6;
        Matrix<int> m9(5,5,2);

        sonuc1=m9+12;

        sonuc2=m9-20;

        sonuc3=m9*10;

        sonuc4=m9/10;

        sonuc5=m9%10;

        sonuc6=m9^2;
        cout << "Toplama:"<<endl;
        sonuc1.displayScreen();
        sonuc1.displayFile();
        cout << "Cikarma:"<< endl;
        sonuc2.displayScreen();
        sonuc2.displayFile();
         cout << "Carpma:"<< endl;
        sonuc3.displayScreen();
        sonuc3.displayFile();
        cout << "Bolme:"<< endl;
        sonuc4.displayScreen();
        sonuc4.displayFile();
        cout << "Mod:"<< endl;
        sonuc5.displayScreen();
        sonuc5.displayFile();
        cout << "Us:"<< endl;
        sonuc6.displayScreen();
        sonuc6.displayFile();
    }
    if(secim==3){
        Matrix<int> m7(5,5,'e');
        Matrix<int> m9(5,5,'r');

        Matrix<int> sonuc1;
        Matrix<int> sonuc2;
        Matrix<int> sonuc3;
        Matrix<int> sonuc4;
        sonuc1=m7.Transpose();
        sonuc2=m7.emul(m9);
        sonuc3=m7.Inverse();
        sonuc4=m7.Determinant();
        cout << "Transpoz:"<< endl;
        sonuc1.displayScreen();
        sonuc1.displayFile();
        cout << "Eleman duzeyinde carpma:"<< endl;
        sonuc2.displayScreen();
        sonuc2.displayFile();
        cout << "Ters:"<< endl;
        sonuc3.displayScreen();
        sonuc3.displayFile();
        cout << "Determinant:";
        sonuc4.displayScreen();
        sonuc4.displayFile();
        }
   }
    if(secim2==2){

        Table<int> nesne1;
        Table<int> nesne2(5,5,'r');
        Table<int> nesne3(3,4,9);
        nesne1.print();
        nesne2.print1();
        nesne3.print1();
    }







    return 0;
}
