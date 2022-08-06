//11a.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define MAX 100
enum Bool {False, True};

using namespace std;

class Set
{
private:
    // int elemen[MAX]; // elemen himpunan
    vector<int> vect;
    int kardinalitas; // kardinalitas himpunan

public:
    Set() {srand(time(NULL)); kardinalitas = 0;}
    Bool Anggota (const int);
    Bool tambahElemen (const int);
    void bubble_sort();
    void buangElemen (const int);
    int getElemen(const int);
    void Copy (Set&);
    Bool Equal (Set&);
    void Irisan (Set&, Set&);
    void Gabungan (Set&, Set&);
    void Print (string);
};

Bool Set::Anggota (const int elem)
{
    for (int i = 0; i < kardinalitas; ++i)
        if(vect.at(i) == elem)
            return True;
        // if (elemen[i] == elem)
        //     return True;
    return False;
}

int Set::getElemen(const int i)
{
    if (i < kardinalitas)
        return vect.at(i);
        // return elemen[i];
    else
        return -99;
}

Bool Set::tambahElemen (const int elem)
{
    if (Anggota(elem))
        return False;
    if (kardinalitas < MAX)
    {
        vect.at(kardinalitas++) = elem;
        // elemen[kardinalitas++] = elem;
        bubble_sort();
        return True;
    }
    else
        cout << "Set overflow\n";
    return False;
}

void Set::bubble_sort()
{
    int i, j, temp;
    for(i = 0; i < kardinalitas-1; i++)
        for(j = kardinalitas-1; j > i; j--)
            if(vect.at(j-1) > vect.at(j)){
                temp = vect.at(j-1);
                vect.at(j - 1) = vect.at(j);
                vect.at(j) = temp;
            }
            // if(elemen[j-1] > elemen[j])
            // {
            //     temp = elemen[j - 1];
            //     elemen[j - 1] = elemen[j];
            //     elemen[j] = temp;
            // }
}

void Set::buangElemen (const int elem)
{
    for (int i = 0; i < kardinalitas; ++i)
        if (vect.at(i) == elem)
        {
            for (; i < kardinalitas-1; ++i)
                vect.at(i) = vect.at(i+1);
            --kardinalitas;
        }
}

void Set::Copy (Set &set)
{
    for (int i = 0; i < kardinalitas; ++i)
        set.vect.at(i) = vect.at(i);
        // set.elemen[i] = elemen[i];
    set.kardinalitas = kardinalitas;
}

Bool Set::Equal (Set &set)
{
    if (kardinalitas != set.kardinalitas)
        return False;
    for (int i = 0; i < kardinalitas; ++i)
        if (!set.Anggota(vect.at(i)))
            return False;
    return True;
}

void Set::Irisan (Set &set, Set &res)
{
    res.kardinalitas = 0;

    for (int i = 0; i < kardinalitas; ++i)
        if (set.Anggota(vect.at(i)))
            res.vect.at(res.kardinalitas++) = vect.at(i);
}

void Set::Gabungan (Set &set, Set &res)
{
    set.Copy(res);
    for (int i = 0; i < kardinalitas; ++i)
        res.tambahElemen(vect.at(i));
}

void Set::Print (string ss)
{
    cout << ss << " = {";
    for (int i = 0; i < kardinalitas-1; ++i)
        cout << vect.at(i) << ",";
    if (kardinalitas > 0)
        cout << vect.at(kardinalitas-1);
    cout << "}\n"; 
}

int main ()
{
    Set s1, s2, s3;
    int i, pil=0;
    string himpunan;

    i=0;
    while(i<10)
        if (s1.tambahElemen(rand()%MAX))
            i++;
    s1.Print("s1");

    i=0;
    while(i<10)
        if (s2.tambahElemen(rand()%MAX))
            i++;
    s2.Print("s2");

    cout <<"Buang elemen ke 1 dari s1:" <<endl;
    s1.buangElemen(1);
    s1.Print("s1");

    if (s1.Anggota(20))
        cout << "20 anggota s1\n";
    else
        cout << "20 bukan anggota s1\n";

    s1.Irisan(s2,s3);

    cout << "s1 Irisan s2: ";
    s3.Print("s3");
    s1.Gabungan(s2,s3);
    cout << "s1 Gabungan s2: ";
    s3.Print("s3");
    if (!s1.Equal(s2)) cout << "s1 != s2\n";

    return 0;
}