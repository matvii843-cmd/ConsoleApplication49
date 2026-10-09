#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Point
{
private:
    double x;
    double y;
    double z;

public:
    void Init()
    {
        cout << "Enter x: "; cin >> x;
        cout << "Enter y: "; cin >> y;
        cout << "Enter z: "; cin >> z;
    }

    void Print()
    {
        cout << "Point (" << x << ", " << y << ", " << z << ")" << endl;
    }

    // setters
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }

    // getters
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    void SaveToFile(string filename)
    {
        ofstream fout(filename);
        fout << x << " " << y << " " << z;
        fout.close();
    }

    void LoadFromFile(string filename)
    {
        ifstream fin(filename);
        fin >> x >> y >> z;
        fin.close();
    }
};

int main()
{
    Point p;
    p.Init();
    p.Print();

    p.setX(1.5);
    p.setY(2.5);
    p.setZ(3.5);

    cout << "After setters:" << endl;
    cout << "x = " << p.getX() << endl;
    cout << "y = " << p.getY() << endl;
    cout << "z = " << p.getZ() << endl;

    p.SaveToFile("point.txt");
    cout << "Saved to point.txt" << endl;

    Point p2;
    p2.LoadFromFile("point.txt");
    cout << "Loaded from point.txt:" << endl;
    p2.Print();

    return 0;
}