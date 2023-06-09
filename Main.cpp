#include<iostream>
using namespace std;
class 	Tasit{
    string marka;
    int yil;
    int teker;
    public:
    	Tasit(){}
    	Tasit(string marka,int yil,int teker):marka(marka),yil(yil),teker(teker){}
    
    string getmarka(){
        return marka;
    }
    
    int getyil(){
        return yil;
    }
    
    int getteker(){
        return teker;
    }
    
    void setmarka(string marka){
        this->marka=marka;
    }
    
     void setyil(int yil){
        this->yil=yil;
    }
    
     void setteker(int teker){
        this->teker=teker;
    }
    
    void ekranaYazdir(){
        cout<<"TASITIN;"<<endl;
        cout<<"Marka: "<<getmarka()<<"\nUretim Yili: "<<getyil()<<"\nTekerlek Sayisi: "<<getteker()<<endl;
    }
};
class MotorluTasit:public Tasit{
    string model;
    int guc;
    public:
    	MotorluTasit(){}
    	MotorluTasit(string marka,int yil,int teker,string model,int guc):Tasit(marka,yil,teker),model(model),guc(guc){}
    
    string getmodel(){
        return model;
    }
    
    int getguc(){
        return guc;
    }
    
    void setmodel(string model){
        this->model=model;
    }
    
    void setguc(int guc){
        this->guc=guc;
    }
    void ekranaYazdir(){
        
        	MotorluTasit::ekranaYazdir();
        cout<<"Modeli: "<<getmodel()<<"Motor Gucu: "<<getguc()<<endl;
    }
    
};

class Otomobil:public 	MotorluTasit{
    int kapi;
    int yolcu;
    double hiz;
    public:
    
    Otomobil(string marka,int yil,int teker,string model,int guc,int kapi,int yolcu,double hiz):MotorluTasit(marka,yil,teker,model,guc),kapi(kapi),yolcu(yolcu),hiz(hiz){}
    Otomobil(){}
    int getkapi(){
        return kapi;
    }
    int getyolcu(){
        return yolcu;
    }
    double gethiz(){
        return hiz;
    }
    
    void setkapi(int kapi){
        this->kapi=kapi;
    }
    
    void setyolcu(int yolcu){
        this->yolcu=yolcu;
    }
    void sethiz(double hiz){
        this->hiz=hiz;
    }
    
    void ekranaYazdir(){
        	MotorluTasit::ekranaYazdir();
        cout<<"Yolcu Kapasitesi: "<<getyolcu()<<"\nKapi Sayisi: "<<getkapi()<<"\nSaatteki maksimum hizi: "<<gethiz()<<endl;
    }
    double sureHesapla(double yol){
        return yol/gethiz();
    }
    void dosyayaYazdir(){
        
    }
    
};

    Tasit TasitOlustur(){
        Tasit t1;
        cout<<"Tasit icin marka, model yili ve teker sayisi girin:"<<endl;
        string marka;
        int yil;
        int teker;
        getline(cin,marka);
        cin>>yil;
        cin>>teker;
        t1.setmarka(marka);
        t1.setyil(yil);
        t1.setteker(teker);
        
        return t1;
    }
     	MotorluTasit MotorluTasitOlustur(){
        MotorluTasit m1;
        cout<<"Motorlu tasit icin marka, model yili, teker sayisi, model ve motor gucu girin:"<<endl;
        string marka;
        int yil;
        int teker;
        string model;
        int guc;
        getline(cin,marka);
        cin>>yil;
        cin>>teker;
        getline(cin,model);
        cin>>guc;
        m1.setmarka(marka);
        m1.setyil(yil);
        m1.setteker(teker);
        m1.setmodel(model);
        m1.setguc(guc);
        
        return m1;
     }
     
        Otomobil OtomobilOlustur(){
        cout<<"Otomobil icin marka, model yili, teker sayisi, model, motor gucu, yolcu sayisi, kapı sayisi ve maksimum hiz girin:"<<endl;
        Otomobil o1;
        string marka;
        int yil;
        int teker;
        string model;
        int guc;
        int yolcu;
        int kapi;
        double hiz;
        getline(cin,marka);
        cin>>yil;
        cin>>teker;
        getline(cin,model);
        cin>>guc;
        cin>>yolcu;
        cin>>kapi;
        cin>>hiz;
        
        o1.setmarka(marka);
        o1.setyil(yil);
        o1.setteker(teker);
        o1.setmodel(model);
        o1.setguc(guc);
        o1.setyolcu(yolcu);
        o1.setkapi(kapi);
        o1.sethiz(hiz);
            
            return o1;
        }
     
     
    







int main(){
	cout << "Tasit olusturmak icin 1, "<< endl << "MotorluTasit olusturmak icin 2," << endl << "Otomobil olusturmak icin 3," << endl << "Gidilecek mesafeye gore sure hesaplamak icin 4," << endl << "Otomobil dosyaya yazdirmak icin 5," << endl << "Kodu sonlandirmak icin 6 giriniz." << endl << endl;
	int islem;
	Tasit T1;
	MotorluTasit MT1;
	Otomobil O1;

	while(1){
		cin >> islem;
		if(islem==1){
			T1 = TasitOlustur();
			T1.ekranaYazdir();
		}
		if(islem==2){
			MT1 = MotorluTasitOlustur();
			MT1.ekranaYazdir();
		}
		if(islem==3){
			O1 = OtomobilOlustur();
			O1.ekranaYazdir();
		}
		if(islem==4){
			int mesafe;
			cout << "Gidilecek mesafeyi girin: " << endl;
			cin >> mesafe;
			cout << "Otomobil " << mesafe << " km yolu " <<  O1.sureHesapla(mesafe) << " saatte gidebilir." << endl;
		}
		if(islem==5){
			O1 = OtomobilOlustur();
			O1.dosyayaYazdir();
		}
		if(islem==6){
		    cout << "Kod sonlandirildi.";
			break;
		}
		cout << endl << "Tasit olusturmak icin 1, "<< endl << "MotorluTasit olusturmak icin 2," << endl << "Otomobil olusturmak icin 3," << endl << "Gidilecek mesafeye gore sure hesaplamak icin 4," << endl << "Otomobil dosyaya yazdirmak icin 5," << endl << "Kodu sonlandirmak icin 6 giriniz." << endl << endl;
	}
	return 0;
}
