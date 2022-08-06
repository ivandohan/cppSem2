#include <iostream>
#define PI 3.14
using namespace std;


class BangunGeometri
{
protected:
    float volume; 
    float area;   
public:
    BangunGeometri()
    {
        volume = 0;
        area = 0;
    }; 
   

    virtual void countVolume();                
    virtual void countArea();                  
    virtual float getArea() { return volume; }; 
    virtual float getVolume() { return area; }; 
};
void BangunGeometri::countVolume()
{
    cout << "ini fungsi dasar countVolume" << endl;
}

void BangunGeometri::countArea()
{
    cout << "ini fungsi dasar countArea";
}

class cube : public BangunGeometri
{
private:
    float side;

public:
    cube(float side) { this->side = side; }
    ~cube() {}
    void countVolume() 
    {
        volume = side * side * side;
    }
    void countArea() 
    {
        area = side * side;
    }
    float getVolume() 
    {
        cout << "Volume Kubus :" << volume << endl;
      
    }
    float getArea() 
    {
        cout << "Luas Kubus : " << area << endl;
     
    }
};

class prism : public BangunGeometri
{
private:
    float length, widht, height;

public:
    prism(float l, float w, float h)
    {
        length = l;
        widht = w;
        height = h;
    }
    ~prism() {}
    void countVolume() 
    {
        volume = length * widht * height;
    }
    void countArea()
    {
        area = 2 * (length * widht + length * height + widht * height);
    }
    float getVolume() 
    {
        cout << "Volume Balok :" << volume << endl;
    }
    float getArea()
    {
        cout << "Luas Balok : " << area << endl;
    }
};

class sphere : public BangunGeometri
{
private:
    float radius;

public:
    sphere(float r) { radius = r; }
    ~sphere() {}
    void countVolume() 
    {
        volume = (4 * 1.0 / 3) * PI * radius * radius * radius;
    }
    void countArea() 
    {
        area = 4 * PI * radius * radius;
    }
    float getVolume() 
    {
        cout << "Volume Bola :" << volume << endl;
        
    }
    float getArea()
    {
        cout << "Luas Bola : " << area << endl;
      
    }
};

int main(int argc, char const *argv[])
{
    BangunGeometri *poly;
    cube a(8);
    sphere b(12);
    prism c(2, 4, 3);

    cout << "Cube:" << endl;
    /// cube
    poly = &a;         
    poly->countArea(); 
                    
    poly->countVolume();
    poly->getArea();
    poly->getVolume();
   
      
    // sphere
    
    poly = &b;
    poly->countArea();
    poly->countVolume();
    poly->getArea();
    poly->getVolume();
   
      
    // prisma
   
    poly = &c;
    poly->countArea();
    poly->countVolume();
    poly->getArea();
    poly->getVolume();
  
     

    return 0;
}