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

    // Метод для скорочення раціонального дробу
    void reduce()
    {
        int gcd = findGCD(m_numerator, m_denominator);
        m_numerator /= gcd;
        m_denominator /= gcd;
    }

private:
    // Знаходження НСД (найменшого спільного дільника) для скорочення дробу
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
    // Використовуємо std::unique_ptr замість звичайного вказівника
    std::unique_ptr<Fraction> ptr = std::make_unique<Fraction>(49, 11711);

    printFraction(ptr.get());

    // Виклик методу для скорочення раціонального дробу
    ptr->reduce();

    std::cout << "\nReduced Fraction: " << *ptr << "\n";

    // Звільняємо пам'ять автоматично через std::unique_ptr

    return 0;
}
