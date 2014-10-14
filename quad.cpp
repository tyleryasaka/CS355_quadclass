#include <iostream>
using namespace std;

class Pair{
protected:
    int x, y;
public:
    Pair():x(0),y(0) {}
    Pair(int v1, int v2):x(v1), y(v2) {}
    int GetX()const{return x;}
    int GetY()const{return y;}
    void SetX(int v){ x = v;}
    void SetY(int v){ y = v;}
    virtual void Set(int v1, int v2){x=v1;y=v2;}
    void Print()const{cout << "[" << x << "," << y << "]";}
    
};

class Triple : public Pair{
protected:
    int z;
public:
    Triple(): z(0){}
    Triple(int v):z(v){}
    Triple(int v1, int v2, int v3):Pair(v1,v2),z(v3){}
    int GetZ()const {return z;}
    void SetZ(int v){z=v;}
    virtual void Set(int v1, int v2, int v3){
        Pair::Set(v1,v2);
        z=v3;
    }
    void Print()const{
        cout << "[" << GetX() << "," << GetY() << "," << z << "]";
    }
};

class Quad : public Triple{
    int w;
public:
    Quad(): w(0){}
    Quad(int v):w(v){}
    Quad(int v1, int v2, int v3, int v4):Triple(v1,v2,v3),w(v4){}
    int GetW()const {return w;}
    void SetW(int v){w=v;}
    void Set(int v1, int v2, int v3, int v4){
        Triple::Set(v1,v2,v3);
        w=v4;
    }
    void Print()const{
        cout << "[" << GetX() << "," << GetY() << "," << GetZ() << "," << w << "]";
    }



};

int main() {
    
    Pair p1;
    Pair* ptrarr[5];
    int choice = -1;
    int x;
    int y;
    int z;
    int w;

    for(int i=0; i<5; i++){
        while(choice < 2 || choice > 4){
            cout<<"2: For ordered pair\n3: For triple\n4: For Quad\n";
            cin>>choice;
        }

        if(choice == 2){
            Pair temp;
            ptrarr[i] = &temp;
            cout<<"Enter x: ";
            cin>>x; 
            cout<<"Enter y: ";
            cin>>y;
            ptrarr[i]->Set(x,y);
        }

        else if(choice == 3){
            Triple temp3;
            ptrarr[i] = &temp;
            cout<<"Enter x: ";
            cin>>x; 
            cout<<"Enter y: ";
            cin>>y;
            cout<<"Enter z: ";
            cin>>z;
            ptrarr[i]->Set(x,y,z);
        }

        else if(choice == 4){
            Quad temp4;
            ptrarr[i] = &temp;
            cout<<"Enter x: ";
            cin>>x; 
            cout<<"Enter y: ";
            cin>>y;
            cout<<"Enter z: ";
            cin>>z;
            cout<<"Enter w: ";
            cin>>w;
            ptrarr[i]->Set(x,y,z,w);
        }


        



        choice = -1;
        
    }

    return 0;
}
