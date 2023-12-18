#include <iostream>
#include <memory>

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator = 1;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
    {
        out << f1.m_numerator << "/" << f1.m_denominator;
        return out;
    }

    // ����� ��� ���������� ������������� �����
    void reduce()
    {
        int gcd = findGCD(m_numerator, m_denominator);
        m_numerator /= gcd;
        m_denominator /= gcd;
    }

private:
    // ����������� ��� (���������� �������� �������) ��� ���������� �����
    int findGCD(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

void printFraction(const Fraction* const ptr)
{
    if (ptr)
        std::cout << *ptr;
}

int main()
{
    // ������������� std::unique_ptr ������ ���������� ���������
    std::unique_ptr<Fraction> ptr = std::make_unique<Fraction>(49, 11711);

    printFraction(ptr.get());

    // ������ ������ ��� ���������� ������������� �����
    ptr->reduce();

    std::cout << "\nReduced Fraction: " << *ptr << "\n";

    // ��������� ���'��� ����������� ����� std::unique_ptr

    return 0;
}
