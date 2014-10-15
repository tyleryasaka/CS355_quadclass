#include <iostream>
using namespace std;

//=============================================================================
//					-Pair (Class)-
//=============================================================================
class Pair{
protected:
    int x, y;
public:
    Pair() : x(0), y(0) {}
    Pair(int v1, int v2) : x(v1), y(v2) {}
    int GetX()const{return x;}
    int GetY()const{return y;}
    void SetX(int v){x = v;}
    void SetY(int v){y= v;}
    virtual void Set(int v1, int v2){x = v1; y = v2;}
    virtual void Print()const{cout << "[" << x << ", " << y << "]";}
};

//=============================================================================
//					-Triple (Class) (Derived from Pair)-
//=============================================================================
class Triple : public Pair{
    int z;
public:
    //Goes up through the (initialization)inheritance heirarchy, and then 
    //  goes back down through the curly braces 
    Triple(): z(0){}
    Triple(int v) : z(v){}
    Triple(int v1, int v2, int v3) : Pair(v1, v2), z(v3){}
    int GetZ()const {return z;}
    void SetZ(int v){z = v;}
    virtual void Set(int v1, int v2, int v3){
        Pair::Set(v1, v2);
        z = v3;
    }
    virtual void Print()const{
        cout << "[" << GetX() << ", " << GetY() << ", " << z << "]";
    }
};

//=============================================================================
//					-Quad (Class) (Derived from Triple)-
//=============================================================================
class Quad : public Triple {
    int w;
public:
    Quad() : w(0){}
    Quad(int v) : w(v){}
    Quad(int v1, int v2, int v3, int v4) : Triple(v1, v2, v3), w(v4){}
    int GetW()const {return w;}
    void SetW(int v){w = v;}
    void Set(int v1, int v2, int v3, int v4) {
        Triple::Set(v1, v2, v3);
        w = v4;
    }
    void Print()const {
        cout << "[" << GetX() << ", " << GetY() << ", " << GetZ() << ", " << w << "]";
    }
};

int main(){
    Pair * pairArray[5];
    int index = 0;
    int choice, x, y, z, w;
    
    do {
        cout << "1: Pair" << endl;
        cout << "2: Triple" << endl;
        cout << "3: Quad" << endl;
        cout << "4: Quit" << endl;
   
        cout << "\n>> "; 
        cin >> choice;   
        cout << endl;    
    
        switch (choice) {
            case 1 :
                cout << "Operating on 'Pair' in index " << index << endl;
                cout << "\nSet X: \n\n>> ";
                cin >> x;
                cout << "\nSet Y: \n\n>> ";
                cin >> y;
                cout << endl;
                pairArray[index] = new Pair(x, y);
                cout << "Printing Values..\n\n";
				pairArray[index]->Print();
                cout << endl << endl;
                break;
            case 2 :       
                cout << "Operating on 'Triple' in index " << index << endl;
                cout << "\nSet X: \n\n>> ";
                cin >> x;
                cout << "\nSet Y: \n\n>> ";
                cin >> y;
                cout << "\nSet Z: \n\n>> ";
                cin >> z;
                cout << endl;
                pairArray[index] = new Triple(x, y, z);
                cout << "Printing Values..\n\n";
                pairArray[index]->Print();
                cout << endl << endl;
                break;
            case 3 :
                cout << "Operating on 'Quad' in index " << index << endl;
                cout << "\nSet X: \n\n>> ";
                cin >> x;
                cout << "\nSet Y: \n\n>> ";
                cin >> y;
                cout << "\nSet Z: \n\n>> ";
                cin >> z;
                cout << "\nSet W: \n\n>> ";
                cin >> w;
                cout << endl;
                pairArray[index] = new Quad(x, y, z, w);
                cout << "Printing Values..\n\n";
                pairArray[index]->Print();
                cout << endl << endl;
                break;
        }
        index++;
    } while ((choice != 4) && (index < 5));
 
 	return 0;
}

