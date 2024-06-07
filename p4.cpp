#include <iostream>
#include <cmath>

using namespace std;

class PersegiPanjang
{
public:
    double xmin, xmax, ymin, ymax;

    PersegiPanjang(double centerX, double centerY, double panjang, double lebar)
    {
        xmin = centerX - panjang / 2;
        xmax = centerX + panjang / 2;
        ymin = centerY - lebar / 2;
        ymax = centerY + lebar / 2;
    }

    double luas() const
    {
        return (xmax - xmin) * (ymax - ymin);
    }

    double max(double a, double b)
    {
        return (a > b) ? a : b;
    }

    double min(double a, double b)
    {
        return (a < b) ? a : b;
    }

    PersegiPanjang operator+(const PersegiPanjang &other)
    {
        if (*this == other)
        {
            double new_xmin = min(this->xmin, other.xmin);
            double new_xmax = max(this->xmax, other.xmax);
            double new_ymin = min(this->ymin, other.ymin);
            double new_ymax = max(this->ymax, other.ymax);
            return PersegiPanjang((new_xmin + new_xmax) / 2, (new_ymin + new_ymax) / 2, new_xmax - new_xmin, new_ymax - new_ymin);
        }

        return PersegiPanjang(0, 0, 0, 0);
    }

    PersegiPanjang operator-(const PersegiPanjang &other)
    {
        if (*this == other)
        {
            double new_xmin = max(this->xmin, other.xmin);
            double new_xmax = min(this->xmax, other.xmax);
            double new_ymin = max(this->ymin, other.ymin);
            double new_ymax = min(this->ymax, other.ymax);
            return PersegiPanjang((new_xmin + new_xmax) / 2, (new_ymin + new_ymax) / 2, new_xmax - new_xmin, new_ymax - new_ymin);
        }
        return PersegiPanjang(0, 0, 0, 0);
    }

    PersegiPanjang &operator++()
    {
        double centerX = (xmin + xmax) / 2;
        double centerY = (ymin + ymax) / 2;
        double panjang = (xmax - xmin) * sqrt(2);
        double lebar = (ymax - ymin) * sqrt(2);
        xmin = centerX - panjang / 2;
        xmax = centerX + panjang / 2;
        ymin = centerY - lebar / 2;
        ymax = centerY + lebar / 2;
        return *this;
    }

    PersegiPanjang &operator--()
    {
        double centerX = (xmin + xmax) / 2;
        double centerY = (ymin + ymax) / 2;
        double panjang = (xmax - xmin) / sqrt(2);
        double lebar = (ymax - ymin) / sqrt(2);
        xmin = centerX - panjang / 2;
        xmax = centerX + panjang / 2;
        ymin = centerY - lebar / 2;
        ymax = centerY + lebar / 2;
        return *this;
    }

    void cetak() const
    {
        cout << "xmin: " << xmin << ", ymin: " << ymin << ", xmax: " << xmax << ", ymax: " << ymax << endl;
    }

    bool operator==(const PersegiPanjang &other) const
    {
        if (other.xmin > this->xmax || this->xmin > other.xmax)
        {
            return false;
        }
        if (other.ymin > this->ymax || this->ymin > other.ymax)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    PersegiPanjang p1(0, 0, 4, 4);
    PersegiPanjang p2(1, 1, 4, 4);

    PersegiPanjang p3 = p1 + p2;
    p3.cetak();

    PersegiPanjang p4 = p1 - p2;
    p4.cetak();

    ++p1;
    p1.cetak();

    --p2;
    p2.cetak();

    bool beririsan = (p1 == p2);
    cout << "Apakah p1 dan p2 beririsan? " << (beririsan ? "Ya" : "Tidak") << endl;

    return 0;
}
